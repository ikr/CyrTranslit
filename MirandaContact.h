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

#pragma once

#include <windows.h>
#include <string>
#include "../miranda/include/m_clist.h"

namespace CyrTranslit
{

/**
 * The Miranda IM contact abstraction in respect to the transliteration process.
 */
class MirandaContact
{
public:
    /**
     * This message must be sent on Miranda startup.
     */
    static void initialize();

    /**
     * A factory method which instantiates new MirandaContact objects, loading
     * its data from the Miranda database.
     *
     * @param hContact The handle of the contact object to be instantiated.
     * @return The Miranda IM contact having the passed handle.
     */
    static MirandaContact getContact(HANDLE hContact);
    
    /**
     * Saves this object's data to the persistent storage -- the Miranda
     * database. This information may be retreived later on by means of
     * getContact() factory method invocation.
     */
    void save() const;
    
    /**
     * @return True only if the Cyrillic transliteration is on for this contact.
     */
    bool shouldTransliterateOutgoingMessages() const;
    
    ~MirandaContact();

private:
    static const std::string SETTINGS_MODULE;
    static const std::string SETTING_SHOULD_TRANSLITERATE;

    static char *MENU_ITEM_TEXT;

    MirandaContact();
    
    /**
     * Must be called on Miranda start-up to generate the transliteration
     * command menu items for all the contacts (a contact-specific menu).
     */
    static void generateMenuItemsForAllContacts();
    
    static void activateTransliterationProtocolForSubscribedContacts();
    
    /**
     * This is a callback function for the transliteration command menu item.
     * This menu item is contact-specific.
     *
     * @param wParam The HANDLE of the contact that owns the activated menu
     * item.
     * @param lParam hwndContactList
     * @return Always returns 0.
     */
    static int onMenuCommandTransliterate(WPARAM wParam, LPARAM lParam);
    
    /**
     * This is a service name to bind the onMenuCommandTransliterate() method to
     * within the Miranda IM framework.
     */
    static char *MENU_COMMAND_CALLBACK_SERVICE;
    
    /**
     * Stores the handle to a single user menu item shared by all the contacts.
     * This menu item has a contact-specific state -- checked or unchecked, as
     * far as for some contacts transliteration may be on, and for others it may
     * be off.
     *
     * MirandaContact class makes the necessary update just before a menu is
     * shown for a contact: it checks or unchecks the transliteration menu item.
     *
     * When the transliteration menu item is activated by a user, the
     * transliteration setting (on or off) is inverted for the contact owing the
     * menu.
     */
    static HANDLE hTransliterateCmdMenuItem;
    
    /**
     * @param wParam The HANDLE of the contact that owns the menu item being
     * built.
     * @param lParam = 0.
     * @return Always returns 0.
     */
    static int onPreBuildContactMenu(WPARAM wParam, LPARAM lParam);
    
    static void fillInMenuItem(CLISTMENUITEM &mi);
    
    HANDLE handle;
    bool transliterateOutgoingMessages;
};

}