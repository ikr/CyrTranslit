/**
 * CyrTranslit: the Cyrillic transliteration plug-in for Miranda IM.
 * Copyright 2005 Ivan Krechetov. 
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <windows.h>
#include "../miranda/include/newpluginapi.h"
#include "../miranda/include/m_database.h"
#include "MirandaContact.h"

HINSTANCE hInst;
PLUGINLINK *pluginLink;

PLUGININFO pluginInfo = {
    sizeof(PLUGININFO),
    "CyrTranslit",
    PLUGIN_MAKE_VERSION(1, 0, 1, 0),
    "Replaces (for the selected contacts only) the Cyrillic letters in the \
        outgoing messages with the phonetically equivalent Latin letter \
        combinations.",
    "Ivan Krechetov",
    "i.krechetov@ewi.utwente.nl",
    "© 2005 Ivan Krechetov",
    "http://wwwhome.cs.utwente.nl/~krechetovi/",
    0,		//not transient
    0		//doesn't replace anything built-in
};

//------------------------------------------------------------------------------

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	hInst = hinstDLL;
	return TRUE;
}

//------------------------------------------------------------------------------

extern "C" __declspec(dllexport) PLUGININFO* MirandaPluginInfo(DWORD mirandaVersion)
{
	return &pluginInfo;
}

//------------------------------------------------------------------------------

extern "C" __declspec(dllexport) int Load(PLUGINLINK *link)
{
	pluginLink = link;
    
    CyrTranslit::MirandaContact::initialize();
    
	return 0;
}

//------------------------------------------------------------------------------

extern "C" __declspec(dllexport) int Unload(void)
{
	return 0;
}