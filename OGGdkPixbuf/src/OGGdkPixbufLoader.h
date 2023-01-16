/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk-pixbuf/gdk-pixbuf.h>

#import <OGObject/OGObject.h>

@class OGGdkPixbufAnimation;
@class OGGdkPixbuf;

/**
 * The GdkPixbufLoader struct contains only private
 * fields.
 *
 */
@interface OGGdkPixbufLoader : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithMimeTypeWithMimeType:(OFString*)mimeType err:(GError**)err;
- (instancetype)initWithTypeWithImageType:(OFString*)imageType err:(GError**)err;

/**
 * Methods
 */

- (GdkPixbufLoader*)PIXBUFLOADER;

/**
 * Informs a pixbuf loader that no further writes with
 * gdk_pixbuf_loader_write() will occur, so that it can free its
 * internal loading structures. Also, tries to parse any data that
 * hasn't yet been parsed; if the remaining data is partial or
 * corrupt, an error will be returned.  If %FALSE is returned, @error
 * will be set to an error from the #GDK_PIXBUF_ERROR or #G_FILE_ERROR
 * domains. If you're just cancelling a load rather than expecting it
 * to be finished, passing %NULL for @error to ignore it is
 * reasonable.
 * 
 * Remember that this does not unref the loader, so if you plan not to
 * use it anymore, please g_object_unref() it.
 *
 * @param err
 * @return %TRUE if all image data written so far was successfully
 *             passed out via the update_area signal
 */
- (bool)close:(GError**)err;

/**
 * Queries the #GdkPixbufAnimation that a pixbuf loader is currently creating.
 * In general it only makes sense to call this function after the "area-prepared"
 * signal has been emitted by the loader. If the loader doesn't have enough
 * bytes yet (hasn't emitted the "area-prepared" signal) this function will
 * return %NULL.
 *
 * @return The #GdkPixbufAnimation that the loader is loading, or %NULL if
 * not enough data has been read to determine the information.
 */
- (OGGdkPixbufAnimation*)animation;

/**
 * Obtains the available information about the format of the
 * currently loading image file.
 *
 * @return A #GdkPixbufFormat or
 * %NULL. The return value is owned by GdkPixbuf and should not be
 * freed.
 */
- (GdkPixbufFormat*)format;

/**
 * Queries the #GdkPixbuf that a pixbuf loader is currently creating.
 * In general it only makes sense to call this function after the
 * "area-prepared" signal has been emitted by the loader; this means
 * that enough data has been read to know the size of the image that
 * will be allocated.  If the loader has not received enough data via
 * gdk_pixbuf_loader_write(), then this function returns %NULL.  The
 * returned pixbuf will be the same in all future calls to the loader,
 * so simply calling g_object_ref() should be sufficient to continue
 * using it.  Additionally, if the loader is an animation, it will
 * return the "static image" of the animation
 * (see gdk_pixbuf_animation_get_static_image()).
 *
 * @return The #GdkPixbuf that the loader is creating, or %NULL if not
 * enough data has been read to determine how to create the image buffer.
 */
- (OGGdkPixbuf*)pixbuf;

/**
 * Causes the image to be scaled while it is loaded. The desired
 * image size can be determined relative to the original size of
 * the image by calling gdk_pixbuf_loader_set_size() from a
 * signal handler for the ::size-prepared signal.
 * 
 * Attempts to set the desired image size  are ignored after the
 * emission of the ::size-prepared signal.
 *
 * @param width The desired width of the image being loaded.
 * @param height The desired height of the image being loaded.
 */
- (void)setSizeWithWidth:(int)width height:(int)height;

/**
 * This will cause a pixbuf loader to parse the next @count bytes of
 * an image.  It will return %TRUE if the data was loaded successfully,
 * and %FALSE if an error occurred.  In the latter case, the loader
 * will be closed, and will not accept further writes. If %FALSE is
 * returned, @error will be set to an error from the #GDK_PIXBUF_ERROR
 * or #G_FILE_ERROR domains.
 *
 * @param buf Pointer to image data.
 * @param count Length of the @buf buffer in bytes.
 * @param err
 * @return %TRUE if the write was successful, or %FALSE if the loader
 * cannot parse the buffer.
 */
- (bool)writeWithBuf:(const guchar*)buf count:(gsize)count err:(GError**)err;

/**
 * This will cause a pixbuf loader to parse a buffer inside a #GBytes
 * for an image.  It will return %TRUE if the data was loaded successfully,
 * and %FALSE if an error occurred.  In the latter case, the loader
 * will be closed, and will not accept further writes. If %FALSE is
 * returned, @error will be set to an error from the #GDK_PIXBUF_ERROR
 * or #G_FILE_ERROR domains.
 * 
 * See also: gdk_pixbuf_loader_write()
 *
 * @param buffer The image data as a #GBytes
 * @param err
 * @return %TRUE if the write was successful, or %FALSE if the loader
 * cannot parse the buffer.
 */
- (bool)writeBytesWithBuffer:(GBytes*)buffer err:(GError**)err;

@end