/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIconTheme.h"

#import <OGdk3/OGGdkWindow.h>
#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import <OGdk3/OGGdkScreen.h>
#import "OGTKIconInfo.h"

@implementation OGTKIconTheme

+ (void)addBuiltinIconWithIconName:(OFString*)iconName size:(gint)size pixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_icon_theme_add_builtin_icon([iconName UTF8String], size, [pixbuf PIXBUF]);
}

+ (OGTKIconTheme*)default
{
	return [[[OGTKIconTheme alloc] initWithGObject:(GObject*)gtk_icon_theme_get_default()] autorelease];
}

+ (OGTKIconTheme*)forScreen:(OGGdkScreen*)screen
{
	return [[[OGTKIconTheme alloc] initWithGObject:(GObject*)gtk_icon_theme_get_for_screen([screen SCREEN])] autorelease];
}

- (instancetype)init
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
	gtk_icon_theme_add_resource_path([self ICONTHEME], [path UTF8String]);
}

- (void)appendSearchPath:(OFString*)path
{
	gtk_icon_theme_append_search_path([self ICONTHEME], [path UTF8String]);
}

- (OGTKIconInfo*)chooseIconWithIconNames:(const gchar**)iconNames size:(gint)size flags:(GtkIconLookupFlags)flags
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_theme_choose_icon([self ICONTHEME], iconNames, size, flags)] autorelease];
}

- (OGTKIconInfo*)chooseIconForScaleWithIconNames:(const gchar**)iconNames size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_theme_choose_icon_for_scale([self ICONTHEME], iconNames, size, scale, flags)] autorelease];
}

- (char*)exampleIconName
{
	return gtk_icon_theme_get_example_icon_name([self ICONTHEME]);
}

- (gint*)iconSizes:(OFString*)iconName
{
	return gtk_icon_theme_get_icon_sizes([self ICONTHEME], [iconName UTF8String]);
}

- (void)searchPathWithPath:(gchar***)path nelements:(gint*)nelements
{
	gtk_icon_theme_get_search_path([self ICONTHEME], path, nelements);
}

- (bool)hasIcon:(OFString*)iconName
{
	return gtk_icon_theme_has_icon([self ICONTHEME], [iconName UTF8String]);
}

- (GList*)listContexts
{
	return gtk_icon_theme_list_contexts([self ICONTHEME]);
}

- (GList*)listIcons:(OFString*)context
{
	return gtk_icon_theme_list_icons([self ICONTHEME], [context UTF8String]);
}

- (OGGdkPixbuf*)loadIconWithIconName:(OFString*)iconName size:(gint)size flags:(GtkIconLookupFlags)flags err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_theme_load_icon([self ICONTHEME], [iconName UTF8String], size, flags, err)] autorelease];
}

- (OGGdkPixbuf*)loadIconForScaleWithIconName:(OFString*)iconName size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags err:(GError**)err
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_icon_theme_load_icon_for_scale([self ICONTHEME], [iconName UTF8String], size, scale, flags, err)] autorelease];
}

- (cairo_surface_t*)loadSurfaceWithIconName:(OFString*)iconName size:(gint)size scale:(gint)scale forWindow:(OGGdkWindow*)forWindow flags:(GtkIconLookupFlags)flags err:(GError**)err
{
	return gtk_icon_theme_load_surface([self ICONTHEME], [iconName UTF8String], size, scale, [forWindow WINDOW], flags, err);
}

- (OGTKIconInfo*)lookupByGiconWithIcon:(GIcon*)icon size:(gint)size flags:(GtkIconLookupFlags)flags
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_theme_lookup_by_gicon([self ICONTHEME], icon, size, flags)] autorelease];
}

- (OGTKIconInfo*)lookupByGiconForScaleWithIcon:(GIcon*)icon size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_theme_lookup_by_gicon_for_scale([self ICONTHEME], icon, size, scale, flags)] autorelease];
}

- (OGTKIconInfo*)lookupIconWithIconName:(OFString*)iconName size:(gint)size flags:(GtkIconLookupFlags)flags
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_theme_lookup_icon([self ICONTHEME], [iconName UTF8String], size, flags)] autorelease];
}

- (OGTKIconInfo*)lookupIconForScaleWithIconName:(OFString*)iconName size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags
{
	return [[[OGTKIconInfo alloc] initWithGObject:(GObject*)gtk_icon_theme_lookup_icon_for_scale([self ICONTHEME], [iconName UTF8String], size, scale, flags)] autorelease];
}

- (void)prependSearchPath:(OFString*)path
{
	gtk_icon_theme_prepend_search_path([self ICONTHEME], [path UTF8String]);
}

- (bool)rescanIfNeeded
{
	return gtk_icon_theme_rescan_if_needed([self ICONTHEME]);
}

- (void)setCustomTheme:(OFString*)themeName
{
	gtk_icon_theme_set_custom_theme([self ICONTHEME], [themeName UTF8String]);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_icon_theme_set_screen([self ICONTHEME], [screen SCREEN]);
}

- (void)setSearchPathWithPath:(const gchar**)path nelements:(gint)nelements
{
	gtk_icon_theme_set_search_path([self ICONTHEME], path, nelements);
}


@end