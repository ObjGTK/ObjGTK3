/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

@interface OGTKListBoxRow : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkListBoxRow*)LISTBOXROW;

/**
 * Marks @row as changed, causing any state that depends on this
 * to be updated. This affects sorting, filtering and headers.
 * 
 * Note that calls to this method must be in sync with the data
 * used for the row functions. For instance, if the list is
 * mirroring some external data set, and *two* rows changed in the
 * external data set then when you call gtk_list_box_row_changed()
 * on the first row the sort function must only read the new data
 * for the first of the two changed rows, otherwise the resorting
 * of the rows will be wrong.
 * 
 * This generally means that if you don’t fully control the data
 * model you have to duplicate the data that affects the listbox
 * row functions into the row widgets themselves. Another alternative
 * is to call gtk_list_box_invalidate_sort() on any model change,
 * but that is more expensive.
 *
 */
- (void)changed;

/**
 * Gets the value of the #GtkListBoxRow:activatable property
 * for this row.
 *
 * @return %TRUE if the row is activatable
 */
- (bool)activatable;

/**
 * Returns the current header of the @row. This can be used
 * in a #GtkListBoxUpdateHeaderFunc to see if there is a header
 * set already, and if so to update the state of it.
 *
 * @return the current header, or %NULL if none
 */
- (OGTKWidget*)header;

/**
 * Gets the current index of the @row in its #GtkListBox container.
 *
 * @return the index of the @row, or -1 if the @row is not in a listbox
 */
- (gint)index;

/**
 * Gets the value of the #GtkListBoxRow:selectable property
 * for this row.
 *
 * @return %TRUE if the row is selectable
 */
- (bool)selectable;

/**
 * Returns whether the child is currently selected in its
 * #GtkListBox container.
 *
 * @return %TRUE if @row is selected
 */
- (bool)isSelected;

/**
 * Set the #GtkListBoxRow:activatable property for this row.
 *
 * @param activatable %TRUE to mark the row as activatable
 */
- (void)setActivatable:(bool)activatable;

/**
 * Sets the current header of the @row. This is only allowed to be called
 * from a #GtkListBoxUpdateHeaderFunc. It will replace any existing
 * header in the row, and be shown in front of the row in the listbox.
 *
 * @param header the header, or %NULL
 */
- (void)setHeader:(OGTKWidget*)header;

/**
 * Set the #GtkListBoxRow:selectable property for this row.
 *
 * @param selectable %TRUE to mark the row as selectable
 */
- (void)setSelectable:(bool)selectable;

@end