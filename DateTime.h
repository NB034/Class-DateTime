#pragma once
#include "Date.h"
#include "Time.h"

class DateTime :public myClasses::Date, public myClasses::Time {
public:
	DateTime(int year = 1970, int month = 1, int day = 1, int hours = 0, int minutes = 0, int seconds = 0);
	void setDateAndTime(int year, int month = 1, int day = 1, int hours = 0, int minutes = 0, int seconds = 0);

	void printDateAndTime() const;

	void addSecond();
	void deductSecond();

	void addMinute();
	void deductMinute();

	void addHour();
	void deductHour();

	void addDay();
	void deductDay();

	void increaseWithSeconds(int seconds);
	void decreaseWithSeconds(int seconds);

	void increaseWithDays(int days);
	void decreaseWithDays(int days);
};



std::ostream& operator<<(std::ostream& out, const DateTime& dt) {
	dt.printDateAndTime();
	return out;
}

std::istream& operator>>(std::istream& in, DateTime& dt) {
	int tmp;
	std::cout << "Year: ";
	in >> tmp;
	dt.setDay(tmp);
	std::cout << "Month: ";
	in >> tmp;
	dt.setMonth(tmp);
	std::cout << "Day: ";
	in >> tmp;
	dt.setYear(tmp);
	std::cout << "Hours: ";
	in >> tmp;
	dt.setHours(tmp);
	std::cout << "Minutes: ";
	in >> tmp;
	dt.setMinutes(tmp);
	std::cout << "Seconds: ";
	in >> tmp;
	dt.setSeconds(tmp);
	return in;
}

bool operator<=(const DateTime& left, const DateTime& right) {
	if (left.getYear() < right.getYear())
		return true;
	if (left.getYear() > right.getYear())
		return false;
	if (left.getMonth() < right.getMonth())
		return true;
	if (left.getMonth() > right.getMonth())
		return false;
	if (left.getDay() < right.getDay())
		return true;
	if (left.getDay() > right.getDay())
		return false;
	if (left.getHours() < right.getHours())
		return true;
	if (left.getHours() > right.getHours())
		return false;
	if (left.getMinutes() < right.getMinutes())
		return true;
	if (left.getMinutes() > right.getMinutes())
		return false;
	if (left.getSeconds() > right.getSeconds())
		return false;
	return true;
}

bool operator==(const DateTime& left, const DateTime& right) {
	if (left.getYear() == right.getYear())
		if (left.getMonth() == right.getMonth())
			if (left.getDay() == right.getDay())
				if (left.getHours() == right.getHours())
					if (left.getMinutes() == right.getMinutes())
						if (left.getSeconds() == right.getSeconds())
							return true;
	return false;
}

bool operator!=(const DateTime& left, const DateTime& right) {
	return !(left == right);
}

bool operator>(const DateTime& left, const DateTime& right) {
	return !(left <= right);
}

bool operator<(const DateTime& left, const DateTime& right) {
	return (left != right && !(left > right));
}

bool operator>=(const DateTime& left, const DateTime& right) {
	return (left == right || left > right);
}

DateTime::DateTime(int year, int month, int day, int hours, int minutes, int seconds)
	:Date(day, month, year), Time(hours, minutes, seconds) {}

void DateTime::setDateAndTime(int year, int month, int day, int hours, int minutes, int seconds) {
	this->setDate(day, month, year);
	this->setTime(hours, minutes, seconds);
}

void DateTime::printDateAndTime() const {
	this->printDate();
	std::cout << " - ";
	this->printTime();
}

void DateTime::addSecond() {
	this->Time::operator++();
	if (this->getHours() == 0 && this->getMinutes() == 0 && this->getSeconds() == 0)
		this->addDay();
}

void DateTime::deductSecond() {
	this->Time::operator--();
	if (this->getHours() == 23 && this->getMinutes() == 59 && this->getSeconds() == 59)
		this->deductDay();
}

void DateTime::addMinute() {
	for (size_t i = 0; i < 60; i++) {
		this->addSecond();
	}
}

void DateTime::deductMinute() {
	for (size_t i = 0; i < 60; i++) {
		this->deductSecond();
	}
}

void DateTime::addHour() {
	for (size_t i = 0; i < 60; i++) {
		this->addMinute();
	}
}

void DateTime::deductHour() {
	for (size_t i = 0; i < 60; i++) {
		this->deductMinute();
	}
}

void DateTime::addDay() {
	this->Date::operator++();
}

void DateTime::deductDay() {
	this->Date::operator--();
}

void DateTime::increaseWithSeconds(int seconds) {
	for (size_t i = 0; i < seconds; i++) {
		this->addSecond();
	}
}

void DateTime::decreaseWithSeconds(int seconds) {
	for (size_t i = 0; i < seconds; i++) {
		this->deductSecond();
	}
}

void DateTime::increaseWithDays(int days) {
	for (size_t i = 0; i < days; i++) {
		this->addDay();
	}
}

void DateTime::decreaseWithDays(int days) {
	for (size_t i = 0; i < days; i++) {
		this->deductDay();
	}
}