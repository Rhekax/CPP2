#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val){
	std::cout << "Int constructor called" << std::endl;
	this->value = val << num_fractions;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(val * (1 << num_fractions));
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	value = obj.value;
}

Fixed::~Fixed() { std::cout << "Destructor called." << std::endl; }

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &obj)
		this->value = obj.getRawBits();

	return *this;
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(const int raw) {
	this->value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}

float Fixed::toFloat(void) const {
	return (float)value / (1 << num_fractions);
}

int Fixed::toInt(void) const {
	return value >> num_fractions;
}

bool Fixed::operator>(const Fixed& obj) const {
	return value > obj.value;
}

bool Fixed::operator<(const Fixed& obj) const {
	return value < obj.value;
}

bool Fixed::operator>=(const Fixed& obj) const {
	return value >= obj.value;
}

bool Fixed::operator<=(const Fixed& obj) const {
	return value <= obj.value;
}

bool Fixed::operator==(const Fixed& obj) const {
	return value == obj.value;
}

bool Fixed::operator!=(const Fixed& obj) const {
	return value != obj.value;
}

Fixed Fixed::operator+(const Fixed& obj) const {
	return Fixed(toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj) const {
	return Fixed(toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const {
	return Fixed(toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const {
	return Fixed(toFloat() / obj.toFloat());
}

Fixed& Fixed::operator++() {
	value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	value += 1;
	return tmp;
}

Fixed& Fixed::operator--() {
	value -= 1;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	value -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
