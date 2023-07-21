#ifndef CHEBYSHEVT1_H
#define CHEBYSHEVT1_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979
#define MAX_N 10 // Define a maximum value for N

// Structure of filter parameters

typedef struct cmpx_no
{
    float Re;
    float Im;
} cmpx_no;

typedef struct filter_param
{

    float fs;    // Sampling frequency
    float fp;    // Passband frequency
    float fsb;   // Stopband frequency
    int N;       // Order
    float rs;    // Stopband ripple or Stopband Attenuation
    float Apass; // Passband ripple or Passband Attenuation

} filter_param;

float calcCmpxMag(cmpx_no cmpx[]);
cmpx_no* multiCmpx(float a, float b, float c, float d);
cmpx_no* chebyT1PG(int N, float rs, cmpx_no* poles, cmpx_no* static_gain);
void printCmpx(cmpx_no cmpx[], int N);

#endif

