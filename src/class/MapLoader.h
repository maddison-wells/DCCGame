#pragma once
#include <iostream>
#include "MapData.h"

class MapLoader{

  public: 
    void Load(std::string filename, MapData& data);
    // void Save(std::string filename);
};