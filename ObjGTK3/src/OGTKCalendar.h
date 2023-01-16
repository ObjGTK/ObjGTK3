/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

/**
 * #GtkCalendar is a widget that displays a Gregorian calendar, one month
 * at a time. It can be created with gtk_calendar_new().
 * 
 * The month and year currently displayed can be altered with
 * gtk_calendar_select_month(). The exact day can be selected from the
 * displayed month using gtk_calendar_select_day().
 * 
 * To place a visual marker on a particular day, use gtk_calendar_mark_day()
 * and to remove the marker, gtk_calendar_unmark_day(). Alternative, all
 * marks can be cleared with gtk_calendar_clear_marks().
 * 
 * The way in which the calendar itself is displayed can be altered using
 * gtk_calendar_set_display_options().
 * 
 * The selected date can be retrieved from a #GtkCalendar using
 * gtk_calendar_get_date().
 * 
 * Users should be aware that, although the Gregorian calendar is the
 * legal calendar in most countries, it was adopted progressively
 * between 1582 and 1929. Display before these dates is likely to be
 * historically incorrect.
 *
 */
@interface OGTKCalendar : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkCalendar*)CALENDAR;

/**
 * Remove all visual markers.
 *
 */
- (void)clearMarks;

/**
 * Obtains the selected date from a #GtkCalendar.
 *
 * @param year location to store the year as a decimal
 *     number (e.g. 2011), or %NULL
 * @param month location to store the month number
 *     (between 0 and 11), or %NULL
 * @param day location to store the day number (between
 *     1 and 31), or %NULL
 */
- (void)dateWithYear:(guint*)year month:(guint*)month day:(guint*)day;

/**
 * Returns if the @day of the @calendar is already marked.
 *
 * @param day the day number between 1 and 31.
 * @return whether the day is marked.
 */
- (bool)dayIsMarked:(guint)day;

/**
 * Queries the height of detail cells, in rows.
 * See #GtkCalendar:detail-width-chars.
 *
 * @return The height of detail cells, in rows.
 */
- (gint)detailHeightRows;

/**
 * Queries the width of detail cells, in characters.
 * See #GtkCalendar:detail-width-chars.
 *
 * @return The width of detail cells, in characters.
 */
- (gint)detailWidthChars;

/**
 * Returns the current display options of @calendar.
 *
 * @return the display options.
 */
- (GtkCalendarDisplayOptions)displayOptions;

/**
 * Places a visual marker on a particular day.
 *
 * @param day the day number to mark between 1 and 31.
 */
- (void)markDay:(guint)day;

/**
 * Selects a day from the current month.
 *
 * @param day the day number between 1 and 31, or 0 to unselect
 *   the currently selected day.
 */
- (void)selectDay:(guint)day;

/**
 * Shifts the calendar to a different month.
 *
 * @param month a month number between 0 and 11.
 * @param year the year the month is in.
 */
- (void)selectMonthWithMonth:(guint)month year:(guint)year;

/**
 * Installs a function which provides Pango markup with detail information
 * for each day. Examples for such details are holidays or appointments. That
 * information is shown below each day when #GtkCalendar:show-details is set.
 * A tooltip containing with full detail information is provided, if the entire
 * text should not fit into the details area, or if #GtkCalendar:show-details
 * is not set.
 * 
 * The size of the details area can be restricted by setting the
 * #GtkCalendar:detail-width-chars and #GtkCalendar:detail-height-rows
 * properties.
 *
 * @param func a function providing details for each day.
 * @param data data to pass to @func invokations.
 * @param destroy a function for releasing @data.
 */
- (void)setDetailFuncWithFunc:(GtkCalendarDetailFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy;

/**
 * Updates the height of detail cells.
 * See #GtkCalendar:detail-height-rows.
 *
 * @param rows detail height in rows.
 */
- (void)setDetailHeightRows:(gint)rows;

/**
 * Updates the width of detail cells.
 * See #GtkCalendar:detail-width-chars.
 *
 * @param chars detail width in characters.
 */
- (void)setDetailWidthChars:(gint)chars;

/**
 * Sets display options (whether to display the heading and the month
 * headings).
 *
 * @param flags the display options to set
 */
- (void)setDisplayOptions:(GtkCalendarDisplayOptions)flags;

/**
 * Removes the visual marker from a particular day.
 *
 * @param day the day number to unmark between 1 and 31.
 */
- (void)unmarkDay:(guint)day;

@end