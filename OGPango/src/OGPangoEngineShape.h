/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoEngine.h"

/**
 * The #PangoEngineShape class is implemented by engines that
 * customize the rendering-system dependent part of the
 * Pango pipeline for a particular script or language.
 * A #PangoEngineShape implementation is then specific to both
 * a particular rendering system or group of rendering systems
 * and to a particular script. For instance, there is one
 * #PangoEngineShape implementation to handle shaping Arabic
 * for Fontconfig-based backends.
 *
 */
@interface OGPangoEngineShape : OGPangoEngine
{

}


/**
 * Methods
 */

- (PangoEngineShape*)ENGINESHAPE;

@end