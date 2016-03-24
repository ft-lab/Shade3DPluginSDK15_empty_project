/**
 *  @file   MyPluginInterface.h
 *  @brief  Plugin SDK, plugin_interface inherited class.
 */

#ifndef _MYPLUGININTERFACE_H
#define _MYPLUGININTERFACE_H

#include "GlobalHeader.h"

struct CMyPluginInterface : public sxsdk::plugin_interface
{
private:
	sxsdk::shade_interface& shade;

	/**
	 * SDK build number.
	 *  This is always required for each plugin_interface.
	 */
	virtual int get_shade_version () const { return SHADE_BUILD_NUMBER; }

	/**
	 * UUID (Unique ID).
	 * This is always required for each plugin_interface.
	 */
	virtual sx::uuid_class get_uuid (void * = 0) { return MY_PLUGIN_ID; }

	/**
	 * Called when it is selected from the plugin menu.
	 */
	virtual void do_it (sxsdk::shade_interface *shade, sxsdk::scene_interface *scene, void *aux = 0);

public:
	CMyPluginInterface (sxsdk::shade_interface& shade);
	virtual ~CMyPluginInterface ();

	/**
	 * Get the plugin name from SXUL (text.sxul).
	 */
	static const char *name (sxsdk::shade_interface *shade) { return shade->gettext("title"); }

};

#endif
