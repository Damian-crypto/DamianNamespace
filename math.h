#ifndef DAMIAN_MATH_H
#define DAMIAN_MATH_H

#include <typeinfo>

namespace Damian {

	using numeric_Type = int;
	constexpr double PI = 3.14159265358979;

	class Math
	{
	public:
		static numeric_Type GetGCD(numeric_Type a, numeric_Type b);
		static numeric_Type GetLCM(numeric_Type a, numeric_Type b);
		static numeric_Type GetCircleArea(numeric_Type radius);
	};

	numeric_Type Math::GetGCD(numeric_Type a, numeric_Type b)
	{
		if(typeid(numeric_Type).name() != typeid(int).name())
		{
			a = static_cast<int>(a);
			b = static_cast<int>(b);
		}

		return (b == 0) ? (a > 0 ? a : -a) : GetGCD(b, a % b);
	}

	numeric_Type Math::GetLCM(numeric_Type a, numeric_Type b)
	{
		return ((a * b) / GetGCD(a, b));
	}

	numeric_Type Math::GetCircleArea(numeric_Type radius)
	{
		return (radius * radius * PI);
	}
}

#endif
