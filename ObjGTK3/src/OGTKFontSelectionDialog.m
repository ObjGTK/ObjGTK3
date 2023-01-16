/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFontSelectionDialog.h"

#import "OGTKWidget.h"

@implementation OGTKFontSelectionDialog

- (instancetype)init:(OFString*)title
{
	self = [super initWithGObject:(GObject*)gtk_font_selection_dialog_new([title UTF8String])];

	return self;
}

- (GtkFontSelectionDialog*)FONTSELECTIONDIALOG
{
	return GTK_FONT_SELECTION_DIALOG([self GOBJECT]);
}

- (OGTKWidget*)cancelButton
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_dialog_get_cancel_button([self FONTSELECTIONDIALOG])] autorelease];
}

- (OFString*)fontName
{
	return [OFString stringWithUTF8String:gtk_font_selection_dialog_get_font_name([self FONTSELECTIONDIALOG])];
}

- (OGTKWidget*)fontSelection
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_dialog_get_font_selection([self FONTSELECTIONDIALOG])] autorelease];
}

- (OGTKWidget*)okButton
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_dialog_get_ok_button([self FONTSELECTIONDIALOG])] autorelease];
}

- (OFString*)previewText
{
	return [OFString stringWithUTF8String:gtk_font_selection_dialog_get_preview_text([self FONTSELECTIONDIALOG])];
}

- (bool)setFontName:(OFString*)fontname
{
	return gtk_font_selection_dialog_set_font_name([self FONTSELECTIONDIALOG], [fontname UTF8String]);
}

- (void)setPreviewText:(OFString*)text
{
	gtk_font_selection_dialog_set_preview_text([self FONTSELECTIONDIALOG], [text UTF8String]);
}


@end