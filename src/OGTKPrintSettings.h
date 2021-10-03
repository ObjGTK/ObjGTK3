/*
 * OGTKPrintSettings.h
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
#import "OGTKBase.h"

@interface OGTKPrintSettings : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initFromFile:(OFString*)fileName;
- (id)initFromGvariant:(GVariant*)variant;
- (id)initFromKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;

/**
 * Methods
 */

- (GtkPrintSettings*)PRINTSETTINGS;

/**
 * - (GtkPrintSettings**)copy;
 *
 * @returns GtkPrintSettings*
 */
- (GtkPrintSettings*)copy;

/**
 * - (void*)foreachWithFunc:(GtkPrintSettingsFunc)func andUserData:(gpointer)userData;
 *
 * @param func
 * @param userData
 */
- (void)foreachWithFunc:(GtkPrintSettingsFunc)func andUserData:(gpointer)userData;

/**
 * - (OFString**)get:(OFString*)key;
 *
 * @param key
 * @returns OFString*
 */
- (OFString*)get:(OFString*)key;

/**
 * - (bool*)getBool:(OFString*)key;
 *
 * @param key
 * @returns bool
 */
- (bool)getBool:(OFString*)key;

/**
 * - (bool*)getCollate;
 *
 * @returns bool
 */
- (bool)getCollate;

/**
 * - (OFString**)getDefaultSource;
 *
 * @returns OFString*
 */
- (OFString*)getDefaultSource;

/**
 * - (OFString**)getDither;
 *
 * @returns OFString*
 */
- (OFString*)getDither;

/**
 * - (gdouble*)getDouble:(OFString*)key;
 *
 * @param key
 * @returns gdouble
 */
- (gdouble)getDouble:(OFString*)key;

/**
 * - (gdouble*)getDoubleWithDefaultWithKey:(OFString*)key andDef:(gdouble)def;
 *
 * @param key
 * @param def
 * @returns gdouble
 */
- (gdouble)getDoubleWithDefaultWithKey:(OFString*)key andDef:(gdouble)def;

/**
 * - (GtkPrintDuplex*)getDuplex;
 *
 * @returns GtkPrintDuplex
 */
- (GtkPrintDuplex)getDuplex;

/**
 * - (OFString**)getFinishings;
 *
 * @returns OFString*
 */
- (OFString*)getFinishings;

/**
 * - (gint*)getInt:(OFString*)key;
 *
 * @param key
 * @returns gint
 */
- (gint)getInt:(OFString*)key;

/**
 * - (gint*)getIntWithDefaultWithKey:(OFString*)key andDef:(gint)def;
 *
 * @param key
 * @param def
 * @returns gint
 */
- (gint)getIntWithDefaultWithKey:(OFString*)key andDef:(gint)def;

/**
 * - (gdouble*)getLengthWithKey:(OFString*)key andUnit:(GtkUnit)unit;
 *
 * @param key
 * @param unit
 * @returns gdouble
 */
- (gdouble)getLengthWithKey:(OFString*)key andUnit:(GtkUnit)unit;

/**
 * - (OFString**)getMediaType;
 *
 * @returns OFString*
 */
- (OFString*)getMediaType;

/**
 * - (gint*)getNcopies;
 *
 * @returns gint
 */
- (gint)getNcopies;

/**
 * - (gint*)getNumberUp;
 *
 * @returns gint
 */
- (gint)getNumberUp;

/**
 * - (GtkNumberUpLayout*)getNumberUpLayout;
 *
 * @returns GtkNumberUpLayout
 */
- (GtkNumberUpLayout)getNumberUpLayout;

/**
 * - (GtkPageOrientation*)getOrientation;
 *
 * @returns GtkPageOrientation
 */
- (GtkPageOrientation)getOrientation;

/**
 * - (OFString**)getOutputBin;
 *
 * @returns OFString*
 */
- (OFString*)getOutputBin;

/**
 * - (GtkPageRange**)getPageRanges:(gint*)numRanges;
 *
 * @param numRanges
 * @returns GtkPageRange*
 */
- (GtkPageRange*)getPageRanges:(gint*)numRanges;

/**
 * - (GtkPageSet*)getPageSet;
 *
 * @returns GtkPageSet
 */
- (GtkPageSet)getPageSet;

/**
 * - (gdouble*)getPaperHeight:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getPaperHeight:(GtkUnit)unit;

/**
 * - (GtkPaperSize**)getPaperSize;
 *
 * @returns GtkPaperSize*
 */
- (GtkPaperSize*)getPaperSize;

/**
 * - (gdouble*)getPaperWidth:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getPaperWidth:(GtkUnit)unit;

/**
 * - (GtkPrintPages*)getPrintPages;
 *
 * @returns GtkPrintPages
 */
- (GtkPrintPages)getPrintPages;

/**
 * - (OFString**)getPrinter;
 *
 * @returns OFString*
 */
- (OFString*)getPrinter;

/**
 * - (gdouble*)getPrinterLpi;
 *
 * @returns gdouble
 */
- (gdouble)getPrinterLpi;

/**
 * - (GtkPrintQuality*)getQuality;
 *
 * @returns GtkPrintQuality
 */
- (GtkPrintQuality)getQuality;

/**
 * - (gint*)getResolution;
 *
 * @returns gint
 */
- (gint)getResolution;

/**
 * - (gint*)getResolutionX;
 *
 * @returns gint
 */
- (gint)getResolutionX;

/**
 * - (gint*)getResolutionY;
 *
 * @returns gint
 */
- (gint)getResolutionY;

/**
 * - (bool*)getReverse;
 *
 * @returns bool
 */
- (bool)getReverse;

/**
 * - (gdouble*)getScale;
 *
 * @returns gdouble
 */
- (gdouble)getScale;

/**
 * - (bool*)getUseColor;
 *
 * @returns bool
 */
- (bool)getUseColor;

/**
 * - (bool*)hasKey:(OFString*)key;
 *
 * @param key
 * @returns bool
 */
- (bool)hasKey:(OFString*)key;

/**
 * - (bool*)loadFile:(OFString*)fileName;
 *
 * @param fileName
 * @returns bool
 */
- (bool)loadFile:(OFString*)fileName;

/**
 * - (bool*)loadKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;
 *
 * @param keyFile
 * @param groupName
 * @returns bool
 */
- (bool)loadKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;

/**
 * - (void*)setWithKey:(OFString*)key andValue:(OFString*)value;
 *
 * @param key
 * @param value
 */
- (void)setWithKey:(OFString*)key andValue:(OFString*)value;

/**
 * - (void*)setBoolWithKey:(OFString*)key andValue:(bool)value;
 *
 * @param key
 * @param value
 */
- (void)setBoolWithKey:(OFString*)key andValue:(bool)value;

/**
 * - (void*)setCollate:(bool)collate;
 *
 * @param collate
 */
- (void)setCollate:(bool)collate;

/**
 * - (void*)setDefaultSource:(OFString*)defaultSource;
 *
 * @param defaultSource
 */
- (void)setDefaultSource:(OFString*)defaultSource;

/**
 * - (void*)setDither:(OFString*)dither;
 *
 * @param dither
 */
- (void)setDither:(OFString*)dither;

/**
 * - (void*)setDoubleWithKey:(OFString*)key andValue:(gdouble)value;
 *
 * @param key
 * @param value
 */
- (void)setDoubleWithKey:(OFString*)key andValue:(gdouble)value;

/**
 * - (void*)setDuplex:(GtkPrintDuplex)duplex;
 *
 * @param duplex
 */
- (void)setDuplex:(GtkPrintDuplex)duplex;

/**
 * - (void*)setFinishings:(OFString*)finishings;
 *
 * @param finishings
 */
- (void)setFinishings:(OFString*)finishings;

/**
 * - (void*)setIntWithKey:(OFString*)key andValue:(gint)value;
 *
 * @param key
 * @param value
 */
- (void)setIntWithKey:(OFString*)key andValue:(gint)value;

/**
 * - (void*)setLengthWithKey:(OFString*)key andValue:(gdouble)value andUnit:(GtkUnit)unit;
 *
 * @param key
 * @param value
 * @param unit
 */
- (void)setLengthWithKey:(OFString*)key andValue:(gdouble)value andUnit:(GtkUnit)unit;

/**
 * - (void*)setMediaType:(OFString*)mediaType;
 *
 * @param mediaType
 */
- (void)setMediaType:(OFString*)mediaType;

/**
 * - (void*)setNcopies:(gint)numCopies;
 *
 * @param numCopies
 */
- (void)setNcopies:(gint)numCopies;

/**
 * - (void*)setNumberUp:(gint)numberUp;
 *
 * @param numberUp
 */
- (void)setNumberUp:(gint)numberUp;

/**
 * - (void*)setNumberUpLayout:(GtkNumberUpLayout)numberUpLayout;
 *
 * @param numberUpLayout
 */
- (void)setNumberUpLayout:(GtkNumberUpLayout)numberUpLayout;

/**
 * - (void*)setOrientation:(GtkPageOrientation)orientation;
 *
 * @param orientation
 */
- (void)setOrientation:(GtkPageOrientation)orientation;

/**
 * - (void*)setOutputBin:(OFString*)outputBin;
 *
 * @param outputBin
 */
- (void)setOutputBin:(OFString*)outputBin;

/**
 * - (void*)setPageRangesWithPageRanges:(GtkPageRange*)pageRanges andNumRanges:(gint)numRanges;
 *
 * @param pageRanges
 * @param numRanges
 */
- (void)setPageRangesWithPageRanges:(GtkPageRange*)pageRanges andNumRanges:(gint)numRanges;

/**
 * - (void*)setPageSet:(GtkPageSet)pageSet;
 *
 * @param pageSet
 */
- (void)setPageSet:(GtkPageSet)pageSet;

/**
 * - (void*)setPaperHeightWithHeight:(gdouble)height andUnit:(GtkUnit)unit;
 *
 * @param height
 * @param unit
 */
- (void)setPaperHeightWithHeight:(gdouble)height andUnit:(GtkUnit)unit;

/**
 * - (void*)setPaperSize:(GtkPaperSize*)paperSize;
 *
 * @param paperSize
 */
- (void)setPaperSize:(GtkPaperSize*)paperSize;

/**
 * - (void*)setPaperWidthWithWidth:(gdouble)width andUnit:(GtkUnit)unit;
 *
 * @param width
 * @param unit
 */
- (void)setPaperWidthWithWidth:(gdouble)width andUnit:(GtkUnit)unit;

/**
 * - (void*)setPrintPages:(GtkPrintPages)pages;
 *
 * @param pages
 */
- (void)setPrintPages:(GtkPrintPages)pages;

/**
 * - (void*)setPrinter:(OFString*)printer;
 *
 * @param printer
 */
- (void)setPrinter:(OFString*)printer;

/**
 * - (void*)setPrinterLpi:(gdouble)lpi;
 *
 * @param lpi
 */
- (void)setPrinterLpi:(gdouble)lpi;

/**
 * - (void*)setQuality:(GtkPrintQuality)quality;
 *
 * @param quality
 */
- (void)setQuality:(GtkPrintQuality)quality;

/**
 * - (void*)setResolution:(gint)resolution;
 *
 * @param resolution
 */
- (void)setResolution:(gint)resolution;

/**
 * - (void*)setResolutionXyWithResolutionX:(gint)resolutionX andResolutionY:(gint)resolutionY;
 *
 * @param resolutionX
 * @param resolutionY
 */
- (void)setResolutionXyWithResolutionX:(gint)resolutionX andResolutionY:(gint)resolutionY;

/**
 * - (void*)setReverse:(bool)reverse;
 *
 * @param reverse
 */
- (void)setReverse:(bool)reverse;

/**
 * - (void*)setScale:(gdouble)scale;
 *
 * @param scale
 */
- (void)setScale:(gdouble)scale;

/**
 * - (void*)setUseColor:(bool)useColor;
 *
 * @param useColor
 */
- (void)setUseColor:(bool)useColor;

/**
 * - (bool*)toFile:(OFString*)fileName;
 *
 * @param fileName
 * @returns bool
 */
- (bool)toFile:(OFString*)fileName;

/**
 * - (GVariant**)toGvariant;
 *
 * @returns GVariant*
 */
- (GVariant*)toGvariant;

/**
 * - (void*)toKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;
 *
 * @param keyFile
 * @param groupName
 */
- (void)toKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;

/**
 * - (void*)unset:(OFString*)key;
 *
 * @param key
 */
- (void)unset:(OFString*)key;

@end