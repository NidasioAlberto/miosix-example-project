#include <stdio.h>
#include <kernel/kernel.h>

int main()
{
    while (true)
    {
        printf("Hi mom\n");
        miosix::Thread::sleep(1000);
    }
}
