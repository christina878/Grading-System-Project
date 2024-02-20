#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
// functions:

// 1. calculateLetterGrade, which takes a double parameter (the weighted average) and returns a string type letter grade.
string calculateLetterGrade(double avg) {
	if (avg >= 90) {
		return "A";
	}
	else if (avg >= 80) {
		return "B";
	}
	else if (avg >= 75) {
		return "C+";
	}
	else if (avg >= 70) {
		return "C";
	}
	else if (avg >= 60) {
		return "D";
	}
	else {
		return "F";
	}
}

// 2. findMinQuiz, which takes 4 double parameters (the 4 quiz scores) and returns the lowest quiz score.
double findMinQuiz(double quizOne, double quizTwo, double quizThree, double quizFour) {
	double min = quizOne;
	if (quizTwo < min) {
		min = quizTwo;
	}
	if (quizThree < min) {
		min = quizThree;
	}
	if (quizFour < min) {
		min = quizFour;
	}
	return min;
}


// 3. findAverageQuizScore that takes 4 double parameters (the 4 quiz scores). This function removes the lowest quiz score and returns the average of the quiz scores.
double findAverageQuizScore(double Qscore1, double Qscore2, double Qscore3, double Qscore4) {
	return (Qscore1 + Qscore2 + Qscore3 + Qscore4 - findMinQuiz(Qscore1, Qscore2, Qscore3, Qscore4)) / 3.0;
}

// 4. findAverageHomeworkScore that takes 4 double parameters which are the homework scores. The function returns the average of the 4 homework scores.
double findAverageHomeworkScore(double hw1, double hw2, double hw3, double hw4) {
	return (hw1 + hw2 + hw3 + hw4) / 4.0;
}

//5. findAverageLabScore that takes 8 double parameters (the 8 lab scores) and returns the average of the 8 lab scores.
double findAverageLabScore(double lab1, double lab2, double lab3, double lab4, double lab5, double lab6, double lab7, double lab8) {
	return (lab1 + lab2 + lab3 + lab4 + lab5 + lab6 + lab7 + lab8) / 8.0;
}


//6. Add more functions if you would like to

int main() {


	int width = 30;
	string name, letterGrade, lastName;

	int attendance, groupwork, midterm, final, studentCount = 0;


	double lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8;


	double hw1, hw2, hw3, hw4;


	double quiz1, quiz2, quiz3, quiz4;


	double labResult, hw_result, quiz_result, average, avg_courses = 0.0;


	ifstream inFile("gradesIn.txt");
	ofstream output1("gradesOut1.txt");
	ofstream output2("gradesOut2.txt");

	//we used while (! end of the file ) to keep reading the data from the file until last charcter in the file.
	while (!inFile.eof()) {

		//reads in name
		if (inFile >> name >> lastName) {
			studentCount++;
		}
		//read in attendance
		inFile >> attendance;
		attendance *= 10;

		//read in labs
		inFile >> lab1 >> lab2 >> lab3 >> lab4 >> lab5 >> lab6 >> lab7 >> lab8;
		labResult = findAverageLabScore(lab1, lab2, lab3, lab4, lab5, lab6, lab7, lab8);
		labResult *= 10;

		//read in homework
		inFile >> hw1 >> hw2 >> hw3 >> hw4;
		hw_result = findAverageHomeworkScore(hw1, hw2, hw3, hw4);
		hw_result *= 10;


		//read in quiz
		inFile >> quiz1 >> quiz2 >> quiz3 >> quiz4;
		quiz_result = findAverageQuizScore(quiz1, quiz2, quiz3, quiz4);



		//read in groupwork score
		inFile >> groupwork;
		groupwork *= 10;

		//read in midterm
		inFile >> midterm;



		//read in final
		inFile >> final;

		//input all the data in gradeOut1.txt


		average = (attendance * 0.10) + (labResult * 0.15) + (hw_result * 0.15) + (quiz_result * 0.15) + (groupwork * 0.05) + (midterm * 0.20) + (final * 0.20);
		avg_courses += average;
		output1 << "--------------------------------------------------------------------------" << endl;
		output1 << "Student's first and last name: " << name << " " << lastName << endl;
		output1 << "Attendance: " << left << setw(width) << attendance << endl;
		output1 << "Group work: " << setw(width) << groupwork << endl;
		output1 << "Average of quizzes: " << setw(width) << quiz_result << endl;
		output1 << "Average of Labs: " << setw(width) << labResult << endl;
		output1 << "Average of homework: " << setw(width) << hw_result << endl;
		output1 << "Final exam: " << setw(width) << final << endl;
		output1 << "Course average: " << setw(width) << average << endl;


		//input all the data in gradeOut2.txt
		output2 << "--------------------------------------------------------------------------" << endl;
		output2 << "Student's first and last name: " << name << " " << lastName << endl;
		output2 << "Course average: " << left << setw(width) << average << endl;
		output2 << "Letter grade: " << setw(width) << calculateLetterGrade(average) << endl;
	
	}
	output2 << "--------------------------------------------------------------------------" << endl;
	output2 << "Number of Students is " << studentCount << endl;
	output2 << "The Average of the Course Averages is " << (avg_courses / studentCount) << endl;

	inFile.close();
	output1.close();
	output2.close();
	return 0;
}
