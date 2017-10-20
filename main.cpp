
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <armadillo>
#include "time.h"
#include "examples.h"

using namespace std;
using namespace arma;



// object for output files
ofstream ofile;

int main(int argc, char *argv[])
{
    int n;

    // Reading in outputfile. Abort if there are too few command line arguments
    if (argc<2){
        cout << "Bad usage: " << argv[0] << "read also 'n' on the same line"<<endl;
        exit(1);
    }
    else{
        n = atoi(argv[1]);
    }

    // Declaring constants
    double pi = M_PI;
    double GM = 4*pi*pi;
    double T = 100.0; // Number of years
    double delta_t = T/((double) n);
    
    // Here we start the time-taking
    clock_t start, finish;
    start = clock();

    //Examples::twoBodyProblem(GM, delta_t, n);
    //Examples::threeBodyProblem(GM, delta_t, n);
    //Examples::tenBodyProblem(GM, delta_t, n);
    Examples::perihelion(GM, delta_t, n, T);

    // Here we end the time-taking
    finish = clock();
    double timeused = (double) (finish - start)/(CLOCKS_PER_SEC ); // Calculating time
    cout << "Time in seconds: " << timeused << endl; // Printing out time spent

    cout << "delta_t =" << delta_t << endl;

    // Success
    return 0;
}
