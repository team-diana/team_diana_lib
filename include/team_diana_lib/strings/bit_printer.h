#ifndef TEAM_DIANA_LIB_STRINGS_BIT_PRINTER
#define TEAM_DIANA_LIB_STRINGS_BIT_PRINTER

#include <string>
#include <bitset>
#include <sstream>

namespace Td {

class BitPrinterBase {
protected:
  BitPrinterBase(const std::string& separator=" ");

protected:
  const std::string separator;
};

template <int chunkSize> class BitPrinter : private BitPrinterBase {
public:
  BitPrinter(const std::string& separator=" ") : BitPrinterBase(separator) {
  }
};

template <> class BitPrinter<4>  : private BitPrinterBase{

public:
  BitPrinter(const std::string& separator=" ") : BitPrinterBase(separator) {
  }

  // Ok for Big endian
  template <typename T> std::string toString(const T& v) {
    std::ostringstream s;
    const unsigned char* bytes = (const unsigned char*)&v;
    for(int i = sizeof(v)-1; i >= 0; i--) {
      const unsigned char b = bytes[i];
      s << std::bitset<4>( (b & 0xf0) >> 4);
      s << separator;
      s << std::bitset<4>( (b & 0x0f) );
      s << separator;
    }
    return s.str();
  }

};


template <> class BitPrinter<8>  : private BitPrinterBase{

public:
  BitPrinter(const std::string& separator=" ") : BitPrinterBase(separator) {
  }

  // Ok for Big endian
  template <typename T> std::string toString(const T& v) {
    std::ostringstream s;
    const unsigned char* bytes = (const unsigned char*)&v;
    for(int i=sizeof(v)-1; i >= 0; i--) {
      unsigned char b = bytes[i];
      s << std::bitset<8>(b);
      s << separator;
    }
    return s.str();
  }

};

}

#endif

