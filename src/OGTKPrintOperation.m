/*
 * OGTKPrintOperation.m
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
#import "OGTKPrintOperation.h"

@implementation OGTKPrintOperation

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_print_operation_new()];

	return self;
}

- (GtkPrintOperation*)PRINTOPERATION
{
	return GTK_PRINT_OPERATION([self GOBJECT]);
}

- (void)cancel
{
	gtk_print_operation_cancel(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (void)drawPageFinish
{
	gtk_print_operation_draw_page_finish(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (GtkPageSetup*)getDefaultPageSetup
{
	return gtk_print_operation_get_default_page_setup(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (bool)getEmbedPageSetup
{
	return gtk_print_operation_get_embed_page_setup(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (void)getError
{
	gtk_print_operation_get_error(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (bool)getHasSelection
{
	return gtk_print_operation_get_has_selection(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (gint)getNpagesToPrint
{
	return gtk_print_operation_get_n_pages_to_print(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (GtkPrintSettings*)getPrintSettings
{
	return gtk_print_operation_get_print_settings(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (GtkPrintStatus)getStatus
{
	return gtk_print_operation_get_status(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (OFString*)getStatusString
{
	return [OFString stringWithUTF8String:gtk_print_operation_get_status_string(GTK_PRINT_OPERATION([self GOBJECT]))];
}

- (bool)getSupportSelection
{
	return gtk_print_operation_get_support_selection(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (bool)isFinished
{
	return gtk_print_operation_is_finished(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (GtkPrintOperationResult)runWithAction:(GtkPrintOperationAction)action andParent:(GtkWindow*)parent
{
	return gtk_print_operation_run(GTK_PRINT_OPERATION([self GOBJECT]), action, parent);
}

- (void)setAllowAsync:(bool)allowAsync
{
	gtk_print_operation_set_allow_async(GTK_PRINT_OPERATION([self GOBJECT]), allowAsync);
}

- (void)setCurrentPage:(gint)currentPage
{
	gtk_print_operation_set_current_page(GTK_PRINT_OPERATION([self GOBJECT]), currentPage);
}

- (void)setCustomTabLabel:(OFString*)label
{
	gtk_print_operation_set_custom_tab_label(GTK_PRINT_OPERATION([self GOBJECT]), [label UTF8String]);
}

- (void)setDefaultPageSetup:(GtkPageSetup*)defaultPageSetup
{
	gtk_print_operation_set_default_page_setup(GTK_PRINT_OPERATION([self GOBJECT]), defaultPageSetup);
}

- (void)setDeferDrawing
{
	gtk_print_operation_set_defer_drawing(GTK_PRINT_OPERATION([self GOBJECT]));
}

- (void)setEmbedPageSetup:(bool)embed
{
	gtk_print_operation_set_embed_page_setup(GTK_PRINT_OPERATION([self GOBJECT]), embed);
}

- (void)setExportFilename:(OFString*)filename
{
	gtk_print_operation_set_export_filename(GTK_PRINT_OPERATION([self GOBJECT]), [filename UTF8String]);
}

- (void)setHasSelection:(bool)hasSelection
{
	gtk_print_operation_set_has_selection(GTK_PRINT_OPERATION([self GOBJECT]), hasSelection);
}

- (void)setJobName:(OFString*)jobName
{
	gtk_print_operation_set_job_name(GTK_PRINT_OPERATION([self GOBJECT]), [jobName UTF8String]);
}

- (void)setNpages:(gint)npages
{
	gtk_print_operation_set_n_pages(GTK_PRINT_OPERATION([self GOBJECT]), npages);
}

- (void)setPrintSettings:(GtkPrintSettings*)printSettings
{
	gtk_print_operation_set_print_settings(GTK_PRINT_OPERATION([self GOBJECT]), printSettings);
}

- (void)setShowProgress:(bool)showProgress
{
	gtk_print_operation_set_show_progress(GTK_PRINT_OPERATION([self GOBJECT]), showProgress);
}

- (void)setSupportSelection:(bool)supportSelection
{
	gtk_print_operation_set_support_selection(GTK_PRINT_OPERATION([self GOBJECT]), supportSelection);
}

- (void)setTrackPrintStatus:(bool)trackStatus
{
	gtk_print_operation_set_track_print_status(GTK_PRINT_OPERATION([self GOBJECT]), trackStatus);
}

- (void)setUnit:(GtkUnit)unit
{
	gtk_print_operation_set_unit(GTK_PRINT_OPERATION([self GOBJECT]), unit);
}

- (void)setUseFullPage:(bool)fullPage
{
	gtk_print_operation_set_use_full_page(GTK_PRINT_OPERATION([self GOBJECT]), fullPage);
}


@end