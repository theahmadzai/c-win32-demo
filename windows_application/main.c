#include "main.h"
#include <winbase.h>

INT CALLBACK wWinMain(HINSTANCE instanceHandle,
				     HINSTANCE prevInstanceHandle,
					 PWSTR commandLineString,
					 INT windowStatus)
{
	globalInstanceHandle = instanceHandle;

	WNDCLASS windowClass = { NULL };

	windowClass.lpfnWndProc = WndProc;
	windowClass.lpszClassName = CLASS_NAME;
	windowClass.hInstance = instanceHandle;
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!RegisterClass(&windowClass))
	{
		MessageBox(NULL, L"Call to RegisterClass Failed!", WINDOW_NAME, NULL);

		return 1;
	}

	HWND windowHandle = CreateWindow(
		CLASS_NAME, WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, instanceHandle, NULL
	);

	if (!windowHandle)
	{
		MessageBox(NULL, L"Call to CreateWindow Failed!", WINDOW_NAME, NULL);

		return 1;
	}

	ShowWindow(windowHandle, windowStatus);

	MSG message;

	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND windowHandle,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	PAINTSTRUCT paintStruct;
	HDC hdc;
	wchar_t greeting[] = L"Hello, Welcome to Application";

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(windowHandle, &paintStruct);

		TextOut(hdc, 5, 5, greeting, wcslen(greeting));

		EndPaint(windowHandle, &paintStruct);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(windowHandle, message, wParam, lParam);
		break;
	}

	return 0;
}
