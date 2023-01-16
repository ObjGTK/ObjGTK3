/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGAtk/OGAtkObject.h>

@class OGTKWidget;

/**
 * The #GtkAccessible class is the base class for accessible
 * implementations for #GtkWidget subclasses. It is a thin
 * wrapper around #AtkObject, which adds facilities for associating
 * a widget with its accessible object.
 * 
 * An accessible implementation for a third-party widget should
 * derive from #GtkAccessible and implement the suitable interfaces
 * from ATK, such as #AtkText or #AtkSelection. To establish
 * the connection between the widget class and its corresponding
 * acccessible implementation, override the get_accessible vfunc
 * in #GtkWidgetClass.
 *
 */
@interface OGTKAccessible : OGAtkObject
{

}


/**
 * Methods
 */

- (GtkAccessible*)ACCESSIBLE;

/**
 * This function specifies the callback function to be called
 * when the widget corresponding to a GtkAccessible is destroyed.
 *
 */
- (void)connectWidgetDestroyed;

/**
 * Gets the #GtkWidget corresponding to the #GtkAccessible.
 * The returned widget does not have a reference added, so
 * you do not need to unref it.
 *
 * @return pointer to the #GtkWidget
 *     corresponding to the #GtkAccessible, or %NULL.
 */
- (OGTKWidget*)widget;

/**
 * Sets the #GtkWidget corresponding to the #GtkAccessible.
 * 
 * @accessible will not hold a reference to @widget.
 * It is the caller’s responsibility to ensure that when @widget
 * is destroyed, the widget is unset by calling this function
 * again with @widget set to %NULL.
 *
 * @param widget a #GtkWidget or %NULL to unset
 */
- (void)setWidget:(OGTKWidget*)widget;

@end