/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGLArea.h"

#import <OGdk3/OGGdkGLContext.h>

@implementation OGTKGLArea

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_gl_area_new()];

	return self;
}

- (GtkGLArea*)GLAREA
{
	return GTK_GL_AREA([self GOBJECT]);
}

- (void)attachBuffers
{
	gtk_gl_area_attach_buffers([self GLAREA]);
}

- (bool)autoRender
{
	return gtk_gl_area_get_auto_render([self GLAREA]);
}

- (OGGdkGLContext*)context
{
	return [[[OGGdkGLContext alloc] initWithGObject:(GObject*)gtk_gl_area_get_context([self GLAREA])] autorelease];
}

- (GError*)error
{
	return gtk_gl_area_get_error([self GLAREA]);
}

- (bool)hasAlpha
{
	return gtk_gl_area_get_has_alpha([self GLAREA]);
}

- (bool)hasDepthBuffer
{
	return gtk_gl_area_get_has_depth_buffer([self GLAREA]);
}

- (bool)hasStencilBuffer
{
	return gtk_gl_area_get_has_stencil_buffer([self GLAREA]);
}

- (void)requiredVersionWithMajor:(gint*)major minor:(gint*)minor
{
	gtk_gl_area_get_required_version([self GLAREA], major, minor);
}

- (bool)useEs
{
	return gtk_gl_area_get_use_es([self GLAREA]);
}

- (void)makeCurrent
{
	gtk_gl_area_make_current([self GLAREA]);
}

- (void)queueRender
{
	gtk_gl_area_queue_render([self GLAREA]);
}

- (void)setAutoRender:(bool)autoRender
{
	gtk_gl_area_set_auto_render([self GLAREA], autoRender);
}

- (void)setError:(const GError*)error
{
	gtk_gl_area_set_error([self GLAREA], error);
}

- (void)setHasAlpha:(bool)hasAlpha
{
	gtk_gl_area_set_has_alpha([self GLAREA], hasAlpha);
}

- (void)setHasDepthBuffer:(bool)hasDepthBuffer
{
	gtk_gl_area_set_has_depth_buffer([self GLAREA], hasDepthBuffer);
}

- (void)setHasStencilBuffer:(bool)hasStencilBuffer
{
	gtk_gl_area_set_has_stencil_buffer([self GLAREA], hasStencilBuffer);
}

- (void)setRequiredVersionWithMajor:(gint)major minor:(gint)minor
{
	gtk_gl_area_set_required_version([self GLAREA], major, minor);
}

- (void)setUseEs:(bool)useEs
{
	gtk_gl_area_set_use_es([self GLAREA], useEs);
}


@end