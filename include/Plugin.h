#pragma once

#include <Mist_Common/include/UtilityMacros.h>
#include "PluginPlatform.h"

MIST_NAMESPACE

// A Plugin will load an API from a shared library
namespace Plugin {

	// -Types-

	using Handle = void*;

	template< typename ReturnType, typename... Args>
	using API = ReturnType(*)(Args...);


	// -API-

	// Load a plugin from the passed in directory
	// @Detail: the plugin will be found in the current active directory
	//    The current active directory will typically be where the executable is located
	inline Handle Load(const char* pluginDirectory);

	inline void Unload(Handle pluginToUnload);

	template< typename ReturnType, typename... Args >
	API<ReturnType, Args...> GetAPI(Handle handle, const char* apiName);
}

MIST_NAMESPACE_END

#ifdef MIST_WINDOWS
#include "WindowsPluginImpl.inl"
#endif