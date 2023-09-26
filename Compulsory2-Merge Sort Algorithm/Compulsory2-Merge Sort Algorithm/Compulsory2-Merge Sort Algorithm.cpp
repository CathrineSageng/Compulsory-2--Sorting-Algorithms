#include <iostream>
#include <chrono>
#include <string>


using namespace std;


//spilts up the array to single numbers, then merge the numbers together to a sorted array. 
//Uses divide and conquer, where we divide the problem into smaller subproblems and then put them together again 


void mergeSort(int* mergeSortArray, int mostLeftIndex, int midOfTheArray, int mostRightIndex);
void recursionMergeSort(int* mergeSortArray, int mostLeftIndex, int mostRightIndex);
void printsOutNumbersOfTheArrayBeforeSorted(int* mergeSortArray, int sizeOfTheArray);
void printsOutNumbersOfTheArrayAfterSorted(int* mergeSortArray, int sizeOfTheArray);



int main()
{
    int* mergeSortArray;
    int sizeOfTheArray;
    cout << "Enter the size(how many elements) you want to sort: " << endl;
	cin >> sizeOfTheArray;
    cout << endl;

    mergeSortArray = new int[sizeOfTheArray];
    auto startTime = chrono::high_resolution_clock::now();

    printsOutNumbersOfTheArrayBeforeSorted(mergeSortArray, sizeOfTheArray);
	recursionMergeSort(mergeSortArray, 0, sizeOfTheArray - 1);
    printsOutNumbersOfTheArrayAfterSorted(mergeSortArray, sizeOfTheArray);

    auto endTime = chrono::high_resolution_clock::now();
    auto durationInMS = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << "Time taken to run the algorithm: " << durationInMS.count() << " milliseconds" << endl;

    delete[] mergeSortArray;

    return 0;
}

/// <summary>
/// This if a recursive function that fist divides the array in the middle. 
/// Then the function calls the left part of the function, then the right part of the function. 
/// Then the function calls the mergeSort function to merge the sorted arrays. 
/// As long mostLeftIndex are less then mostRightIndex the recursion continues.
/// </summary>
/// <param name="mergeSortArray"> This is the array that is going to be divided</param>
/// <param name="mostLeftIndex"> This is the index most left in the array (The first element)</param>
/// <param name="mostRightIndex"> This is the index most right in the array.(The last element)</param>
void recursionMergeSort(int* mergeSortArray, int mostLeftIndex, int mostRightIndex)
{
    int midOfTheArray;
    if (mostLeftIndex < mostRightIndex) 
    {

        midOfTheArray = (mostLeftIndex + mostRightIndex) / 2; //Divides the array in the middle
        recursionMergeSort(mergeSortArray, mostLeftIndex, midOfTheArray); //Calls the left portion of the array
        recursionMergeSort(mergeSortArray, midOfTheArray + 1, mostRightIndex);//Calls the right potion of the array
       
        mergeSort(mergeSortArray, mostLeftIndex, midOfTheArray, mostRightIndex); // Here we merge the sorted arrays. 
    }
}

/// <summary>
/// This function does the sorting of the divided sub arrays. 
/// After that it merge the subarrays into one sorted array.
/// Here we create temporary array so we won't overwrite or lose data.
/// </summary>
/// <param name="mergeSortArray"> This is the array to be sorted</param>
/// <param name="mostLeftIndex"> This is the index most left in the array (The first element) </param>
/// <param name="midOfTheArray"> This is the middle part if the array </param>
/// <param name="mostRightIndex"> This is the index most right in the array.(The last element) </param>
void mergeSort(int* mergeSortArray, int mostLeftIndex, int midOfTheArray, int mostRightIndex)
{
    int i = mostLeftIndex;
    int j = midOfTheArray + 1;
    int k = mostLeftIndex;
    int capacity = 50000;
    int size = 0;
    int* temporaryArray = NULL;
    temporaryArray = new int[capacity]; //Dynamic array

    while (i <= midOfTheArray && j <= mostRightIndex) {
        if (mergeSortArray[i] < mergeSortArray[j]) {
            temporaryArray[k] = mergeSortArray[i];
            k++;
            i++;
        }
        else {
            temporaryArray[k] = mergeSortArray[j];
            k++;
            j++;
        }
    }
    while (i <= midOfTheArray) {
        temporaryArray[k] = mergeSortArray[i];
        k++;
        i++;
    }
    while (j <= mostRightIndex) {
        temporaryArray[k] = mergeSortArray[j];
        k++;
        j++;
    }
    for (i = mostLeftIndex; i < k; i++) {
        mergeSortArray[i] = temporaryArray[i];
    }
}

/// <summary>
/// This function prints out in the console window the integers in the array before sorted. 
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted </param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains </param>
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

/// <summary>
/// This function prints out in the console window the integers in the array after sorted. 
/// </summary>
/// <param name="selectionSortArray"> The array that is beeing sorted </param>
/// <param name="sizeOfTheArray"> How large the array is, how many elements the array contains </param>
void printsOutNumbersOfTheArrayAfterSorted(int* mergeSortArray, int sizeOfTheArray)
{
    cout << "Sorted array: " << endl;
    for (int i = 0; i < sizeOfTheArray; i++)
    {
        if (mergeSortArray == nullptr)
        {
            cerr << "The memory allocation failed." << endl;
            return;
        }
        cout << mergeSortArray[i] << " ";
    }
    cout << endl << endl;
}


