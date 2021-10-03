/*
 * OGTKProgressBar.h
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
#import "OGTKWidget.h"

@interface OGTKProgressBar : OGTKWidget
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkProgressBar*)PROGRESSBAR;

/**
 * - (PangoEllipsizeMode*)getEllipsize;
 *
 * @returns PangoEllipsizeMode
 */
- (PangoEllipsizeMode)getEllipsize;

/**
 * - (gdouble*)getFraction;
 *
 * @returns gdouble
 */
- (gdouble)getFraction;

/**
 * - (bool*)getInverted;
 *
 * @returns bool
 */
- (bool)getInverted;

/**
 * - (gdouble*)getPulseStep;
 *
 * @returns gdouble
 */
- (gdouble)getPulseStep;

/**
 * - (bool*)getShowText;
 *
 * @returns bool
 */
- (bool)getShowText;

/**
 * - (OFString**)getText;
 *
 * @returns OFString*
 */
- (OFString*)getText;

/**
 * - (void*)pulse;
 *
 */
- (void)pulse;

/**
 * - (void*)setEllipsize:(PangoEllipsizeMode)mode;
 *
 * @param mode
 */
- (void)setEllipsize:(PangoEllipsizeMode)mode;

/**
 * - (void*)setFraction:(gdouble)fraction;
 *
 * @param fraction
 */
- (void)setFraction:(gdouble)fraction;

/**
 * - (void*)setInverted:(bool)inverted;
 *
 * @param inverted
 */
- (void)setInverted:(bool)inverted;

/**
 * - (void*)setPulseStep:(gdouble)fraction;
 *
 * @param fraction
 */
- (void)setPulseStep:(gdouble)fraction;

/**
 * - (void*)setShowText:(bool)showText;
 *
 * @param showText
 */
- (void)setShowText:(bool)showText;

/**
 * - (void*)setText:(OFString*)text;
 *
 * @param text
 */
- (void)setText:(OFString*)text;

@end