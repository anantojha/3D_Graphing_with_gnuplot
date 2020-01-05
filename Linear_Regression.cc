#include "Linear_Regression.h"
#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

Linear_Regression::Linear_Regression(vector<double>* x_in, vector<double>* y_in){
	x = (*x_in);
	y = (*y_in);
};

string Linear_Regression::getEquation(){
	return performRegression();
}

void Linear_Regression::getEquVect(vector<double>* v){
	(*v) = equation;
}

string Linear_Regression::performRegression(){
	string equ = "x";

	double a_val, m_val, b_val;
	double xBar, yBar, multi_sum, x_squared_sum, y_squared_sum;
	double r, sy, sx;
	vector<double> X_Minus_Xbar;
	vector<double> Y_Minus_Ybar;
	vector <double> xVec_multi_yVec;
	vector<double> x_Squared;
	vector<double> y_Squared;

	xBar = calculateAvg(&x);
        yBar = calculateAvg(&y);
	
	//cout << "xbar: " << xBar << " ybar: " << yBar<< endl;
	
	
	for(int i = 0; i<x.size(); i++){
	
		X_Minus_Xbar.push_back(x.at(i)-xBar);
		Y_Minus_Ybar.push_back(y.at(i)-yBar);
	}
	for(int i=0; i<x.size(); i++){
		xVec_multi_yVec.push_back(X_Minus_Xbar.at(i)*Y_Minus_Ybar.at(i));
                x_Squared.push_back(X_Minus_Xbar.at(i)*X_Minus_Xbar.at(i));
                y_Squared.push_back(Y_Minus_Ybar.at(i)*Y_Minus_Ybar.at(i));
	}

	multi_sum = calculateSum(&xVec_multi_yVec);
	x_squared_sum = calculateSum(&x_Squared);
	y_squared_sum = calculateSum(&y_Squared);
	
	//cout << "multi_sum: " << multi_sum << endl;
	//cout << "x_squared_sum: " << multi_sum << endl;
	//cout << "y_squared_sum: " << multi_sum << endl;


	r =  (multi_sum)/sqrt(x_squared_sum*y_squared_sum);
	sy = sqrt(y_squared_sum/((y.size()-1)));
	sx = sqrt(x_squared_sum/((x.size()-1)));

	//cout << "r: " << r << endl;
        //cout << "sy: " << sy << endl;
        //cout << "sx: " << sx << endl;
	
	
	b_val = r*(sy/sx);
	a_val = yBar - (b_val*xBar);

	//cout << "b_val: " << b_val << endl;
        //cout << "a_val: " << a_val << endl;

	
	equation.push_back(a_val);
	equation.push_back(b_val);

	ostringstream strs;
	if(a_val < 0)
		strs << b_val << "*x" << a_val;
	else
		strs << b_val << "*x+" << a_val;
	equ = strs.str();
	cout << equ << endl;
	return equ;

	
};

double Linear_Regression::calculateAvg(vector<double>* v){
	return calculateSum(v)/v->size();
}

double Linear_Regression::calculateSum(vector<double>* v){
	double sum = 0;
	for(int i =0; i<v->size(); i++)
		sum += v->at(i);
	//cout << "sum: " << endl; 
	return sum;
}
