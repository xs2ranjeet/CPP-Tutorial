#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
class Employee
{
private:
	string name;
	string dept;
	int salary;
	std::list<Employee *> *subordinate; 
public:
	Employee(string name, string dept, int sal):name(name), dept(dept), salary(sal) {
		this->subordinate = new std::list<Employee *>();
	}
	void add( Employee *e){
		subordinate->push_back(e);
	}
	void remove(Employee *e){
		//subordinate->remove(e);
	}
	std::list<Employee *> *getSubordinates(){
		return this->subordinate;
	}
	string toString(){
		return ("Employee : [Name: "+name+", Dept: "+ dept+", Salary: " +std::to_string(salary)+" ]\n");
	}
	~Employee(){
		/*for(int i = 0; i < subordinate->size(); i++)
			delete subordinate->at(i);
		delete name;
		delete dept;
		delete subordinate;*/
	}
	
};
int main(int argc, char const *argv[])
{
	Employee *CEO = new Employee("John","CEO", 30000);
	Employee *headSales = new Employee("Robert","Head Sales", 20000);

      Employee *headMarketing = new Employee("Michel","Head Marketing", 20000);

      Employee *clerk1 = new Employee("Laura","Marketing", 10000);
      Employee *clerk2 = new Employee("Bob","Marketing", 10000);

      Employee *salesExecutive1 = new Employee("Richard","Sales", 10000);
      Employee *salesExecutive2 = new Employee("Rob","Sales", 10000);

      CEO->add(headSales);
      CEO->add(headMarketing);

      headSales->add(salesExecutive1);
      headSales->add(salesExecutive2);

      headMarketing->add(clerk1);
      headMarketing->add(clerk2);

      //print all employees of the organization
      std::cout<< CEO->toString()<<std::endl; 
      
	  std::list<Employee *>::iterator it = CEO->getSubordinates()->begin();
	  for(it = CEO->getSubordinates()->begin(); it != CEO->getSubordinates()->end();  it++)
	  {
	   		std::cout<< (*it)->toString();
	   		std::list<Employee *>::iterator it1 = (*it)->getSubordinates()->begin();
	   		for(it1 = (*it)->getSubordinates()->begin(); it1 != (*it)->getSubordinates()->end();  it1++)
	   			std::cout<< (*it1)->toString();
	   		std::cout<<std::endl;
	   //   for (Employee *headEmployee : CEO->getSubordinates()) {
         //std::cout<< headEmployee->toString();
         
        // for (Employee *employee : headEmployee->getSubordinates()) {
        //    std::cout<< employee->toString();
        // }
      }		
	return 0;
}