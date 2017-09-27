//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLib.h
//!
//! @brief  �Q�[������p���C�u�����̃w�b�_�t�@�C��
//!
//! @date   2015/6/10
//!
//! @author ���� �W
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once




// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <DxLib.h>

#include "DxLibHelper\FrameTimer.h"
#include "DxLibHelper\Mathematics.h"
#include "SpriteStudio\SpriteStudioPlayer.h"

#if defined(_DEBUG)
	#include "Utilities\MemoryLeakDetector.h"
#endif




// �^�̒�` ================================================================
typedef int HGRP;     //!< �O���t�B�b�N�n���h��
typedef int HSND;     //!< �T�E���h�n���h��
typedef int COLOR;    //!< �J���[�R�[�h
