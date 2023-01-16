/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

#import "OGTKAdjustment.h"

@implementation OGTKContainer

- (GtkContainer*)CONTAINER
{
	return GTK_CONTAINER([self GOBJECT]);
}

- (void)add:(OGTKWidget*)widget
{
	gtk_container_add([self CONTAINER], [widget WIDGET]);
}

- (void)checkResize
{
	gtk_container_check_resize([self CONTAINER]);
}

- (void)childGetPropertyWithChild:(OGTKWidget*)child propertyName:(OFString*)propertyName value:(GValue*)value
{
	gtk_container_child_get_property([self CONTAINER], [child WIDGET], [propertyName UTF8String], value);
}

- (void)childGetValistWithChild:(OGTKWidget*)child firstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs
{
	gtk_container_child_get_valist([self CONTAINER], [child WIDGET], [firstPropertyName UTF8String], varArgs);
}

- (void)childNotifyWithChild:(OGTKWidget*)child childProperty:(OFString*)childProperty
{
	gtk_container_child_notify([self CONTAINER], [child WIDGET], [childProperty UTF8String]);
}

- (void)childNotifyByPspecWithChild:(OGTKWidget*)child pspec:(GParamSpec*)pspec
{
	gtk_container_child_notify_by_pspec([self CONTAINER], [child WIDGET], pspec);
}

- (void)childSetPropertyWithChild:(OGTKWidget*)child propertyName:(OFString*)propertyName value:(const GValue*)value
{
	gtk_container_child_set_property([self CONTAINER], [child WIDGET], [propertyName UTF8String], value);
}

- (void)childSetValistWithChild:(OGTKWidget*)child firstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs
{
	gtk_container_child_set_valist([self CONTAINER], [child WIDGET], [firstPropertyName UTF8String], varArgs);
}

- (GType)childType
{
	return gtk_container_child_type([self CONTAINER]);
}

- (void)forallWithCallback:(GtkCallback)callback callbackData:(gpointer)callbackData
{
	gtk_container_forall([self CONTAINER], callback, callbackData);
}

- (void)foreachWithCallback:(GtkCallback)callback callbackData:(gpointer)callbackData
{
	gtk_container_foreach([self CONTAINER], callback, callbackData);
}

- (guint)borderWidth
{
	return gtk_container_get_border_width([self CONTAINER]);
}

- (GList*)children
{
	return gtk_container_get_children([self CONTAINER]);
}

- (bool)focusChain:(GList**)focusableWidgets
{
	return gtk_container_get_focus_chain([self CONTAINER], focusableWidgets);
}

- (OGTKWidget*)focusChild
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_container_get_focus_child([self CONTAINER])] autorelease];
}

- (OGTKAdjustment*)focusHadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_container_get_focus_hadjustment([self CONTAINER])] autorelease];
}

- (OGTKAdjustment*)focusVadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_container_get_focus_vadjustment([self CONTAINER])] autorelease];
}

- (GtkWidgetPath*)pathForChild:(OGTKWidget*)child
{
	return gtk_container_get_path_for_child([self CONTAINER], [child WIDGET]);
}

- (GtkResizeMode)resizeMode
{
	return gtk_container_get_resize_mode([self CONTAINER]);
}

- (void)propagateDrawWithChild:(OGTKWidget*)child cr:(cairo_t*)cr
{
	gtk_container_propagate_draw([self CONTAINER], [child WIDGET], cr);
}

- (void)remove:(OGTKWidget*)widget
{
	gtk_container_remove([self CONTAINER], [widget WIDGET]);
}

- (void)resizeChildren
{
	gtk_container_resize_children([self CONTAINER]);
}

- (void)setBorderWidth:(guint)borderWidth
{
	gtk_container_set_border_width([self CONTAINER], borderWidth);
}

- (void)setFocusChain:(GList*)focusableWidgets
{
	gtk_container_set_focus_chain([self CONTAINER], focusableWidgets);
}

- (void)setFocusChild:(OGTKWidget*)child
{
	gtk_container_set_focus_child([self CONTAINER], [child WIDGET]);
}

- (void)setFocusHadjustment:(OGTKAdjustment*)adjustment
{
	gtk_container_set_focus_hadjustment([self CONTAINER], [adjustment ADJUSTMENT]);
}

- (void)setFocusVadjustment:(OGTKAdjustment*)adjustment
{
	gtk_container_set_focus_vadjustment([self CONTAINER], [adjustment ADJUSTMENT]);
}

- (void)setReallocateRedraws:(bool)needsRedraws
{
	gtk_container_set_reallocate_redraws([self CONTAINER], needsRedraws);
}

- (void)setResizeMode:(GtkResizeMode)resizeMode
{
	gtk_container_set_resize_mode([self CONTAINER], resizeMode);
}

- (void)unsetFocusChain
{
	gtk_container_unset_focus_chain([self CONTAINER]);
}


@end