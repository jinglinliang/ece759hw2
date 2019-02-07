#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int generate() { //random return 1 or -1

    if (rand() < 0.5*RAND_MAX) {
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) { 
    
    if (argc < 3){
        cout << "Wrong usage!" << endl;
        exit(1); 
    }
    int size1 = atoi(argv[1]);
    int size2 = atoi(argv[2]);

    /* initialize random seed: */
    srand (time(NULL));

    ofstream outfile ("problem3.dat");

    //First matrix
    for (int i=0; i < size1; i++){
        for (int j = 0; j < size1; j++){
            outfile << generate() << ' ';
        }
        outfile << endl;
    }

    //Second matrix
    for (int i=0; i < size2; i++){
        for (int j = 0; j < size2; j++){
            outfile << generate() << ' ';
        }
        outfile << endl;
    }
    outfile.close();
}

