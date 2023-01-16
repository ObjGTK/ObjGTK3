/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

@class OGTKWindow;
@class OGTKWidget;

/**
 * The #GtkColorChooserDialog widget is a dialog for choosing
 * a color. It implements the #GtkColorChooser interface.
 *
 */
@interface OGTKColorChooserDialog : OGTKDialog
{

}


/**
 * Constructors
 */
- (instancetype)initWithTitle:(OFString*)title parent:(OGTKWindow*)parent;

/**
 * Methods
 */

- (GtkColorChooserDialog*)COLORCHOOSERDIALOG;

@end