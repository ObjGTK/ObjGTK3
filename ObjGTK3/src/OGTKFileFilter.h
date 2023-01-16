/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

/**
 * A GtkFileFilter can be used to restrict the files being shown in a
 * #GtkFileChooser. Files can be filtered based on their name (with
 * gtk_file_filter_add_pattern()), on their mime type (with
 * gtk_file_filter_add_mime_type()), or by a custom filter function
 * (with gtk_file_filter_add_custom()).
 * 
 * Filtering by mime types handles aliasing and subclassing of mime
 * types; e.g. a filter for text/plain also matches a file with mime
 * type application/rtf, since application/rtf is a subclass of
 * text/plain. Note that #GtkFileFilter allows wildcards for the
 * subtype of a mime type, so you can e.g. filter for image/\*.
 * 
 * Normally, filters are used by adding them to a #GtkFileChooser,
 * see gtk_file_chooser_add_filter(), but it is also possible
 * to manually use a filter on a file with gtk_file_filter_filter().
 * 
 * # GtkFileFilter as GtkBuildable
 * 
 * The GtkFileFilter implementation of the GtkBuildable interface
 * supports adding rules using the <mime-types>, <patterns> and
 * <applications> elements and listing the rules within. Specifying
 * a <mime-type> or <pattern> has the same effect as as calling
 * gtk_file_filter_add_mime_type() or gtk_file_filter_add_pattern().
 * 
 * An example of a UI definition fragment specifying GtkFileFilter
 * rules:
 * |[
 * <object class="GtkFileFilter">
 *   <mime-types>
 *     <mime-type>text/plain</mime-type>
 *     <mime-type>image/ *</mime-type>
 *   </mime-types>
 *   <patterns>
 *     <pattern>*.txt</pattern>
 *     <pattern>*.png</pattern>
 *   </patterns>
 * </object>
 * ]|
 *
 */
@interface OGTKFileFilter : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromGvariant:(GVariant*)variant;

/**
 * Methods
 */

- (GtkFileFilter*)FILEFILTER;

/**
 * Adds rule to a filter that allows files based on a custom callback
 * function. The bitfield @needed which is passed in provides information
 * about what sorts of information that the filter function needs;
 * this allows GTK+ to avoid retrieving expensive information when
 * it isn’t needed by the filter.
 *
 * @param needed bitfield of flags indicating the information that the custom
 *          filter function needs.
 * @param func callback function; if the function returns %TRUE, then
 *   the file will be displayed.
 * @param data data to pass to @func
 * @param notify function to call to free @data when it is no longer needed.
 */
- (void)addCustomWithNeeded:(GtkFileFilterFlags)needed func:(GtkFileFilterFunc)func data:(gpointer)data notify:(GDestroyNotify)notify;

/**
 * Adds a rule allowing a given mime type to @filter.
 *
 * @param mimeType name of a MIME type
 */
- (void)addMimeType:(OFString*)mimeType;

/**
 * Adds a rule allowing a shell style glob to a filter.
 *
 * @param pattern a shell style glob
 */
- (void)addPattern:(OFString*)pattern;

/**
 * Adds a rule allowing image files in the formats supported
 * by GdkPixbuf.
 *
 */
- (void)addPixbufFormats;

/**
 * Tests whether a file should be displayed according to @filter.
 * The #GtkFileFilterInfo @filter_info should include
 * the fields returned from gtk_file_filter_get_needed().
 * 
 * This function will not typically be used by applications; it
 * is intended principally for use in the implementation of
 * #GtkFileChooser.
 *
 * @param filterInfo a #GtkFileFilterInfo containing information
 *  about a file.
 * @return %TRUE if the file should be displayed
 */
- (bool)filter:(const GtkFileFilterInfo*)filterInfo;

/**
 * Gets the human-readable name for the filter. See gtk_file_filter_set_name().
 *
 * @return The human-readable name of the filter,
 *   or %NULL. This value is owned by GTK+ and must not
 *   be modified or freed.
 */
- (OFString*)name;

/**
 * Gets the fields that need to be filled in for the #GtkFileFilterInfo
 * passed to gtk_file_filter_filter()
 * 
 * This function will not typically be used by applications; it
 * is intended principally for use in the implementation of
 * #GtkFileChooser.
 *
 * @return bitfield of flags indicating needed fields when
 *   calling gtk_file_filter_filter()
 */
- (GtkFileFilterFlags)needed;

/**
 * Sets the human-readable name of the filter; this is the string
 * that will be displayed in the file selector user interface if
 * there is a selectable list of filters.
 *
 * @param name the human-readable-name for the filter, or %NULL
 *   to remove any existing name.
 */
- (void)setName:(OFString*)name;

/**
 * Serialize a file filter to an a{sv} variant.
 *
 * @return a new, floating, #GVariant
 */
- (GVariant*)toGvariant;

@end