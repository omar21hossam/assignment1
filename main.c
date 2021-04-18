#include <stdio.h>

// Contains student information
struct StudentInfo
{
  char name[25];
  int ID;
  int dateofbirth[3];
  int score;
};

// Fills student information from input stream
void fillStudent(struct StudentInfo *student)
{
  printf("welcome\n");
  printf("Enter your name\n");
  gets(student->name);
  printf("Enter your ID\n");
  scanf("%d", &student->ID);
  printf("Enter your date of birth(day, month, year)\n");
  for (int i = 0; i < 3; i++)
  {
    scanf("%d", &student->dateofbirth[i]);
  }
  printf("Enter your score\n");
  scanf("%d", &student->score);
}

// Prints student information to output stream
void printStudent(const struct StudentInfo *student)
{
         student->dateofbirth[0], student->dateofbirth[1],
         student->dateofbirth[2], student->score);
}

int main()
{
  struct StudentInfo student1;
  fillStudent(&student1);
  printStudent(&student1);
  return 0;
}
