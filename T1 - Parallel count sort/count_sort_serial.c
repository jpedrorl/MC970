
#include <stdlib.h>
#include <omp.h>
#include <string.h>

double count_sort_serial(double a[], int n) {
  int i, j, count;
  double *temp;
  double start, end;

  temp = (double *)malloc(n * sizeof(double));

  start = omp_get_wtime();
  
  for (i = 0; i < n; i++) {
    count = 0;
    for (j = 0; j < n; j++)
      if (a[j] < a[i])
	count++;
      else if (a[j] == a[i] && j < i)
	count++;
    temp[count] = a[i];
  }
  
  end = omp_get_wtime();

  memcpy(a, temp, n * sizeof(double));
  free(temp);

  return end - start;
}
