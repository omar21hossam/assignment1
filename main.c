#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ###################### Student ######################

// Contains student info
typedef struct StudentInfo
{
  char name[25];
  int ID;
  int dateofbirth[3];
  int score;
} StudentInfo;

// Fills student info from input stream
void fillStudent(StudentInfo *student)
{
  // Flush input
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    /* ignore */;

  printf("Enter name: ");
  fgets(student->name, sizeof(student->name), stdin);
  student->name[strcspn(student->name, "\n")] = 0;

  printf("Enter ID: ");
  scanf("%d", &student->ID);

  printf("Enter birth date (day month year): ");
  for (int i = 0; i < 3; i++)
    scanf("%d", &student->dateofbirth[i]);

  printf("Enter score: ");
  scanf("%d", &student->score);
  printf("\n");
}

// Fills student info with random info
void fillRandomStudent(StudentInfo *student)
{
  static const const char *firstNames[] = {"Adham", "Omar", "Omar"};
  static const const char *lastNames[] = {"Mohamed", "Hossam", "El Shemy"};

  const char *firstName = firstNames[rand() % 3];
  size_t firstNameLength = strlen(firstName);
  const char *lastName = lastNames[rand() % 3];
  size_t lastNameLength = strlen(lastName);

  memcpy(student->name, firstName, firstNameLength * sizeof(char));
  student->name[firstNameLength] = ' ';
  memcpy(student->name + firstNameLength + 1, lastName, lastNameLength * sizeof(char));
  student->name[firstNameLength + lastNameLength + 1] = '\0';
  student->ID = (rand() % 200) + 1;
  student->dateofbirth[0] = (rand() % 30) + 1;
  student->dateofbirth[1] = (rand() % 12) + 1;
  student->dateofbirth[2] = (rand() % 30) + 1980;
  student->score = (rand() % 50) + 50;
}

// Prints student info to output stream
void printStudent(const StudentInfo *student)
{
  printf("%d: %s %d/%d/%d %d%%\n", student->ID, student->name,
         student->dateofbirth[0], student->dateofbirth[1],
         student->dateofbirth[2], student->score);
}

// Prints students table header
void printStudentTableHeader()
{
  printf("--------------------------------------------------------------\n");
  printf("|     ID |           Name           |  Birth Date  |   Score |\n");
  printf("--------------------------------------------------------------\n");
}

// Prints student in tabular form
void printStudentTable(const StudentInfo *student)
{
  // Format birth date
  char birthDate[13];
  sprintf(birthDate, "%d/%d/%d", student->dateofbirth[0],
          student->dateofbirth[1], student->dateofbirth[2]);

  // Print student in tabular form
  printf("| %6d | %-24s | %-12s | %6d%% |\n",
         student->ID, student->name,
         birthDate, student->score);
}

// Prints student in tabular form
void printStudentTableFooter()
{
  printf("--------------------------------------------------------------\n\n");
}

int main()
{
  struct StudentInfo student1;
  fillStudent(&student1);
  printStudent(&student1);
  return 0;
}
