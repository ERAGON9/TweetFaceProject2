#ifndef __STATUS_H
#define __STATUS_H

#include <string>
#include "Date.h"
#include "Time.h"
#include <iostream>

// Default text status

class Status
{
protected:
	Date date;
	Time time;
	std::string text;

public:
	Status(const std::string text) noexcept(false);
	Status(const Status& other) = delete;

	virtual bool operator==(const Status& otherStatus) const;
	virtual bool operator!=(const Status& otherStatus) const;

	friend std::ostream& operator<<(std::ostream& os, const Status& status)
	{
		os << status.date << " " << status.time << std::endl << status.text;
		status.toOs(os);
		return os;
	}

	virtual void toOs(std::ostream& os) const {};

	std::string getText() const { return text; }

	void printStatus() const;
	virtual void addToPrint() const;
};


// Image Status that inherited from the default text status

class ImageStatus :public Status
{
private:
	std::string image;

public:
	ImageStatus(const std::string text, const std::string image);
	ImageStatus(const ImageStatus& other) = delete;

	virtual bool operator==(const Status& otherStatus) const override;

	virtual void toOs(std::ostream& os) const override;

	std::string getImage() const { return image; }

	virtual void addToPrint() const override;
};


// Video Status that inherited from the default text status

class VideoStatus :public Status
{
private:
	std::string video;

public:
	VideoStatus(const std::string text, const std::string video);
	VideoStatus(const VideoStatus& other) = delete;

	virtual bool operator==(const Status& otherStatus) const override;

	virtual void toOs(std::ostream& os) const override;

	std::string getVideo() const { return video; }

	virtual void addToPrint() const override;
};

#endif // !__STATUS_H