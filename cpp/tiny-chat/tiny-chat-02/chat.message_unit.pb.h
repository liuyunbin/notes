// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.message_unit.proto

#ifndef PROTOBUF_INCLUDED_chat_2emessage_5funit_2eproto
#define PROTOBUF_INCLUDED_chat_2emessage_5funit_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_chat_2emessage_5funit_2eproto 

namespace protobuf_chat_2emessage_5funit_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_chat_2emessage_5funit_2eproto
namespace chat {
class message_unit;
class message_unitDefaultTypeInternal;
extern message_unitDefaultTypeInternal _message_unit_default_instance_;
}  // namespace chat
namespace google {
namespace protobuf {
template<> ::chat::message_unit* Arena::CreateMaybeMessage<::chat::message_unit>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace chat {

// ===================================================================

class message_unit : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chat.message_unit) */ {
 public:
  message_unit();
  virtual ~message_unit();

  message_unit(const message_unit& from);

  inline message_unit& operator=(const message_unit& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  message_unit(message_unit&& from) noexcept
    : message_unit() {
    *this = ::std::move(from);
  }

  inline message_unit& operator=(message_unit&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const message_unit& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const message_unit* internal_default_instance() {
    return reinterpret_cast<const message_unit*>(
               &_message_unit_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(message_unit* other);
  friend void swap(message_unit& a, message_unit& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline message_unit* New() const final {
    return CreateMaybeMessage<message_unit>(NULL);
  }

  message_unit* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<message_unit>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const message_unit& from);
  void MergeFrom(const message_unit& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(message_unit* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string user = 1;
  void clear_user();
  static const int kUserFieldNumber = 1;
  const ::std::string& user() const;
  void set_user(const ::std::string& value);
  #if LANG_CXX11
  void set_user(::std::string&& value);
  #endif
  void set_user(const char* value);
  void set_user(const char* value, size_t size);
  ::std::string* mutable_user();
  ::std::string* release_user();
  void set_allocated_user(::std::string* user);

  // string data = 2;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const char* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // @@protoc_insertion_point(class_scope:chat.message_unit)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr user_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_chat_2emessage_5funit_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// message_unit

// string user = 1;
inline void message_unit::clear_user() {
  user_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& message_unit::user() const {
  // @@protoc_insertion_point(field_get:chat.message_unit.user)
  return user_.GetNoArena();
}
inline void message_unit::set_user(const ::std::string& value) {
  
  user_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.message_unit.user)
}
#if LANG_CXX11
inline void message_unit::set_user(::std::string&& value) {
  
  user_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.message_unit.user)
}
#endif
inline void message_unit::set_user(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  user_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.message_unit.user)
}
inline void message_unit::set_user(const char* value, size_t size) {
  
  user_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.message_unit.user)
}
inline ::std::string* message_unit::mutable_user() {
  
  // @@protoc_insertion_point(field_mutable:chat.message_unit.user)
  return user_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* message_unit::release_user() {
  // @@protoc_insertion_point(field_release:chat.message_unit.user)
  
  return user_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void message_unit::set_allocated_user(::std::string* user) {
  if (user != NULL) {
    
  } else {
    
  }
  user_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), user);
  // @@protoc_insertion_point(field_set_allocated:chat.message_unit.user)
}

// string data = 2;
inline void message_unit::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& message_unit::data() const {
  // @@protoc_insertion_point(field_get:chat.message_unit.data)
  return data_.GetNoArena();
}
inline void message_unit::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chat.message_unit.data)
}
#if LANG_CXX11
inline void message_unit::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chat.message_unit.data)
}
#endif
inline void message_unit::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chat.message_unit.data)
}
inline void message_unit::set_data(const char* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chat.message_unit.data)
}
inline ::std::string* message_unit::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:chat.message_unit.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* message_unit::release_data() {
  // @@protoc_insertion_point(field_release:chat.message_unit.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void message_unit::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:chat.message_unit.data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace chat

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_chat_2emessage_5funit_2eproto
