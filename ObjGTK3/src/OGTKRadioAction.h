/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleAction.h"

/**
 * A #GtkRadioAction is similar to #GtkRadioMenuItem. A number of radio
 * actions can be linked together so that only one may be active at any
 * one time.
 *
 */
@interface OGTKRadioAction : OGTKToggleAction
{

}


/**
 * Constructors
 */
- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId value:(gint)value;

/**
 * Methods
 */

- (GtkRadioAction*)RADIOACTION;

/**
 * Obtains the value property of the currently active member of
 * the group to which @action belongs.
 *
 * @return The value of the currently active group member
 */
- (gint)currentValue;

/**
 * Returns the list representing the radio group for this object.
 * Note that the returned list is only valid until the next change
 * to the group.
 * 
 * A common way to set up a group of radio group is the following:
 * |[<!-- language="C" -->
 *   GSList *group = NULL;
 *   GtkRadioAction *action;
 *  
 *   while ( ...more actions to add... /)
 *     {
 *        action = gtk_radio_action_new (...);
 *        
 *        gtk_radio_action_set_group (action, group);
 *        group = gtk_radio_action_get_group (action);
 *     }
 * ]|
 *
 * @return the list representing the radio group for this object
 */
- (GSList*)group;

/**
 * Joins a radio action object to the group of another radio action object.
 * 
 * Use this in language bindings instead of the gtk_radio_action_get_group()
 * and gtk_radio_action_set_group() methods
 * 
 * A common way to set up a group of radio actions is the following:
 * |[<!-- language="C" -->
 *   GtkRadioAction *action;
 *   GtkRadioAction *last_action;
 *  
 *   while ( ...more actions to add... /)
 *     {
 *        action = gtk_radio_action_new (...);
 *        
 *        gtk_radio_action_join_group (action, last_action);
 *        last_action = action;
 *     }
 * ]|
 *
 * @param groupSource a radio action object whos group we are
 *   joining, or %NULL to remove the radio action from its group
 */
- (void)joinGroup:(OGTKRadioAction*)groupSource;

/**
 * Sets the currently active group member to the member with value
 * property @current_value.
 *
 * @param currentValue the new value
 */
- (void)setCurrentValue:(gint)currentValue;

/**
 * Sets the radio group for the radio action object.
 *
 * @param group a list representing a radio group, or %NULL
 */
- (void)setGroup:(GSList*)group;

@end