/*Creating a C++ laboratory activity for the Sudoku Puzzle Analyzer based on the provided specifications
involves several steps. Below is a step-by-step procedure for implementing this program:*/

/*Group 2*/

/*Laboratory 2 Activity #1 */

/*Leader: ALlen Jefferson C. Orcino
  Member: Carl Angelo Recodigs
 */

#include <iostream>
#include <string>

using namespace std;

const int MAX_COL = 9, MAX_ROW = 9;
int sudokuProblem[9][9] = {};
int sudokuAnswer[9][9];

int columnLocation, rowLocation, boxColumnLocation, boxRowLocation; // various location for analysis
int rowValues[9], columnValues[9], boxValues[9];                    // various values for analysis
int rowHints[9], columnHints[9], boxHints[9], uniqueHints[9];       // Various hints for analysis

void input();
void rowAssignment(int row, string rowValueStr);
void sudokuAnalyzer();
void sudokuAnswers();
void printPuzzle(int sudokuProblem[9][9]);
int menu(string question, string choices[25], int choiceCount);
void rowValue(int row);
void columnValue(int column);
void boxValue();
void hint();
bool inUniqueHints(int value);
void printValues(int values[9]);
void resets(int sodokuProblem[9][9], int sudokuAnswer[9][9]);
//  prototype

void resets()
{
  // Resets only user-answered cells
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      sudokuProblem[i][j] = 0;
      sudokuAnswer[i][j] = 0;
    }
  }
  cout << "Puzzle reset to the original state." << endl;
}

void sudokuAnswers()
{
  int answer;
  cout << "Please provide the answer for cell (" << columnLocation << ", " << rowLocation << "): ";
  cin >> answer;

  if (inUniqueHints(answer))
    sudokuAnswer[rowLocation][columnLocation] = answer;
  else
    cout << "You have provided an incorrect answer.";
}

bool inUniqueHints(int value)
{
  // Checks if the answer is in possible hints
  bool withinHints = false;

  for (int x = 0; x < 9; x++)
  {
    if (uniqueHints[x] == 0)
      continue;
    if (uniqueHints[x] == value)
    {
      withinHints = true;
      break;
    }
  }

  return withinHints;
}

void sudokuAnalyzer()
{
  string cellAddress;
  cout << "\nWhat cell would you like to analyze? ";
  cin >> cellAddress;

  rowLocation = (int)cellAddress.at(1) - 49;
  columnLocation = (int)cellAddress.at(0) - 65;

  // Check if the input is valid
  if (rowLocation < 0 || rowLocation >= MAX_ROW || columnLocation < 0 || columnLocation >= MAX_COL)
  {
    cout << "Cell address is invalid. Please provide a correct cell number." << endl;
    return;
  }

  boxColumnLocation = (columnLocation - columnLocation % 3) / 3;
  boxRowLocation = (rowLocation - rowLocation % 3) / 3;

  cout << "Cell Coordinates: (" << columnLocation << ", " << rowLocation << ")" << endl;
  cout << "Box Coordinates: (" << boxColumnLocation << ", " << boxRowLocation << ")" << endl;

  rowValue(rowLocation);
  columnValue(columnLocation);
  boxValue();
  cout << endl;
  cout << "Row Values: ";
  printValues(rowValues);
  cout << "Column Values: ";
  printValues(columnValues);
  cout << "Box Values: ";
  printValues(boxValues);
  cout << endl;
  hint();
  cout << "Row Hints: ";
  printValues(rowHints);
  cout << "Column Hints: ";
  printValues(columnHints);
  cout << "Box Hints: ";
  printValues(boxHints);
  cout << endl;
  cout << "Possible Answer: ";
  printValues(uniqueHints);
  cout << endl;
  cin.get();
  cout << "Successful . . . ";
  cin.get();
  cout << endl;
}

void rowValue(int row)
{
  for (int col = 0; col < MAX_COL; col++)
    rowValues[col] = sudokuAnswer[row][col];
}

void columnValue(int column)
{
  for (int row = 0; row < MAX_ROW; row++)
    columnValues[row] = sudokuAnswer[row][column];
}

void boxValue()
{
  // Retrieves values from the box
  int startRow = boxRowLocation * 3, startCol = boxColumnLocation * 3,
      endRow = startRow + 2, endCol = startCol + 2;

  for (int row = startRow; row <= endRow; row++)
  {
    for (int col = startCol; col <= endCol; col++)
    {
      boxValues[(col - startCol) + (row - startRow) * 3] = sudokuAnswer[row][col];
    }
  }
}

void hint()
{
  // Generates hints for row, column, and box
  for (int x = 0; x < 9; x++)
  {
    rowHints[x] = x + 1;
    columnHints[x] = x + 1;
    boxHints[x] = x + 1;

    if (rowValues[x] > 0)
      rowHints[rowValues[x] - 1] = 0;
    if (columnValues[x] > 0)
      columnHints[columnValues[x] - 1] = 0;
    if (boxValues[x] > 0)
      boxHints[boxValues[x] - 1] = 0;
  }

  // Generates unique hints
  for (int x = 0; x < 9; x++)
  {
    if (rowHints[x] == (x + 1) && columnHints[x] == (x + 1) && boxHints[x] == (x + 1))
      uniqueHints[x] = x + 1;
    else
      uniqueHints[x] = 0;
  }
}

void printValues(int values[9])
{
  int hintCount = 0;
  for (int x = 0; x < MAX_COL; x++)
  {
    if (values[x] == 0)
      continue;
    if (hintCount > 0)
      cout << ", ";
    cout << values[x];
    hintCount++;
  }
  cout << endl;
}

void input()
// user input
{
  string rowValue;
  cout << "+----------------------------------------------------------------------------------+\n";
  cout << "| Please provide a Sudoku Problem                                                  |\n";
  cout << "| Please enter the values for each row in the following format (e.g., 000100200):: |\n";
  cout << "+----------------------------------------------------------------------------------+\n";
  cout << endl;

  for (int row = 0; row < MAX_ROW; row++)
  {
    bool inValid = false;
    while (!inValid)
    {
      cout << "\nPlease enter value for Row # " << row + 1 << ": ";
      cin >> rowValue;

      // Check if the input is valid
      inValid = true;
      for (char c : rowValue)
      {
        if (c < '0' || c > '9')
        {
          inValid = false;
          break;
        }
      }

      if (!inValid)
      {
        cout << "Invalid data. Please only input digits 0 through 9." << endl;
        cin.clear();
      }
      else
      {
        // Check if the row value adheres to Sudoku rules
        bool validSudokuRow = true;
        for (char c : rowValue)
        {
          int num = c - '0';
          if (num < 0 || num > 9)
          {
            validSudokuRow = false;
            break;
          }
        }

        if (!validSudokuRow)
        {
          cout << "Invalid data. Values from Sudoku must bet." << endl;
          inValid = false;
        }
      }
    }

    rowAssignment(row, rowValue);
  }
}

void rowAssignment(int row, string rowValueStr)
{
  // Assigns row values based on user input
  for (int x = 0; x < MAX_COL; x++)
    sudokuAnswer[row][x] = (int)rowValueStr.at(x) - '0';
}

int main()
{

  string choices[25] = {
      "Provide an answer for this cell",
      "Check another cell",
      "Reset the Puzzle",
      "Exit the application"};

  cout << "+-----------------------------------+\n";
  cout << "| Leader: Allen Jefferson C. Orcino |\n";
  cout << "| Member: Carl Angelo Recodig       |\n";
  cout << "+-----------------------------------+\n";
  cout << endl;

  input(); // Collects initial Sudoku problem from the user

  while (1) // use while for looping
  {
    cout << endl;
    printPuzzle(sudokuAnswer);
    sudokuAnalyzer();

    switch (menu("What action do you like to perform? ", choices, 4))
    {
    case 0:
      sudokuAnswers(); // Allows the user to provide an answer for a cell
      break;
    case 2:
      resets();
      cout << "Puzzle reset to the original state." << endl;
      break;
    case 3:
      cin.get();
      cout << endl;
      cout << endl;
      cout << "Thank you for playing sudoku . . . ";
      cout << endl;
      cin.get();
      exit(1);
      break;
    }
  }
}

// sudoku probloem row and column
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