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

	m_size = Vector2::Zero;
	m_rank = 1;

	//ゲージの読み込み
		DirectX::CreateWICTextureFromFile(
			m_d3dDevice.Get(), L"Images/box.png", nullptr, m_Box.ReleaseAndGetAddressOf());

	m_pKeyboard = keyboard;

	m_KindText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());
	m_SizeText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());
	m_NumText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());


	m_isWrite = WRITE::NONE;
}

TextBox::~TextBox()
{
}

void TextBox::AddText()
{
	// キーボードの状態を取得
	Keyboard::State keystate = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keystate);

	int num;
	switch (m_isWrite)
	{
	case WRITE::NONE:m_isWrite = WRITE::X; break;
	case WRITE::X:
		if (2000 > m_size.x)
		{
			num = m_size.x * 10;
		}
		else
		{
			m_size.x /= 10;
			m_size.x = truncf(m_size.x);
			num = m_size.x;
			num *= 10;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D0))
		{
			m_size.x = 0.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D1))
		{
			m_size.x = 1.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D2))
		{
			m_size.x = 2.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D3))
		{
			m_size.x = 3.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D4))
		{
			m_size.x = 4.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D5))
		{
			m_size.x = 5.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D6))
		{
			m_size.x = 6.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D7))
		{
			m_size.x = 7.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D8))
		{
			m_size.x = 8.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D9))
		{
			m_size.x = 9.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::Enter))
		{
			m_isWrite = WRITE::Y;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::Back))
		{
			m_size.x /= 10;
			m_size.x = truncf(m_size.x);
		}
		break;
	case WRITE::Y:
		if (2000 > m_size.y)
		{
			num = m_size.y * 10;
		}
		else
		{
			m_size.y /= 10;
			m_size.y = truncf(m_size.y);
			num = m_size.y;
			num *= 10;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D0))
		{
			m_size.y = 0.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D1))
		{
			m_size.y = 1.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D2))
		{
			m_size.y = 2.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D3))
		{
			m_size.y = 3.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D4))
		{
			m_size.y = 4.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D5))
		{
			m_size.y = 5.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D6))
		{
			m_size.y = 6.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D7))
		{
			m_size.y = 7.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D8))
		{
			m_size.y = 8.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::D9))
		{
			m_size.y = 9.0f + num;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::Enter))
		{
			m_isWrite = WRITE::END;
		}
		if (m_KeyboardTracker.IsKeyPressed(Keyboard::Keys::Back))
		{
			m_size.y /= 10;
			m_size.y = truncf(m_size.y);
		}
		break;
	case WRITE::WIDTH:

	default:
		break;
	}
}

void TextBox::Draw(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{
	spriteBatch->Draw(m_Box.Get(), DirectX::SimpleMath::Vector2(m_pos.x, m_pos.y));
	m_KindText->AddText(DirectX::SimpleMath::Vector2(m_pos.x, m_pos.y), L"Position");
	m_SizeText->AddText(Vector2(m_pos.x, m_pos.y + 15), L"X : %.0f  Y : %.0f", m_size.x , m_size.y);
	m_NumText->AddText(Vector2(m_pos.x, m_pos.y + 30), L"CreateWidth : %.0f", m_width);
	m_KindText->Draw();
	m_SizeText->Draw();
	m_NumText->Draw();
}