#include <iostream>
#include <string.h>

void searchPatter_novice(char *str, char *p);

void searchPatter_novice(char *str, char *p) {

  /**
   * length of the string and pattern
   */

  size_t Limit, i, j;

    Limit = strlen(str) - strlen(p);

    for (i = 0; i <= Limit; i++) {
      for (j = 0; j < strlen(p); j++) {
        if(p[j] != str[i+j]) {
          break;
        }
      }
      if(j == strlen(p)) {
        printf("Pattern found at position %d\n", i);
      }
    }
  }

  int main(void) {

        char str[] = "AABAAAB";

        //pattern to search
        char p[] = "AA";

        //search for pattern
        searchPatter_novice(str, p);

        return 0;

  }
