
//This program simulates a random walker in 3D, a walker makes several trial steps with a given number of steps per trial.  Prints to multiple output files.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;

int i, a, b, n, position_x, position_y, position_z, position_r, max_trials, number_walks , *walk_cumulativex , *walk_cumulativey , *walk_cumulativez, *walk_cumulativer, *walk2_cumulativex, *walk2_cumulativey, *walk2_cumulativez, *walk2_cumulativer;
double xaverage, yaverage, zaverage, ran_numx, ran_numy, ran_numz, ran_numr, move_probability, c;

void initialize();
void mc_sampling(int, int, double);
void output(int, int);



int main()
{
    
    initialize();
    
    walk_cumulativex = new int[number_walks + 1];
    walk_cumulativey = new int[number_walks +1];
    walk_cumulativez = new int[number_walks +1];
    walk_cumulativer = new int[number_walks +1];
    
    walk2_cumulativex = new int[number_walks + 1];
    walk2_cumulativey = new int[number_walks +1];
    walk2_cumulativez = new int[number_walks +1];
    walk2_cumulativer = new int[number_walks +1];
    
    for(i = 1; i <= number_walks; i++)
    {
        walk_cumulativex[i] = 0;
        walk_cumulativey[i] = 0;
        walk_cumulativez[i] = 0;
        walk_cumulativer[i] = 0;
        
        walk2_cumulativex[i] = 0;
        walk2_cumulativey[i] = 0;
        walk2_cumulativez[i] = 0;
        walk2_cumulativer[i] = 0;
        
    }
    
    mc_sampling(max_trials, number_walks, move_probability);
    output(max_trials, number_walks);
    
    delete [] walk_cumulativex;
    delete [] walk_cumulativey;
    delete [] walk_cumulativez;
    delete [] walk_cumulativer;
    delete [] walk2_cumulativex;
    delete [] walk2_cumulativey;
    delete [] walk2_cumulativez;
    delete [] walk2_cumulativer;
    
    return 0;
    
    
}



void initialize()
{
    cout << "Number of Monte Carlo Trials:";
    cin >> a;
    cout << "Number of attempted walks: ";
    cin >> b;
    cout << "Move Probability: ";
    cin >> c;
    
    max_trials =a;
    number_walks = b;
    move_probability =c;
    
    
    
    
    cout << "Number of Monte Carlo Trials= " << max_trials << endl;;
    cout << "Number of attempted walks= " << number_walks << endl;
    cout << "Move Probability= " << move_probability << endl;
    
}

void mc_sampling(int max_trials, int number_walks, double move_probability)
{
    
    ofstream ofile0;
    ofstream ofile5;
    ofstream ofile6;
    ofstream ofile7;
    
    
    ofile0.open("RanNumbers.dat");
    ofile5.open("RanPositions.dat");
    ofile6.open("WalkCumulative.txt");
    ofile7.open("Walk2Cumulative.txt");
    
    
    for(n = 1; n <= max_trials; n++)
    {
        int position_x = 0;
        int position_y = 0;
        int position_z = 0;
        int position_r = 0;
        
        
        ofile5 << n << endl;
        ofile6 << n << endl;
        ofile7 << n << endl;
        
        for(i = 1; i <= number_walks; i++)
        {
            
            ran_numx = rand()/(double) RAND_MAX;
            ran_numy = rand()/(double) RAND_MAX;
            ran_numz = rand()/(double) RAND_MAX;
            ran_numr = sqrt(pow(ran_numx, 2)+pow(ran_numy,2)+pow(ran_numz,2));
            
            if(ran_numx <= move_probability)
                position_x += 1;
            if(ran_numy <= move_probability)
                position_y += 1;
            if(ran_numx > move_probability)
                position_x -= 1;
            if(ran_numy > move_probability)
                position_y -= 1;
            if(ran_numz <= move_probability)
                position_z += 1;
            if(ran_numz > move_probability)
                position_z -= 1;
            else
                NULL;
            
            ofile0 << n << setw(15) << i << setw(15) << ran_numx << setw(15) << ran_numy << setw(15) << ran_numz << setw(15) << ran_numr << endl;
            ofile5 << n << setw(15) << i << setw(15) << position_x << setw(15) << position_y << setw(15) << position_z << endl;
            
            walk_cumulativex[i] += position_x;
            walk2_cumulativex[i] += pow(position_x, 2);
            walk_cumulativey[i] += position_y;
            walk2_cumulativey[i] += pow(position_y,2);
            walk_cumulativez[i] += position_z;
            walk2_cumulativez[i] += pow(position_z,2);
            walk_cumulativer[i] = sqrt(pow(walk_cumulativex[i],2)+pow(walk_cumulativey[i],2)+pow(walk_cumulativez[i],2));
            walk2_cumulativer[i] = pow(walk_cumulativex[i],2)+pow(walk_cumulativey[i],2)+pow(walk_cumulativez[i],2);
            
            
            
            
            ofile6 << n << setw(15) << i << setw(15) << walk_cumulativex[i] << setw(15) << walk_cumulativey[i] << setw(15) << walk_cumulativez[i] << setw(15) << walk_cumulativer[i] << endl;
            ofile7 << n << setw(15) << i << setw(15) << walk2_cumulativex[i] << setw(15) << walk2_cumulativey[i] << setw(15) << walk2_cumulativez[i] << setw(15) << walk2_cumulativer[i] << endl;
            
            
        }
        
    }
    ofile0.close();
    ofile5.close();
    ofile6.close();
    ofile7.close();
}

void output(int max_trials, int number_walks)
{
    ofstream ofile1("testwalkers1.dat");
    ofstream ofile2("testwalkers2.dat");
    ofstream ofile3("testwalkers3.txt");
    ofstream ofile4("testwalkers4.txt");
    
    for(int i = 1; i <= number_walks; i++)
    {
        
        double xaverage = walk_cumulativex[i]/ ((double) max_trials);
        double x2average = walk2_cumulativex[i]/((double) max_trials);
        double variancex = (x2average - pow(xaverage,2));
        
        double yaverage = walk_cumulativey[i]/((double) max_trials);
        double y2average = walk2_cumulativey[i]/((double) max_trials);
        double variancey = (y2average - pow(yaverage,2));
        
        double zaverage = walk_cumulativez[i]/((double) max_trials);
        double z2average = walk2_cumulativez[i]/((double) max_trials);
        double variancez = z2average - pow(zaverage,2);
        
        double raverage = walk_cumulativer[i]/((double) max_trials);
        double r2average = walk2_cumulativer[i]/((double) max_trials);
        double variancer = (r2average - pow(raverage, 2));
        
        ofile1 << setiosflags(ios :: showpoint | ios :: uppercase);
        ofile2 << setiosflags(ios :: showpoint | ios :: uppercase);
        //ofile1 << setw(6) << i;
        ofile1 << setw(15) << setprecision(8) << xaverage << setw(15) <<  yaverage << setw(15) << zaverage << setw(15) << endl;
        //ofile2 << setw(6) << i ;
        ofile2 << setw(15) << setprecision(8) << variancex << setw(15) << variancey << setw(15) << variancez << setw(15) << variancer << endl;
        ofile3 << setw(6) << i << ",";
        ofile3 << setw(15) << "," << setprecision(8) << xaverage << setw(15) << "," <<  yaverage << setw(15) << "," << zaverage << setw(15) << "," << raverage << endl;
        ofile4 << setw(6) << i << ",";
        ofile4 << setw(15) << "," << setprecision(8) << variancex << setw(15) << "," << variancey << setw(15) << "," << variancez << setw(15) << "," << variancer << endl;
        
    }
    
    ofile1.close();
    ofile2.close();
    ofile3.close();
    ofile4.close();
}
