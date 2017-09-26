//--------------------------------------------------------------------------------------
// File: DetachSprite.cpp
// âÊëúêÿÇËó£Çµ
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------
#include "DetachSprite.h"

void DetachSprite::Initialize(const Microsoft::WRL::ComPtr<ID3D11Device>& d3dDevice, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{
	//ÉQÅ[ÉWÇÃì«Ç›çûÇ›
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(
			d3dDevice.Get(), L"Images/Test.png", nullptr, m_boost.ReleaseAndGetAddressOf()));

	m_TextureLength = std::make_unique<DebugText>(d3dDevice.Get(), spriteBatch.get());

	m_sizeX = 0;
	m_sizeY = 0;
	num = 0;
}

void DetachSprite::Update()
{
	num++;
	if (num % 10 == 0)
	{
		m_sizeX++;
	}
	m_TextureLength->AddText(DirectX::SimpleMath::Vector2(0, 100), L"X : %d  Y : %d", m_sizeX , m_sizeY);
}

void DetachSprite::Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{	
	spriteBatch->Draw(m_boost.Get(), DirectX::SimpleMath::Vector2(0, 0));
	m_TextureLength->Draw();
}

bool DetachSprite::GetTextureSize(const wchar_t Id, float sizex, float sizey)
{
	
	return false;
}
