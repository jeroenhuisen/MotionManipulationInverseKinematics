// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GOOCANVASMM_ITEM_P_H
#define _GOOCANVASMM_ITEM_P_H


#include <glibmm/private/interface_p.h>

#include <glibmm/private/interface_p.h>

namespace Goocanvas
{

class Item_Class : public Glib::Interface_Class
{
public:
  typedef Item CppObjectType;
  typedef GooCanvasItem BaseObjectType;
  typedef GooCanvasItemIface BaseClassType;
  typedef Glib::Interface_Class CppClassParent;

  friend class Item;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static gboolean enter_notify_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventCrossing* p1);
  static gboolean leave_notify_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventCrossing* p1);
  static gboolean motion_notify_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventMotion* p1);
  static gboolean button_press_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventButton* p1);
  static gboolean button_release_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventButton* p1);
  static gboolean focus_in_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventFocus* p1);
  static gboolean focus_out_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventFocus* p1);
  static gboolean key_press_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventKey* p1);
  static gboolean key_release_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventKey* p1);
  static gboolean grab_broken_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventGrabBroken* p1);
  static void child_notify_callback(GooCanvasItem* self, GParamSpec* p0);
  static void animation_finished_callback(GooCanvasItem* self, gboolean p0);
  static gboolean scroll_event_callback(GooCanvasItem* self, GooCanvasItem* p0, GdkEventScroll* p1);

  //Callbacks (virtual functions):
  static gint get_n_children_vfunc_callback(GooCanvasItem* self);
  static GooCanvasItem* get_child_vfunc_callback(GooCanvasItem* self, gint child_num);
  static void request_update_vfunc_callback(GooCanvasItem* self);
  static GooCanvas* get_canvas_vfunc_callback(GooCanvasItem* self);
  static void set_canvas_vfunc_callback(GooCanvasItem* self, GooCanvas* canvas);
  static void add_child_vfunc_callback(GooCanvasItem* self, GooCanvasItem* item, gint position);
  static void move_child_vfunc_callback(GooCanvasItem* self, gint old_position, gint new_position);
  static void remove_child_vfunc_callback(GooCanvasItem* self, gint position);
  static void get_child_property_vfunc_callback(GooCanvasItem* self, GooCanvasItem* child, guint property_id, GValue* value, GParamSpec* pspec);
  static void set_child_property_vfunc_callback(GooCanvasItem* self, GooCanvasItem* child, guint property_id, const GValue* value, GParamSpec* pspec);
  static gboolean get_transform_for_child_vfunc_callback(GooCanvasItem* self, GooCanvasItem* item, cairo_matrix_t* transform);
  static GooCanvasItem* get_parent_vfunc_callback(GooCanvasItem* self);
  static void set_parent_vfunc_callback(GooCanvasItem* self, GooCanvasItem* parent);
  static void get_bounds_vfunc_callback(GooCanvasItem* self, GooCanvasBounds* bounds);
  static GList* get_items_at_vfunc_callback(GooCanvasItem* self, gdouble x, gdouble y, cairo_t* cr, gboolean is_pointer_event, gboolean parent_is_visible, GList* found_items);
    static void update_vfunc_callback(GooCanvasItem* self, gboolean entire_tree, cairo_t* cr, GooCanvasBounds* bounds);
  static void paint_vfunc_callback(GooCanvasItem* self, cairo_t* cr, const GooCanvasBounds* bounds, gdouble scale);
  static gboolean get_requested_area_vfunc_callback(GooCanvasItem* self, cairo_t* cr, GooCanvasBounds* requested_area);
  static void allocate_area_vfunc_callback(GooCanvasItem* self, cairo_t* cr, const GooCanvasBounds* requested_area, const GooCanvasBounds* allocated_area, gdouble x_offset, gdouble y_offset);
  static gboolean get_transform_vfunc_callback(GooCanvasItem* self, cairo_matrix_t* transform);
  static void set_transform_vfunc_callback(GooCanvasItem* self, const cairo_matrix_t* matrix);
  static GooCanvasStyle* get_style_vfunc_callback(GooCanvasItem* self);
  static void set_style_vfunc_callback(GooCanvasItem* self, GooCanvasStyle* style);
  static gboolean is_visible_vfunc_callback(GooCanvasItem* self);
  static gdouble get_requested_height_vfunc_callback(GooCanvasItem* self, cairo_t* cr, gdouble width);
  static gboolean get_is_static_vfunc_callback(GooCanvasItem* self);
  static void set_is_static_vfunc_callback(GooCanvasItem* self, gboolean is_static);
  static GooCanvasItemModel* get_model_vfunc_callback(GooCanvasItem* self);
  static void set_model_vfunc_callback(GooCanvasItem* self, GooCanvasItemModel* model);
};


} // namespace Goocanvas


#endif /* _GOOCANVASMM_ITEM_P_H */

