/*
 * OGTKProgressBar.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKProgressBar.h"

@implementation OGTKProgressBar

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_progress_bar_new()];

	return self;
}

- (GtkProgressBar*)PROGRESSBAR
{
	return GTK_PROGRESS_BAR([self GOBJECT]);
}

- (PangoEllipsizeMode)getEllipsize
{
	return gtk_progress_bar_get_ellipsize(GTK_PROGRESS_BAR([self GOBJECT]));
}

- (gdouble)getFraction
{
	return gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR([self GOBJECT]));
}

- (bool)getInverted
{
	return gtk_progress_bar_get_inverted(GTK_PROGRESS_BAR([self GOBJECT]));
}

- (gdouble)getPulseStep
{
	return gtk_progress_bar_get_pulse_step(GTK_PROGRESS_BAR([self GOBJECT]));
}

- (bool)getShowText
{
	return gtk_progress_bar_get_show_text(GTK_PROGRESS_BAR([self GOBJECT]));
}

- (OFString*)getText
{
	return [OFString stringWithUTF8String:gtk_progress_bar_get_text(GTK_PROGRESS_BAR([self GOBJECT]))];
}

- (void)pulse
{
	gtk_progress_bar_pulse(GTK_PROGRESS_BAR([self GOBJECT]));
}

- (void)setEllipsize:(PangoEllipsizeMode)mode
{
	gtk_progress_bar_set_ellipsize(GTK_PROGRESS_BAR([self GOBJECT]), mode);
}

- (void)setFraction:(gdouble)fraction
{
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR([self GOBJECT]), fraction);
}

- (void)setInverted:(bool)inverted
{
	gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR([self GOBJECT]), inverted);
}

- (void)setPulseStep:(gdouble)fraction
{
	gtk_progress_bar_set_pulse_step(GTK_PROGRESS_BAR([self GOBJECT]), fraction);
}

- (void)setShowText:(bool)showText
{
	gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR([self GOBJECT]), showText);
}

- (void)setText:(OFString*)text
{
	gtk_progress_bar_set_text(GTK_PROGRESS_BAR([self GOBJECT]), [text UTF8String]);
}


@end