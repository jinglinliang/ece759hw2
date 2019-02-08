#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

void printArray(int arr[], int n) 
{ 
    ofstream outfile ("problem2.out");
    int i; 
    for (i=0; i < n; i++){
        outfile << arr[i] << endl;
    }
    outfile.close();
       
} 


int* myScan(int array[], int n) { //my insertion sort
    int *newarr = new int[n];
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < i; j++){
            sum = sum + array[j];
        }
        newarr[i] = sum;
    }
    return newarr;
} 
  
int main(int argc, char *argv[]) { 
    ifstream inFile;
    if (argc < 2){
        cout << "Wrong usage!" << endl;
        exit(1); 
    }
    inFile.open(argv[1]);
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

    int *newarr = myScan(arr, size); 

    // Record end time
    auto finish = chrono::high_resolution_clock::now();
  
    printArray(newarr, size); 

    cout << newarr[size-1] << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(finish - start).count() << endl;

    // cout << "Elapsed time in nanoseconds : " 
	// 	<< chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
	// 	<< " ns" << endl;
    delete[] arr;
    delete[] newarr;
    return 0; 
} 

