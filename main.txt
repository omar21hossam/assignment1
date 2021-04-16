#include <stdio.h>
struct
{
  char name[25];
  int ID;
  int dateofbirth[3];
  int score;
} studnetInfo;
int
main ()
{
  printf ("welcome\n");
  printf ("Enter your name\n");
  gets (studnetInfo.name);
  printf ("Enter your ID\n");
  scanf ("%d", &studnetInfo.ID);
  printf ("Enter your date of birth(day, month, year)\n");
  for (int i = 0; i < 3; i++)
    {
      scanf ("%d", &studnetInfo.dateofbirth[i]);

    }
  printf ("Enter your score\n");
  scanf ("%d", &studnetInfo.score);
  printf ("%s   %d   %d   %d   %d   %d", studnetInfo.name, studnetInfo.ID,
	  studnetInfo.dateofbirth[0], studnetInfo.dateofbirth[1],
	  studnetInfo.dateofbirth[2], studnetInfo.score);
  return 0;
}
