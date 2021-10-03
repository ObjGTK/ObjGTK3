/*
 * OGTKCellView.h
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
#import "OGTKWidget.h"

@interface OGTKCellView : OGTKWidget
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithContextWithArea:(GtkCellArea*)area andContext:(GtkCellAreaContext*)context;
- (id)initWithMarkup:(OFString*)markup;
- (id)initWithPixbuf:(GdkPixbuf*)pixbuf;
- (id)initWithText:(OFString*)text;

/**
 * Methods
 */

- (GtkCellView*)CELLVIEW;

/**
 * - (GtkTreePath**)getDisplayedRow;
 *
 * @returns GtkTreePath*
 */
- (GtkTreePath*)getDisplayedRow;

/**
 * - (bool*)getDrawSensitive;
 *
 * @returns bool
 */
- (bool)getDrawSensitive;

/**
 * - (bool*)getFitModel;
 *
 * @returns bool
 */
- (bool)getFitModel;

/**
 * - (GtkTreeModel**)getModel;
 *
 * @returns GtkTreeModel*
 */
- (GtkTreeModel*)getModel;

/**
 * - (bool*)getSizeOfRowWithPath:(GtkTreePath*)path andRequisition:(GtkRequisition*)requisition;
 *
 * @param path
 * @param requisition
 * @returns bool
 */
- (bool)getSizeOfRowWithPath:(GtkTreePath*)path andRequisition:(GtkRequisition*)requisition;

/**
 * - (void*)setBackgroundColor:(const GdkColor*)color;
 *
 * @param color
 */
- (void)setBackgroundColor:(const GdkColor*)color;

/**
 * - (void*)setBackgroundRgba:(const GdkRGBA*)rgba;
 *
 * @param rgba
 */
- (void)setBackgroundRgba:(const GdkRGBA*)rgba;

/**
 * - (void*)setDisplayedRow:(GtkTreePath*)path;
 *
 * @param path
 */
- (void)setDisplayedRow:(GtkTreePath*)path;

/**
 * - (void*)setDrawSensitive:(bool)drawSensitive;
 *
 * @param drawSensitive
 */
- (void)setDrawSensitive:(bool)drawSensitive;

/**
 * - (void*)setFitModel:(bool)fitModel;
 *
 * @param fitModel
 */
- (void)setFitModel:(bool)fitModel;

/**
 * - (void*)setModel:(GtkTreeModel*)model;
 *
 * @param model
 */
- (void)setModel:(GtkTreeModel*)model;

@end