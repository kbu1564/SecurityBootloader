#include "Global.h"
#include "ThreadPool.h"

int ThreadPool::create(RunFunc run, void *arg)
{
    if (this->mPthActInfo.size() > MAX_THREAD_POOL)
        return -1;

    PthreadInfo pthInfo;
    if (pthread_create(&(pthInfo.pth), NULL, run, arg) < 0) {
        return -1;
    }

    this->mPthActInfo.insert(pair<int, pthread_t>(0, pthInfo.pth));
    this->mPthInfoVec.push_back(pthInfo);
    this->wait(this->mPthInfoVec.size());

    return 0;
}

int ThreadPool::wait(const int idx)
{
    if (this->mPthInfoVec.size() >= idx)
        return -1;

    this->__lock();
    PthreadInfo pth = this->mPthInfoVec[idx];
    for (multimap<int, pthread_t>::iterator pthIter = this->mPthActInfo.begin(); pthIter != this->mPthActInfo.end(); pthIter++) {
        pair<int, pthread_t> element = *pthIter;
        // 찾고자 하는 Thread 가 저장되어 있고 해당 Thread 가 동작중인 상태일 경우
        if (pth.pth == element.second && element.first == 1) {
            this->mPthActInfo.erase(pthIter);
            this->mPthActInfo.insert(pair<int, pthread_t>(0, element.second));
            pthread_cond_wait(&(pth.pthCond), &(this->mPthMutex));
            break;
        }
    }
    this->__unlock();

    return 0;
}

int ThreadPool::wake(const int idx)
{
    if (this->mPthInfoVec.size() >= idx)
        return -1;

    this->__lock();
    PthreadInfo pth = this->mPthInfoVec[idx];
    for (multimap<int, pthread_t>::iterator pthIter = this->mPthActInfo.begin(); pthIter != this->mPthActInfo.end(); pthIter++) {
        pair<int, pthread_t> element = *pthIter;
        // 찾고자 하는 Thread 가 저장되어 있고 해당 Thread 가 대기중인 상태일 경우
        if (pth.pth == element.second && element.first == 0) {
            this->mPthActInfo.erase(pthIter);
            this->mPthActInfo.insert(pair<int, pthread_t>(1, element.second));
            pthread_cond_signal(&(this->mPthInfoVec[idx].pthCond));
            break;
        }
    }
    this->__unlock();

    return 0;
}

void ThreadPool::__lock()
{
    pthread_mutex_lock(&this->mPthMutex);
}

void ThreadPool::__unlock()
{
    pthread_mutex_unlock(&this->mPthMutex);
}

