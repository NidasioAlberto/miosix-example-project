#include <stdio.h>
#include <kernel/kernel.h>
#include <mxgui/display.h>

using namespace mxgui;

int main()
{
    {
        DrawingContext dc(DisplayManager::instance().getDisplay());
        dc.write(Point(0, 0), "Hello world");
    }

    while (true)
    {
        printf("Hi mom\n");
        miosix::Thread::sleep(1000);
    }
}
