#pragma once
#include <windows.h>
#include <tchar.h>

class SaveImage
{
public:
	SaveImage();
	~SaveImage();

	void SaveFileDlg(HWND hWnd, char * filename, int buffSize);
};
