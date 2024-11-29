#include "Profile.h"
#include <iostream>
#include <string>

void Profile::init(User owner)
{
	this->_user = owner;
	_page.init();
	this->_userlist = new UserList;
	_userlist->init();
}

void Profile::clear()
{
	_user.clear();
	_page.clearPage();
	_userlist->clear();
}

void Profile::setStatus(std::string new_status)
{
	this->_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	this->_page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	this->_userlist->add(friend_to_add);
}

User Profile::getOwner() const
{
	return this->_user;
}

std::string Profile::getPage() const
{
	return "Status: " + _page.getStatus() + "\n*******************\n*******************\n" + _page.getPosts();
}

std::string Profile::getFriends() const
{
	std::string friends = "";
	UserNode* temp = _userlist->get_first();

	if (temp != nullptr)
	{
		friends = temp->get_data().getUserName();
		temp = temp->get_next();
	}
	while (temp != nullptr)
	{
		friends = friends + "," + temp->get_data().getUserName();
		temp = temp->get_next();
	}
	return friends;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	int nameSize = this->_user.getUserName().length(), count = 0;
	std::string friends = "";
	UserNode* temp = _userlist->get_first();

	while (temp != nullptr)
	{
		if (temp->get_data().getUserName().length() == nameSize)
		{
			if (count == 0)
			{
				friends = friends + temp->get_data().getUserName();
				count++;
			}
			else
			{
				friends = friends + "," + temp->get_data().getUserName();
			}
		}
		temp = temp->get_next();
	}
	return friends;
}
