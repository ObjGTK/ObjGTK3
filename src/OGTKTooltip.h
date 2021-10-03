/*
 * OGTKTooltip.h
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
#import "OGTKBase.h"

@interface OGTKTooltip : OGTKBase
{

}

/**
 * Functions
 */
+ (void)triggerTooltipQuery:(GdkDisplay*)display;

/**
 * Methods
 */

- (GtkTooltip*)TOOLTIP;

/**
 * - (void*)setCustom:(OGTKWidget*)customWidget;
 *
 * @param customWidget
 */
- (void)setCustom:(OGTKWidget*)customWidget;

/**
 * - (void*)setIcon:(GdkPixbuf*)pixbuf;
 *
 * @param pixbuf
 */
- (void)setIcon:(GdkPixbuf*)pixbuf;

/**
 * - (void*)setIconFromGiconWithGicon:(GIcon*)gicon andSize:(GtkIconSize)size;
 *
 * @param gicon
 * @param size
 */
- (void)setIconFromGiconWithGicon:(GIcon*)gicon andSize:(GtkIconSize)size;

/**
 * - (void*)setIconFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size;
 *
 * @param iconName
 * @param size
 */
- (void)setIconFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size;

/**
 * - (void*)setIconFromStockWithStockId:(OFString*)stockId andSize:(GtkIconSize)size;
 *
 * @param stockId
 * @param size
 */
- (void)setIconFromStockWithStockId:(OFString*)stockId andSize:(GtkIconSize)size;

/**
 * - (void*)setMarkup:(OFString*)markup;
 *
 * @param markup
 */
- (void)setMarkup:(OFString*)markup;

/**
 * - (void*)setText:(OFString*)text;
 *
 * @param text
 */
- (void)setText:(OFString*)text;

/**
 * - (void*)setTipArea:(const GdkRectangle*)rect;
 *
 * @param rect
 */
- (void)setTipArea:(const GdkRectangle*)rect;

@end