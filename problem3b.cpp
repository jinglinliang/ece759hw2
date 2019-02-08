#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 3){
        cout << "Wrong usage!" << endl;
        exit(1); 
    }

    int size1 = atoi(argv[1]);
    int size2 = atoi(argv[2]);
    int size3 = size1 - size2 + 1;

    ifstream inFile;
    
    inFile.open("problem3.dat");
    if (!inFile) {
        cout << "Unable to open file"<<endl;
        exit(1); // terminate with error
    }

    int *matrix = new int[size1*size1];
    int *feature = new int[size2*size2];

    //read matrix
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size1; j++){
            inFile >> matrix[i*size1 + j];
        }
    }

    //read feature
    for (int i = 0; i < size2; i++){
        for (int j = 0; j < size2; j++){
            inFile >> feature[i*size2 + j];
        }
    }

    inFile.close();

    //compute res
    float globalMax = -(1 << 31);
    int outi = 0;
    int outj = 0;
    for (int i = 0; i < size3; i++){
        for (int j = 0; j < size3; j++){
            float score = 0;
            for (int x = 0; x < size2; x++) {
                for (int y = 0; y < size2; y++) {
                    score += feature[x*size2 + y] * matrix[(i+x)*size1 + (j+y)];
                }
            }
            if (score > globalMax) {
                globalMax = score;
                outi = i;
                outj = j;
            }
        }
    }

    cout << outi << endl;
    cout << outj << endl;
    cout << globalMax << endl;
     
    delete[] matrix;
    delete[] feature;

}