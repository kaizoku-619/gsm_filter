#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cmd = "AT+CIPSTART=\"TCP\",\"www.google.com\",80\n";

char *resp1 = "OK +CIPRCV:32,AXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXZ+CIPRCV:25,BYYYYYYYYYYYYYYYYYYYYYYYZ+CIPRCV:58";

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

static void filter_payload(char *frame);

int main ()
{
  filter_payload(resp1);
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
      header_end_index = i+1;
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
}