#include <iostream>
#include "employee.h"
#include <fstream>
#include <stdexcept>
using namespace std;

int main(){
   
   int userIn = 0;
   string fileName;   
   cout << "This program has two options:" << endl;
   cout << "1 - Create a data file, or" << endl;
   cout << "2 - Read data from a file and print paychecks." << endl;
   cout << "Please enter (1) to create a file or (2) to print checks:";
   cin >> userIn;
   cout << endl;
   cout << endl;
   
   
   if(userIn == 1){
      
      cout << "Please enter a file name: " << endl;
      cin >> fileName;
      cout << endl;
      
      ofstream empFile;
      empFile.open(fileName);
      
      Employee joe(37, "Joe Brown", "123 Main St.", "123-6788", 10.00, 45.00);
      Employee sam(21, "Sam Jones", "45 East State", "661-9000", 12.00, 30.00);
      Employee mary(15, "Mary Smith", "12 High Street", "401-8900", 15.00, 40.00);
      
      joe.write(empFile);
      sam.write(empFile);
      mary.write(empFile);
      
      empFile.close();
      cout << "Data file created ... you can now run option 2." << endl;
      cout << endl;
      cout << endl;
   }
   else if (userIn == 2){
      cout << "Please enter a file name:" << endl;
      cin >> fileName;
      ifstream myFile;
      myFile.open(fileName);
      if (myFile.fail()){
         cout << "Couldn't open file for input";
         exit(-1);
      }
      while (!myFile.eof()){
         //myFile >> fileName;
            
            if (myFile.good()){
               try {
               Employee newJoe = Employee::read(myFile);
               Employee newSam = Employee::read(myFile);
               Employee newMary = Employee::read(myFile);
               
               newJoe.printCheck();
               newSam.printCheck();
               newMary.printCheck();
               }
               catch (const runtime_error& error)
               {
               //cout << error.what();
               exit(-1);
               }
            }
            
         else if (myFile.bad()){
            cout << "Couldn't open file for input1" << endl;
            exit(-1);
         }
      }
   }
   
}
