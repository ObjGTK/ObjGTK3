/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCalendar.h"

@implementation OGTKCalendar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_calendar_new()];

	return self;
}

- (GtkCalendar*)CALENDAR
{
	return GTK_CALENDAR([self GOBJECT]);
}

- (void)clearMarks
{
	gtk_calendar_clear_marks([self CALENDAR]);
}

- (void)dateWithYear:(guint*)year month:(guint*)month day:(guint*)day
{
	gtk_calendar_get_date([self CALENDAR], year, month, day);
}

- (bool)dayIsMarked:(guint)day
{
	return gtk_calendar_get_day_is_marked([self CALENDAR], day);
}

- (gint)detailHeightRows
{
	return gtk_calendar_get_detail_height_rows([self CALENDAR]);
}

- (gint)detailWidthChars
{
	return gtk_calendar_get_detail_width_chars([self CALENDAR]);
}

- (GtkCalendarDisplayOptions)displayOptions
{
	return gtk_calendar_get_display_options([self CALENDAR]);
}

- (void)markDay:(guint)day
{
	gtk_calendar_mark_day([self CALENDAR], day);
}

- (void)selectDay:(guint)day
{
	gtk_calendar_select_day([self CALENDAR], day);
}

- (void)selectMonthWithMonth:(guint)month year:(guint)year
{
	gtk_calendar_select_month([self CALENDAR], month, year);
}

- (void)setDetailFuncWithFunc:(GtkCalendarDetailFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_calendar_set_detail_func([self CALENDAR], func, data, destroy);
}

- (void)setDetailHeightRows:(gint)rows
{
	gtk_calendar_set_detail_height_rows([self CALENDAR], rows);
}

- (void)setDetailWidthChars:(gint)chars
{
	gtk_calendar_set_detail_width_chars([self CALENDAR], chars);
}

- (void)setDisplayOptions:(GtkCalendarDisplayOptions)flags
{
	gtk_calendar_set_display_options([self CALENDAR], flags);
}

- (void)unmarkDay:(guint)day
{
	gtk_calendar_unmark_day([self CALENDAR], day);
}


@end