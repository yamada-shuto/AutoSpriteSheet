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
	// 静的メンバの初期化
	static void InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice);
private:
	// デバイス
	static Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
public:
	TextBox(float x,float y, DirectX::Keyboard* keyboard, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
	~TextBox();
	void AddText();
	void Draw(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);
	
	POSITION m_pos;
	bool m_isWrite;
private:
	
	//ボックスのイメージ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_Box;
	// キーボード
	DirectX::Keyboard* m_pKeyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;
	//テキスト
	//項目名
	std::unique_ptr<DebugText> m_KindText;
	std::unique_ptr<DebugText> m_NumText;

	int m_rank;
	int m_size;
};
