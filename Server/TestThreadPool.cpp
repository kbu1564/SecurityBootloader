#include "Global.h"
#include "ThreadPool.h"

ThreadPool tp;

void *func1(void* arg)
{
    tp.wait(0);
    for (int i = 0; i < 10; i++)
        cout << "func1 : " << *((int *)arg) << endl;

    while (1);
}

void *func2(void* arg)
{
    tp.wait(1);
    for (int i = 0; i < 10; i++)
        cout << "func2 : " << *((int *)arg) << endl;

    while (1);
}

int main(int argc, char* argv[])
{
    int arg1 = 10;
    tp.create(func1, &arg1);
    int arg2 = 20;
    tp.create(func2, &arg2);

    tp.wake(0);
    tp.wake(1);

    while (1);

    return 0;
}
