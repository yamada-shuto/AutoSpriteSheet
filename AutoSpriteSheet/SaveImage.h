//�摜�̏o��
//2017�N9��26��
//GS2 04 ���R��

#pragma once
#include <windows.h>
#include <tchar.h>

class SaveImage
{
public:
	SaveImage();
	~SaveImage();

	void SaveFile();

private:
	BOOL SaveFileDlg(HWND hWnd, TCHAR * fname, int sz, TCHAR * initDir);


};
