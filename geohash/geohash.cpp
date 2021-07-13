//
// Created by km on 7/13/21.
//

#include "geohash.h"

void Point::geohash_encode() noexcept {
  double lon_max = c_lon_max;
  double lon_min = c_lon_min;
  double lat_max = c_lat_max;
  double lat_min = c_lat_min;
  uint8_t lon_bit;
  uint8_t lat_bit;
  // 循环进行二分查找
  for (int i = 0; i < this->geoHashBits.step; ++i) {
    if (lat_max - this->lat >= this->lat - lat_min) {
      lat_bit = 0;
      lat_max = (lat_max + lat_min) / 2;
    } else {
      lat_bit = 1;
      lat_min = (lat_max + lat_min) / 2;
    }
    if (lon_max - this->lon >= this->lon - lon_min) {
      lon_bit = 0;
      lon_max = (lon_max + lon_min) / 2;
    } else {
      lon_bit = 1;
      lon_min = (lon_max + lon_min) / 2;
    }
    // 位操作
    this->geoHashBits.bits <<= 1;
    this->geoHashBits.bits += lon_bit;
    this->geoHashBits.bits <<= 1;
    this->geoHashBits.bits += lat_bit;
  }
}

void Point::geohash_decode() noexcept {
  double lat_min = c_lat_min;
  double lat_max = c_lat_max;
  double lon_min = c_lon_min;
  double lon_max = c_lon_max;
  uint8_t lon_bit;
  uint8_t lat_bit;
  for (int i = 0; i < this->geoHashBits.step; ++i) {
    lon_bit =
        get_bit(this->geoHashBits.bits, (this->geoHashBits.step - i) * 2 - 1);
    lat_bit =
        get_bit(this->geoHashBits.bits, (this->geoHashBits.step - i) * 2 - 2);
    if (lat_bit == 0) {
      lat_max = (lat_max + lat_min) / 2;
    } else {
      lat_min = (lat_max + lat_min) / 2;
    }
    if (lon_bit == 0) {
      lon_max = (lon_max + lon_min) / 2;
    } else {
      lon_min = (lon_max + lon_min) / 2;
    }
  }
  this->lon = lon_min;
  this->lat = lat_min;
}