/*
 * OGTKGLArea.m
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
#import "OGTKGLArea.h"

@implementation OGTKGLArea

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_gl_area_new()];

	return self;
}

- (GtkGLArea*)GLAREA
{
	return GTK_GL_AREA([self GOBJECT]);
}

- (void)gtkGlAreaAttachBuffers
{
	gtk_gl_area_attach_buffers(GTK_GL_AREA([self GOBJECT]));
}

- (bool)gtkGlAreaGetAutoRender
{
	return gtk_gl_area_get_auto_render(GTK_GL_AREA([self GOBJECT]));
}

- (GdkGLContext*)gtkGlAreaGetContext
{
	return gtk_gl_area_get_context(GTK_GL_AREA([self GOBJECT]));
}

- (GError*)gtkGlAreaGetError
{
	return gtk_gl_area_get_error(GTK_GL_AREA([self GOBJECT]));
}

- (bool)gtkGlAreaGetHasAlpha
{
	return gtk_gl_area_get_has_alpha(GTK_GL_AREA([self GOBJECT]));
}

- (bool)gtkGlAreaGetHasDepthBuffer
{
	return gtk_gl_area_get_has_depth_buffer(GTK_GL_AREA([self GOBJECT]));
}

- (bool)gtkGlAreaGetHasStencilBuffer
{
	return gtk_gl_area_get_has_stencil_buffer(GTK_GL_AREA([self GOBJECT]));
}

- (void)gtkGlAreaGetRequiredVersionWithMajor:(gint*)major andMinor:(gint*)minor
{
	gtk_gl_area_get_required_version(GTK_GL_AREA([self GOBJECT]), major, minor);
}

- (bool)gtkGlAreaGetUseEs
{
	return gtk_gl_area_get_use_es(GTK_GL_AREA([self GOBJECT]));
}

- (void)gtkGlAreaMakeCurrent
{
	gtk_gl_area_make_current(GTK_GL_AREA([self GOBJECT]));
}

- (void)gtkGlAreaQueueRender
{
	gtk_gl_area_queue_render(GTK_GL_AREA([self GOBJECT]));
}

- (void)gtkGlAreaSetAutoRender:(bool)autoRender
{
	gtk_gl_area_set_auto_render(GTK_GL_AREA([self GOBJECT]), autoRender);
}

- (void)gtkGlAreaSetError:(const GError*)error
{
	gtk_gl_area_set_error(GTK_GL_AREA([self GOBJECT]), error);
}

- (void)gtkGlAreaSetHasAlpha:(bool)hasAlpha
{
	gtk_gl_area_set_has_alpha(GTK_GL_AREA([self GOBJECT]), hasAlpha);
}

- (void)gtkGlAreaSetHasDepthBuffer:(bool)hasDepthBuffer
{
	gtk_gl_area_set_has_depth_buffer(GTK_GL_AREA([self GOBJECT]), hasDepthBuffer);
}

- (void)gtkGlAreaSetHasStencilBuffer:(bool)hasStencilBuffer
{
	gtk_gl_area_set_has_stencil_buffer(GTK_GL_AREA([self GOBJECT]), hasStencilBuffer);
}

- (void)gtkGlAreaSetRequiredVersionWithMajor:(gint)major andMinor:(gint)minor
{
	gtk_gl_area_set_required_version(GTK_GL_AREA([self GOBJECT]), major, minor);
}

- (void)gtkGlAreaSetUseEs:(bool)useEs
{
	gtk_gl_area_set_use_es(GTK_GL_AREA([self GOBJECT]), useEs);
}


@end