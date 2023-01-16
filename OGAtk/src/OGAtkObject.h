/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

@class OGAtkStateSet;
@class OGAtkRelationSet;

/**
 * This class is the primary class for accessibility support via the
 * Accessibility ToolKit (ATK).  Objects which are instances of
 * #AtkObject (or instances of AtkObject-derived types) are queried
 * for properties which relate basic (and generic) properties of a UI
 * component such as name and description.  Instances of #AtkObject
 * may also be queried as to whether they implement other ATK
 * interfaces (e.g. #AtkAction, #AtkComponent, etc.), as appropriate
 * to the role which a given UI component plays in a user interface.
 * 
 * All UI components in an application which provide useful
 * information or services to the user must provide corresponding
 * #AtkObject instances on request (in GTK+, for instance, usually on
 * a call to #gtk_widget_get_accessible ()), either via ATK support
 * built into the toolkit for the widget class or ancestor class, or
 * in the case of custom widgets, if the inherited #AtkObject
 * implementation is insufficient, via instances of a new #AtkObject
 * subclass.
 * 
 * See also: #AtkObjectFactory, #AtkRegistry.  (GTK+ users see also
 * #GtkAccessible).
 *
 */
@interface OGAtkObject : OGObject
{

}


/**
 * Methods
 */

- (AtkObject*)OBJECT;

/**
 * Adds a relationship of the specified type with the specified target.
 *
 * @param relationship The #AtkRelationType of the relation
 * @param target The #AtkObject which is to be the target of the relation.
 * @return TRUE if the relationship is added.
 */
- (bool)addRelationshipWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target;

/**
 * Calls @handler on property changes.
 *
 * @param handler a function to be called when a property changes its value
 * @return a #guint which is the handler id used in
 *   atk_object_remove_property_change_handler()
 */
- (guint)connectPropertyChangeHandler:(AtkPropertyChangeHandler*)handler;

/**
 * Gets the accessible id of the accessible.
 *
 * @return a character string representing the accessible id of the object, or
 * NULL if no such string was set.
 */
- (OFString*)accessibleId;

/**
 * Get a list of properties applied to this object as a whole, as an #AtkAttributeSet consisting of
 * name-value pairs. As such these attributes may be considered weakly-typed properties or annotations,
 * as distinct from strongly-typed object data available via other get/set methods.
 * Not all objects have explicit "name-value pair" #AtkAttributeSet properties.
 *
 * @return an #AtkAttributeSet consisting of all
 * explicit properties/annotations applied to the object, or an empty
 * set if the object has no name-value pair attributes assigned to
 * it. This #atkattributeset should be freed by a call to
 * atk_attribute_set_free().
 */
- (AtkAttributeSet*)attributes;

/**
 * Gets the accessible description of the accessible.
 *
 * @return a character string representing the accessible description
 * of the accessible.
 */
- (OFString*)description;

/**
 * Gets the 0-based index of this accessible in its parent; returns -1 if the
 * accessible does not have an accessible parent.
 *
 * @return an integer which is the index of the accessible in its parent
 */
- (gint)indexInParent;

/**
 * Gets the layer of the accessible.
 *
 * @return an #AtkLayer which is the layer of the accessible
 */
- (AtkLayer)layer;

/**
 * Gets the zorder of the accessible. The value G_MININT will be returned
 * if the layer of the accessible is not ATK_LAYER_MDI.
 *
 * @return a gint which is the zorder of the accessible, i.e. the depth at
 * which the component is shown in relation to other components in the same
 * container.
 */
- (gint)mdiZorder;

/**
 * Gets the number of accessible children of the accessible.
 *
 * @return an integer representing the number of accessible children
 * of the accessible.
 */
- (gint)naccessibleChildren;

/**
 * Gets the accessible name of the accessible.
 *
 * @return a character string representing the accessible name of the object.
 */
- (OFString*)name;

/**
 * Gets a UTF-8 string indicating the POSIX-style LC_MESSAGES locale
 * of @accessible.
 *
 * @return a UTF-8 string indicating the POSIX-style LC_MESSAGES
 *          locale of @accessible.
 */
- (OFString*)objectLocale;

/**
 * Gets the accessible parent of the accessible. By default this is
 * the one assigned with atk_object_set_parent(), but it is assumed
 * that ATK implementors have ways to get the parent of the object
 * without the need of assigning it manually with
 * atk_object_set_parent(), and will return it with this method.
 * 
 * If you are only interested on the parent assigned with
 * atk_object_set_parent(), use atk_object_peek_parent().
 *
 * @return an #AtkObject representing the accessible
 * parent of the accessible
 */
- (OGAtkObject*)parent;

/**
 * Gets the role of the accessible.
 *
 * @return an #AtkRole which is the role of the accessible
 */
- (AtkRole)role;

/**
 * This function is called when implementing subclasses of #AtkObject.
 * It does initialization required for the new object. It is intended
 * that this function should called only in the ..._new() functions used
 * to create an instance of a subclass of #AtkObject
 *
 * @param data a #gpointer which identifies the object for which the AtkObject was created.
 */
- (void)initialize:(gpointer)data;

/**
 * Emits a state-change signal for the specified state.
 * 
 * Note that as a general rule when the state of an existing object changes,
 * emitting a notification is expected.
 *
 * @param state an #AtkState whose state is changed
 * @param value a gboolean which indicates whether the state is being set on or off
 */
- (void)notifyStateChangeWithState:(AtkState)state value:(bool)value;

/**
 * Gets the accessible parent of the accessible, if it has been
 * manually assigned with atk_object_set_parent. Otherwise, this
 * function returns %NULL.
 * 
 * This method is intended as an utility for ATK implementors, and not
 * to be exposed to accessible tools. See atk_object_get_parent() for
 * further reference.
 *
 * @return an #AtkObject representing the accessible
 * parent of the accessible if assigned
 */
- (OGAtkObject*)peekParent;

/**
 * Gets a reference to the specified accessible child of the object.
 * The accessible children are 0-based so the first accessible child is
 * at index 0, the second at index 1 and so on.
 *
 * @param i a gint representing the position of the child, starting from 0
 * @return an #AtkObject representing the specified
 * accessible child of the accessible.
 */
- (OGAtkObject*)refAccessibleChild:(gint)i;

/**
 * Gets the #AtkRelationSet associated with the object.
 *
 * @return an #AtkRelationSet representing the relation set
 * of the object.
 */
- (OGAtkRelationSet*)refRelationSet;

/**
 * Gets a reference to the state set of the accessible; the caller must
 * unreference it when it is no longer needed.
 *
 * @return a reference to an #AtkStateSet which is the state
 * set of the accessible
 */
- (OGAtkStateSet*)refStateSet;

/**
 * Removes a property change handler.
 *
 * @param handlerId a guint which identifies the handler to be removed.
 */
- (void)removePropertyChangeHandler:(guint)handlerId;

/**
 * Removes a relationship of the specified type with the specified target.
 *
 * @param relationship The #AtkRelationType of the relation
 * @param target The #AtkObject which is the target of the relation to be removed.
 * @return TRUE if the relationship is removed.
 */
- (bool)removeRelationshipWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target;

/**
 * Sets the accessible ID of the accessible.  This is not meant to be presented
 * to the user, but to be an ID which is stable over application development.
 * Typically, this is the gtkbuilder ID. Such an ID will be available for
 * instance to identify a given well-known accessible object for tailored screen
 * reading, or for automatic regression testing.
 *
 * @param name a character string to be set as the accessible id
 */
- (void)setAccessibleId:(OFString*)name;

/**
 * Sets the accessible description of the accessible. You can't set
 * the description to NULL. This is reserved for the initial value. In
 * this aspect NULL is similar to ATK_ROLE_UNKNOWN. If you want to set
 * the name to a empty value you can use "".
 *
 * @param description a character string to be set as the accessible description
 */
- (void)setDescription:(OFString*)description;

/**
 * Sets the accessible name of the accessible. You can't set the name
 * to NULL. This is reserved for the initial value. In this aspect
 * NULL is similar to ATK_ROLE_UNKNOWN. If you want to set the name to
 * a empty value you can use "".
 *
 * @param name a character string to be set as the accessible name
 */
- (void)setName:(OFString*)name;

/**
 * Sets the accessible parent of the accessible. @parent can be NULL.
 *
 * @param parent an #AtkObject to be set as the accessible parent
 */
- (void)setParent:(OGAtkObject*)parent;

/**
 * Sets the role of the accessible.
 *
 * @param role an #AtkRole to be set as the role
 */
- (void)setRole:(AtkRole)role;

@end