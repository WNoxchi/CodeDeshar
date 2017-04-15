// Insertion Sort     WNx - 2017-02-05 15:19
#include <stdio.h>

int main(void) {
  int A[10] = {0,9,2,8,4,5,7,5,1,3};

  printf("Array: [ ");
  for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
    printf("%i, ", A[i]);
  }
  printf("]\n");

  for (int j = 1; j < sizeof(A)/sizeof(int); j++) {
    int key = A[j];
    // Insert A[j] into the sorted sequence A[1..j-1]
    int i = j - 1;
    while (i > 0 && A[i] > key) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }

  printf("Sorted Array: [ ");
  for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
    printf("%i, ", A[i]);
  }
  printf("]\n");

  return 0;
}

// Exericse 2.1-2:      WNx - 2017-02-05 15:18
// Rewrite INSERTION-SORT procedure to sort in non-increasing
// instead of increasing order

// int main(void) {
//   int A[10] = {0,9,2,8,4,5,7,5,1,3};
//
//   printf("Array: [ ");
//   for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
//     printf("%i, ", A[i]);
//   }
//   printf("]\n");
//
//   for (int j = 1; j < sizeof(A)/sizeof(int); j++) {
//       int key = A[j];
//       int i = j - 1;
//       while (i >= 0 && A[i] < key) {
//         A[i + 1] = A[i];
//         i = i - 1;
//       }
//       A[i + 1] = key;
//   }
//
//   printf("Sorted Array: [ ");
//   for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
//     printf("%i, ", A[i]);
//   }
//   printf("]\n");
//
//   return 0;
// }
