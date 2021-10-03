/*
 * OGTKEntry.h
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
#import "OGTKWidget.h"

@interface OGTKEntry : OGTKWidget
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithBuffer:(GtkEntryBuffer*)buffer;

/**
 * Methods
 */

- (GtkEntry*)ENTRY;

/**
 * - (bool*)getActivatesDefault;
 *
 * @returns bool
 */
- (bool)getActivatesDefault;

/**
 * - (gfloat*)getAlignment;
 *
 * @returns gfloat
 */
- (gfloat)getAlignment;

/**
 * - (PangoAttrList**)getAttributes;
 *
 * @returns PangoAttrList*
 */
- (PangoAttrList*)getAttributes;

/**
 * - (GtkEntryBuffer**)getBuffer;
 *
 * @returns GtkEntryBuffer*
 */
- (GtkEntryBuffer*)getBuffer;

/**
 * - (GtkEntryCompletion**)getCompletion;
 *
 * @returns GtkEntryCompletion*
 */
- (GtkEntryCompletion*)getCompletion;

/**
 * - (gint*)getCurrentIconDragSource;
 *
 * @returns gint
 */
- (gint)getCurrentIconDragSource;

/**
 * - (GtkAdjustment**)getCursorHadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getCursorHadjustment;

/**
 * - (bool*)getHasFrame;
 *
 * @returns bool
 */
- (bool)getHasFrame;

/**
 * - (bool*)getIconActivatable:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns bool
 */
- (bool)getIconActivatable:(GtkEntryIconPosition)iconPos;

/**
 * - (void*)getIconAreaWithIconPos:(GtkEntryIconPosition)iconPos andIconArea:(GdkRectangle*)iconArea;
 *
 * @param iconPos
 * @param iconArea
 */
- (void)getIconAreaWithIconPos:(GtkEntryIconPosition)iconPos andIconArea:(GdkRectangle*)iconArea;

/**
 * - (gint*)getIconAtPosWithX:(gint)x andY:(gint)y;
 *
 * @param x
 * @param y
 * @returns gint
 */
- (gint)getIconAtPosWithX:(gint)x andY:(gint)y;

/**
 * - (GIcon**)getIconGicon:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns GIcon*
 */
- (GIcon*)getIconGicon:(GtkEntryIconPosition)iconPos;

/**
 * - (OFString**)getIconName:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns OFString*
 */
- (OFString*)getIconName:(GtkEntryIconPosition)iconPos;

/**
 * - (GdkPixbuf**)getIconPixbuf:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getIconPixbuf:(GtkEntryIconPosition)iconPos;

/**
 * - (bool*)getIconSensitive:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns bool
 */
- (bool)getIconSensitive:(GtkEntryIconPosition)iconPos;

/**
 * - (OFString**)getIconStock:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns OFString*
 */
- (OFString*)getIconStock:(GtkEntryIconPosition)iconPos;

/**
 * - (GtkImageType*)getIconStorageType:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns GtkImageType
 */
- (GtkImageType)getIconStorageType:(GtkEntryIconPosition)iconPos;

/**
 * - (OFString**)getIconTooltipMarkup:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns OFString*
 */
- (OFString*)getIconTooltipMarkup:(GtkEntryIconPosition)iconPos;

/**
 * - (OFString**)getIconTooltipText:(GtkEntryIconPosition)iconPos;
 *
 * @param iconPos
 * @returns OFString*
 */
- (OFString*)getIconTooltipText:(GtkEntryIconPosition)iconPos;

/**
 * - (const GtkBorder**)getInnerBorder;
 *
 * @returns const GtkBorder*
 */
- (const GtkBorder*)getInnerBorder;

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
 * - (gunichar*)getInvisibleChar;
 *
 * @returns gunichar
 */
- (gunichar)getInvisibleChar;

/**
 * - (PangoLayout**)getLayout;
 *
 * @returns PangoLayout*
 */
- (PangoLayout*)getLayout;

/**
 * - (void*)getLayoutOffsetsWithX:(gint*)x andY:(gint*)y;
 *
 * @param x
 * @param y
 */
- (void)getLayoutOffsetsWithX:(gint*)x andY:(gint*)y;

/**
 * - (gint*)getMaxLength;
 *
 * @returns gint
 */
- (gint)getMaxLength;

/**
 * - (gint*)getMaxWidthChars;
 *
 * @returns gint
 */
- (gint)getMaxWidthChars;

/**
 * - (bool*)getOverwriteMode;
 *
 * @returns bool
 */
- (bool)getOverwriteMode;

/**
 * - (OFString**)getPlaceholderText;
 *
 * @returns OFString*
 */
- (OFString*)getPlaceholderText;

/**
 * - (gdouble*)getProgressFraction;
 *
 * @returns gdouble
 */
- (gdouble)getProgressFraction;

/**
 * - (gdouble*)getProgressPulseStep;
 *
 * @returns gdouble
 */
- (gdouble)getProgressPulseStep;

/**
 * - (PangoTabArray**)getTabs;
 *
 * @returns PangoTabArray*
 */
- (PangoTabArray*)getTabs;

/**
 * - (OFString**)getText;
 *
 * @returns OFString*
 */
- (OFString*)getText;

/**
 * - (void*)getTextArea:(GdkRectangle*)textArea;
 *
 * @param textArea
 */
- (void)getTextArea:(GdkRectangle*)textArea;

/**
 * - (guint16*)getTextLength;
 *
 * @returns guint16
 */
- (guint16)getTextLength;

/**
 * - (bool*)getVisibility;
 *
 * @returns bool
 */
- (bool)getVisibility;

/**
 * - (gint*)getWidthChars;
 *
 * @returns gint
 */
- (gint)getWidthChars;

/**
 * - (void*)grabFocusWithoutSelecting;
 *
 */
- (void)grabFocusWithoutSelecting;

/**
 * - (bool*)imContextFilterKeypress:(GdkEventKey*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)imContextFilterKeypress:(GdkEventKey*)event;

/**
 * - (gint*)layoutIndexToTextIndex:(gint)layoutIndex;
 *
 * @param layoutIndex
 * @returns gint
 */
- (gint)layoutIndexToTextIndex:(gint)layoutIndex;

/**
 * - (void*)progressPulse;
 *
 */
- (void)progressPulse;

/**
 * - (void*)resetImContext;
 *
 */
- (void)resetImContext;

/**
 * - (void*)setActivatesDefault:(bool)setting;
 *
 * @param setting
 */
- (void)setActivatesDefault:(bool)setting;

/**
 * - (void*)setAlignment:(gfloat)xalign;
 *
 * @param xalign
 */
- (void)setAlignment:(gfloat)xalign;

/**
 * - (void*)setAttributes:(PangoAttrList*)attrs;
 *
 * @param attrs
 */
- (void)setAttributes:(PangoAttrList*)attrs;

/**
 * - (void*)setBuffer:(GtkEntryBuffer*)buffer;
 *
 * @param buffer
 */
- (void)setBuffer:(GtkEntryBuffer*)buffer;

/**
 * - (void*)setCompletion:(GtkEntryCompletion*)completion;
 *
 * @param completion
 */
- (void)setCompletion:(GtkEntryCompletion*)completion;

/**
 * - (void*)setCursorHadjustment:(GtkAdjustment*)adjustment;
 *
 * @param adjustment
 */
- (void)setCursorHadjustment:(GtkAdjustment*)adjustment;

/**
 * - (void*)setHasFrame:(bool)setting;
 *
 * @param setting
 */
- (void)setHasFrame:(bool)setting;

/**
 * - (void*)setIconActivatableWithIconPos:(GtkEntryIconPosition)iconPos andActivatable:(bool)activatable;
 *
 * @param iconPos
 * @param activatable
 */
- (void)setIconActivatableWithIconPos:(GtkEntryIconPosition)iconPos andActivatable:(bool)activatable;

/**
 * - (void*)setIconDragSourceWithIconPos:(GtkEntryIconPosition)iconPos andTargetList:(GtkTargetList*)targetList andActions:(GdkDragAction)actions;
 *
 * @param iconPos
 * @param targetList
 * @param actions
 */
- (void)setIconDragSourceWithIconPos:(GtkEntryIconPosition)iconPos andTargetList:(GtkTargetList*)targetList andActions:(GdkDragAction)actions;

/**
 * - (void*)setIconFromGiconWithIconPos:(GtkEntryIconPosition)iconPos andIcon:(GIcon*)icon;
 *
 * @param iconPos
 * @param icon
 */
- (void)setIconFromGiconWithIconPos:(GtkEntryIconPosition)iconPos andIcon:(GIcon*)icon;

/**
 * - (void*)setIconFromIconNameWithIconPos:(GtkEntryIconPosition)iconPos andIconName:(OFString*)iconName;
 *
 * @param iconPos
 * @param iconName
 */
- (void)setIconFromIconNameWithIconPos:(GtkEntryIconPosition)iconPos andIconName:(OFString*)iconName;

/**
 * - (void*)setIconFromPixbufWithIconPos:(GtkEntryIconPosition)iconPos andPixbuf:(GdkPixbuf*)pixbuf;
 *
 * @param iconPos
 * @param pixbuf
 */
- (void)setIconFromPixbufWithIconPos:(GtkEntryIconPosition)iconPos andPixbuf:(GdkPixbuf*)pixbuf;

/**
 * - (void*)setIconFromStockWithIconPos:(GtkEntryIconPosition)iconPos andStockId:(OFString*)stockId;
 *
 * @param iconPos
 * @param stockId
 */
- (void)setIconFromStockWithIconPos:(GtkEntryIconPosition)iconPos andStockId:(OFString*)stockId;

/**
 * - (void*)setIconSensitiveWithIconPos:(GtkEntryIconPosition)iconPos andSensitive:(bool)sensitive;
 *
 * @param iconPos
 * @param sensitive
 */
- (void)setIconSensitiveWithIconPos:(GtkEntryIconPosition)iconPos andSensitive:(bool)sensitive;

/**
 * - (void*)setIconTooltipMarkupWithIconPos:(GtkEntryIconPosition)iconPos andTooltip:(OFString*)tooltip;
 *
 * @param iconPos
 * @param tooltip
 */
- (void)setIconTooltipMarkupWithIconPos:(GtkEntryIconPosition)iconPos andTooltip:(OFString*)tooltip;

/**
 * - (void*)setIconTooltipTextWithIconPos:(GtkEntryIconPosition)iconPos andTooltip:(OFString*)tooltip;
 *
 * @param iconPos
 * @param tooltip
 */
- (void)setIconTooltipTextWithIconPos:(GtkEntryIconPosition)iconPos andTooltip:(OFString*)tooltip;

/**
 * - (void*)setInnerBorder:(const GtkBorder*)border;
 *
 * @param border
 */
- (void)setInnerBorder:(const GtkBorder*)border;

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
 * - (void*)setInvisibleChar:(gunichar)ch;
 *
 * @param ch
 */
- (void)setInvisibleChar:(gunichar)ch;

/**
 * - (void*)setMaxLength:(gint)max;
 *
 * @param max
 */
- (void)setMaxLength:(gint)max;

/**
 * - (void*)setMaxWidthChars:(gint)nchars;
 *
 * @param nchars
 */
- (void)setMaxWidthChars:(gint)nchars;

/**
 * - (void*)setOverwriteMode:(bool)overwrite;
 *
 * @param overwrite
 */
- (void)setOverwriteMode:(bool)overwrite;

/**
 * - (void*)setPlaceholderText:(OFString*)text;
 *
 * @param text
 */
- (void)setPlaceholderText:(OFString*)text;

/**
 * - (void*)setProgressFraction:(gdouble)fraction;
 *
 * @param fraction
 */
- (void)setProgressFraction:(gdouble)fraction;

/**
 * - (void*)setProgressPulseStep:(gdouble)fraction;
 *
 * @param fraction
 */
- (void)setProgressPulseStep:(gdouble)fraction;

/**
 * - (void*)setTabs:(PangoTabArray*)tabs;
 *
 * @param tabs
 */
- (void)setTabs:(PangoTabArray*)tabs;

/**
 * - (void*)setText:(OFString*)text;
 *
 * @param text
 */
- (void)setText:(OFString*)text;

/**
 * - (void*)setVisibility:(bool)visible;
 *
 * @param visible
 */
- (void)setVisibility:(bool)visible;

/**
 * - (void*)setWidthChars:(gint)nchars;
 *
 * @param nchars
 */
- (void)setWidthChars:(gint)nchars;

/**
 * - (gint*)textIndexToLayoutIndex:(gint)textIndex;
 *
 * @param textIndex
 * @returns gint
 */
- (gint)textIndexToLayoutIndex:(gint)textIndex;

/**
 * - (void*)unsetInvisibleChar;
 *
 */
- (void)unsetInvisibleChar;

@end