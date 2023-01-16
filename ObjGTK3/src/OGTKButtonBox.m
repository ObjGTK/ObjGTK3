/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButtonBox.h"

#import "OGTKWidget.h"

@implementation OGTKButtonBox

- (instancetype)init:(GtkOrientation)orientation
{
	self = [super initWithGObject:(GObject*)gtk_button_box_new(orientation)];

	return self;
}

- (GtkButtonBox*)BUTTONBOX
{
	return GTK_BUTTON_BOX([self GOBJECT]);
}

- (bool)childNonHomogeneous:(OGTKWidget*)child
{
	return gtk_button_box_get_child_non_homogeneous([self BUTTONBOX], [child WIDGET]);
}

- (bool)childSecondary:(OGTKWidget*)child
{
	return gtk_button_box_get_child_secondary([self BUTTONBOX], [child WIDGET]);
}

- (GtkButtonBoxStyle)layout
{
	return gtk_button_box_get_layout([self BUTTONBOX]);
}

- (void)setChildNonHomogeneousWithChild:(OGTKWidget*)child nonHomogeneous:(bool)nonHomogeneous
{
	gtk_button_box_set_child_non_homogeneous([self BUTTONBOX], [child WIDGET], nonHomogeneous);
}

- (void)setChildSecondaryWithChild:(OGTKWidget*)child isSecondary:(bool)isSecondary
{
	gtk_button_box_set_child_secondary([self BUTTONBOX], [child WIDGET], isSecondary);
}

- (void)setLayout:(GtkButtonBoxStyle)layoutStyle
{
	gtk_button_box_set_layout([self BUTTONBOX], layoutStyle);
}


@end