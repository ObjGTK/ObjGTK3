/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFileChooserDialog.h"

@implementation OGTKFileChooserDialog

- (GtkFileChooserDialog*)FILECHOOSERDIALOG
{
	return GTK_FILE_CHOOSER_DIALOG([self GOBJECT]);
}


@end