#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// functions:

// 1. calculateLetterGrade, which takes a double parameter (the weighted average) and returns a string type letter grade.




// 2. findMinQuiz, which takes 4 double parameters (the 4 quiz scores) and returns the lowest quiz score.
double findMinQuiz( double quizOne, double quizTwo, double quizThree, double quizFour) 
{
	if (quizOne < quizTwo && quizTwo < quizThree && quizThree < quizFour) {
		return quizOne;
	}
	if (quizTwo < quizOne && quizOne < quizThree && quizThree < quizFour) {
		return quizTwo;
	}
	if (quizThree < quizOne && quizOne < quizTwo && quizTwo < quizFour) {
		return quizThree;
	}
	if (quizFour < quizOne && quizOne < quizTwo && quizTwo < quizThree) {
		return quizFour;
	}
}



// 3. findAverageQuizScore that takes 4 double parameters (the 4 quiz scores). This function removes the lowest quiz score and returns the average of the quiz scores.



// 4. findAverageHomeworkScore that takes 4 double parameters which are the homework scores. The function returns the average of the 4 homework scores.



//5. findAverageLabScore that takes 8 double parameters (the 8 lab scores) and returns the average of the 8 lab scores.



//6. Add more functions if you would like to

int main() {

	string name; 
	double quizOne, quizTwo, quizThree, quizFour;
	
	ifstream file;
	file.open("gradeIn.txt");
	ofstream fout;
	fout.open("gradeOut.txt");


	//fout << "The grade of student is: ";
	
	
  //we used while (! end of the file ) to keep reading the data from the file until last charcter in the file.
  while (!file.eof())
{
	  file >> quizOne >> quizTwo >> quizThree >> quizFour;
	  cout << findMinQuiz(quizOne, quizTwo, quizThree, quizFour);


}

return 0;
}
