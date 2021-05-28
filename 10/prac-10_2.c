#include <stdio.h>

char *strcat(char *dest, const char *src)
{
  while (*dest) dest++;

  while (*src) dest++[0] = *src++;

  return dest;
}

int main(void)
{
  char dest[80] = "HELLO";
  char src[80] = "WORLD";
  strcat(dest, src);
  printf("%s\n", dest);
  return 0;
}
