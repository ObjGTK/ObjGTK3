/*
 * OGTKEntryCompletion.h
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

@interface OGTKEntryCompletion : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithArea:(GtkCellArea*)area;

/**
 * Methods
 */

- (GtkEntryCompletion*)ENTRYCOMPLETION;

/**
 * - (void*)complete;
 *
 */
- (void)complete;

/**
 * - (OFString**)computePrefix:(const char*)key;
 *
 * @param key
 * @returns OFString*
 */
- (OFString*)computePrefix:(const char*)key;

/**
 * - (void*)deleteAction:(gint)index;
 *
 * @param index
 */
- (void)deleteAction:(gint)index;

/**
 * - (OFString**)getCompletionPrefix;
 *
 * @returns OFString*
 */
- (OFString*)getCompletionPrefix;

/**
 * - (OGTKWidget**)getEntry;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getEntry;

/**
 * - (bool*)getInlineCompletion;
 *
 * @returns bool
 */
- (bool)getInlineCompletion;

/**
 * - (bool*)getInlineSelection;
 *
 * @returns bool
 */
- (bool)getInlineSelection;

/**
 * - (gint*)getMinimumKeyLength;
 *
 * @returns gint
 */
- (gint)getMinimumKeyLength;

/**
 * - (GtkTreeModel**)getModel;
 *
 * @returns GtkTreeModel*
 */
- (GtkTreeModel*)getModel;

/**
 * - (bool*)getPopupCompletion;
 *
 * @returns bool
 */
- (bool)getPopupCompletion;

/**
 * - (bool*)getPopupSetWidth;
 *
 * @returns bool
 */
- (bool)getPopupSetWidth;

/**
 * - (bool*)getPopupSingleMatch;
 *
 * @returns bool
 */
- (bool)getPopupSingleMatch;

/**
 * - (gint*)getTextColumn;
 *
 * @returns gint
 */
- (gint)getTextColumn;

/**
 * - (void*)insertActionMarkupWithIndex:(gint)index andMarkup:(OFString*)markup;
 *
 * @param index
 * @param markup
 */
- (void)insertActionMarkupWithIndex:(gint)index andMarkup:(OFString*)markup;

/**
 * - (void*)insertActionTextWithIndex:(gint)index andText:(OFString*)text;
 *
 * @param index
 * @param text
 */
- (void)insertActionTextWithIndex:(gint)index andText:(OFString*)text;

/**
 * - (void*)insertPrefix;
 *
 */
- (void)insertPrefix;

/**
 * - (void*)setInlineCompletion:(bool)inlineCompletion;
 *
 * @param inlineCompletion
 */
- (void)setInlineCompletion:(bool)inlineCompletion;

/**
 * - (void*)setInlineSelection:(bool)inlineSelection;
 *
 * @param inlineSelection
 */
- (void)setInlineSelection:(bool)inlineSelection;

/**
 * - (void*)setMatchFuncWithFunc:(GtkEntryCompletionMatchFunc)func andFuncData:(gpointer)funcData andFuncNotify:(GDestroyNotify)funcNotify;
 *
 * @param func
 * @param funcData
 * @param funcNotify
 */
- (void)setMatchFuncWithFunc:(GtkEntryCompletionMatchFunc)func andFuncData:(gpointer)funcData andFuncNotify:(GDestroyNotify)funcNotify;

/**
 * - (void*)setMinimumKeyLength:(gint)length;
 *
 * @param length
 */
- (void)setMinimumKeyLength:(gint)length;

/**
 * - (void*)setModel:(GtkTreeModel*)model;
 *
 * @param model
 */
- (void)setModel:(GtkTreeModel*)model;

/**
 * - (void*)setPopupCompletion:(bool)popupCompletion;
 *
 * @param popupCompletion
 */
- (void)setPopupCompletion:(bool)popupCompletion;

/**
 * - (void*)setPopupSetWidth:(bool)popupSetWidth;
 *
 * @param popupSetWidth
 */
- (void)setPopupSetWidth:(bool)popupSetWidth;

/**
 * - (void*)setPopupSingleMatch:(bool)popupSingleMatch;
 *
 * @param popupSingleMatch
 */
- (void)setPopupSingleMatch:(bool)popupSingleMatch;

/**
 * - (void*)setTextColumn:(gint)column;
 *
 * @param column
 */
- (void)setTextColumn:(gint)column;

@end