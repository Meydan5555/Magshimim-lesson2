#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType { PHONE, PC, LAPTOP, TABLET };		     //
//
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
														 //
/// ///////////////////////////////////////////////////////


class Device
{
public:
	void init(const unsigned int id, const DeviceType type, const std::string os);
	unsigned int getID() const;
	std::string getOS() const;
	DeviceType getType() const;
	bool isActive() const;
	void activate();
	void deactivate();

private:
	unsigned int _id;
	bool _active;
	DeviceType _type;
	std::string _os;
};