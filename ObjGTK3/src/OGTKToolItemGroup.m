/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolItemGroup.h"

#import "OGTKWidget.h"
#import "OGTKToolItem.h"

@implementation OGTKToolItemGroup

- (instancetype)init:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_tool_item_group_new([label UTF8String])];

	return self;
}

- (GtkToolItemGroup*)TOOLITEMGROUP
{
	return GTK_TOOL_ITEM_GROUP([self GOBJECT]);
}

- (bool)collapsed
{
	return gtk_tool_item_group_get_collapsed([self TOOLITEMGROUP]);
}

- (OGTKToolItem*)dropItemWithX:(gint)x y:(gint)y
{
	return [[[OGTKToolItem alloc] initWithGObject:(GObject*)gtk_tool_item_group_get_drop_item([self TOOLITEMGROUP], x, y)] autorelease];
}

- (PangoEllipsizeMode)ellipsize
{
	return gtk_tool_item_group_get_ellipsize([self TOOLITEMGROUP]);
}

- (GtkReliefStyle)headerRelief
{
	return gtk_tool_item_group_get_header_relief([self TOOLITEMGROUP]);
}

- (gint)itemPosition:(OGTKToolItem*)item
{
	return gtk_tool_item_group_get_item_position([self TOOLITEMGROUP], [item TOOLITEM]);
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_tool_item_group_get_label([self TOOLITEMGROUP])];
}

- (OGTKWidget*)labelWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_item_group_get_label_widget([self TOOLITEMGROUP])] autorelease];
}

- (guint)nitems
{
	return gtk_tool_item_group_get_n_items([self TOOLITEMGROUP]);
}

- (OGTKToolItem*)nthItem:(guint)index
{
	return [[[OGTKToolItem alloc] initWithGObject:(GObject*)gtk_tool_item_group_get_nth_item([self TOOLITEMGROUP], index)] autorelease];
}

- (void)insertWithItem:(OGTKToolItem*)item position:(gint)position
{
	gtk_tool_item_group_insert([self TOOLITEMGROUP], [item TOOLITEM], position);
}

- (void)setCollapsed:(bool)collapsed
{
	gtk_tool_item_group_set_collapsed([self TOOLITEMGROUP], collapsed);
}

- (void)setEllipsize:(PangoEllipsizeMode)ellipsize
{
	gtk_tool_item_group_set_ellipsize([self TOOLITEMGROUP], ellipsize);
}

- (void)setHeaderRelief:(GtkReliefStyle)style
{
	gtk_tool_item_group_set_header_relief([self TOOLITEMGROUP], style);
}

- (void)setItemPositionWithItem:(OGTKToolItem*)item position:(gint)position
{
	gtk_tool_item_group_set_item_position([self TOOLITEMGROUP], [item TOOLITEM], position);
}

- (void)setLabel:(OFString*)label
{
	gtk_tool_item_group_set_label([self TOOLITEMGROUP], [label UTF8String]);
}

- (void)setLabelWidget:(OGTKWidget*)labelWidget
{
	gtk_tool_item_group_set_label_widget([self TOOLITEMGROUP], [labelWidget WIDGET]);
}


@end