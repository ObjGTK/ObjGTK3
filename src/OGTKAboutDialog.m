/*
 * OGTKAboutDialog.m
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
#import "OGTKAboutDialog.h"

@implementation OGTKAboutDialog

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_about_dialog_new()];

	return self;
}

- (GtkAboutDialog*)ABOUTDIALOG
{
	return GTK_ABOUT_DIALOG([self GOBJECT]);
}

- (void)addCreditSectionWithSectionName:(OFString*)sectionName andPeople:(const gchar**)people
{
	gtk_about_dialog_add_credit_section(GTK_ABOUT_DIALOG([self GOBJECT]), [sectionName UTF8String], people);
}

- (const gchar* const*)getArtists
{
	return gtk_about_dialog_get_artists(GTK_ABOUT_DIALOG([self GOBJECT]));
}

- (const gchar* const*)getAuthors
{
	return gtk_about_dialog_get_authors(GTK_ABOUT_DIALOG([self GOBJECT]));
}

- (OFString*)getComments
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_comments(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (OFString*)getCopyright
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_copyright(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (const gchar* const*)getDocumenters
{
	return gtk_about_dialog_get_documenters(GTK_ABOUT_DIALOG([self GOBJECT]));
}

- (OFString*)getLicense
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_license(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (GtkLicense)getLicenseType
{
	return gtk_about_dialog_get_license_type(GTK_ABOUT_DIALOG([self GOBJECT]));
}

- (GdkPixbuf*)getLogo
{
	return gtk_about_dialog_get_logo(GTK_ABOUT_DIALOG([self GOBJECT]));
}

- (OFString*)getLogoIconName
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_logo_icon_name(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (OFString*)getProgramName
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_program_name(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (OFString*)getTranslatorCredits
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_translator_credits(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (OFString*)getVersion
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_version(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (OFString*)getWebsite
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_website(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (OFString*)getWebsiteLabel
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_website_label(GTK_ABOUT_DIALOG([self GOBJECT]))];
}

- (bool)getWrapLicense
{
	return gtk_about_dialog_get_wrap_license(GTK_ABOUT_DIALOG([self GOBJECT]));
}

- (void)setArtists:(const gchar**)artists
{
	gtk_about_dialog_set_artists(GTK_ABOUT_DIALOG([self GOBJECT]), artists);
}

- (void)setAuthors:(const gchar**)authors
{
	gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG([self GOBJECT]), authors);
}

- (void)setComments:(OFString*)comments
{
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG([self GOBJECT]), [comments UTF8String]);
}

- (void)setCopyright:(OFString*)copyright
{
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG([self GOBJECT]), [copyright UTF8String]);
}

- (void)setDocumenters:(const gchar**)documenters
{
	gtk_about_dialog_set_documenters(GTK_ABOUT_DIALOG([self GOBJECT]), documenters);
}

- (void)setLicense:(OFString*)license
{
	gtk_about_dialog_set_license(GTK_ABOUT_DIALOG([self GOBJECT]), [license UTF8String]);
}

- (void)setLicenseType:(GtkLicense)licenseType
{
	gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG([self GOBJECT]), licenseType);
}

- (void)setLogo:(GdkPixbuf*)logo
{
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG([self GOBJECT]), logo);
}

- (void)setLogoIconName:(OFString*)iconName
{
	gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG([self GOBJECT]), [iconName UTF8String]);
}

- (void)setProgramName:(OFString*)name
{
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG([self GOBJECT]), [name UTF8String]);
}

- (void)setTranslatorCredits:(OFString*)translatorCredits
{
	gtk_about_dialog_set_translator_credits(GTK_ABOUT_DIALOG([self GOBJECT]), [translatorCredits UTF8String]);
}

- (void)setVersion:(OFString*)version
{
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG([self GOBJECT]), [version UTF8String]);
}

- (void)setWebsite:(OFString*)website
{
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG([self GOBJECT]), [website UTF8String]);
}

- (void)setWebsiteLabel:(OFString*)websiteLabel
{
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG([self GOBJECT]), [websiteLabel UTF8String]);
}

- (void)setWrapLicense:(bool)wrapLicense
{
	gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG([self GOBJECT]), wrapLicense);
}


@end