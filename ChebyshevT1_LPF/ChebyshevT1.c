#include "ChebyshevT1.h"
#include <math.h>

void printCmpx(cmpx_no cmpx[], int N)
{

    int i;
    for (i = 0; i < N; i++)
    {
        printf("(%.4f,%.4f)\n", cmpx[i].Re, cmpx[i].Im);
    }
}

float calcCmpxMag(cmpx_no cmpx[])
{
    float mag;
    mag = sqrt((cmpx[0].Re*cmpx[0].Re)+(cmpx[0].Im*cmpx[0].Im));

    return mag;
}

cmpx_no* multiCmpx(float a, float b, float c, float d)
{

    cmpx_no* multNo = (cmpx_no*)malloc(1*sizeof(cmpx_no));
    multNo->Re = (a*c)-(b*d);
    multNo->Im = (a*d)+(b*c);

    return multNo;

}

cmpx_no* chebyT1PG(int N, float rs, cmpx_no* poles, cmpx_no* static_gain)
{
    int i;
    float epsilon, angle, sinh_val,cosh_val;


    epsilon = sqrt(pow(10,0.1 * rs) - 1);



    // Analog poles P:
    for (i = 0; i < N ; i++)
    {

        angle = ((2 * i + N + 1.0) / (2 * N)) * PI;
        sinh_val = sinhf(asinhf(1.0 / epsilon) / N);
        cosh_val = coshf(asinhf(1.0 / epsilon) / N);

        poles[i].Re = sinh_val * cosf(angle);
        poles[i].Im = cosh_val * sinf(angle);

        //Static Gain:

        if(i == 0)
        {
            // Initialize static_gain with the first pole
            static_gain->Re = poles[i].Re;
            static_gain->Im = poles[i].Im;
        }

        else
        {
            // Multiply static_gain with the current pole
            cmpx_no* temp = multiCmpx(static_gain->Re, static_gain->Im, -1*poles[i].Re, -1*poles[i].Im);
            static_gain->Re = temp->Re;
            static_gain->Im = temp->Im;
        }
    }
    //Static gain G0 for even N:
    if(N%2 == 0)
    {
        static_gain->Re/= sqrt((1.0 + epsilon*epsilon));
    }

    return 0;

}

