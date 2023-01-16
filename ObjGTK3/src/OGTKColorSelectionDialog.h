/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

@class OGTKWidget;

@interface OGTKColorSelectionDialog : OGTKDialog
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)title;

/**
 * Methods
 */

- (GtkColorSelectionDialog*)COLORSELECTIONDIALOG;

/**
 * Retrieves the #GtkColorSelection widget embedded in the dialog.
 *
 * @return the embedded #GtkColorSelection
 */
- (OGTKWidget*)colorSelection;

@end