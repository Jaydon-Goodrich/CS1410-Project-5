#include <iostream>
#include "employee.h"
#include <iomanip>
#include <stdexcept>
using namespace std;
double WEEKHOUR = 40;
double FEDTAX = .2;
double STATETAX = .075;
double HALF = 2;

Employee::Employee(int empNum, string name, string address, string phone, double hourlyWage, double hoursWorked){
   this->empNum = empNum;
   this->name = name;
   this->address = address;
   this->phone = phone;
   this->hourlyWage = hourlyWage;
   this->hoursWorked = hoursWorked;
}


int Employee::getEmployeeNumber() const{
   return empNum;
}
const std::string& Employee::getName() const{
   return name;
}
const std::string& Employee::getAddr() const{
   return address;
}
const std::string& Employee::getPhone() const{
   return phone;
}
double Employee::getHourlyWage() const{
   return hourlyWage;
}
double Employee::getHoursWorked() const{
   return hoursWorked;
}
void Employee::setName(const std::string& name){
   this->name = name;
}
void Employee::setAddr(const std::string& address){
   this->address = address;
}
void Employee::setPhone(const std::string& phone){
   this->phone = phone;
}
void Employee::setHourlyWage(double wage){
   hourlyWage = wage;
}
void Employee::setHoursWorked(double hours){
   hoursWorked = hours;
}
double Employee::calcPay() const{
   double grossPay;
   double otwage;
   double netPay;
   double othours;
   grossPay = hoursWorked * hourlyWage;
   if (hoursWorked > WEEKHOUR){
      otwage = hourlyWage + (hourlyWage/HALF);
      othours = hoursWorked - WEEKHOUR;
      grossPay = ((hoursWorked - othours) * hourlyWage) + (othours * otwage);
   }
   netPay = grossPay - ((grossPay * FEDTAX)+(grossPay * STATETAX));
   return netPay;
}
void Employee::printCheck() const{
   cout << std::fixed;
   cout << std::setprecision(HALF);

   cout << "....................UVU Computer Science Dept................................." << endl;
   cout << endl;
   cout << endl;
   cout << "Pay to the order of " << name << "....................................$" << calcPay() << endl;
   cout << endl;
   cout << endl;
   cout << "United Community Credit Union" << endl;
   cout << ".............................................................................." << endl;
   cout << endl;
   cout << "Hours worked: " << hoursWorked << endl;
   cout << "Hourly wage: " << hourlyWage << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
}
void Employee::write(ofstream& fileData){
   fileData << empNum << endl;
   fileData << name << endl;
   fileData << address << endl;
   fileData << phone << endl;
   fileData << hourlyWage << endl;
   fileData << hoursWorked << endl;
}
Employee Employee::read(ifstream& fileData){
   string data;
   int empNum;
   string name;
   string address;
   string phone;
   double hoursWorked;
   double hourlyWage;
   if (getline(fileData, data)){
      empNum = stoi(data);
   }
   else {
      throw std::runtime_error("Error");
   }
         
   getline(fileData, name);
   getline(fileData, address);
   getline(fileData, phone);
   if (getline(fileData, data)){
      hourlyWage = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
   if (getline(fileData, data)){
      hoursWorked = stod(data);
   }
   else {
      throw std::runtime_error("Error");
   }
   Employee person(empNum,name,address,phone,hourlyWage,hoursWorked);
   
   return person;
}
