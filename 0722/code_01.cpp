#include <iostream>
using namespace std;
class employee{
    double salary;
public:
    string name;
    char gender;
    int empID;
    
    void setSalary(double s){
        salary = s;
    }
    double getSalary(){
        return salary;
    }
};    
int main() {
    employee emp1;
    emp1.name = "Jahnvi";
    emp1.gender = 'F';
    emp1.setSalary(50000);
    emp1.empID = 101;

    cout << "Name: " << emp1.name << endl;
    cout << "Gender: " << emp1.gender << endl;
    cout << "Salary: " << emp1.getSalary() << endl;
    cout << "Employee ID: " << emp1.empID << endl;
    return 0;
}