// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_FLOWBOXCHILD_P_H
#define _GTKMM_FLOWBOXCHILD_P_H


#include <gtkmm/private/bin_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class FlowBoxChild_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FlowBoxChild CppObjectType;
  typedef GtkFlowBoxChild BaseObjectType;
  typedef GtkFlowBoxChildClass BaseClassType;
  typedef Gtk::Bin_Class CppClassParent;
  typedef GtkBinClass BaseClassParent;

  friend class FlowBoxChild;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void activate_callback(GtkFlowBoxChild* self);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_FLOWBOXCHILD_P_H */

