/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

/**
 * A #GtkRecentFilter can be used to restrict the files being shown
 * in a #GtkRecentChooser.  Files can be filtered based on their name
 * (with gtk_recent_filter_add_pattern()), on their mime type (with
 * gtk_file_filter_add_mime_type()), on the application that has
 * registered them (with gtk_recent_filter_add_application()), or by
 * a custom filter function (with gtk_recent_filter_add_custom()).
 * 
 * Filtering by mime type handles aliasing and subclassing of mime
 * types; e.g. a filter for text/plain also matches a file with mime
 * type application/rtf, since application/rtf is a subclass of text/plain.
 * Note that #GtkRecentFilter allows wildcards for the subtype of a
 * mime type, so you can e.g. filter for image/\*.
 * 
 * Normally, filters are used by adding them to a #GtkRecentChooser,
 * see gtk_recent_chooser_add_filter(), but it is also possible to
 * manually use a filter on a file with gtk_recent_filter_filter().
 * 
 * Recently used files are supported since GTK+ 2.10.
 * 
 * ## GtkRecentFilter as GtkBuildable
 * 
 * The GtkRecentFilter implementation of the GtkBuildable interface
 * supports adding rules using the `<mime-types>`, `<patterns>` and
 * `<applications>` elements and listing the rules within. Specifying
 * a `<mime-type>`, `<pattern>` or `<application>` has the same effect as
 * calling gtk_recent_filter_add_mime_type(),
 * gtk_recent_filter_add_pattern() or gtk_recent_filter_add_application().
 * 
 * An example of a UI definition fragment specifying `GtkRecentFilter`
 * rules:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkRecentFilter">
 *   <mime-types>
 *     <mime-type>text/plain</mime-type>
 *     <mime-type>image/png</mime-type>
 *   </mime-types>
 *   <patterns>
 *     <pattern>*.txt</pattern>
 *     <pattern>*.png</pattern>
 *   </patterns>
 *   <applications>
 *     <application>gimp</application>
 *     <application>gedit</application>
 *     <application>glade</application>
 *   </applications>
 * </object>
 * ]|
 *
 */
@interface OGTKRecentFilter : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkRecentFilter*)RECENTFILTER;

/**
 * Adds a rule that allows resources based on their age - that is, the number
 * of days elapsed since they were last modified.
 *
 * @param days number of days
 */
- (void)addAge:(gint)days;

/**
 * Adds a rule that allows resources based on the name of the application
 * that has registered them.
 *
 * @param application an application name
 */
- (void)addApplication:(OFString*)application;

/**
 * Adds a rule to a filter that allows resources based on a custom callback
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
 * @param dataDestroy function to call to free @data when it is no longer needed.
 */
- (void)addCustomWithNeeded:(GtkRecentFilterFlags)needed func:(GtkRecentFilterFunc)func data:(gpointer)data dataDestroy:(GDestroyNotify)dataDestroy;

/**
 * Adds a rule that allows resources based on the name of the group
 * to which they belong
 *
 * @param group a group name
 */
- (void)addGroup:(OFString*)group;

/**
 * Adds a rule that allows resources based on their registered MIME type.
 *
 * @param mimeType a MIME type
 */
- (void)addMimeType:(OFString*)mimeType;

/**
 * Adds a rule that allows resources based on a pattern matching their
 * display name.
 *
 * @param pattern a file pattern
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
 * The #GtkRecentFilterInfo @filter_info should include
 * the fields returned from gtk_recent_filter_get_needed(), and
 * must set the #GtkRecentFilterInfo.contains field of @filter_info
 * to indicate which fields have been set.
 * 
 * This function will not typically be used by applications; it
 * is intended principally for use in the implementation of
 * #GtkRecentChooser.
 *
 * @param filterInfo a #GtkRecentFilterInfo containing information
 *   about a recently used resource
 * @return %TRUE if the file should be displayed
 */
- (bool)filter:(const GtkRecentFilterInfo*)filterInfo;

/**
 * Gets the human-readable name for the filter.
 * See gtk_recent_filter_set_name().
 *
 * @return the name of the filter, or %NULL.  The returned string
 *   is owned by the filter object and should not be freed.
 */
- (OFString*)name;

/**
 * Gets the fields that need to be filled in for the #GtkRecentFilterInfo
 * passed to gtk_recent_filter_filter()
 * 
 * This function will not typically be used by applications; it
 * is intended principally for use in the implementation of
 * #GtkRecentChooser.
 *
 * @return bitfield of flags indicating needed fields when
 *   calling gtk_recent_filter_filter()
 */
- (GtkRecentFilterFlags)needed;

/**
 * Sets the human-readable name of the filter; this is the string
 * that will be displayed in the recently used resources selector
 * user interface if there is a selectable list of filters.
 *
 * @param name then human readable name of @filter
 */
- (void)setName:(OFString*)name;

@end