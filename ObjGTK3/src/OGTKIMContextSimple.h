/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIMContext.h"

/**
 * GtkIMContextSimple is a simple input method context supporting table-based
 * input methods. It has a built-in table of compose sequences that is derived
 * from the X11 Compose files.
 * 
 * GtkIMContextSimple reads additional compose sequences from the first of the
 * following files that is found: ~/.config/gtk-3.0/Compose, ~/.XCompose,
 * /usr/share/X11/locale/$locale/Compose (for locales that have a nontrivial
 * Compose file). The syntax of these files is described in the Compose(5)
 * manual page.
 * 
 * ## Unicode characters
 * 
 * GtkIMContextSimple also supports numeric entry of Unicode characters
 * by typing Ctrl-Shift-u, followed by a hexadecimal Unicode codepoint.
 * For example, Ctrl-Shift-u 1 2 3 Enter yields U+0123 LATIN SMALL LETTER
 * G WITH CEDILLA, i.e. ģ.
 *
 */
@interface OGTKIMContextSimple : OGTKIMContext
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkIMContextSimple*)IMCONTEXTSIMPLE;

/**
 * Adds an additional table from the X11 compose file.
 *
 * @param composeFile The path of compose file
 */
- (void)addComposeFile:(OFString*)composeFile;

/**
 * Adds an additional table to search to the input context.
 * Each row of the table consists of @max_seq_len key symbols
 * followed by two #guint16 interpreted as the high and low
 * words of a #gunicode value. Tables are searched starting
 * from the last added.
 * 
 * The table must be sorted in dictionary order on the
 * numeric value of the key symbol fields. (Values beyond
 * the length of the sequence should be zero.)
 *
 * @param data the table
 * @param maxSeqLen Maximum length of a sequence in the table
 * @param nseqs number of sequences in the table
 */
- (void)addTableWithData:(guint16*)data maxSeqLen:(gint)maxSeqLen nseqs:(gint)nseqs;

@end