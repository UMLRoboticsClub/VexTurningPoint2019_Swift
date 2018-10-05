#pragma once

#include <cstdlib>
#include <cstdint>

#define UPDC32(octet,crc) (crc_32_tab[((crc)^((uint8_t)octet)) & 0xff]^((crc) >> 8))

uint32_t crc32buf(char *buf, size_t len);
