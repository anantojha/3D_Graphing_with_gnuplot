#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <string>

using namespace std;


class Linear_Regression{

	public:
		Linear_Regression(vector<double>* x_in, vector<double>* y_in);
		string getEquation();
		void getEquVect(vector<double>* v);
	private:
		//functions
		string performRegression();
		double calculateSum(vector<double>* v);
		double calculateAvg(vector<double>* v);
		vector<double> x;
		vector<double> y;
		vector<double> equation;
};


#endif

