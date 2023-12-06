#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"

char *increment_cmd = "(";

struct Result {
  int level_num;
  int basement_cmd_pos;
} result = { 0, 0 };

struct Result get_result(const char input[])
{
  int input_len = strlen(input);
  bool has_entered_basement = false;

  for (int i; i < input_len; i++) {
    int comp_val = strncmp(&input[i], increment_cmd, 1);
    result.level_num = comp_val == 0 ? result.level_num + 1 : result.level_num - 1;

    if (!has_entered_basement && result.level_num < 0) {
      result.basement_cmd_pos = i + 1;
      has_entered_basement = true;
    }
  }

  return result;
}

int main()
{
  struct Result solution = get_result(DAY_1_INPUT);
  printf("Entered basement at instruction number: %d \n", solution.basement_cmd_pos);
  printf("Final level: %d \n", solution.level_num);

  return 0;
}
