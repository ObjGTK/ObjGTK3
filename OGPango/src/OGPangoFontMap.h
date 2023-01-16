/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <pango/pango.h>

#import <OGObject/OGObject.h>

@class OGPangoFontset;
@class OGPangoFontFamily;
@class OGPangoFont;
@class OGPangoContext;

/**
 * The #PangoFontMap represents the set of fonts available for a
 * particular rendering system. This is a virtual object with
 * implementations being specific to particular rendering systems.  To
 * create an implementation of a #PangoFontMap, the rendering-system
 * specific code should allocate a larger structure that contains a nested
 * #PangoFontMap, fill in the <structfield>klass</structfield> member of the nested #PangoFontMap with a
 * pointer to a appropriate #PangoFontMapClass, then call
 * pango_font_map_init() on the structure.
 * 
 * The #PangoFontMap structure contains one member which the implementation
 * fills in.
 *
 */
@interface OGPangoFontMap : OGObject
{

}


/**
 * Methods
 */

- (PangoFontMap*)FONTMAP;

/**
 * Forces a change in the context, which will cause any #PangoContext
 * using this fontmap to change.
 * 
 * This function is only useful when implementing a new backend
 * for Pango, something applications won't do. Backends should
 * call this function if they have attached extra data to the context
 * and such data is changed.
 *
 */
- (void)changed;

/**
 * Creates a #PangoContext connected to @fontmap.  This is equivalent
 * to pango_context_new() followed by pango_context_set_font_map().
 * 
 * If you are using Pango as part of a higher-level system,
 * that system may have it's own way of create a #PangoContext.
 * For instance, the GTK+ toolkit has, among others,
 * gdk_pango_context_get_for_screen(), and
 * gtk_widget_get_pango_context().  Use those instead.
 *
 * @return the newly allocated #PangoContext,
 *               which should be freed with g_object_unref().
 */
- (OGPangoContext*)createContext;

/**
 * Gets a font family by name.
 *
 * @param name a family name
 * @return the #PangoFontFamily
 */
- (OGPangoFontFamily*)family:(OFString*)name;

/**
 * Returns the current serial number of @fontmap.  The serial number is
 * initialized to an small number larger than zero when a new fontmap
 * is created and is increased whenever the fontmap is changed. It may
 * wrap, but will never have the value 0. Since it can wrap, never compare
 * it with "less than", always use "not equals".
 * 
 * The fontmap can only be changed using backend-specific API, like changing
 * fontmap resolution.
 * 
 * This can be used to automatically detect changes to a #PangoFontMap, like
 * in #PangoContext.
 *
 * @return The current serial number of @fontmap.
 */
- (guint)serial;

/**
 * List all families for a fontmap.
 *
 * @param families location to store a pointer to an array of #PangoFontFamily *.
 *            This array should be freed with g_free().
 * @param nfamilies location to store the number of elements in @families
 */
- (void)listFamiliesWithFamilies:(PangoFontFamily***)families nfamilies:(int*)nfamilies;

/**
 * Load the font in the fontmap that is the closest match for @desc.
 *
 * @param context the #PangoContext the font will be used with
 * @param desc a #PangoFontDescription describing the font to load
 * @return the newly allocated #PangoFont
 *          loaded, or %NULL if no font matched.
 */
- (OGPangoFont*)loadFontWithContext:(OGPangoContext*)context desc:(const PangoFontDescription*)desc;

/**
 * Load a set of fonts in the fontmap that can be used to render
 * a font matching @desc.
 *
 * @param context the #PangoContext the font will be used with
 * @param desc a #PangoFontDescription describing the font to load
 * @param language a #PangoLanguage the fonts will be used for
 * @return the newly allocated
 *          #PangoFontset loaded, or %NULL if no font matched.
 */
- (OGPangoFontset*)loadFontsetWithContext:(OGPangoContext*)context desc:(const PangoFontDescription*)desc language:(PangoLanguage*)language;

@end