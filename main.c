#include <stdio.h>

void CheckBoeingString(char *input, int stg, char *error_switch);
void CheckEndString(char *input, int stg);

int main() {
  int stg = 0;
  char *input = "Default String";
  scanf(input);
  char *error_switch = "no";

  CheckBoeingString(input, stg, error_switch);

  return 0;
}

void CheckBoeingString(char *input, int stg, char *error_switch) {
  if (input[stg] == 'B') {
    ++stg;
  } else {
    error_switch = "yes";
    CheckEndString(input, stg);
  }

  if (input[stg] == '-') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(input, stg);
  }

  if (input[stg] == '7') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(input, stg);
  }

  if (input[stg] == '3' || input[stg] == '4' || input[stg] == '5' ||
      input[stg] == '6' || input[stg] == '7' || input[stg] == '8') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(input, stg);
  }

  if (input[stg] == '7') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(input, stg);
  }
}

void CheckEndString(char *input, int stg) {
  char *error_switch = "no";
  if (input[stg] == ',') {
    stg++;
    CheckBoeingString(input, stg, error_switch);
  } else if (input[stg] != ' ') {
    // The character is not blank
    stg++;
    CheckBoeingString(input, stg, error_switch);
  } else {
    // Stop
    return; // Add the return statement to exit the function
  }
}
