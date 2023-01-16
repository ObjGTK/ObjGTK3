/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTable.h"

#import "OGTKWidget.h"

@implementation OGTKTable

- (instancetype)initWithRows:(guint)rows columns:(guint)columns homogeneous:(bool)homogeneous
{
	self = [super initWithGObject:(GObject*)gtk_table_new(rows, columns, homogeneous)];

	return self;
}

- (GtkTable*)TABLE
{
	return GTK_TABLE([self GOBJECT]);
}

- (void)attachWithChild:(OGTKWidget*)child leftAttach:(guint)leftAttach rightAttach:(guint)rightAttach topAttach:(guint)topAttach bottomAttach:(guint)bottomAttach xoptions:(GtkAttachOptions)xoptions yoptions:(GtkAttachOptions)yoptions xpadding:(guint)xpadding ypadding:(guint)ypadding
{
	gtk_table_attach([self TABLE], [child WIDGET], leftAttach, rightAttach, topAttach, bottomAttach, xoptions, yoptions, xpadding, ypadding);
}

- (void)attachDefaultsWithWidget:(OGTKWidget*)widget leftAttach:(guint)leftAttach rightAttach:(guint)rightAttach topAttach:(guint)topAttach bottomAttach:(guint)bottomAttach
{
	gtk_table_attach_defaults([self TABLE], [widget WIDGET], leftAttach, rightAttach, topAttach, bottomAttach);
}

- (guint)colSpacing:(guint)column
{
	return gtk_table_get_col_spacing([self TABLE], column);
}

- (guint)defaultColSpacing
{
	return gtk_table_get_default_col_spacing([self TABLE]);
}

- (guint)defaultRowSpacing
{
	return gtk_table_get_default_row_spacing([self TABLE]);
}

- (bool)homogeneous
{
	return gtk_table_get_homogeneous([self TABLE]);
}

- (guint)rowSpacing:(guint)row
{
	return gtk_table_get_row_spacing([self TABLE], row);
}

- (void)sizeWithRows:(guint*)rows columns:(guint*)columns
{
	gtk_table_get_size([self TABLE], rows, columns);
}

- (void)resizeWithRows:(guint)rows columns:(guint)columns
{
	gtk_table_resize([self TABLE], rows, columns);
}

- (void)setColSpacingWithColumn:(guint)column spacing:(guint)spacing
{
	gtk_table_set_col_spacing([self TABLE], column, spacing);
}

- (void)setColSpacings:(guint)spacing
{
	gtk_table_set_col_spacings([self TABLE], spacing);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_table_set_homogeneous([self TABLE], homogeneous);
}

- (void)setRowSpacingWithRow:(guint)row spacing:(guint)spacing
{
	gtk_table_set_row_spacing([self TABLE], row, spacing);
}

- (void)setRowSpacings:(guint)spacing
{
	gtk_table_set_row_spacings([self TABLE], spacing);
}


@end