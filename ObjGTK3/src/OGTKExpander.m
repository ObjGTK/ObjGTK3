/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKExpander.h"

#import "OGTKWidget.h"

@implementation OGTKExpander

- (instancetype)init:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_expander_new([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_expander_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkExpander*)EXPANDER
{
	return GTK_EXPANDER([self GOBJECT]);
}

- (bool)expanded
{
	return gtk_expander_get_expanded([self EXPANDER]);
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_expander_get_label([self EXPANDER])];
}

- (bool)labelFill
{
	return gtk_expander_get_label_fill([self EXPANDER]);
}

- (OGTKWidget*)labelWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_expander_get_label_widget([self EXPANDER])] autorelease];
}

- (bool)resizeToplevel
{
	return gtk_expander_get_resize_toplevel([self EXPANDER]);
}

- (gint)spacing
{
	return gtk_expander_get_spacing([self EXPANDER]);
}

- (bool)useMarkup
{
	return gtk_expander_get_use_markup([self EXPANDER]);
}

- (bool)useUnderline
{
	return gtk_expander_get_use_underline([self EXPANDER]);
}

- (void)setExpanded:(bool)expanded
{
	gtk_expander_set_expanded([self EXPANDER], expanded);
}

- (void)setLabel:(OFString*)label
{
	gtk_expander_set_label([self EXPANDER], [label UTF8String]);
}

- (void)setLabelFill:(bool)labelFill
{
	gtk_expander_set_label_fill([self EXPANDER], labelFill);
}

- (void)setLabelWidget:(OGTKWidget*)labelWidget
{
	gtk_expander_set_label_widget([self EXPANDER], [labelWidget WIDGET]);
}

- (void)setResizeToplevel:(bool)resizeToplevel
{
	gtk_expander_set_resize_toplevel([self EXPANDER], resizeToplevel);
}

- (void)setSpacing:(gint)spacing
{
	gtk_expander_set_spacing([self EXPANDER], spacing);
}

- (void)setUseMarkup:(bool)useMarkup
{
	gtk_expander_set_use_markup([self EXPANDER], useMarkup);
}

- (void)setUseUnderline:(bool)useUnderline
{
	gtk_expander_set_use_underline([self EXPANDER], useUnderline);
}


@end