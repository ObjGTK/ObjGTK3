/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAboutDialog.h"

#import "OGTKWidget.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>

@implementation OGTKAboutDialog

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_about_dialog_new()];

	return self;
}

- (GtkAboutDialog*)ABOUTDIALOG
{
	return GTK_ABOUT_DIALOG([self GOBJECT]);
}

- (void)addCreditSectionWithSectionName:(OFString*)sectionName people:(const gchar**)people
{
	gtk_about_dialog_add_credit_section([self ABOUTDIALOG], [sectionName UTF8String], people);
}

- (const gchar* const*)artists
{
	return gtk_about_dialog_get_artists([self ABOUTDIALOG]);
}

- (const gchar* const*)authors
{
	return gtk_about_dialog_get_authors([self ABOUTDIALOG]);
}

- (OFString*)comments
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_comments([self ABOUTDIALOG])];
}

- (OFString*)copyright
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_copyright([self ABOUTDIALOG])];
}

- (const gchar* const*)documenters
{
	return gtk_about_dialog_get_documenters([self ABOUTDIALOG]);
}

- (OFString*)license
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_license([self ABOUTDIALOG])];
}

- (GtkLicense)licenseType
{
	return gtk_about_dialog_get_license_type([self ABOUTDIALOG]);
}

- (OGGdkPixbuf*)logo
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_about_dialog_get_logo([self ABOUTDIALOG])] autorelease];
}

- (OFString*)logoIconName
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_logo_icon_name([self ABOUTDIALOG])];
}

- (OFString*)programName
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_program_name([self ABOUTDIALOG])];
}

- (OFString*)translatorCredits
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_translator_credits([self ABOUTDIALOG])];
}

- (OFString*)version
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_version([self ABOUTDIALOG])];
}

- (OFString*)website
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_website([self ABOUTDIALOG])];
}

- (OFString*)websiteLabel
{
	return [OFString stringWithUTF8String:gtk_about_dialog_get_website_label([self ABOUTDIALOG])];
}

- (bool)wrapLicense
{
	return gtk_about_dialog_get_wrap_license([self ABOUTDIALOG]);
}

- (void)setArtists:(const gchar**)artists
{
	gtk_about_dialog_set_artists([self ABOUTDIALOG], artists);
}

- (void)setAuthors:(const gchar**)authors
{
	gtk_about_dialog_set_authors([self ABOUTDIALOG], authors);
}

- (void)setComments:(OFString*)comments
{
	gtk_about_dialog_set_comments([self ABOUTDIALOG], [comments UTF8String]);
}

- (void)setCopyright:(OFString*)copyright
{
	gtk_about_dialog_set_copyright([self ABOUTDIALOG], [copyright UTF8String]);
}

- (void)setDocumenters:(const gchar**)documenters
{
	gtk_about_dialog_set_documenters([self ABOUTDIALOG], documenters);
}

- (void)setLicense:(OFString*)license
{
	gtk_about_dialog_set_license([self ABOUTDIALOG], [license UTF8String]);
}

- (void)setLicenseType:(GtkLicense)licenseType
{
	gtk_about_dialog_set_license_type([self ABOUTDIALOG], licenseType);
}

- (void)setLogo:(OGGdkPixbuf*)logo
{
	gtk_about_dialog_set_logo([self ABOUTDIALOG], [logo PIXBUF]);
}

- (void)setLogoIconName:(OFString*)iconName
{
	gtk_about_dialog_set_logo_icon_name([self ABOUTDIALOG], [iconName UTF8String]);
}

- (void)setProgramName:(OFString*)name
{
	gtk_about_dialog_set_program_name([self ABOUTDIALOG], [name UTF8String]);
}

- (void)setTranslatorCredits:(OFString*)translatorCredits
{
	gtk_about_dialog_set_translator_credits([self ABOUTDIALOG], [translatorCredits UTF8String]);
}

- (void)setVersion:(OFString*)version
{
	gtk_about_dialog_set_version([self ABOUTDIALOG], [version UTF8String]);
}

- (void)setWebsite:(OFString*)website
{
	gtk_about_dialog_set_website([self ABOUTDIALOG], [website UTF8String]);
}

- (void)setWebsiteLabel:(OFString*)websiteLabel
{
	gtk_about_dialog_set_website_label([self ABOUTDIALOG], [websiteLabel UTF8String]);
}

- (void)setWrapLicense:(bool)wrapLicense
{
	gtk_about_dialog_set_wrap_license([self ABOUTDIALOG], wrapLicense);
}


@end