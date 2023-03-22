#ifndef TXT_H_
#define TXT_H
#include <string>

namespace l1{

class Txt {
public:
	Txt();
	Txt(const char *);
	Txt(const Txt&);
	Txt(Txt&&) noexcept;
	Txt& operator=(const Txt&);
	size_t size() const;
	~Txt();
private:
	size_t strCount;
	std::string* strArr;
};

}

#endif
