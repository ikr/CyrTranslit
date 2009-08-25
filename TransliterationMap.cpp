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

#include "TransliterationMap.h"

namespace CyrTranslit
{

TransliterationMap::Guard TransliterationMap::guard;
const TransliterationMap *TransliterationMap::pInstance = 0;

//------------------------------------------------------------------------------

TransliterationMap::Guard::~Guard()
{
    delete TransliterationMap::pInstance;
}

//------------------------------------------------------------------------------

const TransliterationMap& TransliterationMap::getInstance()
{
    if(!pInstance)
    {
        pInstance = new TransliterationMap();
    }
    return *pInstance;
}

//------------------------------------------------------------------------------

TransliterationMap::TransliterationMap()
{
    theMap['�'] = "a";
    theMap['�'] = "b";
    theMap['�'] = "v";
    theMap['�'] = "g";
    theMap['�'] = "d";
    theMap['�'] = "e";
    theMap['�'] = "e";
    theMap['�'] = "zh";
    theMap['�'] = "z";
    theMap['�'] = "i";
    theMap['�'] = "i";
    theMap['�'] = "k";
    theMap['�'] = "l";
    theMap['�'] = "m";
    theMap['�'] = "n";
    theMap['�'] = "o";
    theMap['�'] = "p";
    theMap['�'] = "r";
    theMap['�'] = "s";
    theMap['�'] = "t";
    theMap['�'] = "u";
    theMap['�'] = "f";
    theMap['�'] = "kh";
    theMap['�'] = "ts";
    theMap['�'] = "ch";
    theMap['�'] = "sh";
    theMap['�'] = "sch";
    theMap['�'] = "`";
    theMap['�'] = "y";
    theMap['�'] = "'";
    theMap['�'] = "e";
    theMap['�'] = "yu";
    theMap['�'] = "ya";
    
    theMap['�'] = "A";
    theMap['�'] = "B";
    theMap['�'] = "V";
    theMap['�'] = "G";
    theMap['�'] = "D";
    theMap['�'] = "E";
    theMap['�'] = "E";
    theMap['�'] = "ZH";
    theMap['�'] = "Z";
    theMap['�'] = "I";
    theMap['�'] = "I";
    theMap['�'] = "K";
    theMap['�'] = "L";
    theMap['�'] = "M";
    theMap['�'] = "N";
    theMap['�'] = "O";
    theMap['�'] = "P";
    theMap['�'] = "R";
    theMap['�'] = "S";
    theMap['�'] = "T";
    theMap['�'] = "U";
    theMap['�'] = "F";
    theMap['�'] = "KH";
    theMap['�'] = "TS";
    theMap['�'] = "CH";
    theMap['�'] = "SH";
    theMap['�'] = "SCH";
    theMap['�'] = "`";
    theMap['�'] = "Y";
    theMap['�'] = "'";
    theMap['�'] = "E";
    theMap['�'] = "YU";
    theMap['�'] = "YA";
}

//------------------------------------------------------------------------------

std::string TransliterationMap::cyrillicToLatin(char c) const
{
    std::string ret(1, c);

    CharMap::const_iterator it = theMap.find(c);
    if(it != theMap.end())
    {
        ret = (*it).second;
    }
    
    return ret;
}

//------------------------------------------------------------------------------

std::string TransliterationMap::cyrillicToLatin(const std::string &src) const
{
    std::string ret;
    
    for(std::string::const_iterator i = src.begin(); i != src.end(); ++i)
    {
        ret += cyrillicToLatin(*i);
    }
    
    return ret;
}

}