#include <sstream>
class Complex {
public:
	double re;
	double im;

	Complex() {}
	Complex(double real, double imaginary) : re(real), im(imaginary) {}

	Complex add(const Complex& other) const {
		return Complex(re + other.re, im + other.im);
	}

	Complex subtract(const Complex& other) const {
		return Complex(re - other.re, im - other.im);
	}

	Complex multiply(const Complex& other) const {
		return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
	}

	Complex divide(const Complex& other) const {
		double denominator = other.re * other.re + other.im * other.im;
		return Complex((re * other.re + im * other.im) / denominator,
			(im * other.re - re * other.im) / denominator);
	}

	void print() const {
		std::cout << re;
		if (im >= 0) {
			if (im == 0) {
				std::cout << "+" << 0 << "j" << std::endl;
			}
			else {
				std::cout << "+" << im << "j" << std::endl;
			}
		}
		else {
			std::cout << im << "j" << std::endl;
		}
	}

	Complex(std::string& num) {
		std::istringstream iss(num);
		iss >> re;
		char sign;
		iss >> sign;
		iss >> im;

		if (sign == '-') {
			im *= -1;
		}
	}
};

Complex operator+(const Complex& lhs, const Complex& rhs) {
	return lhs.add(rhs);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	return lhs.subtract(rhs);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	return lhs.multiply(rhs);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	return lhs.divide(rhs);
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
	os << complex.re;
	if (complex.im >= 0) {
		if (complex.im == 0) {
			os << "+" << 0 << "j";
		}
		else {
			os << "+" << complex.im << "j";
		}
	}
	else {
		os << complex.im << "j";
	}
	return os;
}
