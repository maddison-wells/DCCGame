#pragma once
#include <string>


struct MapData
{
  std::string tilesheet = "";
  std::string name = "";
  int tileWidth = 0;
  unsigned int tileHeight = 0;
  int dataLength = 0;
  int* data = nullptr;

};