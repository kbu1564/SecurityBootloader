#ifndef THREADPOOL_H_
#define THREADPOOL_H_

// Thread 최대 생성 수
const int MAX_THREAD_POOL = 256;
// Thread 실행할 함수 포인터
typedef void *RunFunc(void *arg);
// Thread 정보 저장용 구조체
typedef struct _pth
{
    pthread_t      pth;
    pthread_cond_t pthCond;
} PthreadInfo;

class ThreadPool
{
private:
    multimap<int, pthread_t> mPthActInfo;
    vector<PthreadInfo>      mPthInfoVec;

    pthread_mutex_t          mPthMutex;
public:
    int create(RunFunc run, void *arg);
    int wait(const int idx);
    int wake(const int idx);
private:
    void __lock();
    void __unlock();
};

#endif

