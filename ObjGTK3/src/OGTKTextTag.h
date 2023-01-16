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
 * You may wish to begin by reading the
 * [text widget conceptual overview][TextWidget]
 * which gives an overview of all the objects and
 * data types related to the text widget and how they work together.
 * 
 * Tags should be in the #GtkTextTagTable for a given #GtkTextBuffer
 * before using them with that buffer.
 * 
 * gtk_text_buffer_create_tag() is the best way to create tags.
 * See “gtk3-demo” for numerous examples.
 * 
 * For each property of #GtkTextTag, there is a “set” property, e.g.
 * “font-set” corresponds to “font”. These “set” properties reflect
 * whether a property has been set or not.
 * They are maintained by GTK+ and you should not set them independently.
 *
 */
@interface OGTKTextTag : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)name;

/**
 * Methods
 */

- (GtkTextTag*)TEXTTAG;

/**
 * Emits the #GtkTextTagTable::tag-changed signal on the #GtkTextTagTable where
 * the tag is included.
 * 
 * The signal is already emitted when setting a #GtkTextTag property. This
 * function is useful for a #GtkTextTag subclass.
 *
 * @param sizeChanged whether the change affects the #GtkTextView layout.
 */
- (void)changed:(bool)sizeChanged;

/**
 * Emits the “event” signal on the #GtkTextTag.
 *
 * @param eventObject object that received the event, such as a widget
 * @param event the event
 * @param iter location where the event was received
 * @return result of signal emission (whether the event was handled)
 */
- (bool)eventWithEventObject:(GObject*)eventObject event:(GdkEvent*)event iter:(const GtkTextIter*)iter;

/**
 * Get the tag priority.
 *
 * @return The tag’s priority.
 */
- (gint)priority;

/**
 * Sets the priority of a #GtkTextTag. Valid priorities
 * start at 0 and go to one less than gtk_text_tag_table_get_size().
 * Each tag in a table has a unique priority; setting the priority
 * of one tag shifts the priorities of all the other tags in the
 * table to maintain a unique priority for each tag. Higher priority
 * tags “win” if two tags both set the same text attribute. When adding
 * a tag to a tag table, it will be assigned the highest priority in
 * the table by default; so normally the precedence of a set of tags
 * is the order in which they were added to the table, or created with
 * gtk_text_buffer_create_tag(), which adds the tag to the buffer’s table
 * automatically.
 *
 * @param priority the new priority
 */
- (void)setPriority:(gint)priority;

@end