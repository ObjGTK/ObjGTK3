/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleButton.h"

@class OGTKWidget;

/**
 * A #GtkCheckButton places a discrete #GtkToggleButton next to a widget,
 * (usually a #GtkLabel). See the section on #GtkToggleButton widgets for
 * more information about toggle/check buttons.
 * 
 * The important signal ( #GtkToggleButton::toggled ) is also inherited from
 * #GtkToggleButton.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * checkbutton
 * ├── check
 * ╰── <child>
 * ]|
 * 
 * A GtkCheckButton with indicator (see gtk_toggle_button_set_mode()) has a
 * main CSS node with name checkbutton and a subnode with name check.
 * 
 * |[<!-- language="plain" -->
 * button.check
 * ├── check
 * ╰── <child>
 * ]|
 * 
 * A GtkCheckButton without indicator changes the name of its main node
 * to button and adds a .check style class to it. The subnode is invisible
 * in this case.
 *
 */
@interface OGTKCheckButton : OGTKToggleButton
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithLabel:(OFString*)label;
- (instancetype)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkCheckButton*)CHECKBUTTON;

@end