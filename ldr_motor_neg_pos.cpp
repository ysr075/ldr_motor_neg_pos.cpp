#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void timer_delay(int seconds) {
	int milli_seconds = 1000 * seconds;
	clock_t start_time = clock();
	while (clock() < milli_seconds + start_time);
}

int main() {
	string motor_stop = "\nmotor stop\n"; // 0
	string motor_pos = "\nmotor pos\n"; // +8
	string motor_neg = "\nmotor neg\n"; // -8
	int IF1_ldr;
	do {
		cout << "\nIF1: "; cin >> IF1_ldr;
		if (IF1_ldr == 1) {
			int i; int loop;
			cout << "\nloop: "; cin >> loop;
			do {
				for (i = 0; i < loop; i++) {
					cout << motor_pos;
					timer_delay(1);
				}
			} while (i < 10);
			do {
				cout << "\nIF1: "; cin >> IF1_ldr;
				cout << motor_stop;
			} while (IF1_ldr == 1);
			cout << "\nloop: "; cin >> loop;
			do {
				for (i = 0; i < loop; i++) {
					cout << motor_neg;
					timer_delay(1);
				}
			} while (i < 10);
			return main();
		} else if (IF1_ldr == 0) {
			cout << motor_stop;
			return main();
		} else {
			exit(1);
		}
	} while (true);
	return 0;
}
