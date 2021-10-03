/*
 * OGTKTextView.h
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
#import "OGTKContainer.h"

@interface OGTKTextView : OGTKContainer
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithBuffer:(GtkTextBuffer*)buffer;

/**
 * Methods
 */

- (GtkTextView*)TEXTVIEW;

/**
 * - (void*)addChildAtAnchorWithChild:(OGTKWidget*)child andAnchor:(GtkTextChildAnchor*)anchor;
 *
 * @param child
 * @param anchor
 */
- (void)addChildAtAnchorWithChild:(OGTKWidget*)child andAnchor:(GtkTextChildAnchor*)anchor;

/**
 * - (void*)addChildInWindowWithChild:(OGTKWidget*)child andWhichWindow:(GtkTextWindowType)whichWindow andXpos:(gint)xpos andYpos:(gint)ypos;
 *
 * @param child
 * @param whichWindow
 * @param xpos
 * @param ypos
 */
- (void)addChildInWindowWithChild:(OGTKWidget*)child andWhichWindow:(GtkTextWindowType)whichWindow andXpos:(gint)xpos andYpos:(gint)ypos;

/**
 * - (bool*)backwardDisplayLine:(GtkTextIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)backwardDisplayLine:(GtkTextIter*)iter;

/**
 * - (bool*)backwardDisplayLineStart:(GtkTextIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)backwardDisplayLineStart:(GtkTextIter*)iter;

/**
 * - (void*)bufferToWindowCoordsWithWin:(GtkTextWindowType)win andBufferX:(gint)bufferX andBufferY:(gint)bufferY andWindowX:(gint*)windowX andWindowY:(gint*)windowY;
 *
 * @param win
 * @param bufferX
 * @param bufferY
 * @param windowX
 * @param windowY
 */
- (void)bufferToWindowCoordsWithWin:(GtkTextWindowType)win andBufferX:(gint)bufferX andBufferY:(gint)bufferY andWindowX:(gint*)windowX andWindowY:(gint*)windowY;

/**
 * - (bool*)forwardDisplayLine:(GtkTextIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)forwardDisplayLine:(GtkTextIter*)iter;

/**
 * - (bool*)forwardDisplayLineEnd:(GtkTextIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)forwardDisplayLineEnd:(GtkTextIter*)iter;

/**
 * - (bool*)getAcceptsTab;
 *
 * @returns bool
 */
- (bool)getAcceptsTab;

/**
 * - (gint*)getBorderWindowSize:(GtkTextWindowType)type;
 *
 * @param type
 * @returns gint
 */
- (gint)getBorderWindowSize:(GtkTextWindowType)type;

/**
 * - (gint*)getBottomMargin;
 *
 * @returns gint
 */
- (gint)getBottomMargin;

/**
 * - (GtkTextBuffer**)getBuffer;
 *
 * @returns GtkTextBuffer*
 */
- (GtkTextBuffer*)getBuffer;

/**
 * - (void*)getCursorLocationsWithIter:(const GtkTextIter*)iter andStrong:(GdkRectangle*)strong andWeak:(GdkRectangle*)weak;
 *
 * @param iter
 * @param strong
 * @param weak
 */
- (void)getCursorLocationsWithIter:(const GtkTextIter*)iter andStrong:(GdkRectangle*)strong andWeak:(GdkRectangle*)weak;

/**
 * - (bool*)getCursorVisible;
 *
 * @returns bool
 */
- (bool)getCursorVisible;

/**
 * - (GtkTextAttributes**)getDefaultAttributes;
 *
 * @returns GtkTextAttributes*
 */
- (GtkTextAttributes*)getDefaultAttributes;

/**
 * - (bool*)getEditable;
 *
 * @returns bool
 */
- (bool)getEditable;

/**
 * - (GtkAdjustment**)getHadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getHadjustment;

/**
 * - (gint*)getIndent;
 *
 * @returns gint
 */
- (gint)getIndent;

/**
 * - (GtkInputHints*)getInputHints;
 *
 * @returns GtkInputHints
 */
- (GtkInputHints)getInputHints;

/**
 * - (GtkInputPurpose*)getInputPurpose;
 *
 * @returns GtkInputPurpose
 */
- (GtkInputPurpose)getInputPurpose;

/**
 * - (bool*)getIterAtLocationWithIter:(GtkTextIter*)iter andX:(gint)x andY:(gint)y;
 *
 * @param iter
 * @param x
 * @param y
 * @returns bool
 */
- (bool)getIterAtLocationWithIter:(GtkTextIter*)iter andX:(gint)x andY:(gint)y;

/**
 * - (bool*)getIterAtPositionWithIter:(GtkTextIter*)iter andTrailing:(gint*)trailing andX:(gint)x andY:(gint)y;
 *
 * @param iter
 * @param trailing
 * @param x
 * @param y
 * @returns bool
 */
- (bool)getIterAtPositionWithIter:(GtkTextIter*)iter andTrailing:(gint*)trailing andX:(gint)x andY:(gint)y;

/**
 * - (void*)getIterLocationWithIter:(const GtkTextIter*)iter andLocation:(GdkRectangle*)location;
 *
 * @param iter
 * @param location
 */
- (void)getIterLocationWithIter:(const GtkTextIter*)iter andLocation:(GdkRectangle*)location;

/**
 * - (GtkJustification*)getJustification;
 *
 * @returns GtkJustification
 */
- (GtkJustification)getJustification;

/**
 * - (gint*)getLeftMargin;
 *
 * @returns gint
 */
- (gint)getLeftMargin;

/**
 * - (void*)getLineAtYWithTargetIter:(GtkTextIter*)targetIter andY:(gint)y andLineTop:(gint*)lineTop;
 *
 * @param targetIter
 * @param y
 * @param lineTop
 */
- (void)getLineAtYWithTargetIter:(GtkTextIter*)targetIter andY:(gint)y andLineTop:(gint*)lineTop;

/**
 * - (void*)getLineYrangeWithIter:(const GtkTextIter*)iter andY:(gint*)y andHeight:(gint*)height;
 *
 * @param iter
 * @param y
 * @param height
 */
- (void)getLineYrangeWithIter:(const GtkTextIter*)iter andY:(gint*)y andHeight:(gint*)height;

/**
 * - (bool*)getMonospace;
 *
 * @returns bool
 */
- (bool)getMonospace;

/**
 * - (bool*)getOverwrite;
 *
 * @returns bool
 */
- (bool)getOverwrite;

/**
 * - (gint*)getPixelsAboveLines;
 *
 * @returns gint
 */
- (gint)getPixelsAboveLines;

/**
 * - (gint*)getPixelsBelowLines;
 *
 * @returns gint
 */
- (gint)getPixelsBelowLines;

/**
 * - (gint*)getPixelsInsideWrap;
 *
 * @returns gint
 */
- (gint)getPixelsInsideWrap;

/**
 * - (gint*)getRightMargin;
 *
 * @returns gint
 */
- (gint)getRightMargin;

/**
 * - (PangoTabArray**)getTabs;
 *
 * @returns PangoTabArray*
 */
- (PangoTabArray*)getTabs;

/**
 * - (gint*)getTopMargin;
 *
 * @returns gint
 */
- (gint)getTopMargin;

/**
 * - (GtkAdjustment**)getVadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getVadjustment;

/**
 * - (void*)getVisibleRect:(GdkRectangle*)visibleRect;
 *
 * @param visibleRect
 */
- (void)getVisibleRect:(GdkRectangle*)visibleRect;

/**
 * - (GdkWindow**)getWindow:(GtkTextWindowType)win;
 *
 * @param win
 * @returns GdkWindow*
 */
- (GdkWindow*)getWindow:(GtkTextWindowType)win;

/**
 * - (GtkTextWindowType*)getWindowType:(GdkWindow*)window;
 *
 * @param window
 * @returns GtkTextWindowType
 */
- (GtkTextWindowType)getWindowType:(GdkWindow*)window;

/**
 * - (GtkWrapMode*)getWrapMode;
 *
 * @returns GtkWrapMode
 */
- (GtkWrapMode)getWrapMode;

/**
 * - (bool*)imContextFilterKeypress:(GdkEventKey*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)imContextFilterKeypress:(GdkEventKey*)event;

/**
 * - (void*)moveChildWithChild:(OGTKWidget*)child andXpos:(gint)xpos andYpos:(gint)ypos;
 *
 * @param child
 * @param xpos
 * @param ypos
 */
- (void)moveChildWithChild:(OGTKWidget*)child andXpos:(gint)xpos andYpos:(gint)ypos;

/**
 * - (bool*)moveMarkOnscreen:(GtkTextMark*)mark;
 *
 * @param mark
 * @returns bool
 */
- (bool)moveMarkOnscreen:(GtkTextMark*)mark;

/**
 * - (bool*)moveVisuallyWithIter:(GtkTextIter*)iter andCount:(gint)count;
 *
 * @param iter
 * @param count
 * @returns bool
 */
- (bool)moveVisuallyWithIter:(GtkTextIter*)iter andCount:(gint)count;

/**
 * - (bool*)placeCursorOnscreen;
 *
 * @returns bool
 */
- (bool)placeCursorOnscreen;

/**
 * - (void*)resetCursorBlink;
 *
 */
- (void)resetCursorBlink;

/**
 * - (void*)resetImContext;
 *
 */
- (void)resetImContext;

/**
 * - (void*)scrollMarkOnscreen:(GtkTextMark*)mark;
 *
 * @param mark
 */
- (void)scrollMarkOnscreen:(GtkTextMark*)mark;

/**
 * - (bool*)scrollToIterWithIter:(GtkTextIter*)iter andWithinMargin:(gdouble)withinMargin andUseAlign:(bool)useAlign andXalign:(gdouble)xalign andYalign:(gdouble)yalign;
 *
 * @param iter
 * @param withinMargin
 * @param useAlign
 * @param xalign
 * @param yalign
 * @returns bool
 */
- (bool)scrollToIterWithIter:(GtkTextIter*)iter andWithinMargin:(gdouble)withinMargin andUseAlign:(bool)useAlign andXalign:(gdouble)xalign andYalign:(gdouble)yalign;

/**
 * - (void*)scrollToMarkWithMark:(GtkTextMark*)mark andWithinMargin:(gdouble)withinMargin andUseAlign:(bool)useAlign andXalign:(gdouble)xalign andYalign:(gdouble)yalign;
 *
 * @param mark
 * @param withinMargin
 * @param useAlign
 * @param xalign
 * @param yalign
 */
- (void)scrollToMarkWithMark:(GtkTextMark*)mark andWithinMargin:(gdouble)withinMargin andUseAlign:(bool)useAlign andXalign:(gdouble)xalign andYalign:(gdouble)yalign;

/**
 * - (void*)setAcceptsTab:(bool)acceptsTab;
 *
 * @param acceptsTab
 */
- (void)setAcceptsTab:(bool)acceptsTab;

/**
 * - (void*)setBorderWindowSizeWithType:(GtkTextWindowType)type andSize:(gint)size;
 *
 * @param type
 * @param size
 */
- (void)setBorderWindowSizeWithType:(GtkTextWindowType)type andSize:(gint)size;

/**
 * - (void*)setBottomMargin:(gint)bottomMargin;
 *
 * @param bottomMargin
 */
- (void)setBottomMargin:(gint)bottomMargin;

/**
 * - (void*)setBuffer:(GtkTextBuffer*)buffer;
 *
 * @param buffer
 */
- (void)setBuffer:(GtkTextBuffer*)buffer;

/**
 * - (void*)setCursorVisible:(bool)setting;
 *
 * @param setting
 */
- (void)setCursorVisible:(bool)setting;

/**
 * - (void*)setEditable:(bool)setting;
 *
 * @param setting
 */
- (void)setEditable:(bool)setting;

/**
 * - (void*)setIndent:(gint)indent;
 *
 * @param indent
 */
- (void)setIndent:(gint)indent;

/**
 * - (void*)setInputHints:(GtkInputHints)hints;
 *
 * @param hints
 */
- (void)setInputHints:(GtkInputHints)hints;

/**
 * - (void*)setInputPurpose:(GtkInputPurpose)purpose;
 *
 * @param purpose
 */
- (void)setInputPurpose:(GtkInputPurpose)purpose;

/**
 * - (void*)setJustification:(GtkJustification)justification;
 *
 * @param justification
 */
- (void)setJustification:(GtkJustification)justification;

/**
 * - (void*)setLeftMargin:(gint)leftMargin;
 *
 * @param leftMargin
 */
- (void)setLeftMargin:(gint)leftMargin;

/**
 * - (void*)setMonospace:(bool)monospace;
 *
 * @param monospace
 */
- (void)setMonospace:(bool)monospace;

/**
 * - (void*)setOverwrite:(bool)overwrite;
 *
 * @param overwrite
 */
- (void)setOverwrite:(bool)overwrite;

/**
 * - (void*)setPixelsAboveLines:(gint)pixelsAboveLines;
 *
 * @param pixelsAboveLines
 */
- (void)setPixelsAboveLines:(gint)pixelsAboveLines;

/**
 * - (void*)setPixelsBelowLines:(gint)pixelsBelowLines;
 *
 * @param pixelsBelowLines
 */
- (void)setPixelsBelowLines:(gint)pixelsBelowLines;

/**
 * - (void*)setPixelsInsideWrap:(gint)pixelsInsideWrap;
 *
 * @param pixelsInsideWrap
 */
- (void)setPixelsInsideWrap:(gint)pixelsInsideWrap;

/**
 * - (void*)setRightMargin:(gint)rightMargin;
 *
 * @param rightMargin
 */
- (void)setRightMargin:(gint)rightMargin;

/**
 * - (void*)setTabs:(PangoTabArray*)tabs;
 *
 * @param tabs
 */
- (void)setTabs:(PangoTabArray*)tabs;

/**
 * - (void*)setTopMargin:(gint)topMargin;
 *
 * @param topMargin
 */
- (void)setTopMargin:(gint)topMargin;

/**
 * - (void*)setWrapMode:(GtkWrapMode)wrapMode;
 *
 * @param wrapMode
 */
- (void)setWrapMode:(GtkWrapMode)wrapMode;

/**
 * - (bool*)startsDisplayLine:(const GtkTextIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)startsDisplayLine:(const GtkTextIter*)iter;

/**
 * - (void*)windowToBufferCoordsWithWin:(GtkTextWindowType)win andWindowX:(gint)windowX andWindowY:(gint)windowY andBufferX:(gint*)bufferX andBufferY:(gint*)bufferY;
 *
 * @param win
 * @param windowX
 * @param windowY
 * @param bufferX
 * @param bufferY
 */
- (void)windowToBufferCoordsWithWin:(GtkTextWindowType)win andWindowX:(gint)windowX andWindowY:(gint)windowY andBufferX:(gint*)bufferX andBufferY:(gint*)bufferY;

@end