#include <stdio.h>

void quicksort(int a[], int first, int last);

int main(void){

  int i;
  int a[8] =  {3,2,6,8,5,1,7,4};

  for (i = 0; i < 8; i++) {
      printf("array[%d] = %d\n", i, a[i]);
  }

  printf("Start sorting...\n");
  quicksort(a, 0, 7);

  printf("Finish!\n");
  for (i = 0; i < 8; i++) {
      printf("array[%d] = %d\n", i, a[i]);
  }

  return 0;
}

void quicksort(int a[], int first, int last){

  printf("Check point.");

  int i, j, x, t;

  x = a[(first+last)/2];
  i = first;  j = last;
  while(1){
    while (a[i]<x) i++;
    while (x<a[j]) j--;
    printf("(i,j)=(%d,%d)", i, j);
    if (i >= j) break;
    t = a[i];   a[i] = a[j];    a[j] = t;
    i++;  j--;
  }
  if (first < i-1) quicksort(a, first, i-1);
  if (j+1 < last)  quicksort(a, j+1, last);
}