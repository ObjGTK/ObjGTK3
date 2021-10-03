/*
 * OGTKEntryBuffer.h
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

@interface OGTKEntryBuffer : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initWithInitialChars:(OFString*)initialChars andNinitialChars:(gint)ninitialChars;

/**
 * Methods
 */

- (GtkEntryBuffer*)ENTRYBUFFER;

/**
 * - (guint*)deleteTextWithPosition:(guint)position andNchars:(gint)nchars;
 *
 * @param position
 * @param nchars
 * @returns guint
 */
- (guint)deleteTextWithPosition:(guint)position andNchars:(gint)nchars;

/**
 * - (void*)emitDeletedTextWithPosition:(guint)position andNchars:(guint)nchars;
 *
 * @param position
 * @param nchars
 */
- (void)emitDeletedTextWithPosition:(guint)position andNchars:(guint)nchars;

/**
 * - (void*)emitInsertedTextWithPosition:(guint)position andChars:(OFString*)chars andNchars:(guint)nchars;
 *
 * @param position
 * @param chars
 * @param nchars
 */
- (void)emitInsertedTextWithPosition:(guint)position andChars:(OFString*)chars andNchars:(guint)nchars;

/**
 * - (gsize*)getBytes;
 *
 * @returns gsize
 */
- (gsize)getBytes;

/**
 * - (guint*)getLength;
 *
 * @returns guint
 */
- (guint)getLength;

/**
 * - (gint*)getMaxLength;
 *
 * @returns gint
 */
- (gint)getMaxLength;

/**
 * - (OFString**)getText;
 *
 * @returns OFString*
 */
- (OFString*)getText;

/**
 * - (guint*)insertTextWithPosition:(guint)position andChars:(OFString*)chars andNchars:(gint)nchars;
 *
 * @param position
 * @param chars
 * @param nchars
 * @returns guint
 */
- (guint)insertTextWithPosition:(guint)position andChars:(OFString*)chars andNchars:(gint)nchars;

/**
 * - (void*)setMaxLength:(gint)maxLength;
 *
 * @param maxLength
 */
- (void)setMaxLength:(gint)maxLength;

/**
 * - (void*)setTextWithChars:(OFString*)chars andNchars:(gint)nchars;
 *
 * @param chars
 * @param nchars
 */
- (void)setTextWithChars:(OFString*)chars andNchars:(gint)nchars;

@end