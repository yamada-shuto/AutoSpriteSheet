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
	OpenFileName.lpstrFilter = _TEXT("*.txt(�e�L�X�g�t�@�C��)\0")
		_TEXT("*.txt\0*.html(html�t�@�C��)\0")
		_TEXT("*.html\0*.*(���̑�)\0*.*\0\0");
	OpenFileName.nFilterIndex = 0;
	OpenFileName.lpstrFile = filename;
	OpenFileName.nMaxFile = buffSize;
	OpenFileName.lpstrDefExt = _TEXT("*.txt");//�g���q����͂��Ȃ������ꍇ�̃f�t�H���g�̎w��
	OpenFileName.lpstrTitle = _TEXT("�t�@�C����ۑ�");
	OpenFileName.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;
	if (!GetSaveFileName(&OpenFileName)) filename[0] = '\0';
}
