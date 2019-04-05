#pragma once
#include <exception>
#include <string>

class QueueException :public std::exception
{
	int code_exception;
	std::string s;
public:
	QueueException(std::string s, int state);
	int get_code_exception();
	std::string get_string_exception();
};