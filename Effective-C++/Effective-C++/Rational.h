#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Rational {
public:
	Rational(const T& numerator = 0,
		const T& denominator = 1):
		num(numerator),den(denominator){}
	const T numerator() const {
		return num;
	}
	const T denominator() const {
		return den;                   
	}
	friend const Rational operator*(const Rational& lhs, const Rational& rhs) {
		return Rational<T>(lhs.numerator() * rhs.numerator(),
			lhs.denominator() * rhs.denominator());
	}
private:
	T num;
	T den;
};

template<typename T>
ostream& operator<<(ostream& os, Rational<T> result) {
	os << result.numerator() << " " << result.denominator();
	return os;
}

