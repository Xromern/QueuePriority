#include "QueueException.h"

QueueException::QueueException(std::string s, int code_exception)
{
	this->code_exception = code_exception;
	this->s = s;
}

int QueueException::get_code_exception()
{
	return code_exception;
}

std::string QueueException::get_string_exception()
{
	return s;
}