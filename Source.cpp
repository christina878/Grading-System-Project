#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

string calculateLetterGrade(double avg) {
	string letterGrade;
	
	if (avg >= 90) {
		letterGrade = 'A';
		return letterGrade;
	}
	else if (avg >= 80) {
		letterGrade = 'B';
		return letterGrade;
	}
	else if (avg >= 75){
		letterGrade = "C+ ";
		
	return letterGrade;
}
	else if (avg >= 70){
		letterGrade = 'C';
		return letterGrade;
	}
	else if (avg >= 60){
		letterGrade = 'D';
		return letterGrade;
	}
	else if (avg >= 0){
		letterGrade = 'F';
		return letterGrade;
	}

	
}

int main() {
	int loop;
	double average;
	string letterGrade;
	double att = 0, lab = 0, hw = 0, q = 0, gw = 0, mid = 0, fin = 0;
	ifstream inFile; inFile.open("Text.txt");
	inFile >> loop;
	

	while (!inFile.eof()) {
		
		while (loop != 0) {
			inFile >> att >> lab >> hw >> q >> gw >> mid >> fin;
			
			average = (att * .10) + (lab * .15) + (hw * .15) + (q * .15) + (gw * .05) + (mid * .20) + (fin * .20);
			
			cout << "average= " << average << "    ";
			loop = loop - 1;
			
			cout << "lettergrade= " << calculateLetterGrade(average) << endl;

		}
		inFile.close();
		
	}
}