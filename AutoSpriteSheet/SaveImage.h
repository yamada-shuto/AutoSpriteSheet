//画像の出力
//2017年9月26日
//GS2 04 入山奨

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
