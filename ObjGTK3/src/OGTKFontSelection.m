/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFontSelection.h"

#import <OGPango/OGPangoFontFamily.h>
#import <OGPango/OGPangoFontFace.h>
#import "OGTKWidget.h"

@implementation OGTKFontSelection

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_font_selection_new()];

	return self;
}

- (GtkFontSelection*)FONTSELECTION
{
	return GTK_FONT_SELECTION([self GOBJECT]);
}

- (OGPangoFontFace*)face
{
	return [[[OGPangoFontFace alloc] initWithGObject:(GObject*)gtk_font_selection_get_face([self FONTSELECTION])] autorelease];
}

- (OGTKWidget*)faceList
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_face_list([self FONTSELECTION])] autorelease];
}

- (OGPangoFontFamily*)family
{
	return [[[OGPangoFontFamily alloc] initWithGObject:(GObject*)gtk_font_selection_get_family([self FONTSELECTION])] autorelease];
}

- (OGTKWidget*)familyList
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_family_list([self FONTSELECTION])] autorelease];
}

- (OFString*)fontName
{
	return [OFString stringWithUTF8String:gtk_font_selection_get_font_name([self FONTSELECTION])];
}

- (OGTKWidget*)previewEntry
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_preview_entry([self FONTSELECTION])] autorelease];
}

- (OFString*)previewText
{
	return [OFString stringWithUTF8String:gtk_font_selection_get_preview_text([self FONTSELECTION])];
}

- (gint)size
{
	return gtk_font_selection_get_size([self FONTSELECTION]);
}

- (OGTKWidget*)sizeEntry
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_size_entry([self FONTSELECTION])] autorelease];
}

- (OGTKWidget*)sizeList
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_size_list([self FONTSELECTION])] autorelease];
}

- (bool)setFontName:(OFString*)fontname
{
	return gtk_font_selection_set_font_name([self FONTSELECTION], [fontname UTF8String]);
}

- (void)setPreviewText:(OFString*)text
{
	gtk_font_selection_set_preview_text([self FONTSELECTION], [text UTF8String]);
}


@end