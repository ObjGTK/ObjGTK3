/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAccelLabel.h"

#import "OGTKWidget.h"

@implementation OGTKAccelLabel

- (instancetype)init:(OFString*)string
{
	self = [super initWithGObject:(GObject*)gtk_accel_label_new([string UTF8String])];

	return self;
}

- (GtkAccelLabel*)ACCELLABEL
{
	return GTK_ACCEL_LABEL([self GOBJECT]);
}

- (void)accelWithAcceleratorKey:(guint*)acceleratorKey acceleratorMods:(GdkModifierType*)acceleratorMods
{
	gtk_accel_label_get_accel([self ACCELLABEL], acceleratorKey, acceleratorMods);
}

- (OGTKWidget*)accelWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_accel_label_get_accel_widget([self ACCELLABEL])] autorelease];
}

- (guint)accelWidth
{
	return gtk_accel_label_get_accel_width([self ACCELLABEL]);
}

- (bool)refetch
{
	return gtk_accel_label_refetch([self ACCELLABEL]);
}

- (void)setAccelWithAcceleratorKey:(guint)acceleratorKey acceleratorMods:(GdkModifierType)acceleratorMods
{
	gtk_accel_label_set_accel([self ACCELLABEL], acceleratorKey, acceleratorMods);
}

- (void)setAccelClosure:(GClosure*)accelClosure
{
	gtk_accel_label_set_accel_closure([self ACCELLABEL], accelClosure);
}

- (void)setAccelWidget:(OGTKWidget*)accelWidget
{
	gtk_accel_label_set_accel_widget([self ACCELLABEL], [accelWidget WIDGET]);
}


@end