/*

"OK +CIPRCV:15,A1AAAAAAAAAAAAX+CIPRCV:13,B1BBBBBBBBBBY+CIPRCV:16,C1CCCCCCCCCCCCCZ+CIPRCV:58,"

// 1- fonction tala3 start_index mta3 kol trame w t7othom fi tableau
// 2- nboukli 3al tableau w nextracti el payload men kol trame
// 3- kol payload nextracteha nsobha fi tableau global

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *data_sample = "OK +CIPRCV:15,A1AAAAAAAAAAAAX+CIPRCV:13,B1BBBBBBBBBBY+CIPRCV:16,C1CCCCCCCCCCCCCZ+CIPRCV:58,";

static void fetch_indexes(char *frame, int indexes[]);

int main()
{
  
  return 0;
}

void fetch_indexes(char *frame, int indexes[])
{
  for (int i = 0; i < strlen(frame); i++) 
  {
    
  }
  
}