#include <stdio.h>
#include <string.h>

char *incrementor = "(";

int go_to_level(char input[])
{
  int level = 0;
  int input_len = strlen(input);

  for (int i = 0; i < input_len; i++) {
    int comp_val = strncmp(&input[i], &incrementor[0], 1);
    level = comp_val == 0 ? level + 1 : level - 1;
  }
  return level;
}

int main(int argc, char **argv)
{
  int current_level = go_to_level(argv[1]);
  printf("Current level: %d \n", current_level);

  return current_level;
}
