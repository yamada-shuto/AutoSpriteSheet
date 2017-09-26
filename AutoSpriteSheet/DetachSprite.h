//--------------------------------------------------------------------------------------
// File: DetachSprite.h
// 画像切り離し
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------
#pragma once

#include <wrl/client.h>
#include <memory>
#include <SpriteFont.h>
#include <SimpleMath.h>
#include <d3d11_1.h>
#include <iostream>

#include "WICTextureLoader.h"
#include "DebugText.h"

#include "Constant.h"

class DetachSprite
{
public:
	void Initialize(const Microsoft::WRL::ComPtr<ID3D11Device>& d3dDevice, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
	void Update();
	void Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
private:
	bool GetTextureSize(const wchar_t Id, float sizex ,float sizey);
	float m_sizeX;
	float m_sizeY;
	int num;
	
	//ブーストゲージ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_boost;
	D3D11_SHADER_RESOURCE_VIEW_DESC* m_desc;
	std::unique_ptr<DebugText> m_TextureLength;
};