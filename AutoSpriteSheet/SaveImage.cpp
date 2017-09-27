//画像の出力
//2017年9月26日
//GS2 04 入山奨

#include "SaveImage.h"

#include <atlimage.h>

SaveImage::SaveImage()
{
}

SaveImage::~SaveImage()
{
}

void SaveImage::SaveFile()
{
	TCHAR szFile[MAX_PATH * 256];

	if (SaveFileDlg(0, szFile, sizeof(szFile) / sizeof(TCHAR), _TEXT("C:\\")))
	{
		MessageBox(0, szFile, _TEXT("保存したファイル名"), MB_OK);

		//ファイル作成
		//HANDLE file = CreateFile(szFile, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);

		//ファイルに書き込み
		CImage savefile;

		//現在は固定したもののみが出力される
		savefile.Load(L"papa.bmp");

		//savefile.LoadFromResource(szFile,)

		savefile.Save(szFile);

		//CloseHandle(file);

	}
}

BOOL SaveImage::SaveFileDlg(HWND hWnd, TCHAR * fname, int sz, TCHAR * initDir)
{
	OPENFILENAME o;
	fname[0] = _T('\0');
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	構造体サイズ
	o.hwndOwner = hWnd;				//	親ウィンドウのハンドル
	o.lpstrInitialDir = initDir;	//	初期フォルダー
	o.lpstrFile = fname;			//	取得したファイル名を保存するバッファ
	o.nMaxFile = sz;				//	取得したファイル名を保存するバッファサイズ
	o.lpstrFilter = _TEXT("pngファイル(*.png)\0*.png\0");//_TEXT("bmpファイル(*.bmp)\0*.bmp\0") _TEXT("jpgファイル(*.jpg)\0*.jpg\0") _TEXT("pngファイル(*.png)\0*.png\0");
	//
	o.lpstrDefExt = _TEXT("png");
	o.lpstrTitle = _TEXT("イメージファイルを保存");
	o.nFilterIndex = 1;
	o.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	return GetSaveFileName(&o);
}
