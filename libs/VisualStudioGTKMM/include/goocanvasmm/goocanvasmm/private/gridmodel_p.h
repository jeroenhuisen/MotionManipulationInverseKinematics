// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GOOCANVASMM_GRIDMODEL_P_H
#define _GOOCANVASMM_GRIDMODEL_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Goocanvas
{

class GridModel_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef GridModel CppObjectType;
  typedef GooCanvasGridModel BaseObjectType;
  typedef GooCanvasGridModelClass BaseClassType;
  typedef Goocanvas::ItemModelSimple_Class CppClassParent;
  typedef GooCanvasItemModelSimpleClass BaseClassParent;

  friend class GridModel;
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


} // namespace Goocanvas

#include <goocanvasmm/private/itemmodelsimple_p.h>


#endif /* _GOOCANVASMM_GRIDMODEL_P_H */

