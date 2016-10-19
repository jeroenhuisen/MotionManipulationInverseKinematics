// -*- c++ -*-
// Generated by gmmproc 2.46.0 -- DO NOT MODIFY!
#ifndef _GIOMM_TLSDATABASE_H
#define _GIOMM_TLSDATABASE_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2013 The giomm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm/object.h>
#include <giomm/asyncresult.h>
#include <giomm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsDatabase GTlsDatabase;
typedef struct _GTlsDatabaseClass GTlsDatabaseClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class TlsDatabase_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

// Forward declaration.
class ByteArray;

}

namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var TlsDatabaseVerifyFlags TLS_DATABASE_VERIFY_NONE
 * No verification flags.
 * 
 *  @enum TlsDatabaseVerifyFlags
 * 
 * Flags for g_tls_database_verify_chain().
 * 
 * @newin{2,30}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>%TlsDatabaseVerifyFlags operator|(TlsDatabaseVerifyFlags, TlsDatabaseVerifyFlags)</tt><br>
 * <tt>%TlsDatabaseVerifyFlags operator&(TlsDatabaseVerifyFlags, TlsDatabaseVerifyFlags)</tt><br>
 * <tt>%TlsDatabaseVerifyFlags operator^(TlsDatabaseVerifyFlags, TlsDatabaseVerifyFlags)</tt><br>
 * <tt>%TlsDatabaseVerifyFlags operator~(TlsDatabaseVerifyFlags)</tt><br>
 * <tt>%TlsDatabaseVerifyFlags& operator|=(TlsDatabaseVerifyFlags&, TlsDatabaseVerifyFlags)</tt><br>
 * <tt>%TlsDatabaseVerifyFlags& operator&=(TlsDatabaseVerifyFlags&, TlsDatabaseVerifyFlags)</tt><br>
 * <tt>%TlsDatabaseVerifyFlags& operator^=(TlsDatabaseVerifyFlags&, TlsDatabaseVerifyFlags)</tt><br>
 */
enum TlsDatabaseVerifyFlags
{
  TLS_DATABASE_VERIFY_NONE = 0x0
};

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags operator|(TlsDatabaseVerifyFlags lhs, TlsDatabaseVerifyFlags rhs)
  { return static_cast<TlsDatabaseVerifyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags operator&(TlsDatabaseVerifyFlags lhs, TlsDatabaseVerifyFlags rhs)
  { return static_cast<TlsDatabaseVerifyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags operator^(TlsDatabaseVerifyFlags lhs, TlsDatabaseVerifyFlags rhs)
  { return static_cast<TlsDatabaseVerifyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags operator~(TlsDatabaseVerifyFlags flags)
  { return static_cast<TlsDatabaseVerifyFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags& operator|=(TlsDatabaseVerifyFlags& lhs, TlsDatabaseVerifyFlags rhs)
  { return (lhs = static_cast<TlsDatabaseVerifyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags& operator&=(TlsDatabaseVerifyFlags& lhs, TlsDatabaseVerifyFlags rhs)
  { return (lhs = static_cast<TlsDatabaseVerifyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline TlsDatabaseVerifyFlags& operator^=(TlsDatabaseVerifyFlags& lhs, TlsDatabaseVerifyFlags rhs)
  { return (lhs = static_cast<TlsDatabaseVerifyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::TlsDatabaseVerifyFlags> : public Glib::Value_Flags<Gio::TlsDatabaseVerifyFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{

/** 
 *  @var TlsDatabaseLookupFlags TLS_DATABASE_LOOKUP_NONE
 * No lookup flags.
 * 
 *  @var TlsDatabaseLookupFlags TLS_DATABASE_LOOKUP_KEYPAIR
 * Restrict lookup to certificates that have
 * a private key.
 * 
 *  @enum TlsDatabaseLookupFlags
 * 
 * Flags for Glib::tls_database_lookup_certificate_handle(),
 * g_tls_database_lookup_certificate_issuer(),
 * and g_tls_database_lookup_certificates_issued_by().
 * 
 * @newin{2,30}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>%TlsDatabaseLookupFlags operator|(TlsDatabaseLookupFlags, TlsDatabaseLookupFlags)</tt><br>
 * <tt>%TlsDatabaseLookupFlags operator&(TlsDatabaseLookupFlags, TlsDatabaseLookupFlags)</tt><br>
 * <tt>%TlsDatabaseLookupFlags operator^(TlsDatabaseLookupFlags, TlsDatabaseLookupFlags)</tt><br>
 * <tt>%TlsDatabaseLookupFlags operator~(TlsDatabaseLookupFlags)</tt><br>
 * <tt>%TlsDatabaseLookupFlags& operator|=(TlsDatabaseLookupFlags&, TlsDatabaseLookupFlags)</tt><br>
 * <tt>%TlsDatabaseLookupFlags& operator&=(TlsDatabaseLookupFlags&, TlsDatabaseLookupFlags)</tt><br>
 * <tt>%TlsDatabaseLookupFlags& operator^=(TlsDatabaseLookupFlags&, TlsDatabaseLookupFlags)</tt><br>
 */
enum TlsDatabaseLookupFlags
{
  TLS_DATABASE_LOOKUP_NONE = 0x0,
  TLS_DATABASE_LOOKUP_KEYPAIR = 0x1
};

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags operator|(TlsDatabaseLookupFlags lhs, TlsDatabaseLookupFlags rhs)
  { return static_cast<TlsDatabaseLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags operator&(TlsDatabaseLookupFlags lhs, TlsDatabaseLookupFlags rhs)
  { return static_cast<TlsDatabaseLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags operator^(TlsDatabaseLookupFlags lhs, TlsDatabaseLookupFlags rhs)
  { return static_cast<TlsDatabaseLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags operator~(TlsDatabaseLookupFlags flags)
  { return static_cast<TlsDatabaseLookupFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags& operator|=(TlsDatabaseLookupFlags& lhs, TlsDatabaseLookupFlags rhs)
  { return (lhs = static_cast<TlsDatabaseLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags& operator&=(TlsDatabaseLookupFlags& lhs, TlsDatabaseLookupFlags rhs)
  { return (lhs = static_cast<TlsDatabaseLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline TlsDatabaseLookupFlags& operator^=(TlsDatabaseLookupFlags& lhs, TlsDatabaseLookupFlags rhs)
  { return (lhs = static_cast<TlsDatabaseLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::TlsDatabaseLookupFlags> : public Glib::Value_Flags<Gio::TlsDatabaseLookupFlags>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{


class Cancellable;
class SocketConnectable;
class TlsCertificate;
class TlsInteraction;

/** TlsDatabase - TLS database type.
 * TlsDatabase is used to lookup certificates and other information from a
 * certificate or key store. It is an abstract base class which TLS library
 * specific subtypes override.
 *
 * Most common client applications will not directly interact with TlsDatabase.
 * It is used internally by TlsConnection.
 * @newin{2,36}
 */

class TlsDatabase : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef TlsDatabase CppObjectType;
  typedef TlsDatabase_Class CppClassType;
  typedef GTlsDatabase BaseObjectType;
  typedef GTlsDatabaseClass BaseClassType;

  // noncopyable
  TlsDatabase(const TlsDatabase&) = delete;
  TlsDatabase& operator=(const TlsDatabase&) = delete;

private:  friend class TlsDatabase_Class;
  static CppClassType tlsdatabase_class_;

protected:
  explicit TlsDatabase(const Glib::ConstructParams& construct_params);
  explicit TlsDatabase(GTlsDatabase* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsDatabase(TlsDatabase&& src) noexcept;
  TlsDatabase& operator=(TlsDatabase&& src) noexcept;

  virtual ~TlsDatabase() noexcept;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GTlsDatabase*       gobj()       { return reinterpret_cast<GTlsDatabase*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GTlsDatabase* gobj() const { return reinterpret_cast<GTlsDatabase*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GTlsDatabase* gobj_copy();

private:


protected:
  TlsDatabase();

public:
  //TODO?: Have a constant for the C macro G_TLS_DATABASE_PURPOSE_AUTHENTICATE_SERVER (which is a string)?
  //TODO?: Have a constant for the C macro G_TLS_DATABASE_PURPOSE_AUTHENTICATE_CLIENT (which is a string)?

  
  /** Verify's a certificate chain after looking up and adding any missing
   * certificates to the chain.
   * 
   *  @a chain is a chain of TlsCertificate objects each pointing to the next
   * certificate in the chain by its %issuer property. The chain may initially
   * consist of one or more certificates. After the verification process is
   * complete, @a chain may be modified by adding missing certificates, or removing
   * extra certificates. If a certificate anchor was found, then it is added to
   * the @a chain.
   * 
   *  @a purpose describes the purpose (or usage) for which the certificate
   * is being used. Typically @a purpose will be set to TLS_DATABASE_PURPOSE_AUTHENTICATE_SERVER
   * which means that the certificate is being used to authenticate a server
   * (and we are acting as the client).
   * 
   * The @a identity is used to check for pinned certificates (trust exceptions)
   * in the database. These will override the normal verification process on a
   * host by host basis.
   * 
   * Currently there are no @a flags, and TLS_DATABASE_VERIFY_NONE should be
   * used.
   * 
   * This function can block, use g_tls_database_verify_chain_async() to perform
   * the verification operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param chain A TlsCertificate chain.
   * @param purpose The purpose that this certificate chain will be used for.
   * @param identity The expected peer identity.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Additional verify flags.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return The appropriate TlsCertificateFlags which represents the
   * result of verification.
   */
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain() convenience overload.
  TlsCertificateFlags verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;
  
  /** Asynchronously verify's a certificate chain after looking up and adding
   * any missing certificates to the chain. See g_tls_database_verify_chain()
   * for more information.
   * 
   * @newin{2,30}
   * 
   * @param chain A TlsCertificate chain.
   * @param purpose The purpose that this certificate chain will be used for.
   * @param identity The expected peer identity.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Additional verify flags.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const SlotAsyncReady& slot, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const SlotAsyncReady& slot, TlsDatabaseVerifyFlags flags =  TLS_DATABASE_VERIFY_NONE) const;
  
  /** Finish an asynchronous verify chain operation. See
   * g_tls_database_verify_chain() for more information. *
   * @newin{2,30}
   * 
   * @param result A AsyncResult.
   * @return The appropriate TlsCertificateFlags which represents the
   * result of verification.
   */
  TlsCertificateFlags verify_chain_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /** Lookup the issuer of @a certificate in the database.
   * 
   * The %issuer property
   * of @a certificate is not modified, and the two certificates are not hooked
   * into a chain.
   * 
   * This function can block, use g_tls_database_lookup_certificate_issuer_async() to perform
   * the lookup operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param certificate A TlsCertificate.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return A newly allocated issuer TlsCertificate,
   * or <tt>0</tt>. Use Glib::object_unref() to release the certificate.
   */
  Glib::RefPtr<TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_issuer() convenience overload.
  Glib::RefPtr<TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_issuer() convenience overload.
  Glib::RefPtr<TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_issuer() convenience overload.
  Glib::RefPtr<TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);
  
  /** Lookup the issuer of @a certificate in the database.
   * 
   * The %issuer property
   * of @a certificate is not modified, and the two certificates are not hooked
   * into a chain.
   * 
   * This function can block, use g_tls_database_lookup_certificate_issuer_async() to perform
   * the lookup operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param certificate A TlsCertificate.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return A newly allocated issuer TlsCertificate,
   * or <tt>0</tt>. Use Glib::object_unref() to release the certificate.
   */
  Glib::RefPtr<const TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificate_issuer() convenience overload.
  Glib::RefPtr<const TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificate_issuer() convenience overload.
  Glib::RefPtr<const TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificate_issuer() convenience overload.
  Glib::RefPtr<const TlsCertificate> lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  
  /** Asynchronously lookup the issuer of @a certificate in the database. See
   * g_tls_database_lookup_certificate_issuer() for more information.
   * 
   * @newin{2,30}
   * 
   * @param certificate A TlsCertificate.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_issuer_async() convenience overload.
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_issuer_async() convenience overload.
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_issuer_async() convenience overload.
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const SlotAsyncReady& slot, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);
  
  /** Finish an asynchronous lookup issuer operation. See
   * g_tls_database_lookup_certificate_issuer() for more information.
   * 
   * @newin{2,30}
   * 
   * @param result A AsyncResult.
   * @return A newly allocated issuer TlsCertificate,
   * or <tt>0</tt>. Use Glib::object_unref() to release the certificate.
   */
  Glib::RefPtr<TlsCertificate> lookup_certificate_issuer_finish(const Glib::RefPtr<AsyncResult>& result);

 
  /** Lookup certificates issued by this issuer in the database.
   * 
   * This function can block, use g_tls_database_lookup_certificates_issued_by_async() to perform
   * the lookup operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param issuer_raw_dn A ByteArray which holds the DER encoded issuer DN.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return A newly allocated list of TlsCertificate
   * objects. Use Glib::object_unref() on each certificate, and Glib::list_free() on the release the list.
   */
  std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificates_issued_by() convenience overload.
  std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificates_issued_by() convenience overload.
  std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificates_issued_by() convenience overload.
  std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

 
  /** Lookup certificates issued by this issuer in the database.
   * 
   * This function can block, use g_tls_database_lookup_certificates_issued_by_async() to perform
   * the lookup operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param issuer_raw_dn A ByteArray which holds the DER encoded issuer DN.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return A newly allocated list of TlsCertificate
   * objects. Use Glib::object_unref() on each certificate, and Glib::list_free() on the release the list.
   */
  std::vector< Glib::RefPtr<const TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificates_issued_by() convenience overload.
  std::vector< Glib::RefPtr<const TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificates_issued_by() convenience overload.
  std::vector< Glib::RefPtr<const TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificates_issued_by() convenience overload.
  std::vector< Glib::RefPtr<const TlsCertificate> > lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE) const;

  
  /** Asynchronously lookup certificates issued by this issuer in the database. See
   * g_tls_database_lookup_certificates_issued_by() for more information.
   * 
   * The database may choose to hold a reference to the issuer byte array for the duration
   * of of this asynchronous operation. The byte array should not be modified during
   * this time.
   * 
   * @newin{2,30}
   * 
   * @param issuer_raw_dn A ByteArray which holds the DER encoded issuer DN.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificates_issued_by_async() convenience overload.
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificates_issued_by_async() convenience overload.
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificates_issued_by_async() convenience overload.
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const SlotAsyncReady& slot, TlsDatabaseLookupFlags flags =  Gio::TLS_DATABASE_LOOKUP_NONE);
  
  /** Finish an asynchronous lookup of certificates. See
   * g_tls_database_lookup_certificates_issued_by() for more information.
   * 
   * @newin{2,30}
   * 
   * @param result A AsyncResult.
   * @return A newly allocated list of TlsCertificate
   * objects. Use Glib::object_unref() on each certificate, and Glib::list_free() on the release the list.
   */
  std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /** Create a handle string for the certificate. The database will only be able
   * to create a handle for certificates that originate from the database. In
   * cases where the database cannot create a handle for a certificate, <tt>0</tt>
   * will be returned.
   * 
   * This handle should be stable across various instances of the application,
   * and between applications. If a certificate is modified in the database,
   * then it is not guaranteed that this handle will continue to point to it.
   * 
   * @newin{2,30}
   * 
   * @param certificate Certificate for which to create a handle.
   * @return A newly allocated string containing the
   * handle.
   */
  Glib::ustring create_certificate_handle(const Glib::RefPtr<const TlsCertificate>& certificate) const;

  
  /** Lookup a certificate by its handle.
   * 
   * The handle should have been created by calling
   * g_tls_database_create_certificate_handle() on a TlsDatabase object of
   * the same TLS backend. The handle is designed to remain valid across
   * instantiations of the database.
   * 
   * If the handle is no longer valid, or does not point to a certificate in
   * this database, then <tt>0</tt> will be returned.
   * 
   * This function can block, use g_tls_database_lookup_certificate_for_handle_async() to perform
   * the lookup operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param handle A certificate handle.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return A newly allocated
   * TlsCertificate, or <tt>0</tt>. Use Glib::object_unref() to release the certificate.
   */
  Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_for_handle() convenience overload.
  Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_for_handle() convenience overload.
  Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_for_handle() convenience overload.
  Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);
  
  /** Lookup a certificate by its handle.
   * 
   * The handle should have been created by calling
   * g_tls_database_create_certificate_handle() on a TlsDatabase object of
   * the same TLS backend. The handle is designed to remain valid across
   * instantiations of the database.
   * 
   * If the handle is no longer valid, or does not point to a certificate in
   * this database, then <tt>0</tt> will be returned.
   * 
   * This function can block, use g_tls_database_lookup_certificate_for_handle_async() to perform
   * the lookup operation asynchronously.
   * 
   * @newin{2,30}
   * 
   * @param handle A certificate handle.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @return A newly allocated
   * TlsCertificate, or <tt>0</tt>. Use Glib::object_unref() to release the certificate.
   */
  Glib::RefPtr<const TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificate_for_handle() convenience overload.
  Glib::RefPtr<const TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificate_for_handle() convenience overload.
  Glib::RefPtr<const TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  /// A lookup_certificate_for_handle() convenience overload.
  Glib::RefPtr<const TlsCertificate> lookup_certificate_for_handle(const Glib::ustring& handle, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE) const;

  
  /** Asynchronously lookup a certificate by its handle in the database. See
   * g_tls_database_lookup_certificate_for_handle() for more information.
   * 
   * @newin{2,30}
   * 
   * @param handle A certificate handle.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup.
   * @param cancellable A Cancellable, or <tt>0</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_for_handle_async() convenience overload.
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_for_handle_async() convenience overload.
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);

  /// A lookup_certificate_for_handle_async() convenience overload.
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const SlotAsyncReady& slot, TlsDatabaseLookupFlags flags =  TLS_DATABASE_LOOKUP_NONE);
  
  /** Finish an asynchronous lookup of a certificate by its handle. See
   * Glib::tls_database_lookup_certificate_handle() for more information.
   * 
   * If the handle is no longer valid, or does not point to a certificate in
   * this database, then <tt>0</tt> will be returned.
   * 
   * @newin{2,30}
   * 
   * @param result A AsyncResult.
   * @return A newly allocated TlsCertificate object.
   * Use Glib::object_unref() to release the certificate.
   */
  Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle_finish(const Glib::RefPtr<AsyncResult>& result);

 
  /// @throws Glib::Error.
  virtual TlsCertificateFlags verify_chain_vfunc(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags) const;

    virtual void verify_chain_async_vfunc(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseVerifyFlags flags) const;


  /// @throws Glib::Error.
  virtual TlsCertificateFlags verify_chain_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


    virtual Glib::ustring create_certificate_handle_vfunc(const Glib::RefPtr<const TlsCertificate>& certificate) const;


  /// @throws Glib::Error.
  virtual Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle_vfunc(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags);

    virtual void lookup_certificate_for_handle_async_vfunc(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags);

  /// @throws Glib::Error.
  virtual Glib::RefPtr<TlsCertificate> lookup_certificate_for_handle_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


  /// @throws Glib::Error.
  virtual Glib::RefPtr<TlsCertificate> lookup_certificate_issuer_vfunc(const Glib::RefPtr<TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags);

    virtual void lookup_certificate_issuer_async_vfunc(const Glib::RefPtr<TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags);

  /// @throws Glib::Error.
  virtual Glib::RefPtr<TlsCertificate> lookup_certificate_issuer_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


  /// @throws Glib::Error.
  virtual std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by_vfunc(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags);

    virtual void lookup_certificates_issued_by_async_vfunc(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, TlsDatabaseLookupFlags flags);

  /// @throws Glib::Error.
  virtual std::vector< Glib::RefPtr<TlsCertificate> > lookup_certificates_issued_by_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::TlsDatabase
   */
  Glib::RefPtr<Gio::TlsDatabase> wrap(GTlsDatabase* object, bool take_copy = false);
}


#endif /* _GIOMM_TLSDATABASE_H */

