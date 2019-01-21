#include <stdlib.h>
#include <iostream>
#include "device.h"

using namespace std;

#define lessThan(x, y)   (x < y) ? true : false


int main() {

	if (lessThan(6, 5))
		cout << "Hello World" << endl;

	Device d(0x01);

	cout << d.getStatus() << endl;
	if (d.isConnected() == 1) {
		cout << "device d connected!!" << endl;
	}
	if (d.isDisconnected() == 1) {
		cout << "device d connected!!" << endl;
	}

	d.getIp().toString();
	d.getIp().setAddress("192.169.2.2");
	d.getIp().toString();

	

	system("pause");
	return 0;
}