#include<stdio.h>
#define NROWS 3
#define NCOLS 4

void displayMatrix(int N[][NCOLS]){
	int i, j;
	
	for(i = 0; i < NROWS; i++){
		for(j = 0; j < NCOLS; j++){
			printf("%d ", N[i][j]);
		}
		printf("\n");
	}
}

int Minimum(int N[][NCOLS]){
	int i, j, min;
	min = N[0][0];
	
	for(i = 0; i < NROWS; i++){
		for(j = 0; j < NCOLS; j++){
			if(N[i][j] < min){
				min = N[i][j];
			}
		}
	}
	printf("The min is: %d\n", min);
}

int Sum(int N[][NCOLS]){
	int i, j, sum;
	sum = 0;
	
	for(i = 0; i < NROWS; i++){
		for(j = 0; j < NCOLS; j++){
			sum += N[i][j];
		}
	}
	printf("The sum is: %d\n", sum);
	
	return sum;
}

int RowSum(int N[][NCOLS], int row_index){
	int i, rowsum = 0;
	
	for (i = 0; i < NCOLS; i++){
	rowsum += N[row_index][i];
	}
	printf("Row %d sum is %d\n", row_index, rowsum);
}

int ColSum(int N[][NCOLS], int col_index){
	int i, colsum = 0;
	
	for (i = 0; i < NROWS; i++){
	colsum += N[i][col_index];
	}
	printf("Column %d sum is %d\n", col_index, colsum);
}

float Average(int N[][NCOLS]){
	float ave, sum;
	int n;
	
	n = NCOLS * NROWS;
	sum = Sum(N);
	ave = sum / n;
	printf("The average is %.2f\n", ave);
}

int* Search(int N[][NCOLS], int key){
	int i, j, result, chkr = 0;
	
	for(i = 0; i < NROWS; i++){
		for(j = 0; j < NCOLS; j++){
			if(N[i][j] == key){
				result = N[i][j];
				chkr++;
			}
		}
	}
	if(chkr != 0)
		printf("Key %d is found\n", key);
	else
		printf("Key %d is NOT found\n", key);
}

int main(){
	int i, j, row_index, col_index, key;
	
	int N[NROWS][NCOLS]= {{7, 22, 14, 78}, {120, 53, 62, 45}, {90, 14, 85, 12}};
	
	displayMatrix(N);
	Minimum(N);
	Sum(N);
	
	printf("Enter row index: "); scanf("%d", &row_index);
	printf("Enter column index: "); scanf("%d", &col_index);

	RowSum(N, row_index);
	ColSum(N, col_index);
	Average(N);
	
	printf("Enter key: "); scanf("%d", &key);
	Search(N, key);
	
	return 0;
}