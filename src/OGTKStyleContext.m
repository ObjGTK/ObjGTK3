/*
 * OGTKStyleContext.m
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
#import "OGTKStyleContext.h"

@implementation OGTKStyleContext

+ (void)addProviderForScreenWithScreen:(GdkScreen*)screen andProvider:(GtkStyleProvider*)provider andPriority:(guint)priority
{
	gtk_style_context_add_provider_for_screen(screen, provider, priority);
}

+ (void)removeProviderForScreenWithScreen:(GdkScreen*)screen andProvider:(GtkStyleProvider*)provider
{
	gtk_style_context_remove_provider_for_screen(screen, provider);
}

+ (void)resetWidgets:(GdkScreen*)screen
{
	gtk_style_context_reset_widgets(screen);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_style_context_new()];

	return self;
}

- (GtkStyleContext*)STYLECONTEXT
{
	return GTK_STYLE_CONTEXT([self GOBJECT]);
}

- (void)addClass:(OFString*)className
{
	gtk_style_context_add_class(GTK_STYLE_CONTEXT([self GOBJECT]), [className UTF8String]);
}

- (void)addProviderWithProvider:(GtkStyleProvider*)provider andPriority:(guint)priority
{
	gtk_style_context_add_provider(GTK_STYLE_CONTEXT([self GOBJECT]), provider, priority);
}

- (void)addRegionWithRegionName:(OFString*)regionName andFlags:(GtkRegionFlags)flags
{
	gtk_style_context_add_region(GTK_STYLE_CONTEXT([self GOBJECT]), [regionName UTF8String], flags);
}

- (void)cancelAnimations:(gpointer)regionId
{
	gtk_style_context_cancel_animations(GTK_STYLE_CONTEXT([self GOBJECT]), regionId);
}

- (void)getBackgroundColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color
{
	gtk_style_context_get_background_color(GTK_STYLE_CONTEXT([self GOBJECT]), state, color);
}

- (void)getBorderWithState:(GtkStateFlags)state andBorder:(GtkBorder*)border
{
	gtk_style_context_get_border(GTK_STYLE_CONTEXT([self GOBJECT]), state, border);
}

- (void)getBorderColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color
{
	gtk_style_context_get_border_color(GTK_STYLE_CONTEXT([self GOBJECT]), state, color);
}

- (void)getColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color
{
	gtk_style_context_get_color(GTK_STYLE_CONTEXT([self GOBJECT]), state, color);
}

- (GtkTextDirection)getDirection
{
	return gtk_style_context_get_direction(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (const PangoFontDescription*)getFont:(GtkStateFlags)state
{
	return gtk_style_context_get_font(GTK_STYLE_CONTEXT([self GOBJECT]), state);
}

- (GdkFrameClock*)getFrameClock
{
	return gtk_style_context_get_frame_clock(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (GtkJunctionSides)getJunctionSides
{
	return gtk_style_context_get_junction_sides(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (void)getMarginWithState:(GtkStateFlags)state andMargin:(GtkBorder*)margin
{
	gtk_style_context_get_margin(GTK_STYLE_CONTEXT([self GOBJECT]), state, margin);
}

- (void)getPaddingWithState:(GtkStateFlags)state andPadding:(GtkBorder*)padding
{
	gtk_style_context_get_padding(GTK_STYLE_CONTEXT([self GOBJECT]), state, padding);
}

- (GtkStyleContext*)getParent
{
	return gtk_style_context_get_parent(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (const GtkWidgetPath*)getPath
{
	return gtk_style_context_get_path(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (void)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value
{
	gtk_style_context_get_property(GTK_STYLE_CONTEXT([self GOBJECT]), [property UTF8String], state, value);
}

- (gint)getScale
{
	return gtk_style_context_get_scale(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (GdkScreen*)getScreen
{
	return gtk_style_context_get_screen(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (GtkCssSection*)getSection:(OFString*)property
{
	return gtk_style_context_get_section(GTK_STYLE_CONTEXT([self GOBJECT]), [property UTF8String]);
}

- (GtkStateFlags)getState
{
	return gtk_style_context_get_state(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (void)getStylePropertyWithPropertyName:(OFString*)propertyName andValue:(GValue*)value
{
	gtk_style_context_get_style_property(GTK_STYLE_CONTEXT([self GOBJECT]), [propertyName UTF8String], value);
}

- (void)getStyleValist:(va_list)args
{
	gtk_style_context_get_style_valist(GTK_STYLE_CONTEXT([self GOBJECT]), args);
}

- (void)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args
{
	gtk_style_context_get_valist(GTK_STYLE_CONTEXT([self GOBJECT]), state, args);
}

- (bool)hasClass:(OFString*)className
{
	return gtk_style_context_has_class(GTK_STYLE_CONTEXT([self GOBJECT]), [className UTF8String]);
}

- (bool)hasRegionWithRegionName:(OFString*)regionName andFlagsReturn:(GtkRegionFlags*)flagsReturn
{
	return gtk_style_context_has_region(GTK_STYLE_CONTEXT([self GOBJECT]), [regionName UTF8String], flagsReturn);
}

- (void)invalidate
{
	gtk_style_context_invalidate(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (GList*)listClasses
{
	return gtk_style_context_list_classes(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (GList*)listRegions
{
	return gtk_style_context_list_regions(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (bool)lookupColorWithColorName:(OFString*)colorName andColor:(GdkRGBA*)color
{
	return gtk_style_context_lookup_color(GTK_STYLE_CONTEXT([self GOBJECT]), [colorName UTF8String], color);
}

- (GtkIconSet*)lookupIconSet:(OFString*)stockId
{
	return gtk_style_context_lookup_icon_set(GTK_STYLE_CONTEXT([self GOBJECT]), [stockId UTF8String]);
}

- (void)notifyStateChangeWithWindow:(GdkWindow*)window andRegionId:(gpointer)regionId andState:(GtkStateType)state andStateValue:(bool)stateValue
{
	gtk_style_context_notify_state_change(GTK_STYLE_CONTEXT([self GOBJECT]), window, regionId, state, stateValue);
}

- (void)popAnimatableRegion
{
	gtk_style_context_pop_animatable_region(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (void)pushAnimatableRegion:(gpointer)regionId
{
	gtk_style_context_push_animatable_region(GTK_STYLE_CONTEXT([self GOBJECT]), regionId);
}

- (void)removeClass:(OFString*)className
{
	gtk_style_context_remove_class(GTK_STYLE_CONTEXT([self GOBJECT]), [className UTF8String]);
}

- (void)removeProvider:(GtkStyleProvider*)provider
{
	gtk_style_context_remove_provider(GTK_STYLE_CONTEXT([self GOBJECT]), provider);
}

- (void)removeRegion:(OFString*)regionName
{
	gtk_style_context_remove_region(GTK_STYLE_CONTEXT([self GOBJECT]), [regionName UTF8String]);
}

- (void)restore
{
	gtk_style_context_restore(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (void)save
{
	gtk_style_context_save(GTK_STYLE_CONTEXT([self GOBJECT]));
}

- (void)scrollAnimationsWithWindow:(GdkWindow*)window andDx:(gint)dx andDy:(gint)dy
{
	gtk_style_context_scroll_animations(GTK_STYLE_CONTEXT([self GOBJECT]), window, dx, dy);
}

- (void)setBackground:(GdkWindow*)window
{
	gtk_style_context_set_background(GTK_STYLE_CONTEXT([self GOBJECT]), window);
}

- (void)setDirection:(GtkTextDirection)direction
{
	gtk_style_context_set_direction(GTK_STYLE_CONTEXT([self GOBJECT]), direction);
}

- (void)setFrameClock:(GdkFrameClock*)frameClock
{
	gtk_style_context_set_frame_clock(GTK_STYLE_CONTEXT([self GOBJECT]), frameClock);
}

- (void)setJunctionSides:(GtkJunctionSides)sides
{
	gtk_style_context_set_junction_sides(GTK_STYLE_CONTEXT([self GOBJECT]), sides);
}

- (void)setParent:(GtkStyleContext*)parent
{
	gtk_style_context_set_parent(GTK_STYLE_CONTEXT([self GOBJECT]), parent);
}

- (void)setPath:(GtkWidgetPath*)path
{
	gtk_style_context_set_path(GTK_STYLE_CONTEXT([self GOBJECT]), path);
}

- (void)setScale:(gint)scale
{
	gtk_style_context_set_scale(GTK_STYLE_CONTEXT([self GOBJECT]), scale);
}

- (void)setScreen:(GdkScreen*)screen
{
	gtk_style_context_set_screen(GTK_STYLE_CONTEXT([self GOBJECT]), screen);
}

- (void)setState:(GtkStateFlags)flags
{
	gtk_style_context_set_state(GTK_STYLE_CONTEXT([self GOBJECT]), flags);
}

- (bool)stateIsRunningWithState:(GtkStateType)state andProgress:(gdouble*)progress
{
	return gtk_style_context_state_is_running(GTK_STYLE_CONTEXT([self GOBJECT]), state, progress);
}

- (char*)toString:(GtkStyleContextPrintFlags)flags
{
	return gtk_style_context_to_string(GTK_STYLE_CONTEXT([self GOBJECT]), flags);
}


@end