/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKShortcutLabel.h"

#import "OGTKWidget.h"

@implementation OGTKShortcutLabel

- (instancetype)init:(OFString*)accelerator
{
	self = [super initWithGObject:(GObject*)gtk_shortcut_label_new([accelerator UTF8String])];

	return self;
}

- (GtkShortcutLabel*)SHORTCUTLABEL
{
	return GTK_SHORTCUT_LABEL([self GOBJECT]);
}

- (OFString*)accelerator
{
	return [OFString stringWithUTF8String:gtk_shortcut_label_get_accelerator([self SHORTCUTLABEL])];
}

- (OFString*)disabledText
{
	return [OFString stringWithUTF8String:gtk_shortcut_label_get_disabled_text([self SHORTCUTLABEL])];
}

- (void)setAccelerator:(OFString*)accelerator
{
	gtk_shortcut_label_set_accelerator([self SHORTCUTLABEL], [accelerator UTF8String]);
}

- (void)setDisabledText:(OFString*)disabledText
{
	gtk_shortcut_label_set_disabled_text([self SHORTCUTLABEL], [disabledText UTF8String]);
}


@end