#include "const.h"
#include <omp.h>

// void mmul1(float A[ni][nk], float B[nk][nj], float C[ni][nj])
// {
// 	int i, j, k;
// 	float tmp;
// 	#pragma omp parallel for private(i, j, k, tmp) schedule(guided, 8)	
// 	for (i=0; i<ni; i++) {
// 		for (j=0; j<nj; j++) {
// 			tmp=0;
// 			for (k=0; k<nk; k++) {
// 				tmp += A[i][k]*B[k][j];
// 			}
// 			C[i][j]=tmp;
// 		}
// 	}
// }

void mmul1(float A[ni][nk], float B[nk][nj], float C[ni][nj])
{
	int i, j, k;
	#pragma omp parallel for private(j)
	for (i=0; i<ni; i++) {
		for (j=0; j<nj; j++) {
			C[i][j] = 0;
		}
	}
	#pragma omp parallel for private(j, k)
	for (i=0; i<ni; i++) {
		for (k=0; k<nk; k++){ 
			for (j=0; j<nj; j++) {
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}

// void mmul1(float A[ni][nk], float B[nk][nj], float C[ni][nj])
// {
// 	int i, j, k;
// 	#pragma omp parallel for private(j, k)
// 	for (i=0; i<ni; i++) {
// 		for (j=0; j<nj; j++) {
// 			C[i][j] = 0;
// 			for (k=0; k<nk; k++) {
// 				C[i][j] += A[i][k]*B[k][j];
// 			}
// 		}
// 	}
// }