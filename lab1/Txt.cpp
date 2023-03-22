#include "Txt.h"
#include <istream>
#include <iostream>

l1::Txt::Txt() {
	strCount = 0;
	strArr = nullptr;
}

l1::Txt::Txt(const char *str) : l1::Txt::Txt() {
	try {

	} catch(...) {
		std::cerr << "Can't open file " << str;
	}
}

size_t l1::Txt::size() const {
	return strCount;
}

l1::Txt::~Txt() {
	delete [] strArr;
}

