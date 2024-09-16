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

import sys;import struct;
import sysconfig as s
USE_SYSCONFIG = sys.version_info >= (3, 10)
if not USE_SYSCONFIG:
    from distutils import sysconfig as ds
print('.'.join(str(v) for v in sys.version_info));
print(sys.prefix);
if USE_SYSCONFIG:
    scheme = s.get_default_scheme()
    if scheme == 'posix_local':
        # Debian's default scheme installs to /usr/local/ but we want to find headers in /usr/
        scheme = 'posix_prefix'
    print(s.get_path('platinclude', scheme))
    print(s.get_path('platlib'))
    print(s.get_config_var('EXT_SUFFIX') or s.get_config_var('SO'))
else:
    print(ds.get_python_inc(plat_specific=True));
    print(ds.get_python_lib(plat_specific=True));
    print(ds.get_config_var('EXT_SUFFIX') or ds.get_config_var('SO'));
print(hasattr(sys, 'gettotalrefcount')+0);
print(struct.calcsize('@P'));
print(s.get_config_var('LDVERSION') or s.get_config_var('VERSION'));
print(s.get_config_var('LIBDIR') or '');
print(s.get_config_var('MULTIARCH') or '');
