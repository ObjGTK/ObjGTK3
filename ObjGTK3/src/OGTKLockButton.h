/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

@class OGTKWidget;

/**
 * GtkLockButton is a widget that can be used in control panels or
 * preference dialogs to allow users to obtain and revoke authorizations
 * needed to operate the controls. The required authorization is represented
 * by a #GPermission object. Concrete implementations of #GPermission may use
 * PolicyKit or some other authorization framework. To obtain a PolicyKit-based
 * #GPermission, use polkit_permission_new().
 * 
 * If the user is not currently allowed to perform the action, but can obtain
 * the permission, the widget looks like this:
 * 
 * ![](lockbutton-locked.png)
 * 
 * and the user can click the button to request the permission. Depending
 * on the platform, this may pop up an authentication dialog or ask the user
 * to authenticate in some other way. Once the user has obtained the permission,
 * the widget changes to this:
 * 
 * ![](lockbutton-unlocked.png)
 * 
 * and the permission can be dropped again by clicking the button. If the user
 * is not able to obtain the permission at all, the widget looks like this:
 * 
 * ![](lockbutton-sorry.png)
 * 
 * If the user has the permission and cannot drop it, the button is hidden.
 * 
 * The text (and tooltips) that are shown in the various cases can be adjusted
 * with the #GtkLockButton:text-lock, #GtkLockButton:text-unlock,
 * #GtkLockButton:tooltip-lock, #GtkLockButton:tooltip-unlock and
 * #GtkLockButton:tooltip-not-authorized properties.
 *
 */
@interface OGTKLockButton : OGTKButton
{

}


/**
 * Constructors
 */
- (instancetype)init:(GPermission*)permission;

/**
 * Methods
 */

- (GtkLockButton*)LOCKBUTTON;

/**
 * Obtains the #GPermission object that controls @button.
 *
 * @return the #GPermission of @button
 */
- (GPermission*)permission;

/**
 * Sets the #GPermission object that controls @button.
 *
 * @param permission a #GPermission object, or %NULL
 */
- (void)setPermission:(GPermission*)permission;

@end