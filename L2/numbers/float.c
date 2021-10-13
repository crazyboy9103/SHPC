#include <stdio.h>
#include <float.h>
#include <math.h>
int main() {
  float x;
  scanf("%f", &x);
  
  char sign = (int) x < 0;
  char exp[8]={0};
  char fr[23]={0};


  if(sign == 1){
          x=-x;
  }
  int int_part = (int) log(x)/log(2);
  int tmp_int_part = 127 + int_part;

  float decimal = x / (float) pow(2, int_part);
  int i;
  for(i=7;i>=0;i--){
        exp[i] = tmp_int_part % 2;
        tmp_int_part = tmp_int_part / 2;
  }

  decimal--;
  for(i=0;i<23;i++) {

        decimal *= 2;
        if (decimal > 1) {
                fr[i] = 1;
                decimal -= 1;
        } else {
                fr[i] = 0;
        }
  }

  printf("%d", sign);
  for(i=0;i<8;i++){
          printf("%d", exp[i]);
  }
  for(i=0;i<23;i++){
          printf("%d", fr[i]);
  }
  printf("\n");


  return 0;
}

