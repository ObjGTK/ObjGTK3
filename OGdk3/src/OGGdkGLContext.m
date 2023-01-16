/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkGLContext.h"

#import "OGGdkDisplay.h"
#import "OGGdkWindow.h"

@implementation OGGdkGLContext

+ (void)clearCurrent
{
	gdk_gl_context_clear_current();
}

+ (OGGdkGLContext*)current
{
	return [[[OGGdkGLContext alloc] initWithGObject:(GObject*)gdk_gl_context_get_current()] autorelease];
}

- (GdkGLContext*)GLCONTEXT
{
	return GDK_GL_CONTEXT([self GOBJECT]);
}

- (bool)debugEnabled
{
	return gdk_gl_context_get_debug_enabled([self GLCONTEXT]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_gl_context_get_display([self GLCONTEXT])] autorelease];
}

- (bool)forwardCompatible
{
	return gdk_gl_context_get_forward_compatible([self GLCONTEXT]);
}

- (void)requiredVersionWithMajor:(int*)major minor:(int*)minor
{
	gdk_gl_context_get_required_version([self GLCONTEXT], major, minor);
}

- (OGGdkGLContext*)sharedContext
{
	return [[[OGGdkGLContext alloc] initWithGObject:(GObject*)gdk_gl_context_get_shared_context([self GLCONTEXT])] autorelease];
}

- (bool)useEs
{
	return gdk_gl_context_get_use_es([self GLCONTEXT]);
}

- (void)versionWithMajor:(int*)major minor:(int*)minor
{
	gdk_gl_context_get_version([self GLCONTEXT], major, minor);
}

- (OGGdkWindow*)window
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_gl_context_get_window([self GLCONTEXT])] autorelease];
}

- (bool)isLegacy
{
	return gdk_gl_context_is_legacy([self GLCONTEXT]);
}

- (void)makeCurrent
{
	gdk_gl_context_make_current([self GLCONTEXT]);
}

- (bool)realize:(GError**)err
{
	return gdk_gl_context_realize([self GLCONTEXT], err);
}

- (void)setDebugEnabled:(bool)enabled
{
	gdk_gl_context_set_debug_enabled([self GLCONTEXT], enabled);
}

- (void)setForwardCompatible:(bool)compatible
{
	gdk_gl_context_set_forward_compatible([self GLCONTEXT], compatible);
}

- (void)setRequiredVersionWithMajor:(int)major minor:(int)minor
{
	gdk_gl_context_set_required_version([self GLCONTEXT], major, minor);
}

- (void)setUseEs:(int)useEs
{
	gdk_gl_context_set_use_es([self GLCONTEXT], useEs);
}


@end