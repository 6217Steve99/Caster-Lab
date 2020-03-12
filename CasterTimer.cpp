#include "CasterTimer.h"

using namespace std::chrono;

CasterTimer::CasterTimer() noexcept
{
	last = steady_clock::now();
}

float CasterTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float CasterTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}