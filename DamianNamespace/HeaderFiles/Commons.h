#pragma once

#include <iostream>

#if OS_VERSION == windows
constexpr char line_delim = '\n';
#elif OS_VERSION == linux
constexpr char line_delim = '\r';
#endif

#define D_ASSERT(condition, msg) if(condition)\
	std::cerr << line_delim << "[" << __FILE__ << ":" << __LINE__ << "]" << msg << line_delim << std::endl

#define PRINT_ERR(msg) D_ASSERT(true, msg)