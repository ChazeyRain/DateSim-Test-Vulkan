#ifndef WINDOW_CREATOR_H
#define WINDOW_CREATOR_H

#include <memory>


class WindowCreator {
public:
	WindowCreator();
	~WindowCreator();

	void run();
private:
	struct impl;
	std::unique_ptr<impl> pimpl;
};

#endif