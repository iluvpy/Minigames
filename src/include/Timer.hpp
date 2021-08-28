#pragma once

#include "Structs.hpp"
#include "Types.hpp"
#include "Utils.hpp"

class Timer {
public:
	Timer();
	void Restart();
	float GetDeltaTime();
	~Timer();
private:
	Clock_t m_now;
	Clock_t m_lastNow;
};