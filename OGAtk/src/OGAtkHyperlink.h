/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

@class OGAtkObject;

/**
 * An ATK object which encapsulates a link or set of links (for
 * instance in the case of client-side image maps) in a hypertext
 * document.  It may implement the AtkAction interface.  AtkHyperlink
 * may also be used to refer to inline embedded content, since it
 * allows specification of a start and end offset within the host
 * AtkHypertext object.
 *
 */
@interface OGAtkHyperlink : OGObject
{

}


/**
 * Methods
 */

- (AtkHyperlink*)HYPERLINK;

/**
 * Gets the index with the hypertext document at which this link ends.
 *
 * @return the index with the hypertext document at which this link ends
 */
- (gint)endIndex;

/**
 * Gets the number of anchors associated with this hyperlink.
 *
 * @return the number of anchors associated with this hyperlink
 */
- (gint)nanchors;

/**
 * Returns the item associated with this hyperlinks nth anchor.
 * For instance, the returned #AtkObject will implement #AtkText
 * if @link_ is a text hyperlink, #AtkImage if @link_ is an image
 * hyperlink etc.
 * 
 * Multiple anchors are primarily used by client-side image maps.
 *
 * @param i a (zero-index) integer specifying the desired anchor
 * @return an #AtkObject associated with this hyperlinks
 * i-th anchor
 */
- (OGAtkObject*)object:(gint)i;

/**
 * Gets the index with the hypertext document at which this link begins.
 *
 * @return the index with the hypertext document at which this link begins
 */
- (gint)startIndex;

/**
 * Get a the URI associated with the anchor specified
 * by @i of @link_.
 * 
 * Multiple anchors are primarily used by client-side image maps.
 *
 * @param i a (zero-index) integer specifying the desired anchor
 * @return a string specifying the URI
 */
- (OFString*)uri:(gint)i;

/**
 * Indicates whether the link currently displays some or all of its
 *           content inline.  Ordinary HTML links will usually return
 *           %FALSE, but an inline &lt;src&gt; HTML element will return
 *           %TRUE.
 *
 * @return whether or not this link displays its content inline.
 */
- (bool)isInline;

/**
 * Determines whether this AtkHyperlink is selected
 *
 * @return True if the AtkHyperlink is selected, False otherwise
 */
- (bool)isSelectedLink;

/**
 * Since the document that a link is associated with may have changed
 * this method returns %TRUE if the link is still valid (with
 * respect to the document it references) and %FALSE otherwise.
 *
 * @return whether or not this link is still valid
 */
- (bool)isValid;

@end