/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKAdjustment;
@class OGTKWidget;
@class OGTKToolItemGroup;
@class OGTKToolItem;

/**
 * A #GtkToolPalette allows you to add #GtkToolItems to a palette-like
 * container with different categories and drag and drop support.
 * 
 * A #GtkToolPalette is created with a call to gtk_tool_palette_new().
 * 
 * #GtkToolItems cannot be added directly to a #GtkToolPalette -
 * instead they are added to a #GtkToolItemGroup which can than be added
 * to a #GtkToolPalette. To add a #GtkToolItemGroup to a #GtkToolPalette,
 * use gtk_container_add().
 * 
 * |[<!-- language="C" -->
 * GtkWidget *palette, *group;
 * GtkToolItem *item;
 * 
 * palette = gtk_tool_palette_new ();
 * group = gtk_tool_item_group_new (_("Test Category"));
 * gtk_container_add (GTK_CONTAINER (palette), group);
 * 
 * item = gtk_tool_button_new (NULL, _("_Open"));
 * gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON (item), "document-open");
 * gtk_tool_item_group_insert (GTK_TOOL_ITEM_GROUP (group), item, -1);
 * ]|
 * 
 * The easiest way to use drag and drop with #GtkToolPalette is to call
 * gtk_tool_palette_add_drag_dest() with the desired drag source @palette
 * and the desired drag target @widget. Then gtk_tool_palette_get_drag_item()
 * can be used to get the dragged item in the #GtkWidget::drag-data-received
 * signal handler of the drag target.
 * 
 * |[<!-- language="C" -->
 * static void
 * passive_canvas_drag_data_received (GtkWidget        *widget,
 *                                    GdkDragContext   *context,
 *                                    gint              x,
 *                                    gint              y,
 *                                    GtkSelectionData *selection,
 *                                    guint             info,
 *                                    guint             time,
 *                                    gpointer          data)
 * {
 *   GtkWidget *palette;
 *   GtkWidget *item;
 * 
 *   // Get the dragged item
 *   palette = gtk_widget_get_ancestor (gtk_drag_get_source_widget (context),
 *                                      GTK_TYPE_TOOL_PALETTE);
 *   if (palette != NULL)
 *     item = gtk_tool_palette_get_drag_item (GTK_TOOL_PALETTE (palette),
 *                                            selection);
 * 
 *   // Do something with item
 * }
 * 
 * GtkWidget *target, palette;
 * 
 * palette = gtk_tool_palette_new ();
 * target = gtk_drawing_area_new ();
 * 
 * g_signal_connect (G_OBJECT (target), "drag-data-received",
 *                   G_CALLBACK (passive_canvas_drag_data_received), NULL);
 * gtk_tool_palette_add_drag_dest (GTK_TOOL_PALETTE (palette), target,
 *                                 GTK_DEST_DEFAULT_ALL,
 *                                 GTK_TOOL_PALETTE_DRAG_ITEMS,
 *                                 GDK_ACTION_COPY);
 * ]|
 * 
 * # CSS nodes
 * 
 * GtkToolPalette has a single CSS node named toolpalette.
 *
 */
@interface OGTKToolPalette : OGTKContainer
{

}

/**
 * Functions
 */
+ (const GtkTargetEntry*)dragTargetGroup;
+ (const GtkTargetEntry*)dragTargetItem;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkToolPalette*)TOOLPALETTE;

/**
 * Sets @palette as drag source (see gtk_tool_palette_set_drag_source())
 * and sets @widget as a drag destination for drags from @palette.
 * See gtk_drag_dest_set().
 *
 * @param widget a #GtkWidget which should be a drag destination for @palette
 * @param flags the flags that specify what actions GTK+ should take for drops
 *     on that widget
 * @param targets the #GtkToolPaletteDragTargets which the widget
 *     should support
 * @param actions the #GdkDragActions which the widget should suppport
 */
- (void)addDragDestWithWidget:(OGTKWidget*)widget flags:(GtkDestDefaults)flags targets:(GtkToolPaletteDragTargets)targets actions:(GdkDragAction)actions;

/**
 * Get the dragged item from the selection.
 * This could be a #GtkToolItem or a #GtkToolItemGroup.
 *
 * @param selection a #GtkSelectionData
 * @return the dragged item in selection
 */
- (OGTKWidget*)dragItem:(const GtkSelectionData*)selection;

/**
 * Gets the group at position (x, y).
 *
 * @param x the x position
 * @param y the y position
 * @return the #GtkToolItemGroup at position
 * or %NULL if there is no such group
 */
- (OGTKToolItemGroup*)dropGroupWithX:(gint)x y:(gint)y;

/**
 * Gets the item at position (x, y).
 * See gtk_tool_palette_get_drop_group().
 *
 * @param x the x position
 * @param y the y position
 * @return the #GtkToolItem at position or %NULL if there is no such item
 */
- (OGTKToolItem*)dropItemWithX:(gint)x y:(gint)y;

/**
 * Gets whether @group is exclusive or not.
 * See gtk_tool_palette_set_exclusive().
 *
 * @param group a #GtkToolItemGroup which is a child of palette
 * @return %TRUE if @group is exclusive
 */
- (bool)exclusive:(OGTKToolItemGroup*)group;

/**
 * Gets whether group should be given extra space.
 * See gtk_tool_palette_set_expand().
 *
 * @param group a #GtkToolItemGroup which is a child of palette
 * @return %TRUE if group should be given extra space, %FALSE otherwise
 */
- (bool)expand:(OGTKToolItemGroup*)group;

/**
 * Gets the position of @group in @palette as index.
 * See gtk_tool_palette_set_group_position().
 *
 * @param group a #GtkToolItemGroup
 * @return the index of group or -1 if @group is not a child of @palette
 */
- (gint)groupPosition:(OGTKToolItemGroup*)group;

/**
 * Gets the horizontal adjustment of the tool palette.
 *
 * @return the horizontal adjustment of @palette
 */
- (OGTKAdjustment*)hadjustment;

/**
 * Gets the size of icons in the tool palette.
 * See gtk_tool_palette_set_icon_size().
 *
 * @return the #GtkIconSize of icons in the tool palette
 */
- (GtkIconSize)iconSize;

/**
 * Gets the style (icons, text or both) of items in the tool palette.
 *
 * @return the #GtkToolbarStyle of items in the tool palette.
 */
- (GtkToolbarStyle)style;

/**
 * Gets the vertical adjustment of the tool palette.
 *
 * @return the vertical adjustment of @palette
 */
- (OGTKAdjustment*)vadjustment;

/**
 * Sets the tool palette as a drag source.
 * Enables all groups and items in the tool palette as drag sources
 * on button 1 and button 3 press with copy and move actions.
 * See gtk_drag_source_set().
 *
 * @param targets the #GtkToolPaletteDragTargets
 *     which the widget should support
 */
- (void)setDragSource:(GtkToolPaletteDragTargets)targets;

/**
 * Sets whether the group should be exclusive or not.
 * If an exclusive group is expanded all other groups are collapsed.
 *
 * @param group a #GtkToolItemGroup which is a child of palette
 * @param exclusive whether the group should be exclusive or not
 */
- (void)setExclusiveWithGroup:(OGTKToolItemGroup*)group exclusive:(bool)exclusive;

/**
 * Sets whether the group should be given extra space.
 *
 * @param group a #GtkToolItemGroup which is a child of palette
 * @param expand whether the group should be given extra space
 */
- (void)setExpandWithGroup:(OGTKToolItemGroup*)group expand:(bool)expand;

/**
 * Sets the position of the group as an index of the tool palette.
 * If position is 0 the group will become the first child, if position is
 * -1 it will become the last child.
 *
 * @param group a #GtkToolItemGroup which is a child of palette
 * @param position a new index for group
 */
- (void)setGroupPositionWithGroup:(OGTKToolItemGroup*)group position:(gint)position;

/**
 * Sets the size of icons in the tool palette.
 *
 * @param iconSize the #GtkIconSize that icons in the tool
 *     palette shall have
 */
- (void)setIconSize:(GtkIconSize)iconSize;

/**
 * Sets the style (text, icons or both) of items in the tool palette.
 *
 * @param style the #GtkToolbarStyle that items in the tool palette shall have
 */
- (void)setStyle:(GtkToolbarStyle)style;

/**
 * Unsets the tool palette icon size set with gtk_tool_palette_set_icon_size(),
 * so that user preferences will be used to determine the icon size.
 *
 */
- (void)unsetIconSize;

/**
 * Unsets a toolbar style set with gtk_tool_palette_set_style(),
 * so that user preferences will be used to determine the toolbar style.
 *
 */
- (void)unsetStyle;

@end