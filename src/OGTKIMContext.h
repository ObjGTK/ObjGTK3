/*
 * OGTKIMContext.h
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKBase.h"

@interface OGTKIMContext : OGTKBase
{

}


/**
 * Methods
 */

- (GtkIMContext*)IMCONTEXT;

/**
 * - (bool*)gtkImContextDeleteSurroundingWithOffset:(gint)offset andNchars:(gint)nchars;
 *
 * @param offset
 * @param nchars
 * @returns bool
 */
- (bool)gtkImContextDeleteSurroundingWithOffset:(gint)offset andNchars:(gint)nchars;

/**
 * - (bool*)gtkImContextFilterKeypress:(GdkEventKey*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)gtkImContextFilterKeypress:(GdkEventKey*)event;

/**
 * - (void*)gtkImContextFocusIn;
 *
 */
- (void)gtkImContextFocusIn;

/**
 * - (void*)gtkImContextFocusOut;
 *
 */
- (void)gtkImContextFocusOut;

/**
 * - (void*)gtkImContextGetPreeditStringWithStr:(gchar**)str andAttrs:(PangoAttrList**)attrs andCursorPos:(gint*)cursorPos;
 *
 * @param str
 * @param attrs
 * @param cursorPos
 */
- (void)gtkImContextGetPreeditStringWithStr:(gchar**)str andAttrs:(PangoAttrList**)attrs andCursorPos:(gint*)cursorPos;

/**
 * - (bool*)gtkImContextGetSurroundingWithText:(gchar**)text andCursorIndex:(gint*)cursorIndex;
 *
 * @param text
 * @param cursorIndex
 * @returns bool
 */
- (bool)gtkImContextGetSurroundingWithText:(gchar**)text andCursorIndex:(gint*)cursorIndex;

/**
 * - (void*)gtkImContextReset;
 *
 */
- (void)gtkImContextReset;

/**
 * - (void*)gtkImContextSetClientWindow:(GdkWindow*)window;
 *
 * @param window
 */
- (void)gtkImContextSetClientWindow:(GdkWindow*)window;

/**
 * - (void*)gtkImContextSetCursorLocation:(const GdkRectangle*)area;
 *
 * @param area
 */
- (void)gtkImContextSetCursorLocation:(const GdkRectangle*)area;

/**
 * - (void*)gtkImContextSetSurroundingWithText:(OFString*)text andLen:(gint)len andCursorIndex:(gint)cursorIndex;
 *
 * @param text
 * @param len
 * @param cursorIndex
 */
- (void)gtkImContextSetSurroundingWithText:(OFString*)text andLen:(gint)len andCursorIndex:(gint)cursorIndex;

/**
 * - (void*)gtkImContextSetUsePreedit:(bool)usePreedit;
 *
 * @param usePreedit
 */
- (void)gtkImContextSetUsePreedit:(bool)usePreedit;

@end