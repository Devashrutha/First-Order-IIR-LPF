#ifndef TYPE_1_IIR_H
#define TYPE_1_IIR_H

typedef struct{
	//alpha 0<a<1, 0 means no filtering
	float a;
	 //output
	float y;
}T1IIR;

// Initialize the filter with default values and clear previous output y
void T1IIR_Init(T1IIR *filter, float a);

// Calculate the new output y sample with raw input data point x
float T1IIR_New(T1IIR *filter, float x);

#endif
