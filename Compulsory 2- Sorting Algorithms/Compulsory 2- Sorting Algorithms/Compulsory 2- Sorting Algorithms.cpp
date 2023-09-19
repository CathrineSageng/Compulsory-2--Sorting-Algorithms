#include <iostream>
#include <chrono>
#include <string>
#include <vector>
using namespace std; 
int sizeOfTheArray;
/// <summary>
///  Recursive selection sort function 
/// </summary>
/// <param name="selectionSortArray">The array to be sorted</param>
/// <param name="sizeOfTheArray">How many integer the array stores</param>
/// <param name="currentNumber">The number each index compares to</param>
//void recursiveSelectionSort(int* selectionSortArray, int sizeOfTheArray, int currentNumber = 0)
//{
//	if (currentNumber == sizeOfTheArray-1)
//	{
//		return;
//	}
//	else
//	{
//		int smallestNumber = currentNumber;
//		for (int i =  currentNumber + 1; i < sizeOfTheArray; i++)
//		{
//			if (selectionSortArray[i] < selectionSortArray[smallestNumber])
//			{
//				smallestNumber = i;
//			}
//		}
//
//		if (smallestNumber != currentNumber)
//		{
//			swap(selectionSortArray[smallestNumber], selectionSortArray[currentNumber]);
//		}
//
//		recursiveSelectionSort(selectionSortArray, sizeOfTheArray, currentNumber + 1);
//	}
//}

void selectionSort(int* selectionSortArray, int sizeOfTheArray)
{
	for (int i = 0; i < sizeOfTheArray-1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < sizeOfTheArray; j++)
		{
			if (selectionSortArray[j] < selectionSortArray[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(selectionSortArray[i], selectionSortArray[minIndex]);
		}
	}
}




int main()
{
	int* selectionSortArray;

	cout << "Enter the size of the array you want to sort" << endl;
	cin >> sizeOfTheArray;

	selectionSortArray = new int[sizeOfTheArray];

	cout << "How the numbers in the array are listed int the array before sorted: " << endl; 

	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (selectionSortArray == nullptr)
		{
			std::cerr << "Memory allocation failed." << std::endl;
			return 1;  // Exit with an error code
		}
		else
		{
			selectionSortArray[i] = (rand() % 1000);
			cout << " " << selectionSortArray[i];
		}
	}
	cout << endl;
	cout << endl;
	cout << "The numbers in the array are sorted from the smallest to the largest integer: " << endl;
	

	auto start_time = std::chrono::high_resolution_clock::now();

	selectionSort(selectionSortArray, sizeOfTheArray);

	auto end_time = std::chrono::high_resolution_clock::now();

	auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (selectionSortArray == nullptr)
		{
			std::cerr << "Memory allocation failed." << std::endl;
			return 1;  // Exit with an error code
		}
		cout << selectionSortArray[i] << " ";
	}
	cout << endl;
	cout << endl;
	std::cout << "Time taken: " << duration_ms.count() << " microseconds" << std::endl;

	delete[] selectionSortArray;
	return 0;

}

