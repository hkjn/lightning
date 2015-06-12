/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: lightning.proto */

#ifndef PROTOBUF_C_lightning_2eproto__INCLUDED
#define PROTOBUF_C_lightning_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1001001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Sha256Hash Sha256Hash;
typedef struct _Signature Signature;
typedef struct _BitcoinInput BitcoinInput;
typedef struct _BitcoinPubkey BitcoinPubkey;
typedef struct _Change Change;
typedef struct _Anchor Anchor;
typedef struct _OpenChannel OpenChannel;
typedef struct _OpenCommitSig OpenCommitSig;
typedef struct _OpenAnchorScriptsigs OpenAnchorScriptsigs;
typedef struct _LeakAnchorSigsAndPretendWeDidnt LeakAnchorSigsAndPretendWeDidnt;
typedef struct _OpenComplete OpenComplete;
typedef struct _Update Update;
typedef struct _UpdateAccept UpdateAccept;
typedef struct _UpdateSignature UpdateSignature;
typedef struct _UpdateComplete UpdateComplete;
typedef struct _NewAnchor NewAnchor;
typedef struct _NewAnchorAck NewAnchorAck;
typedef struct _NewAnchorCommitSig NewAnchorCommitSig;
typedef struct _NewAnchorAccept NewAnchorAccept;
typedef struct _NewAnchorComplete NewAnchorComplete;
typedef struct _CloseChannel CloseChannel;
typedef struct _CloseChannelComplete CloseChannelComplete;
typedef struct _Error Error;
typedef struct _Pkt Pkt;


/* --- enums --- */


/* --- messages --- */

/*
 * Protobufs don't have fixed-length fields, so these are a hack.
 */
struct  _Sha256Hash
{
  ProtobufCMessage base;
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};
#define SHA256_HASH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sha256_hash__descriptor) \
    , 0, 0, 0, 0 }


struct  _Signature
{
  ProtobufCMessage base;
  uint64_t r1;
  uint64_t r2;
  uint64_t r3;
  uint64_t r4;
  uint64_t s1;
  uint64_t s2;
  uint64_t s3;
  uint64_t s4;
};
#define SIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&signature__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0 }


/*
 * Identifies consumption of a bitcoin output.
 */
struct  _BitcoinInput
{
  ProtobufCMessage base;
  /*
   * This is the transaction ID.
   */
  Sha256Hash *txid;
  /*
   * This is the output number.
   */
  uint32_t output;
  /*
   * And the subscript we're signing.
   */
  ProtobufCBinaryData subscript;
  /*
   * The amount this input is worth.
   */
  uint64_t amount;
};
#define BITCOIN_INPUT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&bitcoin_input__descriptor) \
    , NULL, 0, {0,NULL}, 0 }


/*
 * Pubkey for commitment transaction input.
 */
struct  _BitcoinPubkey
{
  ProtobufCMessage base;
  /*
   * Either 65 or 33 bytes.
   */
  ProtobufCBinaryData key;
};
#define BITCOIN_PUBKEY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&bitcoin_pubkey__descriptor) \
    , {0,NULL} }


/*
 * Change, if we want any.
 */
struct  _Change
{
  ProtobufCMessage base;
  uint64_t amount;
  BitcoinPubkey *pubkey;
};
#define CHANGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&change__descriptor) \
    , 0, NULL }


/*
 * All about an anchor transaction.
 */
struct  _Anchor
{
  ProtobufCMessage base;
  /*
   * 0 or more unspent inputs we want to use for anchor.
   */
  size_t n_inputs;
  BitcoinInput **inputs;
  /*
   * Pubkey for anchor to pay to for commitment tx (p2sh)
   */
  BitcoinPubkey *pubkey;
  /*
   * Any change from anchor (in case we don't want to use them all)
   */
  Change *change;
  /*
   * How much transaction fee we'll pay in the anchor tx.
   */
  uint64_t fee;
  /*
   * How much we'll be putting into channel (== sum(inputs) - change - fee)
   */
  uint64_t total;
  /*
   * How many confirmations on anchor before we'll use channel.
   */
  uint32_t min_confirms;
};
#define ANCHOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&anchor__descriptor) \
    , 0,NULL, NULL, NULL, 0, 0, 0 }


typedef enum {
  OPEN_CHANNEL__LOCKTIME__NOT_SET = 0,
  OPEN_CHANNEL__LOCKTIME_LOCKTIME_SECONDS = 2,
  OPEN_CHANNEL__LOCKTIME_LOCKTIME_BLOCKS = 3,
} OpenChannel__LocktimeCase;

/*
 * Set channel params.
 */
struct  _OpenChannel
{
  ProtobufCMessage base;
  /*
   * Seed which sets order we create outputs for all transactions.
   */
  uint64_t seed;
  /*
   * Hash seed for revoking commitment transactions.
   */
  Sha256Hash *revocation_hash;
  /*
   * How to pay money to us from commit_tx.
   */
  BitcoinPubkey *final;
  /*
   * How much transaction fee we'll pay for commitment txs.
   */
  uint64_t commitment_fee;
  /*
   * The anchor transaction details.
   */
  Anchor *anchor;
  /*
   * Maximum transaction version we support.
   */
  uint32_t tx_version;
  OpenChannel__LocktimeCase locktime_case;
  union {
    uint32_t locktime_seconds;
    uint32_t locktime_blocks;
  };
};
#define OPEN_CHANNEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_channel__descriptor) \
    , 0, NULL, NULL, 0, NULL, 0, OPEN_CHANNEL__LOCKTIME__NOT_SET, {} }


/*
 * Supply signature for commitment tx
 */
struct  _OpenCommitSig
{
  ProtobufCMessage base;
  Signature *sig;
};
#define OPEN_COMMIT_SIG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_commit_sig__descriptor) \
    , NULL }


/*
 * Supply ScriptSig for each anchor tx inputs.
 */
struct  _OpenAnchorScriptsigs
{
  ProtobufCMessage base;
  size_t n_script;
  ProtobufCBinaryData *script;
};
#define OPEN_ANCHOR_SCRIPTSIGS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_anchor_scriptsigs__descriptor) \
    , 0,NULL }


/*
 * BROKEN AND INSECURE!!!
 * This should not exist; it's completely insecure!  But we need to sign
 * the commitment transaction before we sign the anchor transaction, which
 * doesn't work at all with current bitcoin (as we don't know the anchor
 * txid until it's signed by both sides, and then we'd have to worry about
 * malleability anyway).  So for testing, we send the scriptsigs for the
 * anchor transaction's inputs immediately.
 */
struct  _LeakAnchorSigsAndPretendWeDidnt
{
  ProtobufCMessage base;
  OpenAnchorScriptsigs *sigs;
};
#define LEAK_ANCHOR_SIGS_AND_PRETEND_WE_DIDNT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&leak_anchor_sigs_and_pretend_we_didnt__descriptor) \
    , NULL }


/*
 * Indicates we've seen transaction reach min-depth.
 */
struct  _OpenComplete
{
  ProtobufCMessage base;
  /*
   * Block it went into.
   */
  /*
   * FIXME: add a merkle proof plus block headers here?
   */
  Sha256Hash *blockid;
};
#define OPEN_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_complete__descriptor) \
    , NULL }


/*
 * Let's spend some money in the channel!
 */
struct  _Update
{
  ProtobufCMessage base;
  /*
   * Hash for which I will supply preimage to revoke this.
   */
  Sha256Hash *revocation_hash;
  /*
   * Change in current payment to-me (implies reverse to-you).
   */
  /*
   * FIXME: optional HTLC ops.
   */
  int64_t delta;
};
#define UPDATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update__descriptor) \
    , NULL, 0 }


/*
 * OK, I accept that update; here's your signature.
 */
struct  _UpdateAccept
{
  ProtobufCMessage base;
  /*
   * Signature for your new commitment tx.
   */
  Signature *sig;
  /*
   * Signature for old anchor (if any)
   */
  Signature *old_anchor_sig;
  /*
   * Hash for which I will supply preimage to revoke this new commit tx.
   */
  Sha256Hash *revocation_hash;
};
#define UPDATE_ACCEPT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_accept__descriptor) \
    , NULL, NULL, NULL }


/*
 * Thanks for accepting, here's my last bit.
 */
struct  _UpdateSignature
{
  ProtobufCMessage base;
  /*
   * Signature for your new commitment tx.
   */
  Signature *sig;
  /*
   * Hash preimage which revokes old commitment tx.
   */
  Sha256Hash *revocation_preimage;
};
#define UPDATE_SIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_signature__descriptor) \
    , NULL, NULL }


/*
 * Complete the update.
 */
struct  _UpdateComplete
{
  ProtobufCMessage base;
  /*
   * Hash preimage which revokes old commitment tx.
   */
  Sha256Hash *revocation_preimage;
};
#define UPDATE_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_complete__descriptor) \
    , NULL }


/*
 * Let's change the channel funding source.
 */
struct  _NewAnchor
{
  ProtobufCMessage base;
  /*
   * The new anchor: previous anchor 2x2 input assumed.
   */
  Anchor *anchor;
};
#define NEW_ANCHOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&new_anchor__descriptor) \
    , NULL }


/*
 * That seems OK to me, let's add these too (if any).
 */
struct  _NewAnchorAck
{
  ProtobufCMessage base;
  Anchor *anchor;
};
#define NEW_ANCHOR_ACK__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&new_anchor_ack__descriptor) \
    , NULL }


/*
 * Now we both send signatures for new commit sig.
 */
struct  _NewAnchorCommitSig
{
  ProtobufCMessage base;
  Signature *sig;
};
#define NEW_ANCHOR_COMMIT_SIG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&new_anchor_commit_sig__descriptor) \
    , NULL }


/*
 * Here are the script sigs for the new anchor's new inputs.
 */
struct  _NewAnchorAccept
{
  ProtobufCMessage base;
  size_t n_script;
  ProtobufCBinaryData *script;
};
#define NEW_ANCHOR_ACCEPT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&new_anchor_accept__descriptor) \
    , 0,NULL }


/*
 * Complete the transfer to new anchor (both ends need to send this,
 * once they're happy that it's reached their required depth).
 */
struct  _NewAnchorComplete
{
  ProtobufCMessage base;
  Sha256Hash *revocation_preimage;
};
#define NEW_ANCHOR_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&new_anchor_complete__descriptor) \
    , NULL }


/*
 * Begin cooperative close of channel.
 */
struct  _CloseChannel
{
  ProtobufCMessage base;
  /*
   * This is our signature a new transaction which spends the anchor
   * output to my open->final and your open->final,
   * as per the last commit tx.
   */
  Signature *sig;
};
#define CLOSE_CHANNEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&close_channel__descriptor) \
    , NULL }


/*
 * OK, here's my sig so you can broadcast it too.  We're done.
 */
struct  _CloseChannelComplete
{
  ProtobufCMessage base;
  /*
   * This is my signature for that same tx.
   */
  Signature *sig;
};
#define CLOSE_CHANNEL_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&close_channel_complete__descriptor) \
    , NULL }


/*
 * This means we're going to hang up; it's to help diagnose only! 
 */
struct  _Error
{
  ProtobufCMessage base;
  char *problem;
};
#define ERROR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&error__descriptor) \
    , NULL }


typedef enum {
  PKT__PKT__NOT_SET = 0,
  PKT__PKT_OPEN = 201,
  PKT__PKT_OMG_FAIL = 205,
  PKT__PKT_OPEN_COMMIT_SIG = 202,
  PKT__PKT_OPEN_ANCHOR_SCRIPTSIGS = 203,
  PKT__PKT_OPEN_COMPLETE = 204,
  PKT__PKT_UPDATE = 1,
  PKT__PKT_UPDATE_ACCEPT = 2,
  PKT__PKT_UPDATE_SIGNATURE = 3,
  PKT__PKT_UPDATE_COMPLETE = 4,
  PKT__PKT_NEW_ANCHOR = 301,
  PKT__PKT_NEW_ANCHOR_ACK = 302,
  PKT__PKT_NEW_ANCHOR_ACCEPT = 303,
  PKT__PKT_NEW_ANCHOR_COMPLETE = 304,
  PKT__PKT_CLOSE = 401,
  PKT__PKT_CLOSE_COMPLETE = 402,
  PKT__PKT_ERROR = 1000,
} Pkt__PktCase;

/*
 * This is the union which defines all of them
 */
struct  _Pkt
{
  ProtobufCMessage base;
  Pkt__PktCase pkt_case;
  union {
    /*
     * Opening
     */
    OpenChannel *open;
    LeakAnchorSigsAndPretendWeDidnt *omg_fail;
    OpenCommitSig *open_commit_sig;
    OpenAnchorScriptsigs *open_anchor_scriptsigs;
    OpenComplete *open_complete;
    /*
     * Updating (most common)
     */
    Update *update;
    UpdateAccept *update_accept;
    UpdateSignature *update_signature;
    UpdateComplete *update_complete;
    /*
     * Topping up
     */
    NewAnchor *new_anchor;
    NewAnchorAck *new_anchor_ack;
    NewAnchorAccept *new_anchor_accept;
    NewAnchorComplete *new_anchor_complete;
    /*
     * Closing
     */
    CloseChannel *close;
    CloseChannelComplete *close_complete;
    /*
     * Unexpected issue.
     */
    Error *error;
  };
};
#define PKT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&pkt__descriptor) \
    , PKT__PKT__NOT_SET, {} }


/* Sha256Hash methods */
void   sha256_hash__init
                     (Sha256Hash         *message);
size_t sha256_hash__get_packed_size
                     (const Sha256Hash   *message);
size_t sha256_hash__pack
                     (const Sha256Hash   *message,
                      uint8_t             *out);
size_t sha256_hash__pack_to_buffer
                     (const Sha256Hash   *message,
                      ProtobufCBuffer     *buffer);
Sha256Hash *
       sha256_hash__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   sha256_hash__free_unpacked
                     (Sha256Hash *message,
                      ProtobufCAllocator *allocator);
/* Signature methods */
void   signature__init
                     (Signature         *message);
size_t signature__get_packed_size
                     (const Signature   *message);
size_t signature__pack
                     (const Signature   *message,
                      uint8_t             *out);
size_t signature__pack_to_buffer
                     (const Signature   *message,
                      ProtobufCBuffer     *buffer);
Signature *
       signature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   signature__free_unpacked
                     (Signature *message,
                      ProtobufCAllocator *allocator);
/* BitcoinInput methods */
void   bitcoin_input__init
                     (BitcoinInput         *message);
size_t bitcoin_input__get_packed_size
                     (const BitcoinInput   *message);
size_t bitcoin_input__pack
                     (const BitcoinInput   *message,
                      uint8_t             *out);
size_t bitcoin_input__pack_to_buffer
                     (const BitcoinInput   *message,
                      ProtobufCBuffer     *buffer);
BitcoinInput *
       bitcoin_input__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   bitcoin_input__free_unpacked
                     (BitcoinInput *message,
                      ProtobufCAllocator *allocator);
/* BitcoinPubkey methods */
void   bitcoin_pubkey__init
                     (BitcoinPubkey         *message);
size_t bitcoin_pubkey__get_packed_size
                     (const BitcoinPubkey   *message);
size_t bitcoin_pubkey__pack
                     (const BitcoinPubkey   *message,
                      uint8_t             *out);
size_t bitcoin_pubkey__pack_to_buffer
                     (const BitcoinPubkey   *message,
                      ProtobufCBuffer     *buffer);
BitcoinPubkey *
       bitcoin_pubkey__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   bitcoin_pubkey__free_unpacked
                     (BitcoinPubkey *message,
                      ProtobufCAllocator *allocator);
/* Change methods */
void   change__init
                     (Change         *message);
size_t change__get_packed_size
                     (const Change   *message);
size_t change__pack
                     (const Change   *message,
                      uint8_t             *out);
size_t change__pack_to_buffer
                     (const Change   *message,
                      ProtobufCBuffer     *buffer);
Change *
       change__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   change__free_unpacked
                     (Change *message,
                      ProtobufCAllocator *allocator);
/* Anchor methods */
void   anchor__init
                     (Anchor         *message);
size_t anchor__get_packed_size
                     (const Anchor   *message);
size_t anchor__pack
                     (const Anchor   *message,
                      uint8_t             *out);
size_t anchor__pack_to_buffer
                     (const Anchor   *message,
                      ProtobufCBuffer     *buffer);
Anchor *
       anchor__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   anchor__free_unpacked
                     (Anchor *message,
                      ProtobufCAllocator *allocator);
/* OpenChannel methods */
void   open_channel__init
                     (OpenChannel         *message);
size_t open_channel__get_packed_size
                     (const OpenChannel   *message);
size_t open_channel__pack
                     (const OpenChannel   *message,
                      uint8_t             *out);
size_t open_channel__pack_to_buffer
                     (const OpenChannel   *message,
                      ProtobufCBuffer     *buffer);
OpenChannel *
       open_channel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_channel__free_unpacked
                     (OpenChannel *message,
                      ProtobufCAllocator *allocator);
/* OpenCommitSig methods */
void   open_commit_sig__init
                     (OpenCommitSig         *message);
size_t open_commit_sig__get_packed_size
                     (const OpenCommitSig   *message);
size_t open_commit_sig__pack
                     (const OpenCommitSig   *message,
                      uint8_t             *out);
size_t open_commit_sig__pack_to_buffer
                     (const OpenCommitSig   *message,
                      ProtobufCBuffer     *buffer);
OpenCommitSig *
       open_commit_sig__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_commit_sig__free_unpacked
                     (OpenCommitSig *message,
                      ProtobufCAllocator *allocator);
/* OpenAnchorScriptsigs methods */
void   open_anchor_scriptsigs__init
                     (OpenAnchorScriptsigs         *message);
size_t open_anchor_scriptsigs__get_packed_size
                     (const OpenAnchorScriptsigs   *message);
size_t open_anchor_scriptsigs__pack
                     (const OpenAnchorScriptsigs   *message,
                      uint8_t             *out);
size_t open_anchor_scriptsigs__pack_to_buffer
                     (const OpenAnchorScriptsigs   *message,
                      ProtobufCBuffer     *buffer);
OpenAnchorScriptsigs *
       open_anchor_scriptsigs__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_anchor_scriptsigs__free_unpacked
                     (OpenAnchorScriptsigs *message,
                      ProtobufCAllocator *allocator);
/* LeakAnchorSigsAndPretendWeDidnt methods */
void   leak_anchor_sigs_and_pretend_we_didnt__init
                     (LeakAnchorSigsAndPretendWeDidnt         *message);
size_t leak_anchor_sigs_and_pretend_we_didnt__get_packed_size
                     (const LeakAnchorSigsAndPretendWeDidnt   *message);
size_t leak_anchor_sigs_and_pretend_we_didnt__pack
                     (const LeakAnchorSigsAndPretendWeDidnt   *message,
                      uint8_t             *out);
size_t leak_anchor_sigs_and_pretend_we_didnt__pack_to_buffer
                     (const LeakAnchorSigsAndPretendWeDidnt   *message,
                      ProtobufCBuffer     *buffer);
LeakAnchorSigsAndPretendWeDidnt *
       leak_anchor_sigs_and_pretend_we_didnt__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   leak_anchor_sigs_and_pretend_we_didnt__free_unpacked
                     (LeakAnchorSigsAndPretendWeDidnt *message,
                      ProtobufCAllocator *allocator);
/* OpenComplete methods */
void   open_complete__init
                     (OpenComplete         *message);
size_t open_complete__get_packed_size
                     (const OpenComplete   *message);
size_t open_complete__pack
                     (const OpenComplete   *message,
                      uint8_t             *out);
size_t open_complete__pack_to_buffer
                     (const OpenComplete   *message,
                      ProtobufCBuffer     *buffer);
OpenComplete *
       open_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_complete__free_unpacked
                     (OpenComplete *message,
                      ProtobufCAllocator *allocator);
/* Update methods */
void   update__init
                     (Update         *message);
size_t update__get_packed_size
                     (const Update   *message);
size_t update__pack
                     (const Update   *message,
                      uint8_t             *out);
size_t update__pack_to_buffer
                     (const Update   *message,
                      ProtobufCBuffer     *buffer);
Update *
       update__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update__free_unpacked
                     (Update *message,
                      ProtobufCAllocator *allocator);
/* UpdateAccept methods */
void   update_accept__init
                     (UpdateAccept         *message);
size_t update_accept__get_packed_size
                     (const UpdateAccept   *message);
size_t update_accept__pack
                     (const UpdateAccept   *message,
                      uint8_t             *out);
size_t update_accept__pack_to_buffer
                     (const UpdateAccept   *message,
                      ProtobufCBuffer     *buffer);
UpdateAccept *
       update_accept__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_accept__free_unpacked
                     (UpdateAccept *message,
                      ProtobufCAllocator *allocator);
/* UpdateSignature methods */
void   update_signature__init
                     (UpdateSignature         *message);
size_t update_signature__get_packed_size
                     (const UpdateSignature   *message);
size_t update_signature__pack
                     (const UpdateSignature   *message,
                      uint8_t             *out);
size_t update_signature__pack_to_buffer
                     (const UpdateSignature   *message,
                      ProtobufCBuffer     *buffer);
UpdateSignature *
       update_signature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_signature__free_unpacked
                     (UpdateSignature *message,
                      ProtobufCAllocator *allocator);
/* UpdateComplete methods */
void   update_complete__init
                     (UpdateComplete         *message);
size_t update_complete__get_packed_size
                     (const UpdateComplete   *message);
size_t update_complete__pack
                     (const UpdateComplete   *message,
                      uint8_t             *out);
size_t update_complete__pack_to_buffer
                     (const UpdateComplete   *message,
                      ProtobufCBuffer     *buffer);
UpdateComplete *
       update_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_complete__free_unpacked
                     (UpdateComplete *message,
                      ProtobufCAllocator *allocator);
/* NewAnchor methods */
void   new_anchor__init
                     (NewAnchor         *message);
size_t new_anchor__get_packed_size
                     (const NewAnchor   *message);
size_t new_anchor__pack
                     (const NewAnchor   *message,
                      uint8_t             *out);
size_t new_anchor__pack_to_buffer
                     (const NewAnchor   *message,
                      ProtobufCBuffer     *buffer);
NewAnchor *
       new_anchor__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   new_anchor__free_unpacked
                     (NewAnchor *message,
                      ProtobufCAllocator *allocator);
/* NewAnchorAck methods */
void   new_anchor_ack__init
                     (NewAnchorAck         *message);
size_t new_anchor_ack__get_packed_size
                     (const NewAnchorAck   *message);
size_t new_anchor_ack__pack
                     (const NewAnchorAck   *message,
                      uint8_t             *out);
size_t new_anchor_ack__pack_to_buffer
                     (const NewAnchorAck   *message,
                      ProtobufCBuffer     *buffer);
NewAnchorAck *
       new_anchor_ack__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   new_anchor_ack__free_unpacked
                     (NewAnchorAck *message,
                      ProtobufCAllocator *allocator);
/* NewAnchorCommitSig methods */
void   new_anchor_commit_sig__init
                     (NewAnchorCommitSig         *message);
size_t new_anchor_commit_sig__get_packed_size
                     (const NewAnchorCommitSig   *message);
size_t new_anchor_commit_sig__pack
                     (const NewAnchorCommitSig   *message,
                      uint8_t             *out);
size_t new_anchor_commit_sig__pack_to_buffer
                     (const NewAnchorCommitSig   *message,
                      ProtobufCBuffer     *buffer);
NewAnchorCommitSig *
       new_anchor_commit_sig__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   new_anchor_commit_sig__free_unpacked
                     (NewAnchorCommitSig *message,
                      ProtobufCAllocator *allocator);
/* NewAnchorAccept methods */
void   new_anchor_accept__init
                     (NewAnchorAccept         *message);
size_t new_anchor_accept__get_packed_size
                     (const NewAnchorAccept   *message);
size_t new_anchor_accept__pack
                     (const NewAnchorAccept   *message,
                      uint8_t             *out);
size_t new_anchor_accept__pack_to_buffer
                     (const NewAnchorAccept   *message,
                      ProtobufCBuffer     *buffer);
NewAnchorAccept *
       new_anchor_accept__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   new_anchor_accept__free_unpacked
                     (NewAnchorAccept *message,
                      ProtobufCAllocator *allocator);
/* NewAnchorComplete methods */
void   new_anchor_complete__init
                     (NewAnchorComplete         *message);
size_t new_anchor_complete__get_packed_size
                     (const NewAnchorComplete   *message);
size_t new_anchor_complete__pack
                     (const NewAnchorComplete   *message,
                      uint8_t             *out);
size_t new_anchor_complete__pack_to_buffer
                     (const NewAnchorComplete   *message,
                      ProtobufCBuffer     *buffer);
NewAnchorComplete *
       new_anchor_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   new_anchor_complete__free_unpacked
                     (NewAnchorComplete *message,
                      ProtobufCAllocator *allocator);
/* CloseChannel methods */
void   close_channel__init
                     (CloseChannel         *message);
size_t close_channel__get_packed_size
                     (const CloseChannel   *message);
size_t close_channel__pack
                     (const CloseChannel   *message,
                      uint8_t             *out);
size_t close_channel__pack_to_buffer
                     (const CloseChannel   *message,
                      ProtobufCBuffer     *buffer);
CloseChannel *
       close_channel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   close_channel__free_unpacked
                     (CloseChannel *message,
                      ProtobufCAllocator *allocator);
/* CloseChannelComplete methods */
void   close_channel_complete__init
                     (CloseChannelComplete         *message);
size_t close_channel_complete__get_packed_size
                     (const CloseChannelComplete   *message);
size_t close_channel_complete__pack
                     (const CloseChannelComplete   *message,
                      uint8_t             *out);
size_t close_channel_complete__pack_to_buffer
                     (const CloseChannelComplete   *message,
                      ProtobufCBuffer     *buffer);
CloseChannelComplete *
       close_channel_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   close_channel_complete__free_unpacked
                     (CloseChannelComplete *message,
                      ProtobufCAllocator *allocator);
/* Error methods */
void   error__init
                     (Error         *message);
size_t error__get_packed_size
                     (const Error   *message);
size_t error__pack
                     (const Error   *message,
                      uint8_t             *out);
size_t error__pack_to_buffer
                     (const Error   *message,
                      ProtobufCBuffer     *buffer);
Error *
       error__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   error__free_unpacked
                     (Error *message,
                      ProtobufCAllocator *allocator);
/* Pkt methods */
void   pkt__init
                     (Pkt         *message);
size_t pkt__get_packed_size
                     (const Pkt   *message);
size_t pkt__pack
                     (const Pkt   *message,
                      uint8_t             *out);
size_t pkt__pack_to_buffer
                     (const Pkt   *message,
                      ProtobufCBuffer     *buffer);
Pkt *
       pkt__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   pkt__free_unpacked
                     (Pkt *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Sha256Hash_Closure)
                 (const Sha256Hash *message,
                  void *closure_data);
typedef void (*Signature_Closure)
                 (const Signature *message,
                  void *closure_data);
typedef void (*BitcoinInput_Closure)
                 (const BitcoinInput *message,
                  void *closure_data);
typedef void (*BitcoinPubkey_Closure)
                 (const BitcoinPubkey *message,
                  void *closure_data);
typedef void (*Change_Closure)
                 (const Change *message,
                  void *closure_data);
typedef void (*Anchor_Closure)
                 (const Anchor *message,
                  void *closure_data);
typedef void (*OpenChannel_Closure)
                 (const OpenChannel *message,
                  void *closure_data);
typedef void (*OpenCommitSig_Closure)
                 (const OpenCommitSig *message,
                  void *closure_data);
typedef void (*OpenAnchorScriptsigs_Closure)
                 (const OpenAnchorScriptsigs *message,
                  void *closure_data);
typedef void (*LeakAnchorSigsAndPretendWeDidnt_Closure)
                 (const LeakAnchorSigsAndPretendWeDidnt *message,
                  void *closure_data);
typedef void (*OpenComplete_Closure)
                 (const OpenComplete *message,
                  void *closure_data);
typedef void (*Update_Closure)
                 (const Update *message,
                  void *closure_data);
typedef void (*UpdateAccept_Closure)
                 (const UpdateAccept *message,
                  void *closure_data);
typedef void (*UpdateSignature_Closure)
                 (const UpdateSignature *message,
                  void *closure_data);
typedef void (*UpdateComplete_Closure)
                 (const UpdateComplete *message,
                  void *closure_data);
typedef void (*NewAnchor_Closure)
                 (const NewAnchor *message,
                  void *closure_data);
typedef void (*NewAnchorAck_Closure)
                 (const NewAnchorAck *message,
                  void *closure_data);
typedef void (*NewAnchorCommitSig_Closure)
                 (const NewAnchorCommitSig *message,
                  void *closure_data);
typedef void (*NewAnchorAccept_Closure)
                 (const NewAnchorAccept *message,
                  void *closure_data);
typedef void (*NewAnchorComplete_Closure)
                 (const NewAnchorComplete *message,
                  void *closure_data);
typedef void (*CloseChannel_Closure)
                 (const CloseChannel *message,
                  void *closure_data);
typedef void (*CloseChannelComplete_Closure)
                 (const CloseChannelComplete *message,
                  void *closure_data);
typedef void (*Error_Closure)
                 (const Error *message,
                  void *closure_data);
typedef void (*Pkt_Closure)
                 (const Pkt *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor sha256_hash__descriptor;
extern const ProtobufCMessageDescriptor signature__descriptor;
extern const ProtobufCMessageDescriptor bitcoin_input__descriptor;
extern const ProtobufCMessageDescriptor bitcoin_pubkey__descriptor;
extern const ProtobufCMessageDescriptor change__descriptor;
extern const ProtobufCMessageDescriptor anchor__descriptor;
extern const ProtobufCMessageDescriptor open_channel__descriptor;
extern const ProtobufCMessageDescriptor open_commit_sig__descriptor;
extern const ProtobufCMessageDescriptor open_anchor_scriptsigs__descriptor;
extern const ProtobufCMessageDescriptor leak_anchor_sigs_and_pretend_we_didnt__descriptor;
extern const ProtobufCMessageDescriptor open_complete__descriptor;
extern const ProtobufCMessageDescriptor update__descriptor;
extern const ProtobufCMessageDescriptor update_accept__descriptor;
extern const ProtobufCMessageDescriptor update_signature__descriptor;
extern const ProtobufCMessageDescriptor update_complete__descriptor;
extern const ProtobufCMessageDescriptor new_anchor__descriptor;
extern const ProtobufCMessageDescriptor new_anchor_ack__descriptor;
extern const ProtobufCMessageDescriptor new_anchor_commit_sig__descriptor;
extern const ProtobufCMessageDescriptor new_anchor_accept__descriptor;
extern const ProtobufCMessageDescriptor new_anchor_complete__descriptor;
extern const ProtobufCMessageDescriptor close_channel__descriptor;
extern const ProtobufCMessageDescriptor close_channel_complete__descriptor;
extern const ProtobufCMessageDescriptor error__descriptor;
extern const ProtobufCMessageDescriptor pkt__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_lightning_2eproto__INCLUDED */
