#include <stdio.h>
#include "cpTime.h"
int main()
{
  // FILE *input,
  FILE* output;
  //char text[10000];

  //input = fopen("/dev/ttyACM0", "r");      //open the terminal keyboard

  output = fopen("/dev/ttyACM1", "w");     //open the terminal screen
  if ( output == NULL )
  {
    printf("ACM1 is NULL, trying ACM0.\n");
    output = fopen("/dev/ttyACM0", "w");
    if (output == NULL)
    {
      printf("ACM0 is also NULL. Exiting.\n");
      return 1;
    }
  }



  fprintf(output,"%c",0xFE);
  fprintf(output,"%c",0x88);

  int n = 0;
  for(int i = 0; i < 20; i++)
  {
    n = i*i;
    fprintf(output,"%c",n);
    fprintf(output,"%c",0);
  }
  
  fflush(output); 

 

  

  // for(int i = 0; i <= 8; i++)
  // {
  //   fprintf(output,"%c",251);
  //   fprintf(output,"%c",i+1);
  //   fprintf(output,"%c",50+i);
  //   fflush(output); 
  // }
    
  fclose(output);

  return 0;
}