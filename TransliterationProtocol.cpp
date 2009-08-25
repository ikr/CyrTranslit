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

#include "TransliterationProtocol.h"
#include "../miranda/include/newpluginapi.h"
#include "../miranda/include/m_protomod.h"
#include "../miranda/include/m_protosvc.h"
#include "TransliterationMap.h"
#include "../miranda/include/m_system.h"

namespace CyrTranslit
{

char *TransliterationProtocol::MODULE_NAME = "ProtoCyrTranslitByIKR";

//------------------------------------------------------------------------------

void TransliterationProtocol::initialize()
{
    PROTOCOLDESCRIPTOR desc;
    desc.cbSize = sizeof(desc);
    desc.szName = MODULE_NAME;
    desc.type = PROTOTYPE_TRANSLATION;
    
    CallService(
        MS_PROTO_REGISTERMODULE,
        0,
        reinterpret_cast<LPARAM>(&desc));
        
    CreateProtoServiceFunction(MODULE_NAME, PSS_MESSAGE, sendMessage);
}

//------------------------------------------------------------------------------

int TransliterationProtocol::sendMessage(WPARAM wParam, LPARAM lParam)
{
    
    CCSDATA *ccs = reinterpret_cast<CCSDATA*>(lParam);
    
    std::string txt = reinterpret_cast<const char*>(ccs->lParam);
    txt = TransliterationMap::getInstance().cyrillicToLatin(txt);
    
    MM_INTERFACE mmi;
    CallService(MS_SYSTEM_GET_MMI, 0, reinterpret_cast<LPARAM>(&mmi));
    const DWORD newSize = static_cast<DWORD>(txt.length() + 1);
    
    ccs->lParam = reinterpret_cast<LPARAM>(mmi.mmi_realloc(
        reinterpret_cast<void*>(ccs->lParam), newSize));
        
    strcpy(reinterpret_cast<char*>(ccs->lParam), txt.c_str());

    return CallService(MS_PROTO_CHAINSEND, wParam, lParam);
}

//------------------------------------------------------------------------------

void TransliterationProtocol::activateForContact(HANDLE hContact)
{
    CallService(
        MS_PROTO_ADDTOCONTACT,
        reinterpret_cast<WPARAM>(hContact),
        reinterpret_cast<LPARAM>(MODULE_NAME));
}

//------------------------------------------------------------------------------

void TransliterationProtocol::deactivateForContact(HANDLE hContact)
{
    CallService(
        MS_PROTO_REMOVEFROMCONTACT,
        reinterpret_cast<WPARAM>(hContact),
        reinterpret_cast<LPARAM>(MODULE_NAME));
}

}