/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

@class OGGdkScreen;

/**
 * The #GtkInvisible widget is used internally in GTK+, and is probably not
 * very useful for application developers.
 * 
 * It is used for reliable pointer grabs and selection handling in the code
 * for drag-and-drop.
 *
 */
@interface OGTKInvisible : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initForScreen:(OGGdkScreen*)screen;

/**
 * Methods
 */

- (GtkInvisible*)INVISIBLE;

/**
 * Returns the #GdkScreen object associated with @invisible
 *
 * @return the associated #GdkScreen.
 */
- (OGGdkScreen*)screen;

/**
 * Sets the #GdkScreen where the #GtkInvisible object will be displayed.
 *
 * @param screen a #GdkScreen.
 */
- (void)setScreen:(OGGdkScreen*)screen;

@end