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
	void SaveFileSelect();

	void SetFilePass(TCHAR* file);

private:
	BOOL SaveFileDlg(HWND hWnd, TCHAR * fname, int sz, TCHAR * initDir);

	TCHAR* m_filePass;
	wchar_t* m_a;

};
