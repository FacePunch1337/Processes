// Processes.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Processes.h"

#define MAX_LOADSTRING 100
#define CMD_BUTTON_START_NOTEPAD 1001
#define CMD_BUTTON_STOP_NOTEPAD 1002
#define CMD_BUTTON_START_MYSTAT 1003
#define CMD_BUTTON_STOP_MYSTAT 1004
#define CMD_BUTTON_START_CALC 1005
#define CMD_BUTTON_STOP_CALC 1006
#define CMD_BUTTON_START_CMD 1007
#define CMD_BUTTON_STOP_CMD 1008


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];    // the main window class name
HWND list;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                NotePadStart();
void                NotePadStop();
void                MyStatStart();
void                MyStatStop();
void                CalcStart();
void                CalcStop();
void                CmdStart();
void                CmdStop();
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROCESSES, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROCESSES));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROCESSES));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+22);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROCESSES);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        list = CreateWindowW(L"listbox", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | WS_HSCROLL,
            100, 10, 300, 400, hWnd, 0, hInst, NULL);

        CreateWindowW(L"Static", L"Notepad", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
            10, 10, 75, 23, hWnd, 0, hInst, NULL);
        CreateWindowW(L"Button", L"Start", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 30, 75, 23, hWnd, (HMENU)CMD_BUTTON_START_NOTEPAD, hInst, NULL);
        CreateWindowW(L"Button", L"Stop", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 50, 75, 23, hWnd, (HMENU)CMD_BUTTON_STOP_NOTEPAD, hInst, NULL);
        ///////////////////////////////////////////////////////////////////////////
        CreateWindowW(L"Static", L"MyStat", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
            10, 80, 75, 23, hWnd, 0, hInst, NULL);
        CreateWindowW(L"Button", L"Start", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 100, 75, 23, hWnd, (HMENU)CMD_BUTTON_START_MYSTAT, hInst, NULL);
        CreateWindowW(L"Button", L"Stop", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 120, 75, 23, hWnd, (HMENU)CMD_BUTTON_STOP_MYSTAT, hInst, NULL);
        ///////////////////////////////////////////////////////////////////////////
        CreateWindowW(L"Static", L"Calc", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
            10, 150, 75, 23, hWnd, 0, hInst, NULL);
        CreateWindowW(L"Button", L"Start", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 170, 75, 23, hWnd, (HMENU)CMD_BUTTON_START_CALC, hInst, NULL);
        CreateWindowW(L"Button", L"Stop", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 190, 75, 23, hWnd, (HMENU)CMD_BUTTON_STOP_CALC, hInst, NULL);
        ///////////////////////////////////////////////////////////////////////////
        CreateWindowW(L"Static", L"CMD", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,
            10, 220, 75, 23, hWnd, 0, hInst, NULL);
        CreateWindowW(L"Button", L"Start", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 240, 75, 23, hWnd, (HMENU)CMD_BUTTON_START_CMD, hInst, NULL);
        CreateWindowW(L"Button", L"Stop", WS_VISIBLE | WS_CHILD | WS_BORDER,
            10, 260, 75, 23, hWnd, (HMENU)CMD_BUTTON_STOP_CMD, hInst, NULL);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case CMD_BUTTON_START_NOTEPAD:
                NotePadStart();
                break;
            case CMD_BUTTON_STOP_NOTEPAD:
                NotePadStop();
                break;
            case CMD_BUTTON_START_MYSTAT:
                MyStatStart();
                break;
            case CMD_BUTTON_STOP_MYSTAT:
                MyStatStop();
                break;
            case CMD_BUTTON_START_CALC:
                CalcStart();
                break;
            case CMD_BUTTON_STOP_CALC:
                CalcStop();
                break;
            case CMD_BUTTON_START_CMD:
                CmdStart();
                break;
            case CMD_BUTTON_STOP_CMD:
                CmdStop();
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

struct INFO {

    PROCESS_INFORMATION pInfo;
    STARTUPINFO sInfo;

    INFO() {

        ZeroMemory(&pInfo, sizeof(PROCESS_INFORMATION));
        ZeroMemory(&sInfo, sizeof(STARTUPINFO));

    }

};

DWORD WINAPI NewProcess(LPVOID param) {


    INFO* app = (INFO*)param;
   if( WaitForSingleObject(app->pInfo.hProcess, 60000))
   { 
    TerminateProcess(app->pInfo.hProcess, 0);
    SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"you've not used this app for 1 minute, so it has been closed");
    SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"process stopped");
    CloseHandle(app->pInfo.hThread);
    CloseHandle(app->pInfo.hProcess);
   }
    return 0;
}

INFO Notepad;

void  NotePadStart() {

   

    if (CreateProcessW(
        L"C:\\Windows\\notepad.exe",
        NULL,
        NULL,
        NULL,
        TRUE,
        
        0,
        NULL,
        L"C:\\Windows\\",
        &Notepad.sInfo,
        &Notepad.pInfo
    )) {
        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"notepad works!");
        CreateThread(NULL, 0, NewProcess, &Notepad, 0, NULL);
      
  
    }
    else {
        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"notepad Error!");
    }
}

void NotePadStop()
{
    
   
    if (TerminateProcess(Notepad.pInfo.hProcess, 0)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"notepad stopped");

        CloseHandle(Notepad.pInfo.hThread);
        CloseHandle(Notepad.pInfo.hProcess);
    }
}

INFO MyStat;
void  MyStatStart() {


    if (CreateProcessW(L"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe",
        (LPWSTR)L"\\ https://mystat.itstep.org/en/auth/login/index?returnUrl=%2Fen%2Fmain%2Fdashboard%2Fpage%2Findex",
        NULL, NULL, TRUE, IDLE_PRIORITY_CLASS | CREATE_NEW_PROCESS_GROUP,
        NULL, NULL, &MyStat.sInfo, &MyStat.pInfo)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"mystat works!");
        CreateThread(NULL, 0, NewProcess, &MyStat, 0, NULL);
    }
    else {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"mystat error");
    }
}

void MyStatStop()
{


    if (TerminateProcess(MyStat.pInfo.hProcess, 0)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"mystat stopped");

        CloseHandle(MyStat.pInfo.hThread);
        CloseHandle(MyStat.pInfo.hProcess);
    }
}

INFO calc;

void CalcStart() {

    if (CreateProcessW(L"C:\\Windows\\SysWOW64\\calc.exe",
        NULL, NULL, NULL, TRUE, IDLE_PRIORITY_CLASS | CREATE_NEW_PROCESS_GROUP,
        NULL, NULL, &calc.sInfo, &calc.pInfo)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"calc works!");
        CreateThread(NULL, 0, NewProcess, &calc, 0, NULL);
    }
    else {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"calc error");
    }
}

void CalcStop() {

    if (TerminateProcess(calc.pInfo.hProcess, 0)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"calc stopped");

        CloseHandle(calc.pInfo.hThread);
        CloseHandle(calc.pInfo.hProcess);
    }
}


INFO cmd;

void CmdStart() {

    if (CreateProcessW(L"C:\\Windows\\SysWOW64\\cmd.exe", 
        NULL, NULL, NULL, TRUE, IDLE_PRIORITY_CLASS | CREATE_NEW_PROCESS_GROUP,
        NULL, NULL, &cmd.sInfo, &cmd.pInfo)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"cmd works!");
        CreateThread(NULL, 0, NewProcess, &cmd, 0, NULL);
    }
    else {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"cmd error");
    }
}

void CmdStop() {

    if (TerminateProcess(cmd.pInfo.hProcess, 0)) {

        SendMessageW(list, LB_ADDSTRING, 100, (LPARAM)L"cmd stopped");

        CloseHandle(cmd.pInfo.hThread);
        CloseHandle(cmd.pInfo.hProcess);
    }
}

