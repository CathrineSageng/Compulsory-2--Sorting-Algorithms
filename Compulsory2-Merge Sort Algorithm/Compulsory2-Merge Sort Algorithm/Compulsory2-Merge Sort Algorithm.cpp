#include <iostream>
#include <chrono>
#include <string>

using namespace std;



void mergeSortedArrays(int* mergeSortArray, int mostLeftIndex, int middleOfTheArray, int mostRightIndex)
{
	int leftLength = middleOfTheArray-mostLeftIndex+1;
	int rightLength = mostRightIndex-middleOfTheArray;

	int tempLeft[leftLength];
	int tempRight[rightLength];

	int i, j, k;

	for (int i = 0; i < leftLength; i++)
	{
		
	}


}

//spilts up the array to single numbers, then merge the numbers together to a sorted array. 
//Uses divide and conquer, where we divide the problem into smaller subproblems and then put them together again 

/// <summary>
/// Thos function divides the unsorted array into smaller and smaller portions
/// </summary>
/// <param name="mergeSortArray"></param>
/// <param name="l"></param>
/// <param name="r"></param>
void recursionMergeSort(int* mergeSortArray, int mostLeftIndex, int mostRightIndex)
{
	if (mostLeftIndex < mostRightIndex)
	{
		int middleOfTheArray = mostLeftIndex + (mostRightIndex - mostLeftIndex) / 2; //Defines the middle of the portion of the array we are looking at
		recursionMergeSort(mergeSortArray, mostLeftIndex, middleOfTheArray);
		recursionMergeSort(mergeSortArray, middleOfTheArray + 1, mostRightIndex);

		mergeSortedArrays(mergeSortArray, mostLeftIndex, middleOfTheArray, mostRightIndex);
	}
}



void printsOutNumbersOfTheArrayBeforeSorted(int* mergeSortArray, int sizeOfTheArray)
{
	cout << "How the numbers in the array are listed before they are sorted: " << endl;
	for (int i = 0; i < sizeOfTheArray; i++)
	{
		if (mergeSortArray == nullptr)
		{
			cerr << "The memory allocation failed." << endl;
			return;
		}
		else
		{
			mergeSortArray[i] = (rand() % 10000);
			cout << mergeSortArray[i] << " ";
		}
	}
	cout << endl << endl;
}

int main()
{
	int* mergeSortArray;
	int sizeOfTheArray;

	cout << "Enter the size(how many elements) you want to sort" << endl;
	cin >> sizeOfTheArray;
	cout << endl;

	mergeSortArray = new int[sizeOfTheArray];
	auto startTime = chrono::high_resolution_clock::now();
	printsOutNumbersOfTheArrayBeforeSorted(mergeSortArray, sizeOfTheArray);

	recursionMergeSort(mergeSortArray, 0, sizeOfTheArray - 1);

	auto endTime = chrono::high_resolution_clock::now();
	auto durationInMS = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
	cout << "Time taken to run the algorithm: " << durationInMS.count() << " milliseconds" << endl;

	delete[] mergeSortArray;

	return 0;

}


