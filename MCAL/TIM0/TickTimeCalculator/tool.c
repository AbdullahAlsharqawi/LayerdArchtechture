#include <stdio.h>
#include <conio.h>

#define SYSTEM_FREQUENCY     8000000
#define SYSTEM_RESOLUTION    256

int main (void)
{
int i=0;
int prescalar[]={1,8,64,256,1024};
float DesiredTime=0;
unsigned long SysFreq=SYSTEM_FREQUENCY ;
double TickTime=0,TimeOverFlow=0,OverFlowNum=0,InitialNumber,decpart;
int intpart;
int flag=1;
while(flag==1)
{
printf("Please enter the RequiredTime\n");
scanf("%f",&DesiredTime);
printf("-------------------------------------------------------------------------------------\n");
printf("PreScale  |TickTime          |TimeOverFlow   |Number Of Overflows     |InitialNumber|\n");
printf("----------|------------------|---------------|------------------------|-------------|\n");
  for(i=0;i<5;i++)
   {
     TickTime= ((float)prescalar[i] / SysFreq);
     TimeOverFlow= TickTime*(float)SYSTEM_RESOLUTION ;
     OverFlowNum=DesiredTime/TimeOverFlow;
     intpart=(int)OverFlowNum;
     decpart=OverFlowNum-intpart;
     
     InitialNumber=(float)SYSTEM_RESOLUTION  - (decpart*(float)SYSTEM_RESOLUTION );
     
     printf("%5d     |%10.7f        |%f       |%18.5f      |%10.5f   |\n",prescalar[i],TickTime,TimeOverFlow,OverFlowNum,InitialNumber);
     
   }
printf("------------------------------------------------------------------------------------|\n");
printf("-------------------------------------------------------------------------------------\n\n\n\n");
printf("press 1 to continue or any key to exit\n");
scanf("%d",&flag); 
}
return 0;
}	