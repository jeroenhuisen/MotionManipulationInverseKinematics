// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_LOCKBUTTON_P_H
#define _GTKMM_LOCKBUTTON_P_H


#include <gtkmm/private/button_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class LockButton_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef LockButton CppObjectType;
  typedef GtkLockButton BaseObjectType;
  typedef GtkLockButtonClass BaseClassType;
  typedef Gtk::Button_Class CppClassParent;
  typedef GtkButtonClass BaseClassParent;

  friend class LockButton;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_LOCKBUTTON_P_H */

