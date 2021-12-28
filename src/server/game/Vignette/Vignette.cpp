#include "Vignette.h"
#include "ObjectMgr.h"

namespace Vignette
{
    Entity::Entity(VignetteEntry const* vignetteEntry, uint32 const mapId) : m_Map(mapId), m_VignetteEntry(vignetteEntry)
    {
        ASSERT(vignetteEntry);

        m_Guid             = 0;
        m_NeedClientUpdate = false;
    }

    Entity::~Entity() { }

    void Entity::Create(Type type, G3D::Vector3 position, uint64 sourceGuid)
    {
        m_Guid       = MAKE_NEW_GUID(sObjectMgr->GenerateNewVignetteGUID(), m_VignetteEntry->Id, HIGHGUID_VIGNETTE);
        m_Type       = type;
        m_Position   = position;
        m_SourceGuid = sourceGuid;
    }

    void Entity::UpdatePosition(G3D::Vector3 newPosition)
    {
        if ((int32)m_Position.x == (int32)newPosition.x && (int32)m_Position.y == (int32)newPosition.y)
            return;

        m_Position         = newPosition;
        m_NeedClientUpdate = true;
    }
}
