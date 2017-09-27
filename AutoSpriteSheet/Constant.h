//--------------------------------------------------------------------------------------
// File: Constant.h
// íËêîÉtÉ@ÉCÉã
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------
#pragma once
#include <d3d11_1.h>
#include <exception>

#define TEXTBOX_MAX_WIDTH 100
#define TEXTBOX_MAX_HEIGHT 50

struct POSITION
{
	float x;
	float y;
	float bottom;
	float length;
};

namespace DX
{
	inline void ThrowIfFailed(HRESULT hr)
	{
		if (FAILED(hr))
		{
			// Set a breakpoint on this line to catch DirectX API errors
			throw std::exception();
		}
	}
}