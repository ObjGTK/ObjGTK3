/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBuilder.h"

#import "OGTKApplication.h"
#import "OGTKWidget.h"

@implementation OGTKBuilder

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_builder_new()];

	return self;
}

- (instancetype)initFromFile:(OFString*)filename
{
	self = [super initWithGObject:(GObject*)gtk_builder_new_from_file([filename UTF8String])];

	return self;
}

- (instancetype)initFromResource:(OFString*)resourcePath
{
	self = [super initWithGObject:(GObject*)gtk_builder_new_from_resource([resourcePath UTF8String])];

	return self;
}

- (instancetype)initFromStringWithString:(OFString*)string length:(gssize)length
{
	self = [super initWithGObject:(GObject*)gtk_builder_new_from_string([string UTF8String], length)];

	return self;
}

- (GtkBuilder*)BUILDER
{
	return GTK_BUILDER([self GOBJECT]);
}

- (void)addCallbackSymbolWithCallbackName:(OFString*)callbackName callbackSymbol:(GCallback)callbackSymbol
{
	gtk_builder_add_callback_symbol([self BUILDER], [callbackName UTF8String], callbackSymbol);
}

- (guint)addFromFileWithFilename:(OFString*)filename err:(GError**)err
{
	return gtk_builder_add_from_file([self BUILDER], [filename UTF8String], err);
}

- (guint)addFromResourceWithResourcePath:(OFString*)resourcePath err:(GError**)err
{
	return gtk_builder_add_from_resource([self BUILDER], [resourcePath UTF8String], err);
}

- (guint)addFromStringWithBuffer:(OFString*)buffer length:(gsize)length err:(GError**)err
{
	return gtk_builder_add_from_string([self BUILDER], [buffer UTF8String], length, err);
}

- (guint)addObjectsFromFileWithFilename:(OFString*)filename objectIds:(gchar**)objectIds err:(GError**)err
{
	return gtk_builder_add_objects_from_file([self BUILDER], [filename UTF8String], objectIds, err);
}

- (guint)addObjectsFromResourceWithResourcePath:(OFString*)resourcePath objectIds:(gchar**)objectIds err:(GError**)err
{
	return gtk_builder_add_objects_from_resource([self BUILDER], [resourcePath UTF8String], objectIds, err);
}

- (guint)addObjectsFromStringWithBuffer:(OFString*)buffer length:(gsize)length objectIds:(gchar**)objectIds err:(GError**)err
{
	return gtk_builder_add_objects_from_string([self BUILDER], [buffer UTF8String], length, objectIds, err);
}

- (void)connectSignals:(gpointer)userData
{
	gtk_builder_connect_signals([self BUILDER], userData);
}

- (void)connectSignalsFullWithFunc:(GtkBuilderConnectFunc)func userData:(gpointer)userData
{
	gtk_builder_connect_signals_full([self BUILDER], func, userData);
}

- (void)exposeObjectWithName:(OFString*)name object:(GObject*)object
{
	gtk_builder_expose_object([self BUILDER], [name UTF8String], object);
}

- (guint)extendWithTemplateWithWidget:(OGTKWidget*)widget templateType:(GType)templateType buffer:(OFString*)buffer length:(gsize)length err:(GError**)err
{
	return gtk_builder_extend_with_template([self BUILDER], [widget WIDGET], templateType, [buffer UTF8String], length, err);
}

- (OGTKApplication*)application
{
	return [[[OGTKApplication alloc] initWithGObject:(GObject*)gtk_builder_get_application([self BUILDER])] autorelease];
}

- (GObject*)object:(OFString*)name
{
	return gtk_builder_get_object([self BUILDER], [name UTF8String]);
}

- (GSList*)objects
{
	return gtk_builder_get_objects([self BUILDER]);
}

- (OFString*)translationDomain
{
	return [OFString stringWithUTF8String:gtk_builder_get_translation_domain([self BUILDER])];
}

- (GType)typeFromName:(OFString*)typeName
{
	return gtk_builder_get_type_from_name([self BUILDER], [typeName UTF8String]);
}

- (GCallback)lookupCallbackSymbol:(OFString*)callbackName
{
	return gtk_builder_lookup_callback_symbol([self BUILDER], [callbackName UTF8String]);
}

- (void)setApplication:(OGTKApplication*)application
{
	gtk_builder_set_application([self BUILDER], [application APPLICATION]);
}

- (void)setTranslationDomain:(OFString*)domain
{
	gtk_builder_set_translation_domain([self BUILDER], [domain UTF8String]);
}

- (bool)valueFromStringWithPspec:(GParamSpec*)pspec string:(OFString*)string value:(GValue*)value err:(GError**)err
{
	return gtk_builder_value_from_string([self BUILDER], pspec, [string UTF8String], value, err);
}

- (bool)valueFromStringTypeWithType:(GType)type string:(OFString*)string value:(GValue*)value err:(GError**)err
{
	return gtk_builder_value_from_string_type([self BUILDER], type, [string UTF8String], value, err);
}


@end