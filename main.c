#include "main.h"

char *cmd = "AT+CIPSTART=\"TCP\",\"www.google.com\",80\n";

char *resp1 = "OK +CIPRCV:32,AXXXXXXXXXXXXXXX,,XXXCIPRCV,XXXZ+CIPRCV:25,BYYYYYYYYYCIPRCVYYYYYYYYZ+CIPRCV:58,hello";

char *header;
char *payload;
char *footer;

int frame_chunk_start_index = 0;

int header_start_index;
int header_end_index;

int payload_start_index;
int payload_end_index;

int payload_size_start_index;
int payload_size_end_index;

int footer_start_index;
int footer_end_index;

char *payload_size;
int payload_size_num;

int header_start_indexes[3];
int payload_start_indexes[3];

char clean_buff[128];

static void filter_payload(char *frame);
static void test_func(char *frame);
static void find_headers(char *frame);
static void find_payloads(char *frame);

int main ()
{
  printf("data = %s\n", resp1);
  find_headers(resp1);
  find_payloads(resp1);
  int next = 0;
  for (int i = 0; i < 3; i++)
  {
    memcpy(clean_buff+next, 
           resp1+payload_start_indexes[i], 
           header_start_indexes[i+1] - payload_start_indexes[i]
    );
    next = header_start_indexes[i+1] - payload_start_indexes[i];
    printf("clean_buff = %s\n", clean_buff);
  }

  return(0);
}

void filter_payload(char *frame)
{
  printf("frame = %s\n", frame);
  printf("sizeof frame = %d\n", strlen(frame));
  // extract header
  for (int i = 0; i < strlen(frame); i++)
  {
    if (frame[i] == ',')
    {
      header_end_index = i + 1;
      printf("header_end_index = %d\n", header_end_index);
      // if(memcmp((frame + i) - 12, "+CIPRCV:", 8))
      // {
      //   printf("%s\n", (frame + i) - 12);
      //   printf("MATCH\n");
      // }
      // else
      // {
      //   printf("%s\n", (frame + i) - 12);
      //   printf("NO MATCH\n");
      // }
      break;
    }
  }
  printf("header_end_index = %d\n", header_end_index);
  header = (char *) malloc(header_end_index);
  memcpy(header, frame, header_end_index);
  printf("header = %s\n", header);
  printf("===================================================================================\n");
  // extract payload size from header
  payload_size_end_index = header_end_index - 1;
  for (int k = header_end_index; k > 4; k--)
  {
    if (header[k] == ':')
    {
      payload_size_start_index = k+1;
      break;
    }
  }
  payload_size = (char *) malloc(payload_size_end_index - payload_size_start_index);
  memcpy(payload_size, header + payload_size_start_index, (payload_size_end_index - payload_size_start_index));
  payload_size_num = atoi(payload_size);
  printf("payload_size_start_index = %d\n", payload_size_start_index);
  printf("payload_size_end_index = %d\n", payload_size_end_index);
  printf("payload_size_num = %d\n", payload_size_num);
  printf("===================================================================================\n");
  // extract payload from frame
  payload = (char *) malloc(payload_size_num);
  memcpy(payload, frame + header_end_index, payload_size_num);
  printf("payload = %s\n", payload);
  printf("===================================================================================\n");
  printf("===================================================================================\n");
}

void test_func(char *frame)
{
  // find payload index
  char *ret;
  char tmp[12];
  int i;
  for (i = 0; i < strlen(frame); i++)
  {
    if (frame[i] == ',')
    {
      ret = strstr(frame, "+CIPRCV:");
      printf("header = %s\n", ret);
      memcpy(tmp, ret, 12);
      printf("tmp = %s\n", tmp);
      if (strstr(tmp, "+CIPRCV:"))
      {
        payload_start_index = i+1;
        printf("payload_start_index = %d\n", payload_start_index);
        break;
      }
    }
  }
}

void find_headers(char *frame)
{
  int i = 0;
  int pos = 0;
  int count = 0;
  while(frame = strstr(frame, "+CIPRCV:"))
  {
    // printf("pointer = %s\n", frame);
    // use pointer subtraction to pass from pointer to index
    pos = frame - resp1;
    // printf("header position = %d\n", pos);
    header_start_indexes[i] = pos;
    i++;
    count++;
    frame++;
  }
  printf("found %d header/payload @ indexes: ", count);
  for (int j = 0; j < count; j++)
  {
    printf("%d ", header_start_indexes[j]);
  }
  printf("\n");
}

void find_payloads(char *frame)
{
  int x = 0;
  int i = 0;
  foreach(int *header_pos, header_start_indexes)
  {
    for (x = *header_pos; x < *header_pos+14; x++)
    {
      if (resp1[x] == ',')
      {
        printf("found payload start @ position %d\n", x+1);
        payload_start_indexes[i] = x+1;
        i++;
        break;
      }
    }
  }
}

void load_payloads(char *frame, char *clean_payload)
{

}
