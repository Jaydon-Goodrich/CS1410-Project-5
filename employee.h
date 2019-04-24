//This is mine own work. Jaydon Goodrich CS 1410
/*Using cpp file I/O read data in and handle any exception then print out an employee paycheck */
#include <string>
#include <fstream>
using namespace std;

class Employee{
   public:
   Employee(int empNum, string name, string address, string phone, double hourlyWage, double hoursWorked);
   int getEmployeeNumber() const;
   const std::string& getName() const;
   const std::string& getAddr() const;
   const std::string& getPhone() const;
   double getHourlyWage() const;
   double getHoursWorked() const;
   void setName(const std::string& name);
   void setAddr(const std::string& address);
   void setPhone(const std::string& phone);
   void setHourlyWage(double wage);
   void setHoursWorked(double hours);
   double calcPay() const;
   void printCheck() const;
   static Employee read(ifstream& fileData);
   void write(ofstream& fileData);


   private:
   int empNum;
   string name;
   string address;
   string phone;
   double hourlyWage;
   double hoursWorked;
};
