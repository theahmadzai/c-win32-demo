#include <stdlib.h>
#include <windows.h>

static const wchar_t CLASS_NAME[] = L"Application";
static const wchar_t WINDOW_NAME[] = L"Title of the application";

HINSTANCE globalInstanceHandle;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);