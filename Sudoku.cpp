/*Creating a C++ laboratory activity for the Sudoku Puzzle Analyzer based on the provided specifications
involves several steps. Below is a step-by-step procedure for implementing this program:*/

/*Group 2*/

/*Laboratory 2 Activity #1 */

/*Leader: ALlen Jefferson C. Orcino
  Member:
  Carl Angelo Recodig
  John Carlo Reyes // seen but no respond
  John Carlo Pante // No seen No respond
*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_COL = 9, MAX_ROW = 9;
int sudokuProblem[9][9] = {
    {0, 0, 0, 0, 4, 0, 9, 0, 0}, // 1 000040900
    {0, 8, 0, 6, 7, 0, 0, 0, 0}, // 2 080670000
    {9, 0, 2, 8, 0, 0, 4, 0, 0}, // 3 902800400
    {0, 9, 1, 0, 0, 0, 0, 0, 0}, // 4 091000000
    {0, 4, 0, 3, 6, 0, 0, 0, 2}, // 5 040360002
    {0, 0, 0, 0, 0, 0, 5, 0, 4}, // 6 000000504
    {0, 0, 0, 0, 0, 0, 7, 0, 1}, // 7 000000701
    {0, 2, 8, 0, 0, 1, 0, 3, 0}, // 8 028001030
    {1, 0, 3, 7, 0, 6, 8, 0, 0}  // 9 103706800
},
    sudokuAnswer[9][9];

int columnLocation, rowLocation,
    boxColumnLocation, boxRowLocation;

int rowValues[9], columnValues[9], boxValues[9],
    rowHints[9], columnHints[9], boxHints[9],
    uniqueHints[9];

void printPuzzle(int sudokuProblem[9][9]);

int menu(string question, string choices[25], int choiceCount);

void createHints(int sudokuProblem[9][9], int row, int col, int hint[9], int rowHints[9], int columnHints[9], int boxHints[9])
{

  for (int i = 0; i < 9; i++)
  {
    hint[i] = 0;
    rowHints[i] = 0;
    columnHints[i] = 0;
    boxHints[i] = 0;
  }

  for (int i = 0; i < 9; i++)
  {
    if (sudokuProblem[row][i] != 0)
    {
      rowHints[sudokuProblem[row][i] - 1] = 1;
    }
  }

  for (int i = 0; i < 9; i++)
  {
    if (sudokuProblem[i][col] != 0)
    {
      columnHints[sudokuProblem[i][col] - 1] = 1;
    }
  }

  int boxRow = row - row % 3;
  int boxCol = col - col % 3;
  for (int i = boxRow; i < boxRow + 3; i++)
  {
    for (int j = boxCol; j < boxCol + 3; j++)
    {
      if (sudokuProblem[i][j] != 0)
      {
        boxHints[sudokuProblem[i][j] - 1] = 1;
      }
    }
  }

  for (int i = 0; i < 9; i++)
  {
    hint[i] = rowHints[i] || columnHints[i] || boxHints[i] ? 1 : 0;
  }
}

/*void createValue();*/

int main()
{
  string choices[25] = {
      "Provide an answer for this cell",
      "Check another cell",
      "Reset the Puzzle",
      "Exit the application \n"};

  int choice;

  while (1)
  {
    printPuzzle(sudokuProblem);
    choice = menu("\n What action do you like to perform? \n", choices, 4);
    switch (choice)
    {
    case 0:
      int row, col, value;
      cout << "Enter the row (1-9): ";
      cin >> row;
      cout << "Enter the column (a-i): ";
      char colChar;
      cin >> colChar;
      col = colChar - 'a';
      cout << "Enter the value (1-9): ";
      cin >> value;
      sudokuProblem[row - 1][col] = value;
      cout << endl;
      int hint[9], rowHints[9], columnHints[9], boxHints[9];
      createHints(sudokuProblem, row - 1, col, hint, rowHints, columnHints, boxHints);
      cout << endl;
      cout << "Hints for cell (" << row << ", " << colChar << "): ";
      cout << endl;
      cout << "\nRow Hint: ";
      for (int i = 0; i < 9; i++)
      {
        if (rowHints[i] == 0)
        {
          cout << i + 1 << " ";
        }
      }
      cout << "\nColumn Hint: ";
      for (int i = 0; i < 9; i++)
      {
        if (columnHints[i] == 0)
        {
          cout << i + 1 << " ";
        }
      }
      cout << "\nBox Hint: ";
      for (int i = 0; i < 9; i++)
      {
        if (boxHints[i] == 0)
        {
          cout << i + 1 << " ";
        }
      }
      cout << endl;
      cin.get();
      cout << endl;
      cout << "To return to Choices, press ENTER . . . ";
      cout << endl;
      cin.get();
      break;

    case 1:
      cout << "Enter the row 1-9: ";
      cin >> row;
      cout << "Enter the column a-i: ";
      cin >> colChar;
      col = colChar - 'a';
      cout << "Value in cell (" << row << ", " << colChar << "): " << sudokuProblem[row - 1][col] << endl;
      cout << endl;
      cout << "Hints for cell (" << row << ", " << colChar << "): ";
      cout << endl;
      createHints(sudokuProblem, row - 1, col, hint, rowHints, columnHints, boxHints);
      cout << "\nRow Hint: ";
      for (int i = 0; i < 9; i++)
      {
        if (rowHints[i] == 0)
        {
          cout << i + 1 << " ";
        }
      }
      cout << "\nColumn Hint: ";
      for (int i = 0; i < 9; i++)
      {
        if (columnHints[i] == 0)
        {
          cout << i + 1 << " ";
        }
      }
      cout << "\nBox Hint: ";
      for (int i = 0; i < 9; i++)
      {
        if (boxHints[i] == 0)
        {
          cout << i + 1 << " ";
        }
      }
      cout << endl;
      cin.get();
      cout << endl;
      cout << "To return to Choices, press ENTER . . . ";
      cout << endl;
      cin.get();
      break;

    case 2:
      for (int i = 0; i < MAX_ROW; i++)
      {
        for (int j = 0; j < MAX_COL; j++)
        {
          sudokuProblem[i][j] = sudokuAnswer[i][j];
        }
      }
      cout << "Puzzle reset to the original state." << endl;
      cout << endl;
      cin.get();
      cout << "To return to Choices, press ENTER . . . ";
      cin.get();
      break;

    case 3:
      cout << "Exiting the application." << endl;
      cout << endl;
      cin.get();
      cout << endl;
      cout << "Thank you! and God bless!";
      cout << endl;
      cout << endl;
      cin.get();
      exit(1);
      break;

    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}

void printPuzzle(int sudokuProblem[9][9])
{
  char rowLabels[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
       colLabels[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

  for (int x = 0; x < MAX_COL; x++)
  {
    if (x == 0)
      cout << "    " << colLabels[x];
    else
      cout << "   " << colLabels[x];
  }
  cout << endl;
  cout << ("\n  ╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
  for (int row = 0; row < MAX_ROW; row++)
  {
    for (int col = 0; col < MAX_COL; col++)
    {
      if (col == 0)
        cout << rowLabels[row] << " ";
      if (col % 3 == 0)
        cout << "| ";
      else if (col % 3 == 1 || col % 3 == 2)
        cout << "| ";
      if (sudokuProblem[row][col] != 0)
        cout << sudokuProblem[row][col] << " ";
      else
        cout << "  ";
      if (col == MAX_COL - 1)
        cout << "|";
    }

    cout << endl;

    if (row % 3 == 0 || row % 3 == 1)
      cout << "  |   |   |   |   |   |   |   |   |   |\n";
    else if (row % 3 == 2 && row != MAX_ROW - 1)
      cout << "  |   |   |   |   |   |   |   |   |   |\n";
    else
      cout << "  |   |   |   |   |   |   |   |   |   |\n";
  }
}

int menu(string question, string choices[25], int choiceCount)
{
  int choice = -1;

  cout << question << endl;

  for (int x = 0; x < choiceCount; x++)
  {
    cout << x + 1 << " - " << choices[x] << endl;
  }
  cout << "Please enter your choice: ";
  cin >> choice;

  if (choice >= 1 && choice <= choiceCount)
    return choice - 1;

  return -1;
}