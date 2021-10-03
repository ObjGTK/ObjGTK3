/*
 * OGTKPrintOperation.h
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
#import "OGTKBase.h"

@interface OGTKPrintOperation : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkPrintOperation*)PRINTOPERATION;

/**
 * - (void*)cancel;
 *
 */
- (void)cancel;

/**
 * - (void*)drawPageFinish;
 *
 */
- (void)drawPageFinish;

/**
 * - (GtkPageSetup**)getDefaultPageSetup;
 *
 * @returns GtkPageSetup*
 */
- (GtkPageSetup*)getDefaultPageSetup;

/**
 * - (bool*)getEmbedPageSetup;
 *
 * @returns bool
 */
- (bool)getEmbedPageSetup;

/**
 * - (void*)getError;
 *
 */
- (void)getError;

/**
 * - (bool*)getHasSelection;
 *
 * @returns bool
 */
- (bool)getHasSelection;

/**
 * - (gint*)getNpagesToPrint;
 *
 * @returns gint
 */
- (gint)getNpagesToPrint;

/**
 * - (GtkPrintSettings**)getPrintSettings;
 *
 * @returns GtkPrintSettings*
 */
- (GtkPrintSettings*)getPrintSettings;

/**
 * - (GtkPrintStatus*)getStatus;
 *
 * @returns GtkPrintStatus
 */
- (GtkPrintStatus)getStatus;

/**
 * - (OFString**)getStatusString;
 *
 * @returns OFString*
 */
- (OFString*)getStatusString;

/**
 * - (bool*)getSupportSelection;
 *
 * @returns bool
 */
- (bool)getSupportSelection;

/**
 * - (bool*)isFinished;
 *
 * @returns bool
 */
- (bool)isFinished;

/**
 * - (GtkPrintOperationResult*)runWithAction:(GtkPrintOperationAction)action andParent:(GtkWindow*)parent;
 *
 * @param action
 * @param parent
 * @returns GtkPrintOperationResult
 */
- (GtkPrintOperationResult)runWithAction:(GtkPrintOperationAction)action andParent:(GtkWindow*)parent;

/**
 * - (void*)setAllowAsync:(bool)allowAsync;
 *
 * @param allowAsync
 */
- (void)setAllowAsync:(bool)allowAsync;

/**
 * - (void*)setCurrentPage:(gint)currentPage;
 *
 * @param currentPage
 */
- (void)setCurrentPage:(gint)currentPage;

/**
 * - (void*)setCustomTabLabel:(OFString*)label;
 *
 * @param label
 */
- (void)setCustomTabLabel:(OFString*)label;

/**
 * - (void*)setDefaultPageSetup:(GtkPageSetup*)defaultPageSetup;
 *
 * @param defaultPageSetup
 */
- (void)setDefaultPageSetup:(GtkPageSetup*)defaultPageSetup;

/**
 * - (void*)setDeferDrawing;
 *
 */
- (void)setDeferDrawing;

/**
 * - (void*)setEmbedPageSetup:(bool)embed;
 *
 * @param embed
 */
- (void)setEmbedPageSetup:(bool)embed;

/**
 * - (void*)setExportFilename:(OFString*)filename;
 *
 * @param filename
 */
- (void)setExportFilename:(OFString*)filename;

/**
 * - (void*)setHasSelection:(bool)hasSelection;
 *
 * @param hasSelection
 */
- (void)setHasSelection:(bool)hasSelection;

/**
 * - (void*)setJobName:(OFString*)jobName;
 *
 * @param jobName
 */
- (void)setJobName:(OFString*)jobName;

/**
 * - (void*)setNpages:(gint)npages;
 *
 * @param npages
 */
- (void)setNpages:(gint)npages;

/**
 * - (void*)setPrintSettings:(GtkPrintSettings*)printSettings;
 *
 * @param printSettings
 */
- (void)setPrintSettings:(GtkPrintSettings*)printSettings;

/**
 * - (void*)setShowProgress:(bool)showProgress;
 *
 * @param showProgress
 */
- (void)setShowProgress:(bool)showProgress;

/**
 * - (void*)setSupportSelection:(bool)supportSelection;
 *
 * @param supportSelection
 */
- (void)setSupportSelection:(bool)supportSelection;

/**
 * - (void*)setTrackPrintStatus:(bool)trackStatus;
 *
 * @param trackStatus
 */
- (void)setTrackPrintStatus:(bool)trackStatus;

/**
 * - (void*)setUnit:(GtkUnit)unit;
 *
 * @param unit
 */
- (void)setUnit:(GtkUnit)unit;

/**
 * - (void*)setUseFullPage:(bool)fullPage;
 *
 * @param fullPage
 */
- (void)setUseFullPage:(bool)fullPage;

@end