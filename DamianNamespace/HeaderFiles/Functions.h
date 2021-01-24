#pragma once

#ifndef DAMIAN_FUNCTIONS_H
#define DAMIAN_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cassert>
#include <functional>
#include <cctype>
#include <type_traits>
#include <array>
#include <sstream>

#include "String.h"
#include "Timer.h"

namespace Damian
{
#if OS_VERSION == windows
	constexpr char line_delim = '\n';
#elif OS_VERSION == linux
	constexpr char line_delim = '\r';
#endif

#define D_ASSERT(condition, msg) if(condition)\
	std::cerr << line_delim << msg << line_delim << std::endl

#define PRINT_ERR(msg) D_ASSERT(true, msg)

	/* Convert generic type to C++ standard string type
	 * bit explain: this is done by using stringstreams
	 */
	template<typename T>
	std::string ToString(const T& value)
	{
		std::ostringstream output;
		output << value;
		return output.str();
	}

	/* Convert generic type to integer type
	 */
	template<typename T>
	int ToInt(const T& value)
	{
		return std::atoi(ToString(value).c_str());
	}

	/* Convert generic type to double type
	 */
	template<typename T>
	double ToDouble(const T& value)
	{
		return std::atof(ToString(value).c_str());
	}

	/* Convert generic type to floating point type
	 */
	template<typename T>
	float ToFloat(const T& value)
	{
		return static_cast<float>(std::atof(ToString(value).c_str()));
	}

	/* Convert generic type to long type
	 */
	template<typename T>
	long ToLong(const T& value)
	{
		return std::atol(ToString(value).c_str());
	}

	/* bool InstanceOf(const T* object)
	 * function used to check whether object's base(parent) class is Base type
	 * returns true if object is derived from Base otherwise false
	 * e.g: InstanceOf<std::string>(object) <- returns true if object is a std::string
	 */
	template<typename Base = std::string, typename T>
	inline bool InstanceOf(const T& obj)
	{
		return std::is_base_of<Base, T>::value; // T is a pointer
	}

	// Forward declaration of Print() function
	template<typename T>
	void Print(const T& obj);

	/* bool IsNumber(T object)
	 * function used to chech whether an object is a number or not
	 * return true if object is a number otherwise false
	 */
	template<typename T>
	bool IsNumber(T obj)
	{
		std::string temp_Str(ToString(obj));

		return !temp_Str.empty() && std::find_if(temp_Str.begin(), temp_Str.end(),
			[](unsigned char c) { return !std::isdigit(c); }) == temp_Str.end();
	}

	/* Return sum of all objects in the vector
	 */
	template<typename T>
	T Sum(const std::vector<T>& arr)
	{
		return std::accumulate(arr.begin(), arr.end(), 0.0);
	}

	/* Return sum of all objects in the array
	 */
	template<typename T, size_t size>
	T Sum(const std::array<T, size>& arr)
	{
		return std::accumulate(arr.begin(), arr.end(), 0.0);
	}

	/* Return sum of all objects in the arr
	 */
	template<typename T>
	T Sum(int count, T* arr)
	{
		T sum = 0.0;
		for (int i = 0; i < count; i++)
		{
			sum += arr[i];
		}

		return sum;
	}

	/* Sort the entire vector with the specified type
	 */
	template<typename T>
	void Sort(std::vector<T>& arr)
	{
		std::sort(arr.begin(), arr.end());
	}

	/* Sort the entire array with the specified type
	 */
	template<typename T, size_t size>
	void Sort(std::array<T, size>& arr)
	{
		return std::sort(arr.begin(), arr.end());
	}

	/* Sorting generic array by non-optimized algorithm
	 * Do not use for production
	 */
	template<typename T>
	void Sort(int count = 0, T* arr = nullptr)
	{
		std::function<bool(T, T)> comparison = [](T val1, T val2) { return val1 < val2; };
		if (!IsNumber(arr[0]))
			comparison = [](T val1, T val2) { return String::Compare(ToString(val1), ToString(val2)) > 0; };

		for (int startIndex = 0; startIndex < count - 1; ++startIndex)
		{
			int smallIndex = startIndex;
			for (int currentIndex = startIndex + 1; currentIndex < count; ++currentIndex)
			{
				if (comparison(arr[startIndex], arr[currentIndex]))
				{
					smallIndex = currentIndex;
				}
			}

			std::swap(arr[startIndex], arr[smallIndex]);
		}
	}

	/* Returns default name of the type specified
	 * eg:
	 * int[] arr = { 1, 2, 3 };
	 * const char* typeName = Type(arr);
	 * this will return typeName = "Pi"
	 */
	template<typename T>
	const char* Type(T type)
	{
		return static_cast<const char*>(typeid(type).name());
	}

	/* Print function for normal objects
	 */
	template<typename T>
	void Print(const T& obj)
	{
		std::cout << std::boolalpha << obj << line_delim;
	}

	/* void Print(int count = 0, T* arr = nullptr)
	 * count - elements count in arr
	 * arr - elements holder
	 * Print function for arrays
	 */
	template<typename T>
	void Print(int count = 0, T* arr = nullptr)
	{
		D_ASSERT(count == 0, "ERROR::Array size could not be 0");
		D_ASSERT(arr == nullptr, "ERROR::Array could not be null");

		std::cout << "{ ";
		for (int i = 0; i < count; ++i)
		{
			std::cout << *(arr + i);
			if (i < count - 1)
				std::cout << ", ";
		}
		std::cout << " }" << line_delim;
	}
}

#endif