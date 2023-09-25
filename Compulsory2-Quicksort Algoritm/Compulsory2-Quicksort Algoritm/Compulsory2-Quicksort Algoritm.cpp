
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

/// <summary>
/// This function is partitioning the array. It splits the array to sub arrays where you have numbers less than the pivot 
/// and greater than the pivot. Chose th pivot to be the last index of the array.
/// </summary>
/// <param name="quickSortArray"> The integers in the array to be sorted </param>
/// <param name="mostLeftIndex"> This number is used to define the first index in the array </param>
/// <param name="mostRightIndex"> This number is used ro define the last number in the array </param>
/// <returns> returns the pivotIndex after the last index is swapped</returns>
int quickSortPartition(int* quickSortArray, int mostLeftIndex, int mostRightIndex) 
{
	int pivot = quickSortArray[mostRightIndex];
	int i = mostLeftIndex - 1;

	for (int j = mostLeftIndex; j <= mostRightIndex - 1; j++)  
	{
		if (quickSortArray[j] < pivot)	
		{
			i++;					
			swap(quickSortArray[i], quickSortArray[j]);
		}
	}
	swap(quickSortArray[i + 1], quickSortArray[mostRightIndex]);
	return i + 1; 
}

/// <summary>
/// This function calls itself with recursion. Uses a divide and conquer to divide the array to smaller pieces for sorting. 
/// The pivot tells us where the split is between the left part and the right part of the array.
/// The first recusion sorts the left part of the array uptil the pivot, but does not include the pivot. 
/// The second recursion sorts the right part of the array after the pivot, but does not include the pivot. 
/// The base case is when the most left index is not samller than the right most index. 
/// </summary>
/// <param name="quickSortArray"> The integers in the array to be sorted </param>
/// <param name="lowNumber"> This number is used to define the first index in the array </param>
/// <param name="highNumber"> This number is used ro define the last number in the array </param>
void recursionQuickSort(int* quickSortArray, int mostLeftIndex, int mostRightIndex)
{
	if (mostLeftIndex < mostRightIndex) 
	{
		int pivotIndex = quickSortPartition(quickSortArray, mostLeftIndex, mostRightIndex);  
		recursionQuickSort(quickSortArray, mostLeftIndex, pivotIndex - 1); 
		recursionQuickSort(quickSortArray, pivotIndex + 1, mostRightIndex); 
	}
}


/// <summary>
/// This function prints out in the console window the integers in the array before sorted. 
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted </param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains </param>
void printsOutNumbersOfTheArrayBeforeSorted(int* quickSortArray, int sizeOfTheArray)
{
	cout << "How the numbers in the array are listed before they are sorted: " << endl;
	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (quickSortArray == nullptr)
		{
			cerr << "The memory allocation failed." << endl;
			return;
		}
		else
		{
			quickSortArray[i] = (rand() % 10000);
			cout << quickSortArray[i] << " ";
		}
	}
	cout << endl<< endl;
}

/// <summary>
/// This function prints out in the console window the integers in the array after sorted. 
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted </param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains </param>
void printsOutNumbersOfTheArrayAfterSorted(int* quickSortArray, int sizeOfTheArray)
{
	cout << "Sorted array: " << endl;
	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (quickSortArray == nullptr)
		{
			cerr << "The memory allocation failed." << endl;
			return;
		}
		cout << quickSortArray[i] << " ";
	}
	cout << endl<< endl;
}

int main()
{
	int* quickSortArray;
	int sizeOfTheArray;

	cout << "Enter the size(how many elements) you want to sort" << endl;
	cin >> sizeOfTheArray;
	cout << endl;

	quickSortArray = new int[sizeOfTheArray];
	auto startTime = chrono::high_resolution_clock::now();
	printsOutNumbersOfTheArrayBeforeSorted(quickSortArray,sizeOfTheArray);
	recursionQuickSort(quickSortArray, 0, sizeOfTheArray-1);
	printsOutNumbersOfTheArrayAfterSorted(quickSortArray, sizeOfTheArray);
	auto endTime = chrono::high_resolution_clock::now();
	auto durationInMS = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
	cout << "Time taken to run the algorithm: " << durationInMS.count() << " milliseconds" << endl;

	delete[] quickSortArray;

	return 0;
}


