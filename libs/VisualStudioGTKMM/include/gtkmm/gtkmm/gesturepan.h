// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_GESTUREPAN_H
#define _GTKMM_GESTUREPAN_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkmm/gesturedrag.h>
#include <gtkmm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkGesturePan GtkGesturePan;
typedef struct _GtkGesturePanClass GtkGesturePanClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GesturePan_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** 
 *  @var PanDirection PAN_DIRECTION_LEFT
 * Panned towards the left.
 * 
 *  @var PanDirection PAN_DIRECTION_RIGHT
 * Panned towards the right.
 * 
 *  @var PanDirection PAN_DIRECTION_UP
 * Panned upwards.
 * 
 *  @var PanDirection PAN_DIRECTION_DOWN
 * Panned downwards.
 * 
 *  @enum PanDirection
 * 
 * Describes the panning direction of a Gtk::GesturePan
 * 
 * @newin{3,14}
 *
 * @ingroup gtkmmEnums
 */
enum PanDirection
{
  PAN_DIRECTION_LEFT,
  PAN_DIRECTION_RIGHT,
  PAN_DIRECTION_UP,
  PAN_DIRECTION_DOWN
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PanDirection> : public Glib::Value_Enum<Gtk::PanDirection>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** Pan gesture.
 *
 * This is a Gesture implementation able to recognize
 * pan gestures. Those are drags that are locked to happen along one
 * axis. The axis that a GesturePan handles is defined at
 * construct time, and can be changed through set_orientation().
 *
 * When the gesture starts to be recognized, GesturePan will
 * attempt to determine as early as possible whether the sequence
 * is moving in the expected direction, and denying the sequence if
 * this does not happen.
 *
 * Once a panning gesture along the expected axis is recognized,
 * signal_pan() will be emitted as input events
 * are received, containing the offset in the given axis.
 *
 * @newin{3,14}
 *
 * @ingroup Gestures
 */

class GesturePan : public GestureDrag
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef GesturePan CppObjectType;
  typedef GesturePan_Class CppClassType;
  typedef GtkGesturePan BaseObjectType;
  typedef GtkGesturePanClass BaseClassType;

private:  friend class GesturePan_Class;
  static CppClassType gesturepan_class_;

private:
  // noncopyable
  GesturePan(const GesturePan&);
  GesturePan& operator=(const GesturePan&);

protected:
  explicit GesturePan(const Glib::ConstructParams& construct_params);
  explicit GesturePan(GtkGesturePan* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~GesturePan();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkGesturePan*       gobj()       { return reinterpret_cast<GtkGesturePan*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkGesturePan* gobj() const { return reinterpret_cast<GtkGesturePan*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkGesturePan* gobj_copy();

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because this constructor shall only be used by derived classes.
   */
  GesturePan();

  /** Constructs a Gesture that recognizes pan gestures.
   */
    explicit GesturePan(Widget& widget, Orientation orientation);


public:
  /** Creates a Gesture that recognizes pan gestures.
   *
   * @newin{3,14}
   *
   * @param widget Widget the gesture relates to.
   * @param orientation Expected orientation.
   * @return A RefPtr to a new GesturePan.
   */
  
  static Glib::RefPtr<GesturePan> create(Widget& widget, Orientation orientation);


  /** Returns the orientation of the pan gestures that this @a gesture expects.
   * 
   * @newin{3,14}
   * 
   * @return The expected orientation for pan gestures.
   */
  Orientation get_orientation() const;
  
  /** Sets the orientation to be expected on pan gestures.
   * 
   * @newin{3,14}
   * 
   * @param orientation Expected orientation.
   */
  void set_orientation(Orientation orientation);

  // no_default_handler because GtkGesturePanClass is private.
  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%pan(PanDirection direction, double offset)</tt>
   *
   * This signal is emitted once a panning gesture along the
   * expected axis is detected.
   * 
   * @newin{3,14}
   * 
   * @param direction Current direction of the pan gesture.
   * @param offset Offset along the gesture orientation.
   */

  Glib::SignalProxy2< void,PanDirection,double > signal_pan();


  /** Allowed orientations.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Orientation > property_orientation() ;

/** Allowed orientations.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Orientation > property_orientation() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::GesturePan
   */
  Glib::RefPtr<Gtk::GesturePan> wrap(GtkGesturePan* object, bool take_copy = false);
}


#endif /* _GTKMM_GESTUREPAN_H */

