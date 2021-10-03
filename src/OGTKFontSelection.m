/*
 * OGTKFontSelection.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKFontSelection.h"

@implementation OGTKFontSelection

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_font_selection_new()];

	return self;
}

- (GtkFontSelection*)FONTSELECTION
{
	return GTK_FONT_SELECTION([self GOBJECT]);
}

- (PangoFontFace*)getFace
{
	return gtk_font_selection_get_face(GTK_FONT_SELECTION([self GOBJECT]));
}

- (OGTKWidget*)getFaceList
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_face_list(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (PangoFontFamily*)getFamily
{
	return gtk_font_selection_get_family(GTK_FONT_SELECTION([self GOBJECT]));
}

- (OGTKWidget*)getFamilyList
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_family_list(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (OFString*)getFontName
{
	return [OFString stringWithUTF8String:gtk_font_selection_get_font_name(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (OGTKWidget*)getPreviewEntry
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_preview_entry(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (OFString*)getPreviewText
{
	return [OFString stringWithUTF8String:gtk_font_selection_get_preview_text(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (gint)getSize
{
	return gtk_font_selection_get_size(GTK_FONT_SELECTION([self GOBJECT]));
}

- (OGTKWidget*)getSizeEntry
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_size_entry(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (OGTKWidget*)getSizeList
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_font_selection_get_size_list(GTK_FONT_SELECTION([self GOBJECT]))];
}

- (bool)setFontName:(OFString*)fontname
{
	return gtk_font_selection_set_font_name(GTK_FONT_SELECTION([self GOBJECT]), [fontname UTF8String]);
}

- (void)setPreviewText:(OFString*)text
{
	gtk_font_selection_set_preview_text(GTK_FONT_SELECTION([self GOBJECT]), [text UTF8String]);
}


@end