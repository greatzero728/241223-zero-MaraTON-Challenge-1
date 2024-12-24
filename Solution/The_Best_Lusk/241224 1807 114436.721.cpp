/*
 * solution.cpp
 *
 * Example solution.
 * This is (almost) how blocks are actually compressed in TON.
 * Normally, blocks are stored using vm::std_boc_serialize with mode=31.
 * Compression algorithm takes a block, converts it to mode=2 (which has less extra information) and compresses it using lz4.
 */
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<utility>
#include<algorithm>

#include"td/utils/lz4.h"
#include"td/utils/base64.h"
#include"vm/boc.h"

using namespace std;
using namespace td;
using namespace vm;

const int NN = 2121212;

BufferSlice compress(Slice data) {
  Ref<Cell> root = std_boc_deserialize(data).move_as_ok();
  BufferSlice serialized = std_boc_serialize(root, 2).move_as_ok();
  return lz4_compress(serialized);
}

BufferSlice decompress(Slice data) {
  BufferSlice serialized = lz4_decompress(data, 2 << 20).move_as_ok();
  auto root = std_boc_deserialize(serialized).move_as_ok();
  return std_boc_serialize(root, 31).move_as_ok();
}

char s[NN];

int main() {
  scanf("%s", s);
  bool mode = s[0] == 'c';
  
  scanf("%s", s);

  BufferSlice data(base64_decode(string(s)).move_as_ok());

  if(mode) data = compress(data);
  else data = decompress(data);

  printf("%s", base64_encode(data).c_str());
}