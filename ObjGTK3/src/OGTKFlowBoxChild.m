/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFlowBoxChild.h"

#import "OGTKWidget.h"

@implementation OGTKFlowBoxChild

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_flow_box_child_new()];

	return self;
}

- (GtkFlowBoxChild*)FLOWBOXCHILD
{
	return GTK_FLOW_BOX_CHILD([self GOBJECT]);
}

- (void)changed
{
	gtk_flow_box_child_changed([self FLOWBOXCHILD]);
}

- (gint)index
{
	return gtk_flow_box_child_get_index([self FLOWBOXCHILD]);
}

- (bool)isSelected
{
	return gtk_flow_box_child_is_selected([self FLOWBOXCHILD]);
}


@end