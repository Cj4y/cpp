
#include "Person.h"
#include "OrganizationPayante.h"
//Cheryl Tollola
//8317298

Person::Person(std::string n, int a) {
    name = n;
    age = a;
};

Person::~Person()
{
    organizations.clear();
}

void Person::addOrganization(std::pair<std::string, Organization*> organization)
{
   organizations.insert(organization);
}

void Person::removeOrganization(Organization* organization)
{

    std::string key = "";
    std::map<std::string, Organization*>::iterator it = organizations.begin();
    for (it=organizations.begin(); it!=organizations.end(); ++it)
    {
        if (it->second == organization) {
            key = it->first;
        }
    }
    
    if (!key.empty()){
        organizations.erase(key);
    } else {
        cout << name << " has no member" << organization->getName();
    }
}


std::string Person::getName() { return name; }


int Person::getSize() const {
    return organizations.size();
}


string Person::getOrgNames()
{
    std::string name = "";
    
    std::map<std::string, Organization*>::iterator it = organizations.begin();
    for (it=organizations.begin(); it!=organizations.end(); ++it)
    {
        name = name + it->second->getName() + ", ";
    }
    return name;
}

float Person::getAPayer() {
    float total = 0;
    
    std::map<std::string, Organization*>::iterator it = organizations.begin();
    for (it=organizations.begin(); it!=organizations.end(); ++it)
    {
        OrganizationPayante* op = dynamic_cast<OrganizationPayante*>(it->second);

        if (op != nullptr) {
            total += op->getFrais();
        }
    }
    return total;
}

string Person::printAPayer() {
    string name = "";

    std::map<std::string, Organization*>::iterator it = organizations.begin();
    for (it=organizations.begin(); it!=organizations.end(); ++it)
    {
        OrganizationPayante* op = dynamic_cast<OrganizationPayante*>(it->second);

        if (op != nullptr) {
            name = name + op->getName() + ": " + to_string(op->getFrais()) + "; ";

        }
    }
    return name;

}



