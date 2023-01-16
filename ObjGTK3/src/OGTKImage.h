/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGAtk/OGAtkMisc.h>

@class OGGdkPixbuf;
@class OGTKWidget;
@class OGGdkPixbufAnimation;

/**
 * The #GtkImage widget displays an image. Various kinds of object
 * can be displayed as an image; most typically, you would load a
 * #GdkPixbuf ("pixel buffer") from a file, and then display that.
 * There’s a convenience function to do this, gtk_image_new_from_file(),
 * used as follows:
 * |[<!-- language="C" -->
 *   GtkWidget *image;
 *   image = gtk_image_new_from_file ("myfile.png");
 * ]|
 * If the file isn’t loaded successfully, the image will contain a
 * “broken image” icon similar to that used in many web browsers.
 * If you want to handle errors in loading the file yourself,
 * for example by displaying an error message, then load the image with
 * gdk_pixbuf_new_from_file(), then create the #GtkImage with
 * gtk_image_new_from_pixbuf().
 * 
 * The image file may contain an animation, if so the #GtkImage will
 * display an animation (#GdkPixbufAnimation) instead of a static image.
 * 
 * #GtkImage is a subclass of #GtkMisc, which implies that you can
 * align it (center, left, right) and add padding to it, using
 * #GtkMisc methods.
 * 
 * #GtkImage is a “no window” widget (has no #GdkWindow of its own),
 * so by default does not receive events. If you want to receive events
 * on the image, such as button clicks, place the image inside a
 * #GtkEventBox, then connect to the event signals on the event box.
 * 
 * ## Handling button press events on a #GtkImage.
 * 
 * |[<!-- language="C" -->
 *   static gboolean
 *   button_press_callback (GtkWidget      *event_box,
 *                          GdkEventButton *event,
 *                          gpointer        data)
 *   {
 *     g_print ("Event box clicked at coordinates %f,%f\n",
 *              event->x, event->y);
 * 
 *     // Returning TRUE means we handled the event, so the signal
 *     // emission should be stopped (don’t call any further callbacks
 *     // that may be connected). Return FALSE to continue invoking callbacks.
 *     return TRUE;
 *   }
 * 
 *   static GtkWidget*
 *   create_image (void)
 *   {
 *     GtkWidget *image;
 *     GtkWidget *event_box;
 * 
 *     image = gtk_image_new_from_file ("myfile.png");
 * 
 *     event_box = gtk_event_box_new ();
 * 
 *     gtk_container_add (GTK_CONTAINER (event_box), image);
 * 
 *     g_signal_connect (G_OBJECT (event_box),
 *                       "button_press_event",
 *                       G_CALLBACK (button_press_callback),
 *                       image);
 * 
 *     return image;
 *   }
 * ]|
 * 
 * When handling events on the event box, keep in mind that coordinates
 * in the image may be different from event box coordinates due to
 * the alignment and padding settings on the image (see #GtkMisc).
 * The simplest way to solve this is to set the alignment to 0.0
 * (left/top), and set the padding to zero. Then the origin of
 * the image will be the same as the origin of the event box.
 * 
 * Sometimes an application will want to avoid depending on external data
 * files, such as image files. GTK+ comes with a program to avoid this,
 * called “gdk-pixbuf-csource”. This library
 * allows you to convert an image into a C variable declaration, which
 * can then be loaded into a #GdkPixbuf using
 * gdk_pixbuf_new_from_inline().
 * 
 * # CSS nodes
 * 
 * GtkImage has a single CSS node with the name image. The style classes
 * may appear on image CSS nodes: .icon-dropshadow, .lowres-icon.
 *
 */
@interface OGTKImage : OGAtkMisc
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromAnimation:(OGGdkPixbufAnimation*)animation;
- (instancetype)initFromFile:(OFString*)filename;
- (instancetype)initFromGiconWithIcon:(GIcon*)icon size:(GtkIconSize)size;
- (instancetype)initFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size;
- (instancetype)initFromIconSetWithIconSet:(GtkIconSet*)iconSet size:(GtkIconSize)size;
- (instancetype)initFromPixbuf:(OGGdkPixbuf*)pixbuf;
- (instancetype)initFromResource:(OFString*)resourcePath;
- (instancetype)initFromStockWithStockId:(OFString*)stockId size:(GtkIconSize)size;
- (instancetype)initFromSurface:(cairo_surface_t*)surface;

/**
 * Methods
 */

- (GtkImage*)IMAGE;

/**
 * Resets the image to be empty.
 *
 */
- (void)clear;

/**
 * Gets the #GdkPixbufAnimation being displayed by the #GtkImage.
 * The storage type of the image must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_ANIMATION (see gtk_image_get_storage_type()).
 * The caller of this function does not own a reference to the
 * returned animation.
 *
 * @return the displayed animation, or %NULL if
 * the image is empty
 */
- (OGGdkPixbufAnimation*)animation;

/**
 * Gets the #GIcon and size being displayed by the #GtkImage.
 * The storage type of the image must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_GICON (see gtk_image_get_storage_type()).
 * The caller of this function does not own a reference to the
 * returned #GIcon.
 *
 * @param gicon place to store a
 *     #GIcon, or %NULL
 * @param size place to store an icon size
 *     (#GtkIconSize), or %NULL
 */
- (void)giconWithGicon:(GIcon**)gicon size:(GtkIconSize*)size;

/**
 * Gets the icon name and size being displayed by the #GtkImage.
 * The storage type of the image must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_ICON_NAME (see gtk_image_get_storage_type()).
 * The returned string is owned by the #GtkImage and should not
 * be freed.
 *
 * @param iconName place to store an
 *     icon name, or %NULL
 * @param size place to store an icon size
 *     (#GtkIconSize), or %NULL
 */
- (void)iconNameWithIconName:(const gchar**)iconName size:(GtkIconSize*)size;

/**
 * Gets the icon set and size being displayed by the #GtkImage.
 * The storage type of the image must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_ICON_SET (see gtk_image_get_storage_type()).
 *
 * @param iconSet location to store a
 *     #GtkIconSet, or %NULL
 * @param size location to store a stock
 *     icon size (#GtkIconSize), or %NULL
 */
- (void)iconSetWithIconSet:(GtkIconSet**)iconSet size:(GtkIconSize*)size;

/**
 * Gets the #GdkPixbuf being displayed by the #GtkImage.
 * The storage type of the image must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_PIXBUF (see gtk_image_get_storage_type()).
 * The caller of this function does not own a reference to the
 * returned pixbuf.
 *
 * @return the displayed pixbuf, or %NULL if
 * the image is empty
 */
- (OGGdkPixbuf*)pixbuf;

/**
 * Gets the pixel size used for named icons.
 *
 * @return the pixel size used for named icons.
 */
- (gint)pixelSize;

/**
 * Gets the stock icon name and size being displayed by the #GtkImage.
 * The storage type of the image must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_STOCK (see gtk_image_get_storage_type()).
 * The returned string is owned by the #GtkImage and should not
 * be freed.
 *
 * @param stockId place to store a
 *     stock icon name, or %NULL
 * @param size place to store a stock icon
 *     size (#GtkIconSize), or %NULL
 */
- (void)stockWithStockId:(gchar**)stockId size:(GtkIconSize*)size;

/**
 * Gets the type of representation being used by the #GtkImage
 * to store image data. If the #GtkImage has no image data,
 * the return value will be %GTK_IMAGE_EMPTY.
 *
 * @return image representation being used
 */
- (GtkImageType)storageType;

/**
 * Causes the #GtkImage to display the given animation (or display
 * nothing, if you set the animation to %NULL).
 *
 * @param animation the #GdkPixbufAnimation
 */
- (void)setFromAnimation:(OGGdkPixbufAnimation*)animation;

/**
 * See gtk_image_new_from_file() for details.
 *
 * @param filename a filename or %NULL
 */
- (void)setFromFile:(OFString*)filename;

/**
 * See gtk_image_new_from_gicon() for details.
 *
 * @param icon an icon
 * @param size an icon size (#GtkIconSize)
 */
- (void)setFromGiconWithIcon:(GIcon*)icon size:(GtkIconSize)size;

/**
 * See gtk_image_new_from_icon_name() for details.
 *
 * @param iconName an icon name or %NULL
 * @param size an icon size (#GtkIconSize)
 */
- (void)setFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size;

/**
 * See gtk_image_new_from_icon_set() for details.
 *
 * @param iconSet a #GtkIconSet
 * @param size a stock icon size (#GtkIconSize)
 */
- (void)setFromIconSetWithIconSet:(GtkIconSet*)iconSet size:(GtkIconSize)size;

/**
 * See gtk_image_new_from_pixbuf() for details.
 *
 * @param pixbuf a #GdkPixbuf or %NULL
 */
- (void)setFromPixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * See gtk_image_new_from_resource() for details.
 *
 * @param resourcePath a resource path or %NULL
 */
- (void)setFromResource:(OFString*)resourcePath;

/**
 * See gtk_image_new_from_stock() for details.
 *
 * @param stockId a stock icon name
 * @param size a stock icon size (#GtkIconSize)
 */
- (void)setFromStockWithStockId:(OFString*)stockId size:(GtkIconSize)size;

/**
 * See gtk_image_new_from_surface() for details.
 *
 * @param surface a cairo_surface_t or %NULL
 */
- (void)setFromSurface:(cairo_surface_t*)surface;

/**
 * Sets the pixel size to use for named icons. If the pixel size is set
 * to a value != -1, it is used instead of the icon size set by
 * gtk_image_set_from_icon_name().
 *
 * @param pixelSize the new pixel size
 */
- (void)setPixelSize:(gint)pixelSize;

@end