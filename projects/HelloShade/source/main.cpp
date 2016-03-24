/**
 *  @file   main.cpp
 *  @brief  Empty project for Shade15 Plugin SDK.
 */

/*
	[mac]         Mac OS X project.
    [win_vs2013]  Windows project (Visual Studio 2013).
    [win_vs2015]  Windows project (Visual Studio 2015).

	[source]  sources.
        main.cpp           Sample of only display the "Hello Shade".
		[resources]        Resources folder.
		     [en.lproj]    SXUL for English.
		     [ja.lproj]    SXUL for Japanese.
*/

#include "GlobalHeader.h"
#include "MyPluginInterface.h"


//**************************************************//
//	Global functions.
//**************************************************//
/**
 * Create of plugin interface.
 */
extern "C" SXSDKEXPORT void STDCALL create_interface (const IID &iid, int i, void **p, sxsdk::shade_interface *shade, void *) {
	unknown_interface *u = NULL;
	
	if (iid == plugin_iid) {
		if (i == 0) {
			u = new CMyPluginInterface(*shade);
		}
	}

	if (u) {
		u->AddRef();
		*p = (void *)u;
	}
}

/**
 * Return the number of interface.
 */
extern "C" SXSDKEXPORT int STDCALL has_interface (const IID &iid, sxsdk::shade_interface *shade) {
	if (iid == plugin_iid) return 1;
	return 0;
}

/**
 * Return the interface name.
 */
extern "C" SXSDKEXPORT const char * STDCALL get_name (const IID &iid, int i, sxsdk::shade_interface *shade, void *) {
	if (iid == plugin_iid) {
		if (i == 0) {
			return CMyPluginInterface::name(shade);
		}
	}
	return 0;
}

/**
 * Return the plugin UUID.
 */
extern "C" SXSDKEXPORT sx::uuid_class STDCALL get_uuid (const IID &iid, int i, void *) {
	if (iid == plugin_iid) {
		if (i == 0) {
			return MY_PLUGIN_ID;
		}
	}

	return sx::uuid_class(0, 0, 0, 0);
}


/**
 * Version information.
 */
extern "C" SXSDKEXPORT void STDCALL get_info (sxsdk::shade_plugin_info &info, sxsdk::shade_interface *shade, void *) {
	info.sdk_version = SHADE_BUILD_NUMBER;
	info.recommended_shade_version = 480000;
	info.major_version = 0;
	info.minor_version = 0;
	info.micro_version = 0;
	info.build_number =  1;
}

/**
 * Returns true if the resident plugins.
 */
extern "C" SXSDKEXPORT bool STDCALL is_resident (const IID &iid, int i, void *) {
	return false;
}
