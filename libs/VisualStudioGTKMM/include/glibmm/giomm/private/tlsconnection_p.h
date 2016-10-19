// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_TLSCONNECTION_P_H
#define _GIOMM_TLSCONNECTION_P_H


#include <giomm/private/iostream_p.h>

#include <glibmm/class.h>

namespace Gio
{

class TlsConnection_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TlsConnection CppObjectType;
  typedef GTlsConnection BaseObjectType;
  typedef GTlsConnectionClass BaseClassType;
  typedef IOStream_Class CppClassParent;
  typedef GIOStreamClass BaseClassParent;

  friend class TlsConnection;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static gboolean accept_certificate_callback(GTlsConnection* self, GTlsCertificate* p0, GTlsCertificateFlags p1);

  //Callbacks (virtual functions):
  static gboolean handshake_vfunc_callback(GTlsConnection* self, GCancellable* cancellable, GError** error);
  static void handshake_async_vfunc_callback(GTlsConnection* self, int io_priority, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data);
  static gboolean handshake_finish_vfunc_callback(GTlsConnection* self, GAsyncResult* result, GError** error);
};


} // namespace Gio


#endif /* _GIOMM_TLSCONNECTION_P_H */

