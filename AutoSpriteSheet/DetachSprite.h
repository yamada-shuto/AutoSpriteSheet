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
#include <Keyboard.h>
#include <Mouse.h>

#include "WICTextureLoader.h"
#include "DebugText.h"

#include "Constant.h"
#include "TextBox.h"

class DetachSprite
{
public:
	DetachSprite();
	~DetachSprite();
	void Initialize(const Microsoft::WRL::ComPtr<ID3D11Device>& d3dDevice, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch, HWND window);
	void Update();
	void Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
private:
	bool GetTextureSize(const wchar_t Id, float sizex ,float sizey);
	float m_sizeX;
	float m_sizeY;
	
	// キーボード
	std::unique_ptr<DirectX::Keyboard> keyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;
	//マウス
	std::unique_ptr<DirectX::Mouse> m_mouse;
	DirectX::Mouse::ButtonStateTracker m_MouseTracker;

	std::unique_ptr<TextBox> m_textbox;
	//ブーストゲージ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_boost;
	std::unique_ptr<DebugText> m_TextureLength;
};