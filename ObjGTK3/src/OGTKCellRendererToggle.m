/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererToggle.h"

@implementation OGTKCellRendererToggle

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_toggle_new()];

	return self;
}

- (GtkCellRendererToggle*)CELLRENDERERTOGGLE
{
	return GTK_CELL_RENDERER_TOGGLE([self GOBJECT]);
}

- (bool)activatable
{
	return gtk_cell_renderer_toggle_get_activatable([self CELLRENDERERTOGGLE]);
}

- (bool)active
{
	return gtk_cell_renderer_toggle_get_active([self CELLRENDERERTOGGLE]);
}

- (bool)radio
{
	return gtk_cell_renderer_toggle_get_radio([self CELLRENDERERTOGGLE]);
}

- (void)setActivatable:(bool)setting
{
	gtk_cell_renderer_toggle_set_activatable([self CELLRENDERERTOGGLE], setting);
}

- (void)setActive:(bool)setting
{
	gtk_cell_renderer_toggle_set_active([self CELLRENDERERTOGGLE], setting);
}

- (void)setRadio:(bool)radio
{
	gtk_cell_renderer_toggle_set_radio([self CELLRENDERERTOGGLE], radio);
}


@end