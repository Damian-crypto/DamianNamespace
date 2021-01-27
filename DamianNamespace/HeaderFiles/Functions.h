#pragma once

#ifndef DAMIAN_FUNCTIONS_H
#define DAMIAN_FUNCTIONS_H

#include "String.h"
#include "Timer.h"
#include "Commons.h"

#include <cstdarg>
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

namespace Damian
{
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

	/* Convert int to char
	 */
	char ToChar(int chr)
	{
		return static_cast<char>(chr);
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
		T sum = 0;
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

	/* List(count, objects...) function creates a std::vector<type>
	 * quickly as possible
	 */
	template<typename T>
	std::vector<T> List(int count = 10, ...)
	{
		T start;
		std::vector<T> _tempVec{ count };
		va_list list;
		va_start(list, start);
		for (int i = 0; i < count; ++i)
		{
			_tempVec.push_back(va_arg(i, T));
		}
		va_end(list);

		return _tempVec;
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

	/* Getting data from C++ standard input stream
	 * and return it. Print message to console if provided
	 */
	template<typename OutputType = std::string>
	OutputType Input(const char* msg = nullptr)
	{
		if (msg != nullptr)
			std::cout << msg;

		OutputType _temp = 0;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			PRINT_ERR("Error::something went wrong with input stream!");
		}
		else
		{
			std::cin >> _temp;
		}
		return _temp;
	}

	/* Print function for normal objects
	 */
	template<typename T>
	void Print(const T& obj)
	{
		std::cout << std::boolalpha << obj << line_delim;
	}

	/* Print function for strings only
	 */
	void Print(const char* str1, const char* str2 = "", const char* str3 = "",
		const char* str4 = "", const char* str5 = "", const char* str6 = "",
		const char* str7 = "", const char* str8 = "", const char* str9 = "",
		const char* str10 = "")
	{
		if (std::strlen(str1) > 0)
			std::cout << str1;
		if (std::strlen(str2) > 0)
			std::cout << " " << str2;
		if (std::strlen(str3) > 0)
			std::cout << " " << str3;
		if (std::strlen(str4) > 0)
			std::cout << " " << str4;
		if (std::strlen(str5) > 0)
			std::cout << " " << str5;
		if (std::strlen(str6) > 0)
			std::cout << " " << str6;
		if (std::strlen(str7) > 0)
			std::cout << " " << str7;
		if (std::strlen(str8) > 0)
			std::cout << " " << str8;
		if (std::strlen(str9) > 0)
			std::cout << " " << str9;
		if (std::strlen(str10) > 0)
			std::cout << " " << str10;
	}

	/* Print function for formatted strings
	 */
	void PrintF(const std::string& decoder, ...)
	{
		if (decoder.empty() || decoder.size() == 0)
		{
			PRINT_ERR("ERROR::decoder cannot be empty or null");
			return;
		}

		std::stringstream stringStream;

		va_list list;
		va_start(list, decoder);
		int count = 0;
		int decoderLength = static_cast<int>(decoder.length());

		while (true)
		{
			char codeType = (count < decoderLength) ? decoder.at(count) : '\0';
			switch (codeType)
			{
			default:
			case '\0':
				va_end(list); // clear the list
				Print(stringStream.str());
				return;

			case 'i':
				stringStream << va_arg(list, int);
				count++;
				break;
			case 'd':
				stringStream << va_arg(list, double);
				count++;
				break;
			case 's':
				stringStream << va_arg(list, const char*);
				count++;
				break;
			}
		}
	}

	/* void Print(int count = 0, T* arr = nullptr)
	 * count - elements count in arr
	 * arr - elements holder
	 * Print function for arrays
	 */
	template<typename T = const char*>
	void Print(int count = 0, T* arr = nullptr)
	{
		D_ASSERT(count == 0, "ERROR::array size could not be 0");
		D_ASSERT(arr == nullptr, "ERROR::array could not be null");

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
