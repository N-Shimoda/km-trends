#include <stdio.h>

void quicksort(int a[], int first, int last);

int main(void){

  int i;
  int len = 8;
  int a[8] = {3,2,6,8,5,1,7,4};
  // int a[8] = {1,4,6,8,2,5,3,7};    // answer for question 3

  for (i = 0; i < len; i++) {
      printf("array[%d] = %d\n", i, a[i]);
  }

  printf("Start sorting...\n");
  quicksort(a, 0, len);

  printf("Finish!\n");
  for (i = 0; i < len; i++) {
      printf("array[%d] = %d\n", i, a[i]);
  }

  return 0;
}

void quicksort(int a[], int first, int last){

  int i, j, x, t;
  // printf("saiki\n");   for counting how many times this function was called

  x = a[(first+last)/2];
  i = first;  j = last;
  while(1){
    while (a[i]<x) i++;
    while (x<a[j]) j--;
    if (i >= j) break;
    t = a[i];   a[i] = a[j];    a[j] = t;
    i++;  j--;
  }
  if (first < i-1) quicksort(a, first, i-1);
  if (j+1 < last)  quicksort(a, j+1, last);
}