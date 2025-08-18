#include "MapLoader.h"
#include <iostream>
#include <fstream>


//all from documentation

void MapLoader::Load(std::string filename)
{
  std::string line;
  std::ifstream file(filename);

  if (file.is_open()){
    while(std::getline(file, line))
    {
      std::cout << line << std::endl;
    }
    file.close();
  }
  else
{
  std::cout << "unable to open" << filename << std::endl;
}
}

// Example on how to save to our txt file
// void MapLoader::Save(std::string filename)
// {
//  std::ofstream file;
//  file.open(filename);
//  file << "extra or double" << std::endl;
//  file.close();

// }