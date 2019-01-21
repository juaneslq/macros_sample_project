#ifndef DEVICE_H_
#define DEVICE_H_

#include <cstdint>
#include <iostream>
#include <string> 
#pragma once

using namespace std;
#define getStatusBit(bit)	((statusCode << bit) & 0x01)

// STATUS BITS
#define CONNECTED		0
#define DISCONNECTED	1

typedef uint8_t device_int;

class Ip {
	device_int ipp[4];
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
		cout << ipStr << endl;
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
	Device(device_int status) : statusCode(status) {};
	~Device() { ip.~Ip(); };

	bool isConnected() { return (getStatusBit(CONNECTED)) ? true : false; };
	bool isDisconnected() { return (getStatusBit(DISCONNECTED)) ? true : false; }; 
	void setStatus(device_int status) { statusCode = status; };
	int getStatus() { return (int) statusCode; };
	Ip& getIp() { return ip; }

};

#endif DEVICE_H_

