/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

/**
 * A GtkShortcutsSection collects all the keyboard shortcuts and gestures
 * for a major application mode. If your application needs multiple sections,
 * you should give each section a unique #GtkShortcutsSection:section-name and
 * a #GtkShortcutsSection:title that can be shown in the section selector of
 * the GtkShortcutsWindow.
 * 
 * The #GtkShortcutsSection:max-height property can be used to influence how
 * the groups in the section are distributed over pages and columns.
 * 
 * This widget is only meant to be used with #GtkShortcutsWindow.
 *
 */
@interface OGTKShortcutsSection : OGTKBox
{

}


/**
 * Methods
 */

- (GtkShortcutsSection*)SHORTCUTSSECTION;

@end