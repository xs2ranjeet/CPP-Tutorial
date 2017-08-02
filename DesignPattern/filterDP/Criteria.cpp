#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
private:
	string name;
	string gender;
	string maritialStatus;
public:
	Person(string name, string gender, string ma):name(name), gender(gender),maritialStatus(ma){}
	string getName(){ return this->name;}
	string getGender(){ return this->gender;}
	string getMartialStatus(){ return this->maritialStatus;}
	bool operator==(Person p){
		if(this->name.compare(p.getName())==0 &&
			this->gender.compare(p.getGender()) == 0 &&
			this->maritialStatus.compare(p.getMartialStatus()) == 0)
			return true;
		else
			return false;
	}
};

class Criteria {
public:
	virtual std::vector<Person *> *meetCriteria(std::vector<Person *> *person) = 0;
};
class CriteriaMale: public Criteria
{
public:
	std::vector<Person *> *meetCriteria(std::vector<Person *> *persons) {
		std::vector<Person *> *malePerson = new std::vector<Person*>();
		for(int i = 0; i < persons->size(); i++) {
		//for (Person person: persons){
			Person *person = persons->at(i);
			if(person->getGender().compare("male") == 0)
				malePerson->push_back(person);
		}
		return malePerson;
	}
};
class CriteriaFeMale: public Criteria
{
public:
	std::vector<Person *> *meetCriteria(std::vector<Person *> *persons) {
		std::vector<Person *> *femalePerson = new std::vector<Person *>();
		for(int i = 0; i < persons->size(); i++) {
		//for (Person person: persons){
			Person *person = persons->at(i);
			if(person->getGender().compare("female") == 0)
				femalePerson->push_back(person);
		}
		return femalePerson;
	}
};
class CriteriaSingle: public Criteria
{
public:
	std::vector<Person *> *meetCriteria(std::vector<Person *> *persons) {
		std::vector<Person *> *singlePersons = new std::vector<Person *>();
		for(int i = 0; i < persons->size(); i++) {
		//for (Person person: persons){
			Person *person = persons->at(i);
			if(person->getMartialStatus().compare("single") == 0)
				singlePersons->push_back(person);
		}
		return singlePersons;
	}
};
class AndCriteria: public Criteria
{
private:
	Criteria *crieria;
	Criteria *otherCriteria;
public:
	AndCriteria(Criteria *crieria, Criteria *otherCriteria){
		this->crieria = crieria;
		this->otherCriteria = otherCriteria;
	}
	std::vector<Person *> *meetCriteria(std::vector<Person *> *persons) {
		std::vector<Person *> *firstCriteriaPerson = crieria->meetCriteria(persons);
		return otherCriteria->meetCriteria(firstCriteriaPerson);
	}
};
class OrCriteria : public Criteria
{
private:
	Criteria *crieria;
	Criteria *otherCriteria;
public:
	OrCriteria(Criteria *crieria, Criteria *otherCriteria){
		this->crieria = crieria;
		this->otherCriteria = otherCriteria;
	}
	std::vector<Person *> *meetCriteria(std::vector<Person *> *persons){
		std::vector<Person *> *firstCriteriaItems = crieria->meetCriteria(persons);
		std::vector<Person *> *otherCriteriaItems = otherCriteria->meetCriteria(persons);
		for(int i = 0; i < otherCriteriaItems->size(); i++) {
		//for (Person person: persons){
			Person *person = persons->at(i);
			if(std::find(persons->begin(), persons->end(), person) != persons->end() == false)
			//if(!firstCriteriaItems.contains(person))
				firstCriteriaItems->push_back(person);
		}
		return firstCriteriaItems;
	} 
};

void printPersons(std::vector<Person *> *persons){
		for(int i = 0; i < persons->size(); i++) {
		//for (Person person: persons){
			Person *person = persons->at(i);
			cout<<"Person: [Name: "<<person->getName() <<", Gender: "<<person->getGender() <<",MaritialStatus: "<< person->getMartialStatus()<<endl;
	}
}
int main(int argc, char const *argv[])
{
	std::vector<Person *> *persons = new std::vector<Person *> ();
	persons->push_back(new Person("Robert","male","single"));
	persons->push_back(new Person("John","male","married"));
	persons->push_back(new Person("Laura","female","married"));
	persons->push_back(new Person("Diana","female","single"));
	persons->push_back(new Person("Mika","male","single"));
	persons->push_back(new Person("Bobby","male","single"));

	Criteria *male = new CriteriaMale();
	Criteria *female = new CriteriaFeMale();
	Criteria *single = new CriteriaSingle();
	Criteria *singleMale = new AndCriteria(single, male);
	Criteria *singleOrFemale = new OrCriteria(single, female);

	cout<<"Males:............\n";
	printPersons(male->meetCriteria(persons));

	cout<<"Females:............\n";
	printPersons(female->meetCriteria(persons));
	
	cout<<"Single Males:............\n";
	printPersons(singleMale->meetCriteria(persons));
	
	cout<<"Single Or Females:............\n";
	printPersons(singleOrFemale->meetCriteria(persons));

	return 0;
}