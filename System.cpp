#include "System.h"

System::System() = default;
System::System(const std::vector<double>& time) : m_time{ time } {}

const std::vector<double>& System::getTime() const { return m_time; }
void System::setTime(const std::vector<double>& time) { m_time = time; }