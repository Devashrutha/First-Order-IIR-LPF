#include "ChebyshevT1.h"

int main()
{
    float G0;
    filter_param fp;
    fp.N = 4;
    fp.rs = 1;
    cmpx_no* poles = (cmpx_no*)malloc(fp.N * sizeof(cmpx_no)); // Dynamically allocate memory for poles
    cmpx_no* static_gain = (cmpx_no*)malloc(1*sizeof(cmpx_no)); //Dynamically allocate memory for poles
    chebyT1PG(fp.N, fp.rs, poles, static_gain);
    // Print the poles using the printCmpx function:
    printf("Poles:\n");
    printCmpx(poles, fp.N);

    // Print the static_gain using the printCmpx function:
    printf("Static Gain:\n");
    printCmpx(static_gain, 1);
    G0=calcCmpxMag(static_gain);
    printf("Magnitude of static Gain(G0): %.4f\n",G0);
    // Free the memory for poles and static_gain:
    free(poles);
    free(static_gain);

    return 0;

}
