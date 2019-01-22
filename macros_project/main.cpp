#include <stdlib.h>
#include <iostream>
#include "device.h"
#include "utils.h"

using namespace std;

#define lessThan(x, y)   (x < y) ? true : false


int main() {

	if (lessThan(6, 5))
		INFO_LOG("Hello World");

	Device d(0x01);

	DEBUG_LOG( d.getStatus());
	if (d.isConnected() == 1) {
		INFO_LOG("Device d connected!");
	}
	if (d.isDisconnected() == 1) {
		INFO_LOG("Device d disconnected!");
	}

	d.getIp().toString();
	d.getIp().setAddress("192.169.2.2");
	d.getIp().toString();

	

	system("pause");
	return 0;
}