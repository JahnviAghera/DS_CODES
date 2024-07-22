#include <iostream>
using namespace std;
class employee{
    string name;
    char gender;
    double salary;
    int empID;
};    
int main() {
    employee emp1;
    emp1.name = "Jahnvi";
    emp1.gender = 'F';
    emp1.salary = 50000;
    emp1.empID = 101;

    cout << "Name: " << emp1.name << endl;
    cout << "Gender: " << emp1.gender << endl;
    cout << "Salary: " << emp1.salary << endl;
    cout << "Employee ID: " << emp1.empID << endl;
    return 0;
}