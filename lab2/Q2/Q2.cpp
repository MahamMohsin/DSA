//Q2 main
#include "matrix_multiply.h"
#include <iostream>
using namespace std;

int main(){
	int row1,col1;
	cout<<"Enter dimensions (r1xc1) of matrix1: ";
	cin>>row1>>col1;
	cout<<endl;
	
	int row2,col2;
	cout<<"Enter dimensions (r2xc2) of matrix2: ";
	cin>>row2>>col2;
	cout<<endl;
	
	if(col1!=row2){
		cout<<"Matrix cannot be multiplied!"<<endl;
	}
	
	int**mat1=new int*[row1];
	for(int i=0;i<row1;i++){
		mat1[i]=new int[col1];
	}
	
	int**mat2=new int*[row2];
	for(int j=0;j<row2;j++){
	    mat2[j]=new int[col2];
	}
	
	int**result=new int*[row1];
	for(int i=0;i<row1;i++){
		result[i]=new int[col2];
	}
	
	cout<<"Enter the elements of Matrix 1: "<<endl;
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			cin>>mat1[i][j];
		}
	}
	
	cout<<"Enter the elements of Matrix 2: "<<endl;
	for(int i=0;i<row2;i++){
		for(int j=0;j<col2;j++){
			cin>>mat2[i][j];
		}
	}
	
	multiply(mat1,mat2,result,row1,col1,row2,col2);
	
	cout<<"Resultant Matrix: "<<endl;
	for(int i=0;i<row1;i++){
		for(int j=0;j<col2;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<row1;i++){
		delete[] mat1[i];
	}
	delete[] mat1;
	
	for(int i=0;i<row2;i++){
		delete[] mat2[i];
	}
	delete[] mat2;
	
	for(int i=0;i<row1;i++){
		delete[] result[i];
	}
	delete[] result;
	
return 0;
}
