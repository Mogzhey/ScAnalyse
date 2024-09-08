#include "file_loader.h"
#include "../../extern/fast-cpp-csv-parser/csv.h"

void read_csv(std::string filename) 
{
	io:CSVReader<3> in(filename)
}