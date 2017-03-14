#include "cCsvLogger.h"

cCsvLogger::cCsvLogger(std::string filename) {
	m_filename = filename;
}

void cCsvLogger::log(std::vector<float> vals) {
	std::string line = "";
	for(int i = 0; i<vals.size(); i++) {
		line += (std::to_string(vals[i]) + ",");
	}
	line += "\n";
}
