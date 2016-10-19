// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SEARCHBAR_H
#define _GTKMM_SEARCHBAR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2013 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtkmm/bin.h>
#include <gtkmm/entry.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSearchBar GtkSearchBar;
typedef struct _GtkSearchBarClass GtkSearchBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class SearchBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A toolbar to integrate a search entry with.
 *
 * Gtk::SearchBar is a container made to have a search entry (possibly
 * with additional connex widgets, such as drop-down menus, or buttons)
 * built-in. The search bar would appear when a search is started through
 * typing on the keyboard, or the application's search mode is toggled on.
 *
 * For keyboard presses to start a search, events will need to be
 * forwarded from the top-level window that contains the search bar.
 * See Gtk::SearchBar::handle_event() for example code. Common shortcuts
 * such as Ctrl+F should be handled as an application action, or through
 * the menu items.
 *
 * You will also need to tell the search bar about which entry you
 * are using as your search entry using Gtk::SearchBar::connect_entry().
 *
 * @ingroup Widgets
 * @newin{3,10}
 */

class SearchBar
  : public Bin
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SearchBar CppObjectType;
  typedef SearchBar_Class CppClassType;
  typedef GtkSearchBar BaseObjectType;
  typedef GtkSearchBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~SearchBar();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class SearchBar_Class;
  static CppClassType searchbar_class_;

  // noncopyable
  SearchBar(const SearchBar&);
  SearchBar& operator=(const SearchBar&);

protected:
  explicit SearchBar(const Glib::ConstructParams& construct_params);
  explicit SearchBar(GtkSearchBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkSearchBar*       gobj()       { return reinterpret_cast<GtkSearchBar*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkSearchBar* gobj() const { return reinterpret_cast<GtkSearchBar*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:

  /** Creates a Gtk::SearchBar.
   *
   * You will need to tell it about which widget is going to be your 
   * text entry using Gtk::SearchBar::set_entry().
   *
   */
  SearchBar();


  /** Connects the Gtk::Entry widget passed as the one to be used in
   * this search bar. The entry should be a descendant of the search bar.
   * This is only required if the entry isn’t the direct child of the
   * search bar (as in our main example).
   * 
   * @newin{3,10}
   * 
   * @param entry A Gtk::Entry.
   */
  void connect_entry(Gtk::Entry& entry);

  
  /** Returns whether the search mode is on or off.
   * 
   * @newin{3,10}
   * 
   * @return Whether search mode is toggled on.
   */
  bool get_search_mode() const;
  
  /** Switches the search mode on or off.
   * 
   * @newin{3,10}
   * 
   * @param search_mode The new state of the search mode.
   */
  void set_search_mode(bool search_mode = true);

  
  /** Returns whether the close button is shown.
   * 
   * @newin{3,10}
   * 
   * @return Whether the close button is shown.
   */
  bool get_show_close_button() const;
  
  /** Shows or hides the close button. Applications that
   * already have a “search” toggle button should not show a close
   * button in their search bar, as it duplicates the role of the
   * toggle button.
   * 
   * @newin{3,10}
   * 
   * @param visible Whether the close button will be shown or not.
   */
  void set_show_close_button(bool visible = true);

  //TODO: Use Gdk::EventKey, if we ever use Gdk::Event elsewhere in the API:
//We use GdkEventKey* rather than GdkEvent*. See GTK+ bug https://bugzilla.gnome.org/show_bug.cgi?id=709544
 

  /** This function should be called when the top-level
   * window which contains the search bar received a key event.
   * 
   * If the key event is handled by the search bar, the bar will
   * be shown, the entry populated with the entered text and Gdk::EVENT_STOP
   * will be returned. The caller should ensure that events are
   * not propagated further.
   * 
   * If no entry has been connected to the search bar, using
   * connect_entry(), this function will return
   * immediately with a warning.
   * 
   * ## Showing the search bar on key presses
   * 
   * 
   * [C example ellipted]
   * 
   * @newin{3,10}
   * 
   * @param event A Gdk::Event containing key press events.
   * @return Gdk::EVENT_STOP if the key press event resulted
   * in text being entered in the search entry (and revealing
   * the search bar if necessary), Gdk::EVENT_PROPAGATE otherwise.
   */
  bool handle_event(GdkEventKey* event);


  /** Whether the search mode is on and the search bar shown.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_search_mode_enabled() ;

/** Whether the search mode is on and the search bar shown.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_search_mode_enabled() const;

  /** Whether to show the close button in the toolbar.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_close_button() ;

/** Whether to show the close button in the toolbar.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_close_button() const;


  // Gtk::SearchBar has no signals nor vfuncs as of 3.10.


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
   * @relates Gtk::SearchBar
   */
  Gtk::SearchBar* wrap(GtkSearchBar* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_SEARCHBAR_H */

