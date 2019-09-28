#include "Student.h"
//#include <iostream>


using namespace std;

//Constructor and destructor
Student::Student(string name_in, unsigned long long int ID_in, string address_in, string phNumber_in) : StudentInterface()
{
    this->name = name_in;
    this->ID = ID_in;
    this->total_grade_points = 0.0;
    this->address = address_in;
    this->phNumber = phNumber_in;
    this->no_of_courses = 0;
}
Student::~Student(){}

//Returns the ID of the Student
unsigned long long int Student::getID()
{
    return this->ID;
}

//Returns the name of the Student
string Student::getName()
{
    return this->name;
}

//Returns the string representation of the Student's GPA.
string Student::getGPA()
{
   if (this->no_of_courses == 0)
   {
	   return "0.00";
   }
   else
   {
	stringstream ss;
    string GPA_string;
    double GPA_double = this->total_grade_points / this->no_of_courses;
	//ss.precision(3);
    ss << fixed << setprecision(2) << GPA_double;
    ss >> GPA_string;
    return GPA_string;
   }
    
}

//Incorporates the given course grade into the Student's overall GPA.
void Student::addGPA(double classGrade)
{
    this->total_grade_points = this->total_grade_points + classGrade;
    no_of_courses++;
    
    //double temp_GPA = this->;
    //temp_GPA = (no_of_courses * temp_GPA) + classGrade;
    //no_of_courses++;
    //temp_GPA = temp_GPA / no_of_courses;
    //this->GPA = temp_GPA;
}

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
string Student::toString()
{
    stringstream ss;
    //string result;
	ss << this->getID() << "\n" << this->getName() << "\n" << this->address << "\n"
		<< this->phNumber << "\n" << this->getGPA();
    return ss.str();
}

//Returns the int number of courses that we have data on
int Student::getNoOfCourses()
{
	return this->no_of_courses;
}

//Changes the number of courses that we have GPA data on
void Student::changeCourses(int newNumberOfCourses)
{
	this->no_of_courses = newNumberOfCourses;
}