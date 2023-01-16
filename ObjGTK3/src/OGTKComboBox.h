/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGGdkDevice;
@class OGTKWidget;
@class OGAtkObject;
@class OGTKCellArea;

/**
 * A GtkComboBox is a widget that allows the user to choose from a list of
 * valid choices. The GtkComboBox displays the selected choice. When
 * activated, the GtkComboBox displays a popup which allows the user to
 * make a new choice. The style in which the selected value is displayed,
 * and the style of the popup is determined by the current theme. It may
 * be similar to a Windows-style combo box.
 * 
 * The GtkComboBox uses the model-view pattern; the list of valid choices
 * is specified in the form of a tree model, and the display of the choices
 * can be adapted to the data in the model by using cell renderers, as you
 * would in a tree view. This is possible since GtkComboBox implements the
 * #GtkCellLayout interface. The tree model holding the valid choices is
 * not restricted to a flat list, it can be a real tree, and the popup will
 * reflect the tree structure.
 * 
 * To allow the user to enter values not in the model, the “has-entry”
 * property allows the GtkComboBox to contain a #GtkEntry. This entry
 * can be accessed by calling gtk_bin_get_child() on the combo box.
 * 
 * For a simple list of textual choices, the model-view API of GtkComboBox
 * can be a bit overwhelming. In this case, #GtkComboBoxText offers a
 * simple alternative. Both GtkComboBox and #GtkComboBoxText can contain
 * an entry.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * combobox
 * ├── box.linked
 * │   ╰── button.combo
 * │       ╰── box
 * │           ├── cellview
 * │           ╰── arrow
 * ╰── window.popup
 * ]|
 * 
 * A normal combobox contains a box with the .linked class, a button
 * with the .combo class and inside those buttons, there are a cellview and
 * an arrow.
 * 
 * |[<!-- language="plain" -->
 * combobox
 * ├── box.linked
 * │   ├── entry.combo
 * │   ╰── button.combo
 * │       ╰── box
 * │           ╰── arrow
 * ╰── window.popup
 * ]|
 * 
 * A GtkComboBox with an entry has a single CSS node with name combobox. It
 * contains a box with the .linked class. That box contains an entry and a
 * button, both with the .combo class added.
 * The button also contains another node with name arrow.
 *
 */
@interface OGTKComboBox : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithArea:(OGTKCellArea*)area;
- (instancetype)initWithAreaAndEntry:(OGTKCellArea*)area;
- (instancetype)initWithEntry;
- (instancetype)initWithModel:(GtkTreeModel*)model;
- (instancetype)initWithModelAndEntry:(GtkTreeModel*)model;

/**
 * Methods
 */

- (GtkComboBox*)COMBOBOX;

/**
 * Returns the index of the currently active item, or -1 if there’s no
 * active item. If the model is a non-flat treemodel, and the active item
 * is not an immediate child of the root of the tree, this function returns
 * `gtk_tree_path_get_indices (path)[0]`, where
 * `path` is the #GtkTreePath of the active item.
 *
 * @return An integer which is the index of the currently active item,
 *     or -1 if there’s no active item.
 */
- (gint)active;

/**
 * Returns the ID of the active row of @combo_box.  This value is taken
 * from the active row and the column specified by the #GtkComboBox:id-column
 * property of @combo_box (see gtk_combo_box_set_id_column()).
 * 
 * The returned value is an interned string which means that you can
 * compare the pointer by value to other interned strings and that you
 * must not free it.
 * 
 * If the #GtkComboBox:id-column property of @combo_box is not set, or if
 * no row is active, or if the active row has a %NULL ID value, then %NULL
 * is returned.
 *
 * @return the ID of the active row, or %NULL
 */
- (OFString*)activeId;

/**
 * Sets @iter to point to the currently active item, if any item is active.
 * Otherwise, @iter is left unchanged.
 *
 * @param iter A #GtkTreeIter
 * @return %TRUE if @iter was set, %FALSE otherwise
 */
- (bool)activeIter:(GtkTreeIter*)iter;

/**
 * Gets the current value of the :add-tearoffs property.
 *
 * @return the current value of the :add-tearoffs property.
 */
- (bool)addTearoffs;

/**
 * Returns whether the combo box sets the dropdown button
 * sensitive or not when there are no items in the model.
 *
 * @return %GTK_SENSITIVITY_ON if the dropdown button
 *    is sensitive when the model is empty, %GTK_SENSITIVITY_OFF
 *    if the button is always insensitive or
 *    %GTK_SENSITIVITY_AUTO if it is only sensitive as long as
 *    the model has one item to be selected.
 */
- (GtkSensitivityType)buttonSensitivity;

/**
 * Returns the column with column span information for @combo_box.
 *
 * @return the column span column.
 */
- (gint)columnSpanColumn;

/**
 * Returns the column which @combo_box is using to get the strings
 * from to display in the internal entry.
 *
 * @return A column in the data source model of @combo_box.
 */
- (gint)entryTextColumn;

/**
 * Returns whether the combo box grabs focus when it is clicked
 * with the mouse. See gtk_combo_box_set_focus_on_click().
 *
 * @return %TRUE if the combo box grabs focus when it is
 *     clicked with the mouse.
 */
- (bool)focusOnClick;

/**
 * Returns whether the combo box has an entry.
 *
 * @return whether there is an entry in @combo_box.
 */
- (bool)hasEntry;

/**
 * Returns the column which @combo_box is using to get string IDs
 * for values from.
 *
 * @return A column in the data source model of @combo_box.
 */
- (gint)idColumn;

/**
 * Returns the #GtkTreeModel which is acting as data source for @combo_box.
 *
 * @return A #GtkTreeModel which was passed
 *     during construction.
 */
- (GtkTreeModel*)model;

/**
 * Gets the accessible object corresponding to the combo box’s popup.
 * 
 * This function is mostly intended for use by accessibility technologies;
 * applications should have little use for it.
 *
 * @return the accessible object corresponding
 *     to the combo box’s popup.
 */
- (OGAtkObject*)popupAccessible;

/**
 * Gets whether the popup uses a fixed width matching
 * the allocated width of the combo box.
 *
 * @return %TRUE if the popup uses a fixed width
 */
- (bool)popupFixedWidth;

/**
 * Returns the current row separator function.
 *
 * @return the current row separator function.
 */
- (GtkTreeViewRowSeparatorFunc)rowSeparatorFunc;

/**
 * Returns the column with row span information for @combo_box.
 *
 * @return the row span column.
 */
- (gint)rowSpanColumn;

/**
 * Gets the current title of the menu in tearoff mode. See
 * gtk_combo_box_set_add_tearoffs().
 *
 * @return the menu’s title in tearoff mode. This is an internal copy of the
 * string which must not be freed.
 */
- (OFString*)title;

/**
 * Returns the wrap width which is used to determine the number of columns
 * for the popup menu. If the wrap width is larger than 1, the combo box
 * is in table mode.
 *
 * @return the wrap width.
 */
- (gint)wrapWidth;

/**
 * Hides the menu or dropdown list of @combo_box.
 * 
 * This function is mostly intended for use by accessibility technologies;
 * applications should have little use for it.
 *
 */
- (void)popdown;

/**
 * Pops up the menu or dropdown list of @combo_box.
 * 
 * This function is mostly intended for use by accessibility technologies;
 * applications should have little use for it.
 * 
 * Before calling this, @combo_box must be mapped, or nothing will happen.
 *
 */
- (void)popup;

/**
 * Pops up the menu or dropdown list of @combo_box, the popup window
 * will be grabbed so only @device and its associated pointer/keyboard
 * are the only #GdkDevices able to send events to it.
 *
 * @param device a #GdkDevice
 */
- (void)popupForDevice:(OGGdkDevice*)device;

/**
 * Sets the active item of @combo_box to be the item at @index.
 *
 * @param index An index in the model passed during construction, or -1 to have
 * no active item
 */
- (void)setActive:(gint)index;

/**
 * Changes the active row of @combo_box to the one that has an ID equal to
 * @active_id, or unsets the active row if @active_id is %NULL.  Rows having
 * a %NULL ID string cannot be made active by this function.
 * 
 * If the #GtkComboBox:id-column property of @combo_box is unset or if no
 * row has the given ID then the function does nothing and returns %FALSE.
 *
 * @param activeId the ID of the row to select, or %NULL
 * @return %TRUE if a row with a matching ID was found.  If a %NULL
 *          @active_id was given to unset the active row, the function
 *          always returns %TRUE.
 */
- (bool)setActiveId:(OFString*)activeId;

/**
 * Sets the current active item to be the one referenced by @iter, or
 * unsets the active item if @iter is %NULL.
 *
 * @param iter The #GtkTreeIter, or %NULL
 */
- (void)setActiveIter:(GtkTreeIter*)iter;

/**
 * Sets whether the popup menu should have a tearoff
 * menu item.
 *
 * @param addTearoffs %TRUE to add tearoff menu items
 */
- (void)setAddTearoffs:(bool)addTearoffs;

/**
 * Sets whether the dropdown button of the combo box should be
 * always sensitive (%GTK_SENSITIVITY_ON), never sensitive (%GTK_SENSITIVITY_OFF)
 * or only if there is at least one item to display (%GTK_SENSITIVITY_AUTO).
 *
 * @param sensitivity specify the sensitivity of the dropdown button
 */
- (void)setButtonSensitivity:(GtkSensitivityType)sensitivity;

/**
 * Sets the column with column span information for @combo_box to be
 * @column_span. The column span column contains integers which indicate
 * how many columns an item should span.
 *
 * @param columnSpan A column in the model passed during construction
 */
- (void)setColumnSpanColumn:(gint)columnSpan;

/**
 * Sets the model column which @combo_box should use to get strings from
 * to be @text_column. The column @text_column in the model of @combo_box
 * must be of type %G_TYPE_STRING.
 * 
 * This is only relevant if @combo_box has been created with
 * #GtkComboBox:has-entry as %TRUE.
 *
 * @param textColumn A column in @model to get the strings from for
 *     the internal entry
 */
- (void)setEntryTextColumn:(gint)textColumn;

/**
 * Sets whether the combo box will grab focus when it is clicked with
 * the mouse. Making mouse clicks not grab focus is useful in places
 * like toolbars where you don’t want the keyboard focus removed from
 * the main area of the application.
 *
 * @param focusOnClick whether the combo box grabs focus when clicked
 *    with the mouse
 */
- (void)setFocusOnClick:(bool)focusOnClick;

/**
 * Sets the model column which @combo_box should use to get string IDs
 * for values from. The column @id_column in the model of @combo_box
 * must be of type %G_TYPE_STRING.
 *
 * @param idColumn A column in @model to get string IDs for values from
 */
- (void)setIdColumn:(gint)idColumn;

/**
 * Sets the model used by @combo_box to be @model. Will unset a previously set
 * model (if applicable). If model is %NULL, then it will unset the model.
 * 
 * Note that this function does not clear the cell renderers, you have to
 * call gtk_cell_layout_clear() yourself if you need to set up different
 * cell renderers for the new model.
 *
 * @param model A #GtkTreeModel
 */
- (void)setModel:(GtkTreeModel*)model;

/**
 * Specifies whether the popup’s width should be a fixed width
 * matching the allocated width of the combo box.
 *
 * @param fixed whether to use a fixed popup width
 */
- (void)setPopupFixedWidth:(bool)fixed;

/**
 * Sets the row separator function, which is used to determine
 * whether a row should be drawn as a separator. If the row separator
 * function is %NULL, no separators are drawn. This is the default value.
 *
 * @param func a #GtkTreeViewRowSeparatorFunc
 * @param data user data to pass to @func, or %NULL
 * @param destroy destroy notifier for @data, or %NULL
 */
- (void)setRowSeparatorFuncWithFunc:(GtkTreeViewRowSeparatorFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy;

/**
 * Sets the column with row span information for @combo_box to be @row_span.
 * The row span column contains integers which indicate how many rows
 * an item should span.
 *
 * @param rowSpan A column in the model passed during construction.
 */
- (void)setRowSpanColumn:(gint)rowSpan;

/**
 * Sets the menu’s title in tearoff mode.
 *
 * @param title a title for the menu in tearoff mode
 */
- (void)setTitle:(OFString*)title;

/**
 * Sets the wrap width of @combo_box to be @width. The wrap width is basically
 * the preferred number of columns when you want the popup to be layed out
 * in a table.
 *
 * @param width Preferred number of columns
 */
- (void)setWrapWidth:(gint)width;

@end