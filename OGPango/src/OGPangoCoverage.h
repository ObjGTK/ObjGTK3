/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <pango/pango.h>

#import <OGObject/OGObject.h>

/**
 * The #PangoCoverage structure represents a map from Unicode characters
 * to #PangoCoverageLevel. It is an opaque structure with no public fields.
 *
 */
@interface OGPangoCoverage : OGObject
{

}

/**
 * Functions
 */
+ (OGPangoCoverage*)fromBytesWithBytes:(guchar*)bytes nbytes:(int)nbytes;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (PangoCoverage*)COVERAGE;

/**
 * Copy an existing #PangoCoverage. (This function may now be unnecessary
 * since we refcount the structure. File a bug if you use it.)
 *
 * @return the newly allocated #PangoCoverage,
 *               with a reference count of one, which should be freed
 *               with pango_coverage_unref().
 */
- (OGPangoCoverage*)copy;

/**
 * Determine whether a particular index is covered by @coverage
 *
 * @param index the index to check
 * @return the coverage level of @coverage for character @index_.
 */
- (PangoCoverageLevel):(int)index;

/**
 * Set the coverage for each index in @coverage to be the max (better)
 * value of the current coverage for the index and the coverage for
 * the corresponding index in @other.
 *
 * @param other another #PangoCoverage
 */
- (void)max:(OGPangoCoverage*)other;

/**
 * Modify a particular index within @coverage
 *
 * @param index the index to modify
 * @param level the new level for @index_
 */
- (void)setWithIndex:(int)index level:(PangoCoverageLevel)level;

/**
 * Convert a #PangoCoverage structure into a flat binary format
 *
 * @param bytes location to store result (must be freed with g_free())
 * @param nbytes location to store size of result
 */
- (void)toBytesWithBytes:(guchar**)bytes nbytes:(int*)nbytes;

@end