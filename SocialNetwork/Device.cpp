#include "Device.h"
#include <iostream>
#include <string>

void Device::init(const unsigned int id, const DeviceType type, const std::string os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	this->_active = true;
}

unsigned int Device::getID() const
{
	return this->_id;
}

std::string Device::getOS() const
{
	return this->_os;
}

DeviceType Device::getType() const
{
	return this->_type;
}

bool Device::isActive() const
{
	return this->_active;
}

void Device::activate()
{
	this->_active = true;
}

void Device::deactivate()
{
	this->_active = false;
}