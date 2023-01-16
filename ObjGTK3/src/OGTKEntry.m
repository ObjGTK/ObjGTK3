/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEntry.h"

#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKEntryCompletion.h"
#import "OGTKAdjustment.h"
#import <OGPango/OGPangoLayout.h>
#import "OGTKEntryBuffer.h"

@implementation OGTKEntry

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_entry_new()];

	return self;
}

- (instancetype)initWithBuffer:(OGTKEntryBuffer*)buffer
{
	self = [super initWithGObject:(GObject*)gtk_entry_new_with_buffer([buffer ENTRYBUFFER])];

	return self;
}

- (GtkEntry*)ENTRY
{
	return GTK_ENTRY([self GOBJECT]);
}

- (bool)activatesDefault
{
	return gtk_entry_get_activates_default([self ENTRY]);
}

- (gfloat)alignment
{
	return gtk_entry_get_alignment([self ENTRY]);
}

- (PangoAttrList*)attributes
{
	return gtk_entry_get_attributes([self ENTRY]);
}

- (OGTKEntryBuffer*)buffer
{
	return [[[OGTKEntryBuffer alloc] initWithGObject:(GObject*)gtk_entry_get_buffer([self ENTRY])] autorelease];
}

- (OGTKEntryCompletion*)completion
{
	return [[[OGTKEntryCompletion alloc] initWithGObject:(GObject*)gtk_entry_get_completion([self ENTRY])] autorelease];
}

- (gint)currentIconDragSource
{
	return gtk_entry_get_current_icon_drag_source([self ENTRY]);
}

- (OGTKAdjustment*)cursorHadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_entry_get_cursor_hadjustment([self ENTRY])] autorelease];
}

- (bool)hasFrame
{
	return gtk_entry_get_has_frame([self ENTRY]);
}

- (bool)iconActivatable:(GtkEntryIconPosition)iconPos
{
	return gtk_entry_get_icon_activatable([self ENTRY], iconPos);
}

- (void)iconAreaWithIconPos:(GtkEntryIconPosition)iconPos iconArea:(GdkRectangle*)iconArea
{
	gtk_entry_get_icon_area([self ENTRY], iconPos, iconArea);
}

- (gint)iconAtPosWithX:(gint)x y:(gint)y
{
	return gtk_entry_get_icon_at_pos([self ENTRY], x, y);
}

- (GIcon*)iconGicon:(GtkEntryIconPosition)iconPos
{
	return gtk_entry_get_icon_gicon([self ENTRY], iconPos);
}

- (OFString*)iconName:(GtkEntryIconPosition)iconPos
{
	return [OFString stringWithUTF8String:gtk_entry_get_icon_name([self ENTRY], iconPos)];
}

- (OGGdkPixbuf*)iconPixbuf:(GtkEntryIconPosition)iconPos
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_entry_get_icon_pixbuf([self ENTRY], iconPos)] autorelease];
}

- (bool)iconSensitive:(GtkEntryIconPosition)iconPos
{
	return gtk_entry_get_icon_sensitive([self ENTRY], iconPos);
}

- (OFString*)iconStock:(GtkEntryIconPosition)iconPos
{
	return [OFString stringWithUTF8String:gtk_entry_get_icon_stock([self ENTRY], iconPos)];
}

- (GtkImageType)iconStorageType:(GtkEntryIconPosition)iconPos
{
	return gtk_entry_get_icon_storage_type([self ENTRY], iconPos);
}

- (OFString*)iconTooltipMarkup:(GtkEntryIconPosition)iconPos
{
	return [OFString stringWithUTF8String:gtk_entry_get_icon_tooltip_markup([self ENTRY], iconPos)];
}

- (OFString*)iconTooltipText:(GtkEntryIconPosition)iconPos
{
	return [OFString stringWithUTF8String:gtk_entry_get_icon_tooltip_text([self ENTRY], iconPos)];
}

- (const GtkBorder*)innerBorder
{
	return gtk_entry_get_inner_border([self ENTRY]);
}

- (GtkInputHints)inputHints
{
	return gtk_entry_get_input_hints([self ENTRY]);
}

- (GtkInputPurpose)inputPurpose
{
	return gtk_entry_get_input_purpose([self ENTRY]);
}

- (gunichar)invisibleChar
{
	return gtk_entry_get_invisible_char([self ENTRY]);
}

- (OGPangoLayout*)layout
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)gtk_entry_get_layout([self ENTRY])] autorelease];
}

- (void)layoutOffsetsWithX:(gint*)x y:(gint*)y
{
	gtk_entry_get_layout_offsets([self ENTRY], x, y);
}

- (gint)maxLength
{
	return gtk_entry_get_max_length([self ENTRY]);
}

- (gint)maxWidthChars
{
	return gtk_entry_get_max_width_chars([self ENTRY]);
}

- (bool)overwriteMode
{
	return gtk_entry_get_overwrite_mode([self ENTRY]);
}

- (OFString*)placeholderText
{
	return [OFString stringWithUTF8String:gtk_entry_get_placeholder_text([self ENTRY])];
}

- (gdouble)progressFraction
{
	return gtk_entry_get_progress_fraction([self ENTRY]);
}

- (gdouble)progressPulseStep
{
	return gtk_entry_get_progress_pulse_step([self ENTRY]);
}

- (PangoTabArray*)tabs
{
	return gtk_entry_get_tabs([self ENTRY]);
}

- (OFString*)text
{
	return [OFString stringWithUTF8String:gtk_entry_get_text([self ENTRY])];
}

- (void)textArea:(GdkRectangle*)textArea
{
	gtk_entry_get_text_area([self ENTRY], textArea);
}

- (guint16)textLength
{
	return gtk_entry_get_text_length([self ENTRY]);
}

- (bool)visibility
{
	return gtk_entry_get_visibility([self ENTRY]);
}

- (gint)widthChars
{
	return gtk_entry_get_width_chars([self ENTRY]);
}

- (void)grabFocusWithoutSelecting
{
	gtk_entry_grab_focus_without_selecting([self ENTRY]);
}

- (bool)imContextFilterKeypress:(GdkEventKey*)event
{
	return gtk_entry_im_context_filter_keypress([self ENTRY], event);
}

- (gint)layoutIndexToTextIndex:(gint)layoutIndex
{
	return gtk_entry_layout_index_to_text_index([self ENTRY], layoutIndex);
}

- (void)progressPulse
{
	gtk_entry_progress_pulse([self ENTRY]);
}

- (void)resetImContext
{
	gtk_entry_reset_im_context([self ENTRY]);
}

- (void)setActivatesDefault:(bool)setting
{
	gtk_entry_set_activates_default([self ENTRY], setting);
}

- (void)setAlignment:(gfloat)xalign
{
	gtk_entry_set_alignment([self ENTRY], xalign);
}

- (void)setAttributes:(PangoAttrList*)attrs
{
	gtk_entry_set_attributes([self ENTRY], attrs);
}

- (void)setBuffer:(OGTKEntryBuffer*)buffer
{
	gtk_entry_set_buffer([self ENTRY], [buffer ENTRYBUFFER]);
}

- (void)setCompletion:(OGTKEntryCompletion*)completion
{
	gtk_entry_set_completion([self ENTRY], [completion ENTRYCOMPLETION]);
}

- (void)setCursorHadjustment:(OGTKAdjustment*)adjustment
{
	gtk_entry_set_cursor_hadjustment([self ENTRY], [adjustment ADJUSTMENT]);
}

- (void)setHasFrame:(bool)setting
{
	gtk_entry_set_has_frame([self ENTRY], setting);
}

- (void)setIconActivatableWithIconPos:(GtkEntryIconPosition)iconPos activatable:(bool)activatable
{
	gtk_entry_set_icon_activatable([self ENTRY], iconPos, activatable);
}

- (void)setIconDragSourceWithIconPos:(GtkEntryIconPosition)iconPos targetList:(GtkTargetList*)targetList actions:(GdkDragAction)actions
{
	gtk_entry_set_icon_drag_source([self ENTRY], iconPos, targetList, actions);
}

- (void)setIconFromGiconWithIconPos:(GtkEntryIconPosition)iconPos icon:(GIcon*)icon
{
	gtk_entry_set_icon_from_gicon([self ENTRY], iconPos, icon);
}

- (void)setIconFromIconNameWithIconPos:(GtkEntryIconPosition)iconPos iconName:(OFString*)iconName
{
	gtk_entry_set_icon_from_icon_name([self ENTRY], iconPos, [iconName UTF8String]);
}

- (void)setIconFromPixbufWithIconPos:(GtkEntryIconPosition)iconPos pixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_entry_set_icon_from_pixbuf([self ENTRY], iconPos, [pixbuf PIXBUF]);
}

- (void)setIconFromStockWithIconPos:(GtkEntryIconPosition)iconPos stockId:(OFString*)stockId
{
	gtk_entry_set_icon_from_stock([self ENTRY], iconPos, [stockId UTF8String]);
}

- (void)setIconSensitiveWithIconPos:(GtkEntryIconPosition)iconPos sensitive:(bool)sensitive
{
	gtk_entry_set_icon_sensitive([self ENTRY], iconPos, sensitive);
}

- (void)setIconTooltipMarkupWithIconPos:(GtkEntryIconPosition)iconPos tooltip:(OFString*)tooltip
{
	gtk_entry_set_icon_tooltip_markup([self ENTRY], iconPos, [tooltip UTF8String]);
}

- (void)setIconTooltipTextWithIconPos:(GtkEntryIconPosition)iconPos tooltip:(OFString*)tooltip
{
	gtk_entry_set_icon_tooltip_text([self ENTRY], iconPos, [tooltip UTF8String]);
}

- (void)setInnerBorder:(const GtkBorder*)border
{
	gtk_entry_set_inner_border([self ENTRY], border);
}

- (void)setInputHints:(GtkInputHints)hints
{
	gtk_entry_set_input_hints([self ENTRY], hints);
}

- (void)setInputPurpose:(GtkInputPurpose)purpose
{
	gtk_entry_set_input_purpose([self ENTRY], purpose);
}

- (void)setInvisibleChar:(gunichar)ch
{
	gtk_entry_set_invisible_char([self ENTRY], ch);
}

- (void)setMaxLength:(gint)max
{
	gtk_entry_set_max_length([self ENTRY], max);
}

- (void)setMaxWidthChars:(gint)nchars
{
	gtk_entry_set_max_width_chars([self ENTRY], nchars);
}

- (void)setOverwriteMode:(bool)overwrite
{
	gtk_entry_set_overwrite_mode([self ENTRY], overwrite);
}

- (void)setPlaceholderText:(OFString*)text
{
	gtk_entry_set_placeholder_text([self ENTRY], [text UTF8String]);
}

- (void)setProgressFraction:(gdouble)fraction
{
	gtk_entry_set_progress_fraction([self ENTRY], fraction);
}

- (void)setProgressPulseStep:(gdouble)fraction
{
	gtk_entry_set_progress_pulse_step([self ENTRY], fraction);
}

- (void)setTabs:(PangoTabArray*)tabs
{
	gtk_entry_set_tabs([self ENTRY], tabs);
}

- (void)setText:(OFString*)text
{
	gtk_entry_set_text([self ENTRY], [text UTF8String]);
}

- (void)setVisibility:(bool)visible
{
	gtk_entry_set_visibility([self ENTRY], visible);
}

- (void)setWidthChars:(gint)nchars
{
	gtk_entry_set_width_chars([self ENTRY], nchars);
}

- (gint)textIndexToLayoutIndex:(gint)textIndex
{
	return gtk_entry_text_index_to_layout_index([self ENTRY], textIndex);
}

- (void)unsetInvisibleChar
{
	gtk_entry_unset_invisible_char([self ENTRY]);
}


@end