/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStackSidebar.h"

#import "OGTKStack.h"
#import "OGTKWidget.h"

@implementation OGTKStackSidebar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_stack_sidebar_new()];

	return self;
}

- (GtkStackSidebar*)STACKSIDEBAR
{
	return GTK_STACK_SIDEBAR([self GOBJECT]);
}

- (OGTKStack*)stack
{
	return [[[OGTKStack alloc] initWithGObject:(GObject*)gtk_stack_sidebar_get_stack([self STACKSIDEBAR])] autorelease];
}

- (void)setStack:(OGTKStack*)stack
{
	gtk_stack_sidebar_set_stack([self STACKSIDEBAR], [stack STACK]);
}


@end