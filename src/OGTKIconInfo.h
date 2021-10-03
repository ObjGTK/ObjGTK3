/*
 * OGTKIconInfo.h
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

@interface OGTKIconInfo : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initForPixbufWithIconTheme:(GtkIconTheme*)iconTheme andPixbuf:(GdkPixbuf*)pixbuf;

/**
 * Methods
 */

- (GtkIconInfo*)ICONINFO;

/**
 * - (GtkIconInfo**)copy;
 *
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)copy;

/**
 * - (void*)free;
 *
 */
- (void)free;

/**
 * - (bool*)getAttachPointsWithPoints:(GdkPoint**)points andNpoints:(gint*)npoints;
 *
 * @param points
 * @param npoints
 * @returns bool
 */
- (bool)getAttachPointsWithPoints:(GdkPoint**)points andNpoints:(gint*)npoints;

/**
 * - (gint*)getBaseScale;
 *
 * @returns gint
 */
- (gint)getBaseScale;

/**
 * - (gint*)getBaseSize;
 *
 * @returns gint
 */
- (gint)getBaseSize;

/**
 * - (GdkPixbuf**)getBuiltinPixbuf;
 *
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getBuiltinPixbuf;

/**
 * - (OFString**)getDisplayName;
 *
 * @returns OFString*
 */
- (OFString*)getDisplayName;

/**
 * - (bool*)getEmbeddedRect:(GdkRectangle*)rectangle;
 *
 * @param rectangle
 * @returns bool
 */
- (bool)getEmbeddedRect:(GdkRectangle*)rectangle;

/**
 * - (OFString**)getFilename;
 *
 * @returns OFString*
 */
- (OFString*)getFilename;

/**
 * - (bool*)isSymbolic;
 *
 * @returns bool
 */
- (bool)isSymbolic;

/**
 * - (GdkPixbuf**)loadIcon;
 *
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadIcon;

/**
 * - (void*)loadIconAsyncWithCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData;
 *
 * @param cancellable
 * @param callback
 * @param userData
 */
- (void)loadIconAsyncWithCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData;

/**
 * - (GdkPixbuf**)loadIconFinish:(GAsyncResult*)res;
 *
 * @param res
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadIconFinish:(GAsyncResult*)res;

/**
 * - (cairo_surface_t**)loadSurface:(GdkWindow*)forWindow;
 *
 * @param forWindow
 * @returns cairo_surface_t*
 */
- (cairo_surface_t*)loadSurface:(GdkWindow*)forWindow;

/**
 * - (GdkPixbuf**)loadSymbolicWithFg:(const GdkRGBA*)fg andSuccessColor:(const GdkRGBA*)successColor andWarningColor:(const GdkRGBA*)warningColor andErrorColor:(const GdkRGBA*)errorColor andWasSymbolic:(gboolean*)wasSymbolic;
 *
 * @param fg
 * @param successColor
 * @param warningColor
 * @param errorColor
 * @param wasSymbolic
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadSymbolicWithFg:(const GdkRGBA*)fg andSuccessColor:(const GdkRGBA*)successColor andWarningColor:(const GdkRGBA*)warningColor andErrorColor:(const GdkRGBA*)errorColor andWasSymbolic:(gboolean*)wasSymbolic;

/**
 * - (void*)loadSymbolicAsyncWithFg:(const GdkRGBA*)fg andSuccessColor:(const GdkRGBA*)successColor andWarningColor:(const GdkRGBA*)warningColor andErrorColor:(const GdkRGBA*)errorColor andCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData;
 *
 * @param fg
 * @param successColor
 * @param warningColor
 * @param errorColor
 * @param cancellable
 * @param callback
 * @param userData
 */
- (void)loadSymbolicAsyncWithFg:(const GdkRGBA*)fg andSuccessColor:(const GdkRGBA*)successColor andWarningColor:(const GdkRGBA*)warningColor andErrorColor:(const GdkRGBA*)errorColor andCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData;

/**
 * - (GdkPixbuf**)loadSymbolicFinishWithRes:(GAsyncResult*)res andWasSymbolic:(gboolean*)wasSymbolic;
 *
 * @param res
 * @param wasSymbolic
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadSymbolicFinishWithRes:(GAsyncResult*)res andWasSymbolic:(gboolean*)wasSymbolic;

/**
 * - (GdkPixbuf**)loadSymbolicForContextWithContext:(GtkStyleContext*)context andWasSymbolic:(gboolean*)wasSymbolic;
 *
 * @param context
 * @param wasSymbolic
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadSymbolicForContextWithContext:(GtkStyleContext*)context andWasSymbolic:(gboolean*)wasSymbolic;

/**
 * - (void*)loadSymbolicForContextAsyncWithContext:(GtkStyleContext*)context andCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData;
 *
 * @param context
 * @param cancellable
 * @param callback
 * @param userData
 */
- (void)loadSymbolicForContextAsyncWithContext:(GtkStyleContext*)context andCancellable:(GCancellable*)cancellable andCallback:(GAsyncReadyCallback)callback andUserData:(gpointer)userData;

/**
 * - (GdkPixbuf**)loadSymbolicForContextFinishWithRes:(GAsyncResult*)res andWasSymbolic:(gboolean*)wasSymbolic;
 *
 * @param res
 * @param wasSymbolic
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadSymbolicForContextFinishWithRes:(GAsyncResult*)res andWasSymbolic:(gboolean*)wasSymbolic;

/**
 * - (GdkPixbuf**)loadSymbolicForStyleWithStyle:(GtkStyle*)style andState:(GtkStateType)state andWasSymbolic:(gboolean*)wasSymbolic;
 *
 * @param style
 * @param state
 * @param wasSymbolic
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadSymbolicForStyleWithStyle:(GtkStyle*)style andState:(GtkStateType)state andWasSymbolic:(gboolean*)wasSymbolic;

/**
 * - (void*)setRawCoordinates:(bool)rawCoordinates;
 *
 * @param rawCoordinates
 */
- (void)setRawCoordinates:(bool)rawCoordinates;

@end