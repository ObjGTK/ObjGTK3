/*
 * OGTKStatusIcon.h
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

@interface OGTKStatusIcon : OGTKBase
{

}

/**
 * Functions
 */
+ (void)positionMenuWithMenu:(GtkMenu*)menu andX:(gint*)x andY:(gint*)y andPushIn:(gboolean*)pushIn andUserData:(gpointer)userData;

/**
 * Constructors
 */
- (id)init;
- (id)initFromFile:(OFString*)filename;
- (id)initFromGicon:(GIcon*)icon;
- (id)initFromIconName:(OFString*)iconName;
- (id)initFromPixbuf:(GdkPixbuf*)pixbuf;
- (id)initFromStock:(OFString*)stockId;

/**
 * Methods
 */

- (GtkStatusIcon*)STATUSICON;

/**
 * - (bool*)getGeometryWithScreen:(GdkScreen**)screen andArea:(GdkRectangle*)area andOrientation:(GtkOrientation*)orientation;
 *
 * @param screen
 * @param area
 * @param orientation
 * @returns bool
 */
- (bool)getGeometryWithScreen:(GdkScreen**)screen andArea:(GdkRectangle*)area andOrientation:(GtkOrientation*)orientation;

/**
 * - (GIcon**)getGicon;
 *
 * @returns GIcon*
 */
- (GIcon*)getGicon;

/**
 * - (bool*)getHasTooltip;
 *
 * @returns bool
 */
- (bool)getHasTooltip;

/**
 * - (OFString**)getIconName;
 *
 * @returns OFString*
 */
- (OFString*)getIconName;

/**
 * - (GdkPixbuf**)getPixbuf;
 *
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getPixbuf;

/**
 * - (GdkScreen**)getScreen;
 *
 * @returns GdkScreen*
 */
- (GdkScreen*)getScreen;

/**
 * - (gint*)getSize;
 *
 * @returns gint
 */
- (gint)getSize;

/**
 * - (OFString**)getStock;
 *
 * @returns OFString*
 */
- (OFString*)getStock;

/**
 * - (GtkImageType*)getStorageType;
 *
 * @returns GtkImageType
 */
- (GtkImageType)getStorageType;

/**
 * - (OFString**)getTitle;
 *
 * @returns OFString*
 */
- (OFString*)getTitle;

/**
 * - (OFString**)getTooltipMarkup;
 *
 * @returns OFString*
 */
- (OFString*)getTooltipMarkup;

/**
 * - (OFString**)getTooltipText;
 *
 * @returns OFString*
 */
- (OFString*)getTooltipText;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

/**
 * - (guint32*)getX11WindowId;
 *
 * @returns guint32
 */
- (guint32)getX11WindowId;

/**
 * - (bool*)isEmbedded;
 *
 * @returns bool
 */
- (bool)isEmbedded;

/**
 * - (void*)setFromFile:(OFString*)filename;
 *
 * @param filename
 */
- (void)setFromFile:(OFString*)filename;

/**
 * - (void*)setFromGicon:(GIcon*)icon;
 *
 * @param icon
 */
- (void)setFromGicon:(GIcon*)icon;

/**
 * - (void*)setFromIconName:(OFString*)iconName;
 *
 * @param iconName
 */
- (void)setFromIconName:(OFString*)iconName;

/**
 * - (void*)setFromPixbuf:(GdkPixbuf*)pixbuf;
 *
 * @param pixbuf
 */
- (void)setFromPixbuf:(GdkPixbuf*)pixbuf;

/**
 * - (void*)setFromStock:(OFString*)stockId;
 *
 * @param stockId
 */
- (void)setFromStock:(OFString*)stockId;

/**
 * - (void*)setHasTooltip:(bool)hasTooltip;
 *
 * @param hasTooltip
 */
- (void)setHasTooltip:(bool)hasTooltip;

/**
 * - (void*)setName:(OFString*)name;
 *
 * @param name
 */
- (void)setName:(OFString*)name;

/**
 * - (void*)setScreen:(GdkScreen*)screen;
 *
 * @param screen
 */
- (void)setScreen:(GdkScreen*)screen;

/**
 * - (void*)setTitle:(OFString*)title;
 *
 * @param title
 */
- (void)setTitle:(OFString*)title;

/**
 * - (void*)setTooltipMarkup:(OFString*)markup;
 *
 * @param markup
 */
- (void)setTooltipMarkup:(OFString*)markup;

/**
 * - (void*)setTooltipText:(OFString*)text;
 *
 * @param text
 */
- (void)setTooltipText:(OFString*)text;

/**
 * - (void*)setVisible:(bool)visible;
 *
 * @param visible
 */
- (void)setVisible:(bool)visible;

@end