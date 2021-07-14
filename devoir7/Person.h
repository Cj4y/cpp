#ifndef Person_H_
#define Person_H_
#include "Organization.h"
//Cheryl Tollola
//8317298

class Person {

    string name;
    int age;
    map<std::string, Organization*> organizations;

public:

    Person(std::string n = "default", int a = rand() % 30 + 16);
    ~Person();
    void addOrganization(std::pair<std::string, Organization*> organization);
    void removeOrganization(Organization* organization);
    float getAPayer();
    string printAPayer();
    string getOrgNames();
    int getSize() const;
    std::string getName();
};


#endif 