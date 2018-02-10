#include <iostream>
#include <math.h>

float logmodulus(float frequency, float amplitude, float zeros[], float poles[], int nzero, int npole)
{
    float result=1;
    for(int i=0;i<nzero;i++){
        result*=(((frequency/zeros[i])*(frequency/zeros[i]))+1);
    }
    for(int i=0;i<npole;i++){
        result/=(((frequency/poles[i])*(frequency/poles[i]))+1);
    }
    return 20*log10(fabs(amplitude)*sqrt(result));
}

float phaseshift(float frequency, float amplitude, float zeros[], float poles[], int nzero, int npole)
{
    float result=0;
    for(int i=0;i<nzero;i++){
        result-=(atan(frequency/zeros[i]));
    }
    for(int i=0;i<npole;i++){
        result+=(atan(frequency/poles[i]));
    }
    return result*180/M_PI;
}

int main()
{
    float zeros[1] = {100};
    float poles[1] = {1};
    std::cout<<phaseshift(1,1,zeros,poles,1,0)<<std::endl;
    std::cout<<phaseshift(10,1,zeros,poles,1,0)<<std::endl;
    std::cout<<phaseshift(100,1,zeros,poles,1,0)<<std::endl;
    return 0;
}
