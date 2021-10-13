#include <stdio.h>
#include <math.h>
#include <float.h>
int main() {
  double x;
  scanf("%lf", &x);
  
  char sign = (int) x < 0;
  char exp[11]={0};
  char fr[52]={0};
  
  
  if(sign == 1){
	  x=-x;
  } 
  int int_part = (int) log(x)/log(2);
  int tmp_int_part = 1023 + int_part;

  double decimal = x / (double) pow(2, int_part);
  int i;
  for(i=10;i>=0;i--){
  	exp[i] = tmp_int_part % 2;
	tmp_int_part = tmp_int_part / 2;
  }

  decimal--;
  for(i=0;i<52;i++) {
	
	decimal *= 2;
  	if (decimal > 1) {
		fr[i] = 1;
		decimal -= 1;
	} else {
		fr[i] = 0;
	}
  }

  printf("%d", sign);
  for(i=0;i<11;i++){
	  printf("%d", exp[i]);
  }
  for(i=0;i<52;i++){
	  printf("%d", fr[i]);
  }
  printf("\n");
  

  return 0;
}
