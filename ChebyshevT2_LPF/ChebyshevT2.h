#ifndef CHEBYSHEVT2_H
#define CHEBYSHEVT2_H
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>


 #define EPSILON 1.0e-06
 #define PI      3.14159265358979

// Complex number structure in terms of R+iI
 typedef struct complexno {
    float R;
    float I;
 }complexno;

// Structure of filter parameters


 typedef struct filter_param{
    int N;
    float Wd;
    float Wc;
    float Fs;
    float T;
    float fc;
    float rs;

 }filter_param;





void print_coeff( complexno cNum[], complexno cDen[], int N, int M, int ord, float Kd);
float complexexp (float c, float a);
void chebyPZ();



#endif