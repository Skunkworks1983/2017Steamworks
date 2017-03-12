#pragma once

#include <vector>
#include <string>

class cCsvLogger {
private:
	std::string m_filename;
public:
	cCsvLogger(std::string filename);

	void log(std::vector<float> values);
};
