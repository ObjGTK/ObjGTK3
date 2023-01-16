/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkPixbuf.h"

@implementation OGGdkPixbuf

+ (gint)calculateRowstrideWithColorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height
{
	return gdk_pixbuf_calculate_rowstride(colorspace, hasAlpha, bitsPerSample, width, height);
}

+ (GdkPixbufFormat*)fileInfoWithFilename:(OFString*)filename width:(gint*)width height:(gint*)height
{
	return gdk_pixbuf_get_file_info([filename UTF8String], width, height);
}

+ (void)fileInfoAsyncWithFilename:(OFString*)filename cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gdk_pixbuf_get_file_info_async([filename UTF8String], cancellable, callback, userData);
}

+ (GdkPixbufFormat*)fileInfoFinishWithAsyncResult:(GAsyncResult*)asyncResult width:(gint*)width height:(gint*)height err:(GError**)err
{
	return gdk_pixbuf_get_file_info_finish(asyncResult, width, height, err);
}

+ (GSList*)formats
{
	return gdk_pixbuf_get_formats();
}

+ (bool)initModulesWithPath:(OFString*)path err:(GError**)err
{
	return gdk_pixbuf_init_modules([path UTF8String], err);
}

+ (void)newFromStreamAsyncWithStream:(GInputStream*)stream cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gdk_pixbuf_new_from_stream_async(stream, cancellable, callback, userData);
}

+ (void)newFromStreamAtScaleAsyncWithStream:(GInputStream*)stream width:(gint)width height:(gint)height preserveAspectRatio:(bool)preserveAspectRatio cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gdk_pixbuf_new_from_stream_at_scale_async(stream, width, height, preserveAspectRatio, cancellable, callback, userData);
}

+ (bool)saveToStreamFinishWithAsyncResult:(GAsyncResult*)asyncResult err:(GError**)err
{
	return gdk_pixbuf_save_to_stream_finish(asyncResult, err);
}

- (instancetype)initWithColorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new(colorspace, hasAlpha, bitsPerSample, width, height)];

	return self;
}

- (instancetype)initFromBytesWithData:(GBytes*)data colorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height rowstride:(int)rowstride
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_bytes(data, colorspace, hasAlpha, bitsPerSample, width, height, rowstride)];

	return self;
}

- (instancetype)initFromDataWithData:(const guchar*)data colorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height rowstride:(int)rowstride destroyFn:(GdkPixbufDestroyNotify)destroyFn destroyFnData:(gpointer)destroyFnData
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_data(data, colorspace, hasAlpha, bitsPerSample, width, height, rowstride, destroyFn, destroyFnData)];

	return self;
}

- (instancetype)initFromFileWithFilename:(OFString*)filename err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_file([filename UTF8String], err)];

	return self;
}

- (instancetype)initFromFileAtScaleWithFilename:(OFString*)filename width:(int)width height:(int)height preserveAspectRatio:(bool)preserveAspectRatio err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_file_at_scale([filename UTF8String], width, height, preserveAspectRatio, err)];

	return self;
}

- (instancetype)initFromFileAtSizeWithFilename:(OFString*)filename width:(int)width height:(int)height err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_file_at_size([filename UTF8String], width, height, err)];

	return self;
}

- (instancetype)initFromInlineWithDataLength:(gint)dataLength data:(const guint8*)data copyPixels:(bool)copyPixels err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_inline(dataLength, data, copyPixels, err)];

	return self;
}

- (instancetype)initFromResourceWithResourcePath:(OFString*)resourcePath err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_resource([resourcePath UTF8String], err)];

	return self;
}

- (instancetype)initFromResourceAtScaleWithResourcePath:(OFString*)resourcePath width:(int)width height:(int)height preserveAspectRatio:(bool)preserveAspectRatio err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_resource_at_scale([resourcePath UTF8String], width, height, preserveAspectRatio, err)];

	return self;
}

- (instancetype)initFromStreamWithStream:(GInputStream*)stream cancellable:(GCancellable*)cancellable err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_stream(stream, cancellable, err)];

	return self;
}

- (instancetype)initFromStreamAtScaleWithStream:(GInputStream*)stream width:(gint)width height:(gint)height preserveAspectRatio:(bool)preserveAspectRatio cancellable:(GCancellable*)cancellable err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_stream_at_scale(stream, width, height, preserveAspectRatio, cancellable, err)];

	return self;
}

- (instancetype)initFromStreamFinishWithAsyncResult:(GAsyncResult*)asyncResult err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_stream_finish(asyncResult, err)];

	return self;
}

- (instancetype)initFromXpmData:(const char**)data
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_new_from_xpm_data(data)];

	return self;
}

- (GdkPixbuf*)PIXBUF
{
	return GDK_PIXBUF([self GOBJECT]);
}

- (OGGdkPixbuf*)addAlphaWithSubstituteColor:(bool)substituteColor r:(guchar)r g:(guchar)g b:(guchar)b
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_add_alpha([self PIXBUF], substituteColor, r, g, b)] autorelease];
}

- (OGGdkPixbuf*)applyEmbeddedOrientation
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_apply_embedded_orientation([self PIXBUF])] autorelease];
}

- (void)compositeWithDest:(OGGdkPixbuf*)dest destX:(int)destX destY:(int)destY destWidth:(int)destWidth destHeight:(int)destHeight offsetX:(double)offsetX offsetY:(double)offsetY scaleX:(double)scaleX scaleY:(double)scaleY interpType:(GdkInterpType)interpType overallAlpha:(int)overallAlpha
{
	gdk_pixbuf_composite([self PIXBUF], [dest PIXBUF], destX, destY, destWidth, destHeight, offsetX, offsetY, scaleX, scaleY, interpType, overallAlpha);
}

- (void)compositeColorWithDest:(OGGdkPixbuf*)dest destX:(int)destX destY:(int)destY destWidth:(int)destWidth destHeight:(int)destHeight offsetX:(double)offsetX offsetY:(double)offsetY scaleX:(double)scaleX scaleY:(double)scaleY interpType:(GdkInterpType)interpType overallAlpha:(int)overallAlpha checkX:(int)checkX checkY:(int)checkY checkSize:(int)checkSize color1:(guint32)color1 color2:(guint32)color2
{
	gdk_pixbuf_composite_color([self PIXBUF], [dest PIXBUF], destX, destY, destWidth, destHeight, offsetX, offsetY, scaleX, scaleY, interpType, overallAlpha, checkX, checkY, checkSize, color1, color2);
}

- (OGGdkPixbuf*)compositeColorSimpleWithDestWidth:(int)destWidth destHeight:(int)destHeight interpType:(GdkInterpType)interpType overallAlpha:(int)overallAlpha checkSize:(int)checkSize color1:(guint32)color1 color2:(guint32)color2
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_composite_color_simple([self PIXBUF], destWidth, destHeight, interpType, overallAlpha, checkSize, color1, color2)] autorelease];
}

- (OGGdkPixbuf*)copy
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_copy([self PIXBUF])] autorelease];
}

- (void)copyAreaWithSrcX:(int)srcX srcY:(int)srcY width:(int)width height:(int)height destPixbuf:(OGGdkPixbuf*)destPixbuf destX:(int)destX destY:(int)destY
{
	gdk_pixbuf_copy_area([self PIXBUF], srcX, srcY, width, height, [destPixbuf PIXBUF], destX, destY);
}

- (bool)copyOptions:(OGGdkPixbuf*)destPixbuf
{
	return gdk_pixbuf_copy_options([self PIXBUF], [destPixbuf PIXBUF]);
}

- (void)fill:(guint32)pixel
{
	gdk_pixbuf_fill([self PIXBUF], pixel);
}

- (OGGdkPixbuf*)flip:(bool)horizontal
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_flip([self PIXBUF], horizontal)] autorelease];
}

- (int)bitsPerSample
{
	return gdk_pixbuf_get_bits_per_sample([self PIXBUF]);
}

- (gsize)byteLength
{
	return gdk_pixbuf_get_byte_length([self PIXBUF]);
}

- (GdkColorspace)colorspace
{
	return gdk_pixbuf_get_colorspace([self PIXBUF]);
}

- (bool)hasAlpha
{
	return gdk_pixbuf_get_has_alpha([self PIXBUF]);
}

- (int)height
{
	return gdk_pixbuf_get_height([self PIXBUF]);
}

- (int)nchannels
{
	return gdk_pixbuf_get_n_channels([self PIXBUF]);
}

- (OFString*)option:(OFString*)key
{
	return [OFString stringWithUTF8String:gdk_pixbuf_get_option([self PIXBUF], [key UTF8String])];
}

- (GHashTable*)options
{
	return gdk_pixbuf_get_options([self PIXBUF]);
}

- (guchar*)pixels
{
	return gdk_pixbuf_get_pixels([self PIXBUF]);
}

- (guchar*)pixelsWithLength:(guint*)length
{
	return gdk_pixbuf_get_pixels_with_length([self PIXBUF], length);
}

- (int)rowstride
{
	return gdk_pixbuf_get_rowstride([self PIXBUF]);
}

- (int)width
{
	return gdk_pixbuf_get_width([self PIXBUF]);
}

- (OGGdkPixbuf*)newSubpixbufWithSrcX:(int)srcX srcY:(int)srcY width:(int)width height:(int)height
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_new_subpixbuf([self PIXBUF], srcX, srcY, width, height)] autorelease];
}

- (GBytes*)readPixelBytes
{
	return gdk_pixbuf_read_pixel_bytes([self PIXBUF]);
}

- (const guint8*)readPixels
{
	return gdk_pixbuf_read_pixels([self PIXBUF]);
}

- (bool)removeOption:(OFString*)key
{
	return gdk_pixbuf_remove_option([self PIXBUF], [key UTF8String]);
}

- (OGGdkPixbuf*)rotateSimple:(GdkPixbufRotation)angle
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_rotate_simple([self PIXBUF], angle)] autorelease];
}

- (void)saturateAndPixelateWithDest:(OGGdkPixbuf*)dest saturation:(gfloat)saturation pixelate:(bool)pixelate
{
	gdk_pixbuf_saturate_and_pixelate([self PIXBUF], [dest PIXBUF], saturation, pixelate);
}

- (bool)saveToBuffervWithBuffer:(gchar**)buffer bufferSize:(gsize*)bufferSize type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues err:(GError**)err
{
	return gdk_pixbuf_save_to_bufferv([self PIXBUF], buffer, bufferSize, [type UTF8String], optionKeys, optionValues, err);
}

- (bool)saveToCallbackvWithSaveFunc:(GdkPixbufSaveFunc)saveFunc userData:(gpointer)userData type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues err:(GError**)err
{
	return gdk_pixbuf_save_to_callbackv([self PIXBUF], saveFunc, userData, [type UTF8String], optionKeys, optionValues, err);
}

- (bool)saveToStreamvWithStream:(GOutputStream*)stream type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues cancellable:(GCancellable*)cancellable err:(GError**)err
{
	return gdk_pixbuf_save_to_streamv([self PIXBUF], stream, [type UTF8String], optionKeys, optionValues, cancellable, err);
}

- (void)saveToStreamvAsyncWithStream:(GOutputStream*)stream type:(OFString*)type optionKeys:(gchar**)optionKeys optionValues:(gchar**)optionValues cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gdk_pixbuf_save_to_streamv_async([self PIXBUF], stream, [type UTF8String], optionKeys, optionValues, cancellable, callback, userData);
}

- (bool)savevWithFilename:(OFString*)filename type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues err:(GError**)err
{
	return gdk_pixbuf_savev([self PIXBUF], [filename UTF8String], [type UTF8String], optionKeys, optionValues, err);
}

- (void)scaleWithDest:(OGGdkPixbuf*)dest destX:(int)destX destY:(int)destY destWidth:(int)destWidth destHeight:(int)destHeight offsetX:(double)offsetX offsetY:(double)offsetY scaleX:(double)scaleX scaleY:(double)scaleY interpType:(GdkInterpType)interpType
{
	gdk_pixbuf_scale([self PIXBUF], [dest PIXBUF], destX, destY, destWidth, destHeight, offsetX, offsetY, scaleX, scaleY, interpType);
}

- (OGGdkPixbuf*)scaleSimpleWithDestWidth:(int)destWidth destHeight:(int)destHeight interpType:(GdkInterpType)interpType
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_scale_simple([self PIXBUF], destWidth, destHeight, interpType)] autorelease];
}

- (bool)setOptionWithKey:(OFString*)key value:(OFString*)value
{
	return gdk_pixbuf_set_option([self PIXBUF], [key UTF8String], [value UTF8String]);
}


@end