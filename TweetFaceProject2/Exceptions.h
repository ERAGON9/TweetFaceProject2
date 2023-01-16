#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <exception>

class TweetFaceException : public std::exception
{
public:
	virtual const char* what() const override { return "\nSome eror occurred, call support team"; }
};

class NoSuchUserException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe name of the user does not exist at the system"; }
};

class NoSuchFanPageException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe name of the fan page does not exist at the system"; }
};

class takenNameException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe name already taken"; }
};

class NoUserStatusesException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe user don't have statuses"; }
};

class NoPageStatusesException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe fan page don't have statuses"; }
};

class ExistingFriensdshipException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nYou entered two users that already friends"; }
};

class SelfFriensdshipException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nYou can't make an user a friend of himself"; }
};

class DeleteSelfFriensdshipException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nYou can't delete friendship for an user of himself"; }
};

class NotUserFriendsException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nYou entered two users that not friends"; }
};

class IncorrectDayException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nDay must be between 1 to 31"; }
};

class IncorrectMonthException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nMonth must be between 1 to 12"; }
};

class UserNotFunOfFunPageException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe user already not a fan of this fan page"; }
};

class UserFanOfFanPageException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe user already a fan of this fan page"; }
};

class IncorrectYearException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nYear must be between 1900 to 2022"; }
};

class NoFriendsStatusesException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nAll your friend don't have statuses"; }
};

class EmptyNameException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nName is empty"; }
};

class EmptyTextStatusException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe status text is empty"; }
};

class EmptyImageStatusException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe status image name is empty"; }
};

class EmptyVideoStatusException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe status video name is empty"; }
};

class NoFansException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe fan page has no fans"; }
};

class NoFriendsException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nThe user has no friends"; }
};

class NoSuchStatusTypeException : public TweetFaceException
{
public:
	virtual const char* what() const override { return "\nStatus type is between 1 to 3, you entered wrong input"; }
};
#endif // !__EXCEPTIONS_H

