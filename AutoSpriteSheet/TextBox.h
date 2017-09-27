#pragma once

#include <wrl/client.h>
#include <SpriteFont.h>
#include <SimpleMath.h>
#include <d3d11_1.h>
#include <Keyboard.h>

#include "WICTextureLoader.h"
#include "DebugText.h"

#include "Constant.h"

class TextBox
{
public:
	// �ÓI�����o�̏�����
	static void InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice);
private:
	// �f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
public:
	TextBox(float x,float y, DirectX::Keyboard* keyboard, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
	~TextBox();
	void AddText();
	void Draw(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
	
	POSITION m_pos;
	bool m_isWrite;
private:
	
	//�{�b�N�X�̃C���[�W
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_Box;
	// �L�[�{�[�h
	DirectX::Keyboard* m_pKeyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;
	//�e�L�X�g
	//���ږ�
	std::unique_ptr<DebugText> m_KindText;
	std::unique_ptr<DebugText> m_NumText;

	int m_rank;
	int m_size;
};
