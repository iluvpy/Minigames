#include "Timer.hpp"

Timer::Timer() {
	m_lastNow = Util::GetClock();
	m_now = Util::GetClock();
}

void Timer::Restart() {
	m_lastNow = m_now;
	m_now = Util::GetClock();
}

float Timer::GetDeltaTime() {
	return Util::GetClockDifference(m_now, m_lastNow);
}

Timer::~Timer() {

}
