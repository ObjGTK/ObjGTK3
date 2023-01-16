/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSizeGroup.h"

#import "OGTKWidget.h"

@implementation OGTKSizeGroup

- (instancetype)init:(GtkSizeGroupMode)mode
{
	self = [super initWithGObject:(GObject*)gtk_size_group_new(mode)];

	return self;
}

- (GtkSizeGroup*)SIZEGROUP
{
	return GTK_SIZE_GROUP([self GOBJECT]);
}

- (void)addWidget:(OGTKWidget*)widget
{
	gtk_size_group_add_widget([self SIZEGROUP], [widget WIDGET]);
}

- (bool)ignoreHidden
{
	return gtk_size_group_get_ignore_hidden([self SIZEGROUP]);
}

- (GtkSizeGroupMode)mode
{
	return gtk_size_group_get_mode([self SIZEGROUP]);
}

- (GSList*)widgets
{
	return gtk_size_group_get_widgets([self SIZEGROUP]);
}

- (void)removeWidget:(OGTKWidget*)widget
{
	gtk_size_group_remove_widget([self SIZEGROUP], [widget WIDGET]);
}

- (void)setIgnoreHidden:(bool)ignoreHidden
{
	gtk_size_group_set_ignore_hidden([self SIZEGROUP], ignoreHidden);
}

- (void)setMode:(GtkSizeGroupMode)mode
{
	gtk_size_group_set_mode([self SIZEGROUP], mode);
}


@end