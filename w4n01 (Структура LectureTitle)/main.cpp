#include <iostream>
#include <string>
using namespace std;

struct Specialization{
    explicit Specialization(const string& new_data){
        data = new_data;
    }
    string data;
};

struct Course{
    explicit Course(const string& new_data){
        data = new_data;
    }
    string data;
};

struct Week{
    explicit Week(const string& new_data){
        data = new_data;
    }
    string data;
};

struct LectureTitle {
    LectureTitle(const Specialization& new_specialization,
		 const Course& new_course,
		 const Week& new_week){
        specialization = new_specialization.data;
        course = new_course.data;
        week = new_week.data;
    }
    string specialization;
    string course;
    string week;
};


int main(){
LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
cout << title.specialization << endl;
cout << title.course << endl;
cout << title.week << endl;
    return 0;
}
