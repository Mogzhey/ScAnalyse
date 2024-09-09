#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>
#include "file_loader.h"

std::vector<std::pair<std::string, std::vector<float>>> FileLoader::ReadCSV(std::string filename) 
{
    std::ifstream file(filename);
    std::vector<std::pair<std::string, std::vector<float>>> result;

    std::cout << ("loading file : " , filename) << std::endl;

    if (!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line, colname;
    float val;

    // read column headers
    if (file.good())
    {
        std::getline(file, line);
        std::stringstream ss(line);

        while (std::getline(ss, colname, ',')) {
            result.push_back({ colname, std::vector<float> {} });
        }
    }

    // read column data
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        int colIdx = 0;

        while (ss >> val) {
            result.at(colIdx).second.push_back(val);

            if (ss.peek() == ',') ss.ignore();
                colIdx++;
        }
    }

    // Close file
    file.close();

    return result;
}
