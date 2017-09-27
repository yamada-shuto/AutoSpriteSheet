#include "TextBox.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Microsoft::WRL::ComPtr<ID3D11Device> TextBox::m_d3dDevice;

void TextBox::InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice)
{
	m_d3dDevice = d3dDevice;
}

TextBox::TextBox(float x, float y, DirectX::Keyboard* keyboard, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.bottom = m_pos.y + TEXTBOX_MAX_HEIGHT;
	m_pos.length = m_pos.x + TEXTBOX_MAX_WIDTH;

	m_size = 0;
	m_rank = 1;

	//ゲージの読み込み
		DirectX::CreateWICTextureFromFile(
			m_d3dDevice.Get(), L"Images/box.png", nullptr, m_Box.ReleaseAndGetAddressOf());

	m_pKeyboard = keyboard;

	m_KindText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());
	m_NumText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());


	m_isWrite = false;
}

TextBox::~TextBox()
{
}

void TextBox::AddText()
{
	// キーボードの状態を取得
	Keyboard::State keystate = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keystate);
	
	m_isWrite = true;
	int num;
	if (2000 > m_size)
	{
		num = m_size * 10;
	}
	else
	{
		num = m_size;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D0))
	{
		m_size = 0 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D1))
	{
		m_size = 1 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D2))
	{
		m_size = 2 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D3))
	{
		m_size = 3 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D4))
	{
		m_size = 4 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D5))
	{
		m_size = 5 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D6))
	{
		m_size = 6 + m_rank;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D7))
	{
		m_size = 7 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D8))
	{
		m_size = 8 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D9))
	{
		m_size = 9 + num;
	}
	if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::Enter))
	{
		m_isWrite = false;
	}
}

void TextBox::Draw(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{
	//spriteBatch->Draw(m_Box.Get(), DirectX::SimpleMath::Vector2(m_pos.x, m_pos.y));
	m_KindText->AddText(DirectX::SimpleMath::Vector2(m_pos.x, m_pos.y), L"Position");
	m_NumText->AddText(Vector2(m_pos.x, m_pos.y + 15), L"%d", m_size);
	m_KindText->Draw();
	m_NumText->Draw();
}