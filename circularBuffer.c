/* Implement a circular buffer with write and read APIs */

#include <stdio.h>
#include <stdlib.h> /* For malloc etc. */
#include <string.h> /* For memset */

#define BUFFER_SIZE 10 /* Bytes */

int writeToBuffer(char *ptrToBuffer)
{
  char char_array[] = {'p', 'i', 'n', 'k', 'f', 'l', 'o', 'y', 'd', '\'', 's', 'b', 'e', 's', 't', '\0'};
  unsigned int i = 0;
  unsigned int len = 0;
  unsigned int position = 0;
  if (ptrToBuffer == NULL)
  {
    printf("\nBuffer points to NULL!\n");
    return -1;
  }
  while (char_array[i] != '\0')
  {
    len++;
    i++;
  }
  for(i = 0; i < len; i++)
  {
    if((position + sizeof(char_array[i])) <= BUFFER_SIZE)
    {
      memcpy((ptrToBuffer + position), &char_array[i], sizeof(char));
      position += sizeof(char_array[i]);
    }
    else
    {
      position = 0;
      memcpy((ptrToBuffer + position), &char_array[i], sizeof(char));
      position += sizeof(char_array[i]);
    }
  }
  return 0;
}

int readFromBuffer(char *ptrToBuffer)
{
  unsigned int i = 0;
  if (ptrToBuffer == NULL)
  {
    printf("\nBuffer points to NULL!\n");
    return -1;
  }
  printf("\nBuffer Contains\n");
  while(i < BUFFER_SIZE)
  {
    printf("%c", *(ptrToBuffer + i));
    i = i + sizeof(char);
  }
  printf("\n");
  return 0;
}

int main()
{
  char *ptrToBuffer;
  int return_val = 0;
  ptrToBuffer = malloc(BUFFER_SIZE);
  memset(ptrToBuffer, 0x0, BUFFER_SIZE);
  return_val = writeToBuffer(ptrToBuffer);
  if (return_val != 0)
  {
    printf("\nFailed to write to buffer; Return code %d\n", return_val);
    return return_val;
  }
  return_val = readFromBuffer(ptrToBuffer);
  if (return_val != 0)
  {
    printf("\nFailed to read from buffer; Return code %d\n", return_val);
  }
  return return_val;
}
