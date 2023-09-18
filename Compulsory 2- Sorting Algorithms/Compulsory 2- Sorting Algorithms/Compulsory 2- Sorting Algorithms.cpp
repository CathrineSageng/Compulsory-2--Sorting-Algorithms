#include <iostream>
#include <chrono>
using namespace std; 

/// <summary>
///  This is an sorting algorithm using selection sort. 
/// </summary>
/// <param name="selectionSortArray"></param>
/// <param name="sizeOfTheArray"></param>
/// <param name="currentNumber"></param>
void recursiveSelectionSort(int selectionSortArray[], int sizeOfTheArray, int currentNumber = 0)
{
	if (currentNumber == sizeOfTheArray-1)
	{
		return;
	}
	else
	{
		int smallestNumber = currentNumber;
		for (int i =  currentNumber + 1; i < sizeOfTheArray; i++)
		{
			if (selectionSortArray[i] < selectionSortArray[smallestNumber])
			{
				smallestNumber = i;
			}
		}

		if (smallestNumber != currentNumber)
		{
			swap(selectionSortArray[smallestNumber], selectionSortArray[currentNumber]);
		}

		recursiveSelectionSort(selectionSortArray, sizeOfTheArray, currentNumber + 1);
	}
}




int main()
{

	int selectionSortArray[] = { 11,54,98,41,3,45,7,23,37,100,99,98,97,9,96,25,65,45,75,35,65,25,85,95};

	int sizeOfTheArray = sizeof(selectionSortArray) / sizeof(selectionSortArray[0]);

	cout << "How the numbers in the array are listed int the array before sorted: " << endl; 

	for (int i = 0; i < sizeOfTheArray; i++)
	{
		cout << selectionSortArray[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "The numbers in the array are sorted from the smallest to the largest integer: " << endl;
	

	auto start_time = std::chrono::high_resolution_clock::now();

	recursiveSelectionSort(selectionSortArray, sizeOfTheArray);

	auto end_time = std::chrono::high_resolution_clock::now();

	auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	for (int i = 0; i < sizeOfTheArray; i++)
	{
		cout << selectionSortArray[i] << " ";
	}
	cout << endl;
	cout << endl;
	std::cout << "Time taken: " << duration_ms.count() << " microseconds" << std::endl;

	
	system("pause>0");

}

