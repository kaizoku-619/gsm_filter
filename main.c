#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cmd = "AT+CIPSTART=\"TCP\",\"www.google.com\",80\n";

char *resp1 = "OK +CIPRCV:32,AXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXZ+CIPRCV:58,";
char *resp2 = "OK +CIPRCV:1344,HTTP/1.0 200 OK Date: Tue, 14 May 2019 10:44:00 GMT Expires: -1 Cache-Control: private, max-age=0 Content-Type: text/html; charset=ISO-8859-1 P3P: CP=\"This is not a P3P policy! See g.co/p3phelp for more info.\"Server: gws X-XSS-Protection: 0 X-Frame-Options: SAMEORIGIN Set-Cookie: 1P_JAR=2019-05-14-10; expires=Thu, 13-Jun-2019 10:44:00 GMT; path=/; domain=.google.com Set-Cookie: NID=183=zyW_uc8pLBceuHXvQSlzFeWCrDumLQA16sDYxEYdbhjnxApbDoSiFxJGhvnKi8N-ns4l-Ns3EWgreyjlZD_O9E7bw15C50gm-Dsuwy6-U33dpfiJcBywjAGILFEFOqREv4GVnlaA9gaVtUo_8d26EtvJAJQNeKwEqv_9LUah4Yw; expires=Wed, 13-Nov-2019 10:44:00 GMT; path=/; domain=.google.com; HttpOnly Accept-Ranges: none Vary: Accept-Encoding <!doctype html><html dir=\"rtl\" itemscope=\"\" itemtype=\"http://schema.org/WebPage\" lang=\"ar-TN\"><head><meta content=\"text/html; charset=UTF-8\" http-equiv=\"Content-Type\"><meta content=\"/images/branding/googleg/1x/googleg_standard_color_128dp.png\" itemprop=\"image\"><title>Google</title><script nonce=\"+u+iuUhcwdxS7iayvL9QUQ==\">(function(){window.google={kEI:'8JvaXK3oKIyxU6u0tIgO',kEXPI:'0,1353747,57,1958,1640,782,698,527,730,224,1224,351,1258,1894,57,321,206,1017,285,421,224,113,2332527,329554,1294,12383,4855,32692,15247,861,12169,5281,7638,1406,2196,363,3320,5505,2439,263,5107,575,835,284,2,578,728,2069,363,1361,4323,4967,774,2256,5889,2,1968,2592,3601,669,1045 +CIPRCV:58,";
char *resp3 = "+CIPRCV:58,,2,1811,1397,81,7,491,620,29,9999,305,1288,2,4007,796,101,";

char *header;
char *payload;
char *footer;

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
  filter_payload(resp3);
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