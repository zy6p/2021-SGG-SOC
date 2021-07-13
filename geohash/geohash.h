//
// Created by km on 7/13/21.
//

#ifndef GEOHASH_GEOHASH_H
#define GEOHASH_GEOHASH_H

#include <cstdint>
#include <string>
#include <utility>

/**
 * Hashing works like this:
 * Divide the world into 4 buckets.  Label each one as such:
 *  -----------------
 *  |       |       |
 *  |       |       |
 *  | 0,1   | 1,1   |
 *  -----------------
 *  |       |       |
 *  |       |       |
 *  | 0,0   | 1,0   |
 *  -----------------
 */

const double c_lon_max = 180.0;
const double c_lon_min = -180.0;
const double c_lat_max = 90.0;
const double c_lat_min = -90.0;

/**
 * GeoHash 精度和 hash 编码
 */
class GeoHashBits {
public:
  // 编码
  uint64_t bits = 0;
  // 精度
  uint8_t step = 0;
  // base32 编码
  std::string str;
};

class Point {
public:
  // 经度
  double lon = 0;
  // 纬度
  double lat = 0;
  GeoHashBits geoHashBits{0, 0, ""};

  // GeoHash 编码到二进制
  void geohash_encode() noexcept;

  // GeoHash 解码到左下角
  void geohash_decode() noexcept;
};

static inline uint8_t get_bit(uint64_t bits, uint8_t pos) {
  return (bits >> pos) & 0x01;
}

#endif // GEOHASH_GEOHASH_H