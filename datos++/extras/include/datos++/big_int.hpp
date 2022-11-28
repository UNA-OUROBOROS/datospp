#pragma once
#include <datos++/private/exportAPI.hpp>
#include <cstdint>
#include <datos++/vector.hpp>
#include <string_view>

namespace datospp {

class BigInt {
	vector<std::int32_t> v;

  public:
	datosppAPI BigInt() = default;
	datosppAPI explicit BigInt(const BigInt &b) = default;
	datosppAPI explicit BigInt(BigInt &&b) noexcept = default;
	datosppAPI BigInt(const std::string_view &s);
	datosppAPI BigInt(const std::int32_t i);

	datosppAPI BigInt &operator=(const BigInt &b) = default;
	datosppAPI BigInt &operator=(BigInt &&b) noexcept = default;
	datosppAPI BigInt &operator=(const std::string_view &s);
	datosppAPI BigInt &operator=(const std::int32_t i);

	datosppAPI BigInt operator+(const BigInt &b) const;
	datosppAPI BigInt operator-(const BigInt &b) const;
	datosppAPI BigInt operator*(const BigInt &b) const;
	datosppAPI BigInt operator/(const BigInt &b) const;

	datosppAPI BigInt &operator+=(const BigInt &b);
	datosppAPI BigInt &operator-=(const BigInt &b);
	datosppAPI BigInt &operator*=(const BigInt &b);
	datosppAPI BigInt &operator/=(const BigInt &b);

	datosppAPI bool operator==(const BigInt &b) const;
	datosppAPI bool operator!=(const BigInt &b) const;
	datosppAPI bool operator<(const BigInt &b) const;
	datosppAPI bool operator<=(const BigInt &b) const;
	datosppAPI bool operator>(const BigInt &b) const;
	datosppAPI bool operator>=(const BigInt &b) const;

	datosppAPI explicit operator std::string() const;

	datosppAPI ~BigInt() = default;
  private:
	datosppAPI bool isNegative();
};
namespace user_literals {
BigInt operator"" _BigInt(const char *, size_t);
BigInt operator"" _BigInt(unsigned long long int);
} // namespace user_literals

} // namespace datospp