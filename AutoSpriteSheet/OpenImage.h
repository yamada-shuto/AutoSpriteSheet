//�R�����_�C�A���O���g�p���ăt�@�C�������擾
//2017�N9��26��
//GS2 04 ���R��

#pragma once

#include <windows.h>
#include <tchar.h>

class OpenImage
{
public:
	OpenImage();
	~OpenImage();

	//�t�@�C�����J������t�@�C���̃A�h���X��Ԃ�
	wchar_t OpenImageFile();

private:
	// �t�@�C�������w�肷��R�����_�C�A���O��\��
	BOOL GetFileName(HWND hWnd, TCHAR* fname, int sz, TCHAR* initDir = 0);
};

