/*
 * OGTKScrolledWindow.h
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKBin.h"

@interface OGTKScrolledWindow : OGTKBin
{

}


/**
 * Constructors
 */
- (id)initWithHadjustment:(GtkAdjustment*)hadjustment andVadjustment:(GtkAdjustment*)vadjustment;

/**
 * Methods
 */

- (GtkScrolledWindow*)SCROLLEDWINDOW;

/**
 * - (void*)addWithViewport:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)addWithViewport:(OGTKWidget*)child;

/**
 * - (bool*)getCaptureButtonPress;
 *
 * @returns bool
 */
- (bool)getCaptureButtonPress;

/**
 * - (GtkAdjustment**)getHadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getHadjustment;

/**
 * - (OGTKWidget**)getHscrollbar;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getHscrollbar;

/**
 * - (bool*)getKineticScrolling;
 *
 * @returns bool
 */
- (bool)getKineticScrolling;

/**
 * - (gint*)getMaxContentHeight;
 *
 * @returns gint
 */
- (gint)getMaxContentHeight;

/**
 * - (gint*)getMaxContentWidth;
 *
 * @returns gint
 */
- (gint)getMaxContentWidth;

/**
 * - (gint*)getMinContentHeight;
 *
 * @returns gint
 */
- (gint)getMinContentHeight;

/**
 * - (gint*)getMinContentWidth;
 *
 * @returns gint
 */
- (gint)getMinContentWidth;

/**
 * - (bool*)getOverlayScrolling;
 *
 * @returns bool
 */
- (bool)getOverlayScrolling;

/**
 * - (GtkCornerType*)getPlacement;
 *
 * @returns GtkCornerType
 */
- (GtkCornerType)getPlacement;

/**
 * - (void*)getPolicyWithHscrollbarPolicy:(GtkPolicyType*)hscrollbarPolicy andVscrollbarPolicy:(GtkPolicyType*)vscrollbarPolicy;
 *
 * @param hscrollbarPolicy
 * @param vscrollbarPolicy
 */
- (void)getPolicyWithHscrollbarPolicy:(GtkPolicyType*)hscrollbarPolicy andVscrollbarPolicy:(GtkPolicyType*)vscrollbarPolicy;

/**
 * - (bool*)getPropagateNaturalHeight;
 *
 * @returns bool
 */
- (bool)getPropagateNaturalHeight;

/**
 * - (bool*)getPropagateNaturalWidth;
 *
 * @returns bool
 */
- (bool)getPropagateNaturalWidth;

/**
 * - (GtkShadowType*)getShadowType;
 *
 * @returns GtkShadowType
 */
- (GtkShadowType)getShadowType;

/**
 * - (GtkAdjustment**)getVadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getVadjustment;

/**
 * - (OGTKWidget**)getVscrollbar;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getVscrollbar;

/**
 * - (void*)setCaptureButtonPress:(bool)captureButtonPress;
 *
 * @param captureButtonPress
 */
- (void)setCaptureButtonPress:(bool)captureButtonPress;

/**
 * - (void*)setHadjustment:(GtkAdjustment*)hadjustment;
 *
 * @param hadjustment
 */
- (void)setHadjustment:(GtkAdjustment*)hadjustment;

/**
 * - (void*)setKineticScrolling:(bool)kineticScrolling;
 *
 * @param kineticScrolling
 */
- (void)setKineticScrolling:(bool)kineticScrolling;

/**
 * - (void*)setMaxContentHeight:(gint)height;
 *
 * @param height
 */
- (void)setMaxContentHeight:(gint)height;

/**
 * - (void*)setMaxContentWidth:(gint)width;
 *
 * @param width
 */
- (void)setMaxContentWidth:(gint)width;

/**
 * - (void*)setMinContentHeight:(gint)height;
 *
 * @param height
 */
- (void)setMinContentHeight:(gint)height;

/**
 * - (void*)setMinContentWidth:(gint)width;
 *
 * @param width
 */
- (void)setMinContentWidth:(gint)width;

/**
 * - (void*)setOverlayScrolling:(bool)overlayScrolling;
 *
 * @param overlayScrolling
 */
- (void)setOverlayScrolling:(bool)overlayScrolling;

/**
 * - (void*)setPlacement:(GtkCornerType)windowPlacement;
 *
 * @param windowPlacement
 */
- (void)setPlacement:(GtkCornerType)windowPlacement;

/**
 * - (void*)setPolicyWithHscrollbarPolicy:(GtkPolicyType)hscrollbarPolicy andVscrollbarPolicy:(GtkPolicyType)vscrollbarPolicy;
 *
 * @param hscrollbarPolicy
 * @param vscrollbarPolicy
 */
- (void)setPolicyWithHscrollbarPolicy:(GtkPolicyType)hscrollbarPolicy andVscrollbarPolicy:(GtkPolicyType)vscrollbarPolicy;

/**
 * - (void*)setPropagateNaturalHeight:(bool)propagate;
 *
 * @param propagate
 */
- (void)setPropagateNaturalHeight:(bool)propagate;

/**
 * - (void*)setPropagateNaturalWidth:(bool)propagate;
 *
 * @param propagate
 */
- (void)setPropagateNaturalWidth:(bool)propagate;

/**
 * - (void*)setShadowType:(GtkShadowType)type;
 *
 * @param type
 */
- (void)setShadowType:(GtkShadowType)type;

/**
 * - (void*)setVadjustment:(GtkAdjustment*)vadjustment;
 *
 * @param vadjustment
 */
- (void)setVadjustment:(GtkAdjustment*)vadjustment;

/**
 * - (void*)unsetPlacement;
 *
 */
- (void)unsetPlacement;

@end