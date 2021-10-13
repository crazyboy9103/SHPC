#include <stdio.h>


int main() {
  int x;
  int flag;
  scanf("%d", &x);
  int x_arr[32];
  
  int i;
  if (x < 0) {
	  x = -x;
	  flag = 1;
  } else {
	  flag = 0;
  }


  for (i = 31; i >= 0; i--){
	  x_arr[i] = x % 2;
	  x = x / 2;
  }
  for (i=0;i<32;i++){
	  if(flag == 1) {
		  if (i == 31){
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
