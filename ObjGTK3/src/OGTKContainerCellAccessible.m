/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainerCellAccessible.h"

@implementation OGTKContainerCellAccessible

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_container_cell_accessible_new()];

	return self;
}

- (GtkContainerCellAccessible*)CONTAINERCELLACCESSIBLE
{
	return GTK_CONTAINER_CELL_ACCESSIBLE([self GOBJECT]);
}

- (void)addChild:(OGTKCellAccessible*)child
{
	gtk_container_cell_accessible_add_child([self CONTAINERCELLACCESSIBLE], [child CELLACCESSIBLE]);
}

- (GList*)children
{
	return gtk_container_cell_accessible_get_children([self CONTAINERCELLACCESSIBLE]);
}

- (void)removeChild:(OGTKCellAccessible*)child
{
	gtk_container_cell_accessible_remove_child([self CONTAINERCELLACCESSIBLE], [child CELLACCESSIBLE]);
}


@end