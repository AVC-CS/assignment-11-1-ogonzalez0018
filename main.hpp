#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
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

int makeStruct(vector<Person>);
void printPerson(vector<Person>);

int makeStruct(vector<Person> person)
{
    string line, buf;
    Person p;
    char delimiter = ',';
    ifstream ifs;
    stringstream ss;
    int fcnt, tmp;
    ifs.open("people-100.csv");
    if (!ifs)
    {
        cerr << "File Open Error\n";
        exit(0);
    }
    while (ifs >> line)
    {
        cout << "this is line " << line << endl;
        ss.str("");
        ss.flush();
        ss.clear();
        ss << line;
        fcnt = 0;
        while (getline(ss, buf, delimiter))
        {
            cout << " This is buf from ss " << buf << endl;
            cout << "field work " << fcnt << "buf " << buf << endl;
            switch (fcnt)
            {
            case 0:
                p.no = stoi(buf);
                cout << " case 0 pno " << p.no << endl;
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
                p.bdate.year = stoi(buf.substr(0, 3));
                p.bdate.month = stoi(buf.substr(5, 2));
                p.bdate.day = stoi(buf.substr(8, 2));
                break;
            case 8:
                p.jobtitle = buf;
                ss.str("");
                break;
            default:
                cout << "Error happend while parsing\n";
            }
            fcnt++;
        }
        cout << " Line  " << p.no << endl;
        person.push_back(p);
    }

    return person.size();
}
void printPerson(vector<Person> person)
{
    // vector<Person>::iterator it;
    // for (it = person.begin(); it != person.end(); it++)
    for (int i = 0; i < person.size(); i++)
    {
        cout << "No: " << person[i].no << "\t";
        cout << "ID: " << person[i].ID << "\t";
        // cout << "Name: " << it.name.first << " " << v.name.last << "\t";
        // cout << "Name: " << it.name.first << " " << v.name.last << "\t";
        // cout << "Email " << *it.email << "\t";
        // cout << "Phone " << *it.phone << "\t";
        // cout << "Birthday " << v.bdate.year << "\t"
        //      << v.bdate.month << "\t"
        //      << v.bdate.day << "\t";
        // cout << "Job Title " << v.jobtitle << endl;
    }
}
/*******************************
 * Code your program here
 *******************************/