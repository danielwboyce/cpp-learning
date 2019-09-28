#include "GPA.h"
#include <iostream>

using namespace std;

GPA::GPA() : GPAInterface()
{
	map<unsigned long long int, StudentInterface *> StudentMap;
	set<StudentInterface*, Comparator> StudentSet;
}
GPA::~GPA() 
{
	this->clear();
}

//Returns the map storing the student information.
//The key of the map should be the student ID.
map<unsigned long long int, StudentInterface *> GPA::getMap()
{
	return this->StudentMap;
}

//Returns the set storing the student information.
set<StudentInterface *, Comparator> GPA::getSet()
{
	return this->StudentSet;
}

/*
		 * importStudents()
		 *
		 * Read in and parse through the given files. Each part of an entry in a
		 * file is given on a separate line in the file. Student ID is first, name is
		 * second, address is third, and phone is last. There are no blank lines between
		 * students. The following is an example file:
		 *
		 *	 5291738600
		 * 	 Dick B. Smith
		 * 	 879 Maple Road, Centralia, Colorado 24222
		 * 	 312-000-1000
		 * 	 9251738707
		 *	 Harry C. Anderson
		 *	 635 Main Drive, Midville, California 48444
		 * 	 660-050-2200
		 *
		 * If a valid file is given, the new Students should be added to the existing
		 * map and set. 
		 *
		 * If an invalid file name is given or if there is a missing entry for a student, 	
		 * return false. Duplicate student ID numbers and duplicate students will not be 
		 * tested for. There will never be a student that exists in the map and set. If 
		 * the function returns false, then no changes should have been made to the 
		 * existing map or set. 
		 *
		 * The key of the map should be the student ID.
		 *
		 * Returns false if an invalid filename is given or if there is a missing entry for a
		 * student, otherwise true.
		 */
bool GPA::importStudents(string mapFileName, string setFileName)
{

	ifstream mapInFile;
	ifstream setInFile;
	mapInFile.open(mapFileName);
	setInFile.open(setFileName);
	bool imported = true;
	
	//If the files can be opened
	if (!mapInFile.fail() && !setInFile.fail())
	{
		//Here are some variables we'll need later
		unsigned long long int temp_ID = 0;
		string temp_name;
		string line;
		string temp_address;
		string temp_phNumber;
		
		//Read throught the files first to see if they are valid.
		while(getline(mapInFile, line))
		{
			stringstream ss;
			ss << line;
			if (ss >> temp_ID && getline(mapInFile, temp_name) && getline(mapInFile, temp_address)
				&& getline(mapInFile, temp_phNumber))
				{
					if (temp_name == "" || temp_address == "" || temp_phNumber == "")
					{
						return false;
					}
				}
			else
			{
				return false;
			}
		}
		while(getline(setInFile, line))
		{
			stringstream ss;
			ss << line;
			if (ss >> temp_ID && getline(setInFile, temp_name) && getline(setInFile, temp_address)
				&& getline(setInFile, temp_phNumber))
				{
					if (temp_name == "" || temp_address == "" || temp_phNumber == "")
					{
						return false;
					}
				}
			else
			{
				return false;
			}
		}
		mapInFile.close();
		setInFile.close();

		mapInFile.open(mapFileName);
		setInFile.open(setFileName);

		//If they were invalid, they would have returned false above.
		while (getline(mapInFile, line))
		{
			stringstream ss;
			ss << line;
			if(ss >> temp_ID)
			{
				getline(mapInFile, temp_name);

				//ss << line;
				//ss >> temp_name;
				getline(mapInFile, temp_address);
				//ss << line;
				//ss >> temp_address;
				getline(mapInFile, temp_phNumber);
				//ss << line;
				//ss >> temp_phNumber;
				if (temp_name == "" || temp_address == "" || temp_phNumber == "")
				{
					//this->clear();
					return false;
				}
				else
				{
					Student* onepointer = new Student(temp_name, temp_ID, temp_address, temp_phNumber);
					StudentMap[temp_ID] = onepointer;
				}
			}
			
			//StudentMap.insert(pair<unsigned long long int, StudentInterface*>(temp_ID, onepointer));
			//StudentSet.insert(onepointer);
			



			/*
			if (ss >> temp_ID)
			{
				getline(mapInFile, line);
				ss << line;
				if (ss >> temp_name && temp_name != "")
				{
					getline(mapInFile, line);
					ss << line;
					if (ss >> temp_address && temp_address != "")
					{
						getline(mapInFile, line);
						ss << line;
						if (ss >> temp_phNumber && temp_phNumber != "")
						{
							Student* onepointer = new Student(temp_name, temp_ID, temp_address, temp_phNumber);
							StudentMap.insert(pair<unsigned long long int, StudentInterface*>(temp_ID, onepointer));
							StudentSet.insert(onepointer);
							//cout << StudentMap.size();
						}
						else
						{
							imported = false; // return false;
						}
					}
					else
					{
						imported = false; // return false;
					}
				}
				else
				{
					imported = false; // return false;
				}
			}
			else
			{
				imported = false; // return false;
			}
			*/
		}
		while (getline(setInFile, line))
		{
			stringstream ss;
			ss << line;
			if (ss >> temp_ID)
			{
				getline(setInFile, temp_name);
				//ss << line;
				//ss >> temp_name;
				getline(setInFile, temp_address);
				//ss << line;
				//ss >> temp_address;
				getline(setInFile, temp_phNumber);
				//ss << line;
				//ss >> temp_phNumber;
				if (temp_name == "" || temp_address == "" || temp_phNumber == "")
				{
					//this->clear();
					return false;
				}
				else
				{
					Student* onepointer = new Student(temp_name, temp_ID, temp_address, temp_phNumber);
					//StudentMap.insert(pair<unsigned long long int, StudentInterface*>(temp_ID, onepointer));
					StudentSet.insert(onepointer);
				}
			}
			
			
			
			/*
			ss << line;
			if (ss >> temp_ID)
			{
				getline(setInFile, line);
				ss << line;
				if (ss >> temp_name && temp_name != "")
				{
					getline(setInFile, line);
					ss << line;
					if (ss >> temp_address && temp_address != "")
					{
						getline(setInFile, line);
						ss << line;
						if (ss >> temp_phNumber && temp_phNumber != "")
						{
							Student* onepointer = new Student(temp_name, temp_ID, temp_address, temp_phNumber);
							StudentMap.insert(pair<unsigned long long int, StudentInterface*>(temp_ID, onepointer));
							StudentSet.insert(onepointer);
						}
						else
						{
							imported = false; // return false;
						}
					}
					else
					{
						imported = false; // return false;
					}
				}
				else
				{
					imported = false; // return false;
				}
			}
			else
			{
				imported = false; // return false;
			}
			*/
		}
		return true;
	}
	else
	{
		//this->clear();
		return false;
	}

	//return imported;
}

/*
		 * importGrades()
		 *
		 * Read in and parse through the given file. Each part of an entry in the file
		 * is given on a separate line in the file. Student ID is first, course is
		 * second, and grade is last. There are no blank lines between entries. The
		 * following is an example file:
		 *
		 * 	5291738860
		 * 	CHEM134
		 * 	A
		 * 	9251734870
		 * 	BOT180
		 * 	B
		 * 	9251733870
		 * 	PE273
		 * 	D+
		 * 	5291738760
		 * 	HIS431
		 *  	A-
		 *
		 * Compute the GPA by finding the average of all the grades with a matching student ID
		 * in the Grade file. The GPA is calculated by taking a Student's total sum GPA and 
		 * dividing by the number of classes taken. If the given student ID has no matching 
		 * grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
		 * names so long as the total number of courses taken is counted.
		 *
		 * You may assume that the given student ID exists in the map or set.
		 *
		 * Use the following point values for each grade.
		 *
		 *		  A = 4.0  A- = 3.7
		 *	B+ = 3.4  B = 3.0  B- = 2.7
		 *	C+ = 2.4  C = 2.0  C- = 1.7
		 *	D+ = 1.4  D = 1.0  D- = 0.7
		 *		  E = 0.0
		 *
		 * Returns false if an invalid filename is given, otherwise true.
		 */
bool GPA::importGrades(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);

	if(!inFile.is_open())
	{
		return false;
	}
	//bool imported = true;
	string line;

	unsigned long long int temp_ID;
	string course_name;
	string grade;
	double grade_double;
			

			int counter = 0;

	//Reads through the file quickly checking to see if it's valid
	while(getline(inFile, line))
		{
			counter++;
			/*stringstream ss;
			ss << line;
			if (ss >> temp_ID && getline(inFile, course_name) && getline(inFile, grade))
				{
					if (course_name == "" || grade == "")
					{
						return false;
					}
				}
			else
			{
				return false;
			}*/
		}
	
	//Closes and then reopens
	inFile.close();


	if(counter % 3 != 0)
	return false;
	inFile.open(fileName);

	while(getline(inFile, line))
		{
			stringstream ss;
			ss << line;
			ss >> temp_ID;
			getline(inFile, course_name);
			getline(inFile, grade);

			if (grade == "A"){grade_double = Aflat;}
			else if (grade == "A-"){ grade_double = Aminus; }
			else if (grade == "B+"){ grade_double = Bplus; }
			else if (grade == "B"){ grade_double = Bflat; }
			else if (grade == "B-"){ grade_double = Bminus; }
			else if (grade == "C+"){ grade_double = Cplus; }
			else if (grade == "C"){ grade_double = Cflat; }
			else if (grade == "C-"){ grade_double = Cminus; }
			else if (grade == "D+"){ grade_double = Dplus; }
			else if (grade == "D"){ grade_double = Dflat; }
			else if (grade == "D-"){ grade_double = Dminus; }
			else if (grade == "E"){ grade_double = Eflat; }

			//if (StudentMap[temp_ID] != NULL)
			//{
			//	(*StudentMap[temp_ID]).addGPA(grade_double);
			//}

			for (map<unsigned long long int, StudentInterface*>::iterator itr = StudentMap.begin();
				itr != StudentMap.end(); itr++)
				{
					if ((*(itr->second)).getID() == temp_ID)
					{
						(*(itr->second)).addGPA(grade_double);
					}
				}
			for (set<StudentInterface*, Comparator>::iterator itr = StudentSet.begin();
				itr != StudentSet.end(); itr++)
				{
					if ((*itr)->getID() == temp_ID)
					{
						(*itr)->addGPA(grade_double);
					}
				}

				
		}
		return true;





	/*
	//If the file can be opened
	if (!inFile.fail())
	{
		string line;
		stringstream ss;
		
		while (getline(inFile, line))
		{
			unsigned long long int temp_ID;
			string course_name;
			string grade;
			double grade_double;
			
			ss << line;

			if (ss >> temp_ID)
			{
				getline(inFile, line);
				ss << line;
				if (ss >> course_name)
				{
					getline(inFile, line);
					ss << line;
					if (ss >> grade)
					{
						if (grade == "A"){grade_double = Aflat;}
						else if (grade == "A-"){ grade_double = Aminus; }
						else if (grade == "B+"){ grade_double = Bplus; }
						else if (grade == "B"){ grade_double = Bflat; }
						else if (grade == "B-"){ grade_double = Bminus; }
						else if (grade == "C+"){ grade_double = Cplus; }
						else if (grade == "C"){ grade_double = Cflat; }
						else if (grade == "C-"){ grade_double = Cminus; }
						else if (grade == "D+"){ grade_double = Dplus; }
						else if (grade == "D"){ grade_double = Dflat; }
						else if (grade == "D-"){ grade_double = Dminus; }
						else if (grade == "E"){ grade_double = Eflat; }

						

						(*(StudentMap[temp_ID])).addGPA(grade_double);
					}
				}
			}
		}

		return true;
	}
	else
	{
		return false;
	}
	*/
}

/*
		 * querySet()
		 *
		 * Read in and parse through the given file. The 'Query' file contains a list of
		 * student ID numbers. Each entry in the Query file is a student ID given on a
		 * line by itself. You are to compute and report the GPA for each of the students
		 * listed in the Query file. The following is an example Query file:
		 *
		 * 	5291738860
		 * 	9251733870
		 *
		 * For each student ID given in the Query file, use the student information stored in
		 * your set to compute the GPA for the student and create an output string which
		 * contains the student ID, GPA, and name. If the given student ID does not match any 	
		 * student, do not give any output for that student ID. Each line of the output string
		 * contains student ID, GPA, and name as shown:
		 *
		 * 	5291738860 2.85 Dick B. Smith
		 *	9251733870 3.00 Harry C. Anderson
		 *
		 * Return a string representation of the given query. If an invalid file name is given,
		 * then return an empty string. The precision of the GPA will be set to two decimal places.
		 * There will be a trailing new line.
		 */
string GPA::querySet(string fileName)
{
	ifstream inFile;

	inFile.open(fileName);

	stringstream masterstream;

	if (!inFile.fail())
	{
		string line;
		
		unsigned long long int temp_ID;
		

		while (getline(inFile, line))
		{
			stringstream ss;
			ss << line;
			ss >> temp_ID;

			for (StudentInterface* student : StudentSet)
			{
				if ((*student).getID() == temp_ID)
				{
					masterstream << (*student).getID() << " " << (*student).getGPA() << " " << (*student).getName() << "\n";
				}
			}
		}
	}
	
	string final;
	return masterstream.str();

	//return final;
	
	
}

/*
		 * queryMap()
		 *
		 * Read in and parse through the given file. The 'Query' file contains a list of
		 * student ID numbers. Each entry in the Query file is a student ID given on a
		 * line by itself. You are to compute and report the GPA for each of the students
		 * listed in the Query file. The following is an example Query file:
		 *
		 * 	5291738860
		 * 	9251733870
		 *
		 * For each student ID given in the Query file, use the student information stored in
		 * your map to compute the GPA for the student and create an output string which
		 * contains the student ID, GPA, and name. If the given student ID does not match any 			 
		 * student, do not give any output for that student ID. Each line of the output string
		 * contains student ID, GPA, and name as shown:
		 *
		 * 	5291738860 2.85 Dick B. Smith
		 *	9251733870 3.00 Harry C. Anderson
		 *
		 * Return a string representation of the given query. if an ivalid file name is given,
		 * then return an empty string. The precision of the GPA will be set to two decimal places.
		 * There will be a trailing new line.
		 */
string GPA::queryMap(string fileName)
{
	ifstream inFile;

	inFile.open(fileName);

	stringstream masterstream;

	if (!inFile.fail())
	{
		string line;
		
		unsigned long long int temp_ID;


		while (getline(inFile, line))
		{
			stringstream ss;
			ss << line;
			ss >> temp_ID;
			if(StudentMap.find(temp_ID) != StudentMap.end())
			{
				StudentInterface* student = StudentMap[temp_ID];
				masterstream << (*student).getID() << " " << (*student).getGPA() << " " << (*student).getName() << "\n";
			}
		}
	}

	//string final;
	//masterstream >> final;

	return masterstream.str();
}

//Clears the students from the map and set.
void GPA::clear()
{
	for (map<unsigned long long int, StudentInterface*>::iterator itr = StudentMap.begin();
		itr != StudentMap.end(); itr++)
		{
			delete itr->second;
			//StudentMap.erase(itr);
		}
	for (set<StudentInterface*, Comparator>::iterator itr = StudentSet.begin();
		itr != StudentSet.end(); itr++)
		{
			delete (*itr);
		}
	
	
	StudentMap.clear();
	StudentSet.clear();
}
