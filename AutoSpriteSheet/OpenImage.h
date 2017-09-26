//コモンダイアログを使用してファイル名を取得
//2017年9月26日
//GS2 04 入山奨

#pragma once

#include <windows.h>
#include <tchar.h>

class OpenImage
{
public:
	OpenImage();
	~OpenImage();

	//ファイルを開いたらファイルのアドレスを返す
	wchar_t OpenImageFile();

private:
	// ファイル名を指定するコモンダイアログを表示
	BOOL GetFileName(HWND hWnd, TCHAR* fname, int sz, TCHAR* initDir = 0);
};

