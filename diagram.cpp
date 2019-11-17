#include <complex>
#include <iostream>
#include <vector>

#include <cmath>

#include <SignalGenerator.hpp>

using namespace std;

int main() {
    double pks[] =  {94.55, 40.02,  35.02,  25.35, 15.16, 12.42, 10.18, 4.97,  0.48};
    double amps[] = {250,   15.02,  10.88,  5.569, 0.189, 0.506, 0.443, 0.189, 0.443};
    double fwhm[] = {10,    2,      1.0,    1,     0.1,   0.1,   0.1,   0.1,   0.1};

    //the vector to hold the results.
    vector<double> sum(1000);
    
    for(unsigned int i = 0; i < 9; i++) {
        SignalGenerator sig;
        sig.SetSigma(fwhm[i]);
        sig.SetAmplitude(amps[i]);
        sig.SetDelay(pks[i]);
        sig.SetSignalType("gaussian");
        
        int counter = 0;
        for(double i = 0; i < 100; i+=0.1, counter++) {
            sum[counter] += sig.GetSignalValue(i);
        }
    }
    for(unsigned int i = 0; i < sum.size(); i++) 
        cout << i*0.1 << " " << sum[i] << " " 
             << 0.1*exp(-(i-1000)*0.01)+0.1 <<  endl;
}
