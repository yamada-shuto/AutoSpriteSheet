//--------------------------------------------------------------------------------------
// File: DetachSprite.h
// �摜�؂藣��
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------
#pragma once

#include <wrl/client.h>
#include <memory>
#include <SpriteFont.h>
#include <SimpleMath.h>

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
	//�u�[�X�g�Q�[�W
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_boost;
	std::unique_ptr<DebugText> m_TextureLength;
};