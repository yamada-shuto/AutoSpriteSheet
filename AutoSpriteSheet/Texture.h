//--------------------------------------------------------------------------------------
// File: Texture.h
//--------------------------------------------------------------------------------------
#pragma once

#include <wrl/client.h>
#include <d3d11.h>

// �e�N�X�`���N���X
class Texture
{
private:
	static Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
public:
	static void Initialize(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice);
	// �e�N�X�`���n���h��
	ID3D11ShaderResourceView* m_pTexture;

	// �R���X�g���N�^
	Texture(wchar_t fnam);
	// �f�X�g���N�^
	~Texture();
};
