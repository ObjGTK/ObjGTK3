/*
 * OGTKExpander.m
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
#import "OGTKExpander.h"

@implementation OGTKExpander

- (id)init:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_expander_new([label UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_expander_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkExpander*)EXPANDER
{
	return GTK_EXPANDER([self GOBJECT]);
}

- (bool)getExpanded
{
	return gtk_expander_get_expanded(GTK_EXPANDER([self GOBJECT]));
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_expander_get_label(GTK_EXPANDER([self GOBJECT]))];
}

- (bool)getLabelFill
{
	return gtk_expander_get_label_fill(GTK_EXPANDER([self GOBJECT]));
}

- (OGTKWidget*)getLabelWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_expander_get_label_widget(GTK_EXPANDER([self GOBJECT]))];
}

- (bool)getResizeToplevel
{
	return gtk_expander_get_resize_toplevel(GTK_EXPANDER([self GOBJECT]));
}

- (gint)getSpacing
{
	return gtk_expander_get_spacing(GTK_EXPANDER([self GOBJECT]));
}

- (bool)getUseMarkup
{
	return gtk_expander_get_use_markup(GTK_EXPANDER([self GOBJECT]));
}

- (bool)getUseUnderline
{
	return gtk_expander_get_use_underline(GTK_EXPANDER([self GOBJECT]));
}

- (void)setExpanded:(bool)expanded
{
	gtk_expander_set_expanded(GTK_EXPANDER([self GOBJECT]), expanded);
}

- (void)setLabel:(OFString*)label
{
	gtk_expander_set_label(GTK_EXPANDER([self GOBJECT]), [label UTF8String]);
}

- (void)setLabelFill:(bool)labelFill
{
	gtk_expander_set_label_fill(GTK_EXPANDER([self GOBJECT]), labelFill);
}

- (void)setLabelWidget:(OGTKWidget*)labelWidget
{
	gtk_expander_set_label_widget(GTK_EXPANDER([self GOBJECT]), [labelWidget WIDGET]);
}

- (void)setResizeToplevel:(bool)resizeToplevel
{
	gtk_expander_set_resize_toplevel(GTK_EXPANDER([self GOBJECT]), resizeToplevel);
}

- (void)setSpacing:(gint)spacing
{
	gtk_expander_set_spacing(GTK_EXPANDER([self GOBJECT]), spacing);
}

- (void)setUseMarkup:(bool)useMarkup
{
	gtk_expander_set_use_markup(GTK_EXPANDER([self GOBJECT]), useMarkup);
}

- (void)setUseUnderline:(bool)useUnderline
{
	gtk_expander_set_use_underline(GTK_EXPANDER([self GOBJECT]), useUnderline);
}


@end