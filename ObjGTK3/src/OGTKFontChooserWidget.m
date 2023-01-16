/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFontChooserWidget.h"

#import "OGTKWidget.h"

@implementation OGTKFontChooserWidget

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_font_chooser_widget_new()];

	return self;
}

- (GtkFontChooserWidget*)FONTCHOOSERWIDGET
{
	return GTK_FONT_CHOOSER_WIDGET([self GOBJECT]);
}


@end