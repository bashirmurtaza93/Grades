#include<iostream>
#include<string>
#include<algorithm>
#include<ios>
#include<vector>
#include<iomanip>

using std::cout;		using std::sort;
using std::cin;			using std::streamsize;
using std::endl;		using std::string;
using std::string;		using std::vector;
using std::setprecision;
int main() {

// ask for and read the student's name
	cout << "Please enter your last name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

// ask for and read the midterm and final grades

	cout << "Please enter your mideterm and final exam grades : ";
	double midterm, final;
	cin >> midterm >> final;

// ask fot and read the homework grades

	cout << "Enter all your homework grades , "
		"followed by ebd-of-file: ";

	vector<double> homework;
	double x;
// invataint: homework contains all the homework grades read so far

	while (cin >> x)
		homework.push_back(x); // + 1 to the vector
// check that the student entered some homework grades.

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades"
			"Please try again." << endl;
		return 1;
	}

//sort the grades
	sort(homework.begin(), homework.end());

// compute the median homework grade
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
						   : homework[mid];
// compute the write the final grade
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;

}
