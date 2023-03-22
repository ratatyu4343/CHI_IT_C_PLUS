#include "Txt.h"
#include <istream>
#include <iostream>
#include <algorithm>

l1::Txt::Txt() {
	strCount = 0;
	strArr = nullptr;
}

l1::Txt::Txt(const char *file_path) : l1::Txt::Txt() {
	std::ifstream file(file_path);
	if (file.is_open()) {

	}
	else {
		std::cerr << "Can't open file " << file_path;
	}
}

size_t l1::Txt::size() const {
	return strCount;
}

l1::Txt::~Txt() {
	delete [] strArr;
}

