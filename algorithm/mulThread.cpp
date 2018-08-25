#include <iostream>

#include <thread>
#include <atomic>
using namespace std;

int main(void)
{
    atomic_flag mflags;

    bool a = mflags.test_and_set();
    cout << a << endl;
    thread *t = new thread([&mflags]() {
        while (mflags.test_and_set())
        {
            this_thread::yield();
        }
        mflags.clear();
    });
    t->join();
    delete t;
}