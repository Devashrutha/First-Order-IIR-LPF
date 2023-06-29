# include "Type1IIR.h"

// Initialize the filter with default values and clear previous output y
void T1IIR_Init(T1IIR *filter, float a){

	if( a < 0.0f ){
		filter->a = 0.0f;
	}
	else if( a > 1.0f ){
		filter->a = 1.0f;
	}
	else{
		filter->a = a;
	}

	filter-> y = 0.0f;

}

// Calculate the new output y sample with raw input data point x
float T1IIR_New(T1IIR *filter, float x){

	// FIRST ORDER IIR DIFFERENCE EQUATION: (1-a)*Current_Value+a*Previous_Value
	filter-> y = (1.0f-filter->a) * x + filter->a * filter->y;

	return filter->y;

}
