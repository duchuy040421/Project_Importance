#include"Time.h"

Time::Time() {
	time_t info = time(NULL);
	tm* now = std::localtime(&info);
	this->_hour = now->tm_hour; this->_min = now->tm_min; this->_sec = now->tm_sec;
}
Time::Time(int hour, int min, int sec) {
	this->_hour = hour;
	this->_min = min;
	this->_sec = sec;
}
string Time::toString() {
	string temp;
	temp = to_string(this->_hour) + ':' + to_string(this->_min) + ':' + to_string(this->_sec);
	return temp;
}
Time Time::parse(string n) {
	Time temp;
	temp._hour = 0; temp._min = 0; temp._sec = 0;
	temp._hour = atoi(n.substr(0, 2).c_str());
	temp._min = atoi(n.substr(3, 2).c_str());
	temp._sec = atoi(n.substr(6, 2).c_str());
	return temp;
}
bool Time::tryParse(string n, Time &t) {
	Time temp = parse(n);
	if (temp._hour == t._hour && temp._min == t._min && temp._sec == t._sec)
		return true;
	return false;
}
bool Time::isValid(string n) {
	Time temp;
	temp = Time::parse(n);
	if (temp._hour < 0 || temp._hour>24)
		return false;
	else if (temp._min < 0 || temp._min>59)
		return false;
	else if (temp._sec < 0 || temp._sec>59)
		return false;
	else
		return true;
}