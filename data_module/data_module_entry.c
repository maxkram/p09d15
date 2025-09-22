#include "../data_libs/data_io.h"
#include "data_process.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  double *data;
  int n;

  // Считываем количество элементов
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("n/a");
    return 1;
  }

  // Выделяем память
  data = (double *)malloc(n * sizeof(double));
  if (data == NULL) {
    printf("n/a");
    return 1;
  }

  input(data, n);

  if (normalization(data, n)) {
    output(data, n);
  } else {
    printf("ERROR");
  }

  free(data);
  return 0;
}