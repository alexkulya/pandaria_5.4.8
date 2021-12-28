#ifndef LFG_DATA_OWNER_H
#define LFG_DATA_OWNER_H

#include <LFG.h>

namespace lfg
{
    template <typename QueueData>
    class LfgDataOwner
    {
        typedef std::map<uint32, QueueData> QueueDataMap;

    public:
        void SetState(uint32 queueId, LfgState state)
        {
            auto& queueData = GetQueueData(queueId);

            switch (state)
            {
                case LFG_STATE_FINISHED_DUNGEON:
                case LFG_STATE_DUNGEON:
                    queueData.OldState = state;
                    // No break on purpose
                default:
                    queueData.State = state;
                    break;
            }

            OnStateChanged();
        }

        void RestoreState(uint32 queueId)
        {
            auto& queueData = GetQueueData(queueId);
            queueData.State = queueData.OldState;

            OnStateChanged();
        }

        void RemoveQueue(uint32 queueId)
        {
            auto itr = m_queues.find(queueId);
            ASSERT(itr != m_queues.end());
            m_queues.erase(itr);
            OnStateChanged();
        }

        LfgState GetState(uint32 queueId) const
        {
            return GetQueueData(queueId).State;
        }

        LfgState GetOldState(uint32 queueId) const
        {
            return GetQueueData(queueId).OldState;
        }

        uint32 GetActiveQueueId() const
        {
            return m_activeQueueId;
        }

        QueueData const& GetActiveQueue() const
        {
            ASSERT(m_activeQueueId);
            return GetQueueData(m_activeQueueId);
        }

        QueueDataMap const& GetQueues() const
        {
            return m_queues;
        }

        QueueData const& GetQueueData(uint32 queueId) const
        {
            auto itr = m_queues.find(queueId);
            //ASSERT(itr != m_queues.end());
            return itr->second;
        }

    protected:
        QueueData& GetQueueData(uint32 queueId)
        {
            auto itr = m_queues.find(queueId);
            ASSERT(itr != m_queues.end());
            return itr->second;
        }

        void OnStateChanged()
        {
            m_activeQueueId = 0;
            LfgState topState = LFG_STATE_NONE;

            for (auto itr = m_queues.begin(); itr != m_queues.end(); ++itr)
            {
                switch (itr->second.State)
                {
                    // Should not be able at the same time
                    case LFG_STATE_ROLECHECK:
                    case LFG_STATE_PROPOSAL:
                        topState = itr->second.State;
                        m_activeQueueId = itr->first;
                        break;
                    case LFG_STATE_BOOT:
                        topState = LFG_STATE_DUNGEON;
                        m_activeQueueId = itr->first;
                        break;
                    case LFG_STATE_DUNGEON:
                        // Currently useless
                        if (topState != LFG_STATE_ROLECHECK || topState != LFG_STATE_PROPOSAL)
                        {
                            topState = itr->second.State;
                            m_activeQueueId = itr->first;
                        }
                        break;
                    case LFG_STATE_FINISHED_DUNGEON:
                        if (topState == LFG_STATE_NONE)
                        {
                            topState = itr->second.State;
                            m_activeQueueId = itr->first;
                        }
                        break;
                    case LFG_STATE_QUEUED:
                        if (topState == LFG_STATE_NONE || topState == LFG_STATE_FINISHED_DUNGEON)
                        {
                            topState = itr->second.State;
                            m_activeQueueId = itr->first;
                        }
                        break;
                }
            }
        }

    protected:
        uint32 m_activeQueueId = 0;
        std::map<uint32, QueueData> m_queues;
    };
}

#endif // !LFG_DATA_OWNER_H
