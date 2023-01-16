/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKNativeDialog.h"

#import "OGTKWindow.h"

@implementation OGTKNativeDialog

- (GtkNativeDialog*)NATIVEDIALOG
{
	return GTK_NATIVE_DIALOG([self GOBJECT]);
}

- (void)destroy
{
	gtk_native_dialog_destroy([self NATIVEDIALOG]);
}

- (bool)modal
{
	return gtk_native_dialog_get_modal([self NATIVEDIALOG]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_native_dialog_get_title([self NATIVEDIALOG])];
}

- (OGTKWindow*)transientFor
{
	return [[[OGTKWindow alloc] initWithGObject:(GObject*)gtk_native_dialog_get_transient_for([self NATIVEDIALOG])] autorelease];
}

- (bool)visible
{
	return gtk_native_dialog_get_visible([self NATIVEDIALOG]);
}

- (void)hide
{
	gtk_native_dialog_hide([self NATIVEDIALOG]);
}

- (gint)run
{
	return gtk_native_dialog_run([self NATIVEDIALOG]);
}

- (void)setModal:(bool)modal
{
	gtk_native_dialog_set_modal([self NATIVEDIALOG], modal);
}

- (void)setTitle:(OFString*)title
{
	gtk_native_dialog_set_title([self NATIVEDIALOG], [title UTF8String]);
}

- (void)setTransientFor:(OGTKWindow*)parent
{
	gtk_native_dialog_set_transient_for([self NATIVEDIALOG], [parent WINDOW]);
}

- (void)show
{
	gtk_native_dialog_show([self NATIVEDIALOG]);
}


@end