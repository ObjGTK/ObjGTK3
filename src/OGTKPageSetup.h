/*
 * OGTKPageSetup.h
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

@interface OGTKPageSetup : OGTKBase
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

- (GtkPageSetup*)PAGESETUP;

/**
 * - (GtkPageSetup**)copy;
 *
 * @returns GtkPageSetup*
 */
- (GtkPageSetup*)copy;

/**
 * - (gdouble*)getBottomMargin:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getBottomMargin:(GtkUnit)unit;

/**
 * - (gdouble*)getLeftMargin:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getLeftMargin:(GtkUnit)unit;

/**
 * - (GtkPageOrientation*)getOrientation;
 *
 * @returns GtkPageOrientation
 */
- (GtkPageOrientation)getOrientation;

/**
 * - (gdouble*)getPageHeight:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getPageHeight:(GtkUnit)unit;

/**
 * - (gdouble*)getPageWidth:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getPageWidth:(GtkUnit)unit;

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
 * - (gdouble*)getRightMargin:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getRightMargin:(GtkUnit)unit;

/**
 * - (gdouble*)getTopMargin:(GtkUnit)unit;
 *
 * @param unit
 * @returns gdouble
 */
- (gdouble)getTopMargin:(GtkUnit)unit;

/**
 * - (bool*)loadFile:(const char*)fileName;
 *
 * @param fileName
 * @returns bool
 */
- (bool)loadFile:(const char*)fileName;

/**
 * - (bool*)loadKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;
 *
 * @param keyFile
 * @param groupName
 * @returns bool
 */
- (bool)loadKeyFileWithKeyFile:(GKeyFile*)keyFile andGroupName:(OFString*)groupName;

/**
 * - (void*)setBottomMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;
 *
 * @param margin
 * @param unit
 */
- (void)setBottomMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;

/**
 * - (void*)setLeftMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;
 *
 * @param margin
 * @param unit
 */
- (void)setLeftMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;

/**
 * - (void*)setOrientation:(GtkPageOrientation)orientation;
 *
 * @param orientation
 */
- (void)setOrientation:(GtkPageOrientation)orientation;

/**
 * - (void*)setPaperSize:(GtkPaperSize*)size;
 *
 * @param size
 */
- (void)setPaperSize:(GtkPaperSize*)size;

/**
 * - (void*)setPaperSizeAndDefaultMargins:(GtkPaperSize*)size;
 *
 * @param size
 */
- (void)setPaperSizeAndDefaultMargins:(GtkPaperSize*)size;

/**
 * - (void*)setRightMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;
 *
 * @param margin
 * @param unit
 */
- (void)setRightMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;

/**
 * - (void*)setTopMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;
 *
 * @param margin
 * @param unit
 */
- (void)setTopMarginWithMargin:(gdouble)margin andUnit:(GtkUnit)unit;

/**
 * - (bool*)toFile:(const char*)fileName;
 *
 * @param fileName
 * @returns bool
 */
- (bool)toFile:(const char*)fileName;

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

@end