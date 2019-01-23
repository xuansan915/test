#ifndef SCHEDULEDTHREADPOOLEXECUTOR_H
#define SCHEDULEDTHREADPOOLEXECUTOR_H
#include "ordered_list.h"

enum TIME_ID
{
    TI_CHECK_UPDATE_FILE_CONFIG,
};

class ScheduledThreadExecutor
{
    public:
        ScheduledThreadExecutor();
        virtual ~ScheduledThreadExecutor();

        void AddTimeItem(TIME_ID eTimeID,int nElapse,int nCount,TimeFunc pTimeFunc);
        void Start();
        void run_loop();
    private:
        //定时器任务用有序列表存储
        ordered_list<TimeItem>      m_TimeList;

};

#endif // SCHEDULEDTHREADPOOLEXECUTOR_H
