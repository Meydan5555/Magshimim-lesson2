#include "Page.h"
#include <iostream>
#include <string>

void Page::init()
{
	this->_posts = "";
	this->_status = "";
}

std::string Page::getPosts() const
{
	return this->_posts;
}

std::string Page::getStatus() const
{
	return this->_status;
}

void Page::clearPage()
{
	this->_posts = "";
	this->_status = "";
}

void Page::setStatus(std::string status)
{
	this->_status = status;
}

void Page::addLineToPosts(std::string new_line)
{
	this->_posts = this->_posts + new_line + "\n";
}