#include <iostream>

#define N 9 

/*
 * @desc Check if a number can be in a certain position [row, column]
 * @param row, column, number, sudoku_board- the sudoku to be solve
 * @return bool - true if find a successful number for the position otherwise return false
 */
bool checkSudoku(int row,int column,int number,int matrix_board[N][N]){
	
	for(int i=0;i<N;i++){//Check the row
		if(matrix_board[row][i]==number) return false;			
	}
	
	for(int i=0;i<N;i++){//Check the column
		if(matrix_board[i][column]==number) return false;
	}
	
	row -= row%3;
	column -= column%3;
	
	for(int i=0;i<3;i++){//Check the square
		for(int j=0;j<3;j++){
			if(matrix_board[row+i][column+j]==number) return false;		
		}
	}
			
	return true;	
}


/*
 * @desc Solve a sudoku 9x9
 * @param int matrix[9][9] - the sudoku to be solve
 * @return bool - true if find a successful number for the position otherwise return false
 */
bool solveSudoku (int matrix[N][N]){
	int row, column;
	bool finished = true;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(matrix[i][j]==0){
				finished = false;
				row=i;
				column=j;
				break;
			}
		}
	}
	
	if(finished){
		std::cout<<("Solution: \n")<<std::endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				std::cout<<matrix[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		return true;	
	}
		
	for(int i=0;i<10;i++){
		if(checkSudoku(row,column,i,matrix)){
			matrix[row][column]=i;
			if(solveSudoku(matrix)) return true;		
			matrix[row][column]=0;
		}
	}

	return false;
}


int main(){

	int sudokuTable[N][N] ={ 
	{5, 3, 0, 0, 7, 0, 0, 0, 0},  
	{6, 0, 0, 1, 9, 5, 0, 0, 0},  
	{0, 9, 8, 0, 0, 0, 0, 6, 0},  
	{8, 0, 0, 0, 6, 0, 0, 0, 3},  
	{4, 0, 0, 8, 0, 3, 0, 0, 1},  
	{7, 0, 0, 0, 2, 0, 0, 0, 6},  
	{0, 6, 0, 0, 0, 0, 2, 8, 0},  
	{0, 0, 0, 4, 1, 9, 0, 0, 5},  
	{0, 0, 0, 0, 8, 0, 0, 7, 9}}; 
	                    
	if(solveSudoku(sudokuTable))
		std::cout<<"\nSuccesful ;)"<<std::endl;
	else
		std::cout<<"\nThis sudoku cannot be solved, sorry :("<<std::endl;
	
	return 0;
}


