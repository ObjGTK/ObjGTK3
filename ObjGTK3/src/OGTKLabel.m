/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLabel.h"

#import <OGPango/OGPangoLayout.h>
#import "OGTKWidget.h"

@implementation OGTKLabel

- (instancetype)init:(OFString*)str
{
	self = [super initWithGObject:(GObject*)gtk_label_new([str UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)str
{
	self = [super initWithGObject:(GObject*)gtk_label_new_with_mnemonic([str UTF8String])];

	return self;
}

- (GtkLabel*)LABEL
{
	return GTK_LABEL([self GOBJECT]);
}

- (gdouble)angle
{
	return gtk_label_get_angle([self LABEL]);
}

- (PangoAttrList*)attributes
{
	return gtk_label_get_attributes([self LABEL]);
}

- (OFString*)currentUri
{
	return [OFString stringWithUTF8String:gtk_label_get_current_uri([self LABEL])];
}

- (PangoEllipsizeMode)ellipsize
{
	return gtk_label_get_ellipsize([self LABEL]);
}

- (GtkJustification)justify
{
	return gtk_label_get_justify([self LABEL]);
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_label_get_label([self LABEL])];
}

- (OGPangoLayout*)layout
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)gtk_label_get_layout([self LABEL])] autorelease];
}

- (void)layoutOffsetsWithX:(gint*)x y:(gint*)y
{
	gtk_label_get_layout_offsets([self LABEL], x, y);
}

- (bool)lineWrap
{
	return gtk_label_get_line_wrap([self LABEL]);
}

- (PangoWrapMode)lineWrapMode
{
	return gtk_label_get_line_wrap_mode([self LABEL]);
}

- (gint)lines
{
	return gtk_label_get_lines([self LABEL]);
}

- (gint)maxWidthChars
{
	return gtk_label_get_max_width_chars([self LABEL]);
}

- (guint)mnemonicKeyval
{
	return gtk_label_get_mnemonic_keyval([self LABEL]);
}

- (OGTKWidget*)mnemonicWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_label_get_mnemonic_widget([self LABEL])] autorelease];
}

- (bool)selectable
{
	return gtk_label_get_selectable([self LABEL]);
}

- (bool)selectionBoundsWithStart:(gint*)start end:(gint*)end
{
	return gtk_label_get_selection_bounds([self LABEL], start, end);
}

- (bool)singleLineMode
{
	return gtk_label_get_single_line_mode([self LABEL]);
}

- (OFString*)text
{
	return [OFString stringWithUTF8String:gtk_label_get_text([self LABEL])];
}

- (bool)trackVisitedLinks
{
	return gtk_label_get_track_visited_links([self LABEL]);
}

- (bool)useMarkup
{
	return gtk_label_get_use_markup([self LABEL]);
}

- (bool)useUnderline
{
	return gtk_label_get_use_underline([self LABEL]);
}

- (gint)widthChars
{
	return gtk_label_get_width_chars([self LABEL]);
}

- (gfloat)xalign
{
	return gtk_label_get_xalign([self LABEL]);
}

- (gfloat)yalign
{
	return gtk_label_get_yalign([self LABEL]);
}

- (void)selectRegionWithStartOffset:(gint)startOffset endOffset:(gint)endOffset
{
	gtk_label_select_region([self LABEL], startOffset, endOffset);
}

- (void)setAngle:(gdouble)angle
{
	gtk_label_set_angle([self LABEL], angle);
}

- (void)setAttributes:(PangoAttrList*)attrs
{
	gtk_label_set_attributes([self LABEL], attrs);
}

- (void)setEllipsize:(PangoEllipsizeMode)mode
{
	gtk_label_set_ellipsize([self LABEL], mode);
}

- (void)setJustify:(GtkJustification)jtype
{
	gtk_label_set_justify([self LABEL], jtype);
}

- (void)setLabel:(OFString*)str
{
	gtk_label_set_label([self LABEL], [str UTF8String]);
}

- (void)setLineWrap:(bool)wrap
{
	gtk_label_set_line_wrap([self LABEL], wrap);
}

- (void)setLineWrapMode:(PangoWrapMode)wrapMode
{
	gtk_label_set_line_wrap_mode([self LABEL], wrapMode);
}

- (void)setLines:(gint)lines
{
	gtk_label_set_lines([self LABEL], lines);
}

- (void)setMarkup:(OFString*)str
{
	gtk_label_set_markup([self LABEL], [str UTF8String]);
}

- (void)setMarkupWithMnemonic:(OFString*)str
{
	gtk_label_set_markup_with_mnemonic([self LABEL], [str UTF8String]);
}

- (void)setMaxWidthChars:(gint)nchars
{
	gtk_label_set_max_width_chars([self LABEL], nchars);
}

- (void)setMnemonicWidget:(OGTKWidget*)widget
{
	gtk_label_set_mnemonic_widget([self LABEL], [widget WIDGET]);
}

- (void)setPattern:(OFString*)pattern
{
	gtk_label_set_pattern([self LABEL], [pattern UTF8String]);
}

- (void)setSelectable:(bool)setting
{
	gtk_label_set_selectable([self LABEL], setting);
}

- (void)setSingleLineMode:(bool)singleLineMode
{
	gtk_label_set_single_line_mode([self LABEL], singleLineMode);
}

- (void)setText:(OFString*)str
{
	gtk_label_set_text([self LABEL], [str UTF8String]);
}

- (void)setTextWithMnemonic:(OFString*)str
{
	gtk_label_set_text_with_mnemonic([self LABEL], [str UTF8String]);
}

- (void)setTrackVisitedLinks:(bool)trackLinks
{
	gtk_label_set_track_visited_links([self LABEL], trackLinks);
}

- (void)setUseMarkup:(bool)setting
{
	gtk_label_set_use_markup([self LABEL], setting);
}

- (void)setUseUnderline:(bool)setting
{
	gtk_label_set_use_underline([self LABEL], setting);
}

- (void)setWidthChars:(gint)nchars
{
	gtk_label_set_width_chars([self LABEL], nchars);
}

- (void)setXalign:(gfloat)xalign
{
	gtk_label_set_xalign([self LABEL], xalign);
}

- (void)setYalign:(gfloat)yalign
{
	gtk_label_set_yalign([self LABEL], yalign);
}


@end