/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolbar.h"

#import "OGTKToolItem.h"
#import "OGTKWidget.h"

@implementation OGTKToolbar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_toolbar_new()];

	return self;
}

- (GtkToolbar*)TOOLBAR
{
	return GTK_TOOLBAR([self GOBJECT]);
}

- (gint)dropIndexWithX:(gint)x y:(gint)y
{
	return gtk_toolbar_get_drop_index([self TOOLBAR], x, y);
}

- (GtkIconSize)iconSize
{
	return gtk_toolbar_get_icon_size([self TOOLBAR]);
}

- (gint)itemIndex:(OGTKToolItem*)item
{
	return gtk_toolbar_get_item_index([self TOOLBAR], [item TOOLITEM]);
}

- (gint)nitems
{
	return gtk_toolbar_get_n_items([self TOOLBAR]);
}

- (OGTKToolItem*)nthItem:(gint)n
{
	return [[[OGTKToolItem alloc] initWithGObject:(GObject*)gtk_toolbar_get_nth_item([self TOOLBAR], n)] autorelease];
}

- (GtkReliefStyle)reliefStyle
{
	return gtk_toolbar_get_relief_style([self TOOLBAR]);
}

- (bool)showArrow
{
	return gtk_toolbar_get_show_arrow([self TOOLBAR]);
}

- (GtkToolbarStyle)style
{
	return gtk_toolbar_get_style([self TOOLBAR]);
}

- (void)insertWithItem:(OGTKToolItem*)item pos:(gint)pos
{
	gtk_toolbar_insert([self TOOLBAR], [item TOOLITEM], pos);
}

- (void)setDropHighlightItemWithToolItem:(OGTKToolItem*)toolItem index:(gint)index
{
	gtk_toolbar_set_drop_highlight_item([self TOOLBAR], [toolItem TOOLITEM], index);
}

- (void)setIconSize:(GtkIconSize)iconSize
{
	gtk_toolbar_set_icon_size([self TOOLBAR], iconSize);
}

- (void)setShowArrow:(bool)showArrow
{
	gtk_toolbar_set_show_arrow([self TOOLBAR], showArrow);
}

- (void)setStyle:(GtkToolbarStyle)style
{
	gtk_toolbar_set_style([self TOOLBAR], style);
}

- (void)unsetIconSize
{
	gtk_toolbar_unset_icon_size([self TOOLBAR]);
}

- (void)unsetStyle
{
	gtk_toolbar_unset_style([self TOOLBAR]);
}


@end