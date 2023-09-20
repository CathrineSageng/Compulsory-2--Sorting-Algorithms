
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

/// <summary>
/// 
/// </summary>
/// <param name="quickSortArray"></param>
/// <param name="lowNumber"></param>
/// <param name="highNumber"></param>
/// <returns></returns>
int quickSortPartition(int* quickSortArray, int lowNumber, int highNumber)
{
	int pivot = quickSortArray[highNumber];
	int i = lowNumber - 1;

	for (int j = lowNumber; j <= highNumber - 1; j++)
	{
		if (quickSortArray[j] < pivot)
		{
			i++;
			swap(quickSortArray[i], quickSortArray[j]);
		}
	}
	swap(quickSortArray[i + 1], quickSortArray[highNumber]);
	return i + 1;
}

/// <summary>
/// 
/// </summary>
/// <param name="quickSortArray"></param>
/// <param name="lowNumber"></param>
/// <param name="highNumber"></param>
void recursionQuickSort(int* quickSortArray, int lowNumber, int highNumber)
{
	if (lowNumber < highNumber)
	{
		int pivotIndex = quickSortPartition(quickSortArray, lowNumber, highNumber);
		recursionQuickSort(quickSortArray, lowNumber, pivotIndex - 1);
		recursionQuickSort(quickSortArray, pivotIndex + 1, highNumber);
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
	cout << endl;
	cout << endl;
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
	cout << endl;
	cout << endl;
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


