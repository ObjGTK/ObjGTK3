/*
 * OGTKIconInfo.m
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
#import "OGTKIconInfo.h"

@implementation OGTKIconInfo

- (id)initForPixbufWithIconTheme:(GtkIconTheme*)iconTheme andPixbuf:(GdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_icon_info_new_for_pixbuf(iconTheme, pixbuf)];

	return self;
}

- (GtkIconInfo*)ICONINFO
{
	return GTK_ICON_INFO([self GOBJECT]);
}

- (GtkIconInfo*)copy
{
	return gtk_icon_info_copy(GTK_ICON_INFO([self GOBJECT]));
}

- (void)free
{
	gtk_icon_info_free(GTK_ICON_INFO([self GOBJECT]));
}

- (bool)getAttachPointsWithPoints:(GdkPoint**)points andNpoints:(gint*)npoints
{
	return gtk_icon_info_get_attach_points(GTK_ICON_INFO([self GOBJECT]), points, npoints);
}

- (gint)getBaseScale
{
	return gtk_icon_info_get_base_scale(GTK_ICON_INFO([self GOBJECT]));
}

- (gint)getBaseSize
{
	return gtk_icon_info_get_base_size(GTK_ICON_INFO([self GOBJECT]));
}

- (GdkPixbuf*)getBuiltinPixbuf
{
	return gtk_icon_info_get_builtin_pixbuf(GTK_ICON_INFO([self GOBJECT]));
}

- (OFString*)getDisplayName
{
	return [OFString stringWithUTF8String:gtk_icon_info_get_display_name(GTK_ICON_INFO([self GOBJECT]))];
}

- (bool)getEmbeddedRect:(GdkRectangle*)rectangle
{
	return gtk_icon_info_get_embedded_rect(GTK_ICON_INFO([self GOBJECT]), rectangle);
}

- (OFString*)getFilename
{
	return [OFString stringWithUTF8String:gtk_icon_info_get_filename(GTK_ICON_INFO([self GOBJECT]))];
}

- (bool)isSymbolic
{
	return gtk_icon_info_is_symbolic(GTK_ICON_INFO([self GOBJECT]));
}

- (GdkPixbuf*)loadIcon
{
	return gtk_icon_info_load_icon(GTK_ICON_INFO([self GOBJECT]));
}

- (void)loadIconAsyncWithCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData
{
	gtk_icon_info_load_icon_async(GTK_ICON_INFO([self GOBJECT]), cancellable, callback, userData);
}

- (GdkPixbuf*)loadIconFinish:(GAsyncResult*)res
{
	return gtk_icon_info_load_icon_finish(GTK_ICON_INFO([self GOBJECT]), res);
}

- (cairo_surface_t*)loadSurface:(GdkWindow*)forWindow
{
	return gtk_icon_info_load_surface(GTK_ICON_INFO([self GOBJECT]), forWindow);
}

- (GdkPixbuf*)loadSymbolicWithFg:(const GdkRGBA*)fg andSuccessColor:(const GdkRGBA*)successColor andWarningColor:(const GdkRGBA*)warningColor andErrorColor:(const GdkRGBA*)errorColor andWasSymbolic:(gboolean*)wasSymbolic
{
	return gtk_icon_info_load_symbolic(GTK_ICON_INFO([self GOBJECT]), fg, successColor, warningColor, errorColor, wasSymbolic);
}

- (void)loadSymbolicAsyncWithFg:(const GdkRGBA*)fg andSuccessColor:(const GdkRGBA*)successColor andWarningColor:(const GdkRGBA*)warningColor andErrorColor:(const GdkRGBA*)errorColor andCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData
{
	gtk_icon_info_load_symbolic_async(GTK_ICON_INFO([self GOBJECT]), fg, successColor, warningColor, errorColor, cancellable, callback, userData);
}

- (GdkPixbuf*)loadSymbolicFinishWithRes:(GAsyncResult*)res andWasSymbolic:(gboolean*)wasSymbolic
{
	return gtk_icon_info_load_symbolic_finish(GTK_ICON_INFO([self GOBJECT]), res, wasSymbolic);
}

- (GdkPixbuf*)loadSymbolicForContextWithContext:(GtkStyleContext*)context andWasSymbolic:(gboolean*)wasSymbolic
{
	return gtk_icon_info_load_symbolic_for_context(GTK_ICON_INFO([self GOBJECT]), context, wasSymbolic);
}

- (void)loadSymbolicForContextAsyncWithContext:(GtkStyleContext*)context andCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData
{
	gtk_icon_info_load_symbolic_for_context_async(GTK_ICON_INFO([self GOBJECT]), context, cancellable, callback, userData);
}

- (GdkPixbuf*)loadSymbolicForContextFinishWithRes:(GAsyncResult*)res andWasSymbolic:(gboolean*)wasSymbolic
{
	return gtk_icon_info_load_symbolic_for_context_finish(GTK_ICON_INFO([self GOBJECT]), res, wasSymbolic);
}

- (GdkPixbuf*)loadSymbolicForStyleWithStyle:(GtkStyle*)style andState:(GtkStateType)state andWasSymbolic:(gboolean*)wasSymbolic
{
	return gtk_icon_info_load_symbolic_for_style(GTK_ICON_INFO([self GOBJECT]), style, state, wasSymbolic);
}

- (void)setRawCoordinates:(bool)rawCoordinates
{
	gtk_icon_info_set_raw_coordinates(GTK_ICON_INFO([self GOBJECT]), rawCoordinates);
}


@end