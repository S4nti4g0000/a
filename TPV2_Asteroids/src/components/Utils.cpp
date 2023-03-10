#include "../ecs/Utils.hpp"

Time::Time()
{
	startTime_ = std::chrono::steady_clock::now();
}

float Time::getTime()
{
	std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> timeDifference = currentTime - startTime_;
	return timeDifference.count();
}