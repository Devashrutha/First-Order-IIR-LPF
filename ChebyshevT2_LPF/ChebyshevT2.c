#include "ChebyshevT2.h"

//Function to print coefficients

void print_coeff( complexno cNum[], complexno cDen[], int N, int M, int ord, float Kd){
    int i;

    for(i = 0; i< N; i++){
        printf("Numerator Coefficients:\n");
        printf("%f + i%f\n", cNum[i].R, cNum[i].I);
    }
    
    for(i = 0; i< M; i++){
        printf("Denominator Coefficients:\n");
        printf("%f + i%f\n", cDen[i].R, cDen[i].I);
    }
    printf("Static Gain: %f", Kd);
}

// Function that computes the real and imaginary part of a complex number represented by a*exp(pi*theta)

float complexexp (float c, float a){
    complexno nb;
    nb.R = a*cos((float) PI * c);
    nb.I = a*sin((float) PI * c);
}


void chebyPZ()
{
    int i;
    float deltaS, epsilon, mu, k , kP = 1, kZ = 1;

    filter_param fP = {4, 0, 0, 0, 0.001, 300, 0.5};

    deltaS = 1 / sqrt(pow(10, (.1 * fP.rs) - 1));
    mu = asinh(1 / deltaS) / fP.N;

    fP.T = 1.0 / fP.Fs;
    // normalize digital frequency over 0 to 2pi
    fP.Wd = fP.fc * PI / (fP.Fs / 2.0);
    // convert digital frequency to analog frequency
    fP.Wc = 2.0 / fP.T * tan(fP.Wd / 2.0);
    // analog poles and zeros calculation
    complexno p[fP.N], z[fP.N];

    // analog zeros
    if (fP.N % 2 == 0)
    {

        for (i = 1; i <= fP.N; i++)
        {
            z[i - 1].R = 0.0;
            z[i - 1].I = 1.0 / cos(((2.0 * i + 1.0) * PI) / (2.0 * fP.N));
        }
    }
    else
    {

        for (i = 1; i < fP.N; i++)
        {
            z[i - 1].R = 0.0;
            z[i - 1].I = 1.0 / cos(((2.0 * i + 1.0) * PI) / (2.0 * fP.N));
        }
    }

    // analog poles
    for (i = 1; i <= fP.N; i++)
    {
        p[i - 1].R = 1 / (-sin(((2 * i + 1) / 2 * fP.N) * sinh(mu)));
        p[i - 1].I = 1 / (cos(((2 * i + 1) / 2 * fP.N) * cosh(mu)));
    }

    for (i =1; i<= fP.N; i++){
        kP = kP * p[i-1].R;
        kZ = kZ * p[i-1].R;
    }
    k = kP/kZ;

    
}