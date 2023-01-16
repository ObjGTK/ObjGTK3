/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPadController.h"

#import "OGTKWindow.h"
#import <OGdk3/OGGdkDevice.h>

@implementation OGTKPadController

- (instancetype)initWithWindow:(OGTKWindow*)window group:(GActionGroup*)group pad:(OGGdkDevice*)pad
{
	self = [super initWithGObject:(GObject*)gtk_pad_controller_new([window WINDOW], group, [pad DEVICE])];

	return self;
}

- (GtkPadController*)PADCONTROLLER
{
	return GTK_PAD_CONTROLLER([self GOBJECT]);
}

- (void)setActionWithType:(GtkPadActionType)type index:(gint)index mode:(gint)mode label:(OFString*)label actionName:(OFString*)actionName
{
	gtk_pad_controller_set_action([self PADCONTROLLER], type, index, mode, [label UTF8String], [actionName UTF8String]);
}

- (void)setActionEntriesWithEntries:(const GtkPadActionEntry*)entries nentries:(gint)nentries
{
	gtk_pad_controller_set_action_entries([self PADCONTROLLER], entries, nentries);
}


@end