/*
 * OGTKLabel.h
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
#import "OGTKMisc.h"

@interface OGTKLabel : OGTKMisc
{

}


/**
 * Constructors
 */
- (id)init:(OFString*)str;
- (id)initWithMnemonic:(OFString*)str;

/**
 * Methods
 */

- (GtkLabel*)LABEL;

/**
 * - (gdouble*)getAngle;
 *
 * @returns gdouble
 */
- (gdouble)getAngle;

/**
 * - (PangoAttrList**)getAttributes;
 *
 * @returns PangoAttrList*
 */
- (PangoAttrList*)getAttributes;

/**
 * - (OFString**)getCurrentUri;
 *
 * @returns OFString*
 */
- (OFString*)getCurrentUri;

/**
 * - (PangoEllipsizeMode*)getEllipsize;
 *
 * @returns PangoEllipsizeMode
 */
- (PangoEllipsizeMode)getEllipsize;

/**
 * - (GtkJustification*)getJustify;
 *
 * @returns GtkJustification
 */
- (GtkJustification)getJustify;

/**
 * - (OFString**)getLabel;
 *
 * @returns OFString*
 */
- (OFString*)getLabel;

/**
 * - (PangoLayout**)getLayout;
 *
 * @returns PangoLayout*
 */
- (PangoLayout*)getLayout;

/**
 * - (void*)getLayoutOffsetsWithX:(gint*)x andY:(gint*)y;
 *
 * @param x
 * @param y
 */
- (void)getLayoutOffsetsWithX:(gint*)x andY:(gint*)y;

/**
 * - (bool*)getLineWrap;
 *
 * @returns bool
 */
- (bool)getLineWrap;

/**
 * - (PangoWrapMode*)getLineWrapMode;
 *
 * @returns PangoWrapMode
 */
- (PangoWrapMode)getLineWrapMode;

/**
 * - (gint*)getLines;
 *
 * @returns gint
 */
- (gint)getLines;

/**
 * - (gint*)getMaxWidthChars;
 *
 * @returns gint
 */
- (gint)getMaxWidthChars;

/**
 * - (guint*)getMnemonicKeyval;
 *
 * @returns guint
 */
- (guint)getMnemonicKeyval;

/**
 * - (OGTKWidget**)getMnemonicWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getMnemonicWidget;

/**
 * - (bool*)getSelectable;
 *
 * @returns bool
 */
- (bool)getSelectable;

/**
 * - (bool*)getSelectionBoundsWithStart:(gint*)start andEnd:(gint*)end;
 *
 * @param start
 * @param end
 * @returns bool
 */
- (bool)getSelectionBoundsWithStart:(gint*)start andEnd:(gint*)end;

/**
 * - (bool*)getSingleLineMode;
 *
 * @returns bool
 */
- (bool)getSingleLineMode;

/**
 * - (OFString**)getText;
 *
 * @returns OFString*
 */
- (OFString*)getText;

/**
 * - (bool*)getTrackVisitedLinks;
 *
 * @returns bool
 */
- (bool)getTrackVisitedLinks;

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
 * - (gint*)getWidthChars;
 *
 * @returns gint
 */
- (gint)getWidthChars;

/**
 * - (gfloat*)getXalign;
 *
 * @returns gfloat
 */
- (gfloat)getXalign;

/**
 * - (gfloat*)getYalign;
 *
 * @returns gfloat
 */
- (gfloat)getYalign;

/**
 * - (void*)selectRegionWithStartOffset:(gint)startOffset andEndOffset:(gint)endOffset;
 *
 * @param startOffset
 * @param endOffset
 */
- (void)selectRegionWithStartOffset:(gint)startOffset andEndOffset:(gint)endOffset;

/**
 * - (void*)setAngle:(gdouble)angle;
 *
 * @param angle
 */
- (void)setAngle:(gdouble)angle;

/**
 * - (void*)setAttributes:(PangoAttrList*)attrs;
 *
 * @param attrs
 */
- (void)setAttributes:(PangoAttrList*)attrs;

/**
 * - (void*)setEllipsize:(PangoEllipsizeMode)mode;
 *
 * @param mode
 */
- (void)setEllipsize:(PangoEllipsizeMode)mode;

/**
 * - (void*)setJustify:(GtkJustification)jtype;
 *
 * @param jtype
 */
- (void)setJustify:(GtkJustification)jtype;

/**
 * - (void*)setLabel:(OFString*)str;
 *
 * @param str
 */
- (void)setLabel:(OFString*)str;

/**
 * - (void*)setLineWrap:(bool)wrap;
 *
 * @param wrap
 */
- (void)setLineWrap:(bool)wrap;

/**
 * - (void*)setLineWrapMode:(PangoWrapMode)wrapMode;
 *
 * @param wrapMode
 */
- (void)setLineWrapMode:(PangoWrapMode)wrapMode;

/**
 * - (void*)setLines:(gint)lines;
 *
 * @param lines
 */
- (void)setLines:(gint)lines;

/**
 * - (void*)setMarkup:(OFString*)str;
 *
 * @param str
 */
- (void)setMarkup:(OFString*)str;

/**
 * - (void*)setMarkupWithMnemonic:(OFString*)str;
 *
 * @param str
 */
- (void)setMarkupWithMnemonic:(OFString*)str;

/**
 * - (void*)setMaxWidthChars:(gint)nchars;
 *
 * @param nchars
 */
- (void)setMaxWidthChars:(gint)nchars;

/**
 * - (void*)setMnemonicWidget:(OGTKWidget*)widget;
 *
 * @param widget
 */
- (void)setMnemonicWidget:(OGTKWidget*)widget;

/**
 * - (void*)setPattern:(OFString*)pattern;
 *
 * @param pattern
 */
- (void)setPattern:(OFString*)pattern;

/**
 * - (void*)setSelectable:(bool)setting;
 *
 * @param setting
 */
- (void)setSelectable:(bool)setting;

/**
 * - (void*)setSingleLineMode:(bool)singleLineMode;
 *
 * @param singleLineMode
 */
- (void)setSingleLineMode:(bool)singleLineMode;

/**
 * - (void*)setText:(OFString*)str;
 *
 * @param str
 */
- (void)setText:(OFString*)str;

/**
 * - (void*)setTextWithMnemonic:(OFString*)str;
 *
 * @param str
 */
- (void)setTextWithMnemonic:(OFString*)str;

/**
 * - (void*)setTrackVisitedLinks:(bool)trackLinks;
 *
 * @param trackLinks
 */
- (void)setTrackVisitedLinks:(bool)trackLinks;

/**
 * - (void*)setUseMarkup:(bool)setting;
 *
 * @param setting
 */
- (void)setUseMarkup:(bool)setting;

/**
 * - (void*)setUseUnderline:(bool)setting;
 *
 * @param setting
 */
- (void)setUseUnderline:(bool)setting;

/**
 * - (void*)setWidthChars:(gint)nchars;
 *
 * @param nchars
 */
- (void)setWidthChars:(gint)nchars;

/**
 * - (void*)setXalign:(gfloat)xalign;
 *
 * @param xalign
 */
- (void)setXalign:(gfloat)xalign;

/**
 * - (void*)setYalign:(gfloat)yalign;
 *
 * @param yalign
 */
- (void)setYalign:(gfloat)yalign;

@end