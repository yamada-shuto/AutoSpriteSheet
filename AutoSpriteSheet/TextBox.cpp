#include "TextBox.h"

Microsoft::WRL::ComPtr<ID3D11Device> TextBox::m_d3dDevice;

void TextBox::InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice)
{
	m_d3dDevice = d3dDevice;
}

TextBox::TextBox(float x, float y, const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch,wchar_t kind)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.bottom = m_pos.y + TEXTBOX_MAX_HEIGHT;
	m_pos.length = m_pos.x + TEXTBOX_MAX_WIDTH;

	//�Q�[�W�̓ǂݍ���
	DX::ThrowIfFailed(
		DirectX::CreateWICTextureFromFile(
			m_d3dDevice.Get(), L"Images/box.png", nullptr, m_Box.ReleaseAndGetAddressOf()));

	m_KindText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());
	m_KindText->AddText(DirectX::SimpleMath::Vector2(m_pos.x,m_pos.y),(LPCWSTR)kind);
	m_NumText = std::make_unique<DebugText>(m_d3dDevice.Get(), spriteBatch.get());
}

TextBox::~TextBox()
{
}

void TextBox::AddText(const DirectX::XMFLOAT2 & position, LPCWSTR format, ...)
{
	DebugText::Text text;
	// �\���ʒu
	text.pos = position;

	// ���������������
	va_list args;

	va_start(args, format);
	// �o�͗p������̐���
	text.str.resize(_vscwprintf(format, args) + 1);    // +1 for '\0'
													   // �o�͗p������̏�������
	int length = _vsnwprintf_s(&text.str[0], text.str.size(), _TRUNCATE, format, args);

	va_end(args);

	m_NumText->AddText(position, format, args);
}
