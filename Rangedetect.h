
#define DISPLAY_SIZE  20

typedef struct
{
int RangeStart;
int RangeEnd;
int ReadingsInRange;
}rangeInfo;

int DetectRange(int * reading,int size,rangeInfo *Data_struct);
void PrintRangeInfo(rangeInfo *Data_struct,int totalRange);
int DetectAndDisplayRange(int * readings,int totalData);
