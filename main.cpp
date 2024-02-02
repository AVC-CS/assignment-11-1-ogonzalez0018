#include "main.hpp"

int main()
{
	vector<Person> person;
	int length;

	length = makeStruct(person);
	cout << "The number of record is " << length << endl;
	printPerson(person);
}
