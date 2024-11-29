#include "SocialNetwork.h"
#include <iostream>
#include <string>

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->_networkName = networkName;
	this->_minAge = minAge;
	this->_profilelist = new ProfileList;
	_profilelist->init();
}

void SocialNetwork::clear()
{
	this->_networkName = "";
	this->_minAge = 0;
	_profilelist->clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return this->_networkName;
}

int SocialNetwork::getMinAge() const
{
	return this->_minAge;
}

std::string SocialNetwork::getWindowsDevices() const
{
	int count = 0;
	std::string windowsDevices = "";
	ProfileNode* pTemp = _profilelist->get_first();

	while (pTemp != nullptr)
	{
		Profile dTemp = pTemp->get_data();
		DeviceNode* dNode = dTemp.getOwner().getDevices().get_first();

		while (dNode != nullptr)
		{
			if (dNode->get_data().getOS() == WINDOWS11 || dNode->get_data().getOS() == WINDOWS10 || dNode->get_data().getOS() == WINDOWS7)
			{
				if (count == 0)
				{
					windowsDevices += "[" + std::to_string(dNode->get_data().getID()) + ", " + dNode->get_data().getOS() + "]";
					count++;
				}
				else
				{
					windowsDevices += ", [" + std::to_string(dNode->get_data().getID()) + ", " + dNode->get_data().getOS() + "]";
				}
			}
			dNode = dNode->get_next();
		}
		pTemp = pTemp->get_next();
	}
	return windowsDevices;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < getMinAge())
	{
		return false;
	}
	this->_profilelist->add(profile_to_add);
	return true;
}
