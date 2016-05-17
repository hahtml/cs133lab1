#include "const.h"
#include <omp.h>


// void mmul2(float A[ni][nk], float B[nk][nj], float C[ni][nj])
// {
// 	int i, j, k;
// 	int kk, jj;
// 	float sum;
// 	int step=64;
// 	#pragma omp parallel for private(j)
// 	for (i=0; i<ni; i++) {
// 		for (j=0; j<nj; j++) {
// 			C[i][j]=0.0;
// 		}
// 	}

// 	// for (kk=0; kk<nk; kk+=step) {
// 	// 	#pragma omp parallel for private(i, j, k, sum)
// 	// 	for (jj=0; jj<nj; jj+=step) {	
// 	// 		for (i=0; i<ni; i++) {
// 	// 			for (k=kk; k<kk+step; k++) {
// 	// 				//sum=C[i][j];
// 	// 				for (j=jj; j<jj+step; j++) {
// 	// 					C[i][j]+=A[i][k]*B[k][j];
// 	// 				}
// 	// 				//C[i][j]=sum;
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }


// 	//original version
// 	for (kk=0; kk<nk; kk+=step) {
// 		for (jj=0; jj<nj; jj+=step) {
			
// 			for (i=0; i<ni; i++) {
// 				#pragma omp parallel for private(j) schedule(static)
// 				for (k=kk; k<kk+step; k++) {
// 					//sum=C[i][j];
// 					for (j=jj; j<jj+step; j++) {
// 						C[i][j]+=A[i][k]*B[k][j];
// 					}
// 					//C[i][j]=sum;
// 				}
// 			}
// 		}
// 	}

// }


void mmul2(float A[ni][nk], float B[nk][nj], float C[ni][nj])
{
	int i, j, k;
	int kk, jj;
	float sum;
	int step=64;
	#pragma omp parallel for private(j)
	for (i=0; i<ni; i++) {
		for (j=0; j<nj; j++) {
			C[i][j]=0.0;
		}
	}


	//original version
	for (kk=0; kk<nk; kk+=step) {
		#pragma omp parallel for private(i, j, k)
		for (jj=0; jj<nj; jj+=step) {	
			for (i=0; i<ni; i++) {
				for (k=kk; k<kk+step; k++) {
					//sum=C[i][j];
					for (j=jj; j<jj+step; j++) {
						C[i][j]+=A[i][k]*B[k][j];
					}
					//C[i][j]=sum;
				}
			}
		}
	}

}
