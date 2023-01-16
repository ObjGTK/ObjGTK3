/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIMContext.h"

@class OGTKMenuShell;

@interface OGTKIMMulticontext : OGTKIMContext
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkIMMulticontext*)IMMULTICONTEXT;

/**
 * Add menuitems for various available input methods to a menu;
 * the menuitems, when selected, will switch the input method
 * for the context and the global default input method.
 *
 * @param menushell a #GtkMenuShell
 */
- (void)appendMenuitems:(OGTKMenuShell*)menushell;

/**
 * Gets the id of the currently active slave of the @context.
 *
 * @return the id of the currently active slave
 */
- (OFString*)contextId;

/**
 * Sets the context id for @context.
 * 
 * This causes the currently active slave of @context to be
 * replaced by the slave corresponding to the new context id.
 *
 * @param contextId the id to use
 */
- (void)setContextId:(OFString*)contextId;

@end