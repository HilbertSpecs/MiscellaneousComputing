//This Program will Generate a Set of Sequential Basis Vectors in M Dimensions of an N-Bit Length Basis Vector
//   The M Dimensional Vector Space will be spanned by a complete set of EigenVectors which are the 
//      Complete set of Permutations for the Corresponding N-Bit Length Binary Vector.
//Convert Binary Count and Binary Adder to a String use addBitString() store ith result into eigenVect[i].


/* Update 9/23/18 Have created a Binary Counter All of the questions at the command prompt are overwritten by the 
    parameters in the generateBinaryBasis() at run-time need to extract some parameters after basis generated to 
        display to user the dimension of the space generated.  Also I want to discretize each eigenvector in steps
            of delEig = .001, .00001, .000001, etc.  Can dynamically generated an array for each eigenVector and [N] and then Discretized each eigenVect[i] for all N.  M-times creating N dynamic arrays of Length         
                    M [M]. */

// Note:*****  The New features should be written in New Functions do not go back into existing functions and make any changes.


#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>
#include<random>
#include<string>
#include<stdio.h>
using namespace std;


//declare varialbes

int i, j, M, N, mini, maxi, dim, basis_dimen, bit_length, maxVect, base, input1, input2;
long long int classic_perm, quantum_perm, perm;
int *bin_counter, *bin_adder, *coin, *binaryRan;
char *binCount, *binAdd, *eigenVect;
string Regime, IntCounter, Counter, Adder, read3, read4, Sum;
fstream dataFile1, dataFile2, dataFile3, dataFile4, dataFile5;

int number_vectors;

//function prototypes
int initialize();
//void generateBinaryBasis(int maxDim, int bit, string);
void generateBinaryBasis();
void reverse(char, int);
char* itoa(int, char*, int);
int makeEqualLength(string &, string &);
void a();
string addBitStrings(string, string);
void deallocate();
//int main
int main()
{
    IntCounter = "0";
    Adder = "1";
    base = 2.0;
    initialize();
    generateBinaryBasis();
    cout << "<Binary_Generated_Basis>: " << number_vectors << " Vectors Generated." << endl;
    cout << "Binary_Basis_Vector: 1: " << IntCounter << endl;
    dataFile2 << IntCounter << endl;
    Counter = addBitStrings(IntCounter, Adder);
    cout << "Binary_Basis_Vector: 2: " << Counter << endl;
    dataFile2 << Counter << endl;
    for(i =2; i < number_vectors ;i++)
    {
        string Sum = addBitStrings(Counter, Adder);
        cout << "Binary_Basis_Vector: " << i+1 << ": " << Sum << endl;
        dataFile2 << Sum << endl;
        Counter = Sum;
    }
    deallocate();

    return 0;
}
//function definitions
int initialize()
{
    cout << "How Many Binary Representation Basis Vector's would you like to Generate?" << endl;
    cin >> number_vectors;
    /*
     
     cout << "What Dimension Binary Represenatation of Basis Vectors would you Like to Generate? " << endl;
    cin >> basis_dimen;

    cout << "How Many Bits would you like to Represent your Basis Vectors? " << endl;
    cin >> bit_length;
    
    cout << "Do you want to Operate in Classical Binary Space or Quantum Binary Space? " << endl;
    cin >> Regime;
    
    if(Regime == "Classical")
    {
        classic_perm = basis_dimen;
        perm = classic_perm;
        cout << "User Has Chosen Classical Regime: Program will Generate a Complete Set of OrthoNormal Binary Representation Basis Vectors counting from 0 to " << basis_dimen << " in Numerical Binary Representation." << endl;
    }
    else if(Regime =="Quantum")
    {
        quantum_perm = pow(2, bit_length);
        perm = quantum_perm;
        cout << "Program will Generate a Complete Set Of OrthoNormal Binary Representation Basis Vectors Counting from 0 to " << perm << " in Numerical Binary Representation." << endl;
    }
    else
        cout << "ERROR in Regime Choice: Input IS Case Sensitive." << endl;
    */
    
    
    //dataFile1.open("SystemOutput.dat",ios::out);
    dataFile2.open("EigenVect.txt",ios::out);
    //dataFile3.open("BitCount.txt", ios::out|ios::in);
    //dataFile4.open("BitAdd.txt",ios::out|ios::in);
    //dataFile5.open("StringSumBasis.txt", ios::in|ios::out);
    return number_vectors;
}
void generateBinaryBasis()
{
    
    dim = 3;
    bit_length = 8;
    
    
    //cout << "N:" << dim << endl;
    //cout << "Basis Dem:" << basis_dimen << endl;
    //cout << "Permutations: " << perm << endl;
    
    bin_counter = new int[bit_length];
    bin_adder = new int[bit_length];
    binCount = new char[bit_length];
    binAdd = new char[bit_length];
    eigenVect = new char[perm];
    
    //cout << "Below is the Initialized Bin Counter all Bits in Sequence should be set to 0." << endl;
    for(i=0; i < basis_dimen; i++)
    {
        bin_counter[i] = 0;
        //cout << bin_counter[i];
    }
    //cout << endl;
    //cout << "Generating Binary Adder of Equal Counter Length..." << endl;
    for(i=0; i < basis_dimen; i++)
    {
        if(i == (basis_dimen -1))
            bin_adder[i] = 1;
        else
            bin_adder[i] = 0;
        
    }
    
    //cout << "Below is Binary Adder of " << basis_dimen << " Bit Length." << endl;
    //for(i=0; i < basis_dimen; i++)
        //cout << bin_adder[i];
    //cout << endl;
    
    //cout << "Now we will Start building our Basis Vector's one-by-one by adding in binary. The binary-Adder to the binary-Counter over however many permutations there are for (0,1) in a N Bit-Length Vector." << endl;
    
    //cout << "Bit String Length: " << basis_dimen << endl;
    //cout << "Permutations: " << perm << endl;
    
    //cout << "int bin_counter[]: ";
    //for(i=0;i< bit_length;i++)
        //cout << bin_counter[i];
    //cout << endl;
    
    //cout << "int bin_adder[]: ";
    //for(i=0; i < bit_length;i++)
        //cout << bin_adder[i];
    
    //dataFile1 << "char binCount[]: ";
    for(i =0; i < bit_length; i++)
    {
        int inputCount = bin_counter[i];
        dataFile3 << itoa(inputCount, binCount, base);
    }
    dataFile3 << endl;
    
    //dataFile2 << "char binAdd[]: ";
    for(i=0;i < bit_length;i++)
    {
        int inputAdd = bin_adder[i];
        dataFile4 << itoa(inputAdd,binAdd,base);
    }
    dataFile4 << endl;
    //cout << endl;
    

}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}


char* itoa(int num, char* str, int base)
{
    
    int i = 0;
    bool isNegative = false;
    
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
    
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
    
    str[i] = '\0'; // Append string terminator
    
    // Reverse the string
    reverse(str, i);
    
    return str;
    
}
int makeEqualLength(string &first, string &second)
{
    int len1 = first.size();
    int len2 = second.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            first = '0' + first;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            second = '0' + second;
    }
    return len1; // If len1 >= len2
}


string addBitStrings(string first, string second)
{
    
    string result;  // To store the sum bits
    
    // make the lengths same before adding
    int length = makeEqualLength(first, second);
    
    int carry = 0;  // Initialize carry
    
    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        
        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        
        result = (char)sum + result;
        
        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
    
    // if overflow, then add a leading 1
    if (carry)
        result = '1' + result;
    
    return result;
    
}

void deallocate()
{
    delete [] bin_counter;
    delete [] bin_adder;
    delete [] coin;
    delete [] binaryRan;
    delete [] eigenVect;
    
    perm = 0;
    mini = 0;
    maxi = 0;
    dim = 0;
    bit_length = 0;
    input1=0;
    input2=0;
    Regime = "0";
    Counter = "0";
    Sum = "0";
    
    dataFile1.close();
    dataFile2.close();
    dataFile3.close();
    dataFile4.close();
    dataFile5.close();
}


