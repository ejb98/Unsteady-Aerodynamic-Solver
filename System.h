#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>

class System
{
private:
	std::vector<double> m_time{};

public:
	System();
	System(const std::vector<double>& time);

	const std::vector<double>& getTime() const;
	void setTime(const std::vector<double>& time);
};

#endif