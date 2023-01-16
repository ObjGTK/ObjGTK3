/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * GtkPopover is a bubble-like context window, primarily meant to
 * provide context-dependent information or options. Popovers are
 * attached to a widget, passed at construction time on gtk_popover_new(),
 * or updated afterwards through gtk_popover_set_relative_to(), by
 * default they will point to the whole widget area, although this
 * behavior can be changed through gtk_popover_set_pointing_to().
 * 
 * The position of a popover relative to the widget it is attached to
 * can also be changed through gtk_popover_set_position().
 * 
 * By default, #GtkPopover performs a GTK+ grab, in order to ensure
 * input events get redirected to it while it is shown, and also so
 * the popover is dismissed in the expected situations (clicks outside
 * the popover, or the Esc key being pressed). If no such modal behavior
 * is desired on a popover, gtk_popover_set_modal() may be called on it
 * to tweak its behavior.
 * 
 * ## GtkPopover as menu replacement
 * 
 * GtkPopover is often used to replace menus. To facilitate this, it
 * supports being populated from a #GMenuModel, using
 * gtk_popover_new_from_model(). In addition to all the regular menu
 * model features, this function supports rendering sections in the
 * model in a more compact form, as a row of icon buttons instead of
 * menu items.
 * 
 * To use this rendering, set the ”display-hint” attribute of the
 * section to ”horizontal-buttons” and set the icons of your items
 * with the ”verb-icon” attribute.
 * 
 * |[
 * <section>
 *   <attribute name="display-hint">horizontal-buttons</attribute>
 *   <item>
 *     <attribute name="label">Cut</attribute>
 *     <attribute name="action">app.cut</attribute>
 *     <attribute name="verb-icon">edit-cut-symbolic</attribute>
 *   </item>
 *   <item>
 *     <attribute name="label">Copy</attribute>
 *     <attribute name="action">app.copy</attribute>
 *     <attribute name="verb-icon">edit-copy-symbolic</attribute>
 *   </item>
 *   <item>
 *     <attribute name="label">Paste</attribute>
 *     <attribute name="action">app.paste</attribute>
 *     <attribute name="verb-icon">edit-paste-symbolic</attribute>
 *   </item>
 * </section>
 * ]|
 * 
 * # CSS nodes
 * 
 * GtkPopover has a single css node called popover. It always gets the
 * .background style class and it gets the .menu style class if it is
 * menu-like (e.g. #GtkPopoverMenu or created using gtk_popover_new_from_model().
 * 
 * Particular uses of GtkPopover, such as touch selection popups
 * or magnifiers in #GtkEntry or #GtkTextView get style classes
 * like .touch-selection or .magnifier to differentiate from
 * plain popovers.
 *
 */
@interface OGTKPopover : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)relativeTo;
- (instancetype)initFromModelWithRelativeTo:(OGTKWidget*)relativeTo model:(GMenuModel*)model;

/**
 * Methods
 */

- (GtkPopover*)POPOVER;

/**
 * Establishes a binding between a #GtkPopover and a #GMenuModel.
 * 
 * The contents of @popover are removed and then refilled with menu items
 * according to @model.  When @model changes, @popover is updated.
 * Calling this function twice on @popover with different @model will
 * cause the first binding to be replaced with a binding to the new
 * model. If @model is %NULL then any previous binding is undone and
 * all children are removed.
 * 
 * If @action_namespace is non-%NULL then the effect is as if all
 * actions mentioned in the @model have their names prefixed with the
 * namespace, plus a dot.  For example, if the action “quit” is
 * mentioned and @action_namespace is “app” then the effective action
 * name is “app.quit”.
 * 
 * This function uses #GtkActionable to define the action name and
 * target values on the created menu items.  If you want to use an
 * action group other than “app” and “win”, or if you want to use a
 * #GtkMenuShell outside of a #GtkApplicationWindow, then you will need
 * to attach your own action group to the widget hierarchy using
 * gtk_widget_insert_action_group().  As an example, if you created a
 * group with a “quit” action and inserted it with the name “mygroup”
 * then you would use the action name “mygroup.quit” in your
 * #GMenuModel.
 *
 * @param model the #GMenuModel to bind to or %NULL to remove
 *   binding
 * @param actionNamespace the namespace for actions in @model
 */
- (void)bindModelWithModel:(GMenuModel*)model actionNamespace:(OFString*)actionNamespace;

/**
 * Returns the constraint for placing this popover.
 * See gtk_popover_set_constrain_to().
 *
 * @return the constraint for placing this popover.
 */
- (GtkPopoverConstraint)constrainTo;

/**
 * Gets the widget that should be set as the default while
 * the popover is shown.
 *
 * @return the default widget,
 * or %NULL if there is none
 */
- (OGTKWidget*)defaultWidget;

/**
 * Returns whether the popover is modal, see gtk_popover_set_modal to
 * see the implications of this.
 *
 * @return #TRUE if @popover is modal
 */
- (bool)modal;

/**
 * If a rectangle to point to has been set, this function will
 * return %TRUE and fill in @rect with such rectangle, otherwise
 * it will return %FALSE and fill in @rect with the attached
 * widget coordinates.
 *
 * @param rect location to store the rectangle
 * @return %TRUE if a rectangle to point to was set.
 */
- (bool)pointingTo:(GdkRectangle*)rect;

/**
 * Returns the preferred position of @popover.
 *
 * @return The preferred position.
 */
- (GtkPositionType)position;

/**
 * Returns the widget @popover is currently attached to
 *
 * @return a #GtkWidget
 */
- (OGTKWidget*)relativeTo;

/**
 * Returns whether show/hide transitions are enabled on this popover.
 *
 * @return #TRUE if the show and hide transitions of the given
 *          popover are enabled, #FALSE otherwise.
 */
- (bool)transitionsEnabled;

/**
 * Pops @popover down.This is different than a gtk_widget_hide() call
 * in that it shows the popover with a transition. If you want to hide
 * the popover without a transition, use gtk_widget_hide().
 *
 */
- (void)popdown;

/**
 * Pops @popover up. This is different than a gtk_widget_show() call
 * in that it shows the popover with a transition. If you want to show
 * the popover without a transition, use gtk_widget_show().
 *
 */
- (void)popup;

/**
 * Sets a constraint for positioning this popover.
 * 
 * Note that not all platforms support placing popovers freely,
 * and may already impose constraints.
 *
 * @param constraint the new constraint
 */
- (void)setConstrainTo:(GtkPopoverConstraint)constraint;

/**
 * Sets the widget that should be set as default widget while
 * the popover is shown (see gtk_window_set_default()). #GtkPopover
 * remembers the previous default widget and reestablishes it
 * when the popover is dismissed.
 *
 * @param widget the new default widget, or %NULL
 */
- (void)setDefaultWidget:(OGTKWidget*)widget;

/**
 * Sets whether @popover is modal, a modal popover will grab all input
 * within the toplevel and grab the keyboard focus on it when being
 * displayed. Clicking outside the popover area or pressing Esc will
 * dismiss the popover and ungrab input.
 *
 * @param modal #TRUE to make popover claim all input within the toplevel
 */
- (void)setModal:(bool)modal;

/**
 * Sets the rectangle that @popover will point to, in the
 * coordinate space of the widget @popover is attached to,
 * see gtk_popover_set_relative_to().
 *
 * @param rect rectangle to point to
 */
- (void)setPointingTo:(const GdkRectangle*)rect;

/**
 * Sets the preferred position for @popover to appear. If the @popover
 * is currently visible, it will be immediately updated.
 * 
 * This preference will be respected where possible, although
 * on lack of space (eg. if close to the window edges), the
 * #GtkPopover may choose to appear on the opposite side
 *
 * @param position preferred popover position
 */
- (void)setPosition:(GtkPositionType)position;

/**
 * Sets a new widget to be attached to @popover. If @popover is
 * visible, the position will be updated.
 * 
 * Note: the ownership of popovers is always given to their @relative_to
 * widget, so if @relative_to is set to %NULL on an attached @popover, it
 * will be detached from its previous widget, and consequently destroyed
 * unless extra references are kept.
 *
 * @param relativeTo a #GtkWidget
 */
- (void)setRelativeTo:(OGTKWidget*)relativeTo;

/**
 * Sets whether show/hide transitions are enabled on this popover
 *
 * @param transitionsEnabled Whether transitions are enabled
 */
- (void)setTransitionsEnabled:(bool)transitionsEnabled;

@end