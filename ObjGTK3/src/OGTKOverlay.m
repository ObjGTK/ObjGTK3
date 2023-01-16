/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKOverlay.h"

#import "OGTKWidget.h"

@implementation OGTKOverlay

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_overlay_new()];

	return self;
}

- (GtkOverlay*)OVERLAY
{
	return GTK_OVERLAY([self GOBJECT]);
}

- (void)addOverlay:(OGTKWidget*)widget
{
	gtk_overlay_add_overlay([self OVERLAY], [widget WIDGET]);
}

- (bool)overlayPassThrough:(OGTKWidget*)widget
{
	return gtk_overlay_get_overlay_pass_through([self OVERLAY], [widget WIDGET]);
}

- (void)reorderOverlayWithChild:(OGTKWidget*)child index:(int)index
{
	gtk_overlay_reorder_overlay([self OVERLAY], [child WIDGET], index);
}

- (void)setOverlayPassThroughWithWidget:(OGTKWidget*)widget passThrough:(bool)passThrough
{
	gtk_overlay_set_overlay_pass_through([self OVERLAY], [widget WIDGET], passThrough);
}


@end