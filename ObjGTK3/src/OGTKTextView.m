/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTextView.h"

#import "OGTKTextChildAnchor.h"
#import <OGdk3/OGGdkWindow.h>
#import "OGTKAdjustment.h"
#import "OGTKTextBuffer.h"
#import "OGTKWidget.h"
#import "OGTKTextMark.h"

@implementation OGTKTextView

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_text_view_new()];

	return self;
}

- (instancetype)initWithBuffer:(OGTKTextBuffer*)buffer
{
	self = [super initWithGObject:(GObject*)gtk_text_view_new_with_buffer([buffer TEXTBUFFER])];

	return self;
}

- (GtkTextView*)TEXTVIEW
{
	return GTK_TEXT_VIEW([self GOBJECT]);
}

- (void)addChildAtAnchorWithChild:(OGTKWidget*)child anchor:(OGTKTextChildAnchor*)anchor
{
	gtk_text_view_add_child_at_anchor([self TEXTVIEW], [child WIDGET], [anchor TEXTCHILDANCHOR]);
}

- (void)addChildInWindowWithChild:(OGTKWidget*)child whichWindow:(GtkTextWindowType)whichWindow xpos:(gint)xpos ypos:(gint)ypos
{
	gtk_text_view_add_child_in_window([self TEXTVIEW], [child WIDGET], whichWindow, xpos, ypos);
}

- (bool)backwardDisplayLine:(GtkTextIter*)iter
{
	return gtk_text_view_backward_display_line([self TEXTVIEW], iter);
}

- (bool)backwardDisplayLineStart:(GtkTextIter*)iter
{
	return gtk_text_view_backward_display_line_start([self TEXTVIEW], iter);
}

- (void)bufferToWindowCoordsWithWin:(GtkTextWindowType)win bufferX:(gint)bufferX bufferY:(gint)bufferY windowX:(gint*)windowX windowY:(gint*)windowY
{
	gtk_text_view_buffer_to_window_coords([self TEXTVIEW], win, bufferX, bufferY, windowX, windowY);
}

- (bool)forwardDisplayLine:(GtkTextIter*)iter
{
	return gtk_text_view_forward_display_line([self TEXTVIEW], iter);
}

- (bool)forwardDisplayLineEnd:(GtkTextIter*)iter
{
	return gtk_text_view_forward_display_line_end([self TEXTVIEW], iter);
}

- (bool)acceptsTab
{
	return gtk_text_view_get_accepts_tab([self TEXTVIEW]);
}

- (gint)borderWindowSize:(GtkTextWindowType)type
{
	return gtk_text_view_get_border_window_size([self TEXTVIEW], type);
}

- (gint)bottomMargin
{
	return gtk_text_view_get_bottom_margin([self TEXTVIEW]);
}

- (OGTKTextBuffer*)buffer
{
	return [[[OGTKTextBuffer alloc] initWithGObject:(GObject*)gtk_text_view_get_buffer([self TEXTVIEW])] autorelease];
}

- (void)cursorLocationsWithIter:(const GtkTextIter*)iter strong:(GdkRectangle*)strong weak:(GdkRectangle*)weak
{
	gtk_text_view_get_cursor_locations([self TEXTVIEW], iter, strong, weak);
}

- (bool)cursorVisible
{
	return gtk_text_view_get_cursor_visible([self TEXTVIEW]);
}

- (GtkTextAttributes*)defaultAttributes
{
	return gtk_text_view_get_default_attributes([self TEXTVIEW]);
}

- (bool)editable
{
	return gtk_text_view_get_editable([self TEXTVIEW]);
}

- (OGTKAdjustment*)hadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_text_view_get_hadjustment([self TEXTVIEW])] autorelease];
}

- (gint)indent
{
	return gtk_text_view_get_indent([self TEXTVIEW]);
}

- (GtkInputHints)inputHints
{
	return gtk_text_view_get_input_hints([self TEXTVIEW]);
}

- (GtkInputPurpose)inputPurpose
{
	return gtk_text_view_get_input_purpose([self TEXTVIEW]);
}

- (bool)iterAtLocationWithIter:(GtkTextIter*)iter x:(gint)x y:(gint)y
{
	return gtk_text_view_get_iter_at_location([self TEXTVIEW], iter, x, y);
}

- (bool)iterAtPositionWithIter:(GtkTextIter*)iter trailing:(gint*)trailing x:(gint)x y:(gint)y
{
	return gtk_text_view_get_iter_at_position([self TEXTVIEW], iter, trailing, x, y);
}

- (void)iterLocationWithIter:(const GtkTextIter*)iter location:(GdkRectangle*)location
{
	gtk_text_view_get_iter_location([self TEXTVIEW], iter, location);
}

- (GtkJustification)justification
{
	return gtk_text_view_get_justification([self TEXTVIEW]);
}

- (gint)leftMargin
{
	return gtk_text_view_get_left_margin([self TEXTVIEW]);
}

- (void)lineAtYWithTargetIter:(GtkTextIter*)targetIter y:(gint)y lineTop:(gint*)lineTop
{
	gtk_text_view_get_line_at_y([self TEXTVIEW], targetIter, y, lineTop);
}

- (void)lineYrangeWithIter:(const GtkTextIter*)iter y:(gint*)y height:(gint*)height
{
	gtk_text_view_get_line_yrange([self TEXTVIEW], iter, y, height);
}

- (bool)monospace
{
	return gtk_text_view_get_monospace([self TEXTVIEW]);
}

- (bool)overwrite
{
	return gtk_text_view_get_overwrite([self TEXTVIEW]);
}

- (gint)pixelsAboveLines
{
	return gtk_text_view_get_pixels_above_lines([self TEXTVIEW]);
}

- (gint)pixelsBelowLines
{
	return gtk_text_view_get_pixels_below_lines([self TEXTVIEW]);
}

- (gint)pixelsInsideWrap
{
	return gtk_text_view_get_pixels_inside_wrap([self TEXTVIEW]);
}

- (gint)rightMargin
{
	return gtk_text_view_get_right_margin([self TEXTVIEW]);
}

- (PangoTabArray*)tabs
{
	return gtk_text_view_get_tabs([self TEXTVIEW]);
}

- (gint)topMargin
{
	return gtk_text_view_get_top_margin([self TEXTVIEW]);
}

- (OGTKAdjustment*)vadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_text_view_get_vadjustment([self TEXTVIEW])] autorelease];
}

- (void)visibleRect:(GdkRectangle*)visibleRect
{
	gtk_text_view_get_visible_rect([self TEXTVIEW], visibleRect);
}

- (OGGdkWindow*)window:(GtkTextWindowType)win
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_text_view_get_window([self TEXTVIEW], win)] autorelease];
}

- (GtkTextWindowType)windowType:(OGGdkWindow*)window
{
	return gtk_text_view_get_window_type([self TEXTVIEW], [window WINDOW]);
}

- (GtkWrapMode)wrapMode
{
	return gtk_text_view_get_wrap_mode([self TEXTVIEW]);
}

- (bool)imContextFilterKeypress:(GdkEventKey*)event
{
	return gtk_text_view_im_context_filter_keypress([self TEXTVIEW], event);
}

- (void)moveChildWithChild:(OGTKWidget*)child xpos:(gint)xpos ypos:(gint)ypos
{
	gtk_text_view_move_child([self TEXTVIEW], [child WIDGET], xpos, ypos);
}

- (bool)moveMarkOnscreen:(OGTKTextMark*)mark
{
	return gtk_text_view_move_mark_onscreen([self TEXTVIEW], [mark TEXTMARK]);
}

- (bool)moveVisuallyWithIter:(GtkTextIter*)iter count:(gint)count
{
	return gtk_text_view_move_visually([self TEXTVIEW], iter, count);
}

- (bool)placeCursorOnscreen
{
	return gtk_text_view_place_cursor_onscreen([self TEXTVIEW]);
}

- (void)resetCursorBlink
{
	gtk_text_view_reset_cursor_blink([self TEXTVIEW]);
}

- (void)resetImContext
{
	gtk_text_view_reset_im_context([self TEXTVIEW]);
}

- (void)scrollMarkOnscreen:(OGTKTextMark*)mark
{
	gtk_text_view_scroll_mark_onscreen([self TEXTVIEW], [mark TEXTMARK]);
}

- (bool)scrollToIterWithIter:(GtkTextIter*)iter withinMargin:(gdouble)withinMargin useAlign:(bool)useAlign xalign:(gdouble)xalign yalign:(gdouble)yalign
{
	return gtk_text_view_scroll_to_iter([self TEXTVIEW], iter, withinMargin, useAlign, xalign, yalign);
}

- (void)scrollToMarkWithMark:(OGTKTextMark*)mark withinMargin:(gdouble)withinMargin useAlign:(bool)useAlign xalign:(gdouble)xalign yalign:(gdouble)yalign
{
	gtk_text_view_scroll_to_mark([self TEXTVIEW], [mark TEXTMARK], withinMargin, useAlign, xalign, yalign);
}

- (void)setAcceptsTab:(bool)acceptsTab
{
	gtk_text_view_set_accepts_tab([self TEXTVIEW], acceptsTab);
}

- (void)setBorderWindowSizeWithType:(GtkTextWindowType)type size:(gint)size
{
	gtk_text_view_set_border_window_size([self TEXTVIEW], type, size);
}

- (void)setBottomMargin:(gint)bottomMargin
{
	gtk_text_view_set_bottom_margin([self TEXTVIEW], bottomMargin);
}

- (void)setBuffer:(OGTKTextBuffer*)buffer
{
	gtk_text_view_set_buffer([self TEXTVIEW], [buffer TEXTBUFFER]);
}

- (void)setCursorVisible:(bool)setting
{
	gtk_text_view_set_cursor_visible([self TEXTVIEW], setting);
}

- (void)setEditable:(bool)setting
{
	gtk_text_view_set_editable([self TEXTVIEW], setting);
}

- (void)setIndent:(gint)indent
{
	gtk_text_view_set_indent([self TEXTVIEW], indent);
}

- (void)setInputHints:(GtkInputHints)hints
{
	gtk_text_view_set_input_hints([self TEXTVIEW], hints);
}

- (void)setInputPurpose:(GtkInputPurpose)purpose
{
	gtk_text_view_set_input_purpose([self TEXTVIEW], purpose);
}

- (void)setJustification:(GtkJustification)justification
{
	gtk_text_view_set_justification([self TEXTVIEW], justification);
}

- (void)setLeftMargin:(gint)leftMargin
{
	gtk_text_view_set_left_margin([self TEXTVIEW], leftMargin);
}

- (void)setMonospace:(bool)monospace
{
	gtk_text_view_set_monospace([self TEXTVIEW], monospace);
}

- (void)setOverwrite:(bool)overwrite
{
	gtk_text_view_set_overwrite([self TEXTVIEW], overwrite);
}

- (void)setPixelsAboveLines:(gint)pixelsAboveLines
{
	gtk_text_view_set_pixels_above_lines([self TEXTVIEW], pixelsAboveLines);
}

- (void)setPixelsBelowLines:(gint)pixelsBelowLines
{
	gtk_text_view_set_pixels_below_lines([self TEXTVIEW], pixelsBelowLines);
}

- (void)setPixelsInsideWrap:(gint)pixelsInsideWrap
{
	gtk_text_view_set_pixels_inside_wrap([self TEXTVIEW], pixelsInsideWrap);
}

- (void)setRightMargin:(gint)rightMargin
{
	gtk_text_view_set_right_margin([self TEXTVIEW], rightMargin);
}

- (void)setTabs:(PangoTabArray*)tabs
{
	gtk_text_view_set_tabs([self TEXTVIEW], tabs);
}

- (void)setTopMargin:(gint)topMargin
{
	gtk_text_view_set_top_margin([self TEXTVIEW], topMargin);
}

- (void)setWrapMode:(GtkWrapMode)wrapMode
{
	gtk_text_view_set_wrap_mode([self TEXTVIEW], wrapMode);
}

- (bool)startsDisplayLine:(const GtkTextIter*)iter
{
	return gtk_text_view_starts_display_line([self TEXTVIEW], iter);
}

- (void)windowToBufferCoordsWithWin:(GtkTextWindowType)win windowX:(gint)windowX windowY:(gint)windowY bufferX:(gint*)bufferX bufferY:(gint*)bufferY
{
	gtk_text_view_window_to_buffer_coords([self TEXTVIEW], win, windowX, windowY, bufferX, bufferY);
}


@end