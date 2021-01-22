#include "../toolkit.h"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <typeinfo>
#include <array>

using namespace Damian;

int main()
{
	std::cout << __cplusplus << typeid(__cplusplus).name() << '\n';
	std::cout << Math::GetGCD(54, 24) << '\n';
	std::cout << Math::GetLCM(12, 24) << '\n';
	std::cout << String::Length("Hello, World!") << '\n';
	std::string name = "Damian";
	std::cout << String::CharAt(name, 3) << '\n';
	std::cout << String::CharAt(name.c_str(), 2) << '\n';
	String::ToUpper(name);
	std::cout << name << '\n';
	String::ToLower(name);
	std::cout << name << '\n';
	std::string n1 = " Chamel";
	std::string n2 = " Rodrigo";
	String::Concat(name, 2, n1, n2);
	std::cout << name << '\n';
	String::Concat(name, " Hello!");
	std::cout << name << '\n';
	std::cout << String::Contains(name, "Chamel") << '\n';
	std::cout << String::Contains(name, "Falcon") << '\n';

	std::vector<double> arr { 2.3, 4.5, 5.6, 1.2 };
	std::cout << Sum<double>(arr) << '\n';

	std::string fullName = "Damian Chamel Rodrigo";
	std::cout << String::EndsWith(fullName, "Rodrigo") << '\n';
	std::cout << String::EndsWith(fullName, "Chamel ") << '\n';

	std::string name1 = "Damian";
	std::string name2 = "Damian";
	std::cout << String::Compare(name1, name2) <<  '\n';
	std::cout << String::Equals(name1, name2) <<  '\n';
	std::cout << String::IndexOf(name1, "mian") <<  '\n';
	Print("Hello, World !");

	std::cout << typeid(int).name() << '\n';
	std::cout << Math::GetGCD(54.5, 24.9) << '\n';

	int myArr[] = { 12, 27, 3, 400, 5 };
	std::cout << Sum(5, myArr) << '\n';

	std::array<double, 3> arr1 = { 3.14, 5.6, 2.7 };
	std::array<int, 5> arr2 = { 1, 2, 3, 4, 5 };
	std::cout << Sum<double, 3>(arr1) << '\n';
// Sorting error
	Print(Type(myArr));
	Print(Type(arr1));
	Print(Type(arr2));
	Print(5, myArr);
	Sort(5, myArr);
	Print(5, myArr); 

	std::string strArr[] = { "Damian", "Chamel", "Zigma" };
	Print(3, strArr);
	Sort(3, strArr);
	Print(3, strArr);
	Print(Type(std::string("H")));
	Print(IsNumber(1234));
	Print(IsNumber("Hello"));
	Print(InstanceOf(name1));
	Print(Type("Hello"));

	return 0;
}
