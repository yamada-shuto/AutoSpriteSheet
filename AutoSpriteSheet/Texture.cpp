//--------------------------------------------------------------------------------------
// File: Texture.cpp
//--------------------------------------------------------------------------------------
#include <WICTextureLoader.h>
#include "Texture.h"

Microsoft::WRL::ComPtr<ID3D11Device> Texture::m_d3dDevice;

void Texture::Initialize(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice)
{
	m_d3dDevice = d3dDevice;
}

// �R���X�g���N�^
Texture::Texture(wchar_t fname)
{

	// �e�N�X�`���쐬
	DirectX::CreateWICTextureFromFile(m_d3dDevice, fname, nullptr, m_pTexture);
}

// �f�X�g���N�^
Texture::~Texture()
{
	// �e�N�X�`���̉��
	m_pTexture->Release();
}
