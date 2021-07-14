//Cheryl Tollola
//8317298
#include "Person.h"


Organization::Organization(std::string n) {
    name = n;
};


Organization::~Organization()
{
   members.clear();
}

void Organization::addMember(std::pair<std::string, Person *> person)
{
    members.insert(person);
}

void Organization::removePerson(Person* person)
{
    std::string key = "";
    std::map<std::string, Person*>::iterator it = members.begin();
    for (it=members.begin(); it!=members.end(); ++it)
    {
        if (it->second == person) {
            key = it->first;
        }
    }
    
    if (!key.empty()) {
        members.erase(key);
    } else {
        cout << "Cannot find " << person->getName() <<  " in the organization, " << name << endl;
    }

}

string Organization::getMemberNames()
{
    std::string name = "";
    
    std::map<std::string, Person*>::iterator it = members.begin();
    for (it=members.begin(); it!=members.end(); ++it)
    {
        name = name + it->second->getName() + ", ";
    }

    return name;
}


int Organization::getSize() const {
    return members.size();
}


string Organization::getName() { return name; }



