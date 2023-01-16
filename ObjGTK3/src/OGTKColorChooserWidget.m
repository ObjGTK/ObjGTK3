/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKColorChooserWidget.h"

#import "OGTKWidget.h"

@implementation OGTKColorChooserWidget

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_color_chooser_widget_new()];

	return self;
}

- (GtkColorChooserWidget*)COLORCHOOSERWIDGET
{
	return GTK_COLOR_CHOOSER_WIDGET([self GOBJECT]);
}


@end