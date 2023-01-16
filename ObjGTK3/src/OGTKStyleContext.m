/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStyleContext.h"

#import <OGdk3/OGGdkScreen.h>
#import <OGdk3/OGGdkFrameClock.h>
#import <OGdk3/OGGdkWindow.h>

@implementation OGTKStyleContext

+ (void)addProviderForScreenWithScreen:(OGGdkScreen*)screen provider:(GtkStyleProvider*)provider priority:(guint)priority
{
	gtk_style_context_add_provider_for_screen([screen SCREEN], provider, priority);
}

+ (void)removeProviderForScreenWithScreen:(OGGdkScreen*)screen provider:(GtkStyleProvider*)provider
{
	gtk_style_context_remove_provider_for_screen([screen SCREEN], provider);
}

+ (void)resetWidgets:(OGGdkScreen*)screen
{
	gtk_style_context_reset_widgets([screen SCREEN]);
}

- (instancetype)init
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
	gtk_style_context_add_class([self STYLECONTEXT], [className UTF8String]);
}

- (void)addProviderWithProvider:(GtkStyleProvider*)provider priority:(guint)priority
{
	gtk_style_context_add_provider([self STYLECONTEXT], provider, priority);
}

- (void)addRegionWithRegionName:(OFString*)regionName flags:(GtkRegionFlags)flags
{
	gtk_style_context_add_region([self STYLECONTEXT], [regionName UTF8String], flags);
}

- (void)cancelAnimations:(gpointer)regionId
{
	gtk_style_context_cancel_animations([self STYLECONTEXT], regionId);
}

- (void)backgroundColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color
{
	gtk_style_context_get_background_color([self STYLECONTEXT], state, color);
}

- (void)borderWithState:(GtkStateFlags)state border:(GtkBorder*)border
{
	gtk_style_context_get_border([self STYLECONTEXT], state, border);
}

- (void)borderColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color
{
	gtk_style_context_get_border_color([self STYLECONTEXT], state, color);
}

- (void)colorWithState:(GtkStateFlags)state color:(GdkRGBA*)color
{
	gtk_style_context_get_color([self STYLECONTEXT], state, color);
}

- (GtkTextDirection)direction
{
	return gtk_style_context_get_direction([self STYLECONTEXT]);
}

- (const PangoFontDescription*)font:(GtkStateFlags)state
{
	return gtk_style_context_get_font([self STYLECONTEXT], state);
}

- (OGGdkFrameClock*)frameClock
{
	return [[[OGGdkFrameClock alloc] initWithGObject:(GObject*)gtk_style_context_get_frame_clock([self STYLECONTEXT])] autorelease];
}

- (GtkJunctionSides)junctionSides
{
	return gtk_style_context_get_junction_sides([self STYLECONTEXT]);
}

- (void)marginWithState:(GtkStateFlags)state margin:(GtkBorder*)margin
{
	gtk_style_context_get_margin([self STYLECONTEXT], state, margin);
}

- (void)paddingWithState:(GtkStateFlags)state padding:(GtkBorder*)padding
{
	gtk_style_context_get_padding([self STYLECONTEXT], state, padding);
}

- (OGTKStyleContext*)parent
{
	return [[[OGTKStyleContext alloc] initWithGObject:(GObject*)gtk_style_context_get_parent([self STYLECONTEXT])] autorelease];
}

- (const GtkWidgetPath*)path
{
	return gtk_style_context_get_path([self STYLECONTEXT]);
}

- (void)propertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(GValue*)value
{
	gtk_style_context_get_property([self STYLECONTEXT], [property UTF8String], state, value);
}

- (gint)scale
{
	return gtk_style_context_get_scale([self STYLECONTEXT]);
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_style_context_get_screen([self STYLECONTEXT])] autorelease];
}

- (GtkCssSection*)section:(OFString*)property
{
	return gtk_style_context_get_section([self STYLECONTEXT], [property UTF8String]);
}

- (GtkStateFlags)state
{
	return gtk_style_context_get_state([self STYLECONTEXT]);
}

- (void)stylePropertyWithPropertyName:(OFString*)propertyName value:(GValue*)value
{
	gtk_style_context_get_style_property([self STYLECONTEXT], [propertyName UTF8String], value);
}

- (void)styleValist:(va_list)args
{
	gtk_style_context_get_style_valist([self STYLECONTEXT], args);
}

- (void)valistWithState:(GtkStateFlags)state args:(va_list)args
{
	gtk_style_context_get_valist([self STYLECONTEXT], state, args);
}

- (bool)hasClass:(OFString*)className
{
	return gtk_style_context_has_class([self STYLECONTEXT], [className UTF8String]);
}

- (bool)hasRegionWithRegionName:(OFString*)regionName flagsReturn:(GtkRegionFlags*)flagsReturn
{
	return gtk_style_context_has_region([self STYLECONTEXT], [regionName UTF8String], flagsReturn);
}

- (void)invalidate
{
	gtk_style_context_invalidate([self STYLECONTEXT]);
}

- (GList*)listClasses
{
	return gtk_style_context_list_classes([self STYLECONTEXT]);
}

- (GList*)listRegions
{
	return gtk_style_context_list_regions([self STYLECONTEXT]);
}

- (bool)lookupColorWithColorName:(OFString*)colorName color:(GdkRGBA*)color
{
	return gtk_style_context_lookup_color([self STYLECONTEXT], [colorName UTF8String], color);
}

- (GtkIconSet*)lookupIconSet:(OFString*)stockId
{
	return gtk_style_context_lookup_icon_set([self STYLECONTEXT], [stockId UTF8String]);
}

- (void)notifyStateChangeWithWindow:(OGGdkWindow*)window regionId:(gpointer)regionId state:(GtkStateType)state stateValue:(bool)stateValue
{
	gtk_style_context_notify_state_change([self STYLECONTEXT], [window WINDOW], regionId, state, stateValue);
}

- (void)popAnimatableRegion
{
	gtk_style_context_pop_animatable_region([self STYLECONTEXT]);
}

- (void)pushAnimatableRegion:(gpointer)regionId
{
	gtk_style_context_push_animatable_region([self STYLECONTEXT], regionId);
}

- (void)removeClass:(OFString*)className
{
	gtk_style_context_remove_class([self STYLECONTEXT], [className UTF8String]);
}

- (void)removeProvider:(GtkStyleProvider*)provider
{
	gtk_style_context_remove_provider([self STYLECONTEXT], provider);
}

- (void)removeRegion:(OFString*)regionName
{
	gtk_style_context_remove_region([self STYLECONTEXT], [regionName UTF8String]);
}

- (void)restore
{
	gtk_style_context_restore([self STYLECONTEXT]);
}

- (void)save
{
	gtk_style_context_save([self STYLECONTEXT]);
}

- (void)scrollAnimationsWithWindow:(OGGdkWindow*)window dx:(gint)dx dy:(gint)dy
{
	gtk_style_context_scroll_animations([self STYLECONTEXT], [window WINDOW], dx, dy);
}

- (void)setBackground:(OGGdkWindow*)window
{
	gtk_style_context_set_background([self STYLECONTEXT], [window WINDOW]);
}

- (void)setDirection:(GtkTextDirection)direction
{
	gtk_style_context_set_direction([self STYLECONTEXT], direction);
}

- (void)setFrameClock:(OGGdkFrameClock*)frameClock
{
	gtk_style_context_set_frame_clock([self STYLECONTEXT], [frameClock FRAMECLOCK]);
}

- (void)setJunctionSides:(GtkJunctionSides)sides
{
	gtk_style_context_set_junction_sides([self STYLECONTEXT], sides);
}

- (void)setParent:(OGTKStyleContext*)parent
{
	gtk_style_context_set_parent([self STYLECONTEXT], [parent STYLECONTEXT]);
}

- (void)setPath:(GtkWidgetPath*)path
{
	gtk_style_context_set_path([self STYLECONTEXT], path);
}

- (void)setScale:(gint)scale
{
	gtk_style_context_set_scale([self STYLECONTEXT], scale);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_style_context_set_screen([self STYLECONTEXT], [screen SCREEN]);
}

- (void)setState:(GtkStateFlags)flags
{
	gtk_style_context_set_state([self STYLECONTEXT], flags);
}

- (bool)stateIsRunningWithState:(GtkStateType)state progress:(gdouble*)progress
{
	return gtk_style_context_state_is_running([self STYLECONTEXT], state, progress);
}

- (char*)toString:(GtkStyleContextPrintFlags)flags
{
	return gtk_style_context_to_string([self STYLECONTEXT], flags);
}


@end