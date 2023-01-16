/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGGdkPixbuf;
@class OGGdkDisplay;
@class OGTKWidget;

/**
 * Basic tooltips can be realized simply by using gtk_widget_set_tooltip_text()
 * or gtk_widget_set_tooltip_markup() without any explicit tooltip object.
 * 
 * When you need a tooltip with a little more fancy contents, like adding an
 * image, or you want the tooltip to have different contents per #GtkTreeView
 * row or cell, you will have to do a little more work:
 * 
 * - Set the #GtkWidget:has-tooltip property to %TRUE, this will make GTK+
 *   monitor the widget for motion and related events which are needed to
 *   determine when and where to show a tooltip.
 * 
 * - Connect to the #GtkWidget::query-tooltip signal.  This signal will be
 *   emitted when a tooltip is supposed to be shown. One of the arguments passed
 *   to the signal handler is a GtkTooltip object. This is the object that we
 *   are about to display as a tooltip, and can be manipulated in your callback
 *   using functions like gtk_tooltip_set_icon(). There are functions for setting
 *   the tooltip’s markup, setting an image from a named icon, or even putting in
 *   a custom widget.
 * 
 *   Return %TRUE from your query-tooltip handler. This causes the tooltip to be
 *   show. If you return %FALSE, it will not be shown.
 * 
 * In the probably rare case where you want to have even more control over the
 * tooltip that is about to be shown, you can set your own #GtkWindow which
 * will be used as tooltip window.  This works as follows:
 * 
 * - Set #GtkWidget:has-tooltip and connect to #GtkWidget::query-tooltip as before.
 *   Use gtk_widget_set_tooltip_window() to set a #GtkWindow created by you as
 *   tooltip window.
 * 
 * - In the #GtkWidget::query-tooltip callback you can access your window using
 *   gtk_widget_get_tooltip_window() and manipulate as you wish. The semantics of
 *   the return value are exactly as before, return %TRUE to show the window,
 *   %FALSE to not show it.
 *
 */
@interface OGTKTooltip : OGObject
{

}

/**
 * Functions
 */
+ (void)triggerTooltipQuery:(OGGdkDisplay*)display;

/**
 * Methods
 */

- (GtkTooltip*)TOOLTIP;

/**
 * Replaces the widget packed into the tooltip with
 * @custom_widget. @custom_widget does not get destroyed when the tooltip goes
 * away.
 * By default a box with a #GtkImage and #GtkLabel is embedded in
 * the tooltip, which can be configured using gtk_tooltip_set_markup()
 * and gtk_tooltip_set_icon().
 *
 * @param customWidget a #GtkWidget, or %NULL to unset the old custom widget.
 */
- (void)setCustom:(OGTKWidget*)customWidget;

/**
 * Sets the icon of the tooltip (which is in front of the text) to be
 * @pixbuf.  If @pixbuf is %NULL, the image will be hidden.
 *
 * @param pixbuf a #GdkPixbuf, or %NULL
 */
- (void)setIcon:(OGGdkPixbuf*)pixbuf;

/**
 * Sets the icon of the tooltip (which is in front of the text)
 * to be the icon indicated by @gicon with the size indicated
 * by @size. If @gicon is %NULL, the image will be hidden.
 *
 * @param gicon a #GIcon representing the icon, or %NULL
 * @param size a stock icon size (#GtkIconSize)
 */
- (void)setIconFromGiconWithGicon:(GIcon*)gicon size:(GtkIconSize)size;

/**
 * Sets the icon of the tooltip (which is in front of the text) to be
 * the icon indicated by @icon_name with the size indicated
 * by @size.  If @icon_name is %NULL, the image will be hidden.
 *
 * @param iconName an icon name, or %NULL
 * @param size a stock icon size (#GtkIconSize)
 */
- (void)setIconFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size;

/**
 * Sets the icon of the tooltip (which is in front of the text) to be
 * the stock item indicated by @stock_id with the size indicated
 * by @size.  If @stock_id is %NULL, the image will be hidden.
 *
 * @param stockId a stock id, or %NULL
 * @param size a stock icon size (#GtkIconSize)
 */
- (void)setIconFromStockWithStockId:(OFString*)stockId size:(GtkIconSize)size;

/**
 * Sets the text of the tooltip to be @markup, which is marked up
 * with the [Pango text markup language][PangoMarkupFormat].
 * If @markup is %NULL, the label will be hidden.
 *
 * @param markup a markup string (see [Pango markup format][PangoMarkupFormat]) or %NULL
 */
- (void)setMarkup:(OFString*)markup;

/**
 * Sets the text of the tooltip to be @text. If @text is %NULL, the label
 * will be hidden. See also gtk_tooltip_set_markup().
 *
 * @param text a text string or %NULL
 */
- (void)setText:(OFString*)text;

/**
 * Sets the area of the widget, where the contents of this tooltip apply,
 * to be @rect (in widget coordinates).  This is especially useful for
 * properly setting tooltips on #GtkTreeView rows and cells, #GtkIconViews,
 * etc.
 * 
 * For setting tooltips on #GtkTreeView, please refer to the convenience
 * functions for this: gtk_tree_view_set_tooltip_row() and
 * gtk_tree_view_set_tooltip_cell().
 *
 * @param rect a #GdkRectangle
 */
- (void)setTipArea:(const GdkRectangle*)rect;

@end