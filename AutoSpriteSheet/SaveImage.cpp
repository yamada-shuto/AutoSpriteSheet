//�摜�̏o��
//2017�N9��26��
//GS2 04 ���R��

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
		MessageBox(0, szFile, _TEXT("�ۑ������t�@�C����"), MB_OK);

		//�t�@�C���쐬
		//HANDLE file = CreateFile(szFile, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);

		//�t�@�C���ɏ�������
		CImage savefile;

		//���݂͌Œ肵�����݂̂̂��o�͂����
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
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
	o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	o.lpstrInitialDir = initDir;	//	�����t�H���_�[
	o.lpstrFile = fname;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFile = sz;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFilter = _TEXT("png�t�@�C��(*.png)\0*.png\0");//_TEXT("bmp�t�@�C��(*.bmp)\0*.bmp\0") _TEXT("jpg�t�@�C��(*.jpg)\0*.jpg\0") _TEXT("png�t�@�C��(*.png)\0*.png\0");
	//
	o.lpstrDefExt = _TEXT("png");
	o.lpstrTitle = _TEXT("�C���[�W�t�@�C����ۑ�");
	o.nFilterIndex = 1;
	o.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	return GetSaveFileName(&o);
}
