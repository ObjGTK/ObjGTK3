/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

@class OGTKWidget;
@class OGGdkPixbuf;

/**
 * The GtkAboutDialog offers a simple way to display information about
 * a program like its logo, name, copyright, website and license. It is
 * also possible to give credits to the authors, documenters, translators
 * and artists who have worked on the program. An about dialog is typically
 * opened when the user selects the `About` option from the `Help` menu.
 * All parts of the dialog are optional.
 * 
 * About dialogs often contain links and email addresses. GtkAboutDialog
 * displays these as clickable links. By default, it calls gtk_show_uri_on_window()
 * when a user clicks one. The behaviour can be overridden with the
 * #GtkAboutDialog::activate-link signal.
 * 
 * To specify a person with an email address, use a string like
 * "Edgar Allan Poe <edgar\@poe.com>". To specify a website with a title,
 * use a string like "GTK+ team http://www.gtk.org".
 * 
 * To make constructing a GtkAboutDialog as convenient as possible, you can
 * use the function gtk_show_about_dialog() which constructs and shows a dialog
 * and keeps it around so that it can be shown again.
 * 
 * Note that GTK+ sets a default title of `_("About %s")` on the dialog
 * window (where \%s is replaced by the name of the application, but in
 * order to ensure proper translation of the title, applications should
 * set the title property explicitly when constructing a GtkAboutDialog,
 * as shown in the following example:
 * |[<!-- language="C" -->
 * GdkPixbuf *example_logo = gdk_pixbuf_new_from_file ("./logo.png", NULL);
 * gtk_show_about_dialog (NULL,
 *                        "program-name", "ExampleCode",
 *                        "logo", example_logo,
 *                        "title", _("About ExampleCode"),
 *                        NULL);
 * ]|
 * 
 * It is also possible to show a #GtkAboutDialog like any other #GtkDialog,
 * e.g. using gtk_dialog_run(). In this case, you might need to know that
 * the “Close” button returns the #GTK_RESPONSE_CANCEL response id.
 *
 */
@interface OGTKAboutDialog : OGTKDialog
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkAboutDialog*)ABOUTDIALOG;

/**
 * Creates a new section in the Credits page.
 *
 * @param sectionName The name of the section
 * @param people The people who belong to that section
 */
- (void)addCreditSectionWithSectionName:(OFString*)sectionName people:(const gchar**)people;

/**
 * Returns the string which are displayed in the artists tab
 * of the secondary credits dialog.
 *
 * @return A
 *  %NULL-terminated string array containing the artists. The array is
 *  owned by the about dialog and must not be modified.
 */
- (const gchar* const*)artists;

/**
 * Returns the string which are displayed in the authors tab
 * of the secondary credits dialog.
 *
 * @return A
 *  %NULL-terminated string array containing the authors. The array is
 *  owned by the about dialog and must not be modified.
 */
- (const gchar* const*)authors;

/**
 * Returns the comments string.
 *
 * @return The comments. The string is owned by the about
 *  dialog and must not be modified.
 */
- (OFString*)comments;

/**
 * Returns the copyright string.
 *
 * @return The copyright string. The string is owned by the about
 *  dialog and must not be modified.
 */
- (OFString*)copyright;

/**
 * Returns the string which are displayed in the documenters
 * tab of the secondary credits dialog.
 *
 * @return A
 *  %NULL-terminated string array containing the documenters. The
 *  array is owned by the about dialog and must not be modified.
 */
- (const gchar* const*)documenters;

/**
 * Returns the license information.
 *
 * @return The license information. The string is owned by the about
 *  dialog and must not be modified.
 */
- (OFString*)license;

/**
 * Retrieves the license set using gtk_about_dialog_set_license_type()
 *
 * @return a #GtkLicense value
 */
- (GtkLicense)licenseType;

/**
 * Returns the pixbuf displayed as logo in the about dialog.
 *
 * @return the pixbuf displayed as logo. The
 *   pixbuf is owned by the about dialog. If you want to keep a
 *   reference to it, you have to call g_object_ref() on it.
 */
- (OGGdkPixbuf*)logo;

/**
 * Returns the icon name displayed as logo in the about dialog.
 *
 * @return the icon name displayed as logo. The string is
 *   owned by the dialog. If you want to keep a reference
 *   to it, you have to call g_strdup() on it.
 */
- (OFString*)logoIconName;

/**
 * Returns the program name displayed in the about dialog.
 *
 * @return The program name. The string is owned by the about
 *  dialog and must not be modified.
 */
- (OFString*)programName;

/**
 * Returns the translator credits string which is displayed
 * in the translators tab of the secondary credits dialog.
 *
 * @return The translator credits string. The string is
 *   owned by the about dialog and must not be modified.
 */
- (OFString*)translatorCredits;

/**
 * Returns the version string.
 *
 * @return The version string. The string is owned by the about
 *  dialog and must not be modified.
 */
- (OFString*)version;

/**
 * Returns the website URL.
 *
 * @return The website URL. The string is owned by the about
 *  dialog and must not be modified.
 */
- (OFString*)website;

/**
 * Returns the label used for the website link.
 *
 * @return The label used for the website link. The string is
 *     owned by the about dialog and must not be modified.
 */
- (OFString*)websiteLabel;

/**
 * Returns whether the license text in @about is
 * automatically wrapped.
 *
 * @return %TRUE if the license text is wrapped
 */
- (bool)wrapLicense;

/**
 * Sets the strings which are displayed in the artists tab
 * of the secondary credits dialog.
 *
 * @param artists a %NULL-terminated array of strings
 */
- (void)setArtists:(const gchar**)artists;

/**
 * Sets the strings which are displayed in the authors tab
 * of the secondary credits dialog.
 *
 * @param authors a %NULL-terminated array of strings
 */
- (void)setAuthors:(const gchar**)authors;

/**
 * Sets the comments string to display in the about dialog.
 * This should be a short string of one or two lines.
 *
 * @param comments a comments string
 */
- (void)setComments:(OFString*)comments;

/**
 * Sets the copyright string to display in the about dialog.
 * This should be a short string of one or two lines.
 *
 * @param copyright the copyright string
 */
- (void)setCopyright:(OFString*)copyright;

/**
 * Sets the strings which are displayed in the documenters tab
 * of the secondary credits dialog.
 *
 * @param documenters a %NULL-terminated array of strings
 */
- (void)setDocumenters:(const gchar**)documenters;

/**
 * Sets the license information to be displayed in the secondary
 * license dialog. If @license is %NULL, the license button is
 * hidden.
 *
 * @param license the license information or %NULL
 */
- (void)setLicense:(OFString*)license;

/**
 * Sets the license of the application showing the @about dialog from a
 * list of known licenses.
 * 
 * This function overrides the license set using
 * gtk_about_dialog_set_license().
 *
 * @param licenseType the type of license
 */
- (void)setLicenseType:(GtkLicense)licenseType;

/**
 * Sets the pixbuf to be displayed as logo in the about dialog.
 * If it is %NULL, the default window icon set with
 * gtk_window_set_default_icon() will be used.
 *
 * @param logo a #GdkPixbuf, or %NULL
 */
- (void)setLogo:(OGGdkPixbuf*)logo;

/**
 * Sets the pixbuf to be displayed as logo in the about dialog.
 * If it is %NULL, the default window icon set with
 * gtk_window_set_default_icon() will be used.
 *
 * @param iconName an icon name, or %NULL
 */
- (void)setLogoIconName:(OFString*)iconName;

/**
 * Sets the name to display in the about dialog.
 * If this is not set, it defaults to g_get_application_name().
 *
 * @param name the program name
 */
- (void)setProgramName:(OFString*)name;

/**
 * Sets the translator credits string which is displayed in
 * the translators tab of the secondary credits dialog.
 * 
 * The intended use for this string is to display the translator
 * of the language which is currently used in the user interface.
 * Using gettext(), a simple way to achieve that is to mark the
 * string for translation:
 * |[<!-- language="C" -->
 * GtkWidget *about = gtk_about_dialog_new ();
 * gtk_about_dialog_set_translator_credits (GTK_ABOUT_DIALOG (about),
 *                                          _("translator-credits"));
 * ]|
 * It is a good idea to use the customary msgid “translator-credits” for this
 * purpose, since translators will already know the purpose of that msgid, and
 * since #GtkAboutDialog will detect if “translator-credits” is untranslated
 * and hide the tab.
 *
 * @param translatorCredits the translator credits
 */
- (void)setTranslatorCredits:(OFString*)translatorCredits;

/**
 * Sets the version string to display in the about dialog.
 *
 * @param version the version string
 */
- (void)setVersion:(OFString*)version;

/**
 * Sets the URL to use for the website link.
 *
 * @param website a URL string starting with "http://"
 */
- (void)setWebsite:(OFString*)website;

/**
 * Sets the label to be used for the website link.
 *
 * @param websiteLabel the label used for the website link
 */
- (void)setWebsiteLabel:(OFString*)websiteLabel;

/**
 * Sets whether the license text in @about is
 * automatically wrapped.
 *
 * @param wrapLicense whether to wrap the license
 */
- (void)setWrapLicense:(bool)wrapLicense;

@end