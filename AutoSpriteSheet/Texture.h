//--------------------------------------------------------------------------------------
// File: Texture.h
//--------------------------------------------------------------------------------------
#pragma once

#include <wrl/client.h>
#include <d3d11.h>

// テクスチャクラス
class Texture
{
private:
	static Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
public:
	static void Initialize(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice);
	// テクスチャハンドル
	ID3D11ShaderResourceView* m_pTexture;

	// コンストラクタ
	Texture(wchar_t fnam);
	// デストラクタ
	~Texture();
};
