/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScrolledWindow.h"

#import "OGTKWidget.h"
#import "OGTKAdjustment.h"

@implementation OGTKScrolledWindow

- (instancetype)initWithHadjustment:(OGTKAdjustment*)hadjustment vadjustment:(OGTKAdjustment*)vadjustment
{
	self = [super initWithGObject:(GObject*)gtk_scrolled_window_new([hadjustment ADJUSTMENT], [vadjustment ADJUSTMENT])];

	return self;
}

- (GtkScrolledWindow*)SCROLLEDWINDOW
{
	return GTK_SCROLLED_WINDOW([self GOBJECT]);
}

- (void)addWithViewport:(OGTKWidget*)child
{
	gtk_scrolled_window_add_with_viewport([self SCROLLEDWINDOW], [child WIDGET]);
}

- (bool)captureButtonPress
{
	return gtk_scrolled_window_get_capture_button_press([self SCROLLEDWINDOW]);
}

- (OGTKAdjustment*)hadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_scrolled_window_get_hadjustment([self SCROLLEDWINDOW])] autorelease];
}

- (OGTKWidget*)hscrollbar
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scrolled_window_get_hscrollbar([self SCROLLEDWINDOW])] autorelease];
}

- (bool)kineticScrolling
{
	return gtk_scrolled_window_get_kinetic_scrolling([self SCROLLEDWINDOW]);
}

- (gint)maxContentHeight
{
	return gtk_scrolled_window_get_max_content_height([self SCROLLEDWINDOW]);
}

- (gint)maxContentWidth
{
	return gtk_scrolled_window_get_max_content_width([self SCROLLEDWINDOW]);
}

- (gint)minContentHeight
{
	return gtk_scrolled_window_get_min_content_height([self SCROLLEDWINDOW]);
}

- (gint)minContentWidth
{
	return gtk_scrolled_window_get_min_content_width([self SCROLLEDWINDOW]);
}

- (bool)overlayScrolling
{
	return gtk_scrolled_window_get_overlay_scrolling([self SCROLLEDWINDOW]);
}

- (GtkCornerType)placement
{
	return gtk_scrolled_window_get_placement([self SCROLLEDWINDOW]);
}

- (void)policyWithHscrollbarPolicy:(GtkPolicyType*)hscrollbarPolicy vscrollbarPolicy:(GtkPolicyType*)vscrollbarPolicy
{
	gtk_scrolled_window_get_policy([self SCROLLEDWINDOW], hscrollbarPolicy, vscrollbarPolicy);
}

- (bool)propagateNaturalHeight
{
	return gtk_scrolled_window_get_propagate_natural_height([self SCROLLEDWINDOW]);
}

- (bool)propagateNaturalWidth
{
	return gtk_scrolled_window_get_propagate_natural_width([self SCROLLEDWINDOW]);
}

- (GtkShadowType)shadowType
{
	return gtk_scrolled_window_get_shadow_type([self SCROLLEDWINDOW]);
}

- (OGTKAdjustment*)vadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_scrolled_window_get_vadjustment([self SCROLLEDWINDOW])] autorelease];
}

- (OGTKWidget*)vscrollbar
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scrolled_window_get_vscrollbar([self SCROLLEDWINDOW])] autorelease];
}

- (void)setCaptureButtonPress:(bool)captureButtonPress
{
	gtk_scrolled_window_set_capture_button_press([self SCROLLEDWINDOW], captureButtonPress);
}

- (void)setHadjustment:(OGTKAdjustment*)hadjustment
{
	gtk_scrolled_window_set_hadjustment([self SCROLLEDWINDOW], [hadjustment ADJUSTMENT]);
}

- (void)setKineticScrolling:(bool)kineticScrolling
{
	gtk_scrolled_window_set_kinetic_scrolling([self SCROLLEDWINDOW], kineticScrolling);
}

- (void)setMaxContentHeight:(gint)height
{
	gtk_scrolled_window_set_max_content_height([self SCROLLEDWINDOW], height);
}

- (void)setMaxContentWidth:(gint)width
{
	gtk_scrolled_window_set_max_content_width([self SCROLLEDWINDOW], width);
}

- (void)setMinContentHeight:(gint)height
{
	gtk_scrolled_window_set_min_content_height([self SCROLLEDWINDOW], height);
}

- (void)setMinContentWidth:(gint)width
{
	gtk_scrolled_window_set_min_content_width([self SCROLLEDWINDOW], width);
}

- (void)setOverlayScrolling:(bool)overlayScrolling
{
	gtk_scrolled_window_set_overlay_scrolling([self SCROLLEDWINDOW], overlayScrolling);
}

- (void)setPlacement:(GtkCornerType)windowPlacement
{
	gtk_scrolled_window_set_placement([self SCROLLEDWINDOW], windowPlacement);
}

- (void)setPolicyWithHscrollbarPolicy:(GtkPolicyType)hscrollbarPolicy vscrollbarPolicy:(GtkPolicyType)vscrollbarPolicy
{
	gtk_scrolled_window_set_policy([self SCROLLEDWINDOW], hscrollbarPolicy, vscrollbarPolicy);
}

- (void)setPropagateNaturalHeight:(bool)propagate
{
	gtk_scrolled_window_set_propagate_natural_height([self SCROLLEDWINDOW], propagate);
}

- (void)setPropagateNaturalWidth:(bool)propagate
{
	gtk_scrolled_window_set_propagate_natural_width([self SCROLLEDWINDOW], propagate);
}

- (void)setShadowType:(GtkShadowType)type
{
	gtk_scrolled_window_set_shadow_type([self SCROLLEDWINDOW], type);
}

- (void)setVadjustment:(OGTKAdjustment*)vadjustment
{
	gtk_scrolled_window_set_vadjustment([self SCROLLEDWINDOW], [vadjustment ADJUSTMENT]);
}

- (void)unsetPlacement
{
	gtk_scrolled_window_unset_placement([self SCROLLEDWINDOW]);
}


@end