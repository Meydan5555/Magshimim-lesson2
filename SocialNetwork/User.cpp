#include "User.h"
#include <iostream>
#include <string>

void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
	this->_devicelist = new DevicesList;
	_devicelist->init();
}

void User::clear()
{
	this->_id = 0;
	this->_username = "";
	this->_age = 0;
	_devicelist->clear();
	this->_devicelist = nullptr;
}

unsigned int User::getID() const
{
	return this->_id;
}

const std::string& User::getUserName() const
{
	return _username;
}

unsigned int User::getAge() const
{
	return this->_age;
}

DevicesList& User::getDevices() const
{
	return *_devicelist;
}

bool User::checkIfDevicesAreOn() const
{
	if (_devicelist == nullptr)
	{
		return true;
	}

	DeviceNode* temp = _devicelist->get_first();
	while (temp != nullptr)
	{
		if (!temp->get_data().isActive())
		{
			return false;
		}
		temp = temp->get_next();
	}
	return true;
}

void User::addDevice(const Device& newDevice)
{
	_devicelist->add(newDevice);
}