#include "myprocesshandler.h"


MyProcessHandler::MyProcessHandler()
{

}

MyProcessHandler::~MyProcessHandler()
{

}

vector<uint32_t> *MyProcessHandler::getProcessList()
{
    return NULL;
}

void MyProcessHandler::freeProcessList(vector<uint32_t> **listAddr)
{
    if(*listAddr == NULL)
        return;

    delete *listAddr;

    *listAddr = NULL;
}

bool MyProcessHandler::getWindowFromCurrentPoint(HWND &h)
{
    POINT curPoint;
    if(!GetCursorPos(&curPoint))
        return false;

    //cout << "x: " << curPoint.x << ", y: " << curPoint.y << endl;

    h = WindowFromPoint(curPoint);
    return true;
}

HANDLE MyProcessHandler::processHandle(POINT p)
{
    return WindowFromPoint(p);
}

HANDLE MyProcessHandler::processHandle(DWORD pid)
{
    HANDLE handle = INVALID_HANDLE_VALUE;

    //handle = GetProcessTopWindows


    return handle;
}

std::string MyProcessHandler::processPath(DWORD pid)
{
    string s;
    wchar_t *fileName = new wchar_t[128];
    HANDLE hProcess;


    delete [] fileName;
    return s;
}
