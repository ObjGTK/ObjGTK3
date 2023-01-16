/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKProgressBar.h"

@implementation OGTKProgressBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_progress_bar_new()];

	return self;
}

- (GtkProgressBar*)PROGRESSBAR
{
	return GTK_PROGRESS_BAR([self GOBJECT]);
}

- (PangoEllipsizeMode)ellipsize
{
	return gtk_progress_bar_get_ellipsize([self PROGRESSBAR]);
}

- (gdouble)fraction
{
	return gtk_progress_bar_get_fraction([self PROGRESSBAR]);
}

- (bool)inverted
{
	return gtk_progress_bar_get_inverted([self PROGRESSBAR]);
}

- (gdouble)pulseStep
{
	return gtk_progress_bar_get_pulse_step([self PROGRESSBAR]);
}

- (bool)showText
{
	return gtk_progress_bar_get_show_text([self PROGRESSBAR]);
}

- (OFString*)text
{
	return [OFString stringWithUTF8String:gtk_progress_bar_get_text([self PROGRESSBAR])];
}

- (void)pulse
{
	gtk_progress_bar_pulse([self PROGRESSBAR]);
}

- (void)setEllipsize:(PangoEllipsizeMode)mode
{
	gtk_progress_bar_set_ellipsize([self PROGRESSBAR], mode);
}

- (void)setFraction:(gdouble)fraction
{
	gtk_progress_bar_set_fraction([self PROGRESSBAR], fraction);
}

- (void)setInverted:(bool)inverted
{
	gtk_progress_bar_set_inverted([self PROGRESSBAR], inverted);
}

- (void)setPulseStep:(gdouble)fraction
{
	gtk_progress_bar_set_pulse_step([self PROGRESSBAR], fraction);
}

- (void)setShowText:(bool)showText
{
	gtk_progress_bar_set_show_text([self PROGRESSBAR], showText);
}

- (void)setText:(OFString*)text
{
	gtk_progress_bar_set_text([self PROGRESSBAR], [text UTF8String]);
}


@end