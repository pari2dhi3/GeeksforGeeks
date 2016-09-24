#include<bits/stdc++.h>
using namespace std;
#define N 9
bool find_unassigned(vector<vector<char> >& board, int& row, int& col)
{
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(board[row][col]=='.')
				return true;
		}
	}
	return false;
}
bool is_safe(vector<vector<char> >& board, int& row, int& col, int& num)
{
	int i,r,c,j;
	for(i=0;i<N;i++)
	{
		if(board[row][i]==(num+'0'))
			return false;
	}
	for(i=0;i<N;i++)
	{
		if(board[i][col]==(num+'0'))
			return false;
	}
	r=row/3;
	c=col/3;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[((r*3)+i)][((c*3)+j)]==(num+'0'))
				return false;
		}
	}
	return true;
}
bool sudoku(vector<vector<char> >& board)
{
	int row,col,i;
	if(!find_unassigned(board,row,col))
		return true;
	for(i=1;i<=N;i++)
	{
		if(is_safe(board,row,col,i))
		{
			board[row][col]=(i+'0');
			if(sudoku(board))
				return true;
			else
				board[row][col]='.';
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int i,j;
	vector<vector<char> > board(N,vector<char> (N,'.'));
	cout << "KINDLY ENETR THE NUMBERS AND BLANK SPACES SHOULD BE FILLED WITH '.' \n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			cin >> board[i][j];
	}
	sudoku(board);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	return 0;
}
