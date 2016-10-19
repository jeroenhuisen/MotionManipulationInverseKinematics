// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _ATKMM_ACTION_H
#define _ATKMM_ACTION_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: action.hg,v 1.5 2004/03/12 20:35:53 murrayc Exp $ */

/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <glibmm/interface.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _AtkActionIface AtkActionIface; }
#endif


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _AtkAction AtkAction;
typedef struct _AtkActionClass AtkActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Atk
{ class Action_Class; } // namespace Atk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Atk
{

/** The ATK interface provided by UI components which the user can activate/interact with,
 * This should be implemented by instances of Atk::Object classes with which the user can interact directly, i.e. buttons,
 * checkboxes, scrollbars, e.g. components which are not "passive" providers of UI information.
 *
 * Exceptions: when the user interaction is already covered by another appropriate interface such as Atk::EditableText
 * (insert/delete test, etc.) or Atk::Value (set value) then these actions should not be exposed by Atk::Action as well.
 * 
 * Also note that the Atk::Action API is limited in that parameters may not be passed to the object being activated;
 * thus the action must be self-contained and specifiable via only a single "verb". Concrete examples include "press",
 * "release", "click" for buttons, "drag" (meaning initiate drag) and "drop" for drag sources and drop targets, etc.
 * 
 * Though most UI interactions on components should be invocable via keyboard as well as mouse, there will generally be
 * a close mapping between "mouse actions" that are possible on a component and the Atk::Actions. Where mouse and keyboard
 * actions are redundant in effect, Atk::Action should expose only one action rather than exposing redundant actions if
 * possible. By convention we have been using "mouse centric" terminology for Atk::Action names. 
 */

class Action : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Action CppObjectType;
  typedef Action_Class CppClassType;
  typedef AtkAction BaseObjectType;
  typedef AtkActionIface BaseClassType;

  // noncopyable
  Action(const Action&) = delete;
  Action& operator=(const Action&) = delete;

private:
  friend class Action_Class;
  static CppClassType action_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Action();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit Action(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit Action(AtkAction* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Action(Action&& src) noexcept;
  Action& operator=(Action&& src) noexcept;

  virtual ~Action() noexcept;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  AtkAction*       gobj()       { return reinterpret_cast<AtkAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const AtkAction* gobj() const { return reinterpret_cast<AtkAction*>(gobject_); }

private:


public:

  
  /** Perform the specified action on the object.
   * 
   * @param i The action index corresponding to the action to be performed.
   * @return <tt>true</tt> if success, <tt>false</tt> otherwise.
   */
  bool do_action(int i);
  
  /** Gets the number of accessible actions available on the object.
   * If there are more than one, the first one is considered the
   * "default" action of the object.
   * 
   * @return A the number of actions, or 0 if @a action does not
   * implement this interface.
   */
  int get_n_actions() const;
  
  /** Returns a description of the specified action of the object.
   * 
   * @param i The action index corresponding to the action to be performed.
   * @return A description string, or <tt>0</tt> if @a action does
   * not implement this interface.
   */
  Glib::ustring get_description(int i) const;
  
  /** Returns the name of the specified action of the object.
   * 
   * @param i The action index corresponding to the action to be performed.
   * @return A name string, or an empty string if @a action does not implement this interface.
   */
  Glib::ustring get_name(int i) const;
  
  /** Returns a keybinding associated with this action, if one exists.
   * 
   * @param i The action index corresponding to the action to be performed.
   * @return A string representing the keybinding, or an empty string
   * if there is no keybinding for this action.
   */
  Glib::ustring get_keybinding(int i);
  
  /** Sets a description of the specified action of the object.
   * 
   * @param i The action index corresponding to the action to be performed.
   * @param desc The description to be assigned to this action.
   * @return A <tt>bool</tt> representing if the description was successfully set;.
   */
  bool set_description(int i, const Glib::ustring& desc);
  
  /** Returns the localized name of the specified action of the object.
   * 
   * @param i The action index corresponding to the action to be performed.
   * @return A name string, or an empty string
   * if @a action does not implement this interface.
   */
  Glib::ustring get_localized_name(int i);

protected:
    virtual bool do_action_vfunc(int i);

    virtual int get_n_actions_vfunc() const;

    virtual const char* get_description_vfunc(int i) const;

    virtual const char* get_name_vfunc(int i) const;

    virtual const char* get_keybinding_vfunc(int i) const;


    virtual bool set_description_vfunc(int i, const Glib::ustring& desc);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Atk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Atk::Action
   */
  Glib::RefPtr<Atk::Action> wrap(AtkAction* object, bool take_copy = false);

} // namespace Glib


#endif /* _ATKMM_ACTION_H */

