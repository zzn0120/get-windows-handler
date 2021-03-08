#ifndef MYPROCESSHANDLER_H
#define MYPROCESSHANDLER_H

#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <cstdint>
#include <iostream>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class MyProcessHandler
{
public:
    MyProcessHandler();
    ~MyProcessHandler();

    vector<uint32_t> *getProcessList();
    void freeProcessList(vector<uint32_t> **listAddr);

    bool getWindowFromCurrentPoint(HWND &h);
    HANDLE processHandle(POINT p);
    HANDLE processHandle(DWORD pid);
    string processPath(DWORD pid);


private:


};

#endif // MYPROCESSHANDLER_H
