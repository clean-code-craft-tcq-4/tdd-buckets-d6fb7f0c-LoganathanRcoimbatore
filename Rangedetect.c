#include <stdio.h>
#include "Rangedetect.h"

int DetectRange(int * readings,int size,rangeInfo *Data_struct)
{
    int totalRange=0;
    Data_struct[totalRange].RangeStart=readings[0];
    Data_struct[totalRange].ReadingsInRange=1;
    for(int Readcount=0;Readcount<size-1;Readcount++)
    {
       if((readings[Readcount]+1==readings[Readcount+1])||(readings[Readcount]==readings[Readcount+1]))
       {

       Data_struct[totalRange].RangeEnd=readings[Readcount+1];
       Data_struct[totalRange].ReadingsInRange++;
       }
       else
       {
       totalRange++;
       Data_struct[totalRange].RangeStart=readings[Readcount+1];
       Data_struct[totalRange].ReadingsInRange++;
       }
    }
	  return(totalRange+1);
}

void PrintRangeInfo(rangeInfo *Data_struct,int totalRange)
{
    printf("\nRange         Count\n");
    for(int Rangecount=0;Rangecount<totalRange;Rangecount++)
    {
         if(Data_struct[Rangecount].ReadingsInRange != 1)
         {
           printf("%d - %d , %d\n",Data_struct[Rangecount].RangeStart, Data_struct[Rangecount].RangeEnd,Data_struct[Rangecount].ReadingsInRange);
         }
         else
         {
            printf("%d , %d\n",Data_struct[Rangecount].RangeStart,Data_struct[Rangecount].ReadingsInRange); 
         }
    }

}
int DetectAndDisplayRange(int * readings,int totalData)
{
    int CheckedRanges;
    static rangeInfo DataForDisplay[DISPLAY_SIZE];
    CheckedRanges=DetectRange(readings,totalData,DataForDisplay);
    PrintRangeInfo(DataForDisplay,CheckedRanges);
    return(CheckedRanges);
}
