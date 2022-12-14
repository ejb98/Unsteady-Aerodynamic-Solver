#ifndef SYSTEM_H
#define SYSTEM_H

#include "Body.h"
#include <vector>

class System
{
private:
	std::vector<double> m_time{};
	std::vector<Body> m_bodies{};

public:
	System();
	System(const std::vector<double>& time);

	const std::vector<double>& getTime() const;
	void setTime(const std::vector<double>& time);

	const std::vector<Body>& getBodies() const;
	void setBodies(const std::vector<Body>& bodies);
};

#endif