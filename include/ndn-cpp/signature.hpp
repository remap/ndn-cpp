/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (C) 2014 Regents of the University of California.
 * @author: Jeff Thompson <jefft0@remap.ucla.edu>
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_SIGNATURE_HPP
#define NDN_SIGNATURE_HPP

#include "common.hpp"

struct ndn_Signature;

namespace ndn {

/**
 * A Signature is an abstract base class providing methods to work with the signature information in a Data packet.
 * You must create an object of a subclass, for example Sha256WithRsaSignature.
 */
class Signature {
public:
  /**
   * Return a pointer to a new Signature which is a copy of this signature.
   * This is pure virtual, the subclass must implement it.
   */
  virtual ptr_lib::shared_ptr<Signature> 
  clone() const = 0;
  
  /**
   * The virtual destructor.
   */
  virtual 
  ~Signature();
  
    /**
   * Set the signatureStruct to point to the values in this signature object, without copying any memory.
   * WARNING: The resulting pointers in signatureStruct are invalid after a further use of this object which could reallocate memory.
   * This is pure virtual, the subclass must implement it.
   * @param signatureStruct a C ndn_Signature struct where the name components array is already allocated.
   */
  virtual void 
  get(struct ndn_Signature& signatureStruct) const = 0;

  /**
   * Clear this signature, and set the values by copying from the ndn_Signature struct.
   * This is pure virtual, the subclass must implement it.
   * @param signatureStruct a C ndn_Signature struct
   */
  virtual void 
  set(const struct ndn_Signature& signatureStruct) = 0;
  
  /**
   * Get the change count, which is incremented each time this object (or a child object) is changed.
   * @return The change count.
   */
  virtual uint64_t 
  getChangeCount() const = 0;
};

}

#endif