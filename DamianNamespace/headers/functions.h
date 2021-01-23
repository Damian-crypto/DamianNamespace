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

#define VERSION_OK __cplusplus >= 201103L || __cplusplus >= 199711L

#if VERSION_OK
#include <array>
#endif

#if VERSION_OK && __cplusplus > 199711L
#define RANGES_OK
#include <ranges>
#endif

#include "string.h"
#include "timer.h"

namespace Damian
{
#if OS_VERSION == windows
	constexpr char line_delim = '\n';
#elif OS_VERSION == linux
	constexpr char line_delim = '\r';
#endif

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

	template<typename T>
	void Print(const T& obj);

	/* bool IsNumber(T object)
	 * function used to chech whether an object is a number or not
	 * return true if object is a number otherwise false
	 */
	template<typename T>
	bool IsNumber(T obj)
	{
#if 0
		std::string temp_Str = static_cast<std::string>(obj);

		return !temp_Str.empty() && std::find_if(temp_Str.begin(), temp_Str.end(),
			[](unsigned char c) { return !std::isdigit(c); }) == temp_Str.end();
#endif
		return 0;
	}

	/* Return sum of all objects in the vector
	 */
	template<typename T>
	T Sum(const std::vector<T>& arr)
	{
#if RANGES_OK
		return std::ranges::accumulate(arr, 0.0);
#else
		return std::accumulate(arr.begin(), arr.end(), 0.0);
#endif
	}

	/* Return sum of all objects in the array
	 */
	template<typename T, size_t size>
	T Sum(const std::array<T, size>& arr)
	{
#if RANGES_OK
		return std::ranges::accumulate(arr, 0.0);
#else
		return std::accumulate(arr.begin(), arr.end(), 0.0);
#endif
	}

	/* Return sum of all objects in the arr
	 */
	template<typename T>
	T Sum(int count, T* arr)
	{
		T sum = 0.0;
		for(int i = 0; i < count; i++)
		{
			sum += arr[i];
		}

		return sum;
	}


	template<typename T>
	void Sort(std::vector<T>& arr)
	{
#if RANGES_OK
		std::ranges::sort(arr);
#else
		std::sort(arr.begin(), arr.end());
#endif
	}

	template<typename T, size_t size>
	void Sort(std::array<T, size>& arr)
	{
#if RANGES_OK
		return std::ranges::sort(arr);
#else
		return std::sort(arr.begin(), arr.end());
#endif
	}

	/* Sorting generic array by non-optimized algorithm
	 * Do not use for production
	 */
	template<typename T>
	void Sort(int count = 0, T* arr = nullptr)
	{
		/*std::function<bool(T, T)> comparison = [](T val1, T val2) { return val1 < val2; };
		if(IsNumber(arr[0]))
			comparison = [](T val1, T val2) { return val1 < val2; };
		else
		{
			comparison = [](T val1, T val2) {
				if(!std::is_base_of<std::string, T>::value)
				{
					return String::Compare(std::to_string(val1), std::to_string(val2)) < 0;
				} else {
					return val1.compare(val2);
				}
			};
		}

		for(int startIndex = 0; startIndex < count - 1; ++startIndex)
		{
			int smallIndex = startIndex;
			for(int currentIndex = startIndex + 1; currentIndex < count; ++currentIndex)
			{
				if(comparison(arr[startIndex], arr[currentIndex]))
				{
					smallIndex = currentIndex;
				}
			}

			std::swap(arr[startIndex], arr[smallIndex]);
		}*/
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
		assert(count != 0 && "Array size could not be 0");
		assert(arr != nullptr && "Array could not be null");

		std::cout << "{ ";
		for(int i = 0; i < count; ++i)
		{
			std::cout << *(arr + i);
			if(i < count - 1)
				std::cout << ", ";
		}
		std::cout << " }" << line_delim;
	}
}

#endif