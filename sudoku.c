#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j = 0; j < 9; j++)
  {
    for (int i = 0; i < 9; i++)
    {
      printf("%d  ", sudoku[j][i]);
    }
    printf("\n");
  }
}

int check_sudoku(int sudoku[9][9])
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */

  /*****
   * TO DO:
   * Complete this function
   *   -- BUT ONLY IF YOU WANT TO!
   * Our testing script only checks your Sudoku
   * solution, if you want to solve it without
   * using this function, or if you want to write
   * your own helper functions, that's ok!
   * *****/
  return 0;
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */

  /*****
   * TO DO
   * Complete this function
   * BUT ONLY IF YOU WANT TO!
   *   You can solve the Sudoku without using this function,
   * or you can write a different helper function, whatever
   * makes more sense to yoU! our checker won't look at this
   * function, 
   * ****/
  return 0;
}

int row_exists(int sudoku[9][9], int row, int n) // Checks if a row is solvable
{
  for (int col = 0; col < 9; col++)
  {
    if (sudoku[row][col] == n)
    {
      return 1;
    }
  }
  return 0;
}

int column_exists(int sudoku[9][9], int col, int n) // Checks if a column is solvable
{
  for (int row = 0; row < 9; row++)
  {
    if (sudoku[row][col] == n)
    {
      return 1;
    }
  }
  return 0;
}

int subgrid_exists(int sudoku[9][9], int first_row, int first_col, int n) // Checks if a subgrid is solvable
{
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      if (sudoku[row + first_row][col + first_col] == n)
      {
        return 1;
      }
    }
  }
  return 0;
}

int safe_number(int sudoku[9][9], int row, int col, int n) // Checks if the number is safe to be added
{
  return !row_exists(sudoku, row, n) && !column_exists(sudoku, col, n) &&
         !subgrid_exists(sudoku, row - (row % 3), col - (col % 3), n);
}

int unassigned(int sudoku[9][9], int *row, int *col)
{
  for (*row = 0; *row < 9; (*row)++)
  {
    for (*col = 0; *col < 9; (*col)++)
    {
      if (sudoku[*row][*col] == 0)
      {
        return 1;
      }
    }
  }

  return 0;
}

int real_solver(int sudoku[9][9])
{

  int row = 0, col = 0;

  if (!unassigned(sudoku, &row, &col))
  {
    return 1;
  }

  for (int n = 1; n < 10; n++)
  {

    if (safe_number(sudoku, row, col, n))
    {
      sudoku[row][col] = n;

      if (real_solver(sudoku))
      {
        return 1;
      }

      sudoku[row][col] = 0;
    }
  }

  return 0;
}

void solve_sudoku(int sudoku[9][9], int depth)
{
  real_solver(sudoku);
}

#ifndef __testing

int main()
{
  int Sudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);

  solve_sudoku(Sudoku, 0);

  printf("Solution is:\n");
  print_sudoku(Sudoku);
}

#endif
