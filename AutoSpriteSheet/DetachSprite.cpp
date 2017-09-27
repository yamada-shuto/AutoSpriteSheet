//--------------------------------------------------------------------------------------
// File: DetachSprite.cpp
// �摜�؂藣��
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
	//�Q�[�W�̓ǂݍ���
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(
			d3dDevice.Get(), L"Images/Test.png", nullptr, m_boost.ReleaseAndGetAddressOf()));

	m_TextureLength = std::make_unique<DebugText>(d3dDevice.Get(), spriteBatch.get());

	// �L�[�{�[�h�̐���
	keyboard = std::make_unique<DirectX::Keyboard>();

	//�}�E�X�̐���
	m_mouse = std::make_unique<Mouse>();
	m_mouse->SetWindow(window);

	m_textbox = std::make_unique<TextBox>(0.0f, 120.0f,  keyboard.get(), spriteBatch);
	
	m_sizeX = 0;
	m_sizeY = 0;
}

void DetachSprite::Update()
{
	//�}�E�X�X�e�[�g���擾
	Mouse::State mousestate = m_mouse->GetState();
	// �g���K�[��Ԃ̍X�V
	m_MouseTracker.Update(mousestate);

	// �L�[�{�[�h�̏�Ԃ��擾
	Keyboard::State keystate = keyboard->GetState();
	m_KeyboardTracker.Update(keystate);

	if (m_textbox->m_isWrite)
	{
		m_textbox->AddText();
		return;
	}

	if (m_MouseTracker.RELEASED == m_MouseTracker.leftButton)
	{
		if ((m_textbox->m_pos.x < mousestate.x && mousestate.x < m_textbox->m_pos.length) &&
			(m_textbox->m_pos.y < mousestate.y && mousestate.y < m_textbox->m_pos.bottom))
		{
			m_textbox->AddText();
		}
	}

	if (keystate.Enter)
	{
		m_sizeX = 1.0f;
	}

	m_TextureLength->AddText(Vector2(0, 100),L"X : %.1f  Y : %.1f", m_sizeX , m_sizeY);
}

void DetachSprite::Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{	
	spriteBatch->Draw(m_boost.Get(), DirectX::SimpleMath::Vector2(0, 0));
	m_TextureLength->Draw();

	m_textbox->Draw(spriteBatch);
}

bool DetachSprite::GetTextureSize(const wchar_t Id, float sizex, float sizey)
{
	
	return false;
}
