#include "Txt.h"
#include <fstream>
#include <iostream>

l1::Txt::Txt() {
	strCount = 0;
	strArr = nullptr;
}

l1::Txt::Txt(const char *file_path) : l1::Txt::Txt() {
	std::ifstream textFile(file_path);
	if (textFile.is_open()) {
		//count of lines
		std::string strBuff;
		while(std::getline(textFile, strBuff)) strCount++;
		//memory
		strArr = new std::string[strCount];
		//read strings
		textFile.clear();
		textFile.seekg(std::ios::beg);
		for (size_t i = 0; i < strCount; i++) {
			std::getline(textFile, strArr[i]);
		}
		textFile.close();
	}
	else {
		std::cerr << "Can't open file " << file_path;
	}
}

l1::Txt::Txt(const Txt& other) {
	strCount = other.strCount;
	strArr = new std::string[strCount];
	for (size_t i = 0; i < strCount; i++)
		strArr[i] = other.strArr[i];
}

l1::Txt::Txt(Txt&& other) noexcept {
	strCount = other.strCount;
	strArr = other.strArr;
	other.strCount = 0;
	other.strArr = nullptr;
}

l1::Txt& l1::Txt::operator = (const Txt& other) {
	if(this != &other) {
		delete [] strArr;
		strCount = other.strCount;
		strArr = new std::string[strCount];
		for (size_t i = 0; i < strCount; i++)
			strArr[i] = other.strArr[i];
	}
	return *this;
}

l1::Txt& l1::Txt::operator = (Txt&& other) noexcept {
	if(this != &other) {
		delete [] strArr;
		strCount = other.strCount;
		strArr = other.strArr;
		other.strCount = 0;
		other.strArr = nullptr;
	}
	return *this;
}

size_t l1::Txt::size() const {
	return strCount;
}

l1::Txt::~Txt() {
	delete [] strArr;
}

