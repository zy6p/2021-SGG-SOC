#include "geohash.h"

int main() {
  Point p{114.31, 30.52, {0, 1}};

  for (; p.geoHashBits.step <= 32; p.geoHashBits.step++) {
    p.geohash_encode();
    printf("P(%f, %f) encode(%d): %llu\n", p.lon, p.lat, p.geoHashBits.step,
           p.geoHashBits.bits);
  }
  for (; p.geoHashBits.step > 0; p.geoHashBits.step--) {
    p.geohash_decode();
    printf("P(%f, %f) decode(%d): %llu\n", p.lon, p.lat, p.geoHashBits.step,
           p.geoHashBits.bits);
  }
  return 0;
}
