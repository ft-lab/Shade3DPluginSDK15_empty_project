/**
 *  @file   MyPluginInterface.cpp
 *  @brief  Plugin SDK, plugin_interface inherited class.
 */


#include "MyPluginInterface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CMyPluginInterface::CMyPluginInterface (sxsdk::shade_interface& shade) : shade(shade)
{
}

CMyPluginInterface::~CMyPluginInterface ()
{
}

/**
 * Get the plugin name from SXUL (text.sxul).
 */
void CMyPluginInterface::do_it (sxsdk::shade_interface *shade, sxsdk::scene_interface *scene, void *aux)
{
	shade->message("Hello shade.");
}
