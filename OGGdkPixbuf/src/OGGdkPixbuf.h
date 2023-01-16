/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk-pixbuf/gdk-pixbuf.h>

#import <OGObject/OGObject.h>

/**
 * This is the main structure in the gdk-pixbuf library.  It is
 * used to represent images.  It contains information about the
 * image's pixel data, its color space, bits per sample, width and
 * height, and the rowstride (the number of bytes between the start of
 * one row and the start of the next).
 *
 */
@interface OGGdkPixbuf : OGObject
{

}

/**
 * Functions
 */

/**
 * Calculates the rowstride that an image created with those values would
 * have. This is useful for front-ends and backends that want to sanity
 * check image values without needing to create them.
 *
 * @param colorspace Color space for image
 * @param hasAlpha Whether the image should have transparency information
 * @param bitsPerSample Number of bits per color sample
 * @param width Width of image in pixels, must be > 0
 * @param height Height of image in pixels, must be > 0
 * @return the rowstride for the given values, or -1 in case of error.
 */
+ (gint)calculateRowstrideWithColorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height;

/**
 * Parses an image file far enough to determine its format and size.
 *
 * @param filename The name of the file to identify.
 * @param width Return location for the width of the
 *     image, or %NULL
 * @param height Return location for the height of the
 *     image, or %NULL
 * @return A #GdkPixbufFormat describing
 *    the image format of the file or %NULL if the image format wasn't
 *    recognized. The return value is owned by #GdkPixbuf and should
 *    not be freed.
 */
+ (GdkPixbufFormat*)fileInfoWithFilename:(OFString*)filename width:(gint*)width height:(gint*)height;

/**
 * Asynchronously parses an image file far enough to determine its
 * format and size.
 * 
 * For more details see gdk_pixbuf_get_file_info(), which is the synchronous
 * version of this function.
 * 
 * When the operation is finished, @callback will be called in the
 * main thread. You can then call gdk_pixbuf_get_file_info_finish() to
 * get the result of the operation.
 *
 * @param filename The name of the file to identify
 * @param cancellable optional #GCancellable object, %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the file info is available
 * @param userData the data to pass to the callback function
 */
+ (void)fileInfoAsyncWithFilename:(OFString*)filename cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Finishes an asynchronous pixbuf parsing operation started with
 * gdk_pixbuf_get_file_info_async().
 *
 * @param asyncResult a #GAsyncResult
 * @param width Return location for the width of the image, or %NULL
 * @param height Return location for the height of the image, or %NULL
 * @param err
 * @return A #GdkPixbufFormat describing the image
 *    format of the file or %NULL if the image format wasn't
 *    recognized. The return value is owned by GdkPixbuf and should
 *    not be freed.
 */
+ (GdkPixbufFormat*)fileInfoFinishWithAsyncResult:(GAsyncResult*)asyncResult width:(gint*)width height:(gint*)height err:(GError**)err;

/**
 * Obtains the available information about the image formats supported
 * by GdkPixbuf.
 *
 * @return A list of
 * #GdkPixbufFormats describing the supported image formats. The list should
 * be freed when it is no longer needed, but the structures themselves are
 * owned by #GdkPixbuf and should not be freed.
 */
+ (GSList*)formats;

/**
 * Initalizes the gdk-pixbuf loader modules referenced by the loaders.cache
 * file present inside that directory.
 * 
 * This is to be used by applications that want to ship certain loaders
 * in a different location from the system ones.
 * 
 * This is needed when the OS or runtime ships a minimal number of loaders
 * so as to reduce the potential attack surface of carefully crafted image
 * files, especially for uncommon file types. Applications that require
 * broader image file types coverage, such as image viewers, would be
 * expected to ship the gdk-pixbuf modules in a separate location, bundled
 * with the application in a separate directory from the OS or runtime-
 * provided modules.
 *
 * @param path Path to directory where the loaders.cache is installed
 * @param err
 * @return
 */
+ (bool)initModulesWithPath:(OFString*)path err:(GError**)err;

/**
 * Creates a new pixbuf by asynchronously loading an image from an input stream.
 * 
 * For more details see gdk_pixbuf_new_from_stream(), which is the synchronous
 * version of this function.
 * 
 * When the operation is finished, @callback will be called in the main thread.
 * You can then call gdk_pixbuf_new_from_stream_finish() to get the result of the operation.
 *
 * @param stream a #GInputStream from which to load the pixbuf
 * @param cancellable optional #GCancellable object, %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the pixbuf is loaded
 * @param userData the data to pass to the callback function
 */
+ (void)newFromStreamAsyncWithStream:(GInputStream*)stream cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Creates a new pixbuf by asynchronously loading an image from an input stream.
 * 
 * For more details see gdk_pixbuf_new_from_stream_at_scale(), which is the synchronous
 * version of this function.
 * 
 * When the operation is finished, @callback will be called in the main thread.
 * You can then call gdk_pixbuf_new_from_stream_finish() to get the result of the operation.
 *
 * @param stream a #GInputStream from which to load the pixbuf
 * @param width the width the image should have or -1 to not constrain the width
 * @param height the height the image should have or -1 to not constrain the height
 * @param preserveAspectRatio %TRUE to preserve the image's aspect ratio
 * @param cancellable optional #GCancellable object, %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the pixbuf is loaded
 * @param userData the data to pass to the callback function
 */
+ (void)newFromStreamAtScaleAsyncWithStream:(GInputStream*)stream width:(gint)width height:(gint)height preserveAspectRatio:(bool)preserveAspectRatio cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Finishes an asynchronous pixbuf save operation started with
 * gdk_pixbuf_save_to_stream_async().
 *
 * @param asyncResult a #GAsyncResult
 * @param err
 * @return %TRUE if the pixbuf was saved successfully, %FALSE if an error was set.
 */
+ (bool)saveToStreamFinishWithAsyncResult:(GAsyncResult*)asyncResult err:(GError**)err;

/**
 * Constructors
 */
- (instancetype)initWithColorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height;
- (instancetype)initFromBytesWithData:(GBytes*)data colorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height rowstride:(int)rowstride;
- (instancetype)initFromDataWithData:(const guchar*)data colorspace:(GdkColorspace)colorspace hasAlpha:(bool)hasAlpha bitsPerSample:(int)bitsPerSample width:(int)width height:(int)height rowstride:(int)rowstride destroyFn:(GdkPixbufDestroyNotify)destroyFn destroyFnData:(gpointer)destroyFnData;
- (instancetype)initFromFileWithFilename:(OFString*)filename err:(GError**)err;
- (instancetype)initFromFileAtScaleWithFilename:(OFString*)filename width:(int)width height:(int)height preserveAspectRatio:(bool)preserveAspectRatio err:(GError**)err;
- (instancetype)initFromFileAtSizeWithFilename:(OFString*)filename width:(int)width height:(int)height err:(GError**)err;
- (instancetype)initFromInlineWithDataLength:(gint)dataLength data:(const guint8*)data copyPixels:(bool)copyPixels err:(GError**)err;
- (instancetype)initFromResourceWithResourcePath:(OFString*)resourcePath err:(GError**)err;
- (instancetype)initFromResourceAtScaleWithResourcePath:(OFString*)resourcePath width:(int)width height:(int)height preserveAspectRatio:(bool)preserveAspectRatio err:(GError**)err;
- (instancetype)initFromStreamWithStream:(GInputStream*)stream cancellable:(GCancellable*)cancellable err:(GError**)err;
- (instancetype)initFromStreamAtScaleWithStream:(GInputStream*)stream width:(gint)width height:(gint)height preserveAspectRatio:(bool)preserveAspectRatio cancellable:(GCancellable*)cancellable err:(GError**)err;
- (instancetype)initFromStreamFinishWithAsyncResult:(GAsyncResult*)asyncResult err:(GError**)err;
- (instancetype)initFromXpmData:(const char**)data;

/**
 * Methods
 */

- (GdkPixbuf*)PIXBUF;

/**
 * Takes an existing pixbuf and adds an alpha channel to it.
 * If the existing pixbuf already had an alpha channel, the channel
 * values are copied from the original; otherwise, the alpha channel
 * is initialized to 255 (full opacity).
 * 
 * If @substitute_color is %TRUE, then the color specified by (@r, @g, @b) will be
 * assigned zero opacity. That is, if you pass (255, 255, 255) for the
 * substitute color, all white pixels will become fully transparent.
 *
 * @param substituteColor Whether to set a color to zero opacity.  If this
 * is %FALSE, then the (@r, @g, @b) arguments will be ignored.
 * @param r Red value to substitute.
 * @param g Green value to substitute.
 * @param b Blue value to substitute.
 * @return A newly-created pixbuf with a reference count of 1.
 */
- (OGGdkPixbuf*)addAlphaWithSubstituteColor:(bool)substituteColor r:(guchar)r g:(guchar)g b:(guchar)b;

/**
 * Takes an existing pixbuf and checks for the presence of an
 * associated "orientation" option, which may be provided by the
 * jpeg loader (which reads the exif orientation tag) or the
 * tiff loader (which reads the tiff orientation tag, and
 * compensates it for the partial transforms performed by
 * libtiff). If an orientation option/tag is present, the
 * appropriate transform will be performed so that the pixbuf
 * is oriented correctly.
 *
 * @return A newly-created pixbuf, %NULL if
 * not enough memory could be allocated for it, or a reference to the
 * input pixbuf (with an increased reference count).
 */
- (OGGdkPixbuf*)applyEmbeddedOrientation;

/**
 * Creates a transformation of the source image @src by scaling by
 * @scale_x and @scale_y then translating by @offset_x and @offset_y.
 * This gives an image in the coordinates of the destination pixbuf.
 * The rectangle (@dest_x, @dest_y, @dest_width, @dest_height)
 * is then alpha blended onto the corresponding rectangle of the
 * original destination image.
 * 
 * When the destination rectangle contains parts not in the source
 * image, the data at the edges of the source image is replicated
 * to infinity.
 * 
 * ![](composite.png)
 *
 * @param dest the #GdkPixbuf into which to render the results
 * @param destX the left coordinate for region to render
 * @param destY the top coordinate for region to render
 * @param destWidth the width of the region to render
 * @param destHeight the height of the region to render
 * @param offsetX the offset in the X direction (currently rounded to an integer)
 * @param offsetY the offset in the Y direction (currently rounded to an integer)
 * @param scaleX the scale factor in the X direction
 * @param scaleY the scale factor in the Y direction
 * @param interpType the interpolation type for the transformation.
 * @param overallAlpha overall alpha for source image (0..255)
 */
- (void)compositeWithDest:(OGGdkPixbuf*)dest destX:(int)destX destY:(int)destY destWidth:(int)destWidth destHeight:(int)destHeight offsetX:(double)offsetX offsetY:(double)offsetY scaleX:(double)scaleX scaleY:(double)scaleY interpType:(GdkInterpType)interpType overallAlpha:(int)overallAlpha;

/**
 * Creates a transformation of the source image @src by scaling by
 * @scale_x and @scale_y then translating by @offset_x and @offset_y,
 * then alpha blends the rectangle (@dest_x ,@dest_y, @dest_width,
 * @dest_height) of the resulting image with a checkboard of the
 * colors @color1 and @color2 and renders it onto the destination
 * image.
 * 
 * If the source image has no alpha channel, and @overall_alpha is 255, a fast
 * path is used which omits the alpha blending and just performs the scaling.
 * 
 * See gdk_pixbuf_composite_color_simple() for a simpler variant of this
 * function suitable for many tasks.
 *
 * @param dest the #GdkPixbuf into which to render the results
 * @param destX the left coordinate for region to render
 * @param destY the top coordinate for region to render
 * @param destWidth the width of the region to render
 * @param destHeight the height of the region to render
 * @param offsetX the offset in the X direction (currently rounded to an integer)
 * @param offsetY the offset in the Y direction (currently rounded to an integer)
 * @param scaleX the scale factor in the X direction
 * @param scaleY the scale factor in the Y direction
 * @param interpType the interpolation type for the transformation.
 * @param overallAlpha overall alpha for source image (0..255)
 * @param checkX the X offset for the checkboard (origin of checkboard is at -@check_x, -@check_y)
 * @param checkY the Y offset for the checkboard
 * @param checkSize the size of checks in the checkboard (must be a power of two)
 * @param color1 the color of check at upper left
 * @param color2 the color of the other check
 */
- (void)compositeColorWithDest:(OGGdkPixbuf*)dest destX:(int)destX destY:(int)destY destWidth:(int)destWidth destHeight:(int)destHeight offsetX:(double)offsetX offsetY:(double)offsetY scaleX:(double)scaleX scaleY:(double)scaleY interpType:(GdkInterpType)interpType overallAlpha:(int)overallAlpha checkX:(int)checkX checkY:(int)checkY checkSize:(int)checkSize color1:(guint32)color1 color2:(guint32)color2;

/**
 * Creates a new #GdkPixbuf by scaling @src to @dest_width x
 * @dest_height and alpha blending the result with a checkboard of colors
 * @color1 and @color2.
 *
 * @param destWidth the width of destination image
 * @param destHeight the height of destination image
 * @param interpType the interpolation type for the transformation.
 * @param overallAlpha overall alpha for source image (0..255)
 * @param checkSize the size of checks in the checkboard (must be a power of two)
 * @param color1 the color of check at upper left
 * @param color2 the color of the other check
 * @return the new #GdkPixbuf, or %NULL if not enough memory could be
 * allocated for it.
 */
- (OGGdkPixbuf*)compositeColorSimpleWithDestWidth:(int)destWidth destHeight:(int)destHeight interpType:(GdkInterpType)interpType overallAlpha:(int)overallAlpha checkSize:(int)checkSize color1:(guint32)color1 color2:(guint32)color2;

/**
 * Creates a new #GdkPixbuf with a copy of the information in the specified
 * @pixbuf. Note that this does not copy the options set on the original #GdkPixbuf,
 * use gdk_pixbuf_copy_options() for this.
 *
 * @return A newly-created pixbuf with a reference count of 1, or %NULL if
 * not enough memory could be allocated.
 */
- (OGGdkPixbuf*)copy;

/**
 * Copies a rectangular area from @src_pixbuf to @dest_pixbuf.  Conversion of
 * pixbuf formats is done automatically.
 * 
 * If the source rectangle overlaps the destination rectangle on the
 * same pixbuf, it will be overwritten during the copy operation.
 * Therefore, you can not use this function to scroll a pixbuf.
 *
 * @param srcX Source X coordinate within @src_pixbuf.
 * @param srcY Source Y coordinate within @src_pixbuf.
 * @param width Width of the area to copy.
 * @param height Height of the area to copy.
 * @param destPixbuf Destination pixbuf.
 * @param destX X coordinate within @dest_pixbuf.
 * @param destY Y coordinate within @dest_pixbuf.
 */
- (void)copyAreaWithSrcX:(int)srcX srcY:(int)srcY width:(int)width height:(int)height destPixbuf:(OGGdkPixbuf*)destPixbuf destX:(int)destX destY:(int)destY;

/**
 * Copy the key/value pair options attached to a #GdkPixbuf to another.
 * This is useful to keep original metadata after having manipulated
 * a file. However be careful to remove metadata which you've already
 * applied, such as the "orientation" option after rotating the image.
 *
 * @param destPixbuf the #GdkPixbuf to copy options to
 * @return %TRUE on success.
 */
- (bool)copyOptions:(OGGdkPixbuf*)destPixbuf;

/**
 * Clears a pixbuf to the given RGBA value, converting the RGBA value into
 * the pixbuf's pixel format. The alpha will be ignored if the pixbuf
 * doesn't have an alpha channel.
 *
 * @param pixel RGBA pixel to clear to
 *         (0xffffffff is opaque white, 0x00000000 transparent black)
 */
- (void)fill:(guint32)pixel;

/**
 * Flips a pixbuf horizontally or vertically and returns the
 * result in a new pixbuf.
 *
 * @param horizontal %TRUE to flip horizontally, %FALSE to flip vertically
 * @return the new #GdkPixbuf, or %NULL
 * if not enough memory could be allocated for it.
 */
- (OGGdkPixbuf*)flip:(bool)horizontal;

/**
 * Queries the number of bits per color sample in a pixbuf.
 *
 * @return Number of bits per color sample.
 */
- (int)bitsPerSample;

/**
 * Returns the length of the pixel data, in bytes.
 *
 * @return The length of the pixel data.
 */
- (gsize)byteLength;

/**
 * Queries the color space of a pixbuf.
 *
 * @return Color space.
 */
- (GdkColorspace)colorspace;

/**
 * Queries whether a pixbuf has an alpha channel (opacity information).
 *
 * @return %TRUE if it has an alpha channel, %FALSE otherwise.
 */
- (bool)hasAlpha;

/**
 * Queries the height of a pixbuf.
 *
 * @return Height in pixels.
 */
- (int)height;

/**
 * Queries the number of channels of a pixbuf.
 *
 * @return Number of channels.
 */
- (int)nchannels;

/**
 * Looks up @key in the list of options that may have been attached to the
 * @pixbuf when it was loaded, or that may have been attached by another
 * function using gdk_pixbuf_set_option().
 * 
 * For instance, the ANI loader provides "Title" and "Artist" options.
 * The ICO, XBM, and XPM loaders provide "x_hot" and "y_hot" hot-spot
 * options for cursor definitions. The PNG loader provides the tEXt ancillary
 * chunk key/value pairs as options. Since 2.12, the TIFF and JPEG loaders
 * return an "orientation" option string that corresponds to the embedded
 * TIFF/Exif orientation tag (if present). Since 2.32, the TIFF loader sets
 * the "multipage" option string to "yes" when a multi-page TIFF is loaded.
 * Since 2.32 the JPEG and PNG loaders set "x-dpi" and "y-dpi" if the file
 * contains image density information in dots per inch.
 * Since 2.36.6, the JPEG loader sets the "comment" option with the comment
 * EXIF tag.
 *
 * @param key a nul-terminated string.
 * @return the value associated with @key. This is a nul-terminated
 * string that should not be freed or %NULL if @key was not found.
 */
- (OFString*)option:(OFString*)key;

/**
 * Returns a #GHashTable with a list of all the options that may have been
 * attached to the @pixbuf when it was loaded, or that may have been
 * attached by another function using gdk_pixbuf_set_option().
 * 
 * See gdk_pixbuf_get_option() for more details.
 *
 * @return a #GHashTable of key/values
 */
- (GHashTable*)options;

/**
 * Queries a pointer to the pixel data of a pixbuf.
 *
 * @return A pointer to the pixbuf's pixel data.
 * Please see the section on [image data][image-data] for information
 * about how the pixel data is stored in memory.
 * 
 * This function will cause an implicit copy of the pixbuf data if the
 * pixbuf was created from read-only data.
 */
- (guchar*)pixels;

/**
 * Queries a pointer to the pixel data of a pixbuf.
 *
 * @param length The length of the binary data.
 * @return A pointer to the pixbuf's
 * pixel data.  Please see the section on [image data][image-data]
 * for information about how the pixel data is stored in memory.
 * 
 * This function will cause an implicit copy of the pixbuf data if the
 * pixbuf was created from read-only data.
 */
- (guchar*)pixelsWithLength:(guint*)length;

/**
 * Queries the rowstride of a pixbuf, which is the number of bytes between
 * the start of a row and the start of the next row.
 *
 * @return Distance between row starts.
 */
- (int)rowstride;

/**
 * Queries the width of a pixbuf.
 *
 * @return Width in pixels.
 */
- (int)width;

/**
 * Creates a new pixbuf which represents a sub-region of @src_pixbuf.
 * The new pixbuf shares its pixels with the original pixbuf, so
 * writing to one affects both.  The new pixbuf holds a reference to
 * @src_pixbuf, so @src_pixbuf will not be finalized until the new
 * pixbuf is finalized.
 * 
 * Note that if @src_pixbuf is read-only, this function will force it
 * to be mutable.
 *
 * @param srcX X coord in @src_pixbuf
 * @param srcY Y coord in @src_pixbuf
 * @param width width of region in @src_pixbuf
 * @param height height of region in @src_pixbuf
 * @return a new pixbuf
 */
- (OGGdkPixbuf*)newSubpixbufWithSrcX:(int)srcX srcY:(int)srcY width:(int)width height:(int)height;

/**
 * Provides a #GBytes buffer containing the raw pixel data; the data
 * must not be modified.  This function allows skipping the implicit
 * copy that must be made if gdk_pixbuf_get_pixels() is called on a
 * read-only pixbuf.
 *
 * @return A new reference to a read-only copy of
 *   the pixel data.  Note that for mutable pixbufs, this function will
 *   incur a one-time copy of the pixel data for conversion into the
 *   returned #GBytes.
 */
- (GBytes*)readPixelBytes;

/**
 * Provides a read-only pointer to the raw pixel data; must not be
 * modified.  This function allows skipping the implicit copy that
 * must be made if gdk_pixbuf_get_pixels() is called on a read-only
 * pixbuf.
 *
 * @return a read-only pointer to the raw pixel data
 */
- (const guint8*)readPixels;

/**
 * Remove the key/value pair option attached to a #GdkPixbuf.
 *
 * @param key a nul-terminated string representing the key to remove.
 * @return %TRUE if an option was removed, %FALSE if not.
 */
- (bool)removeOption:(OFString*)key;

/**
 * Rotates a pixbuf by a multiple of 90 degrees, and returns the
 * result in a new pixbuf.
 * 
 * If @angle is 0, a copy of @src is returned, avoiding any rotation.
 *
 * @param angle the angle to rotate by
 * @return the new #GdkPixbuf, or %NULL
 * if not enough memory could be allocated for it.
 */
- (OGGdkPixbuf*)rotateSimple:(GdkPixbufRotation)angle;

/**
 * Modifies saturation and optionally pixelates @src, placing the result in
 * @dest. @src and @dest may be the same pixbuf with no ill effects.  If
 * @saturation is 1.0 then saturation is not changed. If it's less than 1.0,
 * saturation is reduced (the image turns toward grayscale); if greater than
 * 1.0, saturation is increased (the image gets more vivid colors). If @pixelate
 * is %TRUE, then pixels are faded in a checkerboard pattern to create a
 * pixelated image. @src and @dest must have the same image format, size, and
 * rowstride.
 *
 * @param dest place to write modified version of @src
 * @param saturation saturation factor
 * @param pixelate whether to pixelate
 */
- (void)saturateAndPixelateWithDest:(OGGdkPixbuf*)dest saturation:(gfloat)saturation pixelate:(bool)pixelate;

/**
 * Saves pixbuf to a new buffer in format @type, which is currently "jpeg",
 * "tiff", "png", "ico" or "bmp".  See gdk_pixbuf_save_to_buffer()
 * for more details.
 *
 * @param buffer location to receive a pointer to the new buffer.
 * @param bufferSize location to receive the size of the new buffer.
 * @param type name of file format.
 * @param optionKeys name of options to set, %NULL-terminated
 * @param optionValues values for named options
 * @param err
 * @return whether an error was set
 */
- (bool)saveToBuffervWithBuffer:(gchar**)buffer bufferSize:(gsize*)bufferSize type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues err:(GError**)err;

/**
 * Saves pixbuf to a callback in format @type, which is currently "jpeg",
 * "png", "tiff", "ico" or "bmp".  If @error is set, %FALSE will be returned. See
 * gdk_pixbuf_save_to_callback () for more details.
 *
 * @param saveFunc a function that is called to save each block of data that
 *   the save routine generates.
 * @param userData user data to pass to the save function.
 * @param type name of file format.
 * @param optionKeys name of options to set, %NULL-terminated
 * @param optionValues values for named options
 * @param err
 * @return whether an error was set
 */
- (bool)saveToCallbackvWithSaveFunc:(GdkPixbufSaveFunc)saveFunc userData:(gpointer)userData type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues err:(GError**)err;

/**
 * Saves @pixbuf to an output stream.
 * 
 * Supported file formats are currently "jpeg", "tiff", "png", "ico" or
 * "bmp". See gdk_pixbuf_save_to_stream() for more details.
 *
 * @param stream a #GOutputStream to save the pixbuf to
 * @param type name of file format
 * @param optionKeys name of options to set, %NULL-terminated
 * @param optionValues values for named options
 * @param cancellable optional #GCancellable object, %NULL to ignore
 * @param err
 * @return %TRUE if the pixbuf was saved successfully, %FALSE if an
 *     error was set.
 */
- (bool)saveToStreamvWithStream:(GOutputStream*)stream type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues cancellable:(GCancellable*)cancellable err:(GError**)err;

/**
 * Saves @pixbuf to an output stream asynchronously.
 * 
 * For more details see gdk_pixbuf_save_to_streamv(), which is the synchronous
 * version of this function.
 * 
 * When the operation is finished, @callback will be called in the main thread.
 * You can then call gdk_pixbuf_save_to_stream_finish() to get the result of the operation.
 *
 * @param stream a #GOutputStream to which to save the pixbuf
 * @param type name of file format
 * @param optionKeys name of options to set, %NULL-terminated
 * @param optionValues values for named options
 * @param cancellable optional #GCancellable object, %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the pixbuf is saved
 * @param userData the data to pass to the callback function
 */
- (void)saveToStreamvAsyncWithStream:(GOutputStream*)stream type:(OFString*)type optionKeys:(gchar**)optionKeys optionValues:(gchar**)optionValues cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Saves pixbuf to a file in @type, which is currently "jpeg", "png", "tiff", "ico" or "bmp".
 * If @error is set, %FALSE will be returned.
 * See gdk_pixbuf_save () for more details.
 *
 * @param filename name of file to save.
 * @param type name of file format.
 * @param optionKeys name of options to set, %NULL-terminated
 * @param optionValues values for named options
 * @param err
 * @return whether an error was set
 */
- (bool)savevWithFilename:(OFString*)filename type:(OFString*)type optionKeys:(char**)optionKeys optionValues:(char**)optionValues err:(GError**)err;

/**
 * Creates a transformation of the source image @src by scaling by
 * @scale_x and @scale_y then translating by @offset_x and @offset_y,
 * then renders the rectangle (@dest_x, @dest_y, @dest_width,
 * @dest_height) of the resulting image onto the destination image
 * replacing the previous contents.
 * 
 * Try to use gdk_pixbuf_scale_simple() first, this function is
 * the industrial-strength power tool you can fall back to if
 * gdk_pixbuf_scale_simple() isn't powerful enough.
 * 
 * If the source rectangle overlaps the destination rectangle on the
 * same pixbuf, it will be overwritten during the scaling which
 * results in rendering artifacts.
 *
 * @param dest the #GdkPixbuf into which to render the results
 * @param destX the left coordinate for region to render
 * @param destY the top coordinate for region to render
 * @param destWidth the width of the region to render
 * @param destHeight the height of the region to render
 * @param offsetX the offset in the X direction (currently rounded to an integer)
 * @param offsetY the offset in the Y direction (currently rounded to an integer)
 * @param scaleX the scale factor in the X direction
 * @param scaleY the scale factor in the Y direction
 * @param interpType the interpolation type for the transformation.
 */
- (void)scaleWithDest:(OGGdkPixbuf*)dest destX:(int)destX destY:(int)destY destWidth:(int)destWidth destHeight:(int)destHeight offsetX:(double)offsetX offsetY:(double)offsetY scaleX:(double)scaleX scaleY:(double)scaleY interpType:(GdkInterpType)interpType;

/**
 * Create a new #GdkPixbuf containing a copy of @src scaled to
 * @dest_width x @dest_height. Leaves @src unaffected.  @interp_type
 * should be #GDK_INTERP_NEAREST if you want maximum speed (but when
 * scaling down #GDK_INTERP_NEAREST is usually unusably ugly).  The
 * default @interp_type should be #GDK_INTERP_BILINEAR which offers
 * reasonable quality and speed.
 * 
 * You can scale a sub-portion of @src by creating a sub-pixbuf
 * pointing into @src; see gdk_pixbuf_new_subpixbuf().
 * 
 * If @dest_width and @dest_height are equal to the @src width and height, a
 * copy of @src is returned, avoiding any scaling.
 * 
 * For more complicated scaling/alpha blending see gdk_pixbuf_scale()
 * and gdk_pixbuf_composite().
 *
 * @param destWidth the width of destination image
 * @param destHeight the height of destination image
 * @param interpType the interpolation type for the transformation.
 * @return the new #GdkPixbuf, or %NULL if not enough memory could be
 * allocated for it.
 */
- (OGGdkPixbuf*)scaleSimpleWithDestWidth:(int)destWidth destHeight:(int)destHeight interpType:(GdkInterpType)interpType;

/**
 * Attaches a key/value pair as an option to a #GdkPixbuf. If @key already
 * exists in the list of options attached to @pixbuf, the new value is
 * ignored and %FALSE is returned.
 *
 * @param key a nul-terminated string.
 * @param value a nul-terminated string.
 * @return %TRUE on success.
 */
- (bool)setOptionWithKey:(OFString*)key value:(OFString*)value;

@end