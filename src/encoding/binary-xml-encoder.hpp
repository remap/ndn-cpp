/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (C) 2013-2014 Regents of the University of California.
 * @author: Jeff Thompson <jefft0@remap.ucla.edu>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version, with the additional exemption that
 * compiling, linking, and/or using OpenSSL is allowed.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * A copy of the GNU General Public License is in the file COPYING.
 */

#ifndef NDN_BINARYXMLENCODER_HPP
#define NDN_BINARYXMLENCODER_HPP

#include <vector>
#include <ndn-cpp/common.hpp>
#include "../util/dynamic-uint8-vector.hpp"
#include "../c/encoding/binary-xml-encoder.h"

namespace ndn {

/**
 * A BinaryXmlEncoder extends a C ndn_BinaryXmlEncoder struct and wraps related functions.
 */
class BinaryXmlEncoder : public ndn_BinaryXmlEncoder {
public:
  /**
   * Initialize the base ndn_BinaryXmlEncoder struct with the initialLength.  Use simpleRealloc.
   * @param initialLength The initial size of the output.  If omitted, use 16.
   */
  BinaryXmlEncoder(size_t initialLength = 16)
  : output_(16)
  {
    ndn_BinaryXmlEncoder_initialize(this, &output_);
  }

  /**
   * Resize the output vector to the correct encoding length and return.
   * @return The encoding as a shared_ptr.  Assume that the caller now owns the vector.
   */
  const ptr_lib::shared_ptr<std::vector<uint8_t> >&
  getOutput()
  {
    output_.get()->resize(offset);
    return output_.get();
  }

  DynamicUInt8Vector output_;
};

}

#endif
