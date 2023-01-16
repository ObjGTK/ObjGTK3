/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkMisc.h"

@implementation OGAtkMisc

+ (const AtkMisc*)instance
{
	return atk_misc_get_instance();
}

- (AtkMisc*)MISC
{
	return ATK_MISC([self GOBJECT]);
}

- (void)threadsEnter
{
	atk_misc_threads_enter([self MISC]);
}

- (void)threadsLeave
{
	atk_misc_threads_leave([self MISC]);
}


@end