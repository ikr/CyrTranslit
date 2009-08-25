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
    theMap['à'] = "a";
    theMap['á'] = "b";
    theMap['â'] = "v";
    theMap['ã'] = "g";
    theMap['ä'] = "d";
    theMap['å'] = "e";
    theMap['¸'] = "e";
    theMap['æ'] = "zh";
    theMap['ç'] = "z";
    theMap['è'] = "i";
    theMap['é'] = "i";
    theMap['ê'] = "k";
    theMap['ë'] = "l";
    theMap['ì'] = "m";
    theMap['í'] = "n";
    theMap['î'] = "o";
    theMap['ï'] = "p";
    theMap['ð'] = "r";
    theMap['ñ'] = "s";
    theMap['ò'] = "t";
    theMap['ó'] = "u";
    theMap['ô'] = "f";
    theMap['õ'] = "kh";
    theMap['ö'] = "ts";
    theMap['÷'] = "ch";
    theMap['ø'] = "sh";
    theMap['ù'] = "sch";
    theMap['ú'] = "`";
    theMap['û'] = "y";
    theMap['ü'] = "'";
    theMap['ý'] = "e";
    theMap['þ'] = "yu";
    theMap['ÿ'] = "ya";
    
    theMap['À'] = "A";
    theMap['Á'] = "B";
    theMap['Â'] = "V";
    theMap['Ã'] = "G";
    theMap['Ä'] = "D";
    theMap['Å'] = "E";
    theMap['¨'] = "E";
    theMap['Æ'] = "ZH";
    theMap['Ç'] = "Z";
    theMap['È'] = "I";
    theMap['É'] = "I";
    theMap['Ê'] = "K";
    theMap['Ë'] = "L";
    theMap['Ì'] = "M";
    theMap['Í'] = "N";
    theMap['Î'] = "O";
    theMap['Ï'] = "P";
    theMap['Ð'] = "R";
    theMap['Ñ'] = "S";
    theMap['Ò'] = "T";
    theMap['Ó'] = "U";
    theMap['Ô'] = "F";
    theMap['Õ'] = "KH";
    theMap['Ö'] = "TS";
    theMap['×'] = "CH";
    theMap['Ø'] = "SH";
    theMap['Ù'] = "SCH";
    theMap['Ú'] = "`";
    theMap['Û'] = "Y";
    theMap['Ü'] = "'";
    theMap['Ý'] = "E";
    theMap['Þ'] = "YU";
    theMap['ß'] = "YA";
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