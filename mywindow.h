#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <windows.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class MyWindow
{
public:
    MyWindow(HWND &h);
    ~MyWindow();


    HWND &windowHandle(void);
    RECT & windowRect(void);
    RECT & clientRect(void);

    MyWindow &operator=(MyWindow &b);
    void setHWND(HWND &h);
    bool setWindowTop(void);

    string windowTitle(void);
    string windowClassName(void);
    DWORD windowProcessId(void);

private:
    bool getWindowRectFromHWND(void);
    void getClientToScreen(void);


private:
    HWND _mainWindowHandle;
    RECT _mainWindowRect;
    RECT _mainWindowClientRECT; /* 窗口的客户区（不包含标题栏和状态栏） */

public:
    int x;
    int y;
    int width;
    int height;

};

#endif // MYWINDOW_H
