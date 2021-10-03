/*
 * OGTKPageSetup.m
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
#import "OGTKPageSetup.h"

@implementation OGTKPageSetup

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new()];

	return self;
}

- (id)initFromFile:(OFString*)fileName
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new_from_file([fileName UTF8String])];

	return self;
}

- (id)initFromGvariant:(GVariant*)variant
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new_from_gvariant(variant)];

	return self;
}

- (id)initFromKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new_from_key_file(keyFile, [groupName UTF8String])];

	return self;
}

- (GtkPageSetup*)PAGESETUP
{
	return GTK_PAGE_SETUP([self GOBJECT]);
}

- (GtkPageSetup*)copy
{
	return gtk_page_setup_copy(GTK_PAGE_SETUP([self GOBJECT]));
}

- (gdouble)getBottomMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_bottom_margin(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (gdouble)getLeftMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_left_margin(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (GtkPageOrientation)getOrientation
{
	return gtk_page_setup_get_orientation(GTK_PAGE_SETUP([self GOBJECT]));
}

- (gdouble)getPageHeight:(GtkUnit)unit
{
	return gtk_page_setup_get_page_height(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (gdouble)getPageWidth:(GtkUnit)unit
{
	return gtk_page_setup_get_page_width(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (gdouble)getPaperHeight:(GtkUnit)unit
{
	return gtk_page_setup_get_paper_height(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (GtkPaperSize*)getPaperSize
{
	return gtk_page_setup_get_paper_size(GTK_PAGE_SETUP([self GOBJECT]));
}

- (gdouble)getPaperWidth:(GtkUnit)unit
{
	return gtk_page_setup_get_paper_width(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (gdouble)getRightMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_right_margin(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (gdouble)getTopMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_top_margin(GTK_PAGE_SETUP([self GOBJECT]), unit);
}

- (bool)loadFile:(const char*)fileName
{
	return gtk_page_setup_load_file(GTK_PAGE_SETUP([self GOBJECT]), fileName);
}

- (bool)loadKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName
{
	return gtk_page_setup_load_key_file(GTK_PAGE_SETUP([self GOBJECT]), keyFile, [groupName UTF8String]);
}

- (void)setBottomMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit
{
	gtk_page_setup_set_bottom_margin(GTK_PAGE_SETUP([self GOBJECT]), margin, unit);
}

- (void)setLeftMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit
{
	gtk_page_setup_set_left_margin(GTK_PAGE_SETUP([self GOBJECT]), margin, unit);
}

- (void)setOrientation:(GtkPageOrientation)orientation
{
	gtk_page_setup_set_orientation(GTK_PAGE_SETUP([self GOBJECT]), orientation);
}

- (void)setPaperSize:(GtkPaperSize*)size
{
	gtk_page_setup_set_paper_size(GTK_PAGE_SETUP([self GOBJECT]), size);
}

- (void)setPaperSizeAndDefaultMargins:(GtkPaperSize*)size
{
	gtk_page_setup_set_paper_size_and_default_margins(GTK_PAGE_SETUP([self GOBJECT]), size);
}

- (void)setRightMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit
{
	gtk_page_setup_set_right_margin(GTK_PAGE_SETUP([self GOBJECT]), margin, unit);
}

- (void)setTopMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit
{
	gtk_page_setup_set_top_margin(GTK_PAGE_SETUP([self GOBJECT]), margin, unit);
}

- (bool)toFile:(const char*)fileName
{
	return gtk_page_setup_to_file(GTK_PAGE_SETUP([self GOBJECT]), fileName);
}

- (GVariant*)toGvariant
{
	return gtk_page_setup_to_gvariant(GTK_PAGE_SETUP([self GOBJECT]));
}

- (void)toKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName
{
	gtk_page_setup_to_key_file(GTK_PAGE_SETUP([self GOBJECT]), keyFile, [groupName UTF8String]);
}


@end