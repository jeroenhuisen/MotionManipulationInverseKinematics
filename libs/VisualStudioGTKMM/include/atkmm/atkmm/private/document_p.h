// -*- c++ -*-
// Generated by gmmproc 2.46.1 -- DO NOT MODIFY!
#ifndef _ATKMM_DOCUMENT_P_H
#define _ATKMM_DOCUMENT_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/private/interface_p.h>

namespace Atk
{

class Document_Class : public Glib::Interface_Class
{
public:
  typedef Document CppObjectType;
  typedef AtkDocument BaseObjectType;
  typedef AtkDocumentIface BaseClassType;
  typedef Glib::Interface_Class CppClassParent;

  friend class Document;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static const gchar* get_document_type_vfunc_callback(AtkDocument* self);
  static gpointer get_document_vfunc_callback(AtkDocument* self);
};


} // namespace Atk


#endif /* _ATKMM_DOCUMENT_P_H */

