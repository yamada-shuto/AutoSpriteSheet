//�R�����_�C�A���O���g�p���ăt�@�C�������擾
//2017�N9��26��
//GS2 04 ���R��

#include "OpenImage.h"

OpenImage::OpenImage()
{
}

OpenImage::~OpenImage()
{
}

//�t�@�C�����J������t�@�C���̃A�h���X��Ԃ�
wchar_t OpenImage::OpenImageFile()
{
	TCHAR szFile[MAX_PATH * 256];

	if (GetFileName(0, szFile, sizeof(szFile) / sizeof(TCHAR), _TEXT("C:\\")))
	{
		MessageBox(0, szFile, _TEXT("�I�����ꂽ�t�@�C����"), MB_OK);
		return (wchar_t)*szFile;
	}
	
	return 0;
}

// �t�@�C�������w�肷��R�����_�C�A���O��\��
BOOL OpenImage::GetFileName(HWND hWnd, TCHAR * fname, int sz, TCHAR * initDir)
{
	OPENFILENAME o;
	fname[0] = _T('\0');
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);		//	�\���̃T�C�Y
	o.hwndOwner = hWnd;				//	�e�E�B���h�E�̃n���h��
	o.lpstrInitialDir = initDir;	//	�����t�H���_�[
	o.lpstrFile = fname;			//	�擾�����t�@�C������ۑ�����o�b�t�@
	o.nMaxFile = sz;				//	�擾�����t�@�C������ۑ�����o�b�t�@�T�C�Y
	o.lpstrFilter = _TEXT("�C���[�W�t�@�C�� (*.jpg;*.png;*.bmp)\0*.jpg;*.png;*.bmp\0");
					//_TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");//_TEXT("TXT�t�@�C��(*.TXT)\0*.TXT\0") _TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");
	o.lpstrDefExt = _TEXT("JPG");
	o.lpstrTitle = _TEXT("�C���[�W�t�@�C�����J��");
	o.nFilterIndex = 1;
	o.Flags = OFN_FILEMUSTEXIST;	//���݂���t�@�C���̂ݎw�肪�ł���
	
	return GetOpenFileName(&o);
}