/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkVisual;
@class OGGdkDisplay;
@class OGGdkScreen;
@class OGGdkGLContext;
@class OGGdkDrawingContext;
@class OGGdkDevice;
@class OGGdkCursor;
@class OGGdkFrameClock;

@interface OGGdkWindow : OGObject
{

}

/**
 * Functions
 */

/**
 * Obtains the window underneath the mouse pointer, returning the
 * location of that window in @win_x, @win_y. Returns %NULL if the
 * window under the mouse pointer is not known to GDK (if the window
 * belongs to another application and a #GdkWindow hasn’t been created
 * for it with gdk_window_foreign_new())
 * 
 * NOTE: For multihead-aware widgets or applications use
 * gdk_display_get_window_at_pointer() instead.
 *
 * @param winX return location for origin of the window under the pointer
 * @param winY return location for origin of the window under the pointer
 * @return window under the mouse pointer
 */
+ (OGGdkWindow*)atPointerWithWinX:(gint*)winX winY:(gint*)winY;

/**
 * Constrains a desired width and height according to a
 * set of geometry hints (such as minimum and maximum size).
 *
 * @param geometry a #GdkGeometry structure
 * @param flags a mask indicating what portions of @geometry are set
 * @param width desired width of window
 * @param height desired height of the window
 * @param newWidth location to store resulting width
 * @param newHeight location to store resulting height
 */
+ (void)constrainSizeWithGeometry:(GdkGeometry*)geometry flags:(GdkWindowHints)flags width:(gint)width height:(gint)height newWidth:(gint*)newWidth newHeight:(gint*)newHeight;

/**
 * Calls gdk_window_process_updates() for all windows (see #GdkWindow)
 * in the application.
 *
 */
+ (void)processAllUpdates;

/**
 * With update debugging enabled, calls to
 * gdk_window_invalidate_region() clear the invalidated region of the
 * screen to a noticeable color, and GDK pauses for a short time
 * before sending exposes to windows during
 * gdk_window_process_updates().  The net effect is that you can see
 * the invalid region for each window and watch redraws as they
 * occur. This allows you to diagnose inefficiencies in your application.
 * 
 * In essence, because the GDK rendering model prevents all flicker,
 * if you are redrawing the same region 400 times you may never
 * notice, aside from noticing a speed problem. Enabling update
 * debugging causes GTK to flicker slowly and noticeably, so you can
 * see exactly what’s being redrawn when, in what order.
 * 
 * The --gtk-debug=updates command line option passed to GTK+ programs
 * enables this debug option at application startup time. That's
 * usually more useful than calling gdk_window_set_debug_updates()
 * yourself, though you might want to use this function to enable
 * updates sometime after application startup time.
 *
 * @param setting %TRUE to turn on update debugging
 */
+ (void)setDebugUpdates:(bool)setting;

/**
 * Constructors
 */
- (instancetype)initWithParent:(OGGdkWindow*)parent attributes:(GdkWindowAttr*)attributes attributesMask:(gint)attributesMask;

/**
 * Methods
 */

- (GdkWindow*)WINDOW;

/**
 * Adds an event filter to @window, allowing you to intercept events
 * before they reach GDK. This is a low-level operation and makes it
 * easy to break GDK and/or GTK+, so you have to know what you're
 * doing. Pass %NULL for @window to get all events for all windows,
 * instead of events for a specific window.
 * 
 * If you are interested in X GenericEvents, bear in mind that
 * XGetEventData() has been already called on the event, and
 * XFreeEventData() must not be called within @function.
 *
 * @param function filter callback
 * @param data data to pass to filter callback
 */
- (void)addFilterWithFunction:(GdkFilterFunc)function data:(gpointer)data;

/**
 * Emits a short beep associated to @window in the appropriate
 * display, if supported. Otherwise, emits a short beep on
 * the display just as gdk_display_beep().
 *
 */
- (void)beep;

/**
 * Indicates that you are beginning the process of redrawing @region
 * on @window, and provides you with a #GdkDrawingContext.
 * 
 * If @window is a top level #GdkWindow, backed by a native window
 * implementation, a backing store (offscreen buffer) large enough to
 * contain @region will be created. The backing store will be initialized
 * with the background color or background surface for @window. Then, all
 * drawing operations performed on @window will be diverted to the
 * backing store. When you call gdk_window_end_frame(), the contents of
 * the backing store will be copied to @window, making it visible
 * on screen. Only the part of @window contained in @region will be
 * modified; that is, drawing operations are clipped to @region.
 * 
 * The net result of all this is to remove flicker, because the user
 * sees the finished product appear all at once when you call
 * gdk_window_end_draw_frame(). If you draw to @window directly without
 * calling gdk_window_begin_draw_frame(), the user may see flicker
 * as individual drawing operations are performed in sequence.
 * 
 * When using GTK+, the widget system automatically places calls to
 * gdk_window_begin_draw_frame() and gdk_window_end_draw_frame() around
 * emissions of the `GtkWidget::draw` signal. That is, if you’re
 * drawing the contents of the widget yourself, you can assume that the
 * widget has a cleared background, is already set as the clip region,
 * and already has a backing store. Therefore in most cases, application
 * code in GTK does not need to call gdk_window_begin_draw_frame()
 * explicitly.
 *
 * @param region a Cairo region
 * @return a #GdkDrawingContext context that should be
 *   used to draw the contents of the window; the returned context is owned
 *   by GDK.
 */
- (OGGdkDrawingContext*)beginDrawFrame:(const cairo_region_t*)region;

/**
 * Begins a window move operation (for a toplevel window).
 * 
 * This function assumes that the drag is controlled by the
 * client pointer device, use gdk_window_begin_move_drag_for_device()
 * to begin a drag with a different device.
 *
 * @param button the button being used to drag, or 0 for a keyboard-initiated drag
 * @param rootX root window X coordinate of mouse click that began the drag
 * @param rootY root window Y coordinate of mouse click that began the drag
 * @param timestamp timestamp of mouse click that began the drag
 */
- (void)beginMoveDragWithButton:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp;

/**
 * Begins a window move operation (for a toplevel window).
 * You might use this function to implement a “window move grip,” for
 * example. The function works best with window managers that support the
 * [Extended Window Manager Hints](http://www.freedesktop.org/Standards/wm-spec)
 * but has a fallback implementation for other window managers.
 *
 * @param device the device used for the operation
 * @param button the button being used to drag, or 0 for a keyboard-initiated drag
 * @param rootX root window X coordinate of mouse click that began the drag
 * @param rootY root window Y coordinate of mouse click that began the drag
 * @param timestamp timestamp of mouse click that began the drag
 */
- (void)beginMoveDragForDeviceWithDevice:(OGGdkDevice*)device button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp;

/**
 * A convenience wrapper around gdk_window_begin_paint_region() which
 * creates a rectangular region for you. See
 * gdk_window_begin_paint_region() for details.
 *
 * @param rectangle rectangle you intend to draw to
 */
- (void)beginPaintRect:(const GdkRectangle*)rectangle;

/**
 * Indicates that you are beginning the process of redrawing @region.
 * A backing store (offscreen buffer) large enough to contain @region
 * will be created. The backing store will be initialized with the
 * background color or background surface for @window. Then, all
 * drawing operations performed on @window will be diverted to the
 * backing store.  When you call gdk_window_end_paint(), the backing
 * store will be copied to @window, making it visible onscreen. Only
 * the part of @window contained in @region will be modified; that is,
 * drawing operations are clipped to @region.
 * 
 * The net result of all this is to remove flicker, because the user
 * sees the finished product appear all at once when you call
 * gdk_window_end_paint(). If you draw to @window directly without
 * calling gdk_window_begin_paint_region(), the user may see flicker
 * as individual drawing operations are performed in sequence.  The
 * clipping and background-initializing features of
 * gdk_window_begin_paint_region() are conveniences for the
 * programmer, so you can avoid doing that work yourself.
 * 
 * When using GTK+, the widget system automatically places calls to
 * gdk_window_begin_paint_region() and gdk_window_end_paint() around
 * emissions of the expose_event signal. That is, if you’re writing an
 * expose event handler, you can assume that the exposed area in
 * #GdkEventExpose has already been cleared to the window background,
 * is already set as the clip region, and already has a backing store.
 * Therefore in most cases, application code need not call
 * gdk_window_begin_paint_region(). (You can disable the automatic
 * calls around expose events on a widget-by-widget basis by calling
 * gtk_widget_set_double_buffered().)
 * 
 * If you call this function multiple times before calling the
 * matching gdk_window_end_paint(), the backing stores are pushed onto
 * a stack. gdk_window_end_paint() copies the topmost backing store
 * onscreen, subtracts the topmost region from all other regions in
 * the stack, and pops the stack. All drawing operations affect only
 * the topmost backing store in the stack. One matching call to
 * gdk_window_end_paint() is required for each call to
 * gdk_window_begin_paint_region().
 *
 * @param region region you intend to draw to
 */
- (void)beginPaintRegion:(const cairo_region_t*)region;

/**
 * Begins a window resize operation (for a toplevel window).
 * 
 * This function assumes that the drag is controlled by the
 * client pointer device, use gdk_window_begin_resize_drag_for_device()
 * to begin a drag with a different device.
 *
 * @param edge the edge or corner from which the drag is started
 * @param button the button being used to drag, or 0 for a keyboard-initiated drag
 * @param rootX root window X coordinate of mouse click that began the drag
 * @param rootY root window Y coordinate of mouse click that began the drag
 * @param timestamp timestamp of mouse click that began the drag (use gdk_event_get_time())
 */
- (void)beginResizeDragWithEdge:(GdkWindowEdge)edge button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp;

/**
 * Begins a window resize operation (for a toplevel window).
 * You might use this function to implement a “window resize grip,” for
 * example; in fact #GtkStatusbar uses it. The function works best
 * with window managers that support the
 * [Extended Window Manager Hints](http://www.freedesktop.org/Standards/wm-spec)
 * but has a fallback implementation for other window managers.
 *
 * @param edge the edge or corner from which the drag is started
 * @param device the device used for the operation
 * @param button the button being used to drag, or 0 for a keyboard-initiated drag
 * @param rootX root window X coordinate of mouse click that began the drag
 * @param rootY root window Y coordinate of mouse click that began the drag
 * @param timestamp timestamp of mouse click that began the drag (use gdk_event_get_time())
 */
- (void)beginResizeDragForDeviceWithEdge:(GdkWindowEdge)edge device:(OGGdkDevice*)device button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp;

/**
 * Does nothing, present only for compatiblity.
 *
 */
- (void)configureFinished;

/**
 * Transforms window coordinates from a parent window to a child
 * window, where the parent window is the normal parent as returned by
 * gdk_window_get_parent() for normal windows, and the window's
 * embedder as returned by gdk_offscreen_window_get_embedder() for
 * offscreen windows.
 * 
 * For normal windows, calling this function is equivalent to subtracting
 * the return values of gdk_window_get_position() from the parent coordinates.
 * For offscreen windows however (which can be arbitrarily transformed),
 * this function calls the GdkWindow::from-embedder: signal to translate
 * the coordinates.
 * 
 * You should always use this function when writing generic code that
 * walks down a window hierarchy.
 * 
 * See also: gdk_window_coords_to_parent()
 *
 * @param parentX X coordinate in parent’s coordinate system
 * @param parentY Y coordinate in parent’s coordinate system
 * @param x return location for X coordinate in child’s coordinate system
 * @param y return location for Y coordinate in child’s coordinate system
 */
- (void)coordsFromParentWithParentX:(gdouble)parentX parentY:(gdouble)parentY x:(gdouble*)x y:(gdouble*)y;

/**
 * Transforms window coordinates from a child window to its parent
 * window, where the parent window is the normal parent as returned by
 * gdk_window_get_parent() for normal windows, and the window's
 * embedder as returned by gdk_offscreen_window_get_embedder() for
 * offscreen windows.
 * 
 * For normal windows, calling this function is equivalent to adding
 * the return values of gdk_window_get_position() to the child coordinates.
 * For offscreen windows however (which can be arbitrarily transformed),
 * this function calls the GdkWindow::to-embedder: signal to translate
 * the coordinates.
 * 
 * You should always use this function when writing generic code that
 * walks up a window hierarchy.
 * 
 * See also: gdk_window_coords_from_parent()
 *
 * @param x X coordinate in child’s coordinate system
 * @param y Y coordinate in child’s coordinate system
 * @param parentX return location for X coordinate
 * in parent’s coordinate system, or %NULL
 * @param parentY return location for Y coordinate
 * in parent’s coordinate system, or %NULL
 */
- (void)coordsToParentWithX:(gdouble)x y:(gdouble)y parentX:(gdouble*)parentX parentY:(gdouble*)parentY;

/**
 * Creates a new #GdkGLContext matching the
 * framebuffer format to the visual of the #GdkWindow. The context
 * is disconnected from any particular window or surface.
 * 
 * If the creation of the #GdkGLContext failed, @error will be set.
 * 
 * Before using the returned #GdkGLContext, you will need to
 * call gdk_gl_context_make_current() or gdk_gl_context_realize().
 *
 * @param err
 * @return the newly created #GdkGLContext, or
 * %NULL on error
 */
- (OGGdkGLContext*)createGlContext:(GError**)err;

/**
 * Create a new image surface that is efficient to draw on the
 * given @window.
 * 
 * Initially the surface contents are all 0 (transparent if contents
 * have transparency, black otherwise.)
 * 
 * The @width and @height of the new surface are not affected by
 * the scaling factor of the @window, or by the @scale argument; they
 * are the size of the surface in device pixels. If you wish to create
 * an image surface capable of holding the contents of @window you can
 * use:
 * 
 * |[<!-- language="C" -->
 *   int scale = gdk_window_get_scale_factor (window);
 *   int width = gdk_window_get_width (window) * scale;
 *   int height = gdk_window_get_height (window) * scale;
 * 
 *   // format is set elsewhere
 *   cairo_surface_t *surface =
 *     gdk_window_create_similar_image_surface (window,
 *                                              format,
 *                                              width, height,
 *                                              scale);
 * ]|
 * 
 * Note that unlike cairo_surface_create_similar_image(), the new
 * surface's device scale is set to @scale, or to the scale factor of
 * @window if @scale is 0.
 *
 * @param format the format for the new surface
 * @param width width of the new surface
 * @param height height of the new surface
 * @param scale the scale of the new surface, or 0 to use same as @window
 * @return a pointer to the newly allocated surface. The caller
 * owns the surface and should call cairo_surface_destroy() when done
 * with it.
 * 
 * This function always returns a valid pointer, but it will return a
 * pointer to a “nil” surface if @other is already in an error state
 * or any other error occurs.
 */
- (cairo_surface_t*)createSimilarImageSurfaceWithFormat:(cairo_format_t)format width:(int)width height:(int)height scale:(int)scale;

/**
 * Create a new surface that is as compatible as possible with the
 * given @window. For example the new surface will have the same
 * fallback resolution and font options as @window. Generally, the new
 * surface will also use the same backend as @window, unless that is
 * not possible for some reason. The type of the returned surface may
 * be examined with cairo_surface_get_type().
 * 
 * Initially the surface contents are all 0 (transparent if contents
 * have transparency, black otherwise.)
 *
 * @param content the content for the new surface
 * @param width width of the new surface
 * @param height height of the new surface
 * @return a pointer to the newly allocated surface. The caller
 * owns the surface and should call cairo_surface_destroy() when done
 * with it.
 * 
 * This function always returns a valid pointer, but it will return a
 * pointer to a “nil” surface if @other is already in an error state
 * or any other error occurs.
 */
- (cairo_surface_t*)createSimilarSurfaceWithContent:(cairo_content_t)content width:(int)width height:(int)height;

/**
 * Attempt to deiconify (unminimize) @window. On X11 the window manager may
 * choose to ignore the request to deiconify. When using GTK+,
 * use gtk_window_deiconify() instead of the #GdkWindow variant. Or better yet,
 * you probably want to use gtk_window_present_with_time(), which raises the window, focuses it,
 * unminimizes it, and puts it on the current desktop.
 *
 */
- (void)deiconify;

/**
 * Destroys the window system resources associated with @window and decrements @window's
 * reference count. The window system resources for all children of @window are also
 * destroyed, but the children’s reference counts are not decremented.
 * 
 * Note that a window will not be destroyed automatically when its reference count
 * reaches zero. You must call this function yourself before that happens.
 *
 */
- (void)destroy;

/**
 * Does nothing, present only for compatiblity.
 *
 */
- (void)enableSynchronizedConfigure;

/**
 * Indicates that the drawing of the contents of @window started with
 * gdk_window_begin_frame() has been completed.
 * 
 * This function will take care of destroying the #GdkDrawingContext.
 * 
 * It is an error to call this function without a matching
 * gdk_window_begin_frame() first.
 *
 * @param context the #GdkDrawingContext created by gdk_window_begin_draw_frame()
 */
- (void)endDrawFrame:(OGGdkDrawingContext*)context;

/**
 * Indicates that the backing store created by the most recent call
 * to gdk_window_begin_paint_region() should be copied onscreen and
 * deleted, leaving the next-most-recent backing store or no backing
 * store at all as the active paint region. See
 * gdk_window_begin_paint_region() for full details.
 * 
 * It is an error to call this function without a matching
 * gdk_window_begin_paint_region() first.
 *
 */
- (void)endPaint;

/**
 * Tries to ensure that there is a window-system native window for this
 * GdkWindow. This may fail in some situations, returning %FALSE.
 * 
 * Offscreen window and children of them can never have native windows.
 * 
 * Some backends may not support native child windows.
 *
 * @return %TRUE if the window has a native window, %FALSE otherwise
 */
- (bool)ensureNative;

/**
 * This function does nothing.
 *
 */
- (void)flush;

/**
 * Sets keyboard focus to @window. In most cases, gtk_window_present_with_time()
 * should be used on a #GtkWindow, rather than calling this function.
 *
 * @param timestamp timestamp of the event triggering the window focus
 */
- (void)focus:(guint32)timestamp;

/**
 * Temporarily freezes a window and all its descendants such that it won't
 * receive expose events.  The window will begin receiving expose events
 * again when gdk_window_thaw_toplevel_updates_libgtk_only() is called. If
 * gdk_window_freeze_toplevel_updates_libgtk_only()
 * has been called more than once,
 * gdk_window_thaw_toplevel_updates_libgtk_only() must be called
 * an equal number of times to begin processing exposes.
 * 
 * This function is not part of the GDK public API and is only
 * for use by GTK+.
 *
 */
- (void)freezeToplevelUpdatesLibgtkOnly;

/**
 * Temporarily freezes a window such that it won’t receive expose
 * events.  The window will begin receiving expose events again when
 * gdk_window_thaw_updates() is called. If gdk_window_freeze_updates()
 * has been called more than once, gdk_window_thaw_updates() must be called
 * an equal number of times to begin processing exposes.
 *
 */
- (void)freezeUpdates;

/**
 * Moves the window into fullscreen mode. This means the
 * window covers the entire screen and is above any panels
 * or task bars.
 * 
 * If the window was already fullscreen, then this function does nothing.
 * 
 * On X11, asks the window manager to put @window in a fullscreen
 * state, if the window manager supports this operation. Not all
 * window managers support this, and some deliberately ignore it or
 * don’t have a concept of “fullscreen”; so you can’t rely on the
 * fullscreenification actually happening. But it will happen with
 * most standard window managers, and GDK makes a best effort to get
 * it to happen.
 *
 */
- (void)fullscreen;

/**
 * Moves the window into fullscreen mode on the given monitor. This means
 * the window covers the entire screen and is above any panels or task bars.
 * 
 * If the window was already fullscreen, then this function does nothing.
 *
 * @param monitor Which monitor to display fullscreen on.
 */
- (void)fullscreenOnMonitor:(gint)monitor;

/**
 * This function informs GDK that the geometry of an embedded
 * offscreen window has changed. This is necessary for GDK to keep
 * track of which offscreen window the pointer is in.
 *
 */
- (void)geometryChanged;

/**
 * Determines whether or not the desktop environment shuld be hinted that
 * the window does not want to receive input focus.
 *
 * @return whether or not the window should receive input focus.
 */
- (bool)acceptFocus;

/**
 * Gets the pattern used to clear the background on @window.
 *
 * @return The pattern to use for the
 * background or %NULL if there is no background.
 */
- (cairo_pattern_t*)backgroundPattern;

/**
 * Gets the list of children of @window known to GDK.
 * This function only returns children created via GDK,
 * so for example it’s useless when used with the root window;
 * it only returns windows an application created itself.
 * 
 * The returned list must be freed, but the elements in the
 * list need not be.
 *
 * @return list of child windows inside @window
 */
- (GList*)children;

/**
 * Gets the list of children of @window known to GDK with a
 * particular @user_data set on it.
 * 
 * The returned list must be freed, but the elements in the
 * list need not be.
 * 
 * The list is returned in (relative) stacking order, i.e. the
 * lowest window is first.
 *
 * @param userData user data to look for
 * @return list of child windows inside @window
 */
- (GList*)childrenWithUserData:(gpointer)userData;

/**
 * Computes the region of a window that potentially can be written
 * to by drawing primitives. This region may not take into account
 * other factors such as if the window is obscured by other windows,
 * but no area outside of this region will be affected by drawing
 * primitives.
 *
 * @return a #cairo_region_t. This must be freed with cairo_region_destroy()
 *          when you are done.
 */
- (cairo_region_t*)clipRegion;

/**
 * Determines whether @window is composited.
 * 
 * See gdk_window_set_composited().
 *
 * @return %TRUE if the window is composited.
 */
- (bool)composited;

/**
 * Retrieves a #GdkCursor pointer for the cursor currently set on the
 * specified #GdkWindow, or %NULL.  If the return value is %NULL then
 * there is no custom cursor set on the specified window, and it is
 * using the cursor for its parent window.
 *
 * @return a #GdkCursor, or %NULL. The
 *   returned object is owned by the #GdkWindow and should not be
 *   unreferenced directly. Use gdk_window_set_cursor() to unset the
 *   cursor of the window
 */
- (OGGdkCursor*)cursor;

/**
 * Returns the decorations set on the GdkWindow with
 * gdk_window_set_decorations().
 *
 * @param decorations The window decorations will be written here
 * @return %TRUE if the window has decorations set, %FALSE otherwise.
 */
- (bool)decorations:(GdkWMDecoration*)decorations;

/**
 * Retrieves a #GdkCursor pointer for the @device currently set on the
 * specified #GdkWindow, or %NULL.  If the return value is %NULL then
 * there is no custom cursor set on the specified window, and it is
 * using the cursor for its parent window.
 *
 * @param device a master, pointer #GdkDevice.
 * @return a #GdkCursor, or %NULL. The
 *   returned object is owned by the #GdkWindow and should not be
 *   unreferenced directly. Use gdk_window_set_cursor() to unset the
 *   cursor of the window
 */
- (OGGdkCursor*)deviceCursor:(OGGdkDevice*)device;

/**
 * Returns the event mask for @window corresponding to an specific device.
 *
 * @param device a #GdkDevice.
 * @return device event mask for @window
 */
- (GdkEventMask)deviceEvents:(OGGdkDevice*)device;

/**
 * Obtains the current device position and modifier state.
 * The position is given in coordinates relative to the upper left
 * corner of @window.
 * 
 * Use gdk_window_get_device_position_double() if you need subpixel precision.
 *
 * @param device pointer #GdkDevice to query to.
 * @param x return location for the X coordinate of @device, or %NULL.
 * @param y return location for the Y coordinate of @device, or %NULL.
 * @param mask return location for the modifier mask, or %NULL.
 * @return The window underneath @device
 * (as with gdk_device_get_window_at_position()), or %NULL if the
 * window is not known to GDK.
 */
- (OGGdkWindow*)devicePositionWithDevice:(OGGdkDevice*)device x:(gint*)x y:(gint*)y mask:(GdkModifierType*)mask;

/**
 * Obtains the current device position in doubles and modifier state.
 * The position is given in coordinates relative to the upper left
 * corner of @window.
 *
 * @param device pointer #GdkDevice to query to.
 * @param x return location for the X coordinate of @device, or %NULL.
 * @param y return location for the Y coordinate of @device, or %NULL.
 * @param mask return location for the modifier mask, or %NULL.
 * @return The window underneath @device
 * (as with gdk_device_get_window_at_position()), or %NULL if the
 * window is not known to GDK.
 */
- (OGGdkWindow*)devicePositionDoubleWithDevice:(OGGdkDevice*)device x:(gdouble*)x y:(gdouble*)y mask:(GdkModifierType*)mask;

/**
 * Gets the #GdkDisplay associated with a #GdkWindow.
 *
 * @return the #GdkDisplay associated with @window
 */
- (OGGdkDisplay*)display;

/**
 * Finds out the DND protocol supported by a window.
 *
 * @param target location of the window
 *    where the drop should happen. This may be @window or a proxy window,
 *    or %NULL if @window does not support Drag and Drop.
 * @return the supported DND protocol.
 */
- (GdkDragProtocol)dragProtocol:(GdkWindow**)target;

/**
 * Obtains the parent of @window, as known to GDK. Works like
 * gdk_window_get_parent() for normal windows, but returns the
 * window’s embedder for offscreen windows.
 * 
 * See also: gdk_offscreen_window_get_embedder()
 *
 * @return effective parent of @window
 */
- (OGGdkWindow*)effectiveParent;

/**
 * Gets the toplevel window that’s an ancestor of @window.
 * 
 * Works like gdk_window_get_toplevel(), but treats an offscreen window's
 * embedder as its parent, using gdk_window_get_effective_parent().
 * 
 * See also: gdk_offscreen_window_get_embedder()
 *
 * @return the effective toplevel window containing @window
 */
- (OGGdkWindow*)effectiveToplevel;

/**
 * Get the current event compression setting for this window.
 *
 * @return %TRUE if motion events will be compressed
 */
- (bool)eventCompression;

/**
 * Gets the event mask for @window for all master input devices. See
 * gdk_window_set_events().
 *
 * @return event mask for @window
 */
- (GdkEventMask)events;

/**
 * Determines whether or not the desktop environment should be hinted that the
 * window does not want to receive input focus when it is mapped.
 *
 * @return whether or not the window wants to receive input focus when
 * it is mapped.
 */
- (bool)focusOnMap;

/**
 * Gets the frame clock for the window. The frame clock for a window
 * never changes unless the window is reparented to a new toplevel
 * window.
 *
 * @return the frame clock
 */
- (OGGdkFrameClock*)frameClock;

/**
 * Obtains the bounding box of the window, including window manager
 * titlebar/borders if any. The frame position is given in root window
 * coordinates. To get the position of the window itself (rather than
 * the frame) in root window coordinates, use gdk_window_get_origin().
 *
 * @param rect rectangle to fill with bounding box of the window frame
 */
- (void)frameExtents:(GdkRectangle*)rect;

/**
 * Obtains the #GdkFullscreenMode of the @window.
 *
 * @return The #GdkFullscreenMode applied to the window when fullscreen.
 */
- (GdkFullscreenMode)fullscreenMode;

/**
 * Any of the return location arguments to this function may be %NULL,
 * if you aren’t interested in getting the value of that field.
 * 
 * The X and Y coordinates returned are relative to the parent window
 * of @window, which for toplevels usually means relative to the
 * window decorations (titlebar, etc.) rather than relative to the
 * root window (screen-size background window).
 * 
 * On the X11 platform, the geometry is obtained from the X server,
 * so reflects the latest position of @window; this may be out-of-sync
 * with the position of @window delivered in the most-recently-processed
 * #GdkEventConfigure. gdk_window_get_position() in contrast gets the
 * position from the most recent configure event.
 * 
 * Note: If @window is not a toplevel, it is much better
 * to call gdk_window_get_position(), gdk_window_get_width() and
 * gdk_window_get_height() instead, because it avoids the roundtrip to
 * the X server and because these functions support the full 32-bit
 * coordinate space, whereas gdk_window_get_geometry() is restricted to
 * the 16-bit coordinates of X11.
 *
 * @param x return location for X coordinate of window (relative to its parent)
 * @param y return location for Y coordinate of window (relative to its parent)
 * @param width return location for width of window
 * @param height return location for height of window
 */
- (void)geometryWithX:(gint*)x y:(gint*)y width:(gint*)width height:(gint*)height;

/**
 * Returns the group leader window for @window. See gdk_window_set_group().
 *
 * @return the group leader window for @window
 */
- (OGGdkWindow*)group;

/**
 * Returns the height of the given @window.
 * 
 * On the X11 platform the returned size is the size reported in the
 * most-recently-processed configure event, rather than the current
 * size on the X server.
 *
 * @return The height of @window
 */
- (int)height;

/**
 * Determines whether or not the window manager is hinted that @window
 * has modal behaviour.
 *
 * @return whether or not the window has the modal hint set.
 */
- (bool)modalHint;

/**
 * Obtains the position of a window in root window coordinates.
 * (Compare with gdk_window_get_position() and
 * gdk_window_get_geometry() which return the position of a window
 * relative to its parent window.)
 *
 * @param x return location for X coordinate
 * @param y return location for Y coordinate
 * @return not meaningful, ignore
 */
- (gint)originWithX:(gint*)x y:(gint*)y;

/**
 * Obtains the parent of @window, as known to GDK. Does not query the
 * X server; thus this returns the parent as passed to gdk_window_new(),
 * not the actual parent. This should never matter unless you’re using
 * Xlib calls mixed with GDK calls on the X11 platform. It may also
 * matter for toplevel windows, because the window manager may choose
 * to reparent them.
 * 
 * Note that you should use gdk_window_get_effective_parent() when
 * writing generic code that walks up a window hierarchy, because
 * gdk_window_get_parent() will most likely not do what you expect if
 * there are offscreen windows in the hierarchy.
 *
 * @return parent of @window
 */
- (OGGdkWindow*)parent;

/**
 * Returns whether input to the window is passed through to the window
 * below.
 * 
 * See gdk_window_set_pass_through() for details
 *
 * @return
 */
- (bool)passThrough;

/**
 * Obtains the current pointer position and modifier state.
 * The position is given in coordinates relative to the upper left
 * corner of @window.
 *
 * @param x return location for X coordinate of pointer or %NULL to not
 *      return the X coordinate
 * @param y return location for Y coordinate of pointer or %NULL to not
 *      return the Y coordinate
 * @param mask return location for modifier mask or %NULL to not return the
 *      modifier mask
 * @return the window containing the
 * pointer (as with gdk_window_at_pointer()), or %NULL if the window
 * containing the pointer isn’t known to GDK
 */
- (OGGdkWindow*)pointerWithX:(gint*)x y:(gint*)y mask:(GdkModifierType*)mask;

/**
 * Obtains the position of the window as reported in the
 * most-recently-processed #GdkEventConfigure. Contrast with
 * gdk_window_get_geometry() which queries the X server for the
 * current window position, regardless of which events have been
 * received or processed.
 * 
 * The position coordinates are relative to the window’s parent window.
 *
 * @param x X coordinate of window
 * @param y Y coordinate of window
 */
- (void)positionWithX:(gint*)x y:(gint*)y;

/**
 * Obtains the position of a window position in root
 * window coordinates. This is similar to
 * gdk_window_get_origin() but allows you to pass
 * in any position in the window, not just the origin.
 *
 * @param x X coordinate in window
 * @param y Y coordinate in window
 * @param rootX return location for X coordinate
 * @param rootY return location for Y coordinate
 */
- (void)rootCoordsWithX:(gint)x y:(gint)y rootX:(gint*)rootX rootY:(gint*)rootY;

/**
 * Obtains the top-left corner of the window manager frame in root
 * window coordinates.
 *
 * @param x return location for X position of window frame
 * @param y return location for Y position of window frame
 */
- (void)rootOriginWithX:(gint*)x y:(gint*)y;

/**
 * Returns the internal scale factor that maps from window coordiantes
 * to the actual device pixels. On traditional systems this is 1, but
 * on very high density outputs this can be a higher value (often 2).
 * 
 * A higher value means that drawing is automatically scaled up to
 * a higher resolution, so any code doing drawing will automatically look
 * nicer. However, if you are supplying pixel-based data the scale
 * value can be used to determine whether to use a pixel resource
 * with higher resolution data.
 * 
 * The scale of a window may change during runtime, if this happens
 * a configure event will be sent to the toplevel window.
 *
 * @return the scale factor
 */
- (gint)scaleFactor;

/**
 * Gets the #GdkScreen associated with a #GdkWindow.
 *
 * @return the #GdkScreen associated with @window
 */
- (OGGdkScreen*)screen;

/**
 * Returns the event mask for @window corresponding to the device class specified
 * by @source.
 *
 * @param source a #GdkInputSource to define the source class.
 * @return source event mask for @window
 */
- (GdkEventMask)sourceEvents:(GdkInputSource)source;

/**
 * Gets the bitwise OR of the currently active window state flags,
 * from the #GdkWindowState enumeration.
 *
 * @return window state bitfield
 */
- (GdkWindowState)state;

/**
 * Returns %TRUE if the window is aware of the existence of multiple
 * devices.
 *
 * @return %TRUE if the window handles multidevice features.
 */
- (bool)supportMultidevice;

/**
 * Gets the toplevel window that’s an ancestor of @window.
 * 
 * Any window type but %GDK_WINDOW_CHILD is considered a
 * toplevel window, as is a %GDK_WINDOW_CHILD window that
 * has a root window as parent.
 * 
 * Note that you should use gdk_window_get_effective_toplevel() when
 * you want to get to a window’s toplevel as seen on screen, because
 * gdk_window_get_toplevel() will most likely not do what you expect
 * if there are offscreen windows in the hierarchy.
 *
 * @return the toplevel window containing @window
 */
- (OGGdkWindow*)toplevel;

/**
 * This function returns the type hint set for a window.
 *
 * @return The type hint set for @window
 */
- (GdkWindowTypeHint)typeHint;

/**
 * Transfers ownership of the update area from @window to the caller
 * of the function. That is, after calling this function, @window will
 * no longer have an invalid/dirty region; the update area is removed
 * from @window and handed to you. If a window has no update area,
 * gdk_window_get_update_area() returns %NULL. You are responsible for
 * calling cairo_region_destroy() on the returned region if it’s non-%NULL.
 *
 * @return the update area for @window
 */
- (cairo_region_t*)updateArea;

/**
 * Retrieves the user data for @window, which is normally the widget
 * that @window belongs to. See gdk_window_set_user_data().
 *
 * @param data return location for user data
 */
- (void)userData:(gpointer*)data;

/**
 * Computes the region of the @window that is potentially visible.
 * This does not necessarily take into account if the window is
 * obscured by other windows, but no area outside of this region
 * is visible.
 *
 * @return a #cairo_region_t. This must be freed with cairo_region_destroy()
 *          when you are done.
 */
- (cairo_region_t*)visibleRegion;

/**
 * Gets the #GdkVisual describing the pixel format of @window.
 *
 * @return a #GdkVisual
 */
- (OGGdkVisual*)visual;

/**
 * Returns the width of the given @window.
 * 
 * On the X11 platform the returned size is the size reported in the
 * most-recently-processed configure event, rather than the current
 * size on the X server.
 *
 * @return The width of @window
 */
- (int)width;

/**
 * Gets the type of the window. See #GdkWindowType.
 *
 * @return type of window
 */
- (GdkWindowType)windowType;

/**
 * Checks whether the window has a native window or not. Note that
 * you can use gdk_window_ensure_native() if a native window is needed.
 *
 * @return %TRUE if the @window has a native window, %FALSE otherwise.
 */
- (bool)hasNative;

/**
 * For toplevel windows, withdraws them, so they will no longer be
 * known to the window manager; for all windows, unmaps them, so
 * they won’t be displayed. Normally done automatically as
 * part of gtk_widget_hide().
 *
 */
- (void)hide;

/**
 * Asks to iconify (minimize) @window. The window manager may choose
 * to ignore the request, but normally will honor it. Using
 * gtk_window_iconify() is preferred, if you have a #GtkWindow widget.
 * 
 * This function only makes sense when @window is a toplevel window.
 *
 */
- (void)iconify;

/**
 * Like gdk_window_shape_combine_region(), but the shape applies
 * only to event handling. Mouse events which happen while
 * the pointer position corresponds to an unset bit in the
 * mask will be passed on the window below @window.
 * 
 * An input shape is typically used with RGBA windows.
 * The alpha channel of the window defines which pixels are
 * invisible and allows for nicely antialiased borders,
 * and the input shape controls where the window is
 * “clickable”.
 * 
 * On the X11 platform, this requires version 1.1 of the
 * shape extension.
 * 
 * On the Win32 platform, this functionality is not present and the
 * function does nothing.
 *
 * @param shapeRegion region of window to be non-transparent
 * @param offsetX X position of @shape_region in @window coordinates
 * @param offsetY Y position of @shape_region in @window coordinates
 */
- (void)inputShapeCombineRegionWithShapeRegion:(const cairo_region_t*)shapeRegion offsetX:(gint)offsetX offsetY:(gint)offsetY;

/**
 * Adds @region to the update area for @window. The update area is the
 * region that needs to be redrawn, or “dirty region.” The call
 * gdk_window_process_updates() sends one or more expose events to the
 * window, which together cover the entire update area. An
 * application would normally redraw the contents of @window in
 * response to those expose events.
 * 
 * GDK will call gdk_window_process_all_updates() on your behalf
 * whenever your program returns to the main loop and becomes idle, so
 * normally there’s no need to do that manually, you just need to
 * invalidate regions that you know should be redrawn.
 * 
 * The @child_func parameter controls whether the region of
 * each child window that intersects @region will also be invalidated.
 * Only children for which @child_func returns #TRUE will have the area
 * invalidated.
 *
 * @param region a #cairo_region_t
 * @param childFunc function to use to decide if to
 *     recurse to a child, %NULL means never recurse.
 * @param userData data passed to @child_func
 */
- (void)invalidateMaybeRecurseWithRegion:(const cairo_region_t*)region childFunc:(GdkWindowChildFunc)childFunc userData:(gpointer)userData;

/**
 * A convenience wrapper around gdk_window_invalidate_region() which
 * invalidates a rectangular region. See
 * gdk_window_invalidate_region() for details.
 *
 * @param rect rectangle to invalidate or %NULL to invalidate the whole
 *      window
 * @param invalidateChildren whether to also invalidate child windows
 */
- (void)invalidateRectWithRect:(const GdkRectangle*)rect invalidateChildren:(bool)invalidateChildren;

/**
 * Adds @region to the update area for @window. The update area is the
 * region that needs to be redrawn, or “dirty region.” The call
 * gdk_window_process_updates() sends one or more expose events to the
 * window, which together cover the entire update area. An
 * application would normally redraw the contents of @window in
 * response to those expose events.
 * 
 * GDK will call gdk_window_process_all_updates() on your behalf
 * whenever your program returns to the main loop and becomes idle, so
 * normally there’s no need to do that manually, you just need to
 * invalidate regions that you know should be redrawn.
 * 
 * The @invalidate_children parameter controls whether the region of
 * each child window that intersects @region will also be invalidated.
 * If %FALSE, then the update area for child windows will remain
 * unaffected. See gdk_window_invalidate_maybe_recurse if you need
 * fine grained control over which children are invalidated.
 *
 * @param region a #cairo_region_t
 * @param invalidateChildren %TRUE to also invalidate child windows
 */
- (void)invalidateRegionWithRegion:(const cairo_region_t*)region invalidateChildren:(bool)invalidateChildren;

/**
 * Check to see if a window is destroyed..
 *
 * @return %TRUE if the window is destroyed
 */
- (bool)isDestroyed;

/**
 * Determines whether or not the window is an input only window.
 *
 * @return %TRUE if @window is input only
 */
- (bool)isInputOnly;

/**
 * Determines whether or not the window is shaped.
 *
 * @return %TRUE if @window is shaped
 */
- (bool)isShaped;

/**
 * Check if the window and all ancestors of the window are
 * mapped. (This is not necessarily "viewable" in the X sense, since
 * we only check as far as we have GDK window parents, not to the root
 * window.)
 *
 * @return %TRUE if the window is viewable
 */
- (bool)isViewable;

/**
 * Checks whether the window has been mapped (with gdk_window_show() or
 * gdk_window_show_unraised()).
 *
 * @return %TRUE if the window is mapped
 */
- (bool)isVisible;

/**
 * Lowers @window to the bottom of the Z-order (stacking order), so that
 * other windows with the same parent window appear above @window.
 * This is true whether or not the other windows are visible.
 * 
 * If @window is a toplevel, the window manager may choose to deny the
 * request to move the window in the Z-order, gdk_window_lower() only
 * requests the restack, does not guarantee it.
 * 
 * Note that gdk_window_show() raises the window again, so don’t call this
 * function before gdk_window_show(). (Try gdk_window_show_unraised().)
 *
 */
- (void)lower;

/**
 * If you call this during a paint (e.g. between gdk_window_begin_paint_region()
 * and gdk_window_end_paint() then GDK will mark the current clip region of the
 * window as being drawn. This is required when mixing GL rendering via
 * gdk_cairo_draw_from_gl() and cairo rendering, as otherwise GDK has no way
 * of knowing when something paints over the GL-drawn regions.
 * 
 * This is typically called automatically by GTK+ and you don't need
 * to care about this.
 *
 * @param cr a #cairo_t
 */
- (void)markPaintFromClip:(cairo_t*)cr;

/**
 * Maximizes the window. If the window was already maximized, then
 * this function does nothing.
 * 
 * On X11, asks the window manager to maximize @window, if the window
 * manager supports this operation. Not all window managers support
 * this, and some deliberately ignore it or don’t have a concept of
 * “maximized”; so you can’t rely on the maximization actually
 * happening. But it will happen with most standard window managers,
 * and GDK makes a best effort to get it to happen.
 * 
 * On Windows, reliably maximizes the window.
 *
 */
- (void)maximize;

/**
 * Merges the input shape masks for any child windows into the
 * input shape mask for @window. i.e. the union of all input masks
 * for @window and its children will become the new input mask
 * for @window. See gdk_window_input_shape_combine_region().
 * 
 * This function is distinct from gdk_window_set_child_input_shapes()
 * because it includes @window’s input shape mask in the set of
 * shapes to be merged.
 *
 */
- (void)mergeChildInputShapes;

/**
 * Merges the shape masks for any child windows into the
 * shape mask for @window. i.e. the union of all masks
 * for @window and its children will become the new mask
 * for @window. See gdk_window_shape_combine_region().
 * 
 * This function is distinct from gdk_window_set_child_shapes()
 * because it includes @window’s shape mask in the set of shapes to
 * be merged.
 *
 */
- (void)mergeChildShapes;

/**
 * Repositions a window relative to its parent window.
 * For toplevel windows, window managers may ignore or modify the move;
 * you should probably use gtk_window_move() on a #GtkWindow widget
 * anyway, instead of using GDK functions. For child windows,
 * the move will reliably succeed.
 * 
 * If you’re also planning to resize the window, use gdk_window_move_resize()
 * to both move and resize simultaneously, for a nicer visual effect.
 *
 * @param x X coordinate relative to window’s parent
 * @param y Y coordinate relative to window’s parent
 */
- (void)moveWithX:(gint)x y:(gint)y;

/**
 * Move the part of @window indicated by @region by @dy pixels in the Y
 * direction and @dx pixels in the X direction. The portions of @region
 * that not covered by the new position of @region are invalidated.
 * 
 * Child windows are not moved.
 *
 * @param region The #cairo_region_t to move
 * @param dx Amount to move in the X direction
 * @param dy Amount to move in the Y direction
 */
- (void)moveRegionWithRegion:(const cairo_region_t*)region dx:(gint)dx dy:(gint)dy;

/**
 * Equivalent to calling gdk_window_move() and gdk_window_resize(),
 * except that both operations are performed at once, avoiding strange
 * visual effects. (i.e. the user may be able to see the window first
 * move, then resize, if you don’t use gdk_window_move_resize().)
 *
 * @param x new X position relative to window’s parent
 * @param y new Y position relative to window’s parent
 * @param width new width
 * @param height new height
 */
- (void)moveResizeWithX:(gint)x y:(gint)y width:(gint)width height:(gint)height;

/**
 * Moves @window to @rect, aligning their anchor points.
 * 
 * @rect is relative to the top-left corner of the window that @window is
 * transient for. @rect_anchor and @window_anchor determine anchor points on
 * @rect and @window to pin together. @rect's anchor point can optionally be
 * offset by @rect_anchor_dx and @rect_anchor_dy, which is equivalent to
 * offsetting the position of @window.
 * 
 * @anchor_hints determines how @window will be moved if the anchor points cause
 * it to move off-screen. For example, %GDK_ANCHOR_FLIP_X will replace
 * %GDK_GRAVITY_NORTH_WEST with %GDK_GRAVITY_NORTH_EAST and vice versa if
 * @window extends beyond the left or right edges of the monitor.
 * 
 * Connect to the #GdkWindow::moved-to-rect signal to find out how it was
 * actually positioned.
 *
 * @param rect the destination #GdkRectangle to align @window with
 * @param rectAnchor the point on @rect to align with @window's anchor point
 * @param windowAnchor the point on @window to align with @rect's anchor point
 * @param anchorHints positioning hints to use when limited on space
 * @param rectAnchorDx horizontal offset to shift @window, i.e. @rect's anchor
 *                  point
 * @param rectAnchorDy vertical offset to shift @window, i.e. @rect's anchor point
 */
- (void)moveToRectWithRect:(const GdkRectangle*)rect rectAnchor:(GdkGravity)rectAnchor windowAnchor:(GdkGravity)windowAnchor anchorHints:(GdkAnchorHints)anchorHints rectAnchorDx:(gint)rectAnchorDx rectAnchorDy:(gint)rectAnchorDy;

/**
 * Like gdk_window_get_children(), but does not copy the list of
 * children, so the list does not need to be freed.
 *
 * @return a reference to the list of child windows in @window
 */
- (GList*)peekChildren;

/**
 * Sends one or more expose events to @window. The areas in each
 * expose event will cover the entire update area for the window (see
 * gdk_window_invalidate_region() for details). Normally GDK calls
 * gdk_window_process_all_updates() on your behalf, so there’s no
 * need to call this function unless you want to force expose events
 * to be delivered immediately and synchronously (vs. the usual
 * case, where GDK delivers them in an idle handler). Occasionally
 * this is useful to produce nicer scrolling behavior, for example.
 *
 * @param updateChildren whether to also process updates for child windows
 */
- (void)processUpdates:(bool)updateChildren;

/**
 * Raises @window to the top of the Z-order (stacking order), so that
 * other windows with the same parent window appear below @window.
 * This is true whether or not the windows are visible.
 * 
 * If @window is a toplevel, the window manager may choose to deny the
 * request to move the window in the Z-order, gdk_window_raise() only
 * requests the restack, does not guarantee it.
 *
 */
- (void)raise;

/**
 * Registers a window as a potential drop destination.
 *
 */
- (void)registerDnd;

/**
 * Remove a filter previously added with gdk_window_add_filter().
 *
 * @param function previously-added filter function
 * @param data user data for previously-added filter function
 */
- (void)removeFilterWithFunction:(GdkFilterFunc)function data:(gpointer)data;

/**
 * Reparents @window into the given @new_parent. The window being
 * reparented will be unmapped as a side effect.
 *
 * @param newParent new parent to move @window into
 * @param x X location inside the new parent
 * @param y Y location inside the new parent
 */
- (void)reparentWithNewParent:(OGGdkWindow*)newParent x:(gint)x y:(gint)y;

/**
 * Resizes @window; for toplevel windows, asks the window manager to resize
 * the window. The window manager may not allow the resize. When using GTK+,
 * use gtk_window_resize() instead of this low-level GDK function.
 * 
 * Windows may not be resized below 1x1.
 * 
 * If you’re also planning to move the window, use gdk_window_move_resize()
 * to both move and resize simultaneously, for a nicer visual effect.
 *
 * @param width new width of the window
 * @param height new height of the window
 */
- (void)resizeWithWidth:(gint)width height:(gint)height;

/**
 * Changes the position of  @window in the Z-order (stacking order), so that
 * it is above @sibling (if @above is %TRUE) or below @sibling (if @above is
 * %FALSE).
 * 
 * If @sibling is %NULL, then this either raises (if @above is %TRUE) or
 * lowers the window.
 * 
 * If @window is a toplevel, the window manager may choose to deny the
 * request to move the window in the Z-order, gdk_window_restack() only
 * requests the restack, does not guarantee it.
 *
 * @param sibling a #GdkWindow that is a sibling of @window, or %NULL
 * @param above a boolean
 */
- (void)restackWithSibling:(OGGdkWindow*)sibling above:(bool)above;

/**
 * Scroll the contents of @window, both pixels and children, by the
 * given amount. @window itself does not move. Portions of the window
 * that the scroll operation brings in from offscreen areas are
 * invalidated. The invalidated region may be bigger than what would
 * strictly be necessary.
 * 
 * For X11, a minimum area will be invalidated if the window has no
 * subwindows, or if the edges of the window’s parent do not extend
 * beyond the edges of the window. In other cases, a multi-step process
 * is used to scroll the window which may produce temporary visual
 * artifacts and unnecessary invalidations.
 *
 * @param dx Amount to scroll in the X direction
 * @param dy Amount to scroll in the Y direction
 */
- (void)scrollWithDx:(gint)dx dy:(gint)dy;

/**
 * Setting @accept_focus to %FALSE hints the desktop environment that the
 * window doesn’t want to receive input focus.
 * 
 * On X, it is the responsibility of the window manager to interpret this
 * hint. ICCCM-compliant window manager usually respect it.
 *
 * @param acceptFocus %TRUE if the window should receive input focus
 */
- (void)setAcceptFocus:(bool)acceptFocus;

/**
 * Sets the background color of @window.
 * 
 * However, when using GTK+, influence the background of a widget
 * using a style class or CSS — if you’re an application — or with
 * gtk_style_context_set_background() — if you're implementing a
 * custom widget.
 *
 * @param color a #GdkColor
 */
- (void)setBackground:(const GdkColor*)color;

/**
 * Sets the background of @window.
 * 
 * A background of %NULL means that the window won't have any background. On the
 * X11 backend it's also possible to inherit the background from the parent
 * window using gdk_x11_get_parent_relative_pattern().
 * 
 * The windowing system will normally fill a window with its background
 * when the window is obscured then exposed.
 *
 * @param pattern a pattern to use, or %NULL
 */
- (void)setBackgroundPattern:(cairo_pattern_t*)pattern;

/**
 * Sets the background color of @window.
 * 
 * See also gdk_window_set_background_pattern().
 *
 * @param rgba a #GdkRGBA color
 */
- (void)setBackgroundRgba:(const GdkRGBA*)rgba;

/**
 * Sets the input shape mask of @window to the union of input shape masks
 * for all children of @window, ignoring the input shape mask of @window
 * itself. Contrast with gdk_window_merge_child_input_shapes() which includes
 * the input shape mask of @window in the masks to be merged.
 *
 */
- (void)setChildInputShapes;

/**
 * Sets the shape mask of @window to the union of shape masks
 * for all children of @window, ignoring the shape mask of @window
 * itself. Contrast with gdk_window_merge_child_shapes() which includes
 * the shape mask of @window in the masks to be merged.
 *
 */
- (void)setChildShapes;

/**
 * Sets a #GdkWindow as composited, or unsets it. Composited
 * windows do not automatically have their contents drawn to
 * the screen. Drawing is redirected to an offscreen buffer
 * and an expose event is emitted on the parent of the composited
 * window. It is the responsibility of the parent’s expose handler
 * to manually merge the off-screen content onto the screen in
 * whatever way it sees fit.
 * 
 * It only makes sense for child windows to be composited; see
 * gdk_window_set_opacity() if you need translucent toplevel
 * windows.
 * 
 * An additional effect of this call is that the area of this
 * window is no longer clipped from regions marked for
 * invalidation on its parent. Draws done on the parent
 * window are also no longer clipped by the child.
 * 
 * This call is only supported on some systems (currently,
 * only X11 with new enough Xcomposite and Xdamage extensions).
 * You must call gdk_display_supports_composite() to check if
 * setting a window as composited is supported before
 * attempting to do so.
 *
 * @param composited %TRUE to set the window as composited
 */
- (void)setComposited:(bool)composited;

/**
 * Sets the default mouse pointer for a #GdkWindow.
 * 
 * Note that @cursor must be for the same display as @window.
 * 
 * Use gdk_cursor_new_for_display() or gdk_cursor_new_from_pixbuf() to
 * create the cursor. To make the cursor invisible, use %GDK_BLANK_CURSOR.
 * Passing %NULL for the @cursor argument to gdk_window_set_cursor() means
 * that @window will use the cursor of its parent window. Most windows
 * should use this default.
 *
 * @param cursor a cursor
 */
- (void)setCursor:(OGGdkCursor*)cursor;

/**
 * “Decorations” are the features the window manager adds to a toplevel #GdkWindow.
 * This function sets the traditional Motif window manager hints that tell the
 * window manager which decorations you would like your window to have.
 * Usually you should use gtk_window_set_decorated() on a #GtkWindow instead of
 * using the GDK function directly.
 * 
 * The @decorations argument is the logical OR of the fields in
 * the #GdkWMDecoration enumeration. If #GDK_DECOR_ALL is included in the
 * mask, the other bits indicate which decorations should be turned off.
 * If #GDK_DECOR_ALL is not included, then the other bits indicate
 * which decorations should be turned on.
 * 
 * Most window managers honor a decorations hint of 0 to disable all decorations,
 * but very few honor all possible combinations of bits.
 *
 * @param decorations decoration hint mask
 */
- (void)setDecorations:(GdkWMDecoration)decorations;

/**
 * Sets a specific #GdkCursor for a given device when it gets inside @window.
 * Use gdk_cursor_new_for_display() or gdk_cursor_new_from_pixbuf() to create
 * the cursor. To make the cursor invisible, use %GDK_BLANK_CURSOR. Passing
 * %NULL for the @cursor argument to gdk_window_set_cursor() means that
 * @window will use the cursor of its parent window. Most windows should
 * use this default.
 *
 * @param device a master, pointer #GdkDevice
 * @param cursor a #GdkCursor
 */
- (void)setDeviceCursorWithDevice:(OGGdkDevice*)device cursor:(OGGdkCursor*)cursor;

/**
 * Sets the event mask for a given device (Normally a floating device, not
 * attached to any visible pointer) to @window. For example, an event mask
 * including #GDK_BUTTON_PRESS_MASK means the window should report button
 * press events. The event mask is the bitwise OR of values from the
 * #GdkEventMask enumeration.
 * 
 * See the [input handling overview][event-masks] for details.
 *
 * @param device #GdkDevice to enable events for.
 * @param eventMask event mask for @window
 */
- (void)setDeviceEventsWithDevice:(OGGdkDevice*)device eventMask:(GdkEventMask)eventMask;

/**
 * Determines whether or not extra unprocessed motion events in
 * the event queue can be discarded. If %TRUE only the most recent
 * event will be delivered.
 * 
 * Some types of applications, e.g. paint programs, need to see all
 * motion events and will benefit from turning off event compression.
 * 
 * By default, event compression is enabled.
 *
 * @param eventCompression %TRUE if motion events should be compressed
 */
- (void)setEventCompression:(bool)eventCompression;

/**
 * The event mask for a window determines which events will be reported
 * for that window from all master input devices. For example, an event mask
 * including #GDK_BUTTON_PRESS_MASK means the window should report button
 * press events. The event mask is the bitwise OR of values from the
 * #GdkEventMask enumeration.
 * 
 * See the [input handling overview][event-masks] for details.
 *
 * @param eventMask event mask for @window
 */
- (void)setEvents:(GdkEventMask)eventMask;

/**
 * Setting @focus_on_map to %FALSE hints the desktop environment that the
 * window doesn’t want to receive input focus when it is mapped.
 * focus_on_map should be turned off for windows that aren’t triggered
 * interactively (such as popups from network activity).
 * 
 * On X, it is the responsibility of the window manager to interpret
 * this hint. Window managers following the freedesktop.org window
 * manager extension specification should respect it.
 *
 * @param focusOnMap %TRUE if the window should receive input focus when mapped
 */
- (void)setFocusOnMap:(bool)focusOnMap;

/**
 * Specifies whether the @window should span over all monitors (in a multi-head
 * setup) or only the current monitor when in fullscreen mode.
 * 
 * The @mode argument is from the #GdkFullscreenMode enumeration.
 * If #GDK_FULLSCREEN_ON_ALL_MONITORS is specified, the fullscreen @window will
 * span over all monitors from the #GdkScreen.
 * 
 * On X11, searches through the list of monitors from the #GdkScreen the ones
 * which delimit the 4 edges of the entire #GdkScreen and will ask the window
 * manager to span the @window over these monitors.
 * 
 * If the XINERAMA extension is not available or not usable, this function
 * has no effect.
 * 
 * Not all window managers support this, so you can’t rely on the fullscreen
 * window to span over the multiple monitors when #GDK_FULLSCREEN_ON_ALL_MONITORS
 * is specified.
 *
 * @param mode fullscreen mode
 */
- (void)setFullscreenMode:(GdkFullscreenMode)mode;

/**
 * Sets hints about the window management functions to make available
 * via buttons on the window frame.
 * 
 * On the X backend, this function sets the traditional Motif window
 * manager hint for this purpose. However, few window managers do
 * anything reliable or interesting with this hint. Many ignore it
 * entirely.
 * 
 * The @functions argument is the logical OR of values from the
 * #GdkWMFunction enumeration. If the bitmask includes #GDK_FUNC_ALL,
 * then the other bits indicate which functions to disable; if
 * it doesn’t include #GDK_FUNC_ALL, it indicates which functions to
 * enable.
 *
 * @param functions bitmask of operations to allow on @window
 */
- (void)setFunctions:(GdkWMFunction)functions;

/**
 * Sets the geometry hints for @window. Hints flagged in @geom_mask
 * are set, hints not flagged in @geom_mask are unset.
 * To unset all hints, use a @geom_mask of 0 and a @geometry of %NULL.
 * 
 * This function provides hints to the windowing system about
 * acceptable sizes for a toplevel window. The purpose of
 * this is to constrain user resizing, but the windowing system
 * will typically  (but is not required to) also constrain the
 * current size of the window to the provided values and
 * constrain programatic resizing via gdk_window_resize() or
 * gdk_window_move_resize().
 * 
 * Note that on X11, this effect has no effect on windows
 * of type %GDK_WINDOW_TEMP or windows where override redirect
 * has been turned on via gdk_window_set_override_redirect()
 * since these windows are not resizable by the user.
 * 
 * Since you can’t count on the windowing system doing the
 * constraints for programmatic resizes, you should generally
 * call gdk_window_constrain_size() yourself to determine
 * appropriate sizes.
 *
 * @param geometry geometry hints
 * @param geomMask bitmask indicating fields of @geometry to pay attention to
 */
- (void)setGeometryHintsWithGeometry:(const GdkGeometry*)geometry geomMask:(GdkWindowHints)geomMask;

/**
 * Sets the group leader window for @window. By default,
 * GDK sets the group leader for all toplevel windows
 * to a global window implicitly created by GDK. With this function
 * you can override this default.
 * 
 * The group leader window allows the window manager to distinguish
 * all windows that belong to a single application. It may for example
 * allow users to minimize/unminimize all windows belonging to an
 * application at once. You should only set a non-default group window
 * if your application pretends to be multiple applications.
 *
 * @param leader group leader window, or %NULL to restore the default group leader window
 */
- (void)setGroup:(OGGdkWindow*)leader;

/**
 * Sets a list of icons for the window. One of these will be used
 * to represent the window when it has been iconified. The icon is
 * usually shown in an icon box or some sort of task bar. Which icon
 * size is shown depends on the window manager. The window manager
 * can scale the icon  but setting several size icons can give better
 * image quality since the window manager may only need to scale the
 * icon by a small amount or not at all.
 * 
 * Note that some platforms don't support window icons.
 *
 * @param pixbufs A list of pixbufs, of different sizes.
 */
- (void)setIconList:(GList*)pixbufs;

/**
 * Windows may have a name used while minimized, distinct from the
 * name they display in their titlebar. Most of the time this is a bad
 * idea from a user interface standpoint. But you can set such a name
 * with this function, if you like.
 * 
 * After calling this with a non-%NULL @name, calls to gdk_window_set_title()
 * will not update the icon title.
 * 
 * Using %NULL for @name unsets the icon title; further calls to
 * gdk_window_set_title() will again update the icon title as well.
 * 
 * Note that some platforms don't support window icons.
 *
 * @param name name of window while iconified (minimized)
 */
- (void)setIconName:(OFString*)name;

/**
 * Registers an invalidate handler for a specific window. This
 * will get called whenever a region in the window or its children
 * is invalidated.
 * 
 * This can be used to record the invalidated region, which is
 * useful if you are keeping an offscreen copy of some region
 * and want to keep it up to date. You can also modify the
 * invalidated region in case you’re doing some effect where
 * e.g. a child widget appears in multiple places.
 *
 * @param handler a #GdkWindowInvalidateHandlerFunc callback function
 */
- (void)setInvalidateHandler:(GdkWindowInvalidateHandlerFunc)handler;

/**
 * Set if @window must be kept above other windows. If the
 * window was already above, then this function does nothing.
 * 
 * On X11, asks the window manager to keep @window above, if the window
 * manager supports this operation. Not all window managers support
 * this, and some deliberately ignore it or don’t have a concept of
 * “keep above”; so you can’t rely on the window being kept above.
 * But it will happen with most standard window managers,
 * and GDK makes a best effort to get it to happen.
 *
 * @param setting whether to keep @window above other windows
 */
- (void)setKeepAbove:(bool)setting;

/**
 * Set if @window must be kept below other windows. If the
 * window was already below, then this function does nothing.
 * 
 * On X11, asks the window manager to keep @window below, if the window
 * manager supports this operation. Not all window managers support
 * this, and some deliberately ignore it or don’t have a concept of
 * “keep below”; so you can’t rely on the window being kept below.
 * But it will happen with most standard window managers,
 * and GDK makes a best effort to get it to happen.
 *
 * @param setting whether to keep @window below other windows
 */
- (void)setKeepBelow:(bool)setting;

/**
 * The application can use this hint to tell the window manager
 * that a certain window has modal behaviour. The window manager
 * can use this information to handle modal windows in a special
 * way.
 * 
 * You should only use this on windows for which you have
 * previously called gdk_window_set_transient_for()
 *
 * @param modal %TRUE if the window is modal, %FALSE otherwise.
 */
- (void)setModalHint:(bool)modal;

/**
 * Set @window to render as partially transparent,
 * with opacity 0 being fully transparent and 1 fully opaque. (Values
 * of the opacity parameter are clamped to the [0,1] range.)
 * 
 * For toplevel windows this depends on support from the windowing system
 * that may not always be there. For instance, On X11, this works only on
 * X screens with a compositing manager running. On Wayland, there is no
 * per-window opacity value that the compositor would apply. Instead, use
 * `gdk_window_set_opaque_region (window, NULL)` to tell the compositor
 * that the entire window is (potentially) non-opaque, and draw your content
 * with alpha, or use gtk_widget_set_opacity() to set an overall opacity
 * for your widgets.
 * 
 * For child windows this function only works for non-native windows.
 * 
 * For setting up per-pixel alpha topelevels, see gdk_screen_get_rgba_visual(),
 * and for non-toplevels, see gdk_window_set_composited().
 * 
 * Support for non-toplevel windows was added in 3.8.
 *
 * @param opacity opacity
 */
- (void)setOpacity:(gdouble)opacity;

/**
 * For optimisation purposes, compositing window managers may
 * like to not draw obscured regions of windows, or turn off blending
 * during for these regions. With RGB windows with no transparency,
 * this is just the shape of the window, but with ARGB32 windows, the
 * compositor does not know what regions of the window are transparent
 * or not.
 * 
 * This function only works for toplevel windows.
 * 
 * GTK+ will update this property automatically if
 * the @window background is opaque, as we know where the opaque regions
 * are. If your window background is not opaque, please update this
 * property in your #GtkWidget::style-updated handler.
 *
 * @param region a region, or %NULL
 */
- (void)setOpaqueRegion:(cairo_region_t*)region;

/**
 * An override redirect window is not under the control of the window manager.
 * This means it won’t have a titlebar, won’t be minimizable, etc. - it will
 * be entirely under the control of the application. The window manager
 * can’t see the override redirect window at all.
 * 
 * Override redirect should only be used for short-lived temporary
 * windows, such as popup menus. #GtkMenu uses an override redirect
 * window in its implementation, for example.
 *
 * @param overrideRedirect %TRUE if window should be override redirect
 */
- (void)setOverrideRedirect:(bool)overrideRedirect;

/**
 * Sets whether input to the window is passed through to the window
 * below.
 * 
 * The default value of this is %FALSE, which means that pointer
 * events that happen inside the window are send first to the window,
 * but if the event is not selected by the event mask then the event
 * is sent to the parent window, and so on up the hierarchy.
 * 
 * If @pass_through is %TRUE then such pointer events happen as if the
 * window wasn't there at all, and thus will be sent first to any
 * windows below @window. This is useful if the window is used in a
 * transparent fashion. In the terminology of the web this would be called
 * "pointer-events: none".
 * 
 * Note that a window with @pass_through %TRUE can still have a subwindow
 * without pass through, so you can get events on a subset of a window. And in
 * that cases you would get the in-between related events such as the pointer
 * enter/leave events on its way to the destination window.
 *
 * @param passThrough a boolean
 */
- (void)setPassThrough:(bool)passThrough;

/**
 * When using GTK+, typically you should use gtk_window_set_role() instead
 * of this low-level function.
 * 
 * The window manager and session manager use a window’s role to
 * distinguish it from other kinds of window in the same application.
 * When an application is restarted after being saved in a previous
 * session, all windows with the same title and role are treated as
 * interchangeable.  So if you have two windows with the same title
 * that should be distinguished for session management purposes, you
 * should set the role on those windows. It doesn’t matter what string
 * you use for the role, as long as you have a different role for each
 * non-interchangeable kind of window.
 *
 * @param role a string indicating its role
 */
- (void)setRole:(OFString*)role;

/**
 * Newer GTK+ windows using client-side decorations use extra geometry
 * around their frames for effects like shadows and invisible borders.
 * Window managers that want to maximize windows or snap to edges need
 * to know where the extents of the actual frame lie, so that users
 * don’t feel like windows are snapping against random invisible edges.
 * 
 * Note that this property is automatically updated by GTK+, so this
 * function should only be used by applications which do not use GTK+
 * to create toplevel windows.
 *
 * @param left The left extent
 * @param right The right extent
 * @param top The top extent
 * @param bottom The bottom extent
 */
- (void)setShadowWidthWithLeft:(gint)left right:(gint)right top:(gint)top bottom:(gint)bottom;

/**
 * Toggles whether a window should appear in a pager (workspace
 * switcher, or other desktop utility program that displays a small
 * thumbnail representation of the windows on the desktop). If a
 * window’s semantic type as specified with gdk_window_set_type_hint()
 * already fully describes the window, this function should
 * not be called in addition, instead you should
 * allow the window to be treated according to standard policy for
 * its semantic type.
 *
 * @param skipsPager %TRUE to skip the pager
 */
- (void)setSkipPagerHint:(bool)skipsPager;

/**
 * Toggles whether a window should appear in a task list or window
 * list. If a window’s semantic type as specified with
 * gdk_window_set_type_hint() already fully describes the window, this
 * function should not be called in addition,
 * instead you should allow the window to be treated according to
 * standard policy for its semantic type.
 *
 * @param skipsTaskbar %TRUE to skip the taskbar
 */
- (void)setSkipTaskbarHint:(bool)skipsTaskbar;

/**
 * Sets the event mask for any floating device (i.e. not attached to any
 * visible pointer) that has the source defined as @source. This event
 * mask will be applied both to currently existing, newly added devices
 * after this call, and devices being attached/detached.
 *
 * @param source a #GdkInputSource to define the source class.
 * @param eventMask event mask for @window
 */
- (void)setSourceEventsWithSource:(GdkInputSource)source eventMask:(GdkEventMask)eventMask;

/**
 * When using GTK+, typically you should use gtk_window_set_startup_id()
 * instead of this low-level function.
 *
 * @param startupId a string with startup-notification identifier
 */
- (void)setStartupId:(OFString*)startupId;

/**
 * Used to set the bit gravity of the given window to static, and flag
 * it so all children get static subwindow gravity. This is used if you
 * are implementing scary features that involve deep knowledge of the
 * windowing system. Don’t worry about it.
 *
 * @param useStatic %TRUE to turn on static gravity
 * @return %FALSE
 */
- (bool)setStaticGravities:(bool)useStatic;

/**
 * This function will enable multidevice features in @window.
 * 
 * Multidevice aware windows will need to handle properly multiple,
 * per device enter/leave events, device grabs and grab ownerships.
 *
 * @param supportMultidevice %TRUE to enable multidevice support in @window.
 */
- (void)setSupportMultidevice:(bool)supportMultidevice;

/**
 * Sets the title of a toplevel window, to be displayed in the titlebar.
 * If you haven’t explicitly set the icon name for the window
 * (using gdk_window_set_icon_name()), the icon name will be set to
 * @title as well. @title must be in UTF-8 encoding (as with all
 * user-readable strings in GDK/GTK+). @title may not be %NULL.
 *
 * @param title title of @window
 */
- (void)setTitle:(OFString*)title;

/**
 * Indicates to the window manager that @window is a transient dialog
 * associated with the application window @parent. This allows the
 * window manager to do things like center @window on @parent and
 * keep @window above @parent.
 * 
 * See gtk_window_set_transient_for() if you’re using #GtkWindow or
 * #GtkDialog.
 *
 * @param parent another toplevel #GdkWindow
 */
- (void)setTransientFor:(OGGdkWindow*)parent;

/**
 * The application can use this call to provide a hint to the window
 * manager about the functionality of a window. The window manager
 * can use this information when determining the decoration and behaviour
 * of the window.
 * 
 * The hint must be set before the window is mapped.
 *
 * @param hint A hint of the function this window will have
 */
- (void)setTypeHint:(GdkWindowTypeHint)hint;

/**
 * Toggles whether a window needs the user's
 * urgent attention.
 *
 * @param urgent %TRUE if the window is urgent
 */
- (void)setUrgencyHint:(bool)urgent;

/**
 * For most purposes this function is deprecated in favor of
 * g_object_set_data(). However, for historical reasons GTK+ stores
 * the #GtkWidget that owns a #GdkWindow as user data on the
 * #GdkWindow. So, custom widget implementations should use
 * this function for that. If GTK+ receives an event for a #GdkWindow,
 * and the user data for the window is non-%NULL, GTK+ will assume the
 * user data is a #GtkWidget, and forward the event to that widget.
 *
 * @param userData user data
 */
- (void)setUserData:(gpointer)userData;

/**
 * Makes pixels in @window outside @shape_region be transparent,
 * so that the window may be nonrectangular.
 * 
 * If @shape_region is %NULL, the shape will be unset, so the whole
 * window will be opaque again. @offset_x and @offset_y are ignored
 * if @shape_region is %NULL.
 * 
 * On the X11 platform, this uses an X server extension which is
 * widely available on most common platforms, but not available on
 * very old X servers, and occasionally the implementation will be
 * buggy. On servers without the shape extension, this function
 * will do nothing.
 * 
 * This function works on both toplevel and child windows.
 *
 * @param shapeRegion region of window to be non-transparent
 * @param offsetX X position of @shape_region in @window coordinates
 * @param offsetY Y position of @shape_region in @window coordinates
 */
- (void)shapeCombineRegionWithShapeRegion:(const cairo_region_t*)shapeRegion offsetX:(gint)offsetX offsetY:(gint)offsetY;

/**
 * Like gdk_window_show_unraised(), but also raises the window to the
 * top of the window stack (moves the window to the front of the
 * Z-order).
 * 
 * This function maps a window so it’s visible onscreen. Its opposite
 * is gdk_window_hide().
 * 
 * When implementing a #GtkWidget, you should call this function on the widget's
 * #GdkWindow as part of the “map” method.
 *
 */
- (void)show;

/**
 * Shows a #GdkWindow onscreen, but does not modify its stacking
 * order. In contrast, gdk_window_show() will raise the window
 * to the top of the window stack.
 * 
 * On the X11 platform, in Xlib terms, this function calls
 * XMapWindow() (it also updates some internal GDK state, which means
 * that you can’t really use XMapWindow() directly on a GDK window).
 *
 */
- (void)showUnraised;

/**
 * Asks the windowing system to show the window menu. The window menu
 * is the menu shown when right-clicking the titlebar on traditional
 * windows managed by the window manager. This is useful for windows
 * using client-side decorations, activating it with a right-click
 * on the window decorations.
 *
 * @param event a #GdkEvent to show the menu for
 * @return %TRUE if the window menu was shown and %FALSE otherwise.
 */
- (bool)showWindowMenu:(GdkEvent*)event;

/**
 * “Pins” a window such that it’s on all workspaces and does not scroll
 * with viewports, for window managers that have scrollable viewports.
 * (When using #GtkWindow, gtk_window_stick() may be more useful.)
 * 
 * On the X11 platform, this function depends on window manager
 * support, so may have no effect with many window managers. However,
 * GDK will do the best it can to convince the window manager to stick
 * the window. For window managers that don’t support this operation,
 * there’s nothing you can do to force it to happen.
 *
 */
- (void)stick;

/**
 * Thaws a window frozen with
 * gdk_window_freeze_toplevel_updates_libgtk_only().
 * 
 * This function is not part of the GDK public API and is only
 * for use by GTK+.
 *
 */
- (void)thawToplevelUpdatesLibgtkOnly;

/**
 * Thaws a window frozen with gdk_window_freeze_updates().
 *
 */
- (void)thawUpdates;

/**
 * Moves the window out of fullscreen mode. If the window was not
 * fullscreen, does nothing.
 * 
 * On X11, asks the window manager to move @window out of the fullscreen
 * state, if the window manager supports this operation. Not all
 * window managers support this, and some deliberately ignore it or
 * don’t have a concept of “fullscreen”; so you can’t rely on the
 * unfullscreenification actually happening. But it will happen with
 * most standard window managers, and GDK makes a best effort to get
 * it to happen.
 *
 */
- (void)unfullscreen;

/**
 * Unmaximizes the window. If the window wasn’t maximized, then this
 * function does nothing.
 * 
 * On X11, asks the window manager to unmaximize @window, if the
 * window manager supports this operation. Not all window managers
 * support this, and some deliberately ignore it or don’t have a
 * concept of “maximized”; so you can’t rely on the unmaximization
 * actually happening. But it will happen with most standard window
 * managers, and GDK makes a best effort to get it to happen.
 * 
 * On Windows, reliably unmaximizes the window.
 *
 */
- (void)unmaximize;

/**
 * Reverse operation for gdk_window_stick(); see gdk_window_stick(),
 * and gtk_window_unstick().
 *
 */
- (void)unstick;

/**
 * Withdraws a window (unmaps it and asks the window manager to forget about it).
 * This function is not really useful as gdk_window_hide() automatically
 * withdraws toplevel windows before hiding them.
 *
 */
- (void)withdraw;

@end