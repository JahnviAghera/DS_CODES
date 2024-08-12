#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
    int empID;
    string name;
    char gender;
    double salary;

    public:
    //default constructor
    Employee(int id, string n, char g, double s):empID(id),name(n),gender(g),salary(s) {}

    //Getters
    int getEmpId() const {return empID;}
    string getName() const {return name;}
    char getGender() const {return gender;}
    double getSalary() const {return salary;}

    //Setter for Salary
    void setSalary(double s) {salary = s;}

    //Display Employee Details
    void display() const {
        cout<<"ID: "<< empID <<", Name: "<< name <<", Gender:"<<gender<<", Salary: "<<salary<<endl;
    }
};

//Update salary of employees
void updateSalary(Employee &emp, double newsalary){
    emp.setSalary(newsalary);
}

int main(){
    Employee employees[10] = {
        {1,"John",'M',50000},
        {2,"Jane",'F',60000},
        {3,"Jim",'M',70000},
        {4,"Jill",'F',80000},
        {5,"Jack",'M',90000},
        {6,"Jenny",'F',100000},
        {7,"Joe",'M',110000},
        {8,"Jill",'F',120000},
        {9,"Jill",'F',130000},
        {10,"Jill",'F',140000}
    };
    for(int i =0; i<10; i++){
        employees[i].display();
    }
    for(int i =0; i<10; i++){
        int newsalary;
        cout<<"Enter new salary for employee "<<employees[i].getEmpId()<<" "<<;
        updateSalary(employees[i],employees[i].getSalary()*1.1);
    }
}