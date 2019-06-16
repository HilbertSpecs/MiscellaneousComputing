//This Application will Discretized the EigenBasis generated in BasisGenerator.cpp the output file EigenVect.dat will be the input file for 
// 	this program.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;


//declare variables
fstream dataFile1, dataFile2;
string input;
double *eigenVect;
int i, j, N, M;
double mini, maxi, step;
//function prototypes
void initialize();
void hashTable();
void deallocate();

//main function
int main()
{
    initialize();
	return 0;

}

//function definitions
void initialize()
{
    i = 0;
    
    
    dataFile1.open("EigenVect.txt", ios::in);
    dataFile2.open("EigenDiscretization.txt", ios::out);
    
    if(dataFile1)
    {
        getline(dataFile1, input, '\n');
        i++;
        
        while(dataFile1)
        {
            //cout << input << endl;
            getline(dataFile1, input, '\n');
            i++;
            
        }
        
        cout << "The Number of EigenVectors generated that need to be Discretized individually are " << i << " Vectors " << endl;
        
        M = i;
        
    }
    
    else
    {
        cout << "ERROR: Cannot open File.\n";
    }
    
    cout << "What would you like the Step-Size of your Grid to be? " << endl;
    cin >> step;
    cout << "Over what domain would you like to Generate the Finite Difference grid over? (mini, maxi)" << endl;
    cin >> mini;
    cin >> maxi;
    
    
    N = (maxi - mini)/ step;
    cout << "The Number of Nodes on Each EigenVect will be " << N << " generated over the domain of (" << mini << "," << maxi << ")." << endl;
    
    
    eigenVect = new double[N];
    
    eigenVect[0] = 0;
    for(j= 1; j < N ;j++)
    {
        eigenVect[j] = step + eigenVect[j-1];
        cout << "step: " << j << ": " << eigenVect[j] << endl;
        dataFile2 << eigenVect[j] << endl;
        
    }
    
    dataFile1.close();
    dataFile2.close();
}

