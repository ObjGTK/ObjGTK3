/*
 * OGTKLabel.m
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
#import "OGTKLabel.h"

@implementation OGTKLabel

- (id)init:(OFString*)str
{
	self = [super initWithGObject:(GObject*)gtk_label_new([str UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)str
{
	self = [super initWithGObject:(GObject*)gtk_label_new_with_mnemonic([str UTF8String])];

	return self;
}

- (GtkLabel*)LABEL
{
	return GTK_LABEL([self GOBJECT]);
}

- (gdouble)getAngle
{
	return gtk_label_get_angle(GTK_LABEL([self GOBJECT]));
}

- (PangoAttrList*)getAttributes
{
	return gtk_label_get_attributes(GTK_LABEL([self GOBJECT]));
}

- (OFString*)getCurrentUri
{
	return [OFString stringWithUTF8String:gtk_label_get_current_uri(GTK_LABEL([self GOBJECT]))];
}

- (PangoEllipsizeMode)getEllipsize
{
	return gtk_label_get_ellipsize(GTK_LABEL([self GOBJECT]));
}

- (GtkJustification)getJustify
{
	return gtk_label_get_justify(GTK_LABEL([self GOBJECT]));
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_label_get_label(GTK_LABEL([self GOBJECT]))];
}

- (PangoLayout*)getLayout
{
	return gtk_label_get_layout(GTK_LABEL([self GOBJECT]));
}

- (void)getLayoutOffsetsWithX:(gint*)x andY:(gint*)y
{
	gtk_label_get_layout_offsets(GTK_LABEL([self GOBJECT]), x, y);
}

- (bool)getLineWrap
{
	return gtk_label_get_line_wrap(GTK_LABEL([self GOBJECT]));
}

- (PangoWrapMode)getLineWrapMode
{
	return gtk_label_get_line_wrap_mode(GTK_LABEL([self GOBJECT]));
}

- (gint)getLines
{
	return gtk_label_get_lines(GTK_LABEL([self GOBJECT]));
}

- (gint)getMaxWidthChars
{
	return gtk_label_get_max_width_chars(GTK_LABEL([self GOBJECT]));
}

- (guint)getMnemonicKeyval
{
	return gtk_label_get_mnemonic_keyval(GTK_LABEL([self GOBJECT]));
}

- (OGTKWidget*)getMnemonicWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_label_get_mnemonic_widget(GTK_LABEL([self GOBJECT]))];
}

- (bool)getSelectable
{
	return gtk_label_get_selectable(GTK_LABEL([self GOBJECT]));
}

- (bool)getSelectionBoundsWithStart:(gint*)start andEnd:(gint*)end
{
	return gtk_label_get_selection_bounds(GTK_LABEL([self GOBJECT]), start, end);
}

- (bool)getSingleLineMode
{
	return gtk_label_get_single_line_mode(GTK_LABEL([self GOBJECT]));
}

- (OFString*)getText
{
	return [OFString stringWithUTF8String:gtk_label_get_text(GTK_LABEL([self GOBJECT]))];
}

- (bool)getTrackVisitedLinks
{
	return gtk_label_get_track_visited_links(GTK_LABEL([self GOBJECT]));
}

- (bool)getUseMarkup
{
	return gtk_label_get_use_markup(GTK_LABEL([self GOBJECT]));
}

- (bool)getUseUnderline
{
	return gtk_label_get_use_underline(GTK_LABEL([self GOBJECT]));
}

- (gint)getWidthChars
{
	return gtk_label_get_width_chars(GTK_LABEL([self GOBJECT]));
}

- (gfloat)getXalign
{
	return gtk_label_get_xalign(GTK_LABEL([self GOBJECT]));
}

- (gfloat)getYalign
{
	return gtk_label_get_yalign(GTK_LABEL([self GOBJECT]));
}

- (void)selectRegionWithStartOffset:(gint)startOffset andEndOffset:(gint)endOffset
{
	gtk_label_select_region(GTK_LABEL([self GOBJECT]), startOffset, endOffset);
}

- (void)setAngle:(gdouble)angle
{
	gtk_label_set_angle(GTK_LABEL([self GOBJECT]), angle);
}

- (void)setAttributes:(PangoAttrList*)attrs
{
	gtk_label_set_attributes(GTK_LABEL([self GOBJECT]), attrs);
}

- (void)setEllipsize:(PangoEllipsizeMode)mode
{
	gtk_label_set_ellipsize(GTK_LABEL([self GOBJECT]), mode);
}

- (void)setJustify:(GtkJustification)jtype
{
	gtk_label_set_justify(GTK_LABEL([self GOBJECT]), jtype);
}

- (void)setLabel:(OFString*)str
{
	gtk_label_set_label(GTK_LABEL([self GOBJECT]), [str UTF8String]);
}

- (void)setLineWrap:(bool)wrap
{
	gtk_label_set_line_wrap(GTK_LABEL([self GOBJECT]), wrap);
}

- (void)setLineWrapMode:(PangoWrapMode)wrapMode
{
	gtk_label_set_line_wrap_mode(GTK_LABEL([self GOBJECT]), wrapMode);
}

- (void)setLines:(gint)lines
{
	gtk_label_set_lines(GTK_LABEL([self GOBJECT]), lines);
}

- (void)setMarkup:(OFString*)str
{
	gtk_label_set_markup(GTK_LABEL([self GOBJECT]), [str UTF8String]);
}

- (void)setMarkupWithMnemonic:(OFString*)str
{
	gtk_label_set_markup_with_mnemonic(GTK_LABEL([self GOBJECT]), [str UTF8String]);
}

- (void)setMaxWidthChars:(gint)nchars
{
	gtk_label_set_max_width_chars(GTK_LABEL([self GOBJECT]), nchars);
}

- (void)setMnemonicWidget:(OGTKWidget*)widget
{
	gtk_label_set_mnemonic_widget(GTK_LABEL([self GOBJECT]), [widget WIDGET]);
}

- (void)setPattern:(OFString*)pattern
{
	gtk_label_set_pattern(GTK_LABEL([self GOBJECT]), [pattern UTF8String]);
}

- (void)setSelectable:(bool)setting
{
	gtk_label_set_selectable(GTK_LABEL([self GOBJECT]), setting);
}

- (void)setSingleLineMode:(bool)singleLineMode
{
	gtk_label_set_single_line_mode(GTK_LABEL([self GOBJECT]), singleLineMode);
}

- (void)setText:(OFString*)str
{
	gtk_label_set_text(GTK_LABEL([self GOBJECT]), [str UTF8String]);
}

- (void)setTextWithMnemonic:(OFString*)str
{
	gtk_label_set_text_with_mnemonic(GTK_LABEL([self GOBJECT]), [str UTF8String]);
}

- (void)setTrackVisitedLinks:(bool)trackLinks
{
	gtk_label_set_track_visited_links(GTK_LABEL([self GOBJECT]), trackLinks);
}

- (void)setUseMarkup:(bool)setting
{
	gtk_label_set_use_markup(GTK_LABEL([self GOBJECT]), setting);
}

- (void)setUseUnderline:(bool)setting
{
	gtk_label_set_use_underline(GTK_LABEL([self GOBJECT]), setting);
}

- (void)setWidthChars:(gint)nchars
{
	gtk_label_set_width_chars(GTK_LABEL([self GOBJECT]), nchars);
}

- (void)setXalign:(gfloat)xalign
{
	gtk_label_set_xalign(GTK_LABEL([self GOBJECT]), xalign);
}

- (void)setYalign:(gfloat)yalign
{
	gtk_label_set_yalign(GTK_LABEL([self GOBJECT]), yalign);
}


@end