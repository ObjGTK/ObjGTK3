/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIconInfo.h"

#import "OGTKStyle.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKIconTheme.h"
#import "OGTKStyleContext.h"
#import <OGdk3/OGGdkWindow.h>

@implementation OGTKIconInfo

- (instancetype)initForPixbufWithIconTheme:(OGTKIconTheme*)iconTheme pixbuf:(OGGdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_icon_info_new_for_pixbuf([iconTheme ICONTHEME], [pixbuf PIXBUF])];

	return self;
}

- (GtkIconInfo*)ICONINFO
{
	return GTK_ICON_INFO([self GOBJECT]);
}

- (OGTKIconInfo*)copy
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_info_copy([self ICONINFO])] autorelease];
}

- (void)free
{
	gtk_icon_info_free([self ICONINFO]);
}

- (bool)attachPointsWithPoints:(GdkPoint**)points npoints:(gint*)npoints
{
	return gtk_icon_info_get_attach_points([self ICONINFO], points, npoints);
}

- (gint)baseScale
{
	return gtk_icon_info_get_base_scale([self ICONINFO]);
}

- (gint)baseSize
{
	return gtk_icon_info_get_base_size([self ICONINFO]);
}

- (OGGdkPixbuf*)builtinPixbuf
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_get_builtin_pixbuf([self ICONINFO])] autorelease];
}

- (OFString*)displayName
{
	return [OFString stringWithUTF8String:gtk_icon_info_get_display_name([self ICONINFO])];
}

- (bool)embeddedRect:(GdkRectangle*)rectangle
{
	return gtk_icon_info_get_embedded_rect([self ICONINFO], rectangle);
}

- (OFString*)filename
{
	return [OFString stringWithUTF8String:gtk_icon_info_get_filename([self ICONINFO])];
}

- (bool)isSymbolic
{
	return gtk_icon_info_is_symbolic([self ICONINFO]);
}

- (OGGdkPixbuf*)loadIcon:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_icon([self ICONINFO], err)] autorelease];
}

- (void)loadIconAsyncWithCancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gtk_icon_info_load_icon_async([self ICONINFO], cancellable, callback, userData);
}

- (OGGdkPixbuf*)loadIconFinishWithRes:(GAsyncResult*)res err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_icon_finish([self ICONINFO], res, err)] autorelease];
}

- (cairo_surface_t*)loadSurfaceWithForWindow:(OGGdkWindow*)forWindow err:(GError**)err
{
	return gtk_icon_info_load_surface([self ICONINFO], [forWindow WINDOW], err);
}

- (OGGdkPixbuf*)loadSymbolicWithFg:(const GdkRGBA*)fg successColor:(const GdkRGBA*)successColor warningColor:(const GdkRGBA*)warningColor errorColor:(const GdkRGBA*)errorColor wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_symbolic([self ICONINFO], fg, successColor, warningColor, errorColor, wasSymbolic, err)] autorelease];
}

- (void)loadSymbolicAsyncWithFg:(const GdkRGBA*)fg successColor:(const GdkRGBA*)successColor warningColor:(const GdkRGBA*)warningColor errorColor:(const GdkRGBA*)errorColor cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gtk_icon_info_load_symbolic_async([self ICONINFO], fg, successColor, warningColor, errorColor, cancellable, callback, userData);
}

- (OGGdkPixbuf*)loadSymbolicFinishWithRes:(GAsyncResult*)res wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_symbolic_finish([self ICONINFO], res, wasSymbolic, err)] autorelease];
}

- (OGGdkPixbuf*)loadSymbolicForContextWithContext:(OGTKStyleContext*)context wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_symbolic_for_context([self ICONINFO], [context STYLECONTEXT], wasSymbolic, err)] autorelease];
}

- (void)loadSymbolicForContextAsyncWithContext:(OGTKStyleContext*)context cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gtk_icon_info_load_symbolic_for_context_async([self ICONINFO], [context STYLECONTEXT], cancellable, callback, userData);
}

- (OGGdkPixbuf*)loadSymbolicForContextFinishWithRes:(GAsyncResult*)res wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_symbolic_for_context_finish([self ICONINFO], res, wasSymbolic, err)] autorelease];
}

- (OGGdkPixbuf*)loadSymbolicForStyleWithStyle:(OGTKStyle*)style state:(GtkStateType)state wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_info_load_symbolic_for_style([self ICONINFO], [style STYLE], state, wasSymbolic, err)] autorelease];
}

- (void)setRawCoordinates:(bool)rawCoordinates
{
	gtk_icon_info_set_raw_coordinates([self ICONINFO], rawCoordinates);
}


@end