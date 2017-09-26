//--------------------------------------------------------------------------------------
// File: Constant.cpp
// íËêîÉtÉ@ÉCÉã
// Date: 2017.09.26
// Author: Syuto Yamada
//--------------------------------------------------------------------------------------

#pragma once
#ifndef CONSTANT
#define CONSTANT

#include <d3d11.h>


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

#endif CONSTANT