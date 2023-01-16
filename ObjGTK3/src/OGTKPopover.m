/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPopover.h"

#import "OGTKWidget.h"

@implementation OGTKPopover

- (instancetype)init:(OGTKWidget*)relativeTo
{
	self = [super initWithGObject:(GObject*)gtk_popover_new([relativeTo WIDGET])];

	return self;
}

- (instancetype)initFromModelWithRelativeTo:(OGTKWidget*)relativeTo model:(GMenuModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_popover_new_from_model([relativeTo WIDGET], model)];

	return self;
}

- (GtkPopover*)POPOVER
{
	return GTK_POPOVER([self GOBJECT]);
}

- (void)bindModelWithModel:(GMenuModel*)model actionNamespace:(OFString*)actionNamespace
{
	gtk_popover_bind_model([self POPOVER], model, [actionNamespace UTF8String]);
}

- (GtkPopoverConstraint)constrainTo
{
	return gtk_popover_get_constrain_to([self POPOVER]);
}

- (OGTKWidget*)defaultWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_popover_get_default_widget([self POPOVER])] autorelease];
}

- (bool)modal
{
	return gtk_popover_get_modal([self POPOVER]);
}

- (bool)pointingTo:(GdkRectangle*)rect
{
	return gtk_popover_get_pointing_to([self POPOVER], rect);
}

- (GtkPositionType)position
{
	return gtk_popover_get_position([self POPOVER]);
}

- (OGTKWidget*)relativeTo
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_popover_get_relative_to([self POPOVER])] autorelease];
}

- (bool)transitionsEnabled
{
	return gtk_popover_get_transitions_enabled([self POPOVER]);
}

- (void)popdown
{
	gtk_popover_popdown([self POPOVER]);
}

- (void)popup
{
	gtk_popover_popup([self POPOVER]);
}

- (void)setConstrainTo:(GtkPopoverConstraint)constraint
{
	gtk_popover_set_constrain_to([self POPOVER], constraint);
}

- (void)setDefaultWidget:(OGTKWidget*)widget
{
	gtk_popover_set_default_widget([self POPOVER], [widget WIDGET]);
}

- (void)setModal:(bool)modal
{
	gtk_popover_set_modal([self POPOVER], modal);
}

- (void)setPointingTo:(const GdkRectangle*)rect
{
	gtk_popover_set_pointing_to([self POPOVER], rect);
}

- (void)setPosition:(GtkPositionType)position
{
	gtk_popover_set_position([self POPOVER], position);
}

- (void)setRelativeTo:(OGTKWidget*)relativeTo
{
	gtk_popover_set_relative_to([self POPOVER], [relativeTo WIDGET]);
}

- (void)setTransitionsEnabled:(bool)transitionsEnabled
{
	gtk_popover_set_transitions_enabled([self POPOVER], transitionsEnabled);
}


@end