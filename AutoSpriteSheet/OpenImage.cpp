//コモンダイアログを使用してファイル名を取得
//2017年9月26日
//GS2 04 入山奨

#include "OpenImage.h"

OpenImage::OpenImage()
{
}

OpenImage::~OpenImage()
{
}

//ファイルを開いたらファイルのアドレスを返す
wchar_t OpenImage::OpenImageFile()
{
	TCHAR szFile[MAX_PATH * 256];

	if (GetFileName(0, szFile, sizeof(szFile) / sizeof(TCHAR), _TEXT("C:\\")))
	{
		MessageBox(0, szFile, _TEXT("選択されたファイル名"), MB_OK);
		return (wchar_t)*szFile;
	}
	
	return 0;
}

// ファイル名を指定するコモンダイアログを表示
BOOL OpenImage::GetFileName(HWND hWnd, TCHAR * fname, int sz, TCHAR * initDir)
{
	OPENFILENAME o;
	fname[0] = _T('\0');
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	構造体サイズ
	o.hwndOwner = hWnd;				//	親ウィンドウのハンドル
	o.lpstrInitialDir = initDir;	//	初期フォルダー
	o.lpstrFile = fname;			//	取得したファイル名を保存するバッファ
	o.nMaxFile = sz;				//	取得したファイル名を保存するバッファサイズ
	o.lpstrFilter = _TEXT("イメージファイル (*.jpg;*.png;*.bmp)\0*.jpg;*.png;*.bmp\0");
					//_TEXT("全てのファイル(*.*)\0*.*\0");//_TEXT("TXTファイル(*.TXT)\0*.TXT\0") _TEXT("全てのファイル(*.*)\0*.*\0");
	o.lpstrDefExt = _TEXT("JPG");
	o.lpstrTitle = _TEXT("イメージファイルを開く");
	o.nFilterIndex = 1;
	o.Flags = OFN_FILEMUSTEXIST;	//存在するファイルのみ指定ができる
	
	return GetOpenFileName(&o);
}