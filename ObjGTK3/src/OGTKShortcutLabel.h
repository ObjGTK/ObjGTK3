/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

/**
 * #GtkShortcutLabel is a widget that represents a single keyboard shortcut or gesture
 * in the user interface.
 *
 */
@interface OGTKShortcutLabel : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)accelerator;

/**
 * Methods
 */

- (GtkShortcutLabel*)SHORTCUTLABEL;

/**
 * Retrieves the current accelerator of @self.
 *
 * @return the current accelerator.
 */
- (OFString*)accelerator;

/**
 * Retrieves the text that is displayed when no accelerator is set.
 *
 * @return the current text displayed when no
 * accelerator is set.
 */
- (OFString*)disabledText;

/**
 * Sets the accelerator to be displayed by @self.
 *
 * @param accelerator the new accelerator
 */
- (void)setAccelerator:(OFString*)accelerator;

/**
 * Sets the text to be displayed by @self when no accelerator is set.
 *
 * @param disabledText the text to be displayed when no accelerator is set
 */
- (void)setDisabledText:(OFString*)disabledText;

@end