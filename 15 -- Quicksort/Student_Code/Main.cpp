#include "QS.h"

using namespace std;

int main()
{
	QS filler;
	if (filler.createArray(20))
	{
		cout << "The program successfully created an array." << endl;
	}
	else
	{
		cout << "The program failed to create an array." << endl;
	}
	
	filler.addToArray(20);
	filler.addToArray(1);
	filler.addToArray(27);
	filler.addToArray(3);
	cout << filler.getArray() << endl;
	cout << filler.medianOfThree(0, 3) << endl;
	cout << filler.getArray() << endl;
	
	
	
	system("pause");
	return 0;
}