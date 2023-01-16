/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStackSwitcher.h"

#import "OGTKStack.h"
#import "OGTKWidget.h"

@implementation OGTKStackSwitcher

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_stack_switcher_new()];

	return self;
}

- (GtkStackSwitcher*)STACKSWITCHER
{
	return GTK_STACK_SWITCHER([self GOBJECT]);
}

- (OGTKStack*)stack
{
	return [[[OGTKStack alloc] initWithGObject:(GObject*)gtk_stack_switcher_get_stack([self STACKSWITCHER])] autorelease];
}

- (void)setStack:(OGTKStack*)stack
{
	gtk_stack_switcher_set_stack([self STACKSWITCHER], [stack STACK]);
}


@end