/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPrintOperation.h"

#import "OGTKWindow.h"
#import "OGTKPrintSettings.h"
#import "OGTKPageSetup.h"

@implementation OGTKPrintOperation

- (instancetype)init
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
	gtk_print_operation_cancel([self PRINTOPERATION]);
}

- (void)drawPageFinish
{
	gtk_print_operation_draw_page_finish([self PRINTOPERATION]);
}

- (OGTKPageSetup*)defaultPageSetup
{
	return [[[OGTKPageSetup alloc] initWithGObject:(GObject*)gtk_print_operation_get_default_page_setup([self PRINTOPERATION])] autorelease];
}

- (bool)embedPageSetup
{
	return gtk_print_operation_get_embed_page_setup([self PRINTOPERATION]);
}

- (void)error:(GError**)err
{
	gtk_print_operation_get_error([self PRINTOPERATION], err);
}

- (bool)hasSelection
{
	return gtk_print_operation_get_has_selection([self PRINTOPERATION]);
}

- (gint)npagesToPrint
{
	return gtk_print_operation_get_n_pages_to_print([self PRINTOPERATION]);
}

- (OGTKPrintSettings*)printSettings
{
	return [[[OGTKPrintSettings alloc] initWithGObject:(GObject*)gtk_print_operation_get_print_settings([self PRINTOPERATION])] autorelease];
}

- (GtkPrintStatus)status
{
	return gtk_print_operation_get_status([self PRINTOPERATION]);
}

- (OFString*)statusString
{
	return [OFString stringWithUTF8String:gtk_print_operation_get_status_string([self PRINTOPERATION])];
}

- (bool)supportSelection
{
	return gtk_print_operation_get_support_selection([self PRINTOPERATION]);
}

- (bool)isFinished
{
	return gtk_print_operation_is_finished([self PRINTOPERATION]);
}

- (GtkPrintOperationResult)runWithAction:(GtkPrintOperationAction)action parent:(OGTKWindow*)parent err:(GError**)err
{
	return gtk_print_operation_run([self PRINTOPERATION], action, [parent WINDOW], err);
}

- (void)setAllowAsync:(bool)allowAsync
{
	gtk_print_operation_set_allow_async([self PRINTOPERATION], allowAsync);
}

- (void)setCurrentPage:(gint)currentPage
{
	gtk_print_operation_set_current_page([self PRINTOPERATION], currentPage);
}

- (void)setCustomTabLabel:(OFString*)label
{
	gtk_print_operation_set_custom_tab_label([self PRINTOPERATION], [label UTF8String]);
}

- (void)setDefaultPageSetup:(OGTKPageSetup*)defaultPageSetup
{
	gtk_print_operation_set_default_page_setup([self PRINTOPERATION], [defaultPageSetup PAGESETUP]);
}

- (void)setDeferDrawing
{
	gtk_print_operation_set_defer_drawing([self PRINTOPERATION]);
}

- (void)setEmbedPageSetup:(bool)embed
{
	gtk_print_operation_set_embed_page_setup([self PRINTOPERATION], embed);
}

- (void)setExportFilename:(OFString*)filename
{
	gtk_print_operation_set_export_filename([self PRINTOPERATION], [filename UTF8String]);
}

- (void)setHasSelection:(bool)hasSelection
{
	gtk_print_operation_set_has_selection([self PRINTOPERATION], hasSelection);
}

- (void)setJobName:(OFString*)jobName
{
	gtk_print_operation_set_job_name([self PRINTOPERATION], [jobName UTF8String]);
}

- (void)setNpages:(gint)npages
{
	gtk_print_operation_set_n_pages([self PRINTOPERATION], npages);
}

- (void)setPrintSettings:(OGTKPrintSettings*)printSettings
{
	gtk_print_operation_set_print_settings([self PRINTOPERATION], [printSettings PRINTSETTINGS]);
}

- (void)setShowProgress:(bool)showProgress
{
	gtk_print_operation_set_show_progress([self PRINTOPERATION], showProgress);
}

- (void)setSupportSelection:(bool)supportSelection
{
	gtk_print_operation_set_support_selection([self PRINTOPERATION], supportSelection);
}

- (void)setTrackPrintStatus:(bool)trackStatus
{
	gtk_print_operation_set_track_print_status([self PRINTOPERATION], trackStatus);
}

- (void)setUnit:(GtkUnit)unit
{
	gtk_print_operation_set_unit([self PRINTOPERATION], unit);
}

- (void)setUseFullPage:(bool)fullPage
{
	gtk_print_operation_set_use_full_page([self PRINTOPERATION], fullPage);
}


@end