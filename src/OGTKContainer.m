/*
 * OGTKContainer.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKContainer.h"

@implementation OGTKContainer

- (void)addWidget:(OGTKWidget*)widget withProperties:(OFDictionary*)properties
{
	OGTKTypeWrapper *wrapper;
	for(OFString *propName in properties) {
		wrapper = [properties objectForKey:propName];
		
		gtk_container_child_set_property([self CONTAINER], [widget WIDGET], [propName UTF8String], [wrapper asGValuePtr]);
	}
}

- (GtkContainer*)CONTAINER
{
	return GTK_CONTAINER([self GOBJECT]);
}

- (void)add:(OGTKWidget*)widget
{
	gtk_container_add(GTK_CONTAINER([self GOBJECT]), [widget WIDGET]);
}

- (void)checkResize
{
	gtk_container_check_resize(GTK_CONTAINER([self GOBJECT]));
}

- (void)childGetPropertyWithChild:(OGTKWidget*)child andPropertyName:(OFString*)propertyName andValue:(GValue*)value
{
	gtk_container_child_get_property(GTK_CONTAINER([self GOBJECT]), [child WIDGET], [propertyName UTF8String], value);
}

- (void)childGetValistWithChild:(OGTKWidget*)child andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs
{
	gtk_container_child_get_valist(GTK_CONTAINER([self GOBJECT]), [child WIDGET], [firstPropertyName UTF8String], varArgs);
}

- (void)childNotifyWithChild:(OGTKWidget*)child andChildProperty:(OFString*)childProperty
{
	gtk_container_child_notify(GTK_CONTAINER([self GOBJECT]), [child WIDGET], [childProperty UTF8String]);
}

- (void)childNotifyByPspecWithChild:(OGTKWidget*)child andPspec:(GParamSpec*)pspec
{
	gtk_container_child_notify_by_pspec(GTK_CONTAINER([self GOBJECT]), [child WIDGET], pspec);
}

- (void)childSetPropertyWithChild:(OGTKWidget*)child andPropertyName:(OFString*)propertyName andValue:(const GValue*)value
{
	gtk_container_child_set_property(GTK_CONTAINER([self GOBJECT]), [child WIDGET], [propertyName UTF8String], value);
}

- (void)childSetValistWithChild:(OGTKWidget*)child andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs
{
	gtk_container_child_set_valist(GTK_CONTAINER([self GOBJECT]), [child WIDGET], [firstPropertyName UTF8String], varArgs);
}

- (GType)childType
{
	return gtk_container_child_type(GTK_CONTAINER([self GOBJECT]));
}

- (void)forallWithCallback:(GtkCallback)callback andCallbackData:(gpointer)callbackData
{
	gtk_container_forall(GTK_CONTAINER([self GOBJECT]), callback, callbackData);
}

- (void)foreachWithCallback:(GtkCallback)callback andCallbackData:(gpointer)callbackData
{
	gtk_container_foreach(GTK_CONTAINER([self GOBJECT]), callback, callbackData);
}

- (guint)getBorderWidth
{
	return gtk_container_get_border_width(GTK_CONTAINER([self GOBJECT]));
}

- (GList*)getChildren
{
	return gtk_container_get_children(GTK_CONTAINER([self GOBJECT]));
}

- (bool)getFocusChain:(GList**)focusableWidgets
{
	return gtk_container_get_focus_chain(GTK_CONTAINER([self GOBJECT]), focusableWidgets);
}

- (OGTKWidget*)getFocusChild
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_container_get_focus_child(GTK_CONTAINER([self GOBJECT]))];
}

- (GtkAdjustment*)getFocusHadjustment
{
	return gtk_container_get_focus_hadjustment(GTK_CONTAINER([self GOBJECT]));
}

- (GtkAdjustment*)getFocusVadjustment
{
	return gtk_container_get_focus_vadjustment(GTK_CONTAINER([self GOBJECT]));
}

- (GtkWidgetPath*)getPathForChild:(OGTKWidget*)child
{
	return gtk_container_get_path_for_child(GTK_CONTAINER([self GOBJECT]), [child WIDGET]);
}

- (GtkResizeMode)getResizeMode
{
	return gtk_container_get_resize_mode(GTK_CONTAINER([self GOBJECT]));
}

- (void)propagateDrawWithChild:(OGTKWidget*)child andCr:(cairo_t*)cr
{
	gtk_container_propagate_draw(GTK_CONTAINER([self GOBJECT]), [child WIDGET], cr);
}

- (void)remove:(OGTKWidget*)widget
{
	gtk_container_remove(GTK_CONTAINER([self GOBJECT]), [widget WIDGET]);
}

- (void)resizeChildren
{
	gtk_container_resize_children(GTK_CONTAINER([self GOBJECT]));
}

- (void)setBorderWidth:(guint)borderWidth
{
	gtk_container_set_border_width(GTK_CONTAINER([self GOBJECT]), borderWidth);
}

- (void)setFocusChain:(GList*)focusableWidgets
{
	gtk_container_set_focus_chain(GTK_CONTAINER([self GOBJECT]), focusableWidgets);
}

- (void)setFocusChild:(OGTKWidget*)child
{
	gtk_container_set_focus_child(GTK_CONTAINER([self GOBJECT]), [child WIDGET]);
}

- (void)setFocusHadjustment:(GtkAdjustment*)adjustment
{
	gtk_container_set_focus_hadjustment(GTK_CONTAINER([self GOBJECT]), adjustment);
}

- (void)setFocusVadjustment:(GtkAdjustment*)adjustment
{
	gtk_container_set_focus_vadjustment(GTK_CONTAINER([self GOBJECT]), adjustment);
}

- (void)setReallocateRedraws:(bool)needsRedraws
{
	gtk_container_set_reallocate_redraws(GTK_CONTAINER([self GOBJECT]), needsRedraws);
}

- (void)setResizeMode:(GtkResizeMode)resizeMode
{
	gtk_container_set_resize_mode(GTK_CONTAINER([self GOBJECT]), resizeMode);
}

- (void)unsetFocusChain
{
	gtk_container_unset_focus_chain(GTK_CONTAINER([self GOBJECT]));
}


@end