#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>   // needed for std::istringstream
#include "MapData.h"

void MapLoader::Load(std::string filename, MapData& data)
{

    std::string line;
    std::ifstream file(filename);

    bool isMapValid = false;

    if (file.is_open()) {
        while (std::getline(file, line)) {

            if (!isMapValid) {
                if (line == "[Map]") {
                    isMapValid = true;
                    continue;
                } else {
                    std::cout << "Map not valid" << std::endl;
                    break;
                }
            }

            if (isMapValid) {
                int count = line.find('=');
                std::string variable = line.substr(0, count);
                std::string value = line.substr(count + 1);

                std::cout << variable << std::endl;
                std::cout << value << std::endl;

                if (variable == "tilesheet") {
                    data.tilesheet = value;
                }
                else if (variable == "name") {
                    data.name = value;
                }
                else if (variable == "tileWidth") {
                    data.tileWidth = std::stoi(value);
                }
                else if (variable == "tileHeight") {
                    data.tileHeight = std::stoi(value);
                }
                else if (variable == "dataLength") {
                    data.dataLength = std::stoi(value);
                }
                else if (variable == "data") {
                    std::istringstream iss(value);
                    std::vector<int> parsed;
                    int num;
                    while (iss >> num) {
                        parsed.push_back(num);
                    }
                    data.dataLength = parsed.size();
                    data.data = new int[data.dataLength];
                    std::copy(parsed.begin(), parsed.end(), data.data);
                }
            }
        }

        file.close();
    }
    else {
        std::cout << "unable to open " << filename << std::endl;
    }
}  