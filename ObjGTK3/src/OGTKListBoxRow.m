/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKListBoxRow.h"

#import "OGTKWidget.h"

@implementation OGTKListBoxRow

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_list_box_row_new()];

	return self;
}

- (GtkListBoxRow*)LISTBOXROW
{
	return GTK_LIST_BOX_ROW([self GOBJECT]);
}

- (void)changed
{
	gtk_list_box_row_changed([self LISTBOXROW]);
}

- (bool)activatable
{
	return gtk_list_box_row_get_activatable([self LISTBOXROW]);
}

- (OGTKWidget*)header
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_list_box_row_get_header([self LISTBOXROW])] autorelease];
}

- (gint)index
{
	return gtk_list_box_row_get_index([self LISTBOXROW]);
}

- (bool)selectable
{
	return gtk_list_box_row_get_selectable([self LISTBOXROW]);
}

- (bool)isSelected
{
	return gtk_list_box_row_is_selected([self LISTBOXROW]);
}

- (void)setActivatable:(bool)activatable
{
	gtk_list_box_row_set_activatable([self LISTBOXROW], activatable);
}

- (void)setHeader:(OGTKWidget*)header
{
	gtk_list_box_row_set_header([self LISTBOXROW], [header WIDGET]);
}

- (void)setSelectable:(bool)selectable
{
	gtk_list_box_row_set_selectable([self LISTBOXROW], selectable);
}


@end