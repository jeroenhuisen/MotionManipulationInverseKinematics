// -*- c++ -*-
// Generated by gmmproc 2.44.0 -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTMANAGER_H
#define _GTKMM_RECENTMANAGER_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2006 The gtkmm Development Team
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


#include <vector>

#include <gdkmm/screen.h>
#include <gdkmm/pixbuf.h>

#include <gtkmm/recentinfo.h>

#include <glibmm/object.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkRecentManager GtkRecentManager;
typedef struct _GtkRecentManagerClass GtkRecentManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class RecentManager_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Exception class for Gtk::RecentManager errors.
 */
class RecentManagerError : public Glib::Error
{
public:
  /**  @var Code NOT_FOUND
   * The URI specified does not exists in
   * the recently used resources list.
   * 
   *  @var Code INVALID_URI
   * The URI specified is not valid.
   * 
   *  @var Code INVALID_ENCODING
   * The supplied string is not
   * UTF-8 encoded.
   * 
   *  @var Code NOT_REGISTERED
   * No application has registered
   * the specified item.
   * 
   *  @var Code READ
   * Failure while reading the recently used
   * resources file.
   * 
   *  @var Code WRITE
   * Failure while writing the recently used
   * resources file.
   * 
   *  @var Code UNKNOWN
   * Unspecified error.
   * 
   *  @enum Code
   * 
   * %Error codes for Gtk::RecentManager operations
   * 
   * @newin{2,10}
   */
  enum Code
  {
    NOT_FOUND,
    INVALID_URI,
    INVALID_ENCODING,
    NOT_REGISTERED,
    READ,
    WRITE,
    UNKNOWN
  };

  RecentManagerError(Code error_code, const Glib::ustring& error_message);
  explicit RecentManagerError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::RecentManagerError::Code> : public Glib::Value_Enum<Gtk::RecentManagerError::Code>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** @defgroup RecentFiles RecentFiles
 */

/** RecentManager provides a facility for adding, removing and
 * looking up recently used files.  Each recently used file is
 * identified by its URI, and has meta-data associated to it, like
 * the names and command lines of the applications that have
 * registered it, the number of time each application has registered
 * the same file, the mime type of the file and whether the file
 * should be displayed only by the applications that have
 * registered it.
 *
 * The RecentManager acts like a database of all the recently
 * used files.  You can create new RecentManager objects, but
 * it is more efficient to use the standard recent manager for
 * the Gdk::Screen so that informations about the recently used
 * files is shared with other people using them. Normally, you
 * retrieve the recent manager for a particular screen using
 * get_for_screen() and it will contain information about current
 * recent manager for that screen.
 *
 * @newin{2,10}
 *
 * @ingroup RecentFiles
 */

class RecentManager : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef RecentManager CppObjectType;
  typedef RecentManager_Class CppClassType;
  typedef GtkRecentManager BaseObjectType;
  typedef GtkRecentManagerClass BaseClassType;

private:  friend class RecentManager_Class;
  static CppClassType recentmanager_class_;

private:
  // noncopyable
  RecentManager(const RecentManager&);
  RecentManager& operator=(const RecentManager&);

protected:
  explicit RecentManager(const Glib::ConstructParams& construct_params);
  explicit RecentManager(GtkRecentManager* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~RecentManager();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkRecentManager*       gobj()       { return reinterpret_cast<GtkRecentManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkRecentManager* gobj() const { return reinterpret_cast<GtkRecentManager*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkRecentManager* gobj_copy();

private:


protected:
  RecentManager();

public:
  
  static Glib::RefPtr<RecentManager> create();


  /** Gets a unique instance of Gtk::RecentManager, that you can share
   * in your application without caring about memory management.
   * 
   * @newin{2,10}
   * 
   * @return A unique Gtk::RecentManager. Do not ref or
   * unref it.
   */
  static Glib::RefPtr<RecentManager> get_default();

  /** Meta-data passed to add_item().  You should
   * use RecentManager::Data if you want to control the meta-data associated
   * to an entry of the recently used files list when you are adding
   * a new file to it.
   *
   * - display_name: the string to be used when displaying the file inside a RecentChooser
   * - description: a user readable description of the file
   * - mime_type: the mime type of the file
   * - app_name: the name of the application that is registering the file
   * - app_exec: the command line that should be used when launching the file
   * - groups: the list of group names to which the file belongs to
   * - is_private: whether the file should be displayed only by the applications that have registered it
  */
  class Data
  {
  public:
    Glib::ustring display_name;
    Glib::ustring description;

    Glib::ustring mime_type;

    Glib::ustring app_name;
    Glib::ustring app_exec;

    std::vector<Glib::ustring> groups;

    bool is_private;
  };

  
  /** Adds a new resource into the recently used resources list. This function
   * will try and guess some of the meta-data associated to a URI. If you
   * know some of meta-data about the document yourself, set the desired
   * fields of a RecentManager::Data structure and pass it to add_item().
   */
  bool add_item(const Glib::ustring& uri);

  /** Adds a new resource into the recently used resources list, taking
   * meta data from the given Data instead of guessing it from the URI.
   */
  bool add_item(const Glib::ustring& uri, const Data& recent_data);

  
  /** Removes a resource pointed by @a uri from the recently used resources
   * list handled by a recent manager.
   * 
   * @newin{2,10}
   * 
   * @param uri The URI of the item you wish to remove.
   * @return <tt>true</tt> if the item pointed by @a uri has been successfully
   * removed by the recently used resources list, and <tt>false</tt> otherwise.
   */
  bool remove_item(const Glib::ustring& uri);
  
  /** Searches for a URI inside the recently used resources list, and
   * returns a Gtk::RecentInfo-struct containing informations about the resource
   * like its MIME type, or its display name.
   * 
   * @newin{2,10}
   * 
   * @param uri A URI.
   * @return A Gtk::RecentInfo-struct containing information
   * about the resource pointed by @a uri, or <tt>0</tt> if the URI was
   * not registered in the recently used resources list. Free with
   * Gtk::RecentInfo::unref().
   */
  Glib::RefPtr<RecentInfo> lookup_item(const Glib::ustring& uri);
  
  /** Searches for a URI inside the recently used resources list, and
   * returns a Gtk::RecentInfo-struct containing informations about the resource
   * like its MIME type, or its display name.
   * 
   * @newin{2,10}
   * 
   * @param uri A URI.
   * @return A Gtk::RecentInfo-struct containing information
   * about the resource pointed by @a uri, or <tt>0</tt> if the URI was
   * not registered in the recently used resources list. Free with
   * Gtk::RecentInfo::unref().
   */
  Glib::RefPtr<const RecentInfo> lookup_item(const Glib::ustring& uri) const;
  
  /** Checks whether there is a recently used resource registered
   * with @a uri inside the recent manager.
   * 
   * @newin{2,10}
   * 
   * @param uri A URI.
   * @return <tt>true</tt> if the resource was found, <tt>false</tt> otherwise.
   */
  bool has_item(const Glib::ustring& uri) const;
  
  /** Changes the location of a recently used resource from @a uri to @a new_uri.
   * 
   * Please note that this function will not affect the resource pointed
   * by the URIs, but only the URI used in the recently used resources list.
   * 
   * @newin{2,10}
   * 
   * @param uri The URI of a recently used resource.
   * @param new_uri The new URI of the recently used resource, or
   * <tt>0</tt> to remove the item pointed by @a uri in the list.
   * @return <tt>true</tt> on success.
   */
  bool move_item(const Glib::ustring& uri, const Glib::ustring& new_uri);

 
  /** Gets the list of recently used resources.
   * 
   * @newin{2,10}
   * 
   * @return A list of
   * newly allocated Gtk::RecentInfo objects. Use
   * Gtk::RecentInfo::unref() on each item inside the list, and then
   * free the list itself using Glib::list_free().
   */
  std::vector<Glib::RefPtr<RecentInfo> > get_items() const;

  
  /** Purges every item from the recently used resources list.
   * 
   * @newin{2,10}
   * 
   * @return The number of items that have been removed from the
   * recently used resources list.
   */
  int purge_items();

  /// For instance, void on_changed();
  typedef sigc::slot<void> SlotChanged;

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Emitted when the current recently used resources manager changes
   * its contents, either by calling Gtk::RecentManager::add_item() or
   * by another application.
   * 
   * @newin{2,10}
   * 
   */

  Glib::SignalProxy0< void > signal_changed();


  /** The full path to the file to be used to store and read the list.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_filename() const;


  /** The size of the recently used resources list.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_size() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();


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
   * @relates Gtk::RecentManager
   */
  Glib::RefPtr<Gtk::RecentManager> wrap(GtkRecentManager* object, bool take_copy = false);
}


#endif /* _GTKMM_RECENTMANAGER_H */

