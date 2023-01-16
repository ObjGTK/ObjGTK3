/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPrintSettings.h"

@implementation OGTKPrintSettings

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new()];

	return self;
}

- (instancetype)initFromFileWithFileName:(OFString*)fileName err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new_from_file([fileName UTF8String], err)];

	return self;
}

- (instancetype)initFromGvariant:(GVariant*)variant
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new_from_gvariant(variant)];

	return self;
}

- (instancetype)initFromKeyFileWithKeyFile:(GKeyFile*)keyFile groupName:(OFString*)groupName err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new_from_key_file(keyFile, [groupName UTF8String], err)];

	return self;
}

- (GtkPrintSettings*)PRINTSETTINGS
{
	return GTK_PRINT_SETTINGS([self GOBJECT]);
}

- (OGTKPrintSettings*)copy
{
	return [[[OGTKPrintSettings alloc] initWithGObject:(GObject*)gtk_print_settings_copy([self PRINTSETTINGS])] autorelease];
}

- (void)foreachWithFunc:(GtkPrintSettingsFunc)func userData:(gpointer)userData
{
	gtk_print_settings_foreach([self PRINTSETTINGS], func, userData);
}

- (OFString*):(OFString*)key
{
	return [OFString stringWithUTF8String:gtk_print_settings_get([self PRINTSETTINGS], [key UTF8String])];
}

- (bool)bool:(OFString*)key
{
	return gtk_print_settings_get_bool([self PRINTSETTINGS], [key UTF8String]);
}

- (bool)collate
{
	return gtk_print_settings_get_collate([self PRINTSETTINGS]);
}

- (OFString*)defaultSource
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_default_source([self PRINTSETTINGS])];
}

- (OFString*)dither
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_dither([self PRINTSETTINGS])];
}

- (gdouble)double:(OFString*)key
{
	return gtk_print_settings_get_double([self PRINTSETTINGS], [key UTF8String]);
}

- (gdouble)doubleWithDefaultWithKey:(OFString*)key def:(gdouble)def
{
	return gtk_print_settings_get_double_with_default([self PRINTSETTINGS], [key UTF8String], def);
}

- (GtkPrintDuplex)duplex
{
	return gtk_print_settings_get_duplex([self PRINTSETTINGS]);
}

- (OFString*)finishings
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_finishings([self PRINTSETTINGS])];
}

- (gint)int:(OFString*)key
{
	return gtk_print_settings_get_int([self PRINTSETTINGS], [key UTF8String]);
}

- (gint)intWithDefaultWithKey:(OFString*)key def:(gint)def
{
	return gtk_print_settings_get_int_with_default([self PRINTSETTINGS], [key UTF8String], def);
}

- (gdouble)lengthWithKey:(OFString*)key unit:(GtkUnit)unit
{
	return gtk_print_settings_get_length([self PRINTSETTINGS], [key UTF8String], unit);
}

- (OFString*)mediaType
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_media_type([self PRINTSETTINGS])];
}

- (gint)ncopies
{
	return gtk_print_settings_get_n_copies([self PRINTSETTINGS]);
}

- (gint)numberUp
{
	return gtk_print_settings_get_number_up([self PRINTSETTINGS]);
}

- (GtkNumberUpLayout)numberUpLayout
{
	return gtk_print_settings_get_number_up_layout([self PRINTSETTINGS]);
}

- (GtkPageOrientation)orientation
{
	return gtk_print_settings_get_orientation([self PRINTSETTINGS]);
}

- (OFString*)outputBin
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_output_bin([self PRINTSETTINGS])];
}

- (GtkPageRange*)pageRanges:(gint*)numRanges
{
	return gtk_print_settings_get_page_ranges([self PRINTSETTINGS], numRanges);
}

- (GtkPageSet)pageSet
{
	return gtk_print_settings_get_page_set([self PRINTSETTINGS]);
}

- (gdouble)paperHeight:(GtkUnit)unit
{
	return gtk_print_settings_get_paper_height([self PRINTSETTINGS], unit);
}

- (GtkPaperSize*)paperSize
{
	return gtk_print_settings_get_paper_size([self PRINTSETTINGS]);
}

- (gdouble)paperWidth:(GtkUnit)unit
{
	return gtk_print_settings_get_paper_width([self PRINTSETTINGS], unit);
}

- (GtkPrintPages)printPages
{
	return gtk_print_settings_get_print_pages([self PRINTSETTINGS]);
}

- (OFString*)printer
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_printer([self PRINTSETTINGS])];
}

- (gdouble)printerLpi
{
	return gtk_print_settings_get_printer_lpi([self PRINTSETTINGS]);
}

- (GtkPrintQuality)quality
{
	return gtk_print_settings_get_quality([self PRINTSETTINGS]);
}

- (gint)resolution
{
	return gtk_print_settings_get_resolution([self PRINTSETTINGS]);
}

- (gint)resolutionX
{
	return gtk_print_settings_get_resolution_x([self PRINTSETTINGS]);
}

- (gint)resolutionY
{
	return gtk_print_settings_get_resolution_y([self PRINTSETTINGS]);
}

- (bool)reverse
{
	return gtk_print_settings_get_reverse([self PRINTSETTINGS]);
}

- (gdouble)scale
{
	return gtk_print_settings_get_scale([self PRINTSETTINGS]);
}

- (bool)useColor
{
	return gtk_print_settings_get_use_color([self PRINTSETTINGS]);
}

- (bool)hasKey:(OFString*)key
{
	return gtk_print_settings_has_key([self PRINTSETTINGS], [key UTF8String]);
}

- (bool)loadFileWithFileName:(OFString*)fileName err:(GError**)err
{
	return gtk_print_settings_load_file([self PRINTSETTINGS], [fileName UTF8String], err);
}

- (bool)loadKeyFileWithKeyFile:(GKeyFile*)keyFile groupName:(OFString*)groupName err:(GError**)err
{
	return gtk_print_settings_load_key_file([self PRINTSETTINGS], keyFile, [groupName UTF8String], err);
}

- (void)setWithKey:(OFString*)key value:(OFString*)value
{
	gtk_print_settings_set([self PRINTSETTINGS], [key UTF8String], [value UTF8String]);
}

- (void)setBoolWithKey:(OFString*)key value:(bool)value
{
	gtk_print_settings_set_bool([self PRINTSETTINGS], [key UTF8String], value);
}

- (void)setCollate:(bool)collate
{
	gtk_print_settings_set_collate([self PRINTSETTINGS], collate);
}

- (void)setDefaultSource:(OFString*)defaultSource
{
	gtk_print_settings_set_default_source([self PRINTSETTINGS], [defaultSource UTF8String]);
}

- (void)setDither:(OFString*)dither
{
	gtk_print_settings_set_dither([self PRINTSETTINGS], [dither UTF8String]);
}

- (void)setDoubleWithKey:(OFString*)key value:(gdouble)value
{
	gtk_print_settings_set_double([self PRINTSETTINGS], [key UTF8String], value);
}

- (void)setDuplex:(GtkPrintDuplex)duplex
{
	gtk_print_settings_set_duplex([self PRINTSETTINGS], duplex);
}

- (void)setFinishings:(OFString*)finishings
{
	gtk_print_settings_set_finishings([self PRINTSETTINGS], [finishings UTF8String]);
}

- (void)setIntWithKey:(OFString*)key value:(gint)value
{
	gtk_print_settings_set_int([self PRINTSETTINGS], [key UTF8String], value);
}

- (void)setLengthWithKey:(OFString*)key value:(gdouble)value unit:(GtkUnit)unit
{
	gtk_print_settings_set_length([self PRINTSETTINGS], [key UTF8String], value, unit);
}

- (void)setMediaType:(OFString*)mediaType
{
	gtk_print_settings_set_media_type([self PRINTSETTINGS], [mediaType UTF8String]);
}

- (void)setNcopies:(gint)numCopies
{
	gtk_print_settings_set_n_copies([self PRINTSETTINGS], numCopies);
}

- (void)setNumberUp:(gint)numberUp
{
	gtk_print_settings_set_number_up([self PRINTSETTINGS], numberUp);
}

- (void)setNumberUpLayout:(GtkNumberUpLayout)numberUpLayout
{
	gtk_print_settings_set_number_up_layout([self PRINTSETTINGS], numberUpLayout);
}

- (void)setOrientation:(GtkPageOrientation)orientation
{
	gtk_print_settings_set_orientation([self PRINTSETTINGS], orientation);
}

- (void)setOutputBin:(OFString*)outputBin
{
	gtk_print_settings_set_output_bin([self PRINTSETTINGS], [outputBin UTF8String]);
}

- (void)setPageRangesWithPageRanges:(GtkPageRange*)pageRanges numRanges:(gint)numRanges
{
	gtk_print_settings_set_page_ranges([self PRINTSETTINGS], pageRanges, numRanges);
}

- (void)setPageSet:(GtkPageSet)pageSet
{
	gtk_print_settings_set_page_set([self PRINTSETTINGS], pageSet);
}

- (void)setPaperHeightWithHeight:(gdouble)height unit:(GtkUnit)unit
{
	gtk_print_settings_set_paper_height([self PRINTSETTINGS], height, unit);
}

- (void)setPaperSize:(GtkPaperSize*)paperSize
{
	gtk_print_settings_set_paper_size([self PRINTSETTINGS], paperSize);
}

- (void)setPaperWidthWithWidth:(gdouble)width unit:(GtkUnit)unit
{
	gtk_print_settings_set_paper_width([self PRINTSETTINGS], width, unit);
}

- (void)setPrintPages:(GtkPrintPages)pages
{
	gtk_print_settings_set_print_pages([self PRINTSETTINGS], pages);
}

- (void)setPrinter:(OFString*)printer
{
	gtk_print_settings_set_printer([self PRINTSETTINGS], [printer UTF8String]);
}

- (void)setPrinterLpi:(gdouble)lpi
{
	gtk_print_settings_set_printer_lpi([self PRINTSETTINGS], lpi);
}

- (void)setQuality:(GtkPrintQuality)quality
{
	gtk_print_settings_set_quality([self PRINTSETTINGS], quality);
}

- (void)setResolution:(gint)resolution
{
	gtk_print_settings_set_resolution([self PRINTSETTINGS], resolution);
}

- (void)setResolutionXyWithResolutionX:(gint)resolutionX resolutionY:(gint)resolutionY
{
	gtk_print_settings_set_resolution_xy([self PRINTSETTINGS], resolutionX, resolutionY);
}

- (void)setReverse:(bool)reverse
{
	gtk_print_settings_set_reverse([self PRINTSETTINGS], reverse);
}

- (void)setScale:(gdouble)scale
{
	gtk_print_settings_set_scale([self PRINTSETTINGS], scale);
}

- (void)setUseColor:(bool)useColor
{
	gtk_print_settings_set_use_color([self PRINTSETTINGS], useColor);
}

- (bool)toFileWithFileName:(OFString*)fileName err:(GError**)err
{
	return gtk_print_settings_to_file([self PRINTSETTINGS], [fileName UTF8String], err);
}

- (GVariant*)toGvariant
{
	return gtk_print_settings_to_gvariant([self PRINTSETTINGS]);
}

- (void)toKeyFileWithKeyFile:(GKeyFile*)keyFile groupName:(OFString*)groupName
{
	gtk_print_settings_to_key_file([self PRINTSETTINGS], keyFile, [groupName UTF8String]);
}

- (void)unset:(OFString*)key
{
	gtk_print_settings_unset([self PRINTSETTINGS], [key UTF8String]);
}


@end