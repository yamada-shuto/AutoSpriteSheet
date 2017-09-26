//--------------------------------------------------------------------------------------
// File: Constant.h
// íËêîÉtÉ@ÉCÉã
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------
#pragma once
#include <d3d11_1.h>
#include <exception>

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