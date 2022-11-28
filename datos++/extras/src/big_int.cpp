#define datosppLIBRARY_EXPORT
#include <datos++/big_int.hpp>

// dummy export api
datosppAPI void dummyFunction() {}

namespace datospp {

datosppAPI BigInt::BigInt(const std::string_view &s) {
	// TODO: implement
}

datosppAPI BigInt::BigInt(const std::int32_t i) {
	if (i < 0) {
		v.push_back(-1);
		v.push_back(-i);
	} else {
		v.push_back(1);
		v.push_back(i);
	}
}

datosppAPI bool BigInt::operator==(const BigInt &b) const{
	// compare each integer in the vector
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] != b.v[i]) {
			return false;
		}
	}
	return true;
}

} // namespace datospp