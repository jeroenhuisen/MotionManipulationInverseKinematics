// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SPINBUTTON_P_H
#define _GTKMM_SPINBUTTON_P_H


#include <gtkmm/private/entry_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class SpinButton_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SpinButton CppObjectType;
  typedef GtkSpinButton BaseObjectType;
  typedef GtkSpinButtonClass BaseClassType;
  typedef Gtk::Entry_Class CppClassParent;
  typedef GtkEntryClass BaseClassParent;

  friend class SpinButton;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static gint input_callback(GtkSpinButton* self, double* p0);
  static gboolean output_callback(GtkSpinButton* self);
  static void wrapped_callback(GtkSpinButton* self);
  static void value_changed_callback(GtkSpinButton* self);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_SPINBUTTON_P_H */
