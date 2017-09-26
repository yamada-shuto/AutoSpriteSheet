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

// コンストラクタ
Texture::Texture(wchar_t fname)
{

	// テクスチャ作成
	DirectX::CreateWICTextureFromFile(m_d3dDevice, fname, nullptr, m_pTexture);
}

// デストラクタ
Texture::~Texture()
{
	// テクスチャの解放
	m_pTexture->Release();
}
