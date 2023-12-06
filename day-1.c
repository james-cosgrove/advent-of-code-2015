#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"

char *increment_cmd = "(";

int go_to_level(const char input[])
{
  int level_num;
  bool has_entered_basement = false;
  int input_len = strlen(input);

  for (int i = 0; i < input_len; i++) {
    int comp_val = strncmp(&input[i], increment_cmd, 1);
    level_num = comp_val == 0 ? level_num + 1 : level_num - 1;
    if (level_num < 0 && !has_entered_basement) {
      has_entered_basement = true;
      printf("Entered basement at pos: %d \n", i + 1);
    }
  }

  return level_num;
}

int main()
{
  int final_level = go_to_level(day_1_input);
  printf("Final level: %d \n", final_level);

  return 0;
}
