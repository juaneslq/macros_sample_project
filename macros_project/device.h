#ifndef DEVICE_H_
#define DEVICE_H_

#include <cstdint>
#include <iostream>
#include <string> 
#include "utils.h"

using namespace std;

#define getBit(reg, bit)	((reg >> bit) & 0x01)
#define setBit(reg, bit)	(reg | (0x01 << bit))
#define clearBit(reg, bit)	(reg & ~(0x01 << bit))

// STATUS BITS
#define CONNECTED		0
#define DISCONNECTED	1
#define MSG_PENDING		2
#define MSG_SENT		3


typedef uint8_t device_int;

class Ip {
	device_int ipp[4];
	device_int mac[8];
public:
	Ip() : ipp{ 192, 168, 0, 1 } {};
	~Ip() {};

	device_int* getReg() {
		cout << to_string(ipp[0]) << "." << to_string(ipp[1]) << "." << to_string(ipp[2]) << "." << to_string(ipp[3]) << endl;
		return ipp;
	}
	string toString() {
		string ipStr;
		ipStr.append(to_string(ipp[0])); ipStr.append(".");
		ipStr.append(to_string(ipp[1])); ipStr.append(".");
		ipStr.append(to_string(ipp[2])); ipStr.append(".");
		ipStr.append(to_string(ipp[3]));
		DEBUG_LOG(ipStr);
		return ipStr;
	}
	void setAddress(string ipStr) {
		string delimiter = ".";
		int i = 0;
		size_t start_pos = 0;
		size_t end_pos = ipStr.find(delimiter, 0);
		for (size_t i = 0; i < 4; i++)
		{
			ipp[i] = atoi(ipStr.substr(start_pos, end_pos).c_str());
			start_pos = end_pos + 1;
			if (i < 3)
				end_pos = ipStr.find(delimiter, start_pos);
			else
				end_pos = ipStr.size();
		}
	}
};

class Device
{
	device_int statusCode;
	Ip ip;

public:
	Device() {};
	Device(device_int status) : statusCode(status) {};
	~Device() { ip.~Ip(); };

	bool isConnected() { return ( getBit(statusCode, CONNECTED) ) ? true : false; };
	bool isDisconnected() { return (getBit(statusCode, DISCONNECTED) ) ? true : false; };
	bool isMsgPending() { return ( getBit(statusCode, MSG_PENDING) ) ? true : false; };

	void clearMsgPendingBit() { clearBit(statusCode, MSG_PENDING); };

	void setSendMsgBit() { };


	void setStatus(device_int status) { statusCode = status; };
	int getStatus() { return (int) statusCode; };
	Ip& getIp() { return ip; }

};



class Celphone : public Device {
	device_int imei[8];
	device_int phone_number[10];
public:

	Celphone() {};
	~Celphone() {};
	void sendMessage(Device &target) {};
	void Call() {};
	void sendEmail(Device &target) {};

};

#endif DEVICE_H_

