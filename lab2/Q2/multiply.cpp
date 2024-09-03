//multiply.cpp
#include "matrix_multiply.h"

void multiply(int** mat1,int**mat2,int**resultant,int r1,int c1,int r2,int c2){
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
		resultant[i][j]=0;	
		}
	}
	
	if(c1==r2){
		for(int i=0;i<r1;i++){
			for(int j=0;j<c2;j++){
				for(int k=0;k<c1;k++){
					resultant[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}
}
}
