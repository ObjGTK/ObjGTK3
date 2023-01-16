/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEntry.h"

@class OGTKWidget;

/**
 * #GtkSearchEntry is a subclass of #GtkEntry that has been
 * tailored for use as a search entry.
 * 
 * It will show an inactive symbolic “find” icon when the search
 * entry is empty, and a symbolic “clear” icon when there is text.
 * Clicking on the “clear” icon will empty the search entry.
 * 
 * Note that the search/clear icon is shown using a secondary
 * icon, and thus does not work if you are using the secondary
 * icon position for some other purpose.
 * 
 * To make filtering appear more reactive, it is a good idea to
 * not react to every change in the entry text immediately, but
 * only after a short delay. To support this, #GtkSearchEntry
 * emits the #GtkSearchEntry::search-changed signal which can
 * be used instead of the #GtkEditable::changed signal.
 * 
 * The #GtkSearchEntry::previous-match, #GtkSearchEntry::next-match
 * and #GtkSearchEntry::stop-search signals can be used to implement
 * moving between search results and ending the search.
 * 
 * Often, GtkSearchEntry will be fed events by means of being
 * placed inside a #GtkSearchBar. If that is not the case,
 * you can use gtk_search_entry_handle_event() to pass events.
 *
 */
@interface OGTKSearchEntry : OGTKEntry
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkSearchEntry*)SEARCHENTRY;

/**
 * This function should be called when the top-level window
 * which contains the search entry received a key event. If
 * the entry is part of a #GtkSearchBar, it is preferable
 * to call gtk_search_bar_handle_event() instead, which will
 * reveal the entry in addition to passing the event to this
 * function.
 * 
 * If the key event is handled by the search entry and starts
 * or continues a search, %GDK_EVENT_STOP will be returned.
 * The caller should ensure that the entry is shown in this
 * case, and not propagate the event further.
 *
 * @param event a key event
 * @return %GDK_EVENT_STOP if the key press event resulted
 *     in a search beginning or continuing, %GDK_EVENT_PROPAGATE
 *     otherwise.
 */
- (bool)handleEvent:(GdkEvent*)event;

@end