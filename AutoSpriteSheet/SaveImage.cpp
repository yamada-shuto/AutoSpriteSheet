#include "SaveImage.h"

SaveImage::SaveImage()
{
}

SaveImage::~SaveImage()
{
}

void SaveImage::SaveFileDlg(HWND hWnd, char*filename, int buffSize)
{
	OPENFILENAME OpenFileName;
	memset(&OpenFileName, 0, sizeof(OPENFILENAME));
	OpenFileName.lStructSize = sizeof(OPENFILENAME);
	OpenFileName.hwndOwner = hWnd;
	OpenFileName.lpstrFilter = _TEXT("*.txt(テキストファイル)\0")
		_TEXT("*.txt\0*.html(htmlファイル)\0")
		_TEXT("*.html\0*.*(その他)\0*.*\0\0");
	OpenFileName.nFilterIndex = 0;
	OpenFileName.lpstrFile = filename;
	OpenFileName.nMaxFile = buffSize;
	OpenFileName.lpstrDefExt = _TEXT("*.txt");//拡張子を入力しなかった場合のデフォルトの指定
	OpenFileName.lpstrTitle = _TEXT("ファイルを保存");
	OpenFileName.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;
	if (!GetSaveFileName(&OpenFileName)) filename[0] = '\0';
}
