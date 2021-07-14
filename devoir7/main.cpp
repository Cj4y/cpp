#include "Person.h"
#include "OrganizationPayante.h"
//Cheryl Tollola
//8317298

//ajoute une personne a une organisation et une organisation a une personne 
void inscription(std::pair<string, Organization *> o, std::pair<string, Person *> p) {


    p.second->addOrganization(o);
    o.second->addMember(p);
}

void withdraw(Organization* o, Person* p)
{
    p->removeOrganization(o);
    o->removePerson(p);
}


//imprime le nom de la personne, le nombre d'organisations de la personne et la liste de nom des organisations de la personne 
void printMembers(Person* person)
{

    cout << person->getName() << " is part of " << person->getSize() << " organisations: " << endl;
    cout << person->getOrgNames() << endl;

}

void printOrganization(Organization* organization)
{

    cout << organization->getName() << " has " << organization->getSize() << " members: " << endl;
    cout << organization->getMemberNames() << endl;

}



//main: to test program 
int main() {

    Organization* o0 = new Organization("Math");
    pair<string , Organization*> org_pair_0("org_0", o0);
    Organization* o1 = new Organization("Test");
    pair<string , Organization*> org_pair_1("org_1" , o1);
    Organization* o2 = new Organization("UofT");
    pair<string , Organization*> org_pair_2("org_2" , o2);
    Organization* o3 = new Organization("UofO");
    pair<string , Organization* > org_pair_3("org_3" , o3);
    Organization* o4 = new Organization("Microsoft");
    pair<string , Organization*> org_pair_4("org_4" , o4);
    Organization* o5 = new Organization("Google");
    pair<string , Organization*> org_pair_5("org_5" , o5);

    OrganizationPayante* o6 = new OrganizationPayante("Subway");
    pair<string , Organization*> org_pair_6("org_6" , o6);
    OrganizationPayante* o7 = new OrganizationPayante("DND");
    pair<string , Organization*> org_pair_7("org_7" , o7);
    o6->setFrais(10);
    o7->setFrais(30);

    Person* p1 = new Person("Joe");
    pair<string, Person*> person_pair_1("person_1", p1);
    Person* p2 = new Person("John");
    pair<string, Person*> person_pair_2("person_2", p2);

    inscription(org_pair_0, person_pair_1);
    inscription(org_pair_1, person_pair_1);
    inscription(org_pair_2, person_pair_1);
    inscription(org_pair_3, person_pair_1);
    inscription(org_pair_6, person_pair_1);
    inscription(org_pair_5, person_pair_1); 

    inscription(org_pair_1, person_pair_2);
    inscription(org_pair_6, person_pair_2);
    inscription(org_pair_7, person_pair_2);
    inscription(org_pair_2, person_pair_2);


    printMembers(p1);
    cout << "Paying Organization: \n" << p1->printAPayer() << endl;
    cout << "With annual fees of " << p1->getAPayer() << " $" << endl << endl;

    cout << endl;
    withdraw(o2, p1);
    withdraw(o7, p1); // This should output an error message as p1 is not a member of o7

    cout << "----------------------------------------------------------------" << endl;
    printMembers(p1);
    cout << "Paying Organization: \n" << p1->printAPayer() << endl;
    cout << "With annual fees of " << p1->getAPayer() << " $" << endl << endl;

    cout << "----------------------------------------------------------------" << endl;
    printMembers(p2);
    cout << "Paying Organization: \n" << p2->printAPayer() << endl;
    cout << "With annual fees of " << p2->getAPayer() << " $" << endl << endl;


    cout << "----------------------------------------------------------------" << endl;
    printOrganization(o6);
    cout << endl;
    printOrganization(o2);



    return 0;

}