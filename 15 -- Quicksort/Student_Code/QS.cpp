#include "QS.h"

using namespace std;

QS::QS() : QSInterface()
{
	this->data = NULL;
	this->no_of_added_values = 0;
	this->max_capacity = 0;
}
QS::~QS()
{
	this->clear();
}

/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll()
{
	if (data == NULL || this->getSize() == 0)
	{
		return;
	}
	else
	{
		int left_index = 0;
		int right_index = this->no_of_added_values - 1;
		/*
		cout << "The array before processing: " << this->getArray() << endl;
		while (!(right_index - left_index <= 1))
		{
			this->partition(left_index, right_index, this->medianOfThree(left_index, right_index));
			left_index++;
			right_index--;
			cout << "The array after a round: " << this->getArray() << endl;
		}
		*/
		this->recursiveSorterHelper(left_index, right_index);
	}
}

/*
	recursiveSorterHelper()
	@param left is the left index of the subpartition
	@param right is the right index ofthe subpartition

	Base case: if the subpartition is of size < =3 (so right-left <= 2)
	use the medianOfThree() function to sort the subpartition
	Else:
	Uses the partition function to sort the current subpartition
	Make two recursive calls to sort the left partition and the right partition
*/
void QS::recursiveSorterHelper(int left_index, int right_index)
{
	if (right_index - left_index <= 2)
	{
		this->medianOfThree(left_index, right_index);
		return;
	}
	else
	{
		int m = this->medianOfThree(left_index, right_index);
		int p = this->partition(left_index, right_index, m);
		this->recursiveSorterHelper(left_index, (p - 1));
		this->recursiveSorterHelper((p + 1), right_index);
	}
}


/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right)
{
	if (this->no_of_added_values == 0 || left >= right || right >= this->no_of_added_values || left < 0 || right < 0)
	{
		return -1;
	}
	else
	{
		int middle = (left + right) / 2;
		while (data[left] > data[middle] || data[middle] > data[right])
		{
			if (data[left] > data[middle])
			{
				int temporary = data[left];
				data[left] = data[middle];
				data[middle] = temporary;
			}
			if (data[middle] > data[right])
			{
				int temporary = data[middle];
				data[middle] = data[right];
				data[right] = temporary;
			}
		}
		return middle;
	}
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not between the two boundaries.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int left, int right, int pivotIndex)
{
	if (left < 0 || right < 0 || pivotIndex < 0 || left >= pivotIndex || pivotIndex >= right || right >= this->no_of_added_values || this->no_of_added_values == 0)
	{
		return -1;
	}
	else
	{
		vector<int> left_vector;
		vector<int> right_vector;
		int middle = *(this->data + pivotIndex);
		//Add the smaller items to the left vector, and the larger items to the right vector
		for (int i = left; i <= right; i++)
		{
			if (*(this->data + i) <= *(this->data + pivotIndex))
			{
				left_vector.push_back(*(this->data + i));
			}
			if (*(this->data + i) > *(this->data + pivotIndex))
			{
				right_vector.push_back(*(this->data + i));
			}
		}
		//Add the vector back to the array
		for (int i = 0; i < left_vector.size(); i++)
		{
			int tempindex = left + i;
			*(this->data + tempindex) = left_vector[i];
		}
		int endingPivotIndex = left_vector.size() + left;
		*(this->data + endingPivotIndex) = middle;
		for (int i = 0; i < right_vector.size(); i++)
		{
			int tempindex = endingPivotIndex + 1 + i;
			*(this->data + tempindex) = right_vector[i];
		}
		return endingPivotIndex;
	}
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray()
{
	if (data == NULL || this->no_of_added_values == 0)
	{
		return "";
	}
	else
	{
		stringstream ss;
		for (int i = 0; i < this->no_of_added_values; i++)
		{
			ss << *(this->data + i) << ",";
		}
		string tempstring = ss.str();
		if (tempstring.back() == ',')
		{
			tempstring.pop_back();
		}
		return tempstring;
	}
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize()
{
	return this->no_of_added_values;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
*/
void QS::addToArray(int value)
{
	if (this->no_of_added_values < this->max_capacity)
	{
		*(this->data + this->no_of_added_values) = value;
		//data[no_of_added_values] = value;
		this->no_of_added_values++;

		//cout << "The program added the value " << value << endl;
	}
	else
	{
		//cout << "The program didn't add the value " << value << endl;
	}
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity)
{
	if (capacity <= 0)
	{
		return false;
		//cout << "The given capacity was <= 0" << endl;
	}
	
	const int SIZE = capacity;
	this->max_capacity = capacity;

	if (this->data != NULL)
	{
		this->clear();
		this->data = new int[SIZE];
	}
	else
	{
		this->data = new int[SIZE];
	}
	/*
	for (int i = 0; i < capacity; i++)
	{
		this->data[i] = NULL;
	}
	*/

	return true;
}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear()
{
	for (int i = 1; i < this->no_of_added_values; i++)
	{
		delete (this->data + i);
	}
	
	//delete this->data;
	this->no_of_added_values = 0;
	this->max_capacity = 0;
	this->data = NULL;
}