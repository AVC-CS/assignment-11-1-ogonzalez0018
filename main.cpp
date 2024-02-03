#include "main.hpp"

int main()
{
	vector<Person> person;
	int length;

	makePerson(person);
	cout << "The number of record is " << person.size() << endl;
	printPerson(person);
	sortPerson(person);
	printPerson(person);
}
