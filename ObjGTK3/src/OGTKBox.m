/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

#import "OGTKWidget.h"

@implementation OGTKBox

- (instancetype)initWithOrientation:(GtkOrientation)orientation spacing:(gint)spacing
{
	self = [super initWithGObject:(GObject*)gtk_box_new(orientation, spacing)];

	return self;
}

- (GtkBox*)BOX
{
	return GTK_BOX([self GOBJECT]);
}

- (GtkBaselinePosition)baselinePosition
{
	return gtk_box_get_baseline_position([self BOX]);
}

- (OGTKWidget*)centerWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_box_get_center_widget([self BOX])] autorelease];
}

- (bool)homogeneous
{
	return gtk_box_get_homogeneous([self BOX]);
}

- (gint)spacing
{
	return gtk_box_get_spacing([self BOX]);
}

- (void)packEndWithChild:(OGTKWidget*)child expand:(bool)expand fill:(bool)fill padding:(guint)padding
{
	gtk_box_pack_end([self BOX], [child WIDGET], expand, fill, padding);
}

- (void)packStartWithChild:(OGTKWidget*)child expand:(bool)expand fill:(bool)fill padding:(guint)padding
{
	gtk_box_pack_start([self BOX], [child WIDGET], expand, fill, padding);
}

- (void)queryChildPackingWithChild:(OGTKWidget*)child expand:(gboolean*)expand fill:(gboolean*)fill padding:(guint*)padding packType:(GtkPackType*)packType
{
	gtk_box_query_child_packing([self BOX], [child WIDGET], expand, fill, padding, packType);
}

- (void)reorderChildWithChild:(OGTKWidget*)child position:(gint)position
{
	gtk_box_reorder_child([self BOX], [child WIDGET], position);
}

- (void)setBaselinePosition:(GtkBaselinePosition)position
{
	gtk_box_set_baseline_position([self BOX], position);
}

- (void)setCenterWidget:(OGTKWidget*)widget
{
	gtk_box_set_center_widget([self BOX], [widget WIDGET]);
}

- (void)setChildPackingWithChild:(OGTKWidget*)child expand:(bool)expand fill:(bool)fill padding:(guint)padding packType:(GtkPackType)packType
{
	gtk_box_set_child_packing([self BOX], [child WIDGET], expand, fill, padding, packType);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_box_set_homogeneous([self BOX], homogeneous);
}

- (void)setSpacing:(gint)spacing
{
	gtk_box_set_spacing([self BOX], spacing);
}


@end