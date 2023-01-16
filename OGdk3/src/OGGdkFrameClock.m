/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkFrameClock.h"

@implementation OGGdkFrameClock

- (GdkFrameClock*)FRAMECLOCK
{
	return GDK_FRAME_CLOCK([self GOBJECT]);
}

- (void)beginUpdating
{
	gdk_frame_clock_begin_updating([self FRAMECLOCK]);
}

- (void)endUpdating
{
	gdk_frame_clock_end_updating([self FRAMECLOCK]);
}

- (GdkFrameTimings*)currentTimings
{
	return gdk_frame_clock_get_current_timings([self FRAMECLOCK]);
}

- (gint64)frameCounter
{
	return gdk_frame_clock_get_frame_counter([self FRAMECLOCK]);
}

- (gint64)frameTime
{
	return gdk_frame_clock_get_frame_time([self FRAMECLOCK]);
}

- (gint64)historyStart
{
	return gdk_frame_clock_get_history_start([self FRAMECLOCK]);
}

- (void)refreshInfoWithBaseTime:(gint64)baseTime refreshIntervalReturn:(gint64*)refreshIntervalReturn presentationTimeReturn:(gint64*)presentationTimeReturn
{
	gdk_frame_clock_get_refresh_info([self FRAMECLOCK], baseTime, refreshIntervalReturn, presentationTimeReturn);
}

- (GdkFrameTimings*)timings:(gint64)frameCounter
{
	return gdk_frame_clock_get_timings([self FRAMECLOCK], frameCounter);
}

- (void)requestPhase:(GdkFrameClockPhase)phase
{
	gdk_frame_clock_request_phase([self FRAMECLOCK], phase);
}


@end