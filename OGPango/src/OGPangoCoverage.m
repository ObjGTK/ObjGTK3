/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoCoverage.h"

@implementation OGPangoCoverage

+ (OGPangoCoverage*)fromBytesWithBytes:(guchar*)bytes nbytes:(int)nbytes
{
	return [[[OGPangoCoverage alloc] initWithGObject:(GObject*)pango_coverage_from_bytes(bytes, nbytes)] autorelease];
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)pango_coverage_new()];

	return self;
}

- (PangoCoverage*)COVERAGE
{
	return PANGO_COVERAGE([self GOBJECT]);
}

- (OGPangoCoverage*)copy
{
	return [[[OGPangoCoverage alloc] initWithGObject:(GObject*)pango_coverage_copy([self COVERAGE])] autorelease];
}

- (PangoCoverageLevel):(int)index
{
	return pango_coverage_get([self COVERAGE], index);
}

- (void)max:(OGPangoCoverage*)other
{
	pango_coverage_max([self COVERAGE], [other COVERAGE]);
}

- (void)setWithIndex:(int)index level:(PangoCoverageLevel)level
{
	pango_coverage_set([self COVERAGE], index, level);
}

- (void)toBytesWithBytes:(guchar**)bytes nbytes:(int*)nbytes
{
	pango_coverage_to_bytes([self COVERAGE], bytes, nbytes);
}


@end