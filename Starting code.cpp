#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
// functions:

// 1. calculateLetterGrade, which takes a double parameter (the weighted average) and returns a string type letter grade.mathew



// 2. findMinQuiz, which takes 4 double parameters (the 4 quiz scores) and returns the lowest quiz score. ethen



// 3. findAverageQuizScore that takes 4 double parameters (the 4 quiz scores). This function removes the lowest quiz score and returns the average of the quiz scores. ana
double findAverageQuizScore (double Qscore1, double Qscore2, double Qscore3, double Qscore4)
{
  
return (Qscore1 + Qscore2 + Qscore3 + Qscore4 - findMinQuiz())/3;
}

// 4. findAverageHomeworkScore that takes 4 double parameters which are the homework scores. The function returns the average of the 4 homework scores.omar


//5. findAverageLabScore that takes 8 double parameters (the 8 lab scores) and returns the average of the 8 lab scores.the girl


//6. Add more functions if you would like to

int main() {

 ifstream file;
 file.open ("gradesIn.txt")




  //we used while (! end of the file ) to keep reading the data from the file until last charcter in the file.
  
  while (!file.eof())
{










}

return 0;
}