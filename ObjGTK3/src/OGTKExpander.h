/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * A #GtkExpander allows the user to hide or show its child by clicking
 * on an expander triangle similar to the triangles used in a #GtkTreeView.
 * 
 * Normally you use an expander as you would use any other descendant
 * of #GtkBin; you create the child widget and use gtk_container_add()
 * to add it to the expander. When the expander is toggled, it will take
 * care of showing and hiding the child automatically.
 * 
 * # Special Usage
 * 
 * There are situations in which you may prefer to show and hide the
 * expanded widget yourself, such as when you want to actually create
 * the widget at expansion time. In this case, create a #GtkExpander
 * but do not add a child to it. The expander widget has an
 * #GtkExpander:expanded property which can be used to monitor
 * its expansion state. You should watch this property with a signal
 * connection as follows:
 * 
 * |[<!-- language="C" -->
 * static void
 * expander_callback (GObject    *object,
 *                    GParamSpec *param_spec,
 *                    gpointer    user_data)
 * {
 *   GtkExpander *expander;
 * 
 *   expander = GTK_EXPANDER (object);
 * 
 *   if (gtk_expander_get_expanded (expander))
 *     {
 *       // Show or create widgets
 *     }
 *   else
 *     {
 *       // Hide or destroy widgets
 *     }
 * }
 * 
 * static void
 * create_expander (void)
 * {
 *   GtkWidget *expander = gtk_expander_new_with_mnemonic ("_More Options");
 *   g_signal_connect (expander, "notify::expanded",
 *                     G_CALLBACK (expander_callback), NULL);
 * 
 *   // ...
 * }
 * ]|
 * 
 * # GtkExpander as GtkBuildable
 * 
 * The GtkExpander implementation of the GtkBuildable interface supports
 * placing a child in the label position by specifying “label” as the
 * “type” attribute of a `<child>` element. A normal content child can be
 * specified without specifying a `<child>` type attribute.
 * 
 * An example of a UI definition fragment with GtkExpander:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkExpander">
 *   <child type="label">
 *     <object class="GtkLabel" id="expander-label"/>
 *   </child>
 *   <child>
 *     <object class="GtkEntry" id="expander-content"/>
 *   </child>
 * </object>
 * ]|
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * expander
 * ├── title
 * │   ├── arrow
 * │   ╰── <label widget>
 * ╰── <child>
 * ]|
 * 
 * GtkExpander has three CSS nodes, the main node with the name expander,
 * a subnode with name title and node below it with name arrow. The arrow of an
 * expander that is showing its child gets the :checked pseudoclass added to it.
 *
 */
@interface OGTKExpander : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)label;
- (instancetype)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkExpander*)EXPANDER;

/**
 * Queries a #GtkExpander and returns its current state. Returns %TRUE
 * if the child widget is revealed.
 * 
 * See gtk_expander_set_expanded().
 *
 * @return the current state of the expander
 */
- (bool)expanded;

/**
 * Fetches the text from a label widget including any embedded
 * underlines indicating mnemonics and Pango markup, as set by
 * gtk_expander_set_label(). If the label text has not been set the
 * return value will be %NULL. This will be the case if you create an
 * empty button with gtk_button_new() to use as a container.
 * 
 * Note that this function behaved differently in versions prior to
 * 2.14 and used to return the label text stripped of embedded
 * underlines indicating mnemonics and Pango markup. This problem can
 * be avoided by fetching the label text directly from the label
 * widget.
 *
 * @return The text of the label widget. This string is owned
 *     by the widget and must not be modified or freed.
 */
- (OFString*)label;

/**
 * Returns whether the label widget will fill all available
 * horizontal space allocated to @expander.
 *
 * @return %TRUE if the label widget will fill all
 *     available horizontal space
 */
- (bool)labelFill;

/**
 * Retrieves the label widget for the frame. See
 * gtk_expander_set_label_widget().
 *
 * @return the label widget,
 *     or %NULL if there is none
 */
- (OGTKWidget*)labelWidget;

/**
 * Returns whether the expander will resize the toplevel widget
 * containing the expander upon resizing and collpasing.
 *
 * @return the “resize toplevel” setting.
 */
- (bool)resizeToplevel;

/**
 * Gets the value set by gtk_expander_set_spacing().
 *
 * @return spacing between the expander and child
 */
- (gint)spacing;

/**
 * Returns whether the label’s text is interpreted as marked up with
 * the [Pango text markup language][PangoMarkupFormat].
 * See gtk_expander_set_use_markup().
 *
 * @return %TRUE if the label’s text will be parsed for markup
 */
- (bool)useMarkup;

/**
 * Returns whether an embedded underline in the expander label
 * indicates a mnemonic. See gtk_expander_set_use_underline().
 *
 * @return %TRUE if an embedded underline in the expander
 *     label indicates the mnemonic accelerator keys
 */
- (bool)useUnderline;

/**
 * Sets the state of the expander. Set to %TRUE, if you want
 * the child widget to be revealed, and %FALSE if you want the
 * child widget to be hidden.
 *
 * @param expanded whether the child widget is revealed
 */
- (void)setExpanded:(bool)expanded;

/**
 * Sets the text of the label of the expander to @label.
 * 
 * This will also clear any previously set labels.
 *
 * @param label a string
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets whether the label widget should fill all available
 * horizontal space allocated to @expander.
 * 
 * Note that this function has no effect since 3.20.
 *
 * @param labelFill %TRUE if the label should should fill
 *     all available horizontal space
 */
- (void)setLabelFill:(bool)labelFill;

/**
 * Set the label widget for the expander. This is the widget
 * that will appear embedded alongside the expander arrow.
 *
 * @param labelWidget the new label widget
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

/**
 * Sets whether the expander will resize the toplevel widget
 * containing the expander upon resizing and collpasing.
 *
 * @param resizeToplevel whether to resize the toplevel
 */
- (void)setResizeToplevel:(bool)resizeToplevel;

/**
 * Sets the spacing field of @expander, which is the number of
 * pixels to place between expander and the child.
 *
 * @param spacing distance between the expander and child in pixels
 */
- (void)setSpacing:(gint)spacing;

/**
 * Sets whether the text of the label contains markup in
 * [Pango’s text markup language][PangoMarkupFormat].
 * See gtk_label_set_markup().
 *
 * @param useMarkup %TRUE if the label’s text should be parsed for markup
 */
- (void)setUseMarkup:(bool)useMarkup;

/**
 * If true, an underline in the text of the expander label indicates
 * the next character should be used for the mnemonic accelerator key.
 *
 * @param useUnderline %TRUE if underlines in the text indicate mnemonics
 */
- (void)setUseUnderline:(bool)useUnderline;

@end