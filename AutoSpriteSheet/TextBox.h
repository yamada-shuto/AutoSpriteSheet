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
	// 静的メンバの初期化
	static void InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice);
private:
	// デバイス
	static Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
public:
	TextBox(float x,float y, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch,wchar_t kind);
	~TextBox();
	void AddText(const DirectX::XMFLOAT2& position, LPCWSTR format, ...);

private:
	POSITION m_pos;
	//ボックスのイメージ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_Box;
	//テキスト
	//項目名
	std::unique_ptr<DebugText> m_KindText;
	std::unique_ptr<DebugText> m_NumText;
};
