#ifndef VIGNETTE_MGR_HPP
#define VIGNETTE_MGR_HPP

#include "Common.h"
#include "Vignette.h"

class WorldObject;
class GameObject;
class Creature;
class Player;

namespace Vignette
{
    using VignetteContainer = std::map<uint64, Entity*>;

    class Manager
    {
        public:

            /**
            * Constructor of the vignette manager
            * @param player : Owner of the manager
            */
            Manager(Player const* player);

            /**
            * Destructor of the vignette manager
            */
            ~Manager();

            /**
            * Create the vignette and add it to the manager
            * @param vignetteEntry : the db2 entry of the vignette to create
            * @param mapId : The map id where the vignette is
            * @param vignetteType : Type of the vignette, @see Type
            * @param position : Position of the vignette
            * @param sourceGuid : Source of the vignette if any (can be gameobject or creature), the vignette will follow the position of the source
            */
            Entity* CreateAndAddVignette(VignetteEntry const* vignetteEntry, uint32 const mapId, Type const vignetteType, G3D::Vector3 const position, uint64 const sourceGuid = 0);

            /*
            * Remove the vignettes of the manager if they are of the same ID as specified, and destroy them
            * @param vignetteEntry: DB2 entry of the vignette to remove and destroy
            */
            void DestroyAndRemoveVignetteByEntry(VignetteEntry const* vignetteEntry);

            /**
            * Remove the vignettes of the manager and destroy them
            * @param lamba: Function to call for check if the vignette can be remove & destroy
            */
            void DestroyAndRemoveVignettes(std::function <bool(Entity* const)> lamba);

            /**
            * Update the vignette manager, send vignette update to client if needed
            */
            void Update();

            /**
            * Call by Player::UpdateVisibilityOf
            * Hook to handle vignettes linked to WorldObjects
            * @param target: The worldobject who appear
            */
            template<class T>
            void OnWorldObjectAppear(T const* target); // Inline function 'Manager::OnWorldObjectAppear<WorldObject>' is not defined

            /**
            * Call by Player::UpdateVisibilityOf
            * Hook to handle vignettes linked to WorldObjects
            * @param target: The worldobject who disappear
            */
            template<class T>
            void OnWorldObjectDisappear(T const* target); // Inline function 'Manager::OnWorldObjectDisappear<WorldObject>' is not defined

        private:

            /**
            * Send to the client creation, update & remove of vignette
            */
            void SendVignetteUpdateToClient();

            Player const*       m_Owner;             // Player for who we handle the vignettes
            VignetteContainer   m_Vignettes;         // Contains all the vignette the player can see
            std::set<uint64>    m_RemovedVignette;   // Contains all the removed vignettes to send to client at the next SMSG_VIGNETTE_UPDATE
            std::set<uint64>    m_AddedVignette;     // Contains all the added vignettes to send to client at the next SMSG_VIGNETTE_UPDATE
            std::set<uint64>    m_UpdatedVignette;   // Contains all the updated vignettes to send to client at the next SMSG_VIGNETTE_UPDATE
    };
}

#endif // VIGNETTE_MGR_H
