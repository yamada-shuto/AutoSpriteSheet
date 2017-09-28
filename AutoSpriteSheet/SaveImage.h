//‰æ‘œ‚Ìo—Í
//2017”N9Œ26“ú
//GS2 04 “üR§

#pragma once
#include <windows.h>
#include <tchar.h>

class SaveImage
{
public:
	SaveImage();
	~SaveImage();

	void SaveFile();
	void SaveFileSelect();

	void SetFilePass(TCHAR* file);

private:
	BOOL SaveFileDlg(HWND hWnd, TCHAR * fname, int sz, TCHAR * initDir);

	TCHAR* m_filePass;
	wchar_t* m_a;

};
