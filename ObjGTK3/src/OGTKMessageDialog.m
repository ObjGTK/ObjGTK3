/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMessageDialog.h"

#import "OGTKWidget.h"

@implementation OGTKMessageDialog

- (GtkMessageDialog*)MESSAGEDIALOG
{
	return GTK_MESSAGE_DIALOG([self GOBJECT]);
}

- (OGTKWidget*)image
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_message_dialog_get_image([self MESSAGEDIALOG])] autorelease];
}

- (OGTKWidget*)messageArea
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_message_dialog_get_message_area([self MESSAGEDIALOG])] autorelease];
}

- (void)setImage:(OGTKWidget*)image
{
	gtk_message_dialog_set_image([self MESSAGEDIALOG], [image WIDGET]);
}

- (void)setMarkup:(OFString*)str
{
	gtk_message_dialog_set_markup([self MESSAGEDIALOG], [str UTF8String]);
}


@end