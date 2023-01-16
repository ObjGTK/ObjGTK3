/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventController.h"

@class OGGdkWindow;
@class OGGdkDevice;

/**
 * #GtkGesture is the base object for gesture recognition, although this
 * object is quite generalized to serve as a base for multi-touch gestures,
 * it is suitable to implement single-touch and pointer-based gestures (using
 * the special %NULL #GdkEventSequence value for these).
 * 
 * The number of touches that a #GtkGesture need to be recognized is controlled
 * by the #GtkGesture:n-points property, if a gesture is keeping track of less
 * or more than that number of sequences, it won't check wether the gesture
 * is recognized.
 * 
 * As soon as the gesture has the expected number of touches, the gesture will
 * run the #GtkGesture::check signal regularly on input events until the gesture
 * is recognized, the criteria to consider a gesture as "recognized" is left to
 * #GtkGesture subclasses.
 * 
 * A recognized gesture will then emit the following signals:
 * - #GtkGesture::begin when the gesture is recognized.
 * - A number of #GtkGesture::update, whenever an input event is processed.
 * - #GtkGesture::end when the gesture is no longer recognized.
 * 
 * ## Event propagation
 * 
 * In order to receive events, a gesture needs to either set a propagation phase
 * through gtk_event_controller_set_propagation_phase(), or feed those manually
 * through gtk_event_controller_handle_event().
 * 
 * In the capture phase, events are propagated from the toplevel down to the
 * target widget, and gestures that are attached to containers above the widget
 * get a chance to interact with the event before it reaches the target.
 * 
 * After the capture phase, GTK+ emits the traditional #GtkWidget::button-press-event,
 * #GtkWidget::button-release-event, #GtkWidget::touch-event, etc signals. Gestures
 * with the %GTK_PHASE_TARGET phase are fed events from the default #GtkWidget::event
 * handlers.
 * 
 * In the bubble phase, events are propagated up from the target widget to the
 * toplevel, and gestures that are attached to containers above the widget get
 * a chance to interact with events that have not been handled yet.
 * 
 * ## States of a sequence # {#touch-sequence-states}
 * 
 * Whenever input interaction happens, a single event may trigger a cascade of
 * #GtkGestures, both across the parents of the widget receiving the event and
 * in parallel within an individual widget. It is a responsibility of the
 * widgets using those gestures to set the state of touch sequences accordingly
 * in order to enable cooperation of gestures around the #GdkEventSequences
 * triggering those.
 * 
 * Within a widget, gestures can be grouped through gtk_gesture_group(),
 * grouped gestures synchronize the state of sequences, so calling
 * gtk_gesture_set_sequence_state() on one will effectively propagate
 * the state throughout the group.
 * 
 * By default, all sequences start out in the #GTK_EVENT_SEQUENCE_NONE state,
 * sequences in this state trigger the gesture event handler, but event
 * propagation will continue unstopped by gestures.
 * 
 * If a sequence enters into the #GTK_EVENT_SEQUENCE_DENIED state, the gesture
 * group will effectively ignore the sequence, letting events go unstopped
 * through the gesture, but the "slot" will still remain occupied while
 * the touch is active.
 * 
 * If a sequence enters in the #GTK_EVENT_SEQUENCE_CLAIMED state, the gesture
 * group will grab all interaction on the sequence, by:
 * - Setting the same sequence to #GTK_EVENT_SEQUENCE_DENIED on every other gesture
 *   group within the widget, and every gesture on parent widgets in the propagation
 *   chain.
 * - calling #GtkGesture::cancel on every gesture in widgets underneath in the
 *   propagation chain.
 * - Stopping event propagation after the gesture group handles the event.
 * 
 * Note: if a sequence is set early to #GTK_EVENT_SEQUENCE_CLAIMED on
 * #GDK_TOUCH_BEGIN/#GDK_BUTTON_PRESS (so those events are captured before
 * reaching the event widget, this implies #GTK_PHASE_CAPTURE), one similar
 * event will emulated if the sequence changes to #GTK_EVENT_SEQUENCE_DENIED.
 * This way event coherence is preserved before event propagation is unstopped
 * again.
 * 
 * Sequence states can't be changed freely, see gtk_gesture_set_sequence_state()
 * to know about the possible lifetimes of a #GdkEventSequence.
 * 
 * ## Touchpad gestures
 * 
 * On the platforms that support it, #GtkGesture will handle transparently
 * touchpad gesture events. The only precautions users of #GtkGesture should do
 * to enable this support are:
 * - Enabling %GDK_TOUCHPAD_GESTURE_MASK on their #GdkWindows
 * - If the gesture has %GTK_PHASE_NONE, ensuring events of type
 *   %GDK_TOUCHPAD_SWIPE and %GDK_TOUCHPAD_PINCH are handled by the #GtkGesture
 *
 */
@interface OGTKGesture : OGTKEventController
{

}


/**
 * Methods
 */

- (GtkGesture*)GESTURE;

/**
 * If there are touch sequences being currently handled by @gesture,
 * this function returns %TRUE and fills in @rect with the bounding
 * box containing all active touches. Otherwise, %FALSE will be
 * returned.
 * 
 * Note: This function will yield unexpected results on touchpad
 * gestures. Since there is no correlation between physical and
 * pixel distances, these will look as if constrained in an
 * infinitely small area, @rect width and height will thus be 0
 * regardless of the number of touchpoints.
 *
 * @param rect bounding box containing all active touches.
 * @return %TRUE if there are active touches, %FALSE otherwise
 */
- (bool)boundingBox:(GdkRectangle*)rect;

/**
 * If there are touch sequences being currently handled by @gesture,
 * this function returns %TRUE and fills in @x and @y with the center
 * of the bounding box containing all active touches. Otherwise, %FALSE
 * will be returned.
 *
 * @param x X coordinate for the bounding box center
 * @param y Y coordinate for the bounding box center
 * @return %FALSE if no active touches are present, %TRUE otherwise
 */
- (bool)boundingBoxCenterWithX:(gdouble*)x y:(gdouble*)y;

/**
 * Returns the master #GdkDevice that is currently operating
 * on @gesture, or %NULL if the gesture is not being interacted.
 *
 * @return a #GdkDevice, or %NULL
 */
- (OGGdkDevice*)device;

/**
 * Returns all gestures in the group of @gesture
 *
 * @return The list
 *   of #GtkGestures, free with g_list_free()
 */
- (GList*)group;

/**
 * Returns the last event that was processed for @sequence.
 * 
 * Note that the returned pointer is only valid as long as the @sequence
 * is still interpreted by the @gesture. If in doubt, you should make
 * a copy of the event.
 *
 * @param sequence a #GdkEventSequence
 * @return The last event from @sequence
 */
- (const GdkEvent*)lastEvent:(GdkEventSequence*)sequence;

/**
 * Returns the #GdkEventSequence that was last updated on @gesture.
 *
 * @return The last updated sequence
 */
- (GdkEventSequence*)lastUpdatedSequence;

/**
 * If @sequence is currently being interpreted by @gesture, this
 * function returns %TRUE and fills in @x and @y with the last coordinates
 * stored for that event sequence. The coordinates are always relative to the
 * widget allocation.
 *
 * @param sequence a #GdkEventSequence, or %NULL for pointer events
 * @param x return location for X axis of the sequence coordinates
 * @param y return location for Y axis of the sequence coordinates
 * @return %TRUE if @sequence is currently interpreted
 */
- (bool)pointWithSequence:(GdkEventSequence*)sequence x:(gdouble*)x y:(gdouble*)y;

/**
 * Returns the @sequence state, as seen by @gesture.
 *
 * @param sequence a #GdkEventSequence
 * @return The sequence state in @gesture
 */
- (GtkEventSequenceState)sequenceState:(GdkEventSequence*)sequence;

/**
 * Returns the list of #GdkEventSequences currently being interpreted
 * by @gesture.
 *
 * @return A list
 *          of #GdkEventSequences, the list elements are owned by GTK+
 *          and must not be freed or modified, the list itself must be deleted
 *          through g_list_free()
 */
- (GList*)sequences;

/**
 * Returns the user-defined window that receives the events
 * handled by @gesture. See gtk_gesture_set_window() for more
 * information.
 *
 * @return the user defined window, or %NULL if none
 */
- (OGGdkWindow*)window;

/**
 * Adds @gesture to the same group than @group_gesture. Gestures
 * are by default isolated in their own groups.
 * 
 * When gestures are grouped, the state of #GdkEventSequences
 * is kept in sync for all of those, so calling gtk_gesture_set_sequence_state(),
 * on one will transfer the same value to the others.
 * 
 * Groups also perform an "implicit grabbing" of sequences, if a
 * #GdkEventSequence state is set to #GTK_EVENT_SEQUENCE_CLAIMED on one group,
 * every other gesture group attached to the same #GtkWidget will switch the
 * state for that sequence to #GTK_EVENT_SEQUENCE_DENIED.
 *
 * @param gesture a #GtkGesture
 */
- (void)group:(OGTKGesture*)gesture;

/**
 * Returns %TRUE if @gesture is currently handling events corresponding to
 * @sequence.
 *
 * @param sequence a #GdkEventSequence or %NULL
 * @return %TRUE if @gesture is handling @sequence, %FALSE otherwise
 */
- (bool)handlesSequence:(GdkEventSequence*)sequence;

/**
 * Returns %TRUE if the gesture is currently active.
 * A gesture is active meanwhile there are touch sequences
 * interacting with it.
 *
 * @return %TRUE if gesture is active
 */
- (bool)isActive;

/**
 * Returns %TRUE if both gestures pertain to the same group.
 *
 * @param other another #GtkGesture
 * @return whether the gestures are grouped
 */
- (bool)isGroupedWith:(OGTKGesture*)other;

/**
 * Returns %TRUE if the gesture is currently recognized.
 * A gesture is recognized if there are as many interacting
 * touch sequences as required by @gesture, and #GtkGesture::check
 * returned %TRUE for the sequences being currently interpreted.
 *
 * @return %TRUE if gesture is recognized
 */
- (bool)isRecognized;

/**
 * Sets the state of @sequence in @gesture. Sequences start
 * in state #GTK_EVENT_SEQUENCE_NONE, and whenever they change
 * state, they can never go back to that state. Likewise,
 * sequences in state #GTK_EVENT_SEQUENCE_DENIED cannot turn
 * back to a not denied state. With these rules, the lifetime
 * of an event sequence is constrained to the next four:
 * 
 * * None
 * * None → Denied
 * * None → Claimed
 * * None → Claimed → Denied
 * 
 * Note: Due to event handling ordering, it may be unsafe to
 * set the state on another gesture within a #GtkGesture::begin
 * signal handler, as the callback might be executed before
 * the other gesture knows about the sequence. A safe way to
 * perform this could be:
 * 
 * |[
 * static void
 * first_gesture_begin_cb (GtkGesture       *first_gesture,
 *                         GdkEventSequence *sequence,
 *                         gpointer          user_data)
 * {
 *   gtk_gesture_set_sequence_state (first_gesture, sequence, GTK_EVENT_SEQUENCE_CLAIMED);
 *   gtk_gesture_set_sequence_state (second_gesture, sequence, GTK_EVENT_SEQUENCE_DENIED);
 * }
 * 
 * static void
 * second_gesture_begin_cb (GtkGesture       *second_gesture,
 *                          GdkEventSequence *sequence,
 *                          gpointer          user_data)
 * {
 *   if (gtk_gesture_get_sequence_state (first_gesture, sequence) == GTK_EVENT_SEQUENCE_CLAIMED)
 *     gtk_gesture_set_sequence_state (second_gesture, sequence, GTK_EVENT_SEQUENCE_DENIED);
 * }
 * ]|
 * 
 * If both gestures are in the same group, just set the state on
 * the gesture emitting the event, the sequence will be already
 * be initialized to the group's global state when the second
 * gesture processes the event.
 *
 * @param sequence a #GdkEventSequence
 * @param state the sequence state
 * @return %TRUE if @sequence is handled by @gesture,
 *          and the state is changed successfully
 */
- (bool)setSequenceStateWithSequence:(GdkEventSequence*)sequence state:(GtkEventSequenceState)state;

/**
 * Sets the state of all sequences that @gesture is currently
 * interacting with. See gtk_gesture_set_sequence_state()
 * for more details on sequence states.
 *
 * @param state the sequence state
 * @return %TRUE if the state of at least one sequence
 *     was changed successfully
 */
- (bool)setState:(GtkEventSequenceState)state;

/**
 * Sets a specific window to receive events about, so @gesture
 * will effectively handle only events targeting @window, or
 * a child of it. @window must pertain to gtk_event_controller_get_widget().
 *
 * @param window a #GdkWindow, or %NULL
 */
- (void)setWindow:(OGGdkWindow*)window;

/**
 * Separates @gesture into an isolated group.
 *
 */
- (void)ungroup;

@end