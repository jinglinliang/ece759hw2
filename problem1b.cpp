#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n) 
{ 
    ofstream outfile ("problem1.out");
    int i; 
    for (i=0; i < n; i++){
        outfile << arr[i] << endl;
    }
    outfile.close();
       
} 


  
int main() { 
    ifstream inFile;
    
    inFile.open("problem1.in");
    if (!inFile) {
        cout << "Unable to open file"<<endl;
        exit(1); // terminate with error
    }
    int size;
    inFile >> size;
    cout << size <<endl;
    
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        inFile >> arr[i];
    }

    inFile.close();
    
    // Record start time
    auto start = chrono::high_resolution_clock::now();

    sort(arr, arr+size);

    // Record end time
    auto finish = chrono::high_resolution_clock::now();
  
    printArray(arr, size); 
    cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(finish - start).count()
		<< " ms" << endl;

    // cout << "Elapsed time in nanoseconds : " 
	// 	<< chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
	// 	<< " ns" << endl;
    
    return 0; 
} 

