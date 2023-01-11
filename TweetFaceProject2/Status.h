#ifndef __STATUS_H
#define __STATUS_H

#include <string>
#include "Date.h"
#include "Time.h"


class Status
{
protected:
	Date date;
	Time time;
	std::string text;

public:
	Status(const std::string text);
	Status(const Status& other) = delete;
	//virtual ~Status() = default;

	virtual bool operator==(const Status& otherStatus) const;
	virtual bool operator!=(const Status& otherStatus) const;

	std::string getText() const { return text; }

	void printStatus() const;
	virtual void addToPrint() const;

};


class ImageStatus :public Status
{
private:
	std::string image;

public:
	ImageStatus(const std::string text, const std::string image);
	ImageStatus(const ImageStatus& other) = delete;

	virtual bool operator==(const Status& otherStatus) const override;
	//virtual bool operator!=(const Status& otherStatus) const override;

	std::string getImage() const { return image; }

	virtual void addToPrint() const override;
};


class VideoStatus :public Status
{
private:
	std::string video;


public:
	VideoStatus(const std::string text, const std::string video);
	VideoStatus(const VideoStatus& other) = delete;

	virtual bool operator==(const Status& otherStatus) const override;
	//virtual bool operator!=(const Status& otherStatus) const override;

	std::string getVideo() const { return video; }

	virtual void addToPrint() const override;
};

#endif // !__STATUS_H