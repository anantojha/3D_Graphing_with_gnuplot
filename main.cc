#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

#include "gnuplot_i.hpp"
#include "Linear_Regression.h"




using namespace std;


int main(int argc, char* argv[]){
   
	// Create some points to plot
	/*
	string src;
	if(argc < 1){
		cout << "Enter file name as argument: " << endl;
		return 0;
	}
	else if (argc == 2){
		src = argv[1];	
	}
	else { 
		cout << "too mant arguments" << endl;
		return 0;
	}
	*/

  	double xVal, yVal, zVal;
 	vector<double> x;
        vector<double> y;	
	//vector<double> z;
	string path("~/Desktop/gnuplot-cpp_2/");
	ifstream file;
	file.open("data/data_2D.txt");
	int i =0;
	

	while(file >> xVal >> yVal){
		cout <<  xVal << setw(5) << yVal <<  endl; 
		x.push_back(xVal);
		y.push_back(yVal);
		//zdata[i] = zVal*100;
		i++;	
	}

	Linear_Regression lreg(&x,&y);
	string equ = lreg.getEquation();


	//cout << equ << endl;

  	try {
    		Gnuplot gp;
		gp.cmd("set terminal x11 size 1000, 650");
    		
    		gp.set_style("lines").set_smooth();
    		gp.set_xlabel("x");
    		gp.set_ylabel("y");
		//gp.set_zlabel("xy");

    		
		gp.plot_equation(equ).set_style("points").set_pointsize(2.0).plot_xy(x,y);

		cout << "Press Enter to quit...";
    		cin.get();

    		return 0;
  	}

  	catch (const GnuplotException& error) {
		// Something went wrong, so display error message
    		cerr << error.what() << endl;
    		return 1;	
	}


};



