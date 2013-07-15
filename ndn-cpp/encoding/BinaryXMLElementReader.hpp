/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_BINARYXMLELEMENTREADER_HPP
#define	NDN_BINARYXMLELEMENTREADER_HPP

#include "../c/encoding/BinaryXMLElementReader.h"

namespace ndn {

/**
 * An ElementListener extends an ndn_ElementListener struct to proved an abstract virtual onReceivedElement function which wraps
 * the onReceivedElement used by the ndn_ElementListener struct.  You must extend this class to override onReceivedElement.
 */
class ElementListener : private ndn_ElementListener {
public:
  ElementListener() 
  {
    ndn_ElementListener_init(this, staticOnReceivedElement);
  }
  
  /**
   * This is called when an entire binary XML element is received.  You must extend this class to override this method.
   * @param element pointer to the binary XML element.  This buffer is only valid during this call.  If you need the data
   * later, you must copy.
   * @param elementLength length of element
   */
  virtual void onReceivedElement(unsigned char *element, unsigned int elementLength) = 0;
  
private:
  /**
   * Call the virtual method onReceivedElement. This is used to initialize the base ndn_ElementListener struct.
   * @param self
   * @param element
   * @param elementLength
   */
  static void staticOnReceivedElement(struct ndn_ElementListener *self, unsigned char *element, unsigned int elementLength);
};

}

#endif
