#include "VignetteMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "AreaTrigger.h"

namespace Vignette
{
    Manager::Manager(Player const* player)
    {
        m_Owner = player;
    }

    Manager::~Manager()
    {
        m_Owner = nullptr;

        for (auto&& itr : m_Vignettes)
            delete itr.second;
    }

    Entity* Manager::CreateAndAddVignette(VignetteEntry const* vignetteEntry, uint32 const mapId, Type const vignetteType, G3D::Vector3 const position, uint64 const sourceGuid)
    {
        // Check for duplicated vignettes
        for (auto&& vignette : m_Vignettes)
        {
            // Return if same vignette has already been created
            if (vignette.second->GetVignetteEntry()->Id == vignetteEntry->Id)
                return nullptr;
        }

        Entity* vignette = new Entity(vignetteEntry, mapId);
        vignette->Create(vignetteType, position, sourceGuid);

        m_Vignettes.insert(std::make_pair(vignette->GetGuid(), vignette));
        m_AddedVignette.insert(vignette->GetGuid());

        return vignette;
    }

    void Manager::DestroyAndRemoveVignetteByEntry(VignetteEntry const* vignetteEntry)
    {
        if (!vignetteEntry)
            return;

        for (auto&& itr = m_Vignettes.begin(); itr != m_Vignettes.end();)
        {
            if (itr->second->GetVignetteEntry()->Id == vignetteEntry->Id)
            {
                delete itr->second;
                m_RemovedVignette.insert(itr->first);
                itr = m_Vignettes.erase(itr);
                continue;
            }

            ++itr;
        }
    }

    void Manager::DestroyAndRemoveVignettes(std::function<bool(Entity* const)> lambda)
    {
        for (auto&& itr = m_Vignettes.begin(); itr != m_Vignettes.end();)
        {
            if (lambda(itr->second))
            {
                delete itr->second;
                m_RemovedVignette.insert(itr->first);
                itr = m_Vignettes.erase(itr);
                continue;
            }

            ++itr;
        }
    }

    void Manager::SendVignetteUpdateToClient()
    {
        uint32 addedVignetteCount = 0, updatedVignetteCount = 0;
        ByteBuffer playersAddBuffer, playersUpdateBuffer, playersRemoveBuffer, objectAddBuffer, objectUpdateBuffer;
        WorldPacket data(SMSG_VIGNETTE_UPDATE);

        data.WriteBits(m_RemovedVignette.size(), 24);
        data.WriteBit(false);                                 // ForceUpdate
        data.WriteBits(m_UpdatedVignette.size(), 24);
        for (auto&& vignetteGuid : m_UpdatedVignette)
        {
            data.WriteGuidMask(vignetteGuid, 4, 7, 3, 2, 6, 0, 5, 1);
            playersUpdateBuffer.WriteGuidBytes(vignetteGuid, 6, 2, 5, 0, 3, 4, 1, 7);
        }

        for (auto&& vignetteGuid : m_RemovedVignette)
        {
            data.WriteGuidMask(vignetteGuid, 5, 4, 1, 7, 0, 6, 2, 3);
            playersRemoveBuffer.WriteGuidBytes(vignetteGuid, 4, 0, 6, 7, 5, 3, 1, 2);
        }
        m_RemovedVignette.clear();

        data.WriteBits(m_AddedVignette.size(), 24);
        for (auto&& vignetteGuid : m_AddedVignette)
        {
            data.WriteGuidMask(vignetteGuid, 1, 4, 3, 6, 2, 0, 7, 5);
            playersAddBuffer.WriteGuidBytes(vignetteGuid, 7, 1, 0, 6, 2, 3, 4, 5);
        }

        size_t addedVignetteCountPos = data.bitwpos();
        data.WriteBits(addedVignetteCount, 20);

        for (auto&& vignetteGuid : m_AddedVignette)
        {
            auto findResult = m_Vignettes.find(vignetteGuid);
            if (findResult == m_Vignettes.end())
                continue;

            addedVignetteCount++;

            auto vignette = findResult->second;
            ObjectGuid objectGUID = vignette->GetGuid();

            data.WriteGuidMask(objectGUID, 5, 3, 7, 4, 2, 0, 6, 1);
            objectAddBuffer.WriteGuidBytes(objectGUID, 2, 5);
            objectAddBuffer << float(vignette->GetPosition().z);
            objectAddBuffer << uint32(vignette->GetVignetteEntry()->Id);
            objectAddBuffer << float(vignette->GetPosition().y);
            objectAddBuffer.WriteGuidBytes(objectGUID, 1);
            objectAddBuffer << float(vignette->GetPosition().x);
            objectAddBuffer.WriteGuidBytes(objectGUID, 6, 7, 4, 3, 0);
        }
        m_AddedVignette.clear();

        size_t updatedVignetteCountPos = data.bitwpos();
        data.WriteBits(updatedVignetteCount, 20);

        for (auto&& vignetteGuid : m_UpdatedVignette)
        {
            auto findResult = m_Vignettes.find(vignetteGuid);
            if (findResult == m_Vignettes.end())
                continue;

            updatedVignetteCount++;

            auto vignette = findResult->second;
            ObjectGuid objectGUID = vignette->GetGuid();

            data.WriteGuidMask(objectGUID, 3, 5, 2, 6, 4, 0, 1, 7);
            objectUpdateBuffer.WriteGuidBytes(objectGUID, 5, 2);
            objectUpdateBuffer << float(vignette->GetPosition().z);
            objectUpdateBuffer << float(vignette->GetPosition().x);
            objectUpdateBuffer.WriteGuidBytes(objectGUID, 1, 4, 6, 0);
            objectUpdateBuffer << uint32(vignette->GetVignetteEntry()->Id);
            objectUpdateBuffer << float(vignette->GetPosition().y);
            objectUpdateBuffer.WriteGuidBytes(objectGUID, 3, 7);
        }
        m_UpdatedVignette.clear();

        data.FlushBits();

        data.PutBits(addedVignetteCountPos, addedVignetteCount, 20);
        data.PutBits(updatedVignetteCountPos, updatedVignetteCount, 20);

        if (objectUpdateBuffer.size())
            data.append(objectUpdateBuffer);
        if (playersRemoveBuffer.size())
            data.append(playersRemoveBuffer);
        if (objectAddBuffer.size())
            data.append(objectAddBuffer);
        if (playersAddBuffer.size())
            data.append(playersAddBuffer);
        if (playersUpdateBuffer.size())
            data.append(playersUpdateBuffer);

        m_Owner->GetSession()->SendPacket(&data);
    }

    void Manager::Update()
    {
        for (auto&& itr : m_Vignettes)
        {
            auto vignette = itr.second;

            // Update the position of the vignette if vignette is linked to a creature
            if (IS_UNIT_GUID(vignette->GeSourceGuid()))
            {
                TaskMgr::Default()->ScheduleInvocation([=]
                {
                    if (Creature* sourceCreature = sObjectAccessor->FindCreature(vignette->GeSourceGuid()))
                        vignette->UpdatePosition(G3D::Vector3(sourceCreature->GetPositionX(), sourceCreature->GetPositionY(), sourceCreature->GetPositionZ()));
                });
            }

            if (vignette->NeedClientUpdate())
            {
                m_UpdatedVignette.insert(vignette->GetGuid());
                vignette->ResetNeedClientUpdate();
            }
        }

        // Send update to client if needed
        if (!m_AddedVignette.empty() || !m_UpdatedVignette.empty() || !m_RemovedVignette.empty())
            SendVignetteUpdateToClient();
    }

    template <class T>
    void Manager::OnWorldObjectAppear(T const* target)
    {
        VignetteEntry const* vignetteEntry = GetVignetteEntryFromWorldObject(target);
        if (!vignetteEntry)
            return;

        auto type = GetDefaultVignetteTypeFromWorldObject(target);
        auto trackingQuest = GetTrackingQuestIdFromWorldObject(target);

        if (trackingQuest)
        {
            if (m_Owner->IsQuestRewarded(trackingQuest))
                return;

            type = GetTrackingVignetteTypeFromWorldObject(target);
        }

        CreateAndAddVignette(vignetteEntry, target->GetMapId(), type, G3D::Vector3(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ()), target->GetGUID());
    }

    template <class T>
    void Manager::OnWorldObjectDisappear(T const* target)
    {
        auto vignetteEntry = GetVignetteEntryFromWorldObject(target);
        if (!vignetteEntry)
            return;

        DestroyAndRemoveVignettes([target](Entity const* vignette) -> bool
        {
            if (vignette->GeSourceGuid() == target->GetGUID() && vignette->GetVignetteType() != Type::SourceScript)
                return true;

            return false;
        });
    }

    template void Manager::OnWorldObjectDisappear(Corpse const*);
    template void Manager::OnWorldObjectDisappear(Creature const*);
    template void Manager::OnWorldObjectDisappear(GameObject const*);
    template void Manager::OnWorldObjectDisappear(DynamicObject const*);
    template void Manager::OnWorldObjectDisappear(AreaTrigger const*);
    template void Manager::OnWorldObjectDisappear(WorldObject const*);
    template void Manager::OnWorldObjectDisappear(Player const*);

    template void Manager::OnWorldObjectAppear(Corpse const*);
    template void Manager::OnWorldObjectAppear(Creature const*);
    template void Manager::OnWorldObjectAppear(GameObject const*);
    template void Manager::OnWorldObjectAppear(DynamicObject const*);
    template void Manager::OnWorldObjectAppear(AreaTrigger const*);
    template void Manager::OnWorldObjectAppear(WorldObject const*);
    template void Manager::OnWorldObjectAppear(Player const*);
}
