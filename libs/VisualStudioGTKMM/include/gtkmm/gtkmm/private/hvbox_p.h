// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_HVBOX_P_H
#define _GTKMM_HVBOX_P_H


#include <gtkmm/private/box_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class VBox_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef VBox CppObjectType;
  typedef GtkVBox BaseObjectType;
  typedef GtkVBoxClass BaseClassType;
  typedef Gtk::Box_Class CppClassParent;
  typedef GtkBoxClass BaseClassParent;

  friend class VBox;
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


#include <glibmm/class.h>

namespace Gtk
{

class HBox_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef HBox CppObjectType;
  typedef GtkHBox BaseObjectType;
  typedef GtkHBoxClass BaseClassType;
  typedef Gtk::Box_Class CppClassParent;
  typedef GtkBoxClass BaseClassParent;

  friend class HBox;
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


#endif /* _GTKMM_HVBOX_P_H */

