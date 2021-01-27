#pragma once

#ifndef DAMIAN_TIMER_H
#define DAMIAN_TIMER_H

#include "Commons.h"

#include <iostream>
#include <chrono>

namespace Damian
{
	class Timer
	{
	private:
		using clock_T = std::chrono::high_resolution_clock;
		using second_T = std::chrono::duration<double, std::ratio<1>>;

		std::chrono::time_point<clock_T> m_Begin;

	public:
		Timer() : m_Begin(clock_T::now())
		{
		}

		void Reset()
		{
			m_Begin = clock_T::now();
		}

		double GetCurrentPoint() const
		{
			return std::chrono::duration_cast<second_T>(clock_T::now() - m_Begin).count();
		}

		double Elapsed() const
		{
			return std::chrono::duration_cast<second_T>(clock_T::now() - m_Begin).count();
		}
	};
}

#endif