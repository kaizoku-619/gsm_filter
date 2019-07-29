/*

"OK +CIPRCV:15,A1AAAAAAAAAAAAX+CIPRCV:13,B1BBBBBBBBBBY+CIPRCV:16,C1CCCCCCCCCCCCCZ+CIPRCV:58,"

1- fonction tala3 start_index mta3 kol payload fil trame w t7othom fi tableau
  - bch tala3 start_index mta3 el payload lezem tverifi 2 conditions
      I- lezem tal9a virgule
      II- AND lezem el chaine eli l'index mte3ha 9bal el virgule b 12 feha "CIPRCV:"
2- nboukli 3al tableau w nextracti kol payload mel trame
3- kol payload nextracteha nsobha fi tableau global
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *data_sample = "OK +CIPRCV:15,A1AAAAAAAAAAAAX+CIPRCV:13,B1BBBBBBBBBBY+CIPRCV:16,C1CCCCCCCCCCCCCZ+CIPRCV:58,";

static void fetch_indexes(char *frame, int indexes[]);

int main()
{
  memcmp()
  return 0;
}

void fetch_indexes(char *frame, int indexes[])
{
  char *check_ciprcv;
  int j = 0;
  for (int i = 0; i < strlen(frame); i++) 
  {
    if (frame[i] == ',')
    {
      // memcpy(check_ciprcv, (frame + i) - 12, 12);
      if(memcmp((frame + i) - 12, "+CIPRCV:", 8))
      {
        printf("%s\n", (frame + i) - 12);
        printf("MATCH\n");
        indexes[j] = 
      }
    }
  }
  
}