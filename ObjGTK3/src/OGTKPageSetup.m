/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPageSetup.h"

@implementation OGTKPageSetup

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new()];

	return self;
}

- (instancetype)initFromFileWithFileName:(OFString*)fileName err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new_from_file([fileName UTF8String], err)];

	return self;
}

- (instancetype)initFromGvariant:(GVariant*)variant
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new_from_gvariant(variant)];

	return self;
}

- (instancetype)initFromKeyFileWithKeyFile:(GKeyFile*)keyFile groupName:(OFString*)groupName err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gtk_page_setup_new_from_key_file(keyFile, [groupName UTF8String], err)];

	return self;
}

- (GtkPageSetup*)PAGESETUP
{
	return GTK_PAGE_SETUP([self GOBJECT]);
}

- (OGTKPageSetup*)copy
{
	return [[[OGTKPageSetup alloc] initWithGObject:(GObject*)gtk_page_setup_copy([self PAGESETUP])] autorelease];
}

- (gdouble)bottomMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_bottom_margin([self PAGESETUP], unit);
}

- (gdouble)leftMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_left_margin([self PAGESETUP], unit);
}

- (GtkPageOrientation)orientation
{
	return gtk_page_setup_get_orientation([self PAGESETUP]);
}

- (gdouble)pageHeight:(GtkUnit)unit
{
	return gtk_page_setup_get_page_height([self PAGESETUP], unit);
}

- (gdouble)pageWidth:(GtkUnit)unit
{
	return gtk_page_setup_get_page_width([self PAGESETUP], unit);
}

- (gdouble)paperHeight:(GtkUnit)unit
{
	return gtk_page_setup_get_paper_height([self PAGESETUP], unit);
}

- (GtkPaperSize*)paperSize
{
	return gtk_page_setup_get_paper_size([self PAGESETUP]);
}

- (gdouble)paperWidth:(GtkUnit)unit
{
	return gtk_page_setup_get_paper_width([self PAGESETUP], unit);
}

- (gdouble)rightMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_right_margin([self PAGESETUP], unit);
}

- (gdouble)topMargin:(GtkUnit)unit
{
	return gtk_page_setup_get_top_margin([self PAGESETUP], unit);
}

- (bool)loadFileWithFileName:(OFString*)fileName err:(GError**)err
{
	return gtk_page_setup_load_file([self PAGESETUP], [fileName UTF8String], err);
}

- (bool)loadKeyFileWithKeyFile:(GKeyFile*)keyFile groupName:(OFString*)groupName err:(GError**)err
{
	return gtk_page_setup_load_key_file([self PAGESETUP], keyFile, [groupName UTF8String], err);
}

- (void)setBottomMarginWithMargin:(gdouble)margin unit:(GtkUnit)unit
{
	gtk_page_setup_set_bottom_margin([self PAGESETUP], margin, unit);
}

- (void)setLeftMarginWithMargin:(gdouble)margin unit:(GtkUnit)unit
{
	gtk_page_setup_set_left_margin([self PAGESETUP], margin, unit);
}

- (void)setOrientation:(GtkPageOrientation)orientation
{
	gtk_page_setup_set_orientation([self PAGESETUP], orientation);
}

- (void)setPaperSize:(GtkPaperSize*)size
{
	gtk_page_setup_set_paper_size([self PAGESETUP], size);
}

- (void)setPaperSizeAndDefaultMargins:(GtkPaperSize*)size
{
	gtk_page_setup_set_paper_size_and_default_margins([self PAGESETUP], size);
}

- (void)setRightMarginWithMargin:(gdouble)margin unit:(GtkUnit)unit
{
	gtk_page_setup_set_right_margin([self PAGESETUP], margin, unit);
}

- (void)setTopMarginWithMargin:(gdouble)margin unit:(GtkUnit)unit
{
	gtk_page_setup_set_top_margin([self PAGESETUP], margin, unit);
}

- (bool)toFileWithFileName:(OFString*)fileName err:(GError**)err
{
	return gtk_page_setup_to_file([self PAGESETUP], [fileName UTF8String], err);
}

- (GVariant*)toGvariant
{
	return gtk_page_setup_to_gvariant([self PAGESETUP]);
}

- (void)toKeyFileWithKeyFile:(GKeyFile*)keyFile groupName:(OFString*)groupName
{
	gtk_page_setup_to_key_file([self PAGESETUP], keyFile, [groupName UTF8String]);
}


@end