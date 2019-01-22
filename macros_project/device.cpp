#include "device.h"
#include <cstdint>

//device_int* Ip::getReg() {
//	cout << to_string(ipp[0]) << "." << to_string(ipp[1]) << "." << to_string(ipp[2]) << "." << to_string(ipp[3]) << endl;
//	return ipp;
//}
//
//string Ip::toString() {
//	string ipStr;
//	ipStr.append(to_string(ipp[0])); ipStr.append(".");
//	ipStr.append(to_string(ipp[1])); ipStr.append(".");
//	ipStr.append(to_string(ipp[2])); ipStr.append(".");
//	ipStr.append(to_string(ipp[3]));
//	DEBUG_LOG(ipStr);
//	return ipStr;
//}
//
//void Ip::setAddress(string ipStr) {
//	string delimiter = ".";
//	int i = 0;
//	size_t start_pos = 0;
//	size_t end_pos = ipStr.find(delimiter, 0);
//	for (size_t i = 0; i < 4; i++)
//	{
//		ipp[i] = atoi(ipStr.substr(start_pos, end_pos).c_str());
//		start_pos = end_pos + 1;
//		if (i < 3)
//			end_pos = ipStr.find(delimiter, start_pos);
//		else
//			end_pos = ipStr.size();
//	}
//}
//
//Device::Device(device_int status) : statusCode(status) {
//
//}
//
//Device::~Device() { 
//	ip.~Ip(); 
//}
//
//bool Device::isConnected() {
//	return (getBit(statusCode, CONNECTED)) ? true : false; 
//}
//
//bool Device::isDisconnected() { 
//	return (getBit(statusCode, DISCONNECTED)) ? true : false; 
//}
//
//bool Device::isMsgPending() {
//	return (getBit(statusCode, MSG_PENDING)) ? true : false; 
//}
//
//void Device::clearMsgPendingBit() { 
//	clearBit(statusCode, MSG_PENDING); 
//}
//
//void Device::setSendMsgBit() { 
//
//}
//
//
//void Device::setStatus(device_int status) { 
//	statusCode = status; 
//}
//
//int Device::getStatus() {
//	return (int)statusCode; 
//}
//
//Ip& Device::getIp() {
//	return ip;
//}
//
//
//void Celphone::sendMessage(Device &target) {
//
//}
//
//void Celphone::Call() {
//
//}
//
//void Celphone::sendEmail(Device &target) {
//
//}
