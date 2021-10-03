/*
 * OGTKExpander.h
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
#import "OGTKBin.h"

@interface OGTKExpander : OGTKBin
{

}


/**
 * Constructors
 */
- (id)init:(OFString*)label;
- (id)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkExpander*)EXPANDER;

/**
 * - (bool*)getExpanded;
 *
 * @returns bool
 */
- (bool)getExpanded;

/**
 * - (OFString**)getLabel;
 *
 * @returns OFString*
 */
- (OFString*)getLabel;

/**
 * - (bool*)getLabelFill;
 *
 * @returns bool
 */
- (bool)getLabelFill;

/**
 * - (OGTKWidget**)getLabelWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getLabelWidget;

/**
 * - (bool*)getResizeToplevel;
 *
 * @returns bool
 */
- (bool)getResizeToplevel;

/**
 * - (gint*)getSpacing;
 *
 * @returns gint
 */
- (gint)getSpacing;

/**
 * - (bool*)getUseMarkup;
 *
 * @returns bool
 */
- (bool)getUseMarkup;

/**
 * - (bool*)getUseUnderline;
 *
 * @returns bool
 */
- (bool)getUseUnderline;

/**
 * - (void*)setExpanded:(bool)expanded;
 *
 * @param expanded
 */
- (void)setExpanded:(bool)expanded;

/**
 * - (void*)setLabel:(OFString*)label;
 *
 * @param label
 */
- (void)setLabel:(OFString*)label;

/**
 * - (void*)setLabelFill:(bool)labelFill;
 *
 * @param labelFill
 */
- (void)setLabelFill:(bool)labelFill;

/**
 * - (void*)setLabelWidget:(OGTKWidget*)labelWidget;
 *
 * @param labelWidget
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

/**
 * - (void*)setResizeToplevel:(bool)resizeToplevel;
 *
 * @param resizeToplevel
 */
- (void)setResizeToplevel:(bool)resizeToplevel;

/**
 * - (void*)setSpacing:(gint)spacing;
 *
 * @param spacing
 */
- (void)setSpacing:(gint)spacing;

/**
 * - (void*)setUseMarkup:(bool)useMarkup;
 *
 * @param useMarkup
 */
- (void)setUseMarkup:(bool)useMarkup;

/**
 * - (void*)setUseUnderline:(bool)useUnderline;
 *
 * @param useUnderline
 */
- (void)setUseUnderline:(bool)useUnderline;

@end