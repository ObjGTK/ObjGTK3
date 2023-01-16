/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStyle.h"

#import <OGdk3/OGGdkWindow.h>
#import "OGTKWidget.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>

@implementation OGTKStyle

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_style_new()];

	return self;
}

- (GtkStyle*)STYLE
{
	return GTK_STYLE([self GOBJECT]);
}

- (void)applyDefaultBackgroundWithCr:(cairo_t*)cr window:(OGGdkWindow*)window stateType:(GtkStateType)stateType x:(gint)x y:(gint)y width:(gint)width height:(gint)height
{
	gtk_style_apply_default_background([self STYLE], cr, [window WINDOW], stateType, x, y, width, height);
}

- (OGTKStyle*)attach:(OGGdkWindow*)window
{
	return [[[OGTKStyle alloc] initWithGObject:(GObject*)gtk_style_attach([self STYLE], [window WINDOW])] autorelease];
}

- (OGTKStyle*)copy
{
	return [[[OGTKStyle alloc] initWithGObject:(GObject*)gtk_style_copy([self STYLE])] autorelease];
}

- (void)detach
{
	gtk_style_detach([self STYLE]);
}

- (void)stylePropertyWithWidgetType:(GType)widgetType propertyName:(OFString*)propertyName value:(GValue*)value
{
	gtk_style_get_style_property([self STYLE], widgetType, [propertyName UTF8String], value);
}

- (void)valistWithWidgetType:(GType)widgetType firstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs
{
	gtk_style_get_valist([self STYLE], widgetType, [firstPropertyName UTF8String], varArgs);
}

- (bool)hasContext
{
	return gtk_style_has_context([self STYLE]);
}

- (bool)lookupColorWithColorName:(OFString*)colorName color:(GdkColor*)color
{
	return gtk_style_lookup_color([self STYLE], [colorName UTF8String], color);
}

- (GtkIconSet*)lookupIconSet:(OFString*)stockId
{
	return gtk_style_lookup_icon_set([self STYLE], [stockId UTF8String]);
}

- (OGGdkPixbuf*)renderIconWithSource:(const GtkIconSource*)source direction:(GtkTextDirection)direction state:(GtkStateType)state size:(GtkIconSize)size widget:(OGTKWidget*)widget detail:(OFString*)detail
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_style_render_icon([self STYLE], source, direction, state, size, [widget WIDGET], [detail UTF8String])] autorelease];
}

- (void)setBackgroundWithWindow:(OGGdkWindow*)window stateType:(GtkStateType)stateType
{
	gtk_style_set_background([self STYLE], [window WINDOW], stateType);
}


@end