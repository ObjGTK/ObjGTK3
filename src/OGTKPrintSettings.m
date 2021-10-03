/*
 * OGTKPrintSettings.m
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
#import "OGTKPrintSettings.h"

@implementation OGTKPrintSettings

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new()];

	return self;
}

- (id)initFromFile:(OFString*)fileName
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new_from_file([fileName UTF8String])];

	return self;
}

- (id)initFromGvariant:(GVariant*)variant
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new_from_gvariant(variant)];

	return self;
}

- (id)initFromKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName
{
	self = [super initWithGObject:(GObject*)gtk_print_settings_new_from_key_file(keyFile, [groupName UTF8String])];

	return self;
}

- (GtkPrintSettings*)PRINTSETTINGS
{
	return GTK_PRINT_SETTINGS([self GOBJECT]);
}

- (GtkPrintSettings*)copy
{
	return gtk_print_settings_copy(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (void)foreachWithFunc:(GtkPrintSettingsFunc)func andUserData:(gpointer)userData
{
	gtk_print_settings_foreach(GTK_PRINT_SETTINGS([self GOBJECT]), func, userData);
}

- (OFString*)get:(OFString*)key
{
	return [OFString stringWithUTF8String:gtk_print_settings_get(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String])];
}

- (bool)getBool:(OFString*)key
{
	return gtk_print_settings_get_bool(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String]);
}

- (bool)getCollate
{
	return gtk_print_settings_get_collate(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (OFString*)getDefaultSource
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_default_source(GTK_PRINT_SETTINGS([self GOBJECT]))];
}

- (OFString*)getDither
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_dither(GTK_PRINT_SETTINGS([self GOBJECT]))];
}

- (gdouble)getDouble:(OFString*)key
{
	return gtk_print_settings_get_double(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String]);
}

- (gdouble)getDoubleWithDefaultWithKey:(OFString*)key andDef:(gdouble)def
{
	return gtk_print_settings_get_double_with_default(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], def);
}

- (GtkPrintDuplex)getDuplex
{
	return gtk_print_settings_get_duplex(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (OFString*)getFinishings
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_finishings(GTK_PRINT_SETTINGS([self GOBJECT]))];
}

- (gint)getInt:(OFString*)key
{
	return gtk_print_settings_get_int(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String]);
}

- (gint)getIntWithDefaultWithKey:(OFString*)key andDef:(gint)def
{
	return gtk_print_settings_get_int_with_default(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], def);
}

- (gdouble)getLengthWithKey:(OFString*)key andUnit:(GtkUnit)unit
{
	return gtk_print_settings_get_length(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], unit);
}

- (OFString*)getMediaType
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_media_type(GTK_PRINT_SETTINGS([self GOBJECT]))];
}

- (gint)getNcopies
{
	return gtk_print_settings_get_n_copies(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gint)getNumberUp
{
	return gtk_print_settings_get_number_up(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (GtkNumberUpLayout)getNumberUpLayout
{
	return gtk_print_settings_get_number_up_layout(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (GtkPageOrientation)getOrientation
{
	return gtk_print_settings_get_orientation(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (OFString*)getOutputBin
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_output_bin(GTK_PRINT_SETTINGS([self GOBJECT]))];
}

- (GtkPageRange*)getPageRanges:(gint*)numRanges
{
	return gtk_print_settings_get_page_ranges(GTK_PRINT_SETTINGS([self GOBJECT]), numRanges);
}

- (GtkPageSet)getPageSet
{
	return gtk_print_settings_get_page_set(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gdouble)getPaperHeight:(GtkUnit)unit
{
	return gtk_print_settings_get_paper_height(GTK_PRINT_SETTINGS([self GOBJECT]), unit);
}

- (GtkPaperSize*)getPaperSize
{
	return gtk_print_settings_get_paper_size(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gdouble)getPaperWidth:(GtkUnit)unit
{
	return gtk_print_settings_get_paper_width(GTK_PRINT_SETTINGS([self GOBJECT]), unit);
}

- (GtkPrintPages)getPrintPages
{
	return gtk_print_settings_get_print_pages(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (OFString*)getPrinter
{
	return [OFString stringWithUTF8String:gtk_print_settings_get_printer(GTK_PRINT_SETTINGS([self GOBJECT]))];
}

- (gdouble)getPrinterLpi
{
	return gtk_print_settings_get_printer_lpi(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (GtkPrintQuality)getQuality
{
	return gtk_print_settings_get_quality(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gint)getResolution
{
	return gtk_print_settings_get_resolution(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gint)getResolutionX
{
	return gtk_print_settings_get_resolution_x(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gint)getResolutionY
{
	return gtk_print_settings_get_resolution_y(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (bool)getReverse
{
	return gtk_print_settings_get_reverse(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (gdouble)getScale
{
	return gtk_print_settings_get_scale(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (bool)getUseColor
{
	return gtk_print_settings_get_use_color(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (bool)hasKey:(OFString*)key
{
	return gtk_print_settings_has_key(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String]);
}

- (bool)loadFile:(OFString*)fileName
{
	return gtk_print_settings_load_file(GTK_PRINT_SETTINGS([self GOBJECT]), [fileName UTF8String]);
}

- (bool)loadKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName
{
	return gtk_print_settings_load_key_file(GTK_PRINT_SETTINGS([self GOBJECT]), keyFile, [groupName UTF8String]);
}

- (void)setWithKey:(OFString*)key andValue:(OFString*)value
{
	gtk_print_settings_set(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], [value UTF8String]);
}

- (void)setBoolWithKey:(OFString*)key andValue:(bool)value
{
	gtk_print_settings_set_bool(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], value);
}

- (void)setCollate:(bool)collate
{
	gtk_print_settings_set_collate(GTK_PRINT_SETTINGS([self GOBJECT]), collate);
}

- (void)setDefaultSource:(OFString*)defaultSource
{
	gtk_print_settings_set_default_source(GTK_PRINT_SETTINGS([self GOBJECT]), [defaultSource UTF8String]);
}

- (void)setDither:(OFString*)dither
{
	gtk_print_settings_set_dither(GTK_PRINT_SETTINGS([self GOBJECT]), [dither UTF8String]);
}

- (void)setDoubleWithKey:(OFString*)key andValue:(gdouble)value
{
	gtk_print_settings_set_double(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], value);
}

- (void)setDuplex:(GtkPrintDuplex)duplex
{
	gtk_print_settings_set_duplex(GTK_PRINT_SETTINGS([self GOBJECT]), duplex);
}

- (void)setFinishings:(OFString*)finishings
{
	gtk_print_settings_set_finishings(GTK_PRINT_SETTINGS([self GOBJECT]), [finishings UTF8String]);
}

- (void)setIntWithKey:(OFString*)key andValue:(gint)value
{
	gtk_print_settings_set_int(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], value);
}

- (void)setLengthWithKey:(OFString*)key andValue:(gdouble)value andUnit:(GtkUnit)unit
{
	gtk_print_settings_set_length(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String], value, unit);
}

- (void)setMediaType:(OFString*)mediaType
{
	gtk_print_settings_set_media_type(GTK_PRINT_SETTINGS([self GOBJECT]), [mediaType UTF8String]);
}

- (void)setNcopies:(gint)numCopies
{
	gtk_print_settings_set_n_copies(GTK_PRINT_SETTINGS([self GOBJECT]), numCopies);
}

- (void)setNumberUp:(gint)numberUp
{
	gtk_print_settings_set_number_up(GTK_PRINT_SETTINGS([self GOBJECT]), numberUp);
}

- (void)setNumberUpLayout:(GtkNumberUpLayout)numberUpLayout
{
	gtk_print_settings_set_number_up_layout(GTK_PRINT_SETTINGS([self GOBJECT]), numberUpLayout);
}

- (void)setOrientation:(GtkPageOrientation)orientation
{
	gtk_print_settings_set_orientation(GTK_PRINT_SETTINGS([self GOBJECT]), orientation);
}

- (void)setOutputBin:(OFString*)outputBin
{
	gtk_print_settings_set_output_bin(GTK_PRINT_SETTINGS([self GOBJECT]), [outputBin UTF8String]);
}

- (void)setPageRangesWithPageRanges:(GtkPageRange*)pageRanges andNumRanges:(gint)numRanges
{
	gtk_print_settings_set_page_ranges(GTK_PRINT_SETTINGS([self GOBJECT]), pageRanges, numRanges);
}

- (void)setPageSet:(GtkPageSet)pageSet
{
	gtk_print_settings_set_page_set(GTK_PRINT_SETTINGS([self GOBJECT]), pageSet);
}

- (void)setPaperHeightWithHeight:(gdouble)height andUnit:(GtkUnit)unit
{
	gtk_print_settings_set_paper_height(GTK_PRINT_SETTINGS([self GOBJECT]), height, unit);
}

- (void)setPaperSize:(GtkPaperSize*)paperSize
{
	gtk_print_settings_set_paper_size(GTK_PRINT_SETTINGS([self GOBJECT]), paperSize);
}

- (void)setPaperWidthWithWidth:(gdouble)width andUnit:(GtkUnit)unit
{
	gtk_print_settings_set_paper_width(GTK_PRINT_SETTINGS([self GOBJECT]), width, unit);
}

- (void)setPrintPages:(GtkPrintPages)pages
{
	gtk_print_settings_set_print_pages(GTK_PRINT_SETTINGS([self GOBJECT]), pages);
}

- (void)setPrinter:(OFString*)printer
{
	gtk_print_settings_set_printer(GTK_PRINT_SETTINGS([self GOBJECT]), [printer UTF8String]);
}

- (void)setPrinterLpi:(gdouble)lpi
{
	gtk_print_settings_set_printer_lpi(GTK_PRINT_SETTINGS([self GOBJECT]), lpi);
}

- (void)setQuality:(GtkPrintQuality)quality
{
	gtk_print_settings_set_quality(GTK_PRINT_SETTINGS([self GOBJECT]), quality);
}

- (void)setResolution:(gint)resolution
{
	gtk_print_settings_set_resolution(GTK_PRINT_SETTINGS([self GOBJECT]), resolution);
}

- (void)setResolutionXyWithResolutionX:(gint)resolutionX andResolutionY:(gint)resolutionY
{
	gtk_print_settings_set_resolution_xy(GTK_PRINT_SETTINGS([self GOBJECT]), resolutionX, resolutionY);
}

- (void)setReverse:(bool)reverse
{
	gtk_print_settings_set_reverse(GTK_PRINT_SETTINGS([self GOBJECT]), reverse);
}

- (void)setScale:(gdouble)scale
{
	gtk_print_settings_set_scale(GTK_PRINT_SETTINGS([self GOBJECT]), scale);
}

- (void)setUseColor:(bool)useColor
{
	gtk_print_settings_set_use_color(GTK_PRINT_SETTINGS([self GOBJECT]), useColor);
}

- (bool)toFile:(OFString*)fileName
{
	return gtk_print_settings_to_file(GTK_PRINT_SETTINGS([self GOBJECT]), [fileName UTF8String]);
}

- (GVariant*)toGvariant
{
	return gtk_print_settings_to_gvariant(GTK_PRINT_SETTINGS([self GOBJECT]));
}

- (void)toKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName
{
	gtk_print_settings_to_key_file(GTK_PRINT_SETTINGS([self GOBJECT]), keyFile, [groupName UTF8String]);
}

- (void)unset:(OFString*)key
{
	gtk_print_settings_unset(GTK_PRINT_SETTINGS([self GOBJECT]), [key UTF8String]);
}


@end