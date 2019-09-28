#include "StudentInterface.h"
//#include "GPA.h"
#include <sstream>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>
#include <iomanip>

using namespace std;

class Student : public StudentInterface
{
  public:
    //constructor and destructor
    Student(string name_in, unsigned long long int ID_in, string address_in, string phNumber_in);
    ~Student();

    //Returns the ID of the Student
    unsigned long long int getID();

    //Returns the name of the Student
    string getName();

    //Returns the string representation of the Student's GPA.
    string getGPA();

    //Incorporates the given course grade into the Student's overall GPA.
    void addGPA(double classGrade);

    /*
		 * toString()
		 *
		 * The student object will be put into string representation. Student info will be
		 * ordered ID, name, address, phone number, and GPA. Each piece of information will
		 * be on its own line. GPA will not have a newline following it and the precision 
		 * of the GPA will be set to two decimal places. For example,
		 * 
		 * 123456789
		 * Ben Thompson
		 * 17 Russell St, Provo, UT 84606
		 * 555-555-5555
		 * 3.12
		 * 
		 * Returns a string representation of the student object There is no trailing new line.
		 */
    string toString();

	  //Returns the int number of courses that we have data on
	  int getNoOfCourses();

	  //Changes the number of courses that we have GPA data on
	  void changeCourses(int newNumberOfCourses);

  private:
    string name;
    unsigned long long int ID;
    double total_grade_points;
    string address;
    string phNumber;
    int no_of_courses;
};