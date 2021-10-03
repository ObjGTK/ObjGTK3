/*
 * OGTKAboutDialog.h
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
#import "OGTKDialog.h"

@interface OGTKAboutDialog : OGTKDialog
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkAboutDialog*)ABOUTDIALOG;

/**
 * - (void*)addCreditSectionWithSectionName:(OFString*)sectionName andPeople:(const gchar**)people;
 *
 * @param sectionName
 * @param people
 */
- (void)addCreditSectionWithSectionName:(OFString*)sectionName andPeople:(const gchar**)people;

/**
 * - (const gchar* const**)getArtists;
 *
 * @returns const gchar* const*
 */
- (const gchar* const*)getArtists;

/**
 * - (const gchar* const**)getAuthors;
 *
 * @returns const gchar* const*
 */
- (const gchar* const*)getAuthors;

/**
 * - (OFString**)getComments;
 *
 * @returns OFString*
 */
- (OFString*)getComments;

/**
 * - (OFString**)getCopyright;
 *
 * @returns OFString*
 */
- (OFString*)getCopyright;

/**
 * - (const gchar* const**)getDocumenters;
 *
 * @returns const gchar* const*
 */
- (const gchar* const*)getDocumenters;

/**
 * - (OFString**)getLicense;
 *
 * @returns OFString*
 */
- (OFString*)getLicense;

/**
 * - (GtkLicense*)getLicenseType;
 *
 * @returns GtkLicense
 */
- (GtkLicense)getLicenseType;

/**
 * - (GdkPixbuf**)getLogo;
 *
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getLogo;

/**
 * - (OFString**)getLogoIconName;
 *
 * @returns OFString*
 */
- (OFString*)getLogoIconName;

/**
 * - (OFString**)getProgramName;
 *
 * @returns OFString*
 */
- (OFString*)getProgramName;

/**
 * - (OFString**)getTranslatorCredits;
 *
 * @returns OFString*
 */
- (OFString*)getTranslatorCredits;

/**
 * - (OFString**)getVersion;
 *
 * @returns OFString*
 */
- (OFString*)getVersion;

/**
 * - (OFString**)getWebsite;
 *
 * @returns OFString*
 */
- (OFString*)getWebsite;

/**
 * - (OFString**)getWebsiteLabel;
 *
 * @returns OFString*
 */
- (OFString*)getWebsiteLabel;

/**
 * - (bool*)getWrapLicense;
 *
 * @returns bool
 */
- (bool)getWrapLicense;

/**
 * - (void*)setArtists:(const gchar**)artists;
 *
 * @param artists
 */
- (void)setArtists:(const gchar**)artists;

/**
 * - (void*)setAuthors:(const gchar**)authors;
 *
 * @param authors
 */
- (void)setAuthors:(const gchar**)authors;

/**
 * - (void*)setComments:(OFString*)comments;
 *
 * @param comments
 */
- (void)setComments:(OFString*)comments;

/**
 * - (void*)setCopyright:(OFString*)copyright;
 *
 * @param copyright
 */
- (void)setCopyright:(OFString*)copyright;

/**
 * - (void*)setDocumenters:(const gchar**)documenters;
 *
 * @param documenters
 */
- (void)setDocumenters:(const gchar**)documenters;

/**
 * - (void*)setLicense:(OFString*)license;
 *
 * @param license
 */
- (void)setLicense:(OFString*)license;

/**
 * - (void*)setLicenseType:(GtkLicense)licenseType;
 *
 * @param licenseType
 */
- (void)setLicenseType:(GtkLicense)licenseType;

/**
 * - (void*)setLogo:(GdkPixbuf*)logo;
 *
 * @param logo
 */
- (void)setLogo:(GdkPixbuf*)logo;

/**
 * - (void*)setLogoIconName:(OFString*)iconName;
 *
 * @param iconName
 */
- (void)setLogoIconName:(OFString*)iconName;

/**
 * - (void*)setProgramName:(OFString*)name;
 *
 * @param name
 */
- (void)setProgramName:(OFString*)name;

/**
 * - (void*)setTranslatorCredits:(OFString*)translatorCredits;
 *
 * @param translatorCredits
 */
- (void)setTranslatorCredits:(OFString*)translatorCredits;

/**
 * - (void*)setVersion:(OFString*)version;
 *
 * @param version
 */
- (void)setVersion:(OFString*)version;

/**
 * - (void*)setWebsite:(OFString*)website;
 *
 * @param website
 */
- (void)setWebsite:(OFString*)website;

/**
 * - (void*)setWebsiteLabel:(OFString*)websiteLabel;
 *
 * @param websiteLabel
 */
- (void)setWebsiteLabel:(OFString*)websiteLabel;

/**
 * - (void*)setWrapLicense:(bool)wrapLicense;
 *
 * @param wrapLicense
 */
- (void)setWrapLicense:(bool)wrapLicense;

@end