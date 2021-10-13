#include <stdio.h>

int main() {
  long x;
  int flag;
  scanf("%ld", &x);
  // TODO
  char x_arr[64];
  int i;
  if (x < 0)
	  if (x < 0) {
          x = -x;
          flag = 1;
  } else {
          flag = 0;
  }


  for (i = 63; i >= 0; i--){
          x_arr[i] = x % 2;
          x = x / 2;
  }
  for (i=0;i<64;i++){
          if(flag == 1) {
                  if (i == 63){
                        printf("%d", x_arr[i]);
                  } else {
                          printf("%d", 1-x_arr[i]);
                  }
          } else {
                  printf("%d", x_arr[i]);
          }
  }
  printf("\n");
  return 0;
}
