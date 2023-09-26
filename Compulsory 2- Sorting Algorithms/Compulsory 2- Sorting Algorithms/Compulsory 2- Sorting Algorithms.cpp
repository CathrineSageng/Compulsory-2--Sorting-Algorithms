#include <iostream>
#include <chrono>
#include <string>

using namespace std; 

void selectionSort(int* selectionSortArray, int sizeOfTheArray);
void printsOutNumbersOfTheArrayBeforeSorted(int* selectionSortArray, int sizeOfTheArray);
void printsOutNumbersOfTheArrayAfterSorted(int* selectionSortArray, int sizeOfTheArray);

int main()
{
	int* selectionSortArray;
	int sizeOfTheArray;

	cout << "Enter the size(how many elements) you want to sort" << endl;
	cin >> sizeOfTheArray;
	cout << endl;

	selectionSortArray = new int[sizeOfTheArray];

	auto startTime = chrono::high_resolution_clock::now();
	printsOutNumbersOfTheArrayBeforeSorted(selectionSortArray, sizeOfTheArray);
	selectionSort(selectionSortArray, sizeOfTheArray);
	printsOutNumbersOfTheArrayAfterSorted(selectionSortArray, sizeOfTheArray);
	auto endTime = chrono::high_resolution_clock::now();
	auto durationInMS = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

	cout << "Time taken to run the algorithm: " << durationInMS.count() << " milliseconds" << endl;

	delete[] selectionSortArray;

	return 0;

}

/// <summary>
/// This function sorts the array from the smallest integer to the 
/// largest integer using selection sort algorithm with for loop
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted</param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains</param>
void selectionSort(int* selectionSortArray, int sizeOfTheArray)
{
	for (int i = 0; i < sizeOfTheArray - 1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < sizeOfTheArray; j++)
		{
			if (selectionSortArray[j] < selectionSortArray[smallestIndex])
			{
				smallestIndex = j;
			}
		}
		if (smallestIndex != i) {
			swap(selectionSortArray[i], selectionSortArray[smallestIndex]);
		}
	}
}

/// <summary>
/// This function prints out in the console window the integers in the array before sorted. 
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted </param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains </param>
void printsOutNumbersOfTheArrayBeforeSorted(int* selectionSortArray, int sizeOfTheArray)
{
	cout << "How the numbers in the array are listed before they are sorted: " << endl;
	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (selectionSortArray == nullptr)
		{
			cerr << "The memory allocation failed." << endl;
			return;
		}
		else
		{
			selectionSortArray[i] = (rand() % 10000);
			cout << selectionSortArray[i] << " ";
		}
	}
	cout << endl;
	cout << endl;
}

/// <summary>
/// This function prints out in the console window the integers in the array after sorted. 
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted </param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains </param>
void printsOutNumbersOfTheArrayAfterSorted(int* selectionSortArray, int sizeOfTheArray)
{
	cout << "Sorted array: " << endl;
	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (selectionSortArray == nullptr)
		{
			cerr << "The memory allocation failed." << endl;
			return;
		}
		cout << selectionSortArray[i] << " ";
	}
	cout << endl;
	cout << endl;
}