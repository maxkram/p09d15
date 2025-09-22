#include "decision.h"
#include "../data_libs/data_stat.h"
#include <math.h>

int make_decision(double *data, int n) {
  if (n <= 0)
    return 0;

  double m = mean(data, n);
  double sigma = sqrt(variance(data, n));
  double max_value = max(data, n);
  double min_value = min(data, n);

  int decision =
      (max_value <= m + 3 * sigma) && // Максимум в пределах +3σ
      (min_value >= m - 3 * sigma) && // Минимум в пределах -3σ
      (m >= GOLDEN_RATIO - 0.1) &&    // Среднее близко к золотому сечению
      (m <= GOLDEN_RATIO + 0.1);      // Но с допустимым отклонением

  return decision;
}