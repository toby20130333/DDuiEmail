#include <string>

#ifndef _BASE64_H_
#define _BASE64_H_

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);
std::string base64_encode_new(unsigned char const* szEncoding, unsigned int nSize);
#endif