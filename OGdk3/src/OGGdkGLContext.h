/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;
@class OGGdkDisplay;

/**
 * #GdkGLContext is an object representing the platform-specific
 * OpenGL drawing context.
 * 
 * #GdkGLContexts are created for a #GdkWindow using
 * gdk_window_create_gl_context(), and the context will match
 * the #GdkVisual of the window.
 * 
 * A #GdkGLContext is not tied to any particular normal framebuffer.
 * For instance, it cannot draw to the #GdkWindow back buffer. The GDK
 * repaint system is in full control of the painting to that. Instead,
 * you can create render buffers or textures and use gdk_cairo_draw_from_gl()
 * in the draw function of your widget to draw them. Then GDK will handle
 * the integration of your rendering with that of other widgets.
 * 
 * Support for #GdkGLContext is platform-specific, context creation
 * can fail, returning %NULL context.
 * 
 * A #GdkGLContext has to be made "current" in order to start using
 * it, otherwise any OpenGL call will be ignored.
 * 
 * ## Creating a new OpenGL context ##
 * 
 * In order to create a new #GdkGLContext instance you need a
 * #GdkWindow, which you typically get during the realize call
 * of a widget.
 * 
 * A #GdkGLContext is not realized until either gdk_gl_context_make_current(),
 * or until it is realized using gdk_gl_context_realize(). It is possible to
 * specify details of the GL context like the OpenGL version to be used, or
 * whether the GL context should have extra state validation enabled after
 * calling gdk_window_create_gl_context() by calling gdk_gl_context_realize().
 * If the realization fails you have the option to change the settings of the
 * #GdkGLContext and try again.
 * 
 * ## Using a GdkGLContext ##
 * 
 * You will need to make the #GdkGLContext the current context
 * before issuing OpenGL calls; the system sends OpenGL commands to
 * whichever context is current. It is possible to have multiple
 * contexts, so you always need to ensure that the one which you
 * want to draw with is the current one before issuing commands:
 * 
 * |[<!-- language="C" -->
 *   gdk_gl_context_make_current (context);
 * ]|
 * 
 * You can now perform your drawing using OpenGL commands.
 * 
 * You can check which #GdkGLContext is the current one by using
 * gdk_gl_context_get_current(); you can also unset any #GdkGLContext
 * that is currently set by calling gdk_gl_context_clear_current().
 *
 */
@interface OGGdkGLContext : OGObject
{

}

/**
 * Functions
 */
+ (void)clearCurrent;
+ (OGGdkGLContext*)current;

/**
 * Methods
 */

- (GdkGLContext*)GLCONTEXT;

/**
 * Retrieves the value set using gdk_gl_context_set_debug_enabled().
 *
 * @return %TRUE if debugging is enabled
 */
- (bool)debugEnabled;

/**
 * Retrieves the #GdkDisplay the @context is created for
 *
 * @return a #GdkDisplay or %NULL
 */
- (OGGdkDisplay*)display;

/**
 * Retrieves the value set using gdk_gl_context_set_forward_compatible().
 *
 * @return %TRUE if the context should be forward compatible
 */
- (bool)forwardCompatible;

/**
 * Retrieves the major and minor version requested by calling
 * gdk_gl_context_set_required_version().
 *
 * @param major return location for the major version to request
 * @param minor return location for the minor version to request
 */
- (void)requiredVersionWithMajor:(int*)major minor:(int*)minor;

/**
 * Retrieves the #GdkGLContext that this @context share data with.
 *
 * @return a #GdkGLContext or %NULL
 */
- (OGGdkGLContext*)sharedContext;

/**
 * Checks whether the @context is using an OpenGL or OpenGL ES profile.
 *
 * @return %TRUE if the #GdkGLContext is using an OpenGL ES profile
 */
- (bool)useEs;

/**
 * Retrieves the OpenGL version of the @context.
 * 
 * The @context must be realized prior to calling this function.
 *
 * @param major return location for the major version
 * @param minor return location for the minor version
 */
- (void)versionWithMajor:(int*)major minor:(int*)minor;

/**
 * Retrieves the #GdkWindow used by the @context.
 *
 * @return a #GdkWindow or %NULL
 */
- (OGGdkWindow*)window;

/**
 * Whether the #GdkGLContext is in legacy mode or not.
 * 
 * The #GdkGLContext must be realized before calling this function.
 * 
 * When realizing a GL context, GDK will try to use the OpenGL 3.2 core
 * profile; this profile removes all the OpenGL API that was deprecated
 * prior to the 3.2 version of the specification. If the realization is
 * successful, this function will return %FALSE.
 * 
 * If the underlying OpenGL implementation does not support core profiles,
 * GDK will fall back to a pre-3.2 compatibility profile, and this function
 * will return %TRUE.
 * 
 * You can use the value returned by this function to decide which kind
 * of OpenGL API to use, or whether to do extension discovery, or what
 * kind of shader programs to load.
 *
 * @return %TRUE if the GL context is in legacy mode
 */
- (bool)isLegacy;

/**
 * Makes the @context the current one.
 *
 */
- (void)makeCurrent;

/**
 * Realizes the given #GdkGLContext.
 * 
 * It is safe to call this function on a realized #GdkGLContext.
 *
 * @param err
 * @return %TRUE if the context is realized
 */
- (bool)realize:(GError**)err;

/**
 * Sets whether the #GdkGLContext should perform extra validations and
 * run time checking. This is useful during development, but has
 * additional overhead.
 * 
 * The #GdkGLContext must not be realized or made current prior to
 * calling this function.
 *
 * @param enabled whether to enable debugging in the context
 */
- (void)setDebugEnabled:(bool)enabled;

/**
 * Sets whether the #GdkGLContext should be forward compatible.
 * 
 * Forward compatibile contexts must not support OpenGL functionality that
 * has been marked as deprecated in the requested version; non-forward
 * compatible contexts, on the other hand, must support both deprecated and
 * non deprecated functionality.
 * 
 * The #GdkGLContext must not be realized or made current prior to calling
 * this function.
 *
 * @param compatible whether the context should be forward compatible
 */
- (void)setForwardCompatible:(bool)compatible;

/**
 * Sets the major and minor version of OpenGL to request.
 * 
 * Setting @major and @minor to zero will use the default values.
 * 
 * The #GdkGLContext must not be realized or made current prior to calling
 * this function.
 *
 * @param major the major version to request
 * @param minor the minor version to request
 */
- (void)setRequiredVersionWithMajor:(int)major minor:(int)minor;

/**
 * Requests that GDK create a OpenGL ES context instead of an OpenGL one,
 * if the platform and windowing system allows it.
 * 
 * The @context must not have been realized.
 * 
 * By default, GDK will attempt to automatically detect whether the
 * underlying GL implementation is OpenGL or OpenGL ES once the @context
 * is realized.
 * 
 * You should check the return value of gdk_gl_context_get_use_es() after
 * calling gdk_gl_context_realize() to decide whether to use the OpenGL or
 * OpenGL ES API, extensions, or shaders.
 *
 * @param useEs whether the context should use OpenGL ES instead of OpenGL,
 *   or -1 to allow auto-detection
 */
- (void)setUseEs:(int)useEs;

@end