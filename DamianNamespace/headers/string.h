#ifndef DAMIAN_STRING_H
#define DAMIAN_STRING_H

#include <string>
#include <cstring> // strlen
#include <cctype> // tolower, toupper
#include <cstdarg> // va_list, va_start, va_end, va_arg
#include <algorithm> // find_if

#if __cplusplus >= 2017091L
#include <string_view>
#endif

namespace Damian
{
	class String
	{
	public:
		static size_t Length(const std::string& str);
#if __cplusplus >= 2017091L
		static size_t String::Length(const std::string_view& str);
#endif
		static size_t Length(const char* str);
		static char CharAt(const std::string& str, int index);
		static char CharAt(const char* str, int index);
		static void ToUpper(std::string& str);
		static void ToLower(std::string& str);
		static void Concat(std::string& str, int count, ...);
		static void Concat(std::string& str1, const std::string& str2);
		static int IndexOf(const std::string& str, char c);
		static int IndexOf(const std::string& str, const std::string& search);
		static void LeftTrim(std::string& str);
		static void RightTrim(std::string& str);
		static void Trim(std::string& str);
		static bool Contains(const std::string& mainStr, const std::string& str);
		static bool EndsWith(const std::string& mainStr, const std::string& str);
		static int Compare(const std::string& str1, const std::string& str2);
		static bool Equals(const std::string& str1, const std::string& str2);
	};

	size_t String::Length(const std::string& str)
	{
		return static_cast<size_t>(str.size());
	}

#if __cplusplus >= 2017091L
	size_t String::Length(const std::string_view& str)
	{
		return static_cast<size_t>(str);
	}
#endif

	size_t String::Length(const char* str)
	{
		return static_cast<size_t>(std::strlen(str));
	}

	char String::CharAt(const std::string& str, int index)
	{
		char tempChar = '\0';
		if(index < static_cast<int>(str.size()) && index > 0)
		{
			tempChar = static_cast<char>(str.at(index));
		}

		return tempChar;
	}

	char String::CharAt(const char* str, int index)
	{
		if(index < static_cast<int>(std::strlen(str)) && index > 0)
		{
			for(size_t i = 0; i < std::strlen(str); i++)
			{
				if(str[i] == str[index])
				{
					return str[index];
				}
			}
		}

		return '\0';
	}

	void String::ToUpper(std::string& str)
	{
		for(size_t i = 0; i < str.size(); i++)
		{
			str.at(i) = std::toupper(str.at(i));
		}
	}

	void String::ToLower(std::string& str)
	{
		for(size_t i = 0; i < str.size(); i++)
		{
			str.at(i) = std::tolower(str.at(i));
		}
	}

	void String::Concat(std::string& str1, const std::string& str2)
	{
		str1 += str2;
	}

	void String::Concat(std::string& str, int count, ...)
	{
		std::string _temp = str;
		va_list strList;

		va_start(strList, count);
		for(int arg = 0; arg < count; ++arg)
		{
			_temp += va_arg(strList, std::string);
		}
		va_end(strList);

		str = _temp;
	}

	int String::IndexOf(const std::string& str, char c)
	{
		return static_cast<int>(str.find(c));
	}

	int String::IndexOf(const std::string& str, const std::string& search)
	{
		return static_cast<int>(str.find(search));
	}

	void String::LeftTrim(std::string& str)
	{
		str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) { return !std::isspace(ch); }));
	}

	void String::RightTrim(std::string& str)
	{
		str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), str.end());
	}

	void String::Trim(std::string& str)
	{
		RightTrim(str);
		LeftTrim(str);
	}

	bool String::Contains(const std::string& mainStr, const std::string& str)
	{
		return mainStr.find(str) != std::string::npos;
	}

	bool String::EndsWith(const std::string& mainStr, const std::string& str)
	{
		int index = static_cast<int>(mainStr.find(str));
		if(index != -1)
		{
			if(str.length() + index == mainStr.length())
				return true;
			else
				return false;
		}

		return false;
	}

	int String::Compare(const std::string& str1, const std::string& str2)
	{
		return str1.compare(str2);
	}

	bool String::Equals(const std::string& str1, const std::string& str2)
	{
		return Compare(str1, str2) == 0;
	}
}

#endif
