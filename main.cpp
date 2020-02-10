#include <iostream>

/*
 * @desc Check if a number can be in a certain position [row, column]
 * @param row, column, number, sudoku_board- the sudoku to be solve
 * @return bool - true if find a successful number for the position otherwise return false
 */
bool check_sudoku(int row,int column,int number,int matrix_board[9][9]){
	bool notPossible=false;
	
	for(int i=0;i<9;i++){//Check the row
		if(matrix_board[row][i]==number){
			notPossible=true;
		}			
	}
	
	for(int i=0;i<9;i++){//Check the column
		if(matrix_board[i][column]==number){
			notPossible=true;
		}
	}
	
	row -= row%3;
	column -= column%3;
	
	for(int i=0;i<3;i++){//Check the number in its 3x3 box 
		for(int j=0;j<3;j++){
			if(matrix_board[row+i][column+j]==number){
				notPossible=true;
			}
		}
	}	
	
	if(notPossible){
		return false;
	}else{
		return true;
	}

}

/*
 * @desc Solve a sudoku 9x9
 * @param int matrix[9][9] - the sudoku to be solve
 * @return bool - true if find a successful number for the position otherwise return false
 */
bool sudoku_solver(int matrix[9][9]){
	int row, column;
	bool finished = true;
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
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
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				std::cout<<matrix[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		return true;	
	}
		
	for(int i=0;i<10;i++){
		if(check_sudoku(row,column,i,matrix)){
			matrix[row][column]=i;
			if(sudoku_solver(matrix)){
				return true;
			}
			matrix[row][column]=0;
		}
	}

	return false;
}


int main(){

	int sudokuTable[9][9] ={ 
	{5, 3, 0, 0, 7, 0, 0, 0, 0},  
	{6, 0, 0, 1, 9, 5, 0, 0, 0},  
	{0, 9, 8, 0, 0, 0, 0, 6, 0},  
	{8, 0, 0, 0, 6, 0, 0, 0, 3},  
	{4, 0, 0, 8, 0, 3, 0, 0, 1},  
	{7, 0, 0, 0, 2, 0, 0, 0, 6},  
	{0, 6, 0, 0, 0, 0, 2, 8, 0},  
	{0, 0, 0, 4, 1, 9, 0, 0, 5},  
	{0, 0, 0, 0, 8, 0, 0, 7, 9}}; 
	                    
	if(sudoku_solver(sudokuTable)){
		std::cout<<"\nSuccesful ;)"<<std::endl;
	}else{
		std::cout<<"\nThis suoku cannot be solved, sorry :("<<std::endl;
	}

	return 0;
}


