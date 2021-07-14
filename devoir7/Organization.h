#ifndef OrganizationH
#define OrganizationH 

#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
//Cheryl Tollola
//8317298

using namespace std;
class Person;

class Organization {
    string name;
    multimap<string, Person *> members;

public:

    Organization(string n = "default");
    virtual ~Organization();
    void addMember(pair<string, Person *> person);
    void removePerson(Person* members);
    string getMemberNames();
    string getName();
    int getSize() const;


};

#endif 