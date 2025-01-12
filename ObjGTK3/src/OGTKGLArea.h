/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

@class OGGdkGLContext;

/**
 * #GtkGLArea is a widget that allows drawing with OpenGL.
 * 
 * #GtkGLArea sets up its own #GdkGLContext for the window it creates, and
 * creates a custom GL framebuffer that the widget will do GL rendering onto.
 * It also ensures that this framebuffer is the default GL rendering target
 * when rendering.
 * 
 * In order to draw, you have to connect to the #GtkGLArea::render signal,
 * or subclass #GtkGLArea and override the @GtkGLAreaClass.render() virtual
 * function.
 * 
 * The #GtkGLArea widget ensures that the #GdkGLContext is associated with
 * the widget's drawing area, and it is kept updated when the size and
 * position of the drawing area changes.
 * 
 * ## Drawing with GtkGLArea ##
 * 
 * The simplest way to draw using OpenGL commands in a #GtkGLArea is to
 * create a widget instance and connect to the #GtkGLArea::render signal:
 * 
 * |[<!-- language="C" -->
 *   // create a GtkGLArea instance
 *   GtkWidget *gl_area = gtk_gl_area_new ();
 * 
 *   // connect to the "render" signal
 *   g_signal_connect (gl_area, "render", G_CALLBACK (render), NULL);
 * ]|
 * 
 * The `render()` function will be called when the #GtkGLArea is ready
 * for you to draw its content:
 * 
 * |[<!-- language="C" -->
 *   static gboolean
 *   render (GtkGLArea *area, GdkGLContext *context)
 *   {
 *     // inside this function it's safe to use GL; the given
 *     // #GdkGLContext has been made current to the drawable
 *     // surface used by the #GtkGLArea and the viewport has
 *     // already been set to be the size of the allocation
 * 
 *     // we can start by clearing the buffer
 *     glClearColor (0, 0, 0, 0);
 *     glClear (GL_COLOR_BUFFER_BIT);
 * 
 *     // draw your object
 *     draw_an_object ();
 * 
 *     // we completed our drawing; the draw commands will be
 *     // flushed at the end of the signal emission chain, and
 *     // the buffers will be drawn on the window
 *     return TRUE;
 *   }
 * ]|
 * 
 * If you need to initialize OpenGL state, e.g. buffer objects or
 * shaders, you should use the #GtkWidget::realize signal; you
 * can use the #GtkWidget::unrealize signal to clean up. Since the
 * #GdkGLContext creation and initialization may fail, you will
 * need to check for errors, using gtk_gl_area_get_error(). An example
 * of how to safely initialize the GL state is:
 * 
 * |[<!-- language="C" -->
 *   static void
 *   on_realize (GtkGLarea *area)
 *   {
 *     // We need to make the context current if we want to
 *     // call GL API
 *     gtk_gl_area_make_current (area);
 * 
 *     // If there were errors during the initialization or
 *     // when trying to make the context current, this
 *     // function will return a #GError for you to catch
 *     if (gtk_gl_area_get_error (area) != NULL)
 *       return;
 * 
 *     // You can also use gtk_gl_area_set_error() in order
 *     // to show eventual initialization errors on the
 *     // GtkGLArea widget itself
 *     GError *internal_error = NULL;
 *     init_buffer_objects (&error);
 *     if (error != NULL)
 *       {
 *         gtk_gl_area_set_error (area, error);
 *         g_error_free (error);
 *         return;
 *       }
 * 
 *     init_shaders (&error);
 *     if (error != NULL)
 *       {
 *         gtk_gl_area_set_error (area, error);
 *         g_error_free (error);
 *         return;
 *       }
 *   }
 * ]|
 * 
 * If you need to change the options for creating the #GdkGLContext
 * you should use the #GtkGLArea::create-context signal.
 *
 */
@interface OGTKGLArea : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkGLArea*)GLAREA;

/**
 * Ensures that the @area framebuffer object is made the current draw
 * and read target, and that all the required buffers for the @area
 * are created and bound to the frambuffer.
 * 
 * This function is automatically called before emitting the
 * #GtkGLArea::render signal, and doesn't normally need to be called
 * by application code.
 *
 */
- (void)attachBuffers;

/**
 * Returns whether the area is in auto render mode or not.
 *
 * @return %TRUE if the @area is auto rendering, %FALSE otherwise
 */
- (bool)autoRender;

/**
 * Retrieves the #GdkGLContext used by @area.
 *
 * @return the #GdkGLContext
 */
- (OGGdkGLContext*)context;

/**
 * Gets the current error set on the @area.
 *
 * @return the #GError or %NULL
 */
- (GError*)error;

/**
 * Returns whether the area has an alpha component.
 *
 * @return %TRUE if the @area has an alpha component, %FALSE otherwise
 */
- (bool)hasAlpha;

/**
 * Returns whether the area has a depth buffer.
 *
 * @return %TRUE if the @area has a depth buffer, %FALSE otherwise
 */
- (bool)hasDepthBuffer;

/**
 * Returns whether the area has a stencil buffer.
 *
 * @return %TRUE if the @area has a stencil buffer, %FALSE otherwise
 */
- (bool)hasStencilBuffer;

/**
 * Retrieves the required version of OpenGL set
 * using gtk_gl_area_set_required_version().
 *
 * @param major return location for the required major version
 * @param minor return location for the required minor version
 */
- (void)requiredVersionWithMajor:(gint*)major minor:(gint*)minor;

/**
 * Retrieves the value set by gtk_gl_area_set_use_es().
 *
 * @return %TRUE if the #GtkGLArea should create an OpenGL ES context
 *   and %FALSE otherwise
 */
- (bool)useEs;

/**
 * Ensures that the #GdkGLContext used by @area is associated with
 * the #GtkGLArea.
 * 
 * This function is automatically called before emitting the
 * #GtkGLArea::render signal, and doesn't normally need to be called
 * by application code.
 *
 */
- (void)makeCurrent;

/**
 * Marks the currently rendered data (if any) as invalid, and queues
 * a redraw of the widget, ensuring that the #GtkGLArea::render signal
 * is emitted during the draw.
 * 
 * This is only needed when the gtk_gl_area_set_auto_render() has
 * been called with a %FALSE value. The default behaviour is to
 * emit #GtkGLArea::render on each draw.
 *
 */
- (void)queueRender;

/**
 * If @auto_render is %TRUE the #GtkGLArea::render signal will be
 * emitted every time the widget draws. This is the default and is
 * useful if drawing the widget is faster.
 * 
 * If @auto_render is %FALSE the data from previous rendering is kept
 * around and will be used for drawing the widget the next time,
 * unless the window is resized. In order to force a rendering
 * gtk_gl_area_queue_render() must be called. This mode is useful when
 * the scene changes seldomly, but takes a long time to redraw.
 *
 * @param autoRender a boolean
 */
- (void)setAutoRender:(bool)autoRender;

/**
 * Sets an error on the area which will be shown instead of the
 * GL rendering. This is useful in the #GtkGLArea::create-context
 * signal if GL context creation fails.
 *
 * @param error a new #GError, or %NULL to unset the error
 */
- (void)setError:(const GError*)error;

/**
 * If @has_alpha is %TRUE the buffer allocated by the widget will have
 * an alpha channel component, and when rendering to the window the
 * result will be composited over whatever is below the widget.
 * 
 * If @has_alpha is %FALSE there will be no alpha channel, and the
 * buffer will fully replace anything below the widget.
 *
 * @param hasAlpha %TRUE to add an alpha component
 */
- (void)setHasAlpha:(bool)hasAlpha;

/**
 * If @has_depth_buffer is %TRUE the widget will allocate and
 * enable a depth buffer for the target framebuffer. Otherwise
 * there will be none.
 *
 * @param hasDepthBuffer %TRUE to add a depth buffer
 */
- (void)setHasDepthBuffer:(bool)hasDepthBuffer;

/**
 * If @has_stencil_buffer is %TRUE the widget will allocate and
 * enable a stencil buffer for the target framebuffer. Otherwise
 * there will be none.
 *
 * @param hasStencilBuffer %TRUE to add a stencil buffer
 */
- (void)setHasStencilBuffer:(bool)hasStencilBuffer;

/**
 * Sets the required version of OpenGL to be used when creating the context
 * for the widget.
 * 
 * This function must be called before the area has been realized.
 *
 * @param major the major version
 * @param minor the minor version
 */
- (void)setRequiredVersionWithMajor:(gint)major minor:(gint)minor;

/**
 * Sets whether the @area should create an OpenGL or an OpenGL ES context.
 * 
 * You should check the capabilities of the #GdkGLContext before drawing
 * with either API.
 *
 * @param useEs whether to use OpenGL or OpenGL ES
 */
- (void)setUseEs:(bool)useEs;

@end