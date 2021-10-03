/*
 * OGTKIconTheme.m
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
#import "OGTKIconTheme.h"

@implementation OGTKIconTheme

+ (void)addBuiltinIconWithIconName:(OFString*)iconName andSize:(gint)size andPixbuf:(GdkPixbuf*)pixbuf
{
	gtk_icon_theme_add_builtin_icon([iconName UTF8String], size, pixbuf);
}

+ (GtkIconTheme*)getDefault
{
	return gtk_icon_theme_get_default();
}

+ (GtkIconTheme*)getForScreen:(GdkScreen*)screen
{
	return gtk_icon_theme_get_for_screen(screen);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_icon_theme_new()];

	return self;
}

- (GtkIconTheme*)ICONTHEME
{
	return GTK_ICON_THEME([self GOBJECT]);
}

- (void)addResourcePath:(OFString*)path
{
	gtk_icon_theme_add_resource_path(GTK_ICON_THEME([self GOBJECT]), [path UTF8String]);
}

- (void)appendSearchPath:(OFString*)path
{
	gtk_icon_theme_append_search_path(GTK_ICON_THEME([self GOBJECT]), [path UTF8String]);
}

- (GtkIconInfo*)chooseIconWithIconNames:(const gchar**)iconNames andSize:(gint)size andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_choose_icon(GTK_ICON_THEME([self GOBJECT]), iconNames, size, flags);
}

- (GtkIconInfo*)chooseIconForScaleWithIconNames:(const gchar**)iconNames andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_choose_icon_for_scale(GTK_ICON_THEME([self GOBJECT]), iconNames, size, scale, flags);
}

- (char*)getExampleIconName
{
	return gtk_icon_theme_get_example_icon_name(GTK_ICON_THEME([self GOBJECT]));
}

- (gint*)getIconSizes:(OFString*)iconName
{
	return gtk_icon_theme_get_icon_sizes(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String]);
}

- (void)getSearchPathWithPath:(gchar***)path andNelements:(gint*)nelements
{
	gtk_icon_theme_get_search_path(GTK_ICON_THEME([self GOBJECT]), path, nelements);
}

- (bool)hasIcon:(OFString*)iconName
{
	return gtk_icon_theme_has_icon(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String]);
}

- (GList*)listContexts
{
	return gtk_icon_theme_list_contexts(GTK_ICON_THEME([self GOBJECT]));
}

- (GList*)listIcons:(OFString*)context
{
	return gtk_icon_theme_list_icons(GTK_ICON_THEME([self GOBJECT]), [context UTF8String]);
}

- (GdkPixbuf*)loadIconWithIconName:(OFString*)iconName andSize:(gint)size andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_load_icon(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String], size, flags);
}

- (GdkPixbuf*)loadIconForScaleWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_load_icon_for_scale(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String], size, scale, flags);
}

- (cairo_surface_t*)loadSurfaceWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andForWindow:(GdkWindow*)forWindow andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_load_surface(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String], size, scale, forWindow, flags);
}

- (GtkIconInfo*)lookupByGiconWithIcon:(GIcon*)icon andSize:(gint)size andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_lookup_by_gicon(GTK_ICON_THEME([self GOBJECT]), icon, size, flags);
}

- (GtkIconInfo*)lookupByGiconForScaleWithIcon:(GIcon*)icon andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_lookup_by_gicon_for_scale(GTK_ICON_THEME([self GOBJECT]), icon, size, scale, flags);
}

- (GtkIconInfo*)lookupIconWithIconName:(OFString*)iconName andSize:(gint)size andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_lookup_icon(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String], size, flags);
}

- (GtkIconInfo*)lookupIconForScaleWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags
{
	return gtk_icon_theme_lookup_icon_for_scale(GTK_ICON_THEME([self GOBJECT]), [iconName UTF8String], size, scale, flags);
}

- (void)prependSearchPath:(OFString*)path
{
	gtk_icon_theme_prepend_search_path(GTK_ICON_THEME([self GOBJECT]), [path UTF8String]);
}

- (bool)rescanIfNeeded
{
	return gtk_icon_theme_rescan_if_needed(GTK_ICON_THEME([self GOBJECT]));
}

- (void)setCustomTheme:(OFString*)themeName
{
	gtk_icon_theme_set_custom_theme(GTK_ICON_THEME([self GOBJECT]), [themeName UTF8String]);
}

- (void)setScreen:(GdkScreen*)screen
{
	gtk_icon_theme_set_screen(GTK_ICON_THEME([self GOBJECT]), screen);
}

- (void)setSearchPathWithPath:(const gchar**)path andNelements:(gint)nelements
{
	gtk_icon_theme_set_search_path(GTK_ICON_THEME([self GOBJECT]), path, nelements);
}


@end