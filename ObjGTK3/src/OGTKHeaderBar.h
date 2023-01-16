/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;

/**
 * GtkHeaderBar is similar to a horizontal #GtkBox. It allows children to
 * be placed at the start or the end. In addition, it allows a title and
 * subtitle to be displayed. The title will be centered with respect to
 * the width of the box, even if the children at either side take up
 * different amounts of space. The height of the titlebar will be
 * set to provide sufficient space for the subtitle, even if none is
 * currently set. If a subtitle is not needed, the space reservation
 * can be turned off with gtk_header_bar_set_has_subtitle().
 * 
 * GtkHeaderBar can add typical window frame controls, such as minimize,
 * maximize and close buttons, or the window icon.
 * 
 * For these reasons, GtkHeaderBar is the natural choice for use as the custom
 * titlebar widget of a #GtkWindow (see gtk_window_set_titlebar()), as it gives
 * features typical of titlebars while allowing the addition of child widgets.
 *
 */
@interface OGTKHeaderBar : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkHeaderBar*)HEADERBAR;

/**
 * Retrieves the custom title widget of the header. See
 * gtk_header_bar_set_custom_title().
 *
 * @return the custom title widget
 *    of the header, or %NULL if none has been set explicitly.
 */
- (OGTKWidget*)customTitle;

/**
 * Gets the decoration layout set with
 * gtk_header_bar_set_decoration_layout().
 *
 * @return the decoration layout
 */
- (OFString*)decorationLayout;

/**
 * Retrieves whether the header bar reserves space for
 * a subtitle, regardless if one is currently set or not.
 *
 * @return %TRUE if the header bar reserves space
 *     for a subtitle
 */
- (bool)hasSubtitle;

/**
 * Returns whether this header bar shows the standard window
 * decorations.
 *
 * @return %TRUE if the decorations are shown
 */
- (bool)showCloseButton;

/**
 * Retrieves the subtitle of the header. See gtk_header_bar_set_subtitle().
 *
 * @return the subtitle of the header, or %NULL if none has
 *    been set explicitly. The returned string is owned by the widget
 *    and must not be modified or freed.
 */
- (OFString*)subtitle;

/**
 * Retrieves the title of the header. See gtk_header_bar_set_title().
 *
 * @return the title of the header, or %NULL if none has
 *    been set explicitly. The returned string is owned by the widget
 *    and must not be modified or freed.
 */
- (OFString*)title;

/**
 * Adds @child to @bar, packed with reference to the
 * end of the @bar.
 *
 * @param child the #GtkWidget to be added to @bar
 */
- (void)packEnd:(OGTKWidget*)child;

/**
 * Adds @child to @bar, packed with reference to the
 * start of the @bar.
 *
 * @param child the #GtkWidget to be added to @bar
 */
- (void)packStart:(OGTKWidget*)child;

/**
 * Sets a custom title for the #GtkHeaderBar.
 * 
 * The title should help a user identify the current view. This
 * supersedes any title set by gtk_header_bar_set_title() or
 * gtk_header_bar_set_subtitle(). To achieve the same style as
 * the builtin title and subtitle, use the “title” and “subtitle”
 * style classes.
 * 
 * You should set the custom title to %NULL, for the header title
 * label to be visible again.
 *
 * @param titleWidget a custom widget to use for a title
 */
- (void)setCustomTitle:(OGTKWidget*)titleWidget;

/**
 * Sets the decoration layout for this header bar, overriding
 * the #GtkSettings:gtk-decoration-layout setting.
 * 
 * There can be valid reasons for overriding the setting, such
 * as a header bar design that does not allow for buttons to take
 * room on the right, or only offers room for a single close button.
 * Split header bars are another example for overriding the
 * setting.
 * 
 * The format of the string is button names, separated by commas.
 * A colon separates the buttons that should appear on the left
 * from those on the right. Recognized button names are minimize,
 * maximize, close, icon (the window icon) and menu (a menu button
 * for the fallback app menu).
 * 
 * For example, “menu:minimize,maximize,close” specifies a menu
 * on the left, and minimize, maximize and close buttons on the right.
 *
 * @param layout a decoration layout, or %NULL to
 *     unset the layout
 */
- (void)setDecorationLayout:(OFString*)layout;

/**
 * Sets whether the header bar should reserve space
 * for a subtitle, even if none is currently set.
 *
 * @param setting %TRUE to reserve space for a subtitle
 */
- (void)setHasSubtitle:(bool)setting;

/**
 * Sets whether this header bar shows the standard window decorations,
 * including close, maximize, and minimize.
 *
 * @param setting %TRUE to show standard window decorations
 */
- (void)setShowCloseButton:(bool)setting;

/**
 * Sets the subtitle of the #GtkHeaderBar. The title should give a user
 * an additional detail to help him identify the current view.
 * 
 * Note that GtkHeaderBar by default reserves room for the subtitle,
 * even if none is currently set. If this is not desired, set the
 * #GtkHeaderBar:has-subtitle property to %FALSE.
 *
 * @param subtitle a subtitle, or %NULL
 */
- (void)setSubtitle:(OFString*)subtitle;

/**
 * Sets the title of the #GtkHeaderBar. The title should help a user
 * identify the current view. A good title should not include the
 * application name.
 *
 * @param title a title, or %NULL
 */
- (void)setTitle:(OFString*)title;

@end