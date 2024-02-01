#include "main.hpp"

int main()
{
	struct Person person[200];
	int length;

	length = makeStruct(person);
	cout << "The number of record is " << length << endl;
}
