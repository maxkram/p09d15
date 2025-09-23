#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"
#include <stdio.h>
#include <stdlib.h>

// Динамическая загрузка
#ifdef DYNAMIC
#include <dlfcn.h>

// Объявления функций для динамической загрузки
typedef int (*normalization_func)(double *, int);
typedef void (*sort_func)(double *, int);

#else
// Статическая линковка
#include "../data_module/data_process.h"

#endif

int main() {
  double *data;
  int n;
  printf("LOAD DATA...\n");
  if (scanf("%d", &n) != 1 || n <= 0) return printf("n/a"), 1;
  data = (double *)malloc(n * sizeof(double));
  if (data == NULL) return printf("n/a"), 1;
  input(data, n);
  printf("RAW DATA:\n\t");
  output(data, n);
#ifdef DYNAMIC
  // Динамическая загрузка библиотеки
  void *handle = dlopen("./data_process.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "Error loading library: %s\n", dlerror());
    free(data);
    return 1;
  }
  // Загрузка функций из библиотеки
  normalization_func normalization =
      (normalization_func)dlsym(handle, "normalization");
  sort_func sort = (sort_func)dlsym(handle, "sort");
  char *error = dlerror();
  if (error) {
    fprintf(stderr, "Error loading functions: %s\n", error);
    dlclose(handle);
    free(data);
    return 1;
  }
#endif
  printf("\nNORMALIZED DATA:\n\t");
  double *normalized_data = (double *)malloc(n * sizeof(double));
  for (int i = 0; i < n; i++)
    normalized_data[i] = data[i];
  if (normalization(normalized_data, n))
    output(normalized_data, n);
  else printf("ERROR");
  printf("\nSORTED NORMALIZED DATA:\n\t");
  sort(normalized_data, n);
  output(normalized_data, n);
  printf("\nFINAL DECISION:\n\t");
  if (make_decision(data, n)) printf("YES");
  else printf("NO");
  printf("\n");
#ifdef DYNAMIC
  dlclose(handle);
#endif
  free(data);
  free(normalized_data);
  return 0;
}