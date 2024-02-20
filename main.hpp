#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
struct Name
{
    string first;
    string last;
};
struct Bdate
{
    int year;
    int month;
    int day;
};
struct Person
{
    int no;
    string ID;
    Name name;
    string email;
    string gender;
    string phone;
    Bdate bdate;
    string jobtitle;
};

void makePerson(vector<Person> &);
void printPerson(vector<Person>);
void sortPerson(vector<Person> &);

void makePerson(vector<Person> &person)
{
  ifstream ifs;
  string line, buf;
  stringstream ss;
  Person p;
  int fcnt = 0;
  ifs.open("people-100.csv.10");
  if (!ifs) {
    cerr << "Error: file open error" << endl;
    exit(0);
  }
  while (getline(ifs, line)) {
    ss << line;
    fcnt = 0;
    while (getline(ss, buf, ',')) {
      switch(fcnt)
        {
          case 0:
            p.no = stoi(buf);
            break;
          case 1:
            p.ID = buf;
            break;
          case 2:
            p.name.first = buf;
            break;
          case 3:
            p.name.last = buf;
            break;
          case 4:
            p.gender = buf;
            break;
          case 5:
            p.email = buf;
            break;
          case 6:
            p.phone = buf;
            break;
          case 7:
            p.bdate.year = stoi(buf.substr(0, 4));
            p.bdate.month = stoi(buf.substr(5, 2));
            p.bdate.day = stoi(buf.substr(8, 2));
            break;
          case 8:
            p.jobtitle = buf;
            ss.str("");
            ss.clear();
            break;
          default:
            cerr << "Field count error" << endl;
        }
        fcnt++;
    }
    person.push_back(p);
    ss.clear();
  }
}
void printPerson(vector<Person> person)
{
    vector<Person>::iterator it;
    printf("NO\tID\t\tName\t\t\tEmail\t\tPhone\t\t\tBirthday\t\t\t\tJobtitle\n");
    for (it = person.begin(); it != person.end(); it++)
    {
        cout << it->no << "\t";
        cout << it->ID << "\t";
        cout << it->name.first << " " << it->name.last << "\t";
        cout << it->email << "\t";
        cout << it->phone << "\t";
        cout << it->bdate.year << "\t"
             << it->bdate.month << "\t"
             << it->bdate.day << "\t";
        cout << it->jobtitle << endl;
    }
    cout << "**************************************************\n";
}
void sortPerson(vector<Person> &person)
{
  // Sort by Last name 
  for(int i=0;i<person.size()-1;i++)
    {
      for(int j=0;j<person.size()-i-1;j++)
        {
          if(person[j].name.last>person[j+1].name.last)
            swap(person[j],person[j+1]);
    
        }
    }
/*******************************
 * Code your program here
*******************************/
}
