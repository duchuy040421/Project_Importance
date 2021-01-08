#include "Header.h"

int modernization(int sec, int min) {
	return min * 60 + sec;
}
void printTime() {
	time_t info = time(NULL);
	tm* now = localtime(&info);

	int time = modernization(now->tm_sec - Sec, now->tm_min - Min);
	if (time < 60) {
		cout << time << " s";
	}
	else
		cout << time / 60 << " m " << time - (time / 60) * 60 << " s";
}
void startTime() {
	time_t info = time(NULL);	// get time now
	tm* now = localtime(&info);
	Sec = now->tm_sec + 2;
	Min = now->tm_min;
}