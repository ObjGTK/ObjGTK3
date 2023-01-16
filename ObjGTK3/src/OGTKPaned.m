/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPaned.h"

#import "OGTKWidget.h"
#import <OGdk3/OGGdkWindow.h>

@implementation OGTKPaned

- (instancetype)init:(GtkOrientation)orientation
{
	self = [super initWithGObject:(GObject*)gtk_paned_new(orientation)];

	return self;
}

- (GtkPaned*)PANED
{
	return GTK_PANED([self GOBJECT]);
}

- (void)add1:(OGTKWidget*)child
{
	gtk_paned_add1([self PANED], [child WIDGET]);
}

- (void)add2:(OGTKWidget*)child
{
	gtk_paned_add2([self PANED], [child WIDGET]);
}

- (OGTKWidget*)child1
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_paned_get_child1([self PANED])] autorelease];
}

- (OGTKWidget*)child2
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_paned_get_child2([self PANED])] autorelease];
}

- (OGGdkWindow*)handleWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_paned_get_handle_window([self PANED])] autorelease];
}

- (gint)position
{
	return gtk_paned_get_position([self PANED]);
}

- (bool)wideHandle
{
	return gtk_paned_get_wide_handle([self PANED]);
}

- (void)pack1WithChild:(OGTKWidget*)child resize:(bool)resize shrink:(bool)shrink
{
	gtk_paned_pack1([self PANED], [child WIDGET], resize, shrink);
}

- (void)pack2WithChild:(OGTKWidget*)child resize:(bool)resize shrink:(bool)shrink
{
	gtk_paned_pack2([self PANED], [child WIDGET], resize, shrink);
}

- (void)setPosition:(gint)position
{
	gtk_paned_set_position([self PANED], position);
}

- (void)setWideHandle:(bool)wide
{
	gtk_paned_set_wide_handle([self PANED], wide);
}


@end