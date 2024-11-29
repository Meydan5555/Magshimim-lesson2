#pragma once
#include <string>
#include "User.h"
#include "Page.h"
#include "UserList.h"

class Profile
{
public:
	void init(User owner);
	void clear();
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	User getOwner() const;
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;

private:
	User _user;
	Page _page;
	UserList* _userlist;
};