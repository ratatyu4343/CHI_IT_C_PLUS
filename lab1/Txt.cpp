#include "Txt.h"

l1::Txt::Txt() {
	strCount = 0;
	strArr = nullptr;
}

size_t l1::Txt::size() const {
	return strCount;
}

l1::Txt::~Txt() {

}

