//This Program will be used to generate M-Dimensional Random Sequences of Numbers which will
//  then be used to Generate Random Binary Sequences on a Keep-Toss Condition.  Would like for Program to 
//    determine at run-time the Number of Random Sequences or Binary Coin Sequences [M] of Length [N].


/* Update 9/23/18 Must be Square Matrix for coin[i][j] and binaryRan[i][j] Random Binary Coins will be written to BinarySequence.dat and the prompt input is overwritten by whatever parameters are in the randomMessage_gen() */


#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<random>
#include<cstdlib>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;


//declare variables
int i, j, M, N, mini, maxi, base, permutations, coinNum, bitstring_length;
int **coin, **binaryRan;
fstream dataFile1, dataFile2;

//function prototypes
void initialize();
void randomMessage_gen(int, int, int, int);
void deallocate();

//int main
int main()
{
    initialize();
    randomMessage_gen(64, 64, 0, 1000000);
    deallocate();

    return 0;
}


//function definitions

void initialize()
{
    /*
    
     
     cout << "How Many RandomCoins would you like to generate today?" << endl;
    cin >> M;
    cout << "How many Bits would you Like your RandomCoin to Be? " << endl;
    cin >> N;
    cout <<"Please Enter a RandomCoinRange for your Random Binary Sequence." << endl;
    
    cin >> mini;
    cin >> maxi;
    
    cout << M << " RandomCoins will be generated of Bit Length " << N << ". " << "The CoinRange is between " << mini << " and " << maxi << endl;
    
    */
    
    
    //dataFile1.open("CoinSequence.dat", ios::out);
    dataFile2.open("BinarySequence.dat", ios::out);
    
}

void randomMessage_gen(int coinNum, int bitstring_length,int coinMin,int coinMax)
{
    M = coinNum;
    N = bitstring_length;
    mini = coinMin;
    maxi = coinMax;
    
    binaryRan = new int*[M];
    for(i=0; i< M;i++)
        binaryRan[i] = new int[N];
    for(i=0; i < M;i++)
    {
        for(j=0;j < N;j++)
        {
            binaryRan[i][j] = 0;
            //cout << binaryRan[i][j] << "\t";
        }
        
        //cout << endl;
    }
 
    coin = new int*[M];
    for(i=0;i< N;i++)
        coin[i] = new int[N];
    for(i=0;i<M;i++)
    {
        for(j=0; j < N;j++)
        {
            coin[i][j] =0;
            //cout << coin[i][j] << "\t";
        }
        
        //cout << endl;
    }
    
    cout << "Coin Min: " << mini << endl;
    cout << "Coin Max: " << maxi << endl;
    cout << "Num Coins: " << M << endl;
    cout << "SequenceLength:" << N << endl;

    cout << "A Random CoinSequence of " << M << " Coins will be Generated. " << endl;
    cout << "Each CoinSequence will be " << N << " Bits in Length." << endl;
    
    for(i=0; i < M;i++)
    {
        for(j = 0; j < M;j++)
        {
            coin[i][j] = (rand()% maxi) + mini;
            //cout << coin[i][j] << "\t";
            
        }
        
        //cout << endl;
    }
    for(i=0; i < M;i++)
    {
        cout << "Random_Coin_Flip: " << i << ": ";
        
        for(j=0; j < N;j++)
        {
        if(coin[i][j] < maxi/2)
            binaryRan[i][j] = 0;
        else if(coin[i][j] >= maxi/2)
            binaryRan[i][j] = 1;
        else
            cout << "ERROR: With Coin Flip Conditional Algorithm!" << endl;
        
        cout << binaryRan[i][j];
        }
        cout << endl;
    }
    
    cout << "The Coin[i][j] and Random BinarySequence[i][j] will be written to an Independent Output File." << endl;
    
    for(i = 0;i < M;i++)
    {
        for(j = 0;j < N;j++)
        {
            dataFile1 << coin[i][j] << "\t";
            dataFile2 << binaryRan[i][j];
        }
        
        dataFile1 << endl;
        dataFile2 << endl;
    }
}

void deallocate()
{
    for(i = 0;i < M;i++)
        delete coin[i];
    delete [] coin;
    
    for(i=0; i < M;i++)
        delete  binaryRan[i];
    delete[] binaryRan;
    
    
    dataFile1.close();
    dataFile2.close();
}

