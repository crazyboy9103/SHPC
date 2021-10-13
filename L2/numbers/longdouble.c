#include <stdio.h>
#include <math.h>
#include <float.h>
int main() {
  long double x;
  scanf("%Lf", &x);

  char sign = (int) x < 0;
  char exp[15]={0};
  char intPart;
  char fr[63]={0};


  if(sign == 1){
          x=-x;
  }
  int int_part = (int) log(x)/log(2);
  int tmp_int_part = pow(2, 15-1)-1  + int_part;

  long double decimal = x / (long double) pow(2, int_part);
  int i;
  for(i=14;i>=0;i--){
        exp[i] = tmp_int_part % 2;
        tmp_int_part = tmp_int_part / 2;
  }

  decimal--;
  for(i=0;i<63;i++) {
        decimal *= 2;
        if (decimal > 1) {
                fr[i] = 1;
                decimal -= 1;
        } else {
                fr[i] = 0;
        }
  }

  printf("%d", sign);
  for(i=0;i<15;i++){
          printf("%d", exp[i]);
  }
  for(i=0;i<63;i++){
          printf("%d", fr[i]);
  }
  printf("\n");


  return 0;
}
