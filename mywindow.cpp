#include "mywindow.h"

MyWindow::MyWindow(HWND &h)
    :_mainWindowHandle(h),
      x(0),
      y(0),
      width(0),
      height(0)
{
    getWindowRectFromHWND();

    getClientToScreen();
}

MyWindow::~MyWindow()
{

}

HWND &MyWindow::windowHandle()
{
    return _mainWindowHandle;
}

bool MyWindow::getWindowRectFromHWND()
{
    if(GetWindowRect(_mainWindowHandle, &_mainWindowRect))
        return true;
    cout << "getWindowRect failed: " << __LINE__  << ", " << __FILE__ << endl;

    return false;
}

RECT & MyWindow::windowRect()
{
    return _mainWindowRect;
}

RECT & MyWindow::clientRect()
{
    return _mainWindowClientRECT;
}

void MyWindow::getClientToScreen()
{

    if(!GetClientRect(_mainWindowHandle, &_mainWindowClientRECT))
        cout << "getClientRect failed: " << __LINE__  << ", " << __FILE__ << endl;

    POINT mcPoint;
    mcPoint.x = mcPoint.y = 0;
    ClientToScreen(_mainWindowHandle, &mcPoint);

    this->x = mcPoint.x;
    this->y = mcPoint.y;
    this->width = _mainWindowClientRECT.right - _mainWindowClientRECT.left;
    this->height = _mainWindowClientRECT.bottom - _mainWindowClientRECT.top;
}

MyWindow &MyWindow::operator=(MyWindow &b)
{
    this->x = b.x;
    this->y = b.y;
    this->width = b.width;
    this->height = b.height;
    this->_mainWindowHandle = b._mainWindowHandle;
    this->_mainWindowRect = b._mainWindowRect;
    this->_mainWindowClientRECT = b._mainWindowClientRECT;

    return *this;
}

void MyWindow::setHWND(HWND &h)
{
    _mainWindowHandle = h;
    getWindowRectFromHWND();
    getClientToScreen();
}

bool MyWindow::setWindowTop()
{
    //SetForegroundWindow(this->_mainWindowHandle);

    return true;
}

string MyWindow::windowTitle()
{
    char *p = new char[128];

    ::GetWindowTextA(_mainWindowHandle, p, 128);

    string s(p);

    delete [] p;

    return s;
}

string MyWindow::windowClassName()
{
    char *p = new char[128];

    ::GetClassNameA(_mainWindowHandle, p, 128);

    string s(p);

    delete [] p;

    return s;
}

DWORD MyWindow::windowProcessId()
{
    DWORD dwPid;

    GetWindowThreadProcessId(_mainWindowHandle, &dwPid);

    return dwPid;
}
