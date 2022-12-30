#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

class TweetFaceException : public std::exception
{
public:
	virtual const char* what() const override { return "\nSome eror occurred at function 1, call support team."; }

};
class NoSuchUserException : public std::TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe name of the user does not exist at the system"; }

};

class NoSuchFanPageException : public std::TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe name of the fan page does not exist at the system"; }

};









#endif // !__EXCEPTIONS_H

