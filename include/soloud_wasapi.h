/*
SoLoud audio engine
Copyright (c) 2013-2019 Jari Komppa

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

#ifndef SOLOUD_WASAPI_H
#define SOLOUD_WASAPI_H

#include <string>
#include <vector>

namespace SoLoud
{
	class Soloud;

	struct WASAPIDeviceInfo
	{
		std::wstring id;
		std::wstring name;
	};

	// List active render (playback) endpoints. Safe to call before init().
	std::vector<WASAPIDeviceInfo> WASAPI_enumerateDevices();

	// Select which device the next init() call should open. Empty id = default endpoint.
	void WASAPI_setInitialDevice(const std::wstring &aDeviceId);

	// Switch a running engine to a different device, reusing the existing
	// default-device-changed teardown/rebuild path. Empty id = default endpoint.
	void WASAPI_requestDeviceChange(Soloud &aSoloud, const std::wstring &aDeviceId);
};

#endif
