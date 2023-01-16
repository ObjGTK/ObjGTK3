/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * The #GtkHandleBox widget allows a portion of a window to be "torn
 * off". It is a bin widget which displays its child and a handle that
 * the user can drag to tear off a separate window (the “float
 * window”) containing the child widget. A thin
 * “ghost” is drawn in the original location of the
 * handlebox. By dragging the separate window back to its original
 * location, it can be reattached.
 * 
 * When reattaching, the ghost and float window, must be aligned
 * along one of the edges, the “snap edge”.
 * This either can be specified by the application programmer
 * explicitly, or GTK+ will pick a reasonable default based
 * on the handle position.
 * 
 * To make detaching and reattaching the handlebox as minimally confusing
 * as possible to the user, it is important to set the snap edge so that
 * the snap edge does not move when the handlebox is deattached. For
 * instance, if the handlebox is packed at the bottom of a VBox, then
 * when the handlebox is detached, the bottom edge of the handlebox's
 * allocation will remain fixed as the height of the handlebox shrinks,
 * so the snap edge should be set to %GTK_POS_BOTTOM.
 * 
 * > #GtkHandleBox has been deprecated. It is very specialized, lacks features
 * > to make it useful and most importantly does not fit well into modern
 * > application design. Do not use it. There is no replacement.
 *
 */
@interface OGTKHandleBox : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkHandleBox*)HANDLEBOX;

/**
 * Whether the handlebox’s child is currently detached.
 *
 * @return %TRUE if the child is currently detached, otherwise %FALSE
 */
- (bool)childDetached;

/**
 * Gets the handle position of the handle box. See
 * gtk_handle_box_set_handle_position().
 *
 * @return the current handle position.
 */
- (GtkPositionType)handlePosition;

/**
 * Gets the type of shadow drawn around the handle box. See
 * gtk_handle_box_set_shadow_type().
 *
 * @return the type of shadow currently drawn around the handle box.
 */
- (GtkShadowType)shadowType;

/**
 * Gets the edge used for determining reattachment of the handle box.
 * See gtk_handle_box_set_snap_edge().
 *
 * @return the edge used for determining reattachment, or
 *   (GtkPositionType)-1 if this is determined (as per default)
 *   from the handle position.
 */
- (GtkPositionType)snapEdge;

/**
 * Sets the side of the handlebox where the handle is drawn.
 *
 * @param position the side of the handlebox where the handle should be drawn.
 */
- (void)setHandlePosition:(GtkPositionType)position;

/**
 * Sets the type of shadow to be drawn around the border
 * of the handle box.
 *
 * @param type the shadow type.
 */
- (void)setShadowType:(GtkShadowType)type;

/**
 * Sets the snap edge of a handlebox. The snap edge is
 * the edge of the detached child that must be aligned
 * with the corresponding edge of the “ghost” left
 * behind when the child was detached to reattach
 * the torn-off window. Usually, the snap edge should
 * be chosen so that it stays in the same place on
 * the screen when the handlebox is torn off.
 * 
 * If the snap edge is not set, then an appropriate value
 * will be guessed from the handle position. If the
 * handle position is %GTK_POS_RIGHT or %GTK_POS_LEFT,
 * then the snap edge will be %GTK_POS_TOP, otherwise
 * it will be %GTK_POS_LEFT.
 *
 * @param edge the snap edge, or -1 to unset the value; in which
 *   case GTK+ will try to guess an appropriate value
 *   in the future.
 */
- (void)setSnapEdge:(GtkPositionType)edge;

@end