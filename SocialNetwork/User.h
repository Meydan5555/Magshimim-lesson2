#pragma once
#include <string>
#include "DeviceList.h"

class User
{
public:
	void init(unsigned int id, std::string username, unsigned int age);
	void clear();
	unsigned int getID() const;
	const std::string& getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices() const;
	bool checkIfDevicesAreOn() const;
	void addDevice(const Device& newDevice);

private:
	unsigned int _id;
	unsigned int _age;
	std::string _username;
	DevicesList* _devicelist;
};