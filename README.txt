				MAC OSX Terminal


This program was originally written in 1D and used a different random number generator.
I converted the Random Number Generator to A function I had access to and then Expanded the Random Walker to 3 Dimensions.
Move Probability should be set at “.5” for accurate results. 
Number of Walks should be greater than 1000.
Number of Trials should be at least 100.
As you increase the number of walks and trials answer approaches greater precision.





Source Code: RandomWalker_3D.cpp
Compile: g++ RandomWalker_3D.cpp
Execute: ./a.out

Output Files:	RanNumbers.dat
		RanPositions.dat
		WalkCumulative.txt
		Walk2Cumulative.txt
		testwalkers1.dat
		testwalkers2.dat
		testwalkers3.txt
		testwalkers4.txt
		
Random Walk in 3D can be visualized by plotting ‘testwalkers1.dat’ in 3D GNUplot splot.

>gnuplot
>set terminal x11
>splot ‘testwalkers1.dat’


