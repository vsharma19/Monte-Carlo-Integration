//includes various libraries
#include <iostream>
#include <string>
#include <random>
#include <math.h>
#include <time.h>

using namespace std;

//declares function calculateArea, which will take 2 doubles and 2 integers and return a double
double calculateArea(double lowerBound, double upperBound, int functionNumber, int iterations);

// code inside main will be executed
int main() {
	//initiates user input variables
	int functionNumber;
	double lowerBound;
	double upperBound;
	int iterations;

	// this is the condition to exit the while loop. if the user doesnt want to integrate again, the user will enter 0 and the condition will turn to false, leaving the loop
	bool userAgain = 1;
	
	// this function makes rand() produce random numbers every time rand() is called
	srand(time(0));

	cout << "Welcome! ";

	// this while loops allows the user to integrate multiple times
	while (userAgain) {

		// allows user to pick desired function to integrate, input lowerBound, upperBound, and number of iterations
		cout << "Please select a function to numerically integrate from the options below." << endl << endl;

		cout << "1. |sin(x^2)|" << endl << "2. e^(-x^2)" << endl << "3. |arctan(x)|" << endl << endl;

		cout << "Integrate function number: ";

		cin >> functionNumber;

		cout << endl << endl << "Please specify a lower bound: ";
		cin >> lowerBound;

		cout << "Please specify an upper bound: ";
		cin >> upperBound;

		cout << "Please specify the number of iteration: ";
		cin >> iterations;

		//initates variable areaUnderCurve and sets it equal to the output of calculateArea
		double areaUnderCurve = calculateArea(lowerBound, upperBound, functionNumber, iterations);

		//this set of if/if else statements outputs different sentences based on the function the user chose
		if (functionNumber == 1) {
			cout << endl << endl <<  "The estimate for the area of |sin(x^2)| from " << lowerBound << " to " << upperBound << " is " << areaUnderCurve << endl;
		}
		else if (functionNumber == 2) {
			cout << endl << endl << "The estimate for the area of e^(-x^2) from " << lowerBound << " to " << upperBound << " is " << areaUnderCurve << endl;

		}
		else {
			cout << endl << endl << "The estimate for the area of |arctan(x)| from " << lowerBound << " to " << upperBound << " is " << areaUnderCurve << endl;

		}
		
		// allows user to integrate again
		cout << endl << endl << "Would you like to integrate again? Enter 0 for 'no' and 1 for 'yes': ";

		cin >> userAgain;

		cout << endl << endl;

	}

	// exits program
	return 0;
}


/** estimates the area under the curve between the desired bounds
    @param lowerBound is the lower bound
	@param upperBound is the upper bound
	@param functionNumber is the number of the function the user picked
	@param iterations is the number of iterations the user wants to run

*/

double calculateArea(double lowerBound, double upperBound, int functionNumber, int iterations) {
	
	// initiates variable boxArea as double
	double boxArea;

	// these if statements calculate the area of the box depending on the function chosen
	if (functionNumber == 1) {
		boxArea = (upperBound - (lowerBound)) * 1;
	}
	if (functionNumber == 2) {
		boxArea = (upperBound - (lowerBound)) * 1;
	}
	if (functionNumber == 3) {
		boxArea = (upperBound - (lowerBound)) * 3.1415926 / 2;
	}

	// initiates a counter variable pointUnderCurve which will count the number of points within the area of the curve
	int pointUnderCurve = 0;

	

	// this for loop iterates as many times as the user wants, creating random numbers and testing if the points are within the area of the curve
	for (int iterator = 0; iterator < iterations; ++iterator) {

		// these two lines of code create a random x value between the lower and upper bounds
		double x = static_cast<double>(rand()) / RAND_MAX;
		x = (upperBound - lowerBound) * x + lowerBound;

		// runs code if user wanted to integrate first function 
		if (functionNumber == 1) {
			
			// makes the random x into x^2, so that the sin function does not become cluttered and unreadable below
			x = pow(x, 2);
			// creates random y variable between 0 and 1 because max value of sin is 1
			double y = static_cast<double>(rand()) / RAND_MAX;

			// if the random y value is less than or equal to f(x) then add one to pointUnderCurve
			if (y <= abs(sin(x))) {
				
				++pointUnderCurve;
				
			}
		}
		// runs code if user wanted to integrate second function
		else if (functionNumber == 2) {
			//creates random y value between 0 and 1 because max value of e^(-x^2) is 1
			double y = static_cast<double>(rand()) / RAND_MAX;

			// sets x equal to -x^2 so that the function below does not get cluttered and is readable
			x = -(pow(x, 2));

			// if random y value is less than f(x) then add one to pointUnderCurve
			if (y <= exp(x)) {
			
				++pointUnderCurve;
			}
		}
		// runs code if user wanted to integrate the third function
		else {
			// creates random y value between 0 and pi/2 because the max of arctan is pi/2
			double y = static_cast<double>(rand()) / RAND_MAX;
			y = ((22. / 7) / 2) * y;

			// if random y value is less than f(x) then add one to pointUnderCurve
			if (y <= abs(atan(x))) {

				++pointUnderCurve;
			}
		}
			
	}

	// initiates variable called areaUnderCurve and sets it equal to the percentage of points within the
	//area of the curve and multiplies it by the total box area to get an estimate of the area under the curve
	double areaUnderCurve = (static_cast<double> (pointUnderCurve) / iterations) * boxArea;

	// returns areaUnderCurve
	return areaUnderCurve;
}