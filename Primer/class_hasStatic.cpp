//example of a class that has a static data member

#include <iostream>
#include <string>


class Employee
{
public:
	std::string name;
	int id;
	static int id_gen;

	Employee(std::string s) : name(s), id(Employee::id_gen++) {}

};

int Employee::id_gen = 1000000;

int main()
{
	Employee Bob("Bob");
	Employee Jill("Jill");

	std::cout << Bob.name << ": " << Bob.id << std::endl;
	std::cout << Jill.name << ": " << Jill.id << std::endl;

	return 0;
}
