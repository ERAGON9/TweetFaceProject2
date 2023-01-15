
#include "Status.h"
#include <string>
#include <iostream>
#include "Exceptions.h"

using namespace std;

const int TEN = 10;


// Status definition

Status::Status(const string text) noexcept(false) : date(), time()
{
	if (text.size() == 0)
		throw EmptyStatusException();

	this->text = text;
}


bool Status::operator==(const Status& otherStatus) const
{
	if (text == otherStatus.getText())
		return true;
	else
		return false;
}


bool Status::operator!=(const Status& otherStatus) const
{
	if (*this == otherStatus)
		return false;
	else
		return true;
}


void Status::printStatus() const
{
	cout << "\nThe status wroten at: " << (date.getDay() < TEN ? "0" : "") << date.getDay() << " / "
		 << (date.getmonth() < TEN ? "0" : "") << date.getmonth() << " / " << date.getYear() << endl
		 << "At time: " << (time.getHour() < 10 ? "0" : "") << time.getHour() << " : "
		 << (time.getminute() < TEN ? "0" : "") << time.getminute() << endl;

	this->addToPrint();

	cout << "The status text is: " << text << endl;
}


void Status::addToPrint() const
{
	cout << "This status is printed at black & white" << endl
		 << "This status is shown by simple program" << endl;
}


// ImageStatus definition


ImageStatus::ImageStatus(const string text, const string image) : Status(text)
{
	this->image = image;
}


bool ImageStatus::operator==(const Status& otherStatus) const
{
	const ImageStatus* other = dynamic_cast<const ImageStatus*>(&otherStatus);

	if (other == nullptr)
		return false;

	if (Status::operator==(*other) == false)
		return false;
	
	if (this->getImage() != other->getImage())
		return false;

	return true;
}


void ImageStatus::toOs(std::ostream& os) const
{
	os << endl << image;
}


void ImageStatus::addToPrint() const
{
	cout << "This status is printed at black & white or colorfully" << endl
		 << "This status is shown by simple program" << endl
	     << "The status Image is: " << image << endl;
}


// VideoStatus definition


VideoStatus::VideoStatus(const string text, const string video) : Status(text)
{
	this->video = video;
}


bool VideoStatus::operator==(const Status& otherStatus) const
{
	const VideoStatus* other = dynamic_cast<const VideoStatus*>(&otherStatus);

	if (other == nullptr)
		return false;

	if (Status::operator==(*other) == false)
		return false;

	if (this->getVideo() != other->getVideo())
		return false;

	return true;
}


void VideoStatus::toOs(std::ostream& os) const
{
	os << endl << video;
}


void VideoStatus::addToPrint() const
{
	cout << "This status is printed at black & white or colorfully" << endl
		<< "This status is shown by video software" << endl
		<< "The status video is: " << video << endl;
}