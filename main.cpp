#include <iostream>
#include <string>
#include "myprocesshandler.h"
#include "mywindow.h"

using namespace std;

HWND getParent(HWND h)
{
    HWND child = NULL;
    HWND parent = h;

    while(parent != NULL)
    {
        child = parent;
        parent = GetParent(child);
    }

    return child;
}

int main()
{
    MyProcessHandler *myph = new MyProcessHandler;

    HWND h;
    myph->getWindowFromCurrentPoint(h);

    MyWindow *mywindow = new MyWindow(h);

    string s;

    while(1)
    {
        Sleep(500);
        myph->getWindowFromCurrentPoint(h);

        mywindow->setHWND(h);
#if 1
        cout << "X: " << mywindow->x << ", Y: " << mywindow->y;
        cout << ", Width: " << mywindow->width << ", Height: " << mywindow->height << endl;
        cout << "Window Handle: " << mywindow->windowHandle() << endl;
        cout << " Window Title: " << mywindow->windowTitle() << endl;
        cout << " Window Class: " << mywindow->windowClassName() << endl;
        cout << "          PID: " << mywindow->windowProcessId() << endl;
        cout << "Parent Handle: " << GetParent(mywindow->windowHandle()) << endl;
        cout << "  Real Parent: " << getParent(mywindow->windowHandle()) << endl;
        SetWindowPos(getParent(mywindow->windowHandle()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);

#endif
    }

    delete myph;
    delete mywindow;

    return 0;
}
