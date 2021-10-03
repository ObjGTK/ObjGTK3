/*
 * OGTKGLArea.h
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

@interface OGTKGLArea : OGTKWidget
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkGLArea*)GLAREA;

/**
 * - (void*)gtkGlAreaAttachBuffers;
 *
 */
- (void)gtkGlAreaAttachBuffers;

/**
 * - (bool*)gtkGlAreaGetAutoRender;
 *
 * @returns bool
 */
- (bool)gtkGlAreaGetAutoRender;

/**
 * - (GdkGLContext**)gtkGlAreaGetContext;
 *
 * @returns GdkGLContext*
 */
- (GdkGLContext*)gtkGlAreaGetContext;

/**
 * - (GError**)gtkGlAreaGetError;
 *
 * @returns GError*
 */
- (GError*)gtkGlAreaGetError;

/**
 * - (bool*)gtkGlAreaGetHasAlpha;
 *
 * @returns bool
 */
- (bool)gtkGlAreaGetHasAlpha;

/**
 * - (bool*)gtkGlAreaGetHasDepthBuffer;
 *
 * @returns bool
 */
- (bool)gtkGlAreaGetHasDepthBuffer;

/**
 * - (bool*)gtkGlAreaGetHasStencilBuffer;
 *
 * @returns bool
 */
- (bool)gtkGlAreaGetHasStencilBuffer;

/**
 * - (void*)gtkGlAreaGetRequiredVersionWithMajor:(gint*)major andMinor:(gint*)minor;
 *
 * @param major
 * @param minor
 */
- (void)gtkGlAreaGetRequiredVersionWithMajor:(gint*)major andMinor:(gint*)minor;

/**
 * - (bool*)gtkGlAreaGetUseEs;
 *
 * @returns bool
 */
- (bool)gtkGlAreaGetUseEs;

/**
 * - (void*)gtkGlAreaMakeCurrent;
 *
 */
- (void)gtkGlAreaMakeCurrent;

/**
 * - (void*)gtkGlAreaQueueRender;
 *
 */
- (void)gtkGlAreaQueueRender;

/**
 * - (void*)gtkGlAreaSetAutoRender:(bool)autoRender;
 *
 * @param autoRender
 */
- (void)gtkGlAreaSetAutoRender:(bool)autoRender;

/**
 * - (void*)gtkGlAreaSetError:(const GError*)error;
 *
 * @param error
 */
- (void)gtkGlAreaSetError:(const GError*)error;

/**
 * - (void*)gtkGlAreaSetHasAlpha:(bool)hasAlpha;
 *
 * @param hasAlpha
 */
- (void)gtkGlAreaSetHasAlpha:(bool)hasAlpha;

/**
 * - (void*)gtkGlAreaSetHasDepthBuffer:(bool)hasDepthBuffer;
 *
 * @param hasDepthBuffer
 */
- (void)gtkGlAreaSetHasDepthBuffer:(bool)hasDepthBuffer;

/**
 * - (void*)gtkGlAreaSetHasStencilBuffer:(bool)hasStencilBuffer;
 *
 * @param hasStencilBuffer
 */
- (void)gtkGlAreaSetHasStencilBuffer:(bool)hasStencilBuffer;

/**
 * - (void*)gtkGlAreaSetRequiredVersionWithMajor:(gint)major andMinor:(gint)minor;
 *
 * @param major
 * @param minor
 */
- (void)gtkGlAreaSetRequiredVersionWithMajor:(gint)major andMinor:(gint)minor;

/**
 * - (void*)gtkGlAreaSetUseEs:(bool)useEs;
 *
 * @param useEs
 */
- (void)gtkGlAreaSetUseEs:(bool)useEs;

@end