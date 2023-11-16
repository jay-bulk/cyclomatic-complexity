#include <stdio.h>
#include <string.h>

void CheckBoeingString(char *aircraft, int stg, char *error_switch);
void CheckEndString(char *aircraft, int stg);

int main() {
  int stg = 0;
  char* aircraft;
  char error_switch[3] = "no";

  CheckBoeingString(aircraft, stg, error_switch);

  return 0;
}

void CheckBoeingString() {
  char error_switch[3];
  if (aircraft[stg] == 'B') {
    ++stg;
  } else {
    error_switch = "yes";
    CheckEndString(aircraft, stg);
  }

  if (&aircraft[stg] == '-') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(aircraft, stg);
  }

  if (&aircraft[stg] == '7') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(aircraft, stg);
  }

  if (aircraft[stg] == '3' || aircraft[stg] == '4' || aircraft[stg] == '5' ||
      aircraft[stg] == '6' || aircraft[stg] == '7' || aircraft[stg] == '8') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(aircraft, stg);
  }

  if (aircraft[stg] == '7') {
    stg++;
  } else {
    error_switch = "yes";
    CheckEndString(aircraft, stg);
  }
}

void CheckEndString() {
  char *error_switch = "no";
  if (aircraft[stg] == ',') {
    stg++;
    CheckBoeingString(&aircraft, stg, error_switch);
  } else if (aircraft[stg] != ' ') {
    /*  
    * This doesn't make sense... the PDL said 'not = " " comment "the character is blank" '. 
    * Is the code meant to check if it is blank?
    */
    printf("The character %c is blank", aircraft[stg]);
    stg++;
    CheckBoeingString(aircraft, stg, error_switch);
  } else {
    // Stop
    printf("Squawk Received: I am a %s", aircraft);
    return; // Add the return statement to exit the function
  }
}
