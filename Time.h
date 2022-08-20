#pragma once
#include <iostream>
#include <Windows.h>

namespace myClasses {

	class Time {
		int hours;
		int minutes;
		int seconds;
	public:
		Time(int h = 0, int m = 0, int s = 0);

		Time& setHours(int h);
		Time& setMinutes(int m);
		Time& setSeconds(int s);
		Time& setTime(int h = 0, int m = 0, int s = 0);

		int getHours() const;
		int getMinutes() const;
		int getSeconds() const;

		void printTime() const;
		void setTimeWithSeconds(int sec);

		Time& operator++();
		Time operator++(int);
		Time& operator--();
		Time operator--(int);

		Time& operator+=(const Time& right);
		Time& operator-=(const Time& right);

		friend Time operator+(const Time& left, const Time& right);
		friend Time operator-(const Time& left, const Time& right);

		friend bool operator==(const Time& left, const Time& right);
		friend bool operator!=(const Time& left, const Time& right);
		friend bool operator<(const Time& left, const Time& right);
		friend bool operator>(const Time& left, const Time& right);
		friend bool operator<=(const Time& left, const Time& right);
		friend bool operator>=(const Time& left, const Time& right);

		friend std::ostream& operator<<(std::ostream& out, const Time& cl);
		friend std::istream& operator>>(std::istream& in, Time& cl);
	};



	Time::Time(int h, int m, int s) {
		setTime(h, m, s);
	}

	Time& Time::setHours(int h) {
		if (0 <= h && h < 24)
			hours = h;
		else
			hours = 0;
		return *this;
	}
	Time& Time::setMinutes(int m) {
		if (0 <= m && m < 60)
			minutes = m;
		else
			minutes = 0;
		return *this;
	}
	Time& Time::setSeconds(int s) {
		if (0 <= s && s < 60)
			seconds = s;
		else
			seconds = 0;
		return *this;
	}
	Time& Time::setTime(int h, int m, int s) {
		setHours(h);
		setMinutes(m);
		setSeconds(s);
		return *this;
	}

	int Time::getHours() const { return hours; }
	int Time::getMinutes() const { return minutes; }
	int Time::getSeconds() const { return seconds; }

	void Time::printTime() const {
		if (hours < 10)
			std::cout << "0";
		std::cout << hours << ":";
		if (minutes < 10)
			std::cout << "0";
		std::cout << minutes << ":";
		if (seconds < 10)
			std::cout << "0";
		std::cout << seconds;
	}
	void Time::setTimeWithSeconds(int sec) {
		this->seconds = sec % 60;
		this->hours = sec / 3600;
		this->minutes = (sec - this->seconds - this->hours * 3600) / 60;
		this->hours %= 24;
	}

	Time& Time::operator++() {
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			minutes++;
			if (minutes == 60) {
				minutes = 0;
				hours++;
				if (hours == 24)
					hours = 0;
			}
		}
		return *this;
	}
	Time Time::operator++(int) {
		Time cl = *this;
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			minutes++;
			if (minutes == 60) {
				minutes = 0;
				hours++;
				if (hours == 24)
					hours = 0;
			}
		}
		return cl;
	}
	Time& Time::operator--() {
		seconds--;
		if (seconds == -1) {
			seconds = 59;
			minutes--;
			if (minutes == -1) {
				minutes = 59;
				hours--;
				if (hours == -1)
					hours = 23;
			}
		}
		return *this;
	}
	Time Time::operator--(int) {
		Time cl = *this;
		seconds--;
		if (seconds == -1) {
			seconds = 59;
			minutes--;
			if (minutes == -1) {
				minutes = 59;
				hours--;
				if (hours == -1)
					hours = 23;
			}
		}
		return cl;
	}

	Time& Time::operator+=(const Time& right) {
		this->seconds += right.seconds;
		if (this->seconds >= 60) {
			this->seconds -= 60;
			this->minutes++;
		}
		this->minutes += right.minutes;
		if (this->minutes >= 60) {
			this->minutes -= 60;
			this->hours++;
		}
		this->hours += right.hours;
		if (hours >= 24)
			this->hours -= 24;
		return *this;
	}
	Time& Time::operator-=(const Time& right) {
		this->seconds -= right.seconds;
		if (this->seconds < 0) {
			this->seconds += 60;
			this->minutes--;
		}
		this->minutes -= right.minutes;
		if (this->minutes < 0) {
			this->minutes += 60;
			this->hours--;
		}
		this->hours -= right.hours;
		if (hours < 0)
			this->hours += 24;
		return *this;
	}

	Time operator+(const Time& left, const Time& right) {
		Time res = left;
		return res += right;
	}
	Time operator-(const Time& left, const Time& right) {
		Time res = left;
		return res -= right;
	}

	bool operator==(const Time& left, const Time& right) {
		if (left.hours == right.hours)
			if (left.minutes == right.minutes)
				return left.seconds == right.seconds;
		return false;
	}
	bool operator!=(const Time& left, const Time& right) {
		return !(left == right);
	}
	bool operator<(const Time& left, const Time& right) {
		if (left.hours < right.hours)
			return true;
		else if (left.hours > right.hours)
			return false;
		else {
			if (left.minutes < right.minutes)
				return true;
			else if (left.minutes > right.minutes)
				return false;
			else
				return left.seconds < right.seconds;
		}
	}
	bool operator>(const Time& left, const Time& right) {
		return !(left < right) && !(left == right);
	}
	bool operator<=(const Time& left, const Time& right) {
		return !(left > right);
	}
	bool operator>=(const Time& left, const Time& right) {
		return !(left < right);
	}

	std::ostream& operator<<(std::ostream& out, const Time& cl) {
		cl.printTime();
		return out;
	}
	std::istream& operator>>(std::istream& in, Time& cl) {
		int tmp;
		std::cout << "Hours: ";
		in >> tmp;
		cl.setHours(tmp);
		std::cout << "Minutes: ";
		in >> tmp;
		cl.setMinutes(tmp);
		std::cout << "Seconds: ";
		in >> tmp;
		cl.setSeconds(tmp);
		return in;
	}
}