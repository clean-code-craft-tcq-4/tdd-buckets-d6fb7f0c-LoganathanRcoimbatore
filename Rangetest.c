#include <stdio.h>
#include <assert.h>
#include "Rangedetect.h"

void TEST_CASE_01()
{
    int Data[]={4,1,1};
    int Totalreadings=sizeof(Data)/sizeof(Data[0]);
    assert(DetectAndDisplayRange(Data,Totalreadings) == 1);
}
void TEST_CASE_02()
{
    int Data[]={4,5,5,6,8,10};
    int Totalreadings=sizeof(Data)/sizeof(Data[0]);
    assert(DetectAndDisplayRange(Data,Totalreadings) == 3);
}
int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
}
