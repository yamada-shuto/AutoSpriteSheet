//--------------------------------------------------------------------------------------
// File: DetachSprite.cpp
// 画像切り離し
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------
#include "DetachSprite.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

DetachSprite::DetachSprite()
{
}

DetachSprite::~DetachSprite()
{
}

void DetachSprite::Initialize(const Microsoft::WRL::ComPtr<ID3D11Device>& d3dDevice, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch, HWND window)
{
	// テクスチャファイルをロード
	Microsoft::WRL::ComPtr<ID3D11Resource> resource;

	//ゲージの読み込み
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(
			d3dDevice.Get(), L"Images/Test.png", resource.GetAddressOf(), m_test.ReleaseAndGetAddressOf()));
	m_copy = nullptr;

	//サイズの取得
	Microsoft::WRL::ComPtr<ID3D11Texture2D> cat;
	DX::ThrowIfFailed(resource.As(&cat));
	CD3D11_TEXTURE2D_DESC desc;
	cat->GetDesc(&desc);
	
	m_TextureLength = std::make_unique<DebugText>(d3dDevice.Get(), spriteBatch.get());

	// キーボードの生成
	keyboard = std::make_unique<DirectX::Keyboard>();

	//マウスの生成
	m_mouse = std::make_unique<Mouse>();
	m_mouse->SetWindow(window);

	m_textbox = std::make_unique<TextBox>(0.0f, 120.0f,  keyboard.get(), spriteBatch);
	
	m_originsize.x = float(desc.Width);
	m_originsize.y = float(desc.Height);

	m_copyrect = RECT{ 0,0,0,0 };

	m_isretouch = false;
}

void DetachSprite::Update()
{
	//マウスステートを取得
	Mouse::State mousestate = m_mouse->GetState();
	// トリガー状態の更新
	m_MouseTracker.Update(mousestate);

	// キーボードの状態を取得
	Keyboard::State keystate = keyboard->GetState();
	m_KeyboardTracker.Update(keystate);

	if (m_textbox->GetIsWrite() == m_textbox->X || m_textbox->GetIsWrite() == m_textbox->Y)
	{
		m_textbox->AddText();
		return;
	}
	if (m_textbox->GetIsWrite() == m_textbox->END)
	{
		m_retouchsize = m_textbox->GetVector();
		int x = m_retouchsize.x;
		int y = m_retouchsize.y;
		m_retouchrect = RECT{ 0,0,x,y };
		m_textbox->SetIsWrite(m_textbox->NONE);

		m_copy = m_test;
		m_copyrect = RECT{m_retouchrect.right +10,m_retouchrect.top,m_retouchrect.right *2,m_retouchrect.bottom };
		m_isretouch = true;
	}

	if (m_MouseTracker.RELEASED == m_MouseTracker.leftButton)
	{
		if ((m_textbox->m_pos.x < mousestate.x && mousestate.x < m_textbox->m_pos.length) &&
			(m_textbox->m_pos.y < mousestate.y && mousestate.y < m_textbox->m_pos.bottom))
		{
			m_textbox->AddText();
		}
	}

	if(m_isretouch)
	{
		m_TextureLength->AddText(Vector2(0, 100), L"X : %.1f  Y : %.1f", m_retouchsize.x, m_retouchsize.y);
	}
	else
	{
		m_TextureLength->AddText(Vector2(0, 100), L"X : %.1f  Y : %.1f", m_originsize.x, m_originsize.y);
	}
	
}

void DetachSprite::Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{	
	if (m_isretouch)
	{
		spriteBatch->Draw(m_test.Get(), m_retouchrect,&m_retouchrect, DirectX::Colors::White,0.0f,Vector2(0.0f,0.0f));
	}
	else
	{
		spriteBatch->Draw(m_test.Get(), DirectX::Colors::White);
	}
	if (m_copy != nullptr)
	{
		spriteBatch->Draw(m_copy.Get(), m_copyrect, &m_copyrect, DirectX::Colors::White, 0.0f, Vector2(0.0f, 0.0f));
	}
	m_TextureLength->Draw();
	m_textbox->Draw(spriteBatch);
}

bool DetachSprite::GetTextureSize(const wchar_t Id, float sizex, float sizey)
{
	
	return false;
}
