#pragma once

#include <wrl/client.h>
#include <SpriteFont.h>
#include <SimpleMath.h>
#include <d3d11_1.h>

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
	TextBox(float x,float y, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch,wchar_t kind);
	~TextBox();
	void AddText(const DirectX::XMFLOAT2& position, LPCWSTR format, ...);

private:
	POSITION m_pos;
	//�{�b�N�X�̃C���[�W
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_Box;
	//�e�L�X�g
	//���ږ�
	std::unique_ptr<DebugText> m_KindText;
	std::unique_ptr<DebugText> m_NumText;
};
