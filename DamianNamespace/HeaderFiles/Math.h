#pragma once

#ifndef DAMIAN_MATH_H
#define DAMIAN_MATH_H

#include "Functions.h"

#include <typeinfo>
#include <limits>
#include <cmath>

namespace Damian {

	using numeric_Type = double;
	constexpr double PI = 3.14159265358979;

	class Point2D
	{
	private:
		numeric_Type m_X = 0;
		numeric_Type m_Y = 0;
		std::string m_Tag = "";

	public:
		Point2D(numeric_Type x = 0, numeric_Type y = 0, const std::string& tag = "a")
			: m_X(x), m_Y(y), m_Tag(tag)
		{}

		numeric_Type GetX() const { return m_X; }
		numeric_Type GetY() const { return m_Y; }

		const std::string& GetTag() const { return m_Tag; }
		void SetTag(const std::string& tag) { m_Tag = tag; }

		Point2D& operator+=(const Point2D& point)
		{
			m_X += point.m_X;
			m_Y += point.m_Y;

			return *this;
		}

		Point2D& operator-=(const Point2D& point)
		{
			m_X -= point.m_X;
			m_Y -= point.m_Y;

			return *this;
		}

		friend Point2D operator+(const Point2D& point1, const Point2D& point2);
		friend Point2D operator-(const Point2D& point1, const Point2D& point2);
		friend bool operator==(const Point2D& point1, const Point2D& point2);
		friend bool operator!=(const Point2D& point1, const Point2D& point2);
	};

	Point2D operator+(const Point2D& point1, const Point2D& point2)
	{
		Point2D _temp{ point1 };
		_temp += point2;
		return _temp;
	}

	Point2D operator-(const Point2D& point1, const Point2D& point2)
	{
		Point2D _temp{ point1 };
		_temp -= point2;
		return _temp;
	}

	bool operator==(const Point2D& point1, const Point2D& point2)
	{
		return point1.m_X == point2.m_X && point1.m_Y == point2.m_Y;
	}

	bool operator!=(const Point2D& point1, const Point2D& point2)
	{
		return point1 != point2;
	}

	class Point3D
	{
	private:
		numeric_Type m_X;
		numeric_Type m_Y;
		numeric_Type m_Z;
		std::string m_Tag = "";

	public:
		Point3D(numeric_Type x = 0, numeric_Type y = 0, numeric_Type z = 0, const std::string& tag = "a")
			: m_X(x), m_Y(y), m_Z(z), m_Tag(tag)
		{}

		numeric_Type GetX() const { return m_X; }
		numeric_Type GetY() const { return m_Y; }
		numeric_Type GetZ() const { return m_Z; }

		const std::string& GetTag() const { return m_Tag; }
		void SetTag(const std::string& tag) { m_Tag = tag; }
	};

	class Math
	{
	public:
		static constexpr int MIN_INT = std::numeric_limits<int>::min();
		static constexpr int MAX_INT = std::numeric_limits<int>::max();
		static constexpr numeric_Type MIN_NUM = std::numeric_limits<numeric_Type>::min();
		static constexpr numeric_Type MAX_NUM = std::numeric_limits<numeric_Type>::max();

	public:
		static numeric_Type GetGCD(numeric_Type a, numeric_Type b);
		static numeric_Type GetLCM(numeric_Type a, numeric_Type b);
		static numeric_Type GetCircleArea(numeric_Type radius);
		static numeric_Type GetSquareArea(numeric_Type side);
		static numeric_Type GetCircleCircumference(numeric_Type radius);
		static numeric_Type Pow(numeric_Type base, numeric_Type exponent);
		static numeric_Type Sqrt(numeric_Type number);
		static numeric_Type Distance(const Point2D& a, const Point2D& b);
		static numeric_Type Permutation(numeric_Type n, numeric_Type k);
		static numeric_Type Combination(numeric_Type n, numeric_Type k);
		static numeric_Type Factorial(numeric_Type n);
	};

	numeric_Type Math::GetGCD(numeric_Type a, numeric_Type b)
	{
		int l_a = 0, l_b = 0;
		if (Type(MIN_NUM) != Type(MIN_INT))
		{
			l_a = static_cast<int>(a);
			l_b = static_cast<int>(b);
		}
		else
		{
			l_a = a;
			l_b = b;
		}

		return (l_b == 0) ? (l_a > 0 ? l_a : -l_a) : GetGCD(l_b, l_a % l_b);
	}

	numeric_Type Math::GetLCM(numeric_Type a, numeric_Type b)
	{
		return ((a * b) / GetGCD(a, b));
	}

	numeric_Type Math::GetCircleArea(numeric_Type radius)
	{
		return (radius * radius * PI);
	}

	numeric_Type Math::GetSquareArea(numeric_Type side)
	{
		return (side * side);
	}

	numeric_Type Math::GetCircleCircumference(numeric_Type radius)
	{
		return (2 * PI * radius);
	}

	numeric_Type Math::Pow(numeric_Type base, numeric_Type exponent)
	{
		return std::pow(base, exponent);
	}

	numeric_Type Math::Sqrt(numeric_Type value)
	{
		return std::sqrt(value);
	}

	numeric_Type Math::Distance(const Point2D& a, const Point2D& b)
	{
		return Sqrt(Pow((a.GetX() - b.GetX()), 2) + Pow((a.GetY() - b.GetY()), 2));
	}

	numeric_Type Math::Factorial(numeric_Type n)
	{
		try
		{
			numeric_Type result = 1;

			if (n > 0)
				result = n * Factorial(n - 1);

			return result;
		}
		catch (std::exception e)
		{
			PRINT_ERR("Error: cannot calculate numbers: " + std::string(e.what()));
			return 0;
		}

		return 0;
	}

	numeric_Type Math::Permutation(numeric_Type n, numeric_Type k)
	{
		try
		{
			numeric_Type result = 1;

			for (numeric_Type i = 0; i < n; ++i)
			{
				result *= (n - i);
			}

			for (numeric_Type i = 1; i <= (n - k); ++i)
			{
				result /= i;
			}

			return result;
		}
		catch (std::exception e)
		{
			PRINT_ERR("Error: cannot calculate numbers: " + std::string(e.what()));
			return 0;
		}
	}

	numeric_Type Math::Combination(numeric_Type n, numeric_Type k)
	{
		try
		{
			numeric_Type result = 1;

			for (numeric_Type i = 0; i < n; ++i)
			{
				result *= (n - i);
			}

			for (numeric_Type i = 1; i <= k; ++i)
			{
				result /= i;
			}

			return result;
		}
		catch (std::exception e)
		{
			PRINT_ERR("Error: cannot calculate numbers: " + std::string(e.what()));
			return 0;
		}
	}
}

#endif
