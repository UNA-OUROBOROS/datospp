#pragma once
#include <cstdint>
#include <datos++/vector.hpp>
#include <string_view>

namespace datospp {

class BigInt {
	vector<std::int32_t> v;

  public:
	BigInt() = default;
	explicit BigInt(const BigInt &b) = default;
	explicit BigInt(BigInt &&b) noexcept = default;
	BigInt(const std::string_view &s);
	BigInt(const std::int32_t i);

	BigInt &operator=(const BigInt &b) = default;
	BigInt &operator=(BigInt &&b) noexcept = default;
	BigInt &operator=(const std::string_view &s);
	BigInt &operator=(const std::int32_t i);

	BigInt operator+(const BigInt &b) const;
	BigInt operator-(const BigInt &b) const;
	BigInt operator*(const BigInt &b) const;
	BigInt operator/(const BigInt &b) const;

	BigInt &operator+=(const BigInt &b);
	BigInt &operator-=(const BigInt &b);
	BigInt &operator*=(const BigInt &b);
	BigInt &operator/=(const BigInt &b);

	bool operator==(const BigInt &b) const;
	bool operator!=(const BigInt &b) const;
	bool operator<(const BigInt &b) const;
	bool operator<=(const BigInt &b) const;
	bool operator>(const BigInt &b) const;
	bool operator>=(const BigInt &b) const;

	explicit operator std::string() const;

  private:
	bool isNegative();
};
namespace user_literals {
BigInt operator"" _BigInt(const char *, size_t);
BigInt operator"" _BigInt(unsigned long long int);
} // namespace user_literals

} // namespace datospp