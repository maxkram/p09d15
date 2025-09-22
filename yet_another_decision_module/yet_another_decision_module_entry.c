#include "../data_libs/data_io.h"
#include "decision.h"
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

  // Вводим данные
  input(data, n);

  // Принимаем решение и выводим результат
  if (make_decision(data, n)) {
    printf("YES");
  } else {
    printf("NO");
  }

  free(data);
  return 0;
}