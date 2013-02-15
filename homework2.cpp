/*
 * Michael Brew
 * 01/23/13
 *
 * COEN 70 - Professor Vu
 */

#include <iostream>
#include <cstdio>

using namespace std;

/*
 * StudentRecord provides constructors, destructors, operator overload functions
 * accessors, and mutators. Private variables for first name, last name, ID, GPA,
 * enrollment, and number enrolled.
 */
class StudentRecord {
      public:
             // constructors
             StudentRecord();
             StudentRecord(string, string, int, float, string*, int);
             // destructor
             ~StudentRecord();
             // copy constructor
             StudentRecord(const StudentRecord&);
             // assignment operator
             const StudentRecord& operator=(const StudentRecord&);
             // input/output operators
             friend ostream& operator<<(ostream&, const StudentRecord&);
             friend istream& operator>>(istream&, StudentRecord&);
             // accessors
             string getFirstName();
             string getLastName();
             int getID();
             float getGPA();
             string* getEnrollment();
             int getNumEnroll();
             // mutators
             void setFirstName(string);
             void setLastName(string);
             void setID(int);
             void setGPA(float);
             void setEnrollment(string*);
             void setNumEnroll(int);
      
      private:
              string _firstName;
              string _lastName;
              int _id;
              float _gpa;
              string* _enrollment;
              int _numEnroll;
};

//Default constructors populating variables
StudentRecord::StudentRecord() {
      _firstName = "No name";
      _lastName = "No name";
      _id = -1;
      _gpa = 0;
      _enrollment = NULL;
      _numEnroll = -1;
}

//Constructor taking in parameters for first name, last name, ID, GPA, enrollment, and number enrolled
StudentRecord::StudentRecord(string firstName, string lastName, int id, float gpa, string* enrollment, int numEnroll) {
      _firstName = firstName;
      _lastName = lastName;
      _id = id;
      _gpa = gpa;
      _enrollment = enrollment;
      _numEnroll = numEnroll;
}

//Destructor, frees enrollment pointer
StudentRecord::~StudentRecord() {
      free (_enrollment);
}

//Copy constructor that just calls the assignment operator
StudentRecord::StudentRecord(const StudentRecord& other) {
      *this = other;
}

//Assignment operator that equates one StudentRecord object to another, returning a StudentRecord reference
const StudentRecord& StudentRecord::operator=(const StudentRecord& other) {
      //If object passed in is this object, just return this
      if(this == &other)
              return *this;
              
      //Assign variables from object passed in to this object's variables and return this
      _firstName = other._firstName;
      _lastName = other._lastName;
      _id = other._id;
      _gpa = other._gpa;
      _enrollment = other._enrollment;
      _numEnroll = other._numEnroll;
      return *this;
}

//Overloading << operator to print out each variable of a StudentRecord on a new line, returning ostream reference
ostream& operator<<(ostream& out_str, StudentRecord& other) {
      out_str << "First name: " << other.getFirstName() << endl << "Last name: " << other.getLastName() << endl << "ID: " << other.getID() << endl << "GPA: " << other.getGPA() << endl << "Enrollment: " << other.getEnrollment() << endl << "Number enrolled: " << other.getNumEnroll() << endl;
      return out_str;
}

//Overloading >> operator to take in each variable of a StudentRecord separated by a space, returning istream reference
istream& operator>>(istream& in_str, StudentRecord& other) {
      in_str >> other._firstName >> other._lastName >> other._id >> other._gpa >> *(other._enrollment) >> other._numEnroll;
      return in_str;
}

//Accessor, returns first name of student
string StudentRecord::getFirstName() {
       return _firstName;
}

//Accessor, returns last name of student
string StudentRecord::getLastName() {
       return _lastName;
}

//Accessor, returns student ID
int StudentRecord::getID() {
    return _id;
}

//Accessor, returns GPA
float StudentRecord::getGPA() {
      return _gpa;
}

//Accessor, returns enrollment
string* StudentRecord::getEnrollment() {
        return _enrollment;
}

//Accessor, returns number enrolled
int StudentRecord::getNumEnroll() {
    return _numEnroll;
}

//Mutator, _firstName variable set to name passed in
void StudentRecord::setFirstName(string name) {
     _firstName = name;
}

//Mutator, _lastName variable set to name passed in
void StudentRecord::setLastName(string name) {
     _lastName = name;
}

//Mutator, _id variable set to ID passed in
void StudentRecord::setID(int newid) {
     _id = newid;
}

//Mutator, _gpa variable set to GPA passed in
void StudentRecord::setGPA(float gpa) {
     _gpa = gpa;
}

//Mutator, _enrollment variable set to enrollment passed in
void StudentRecord::setEnrollment(string* enrollment) {
     _enrollment = enrollment;
}

//Mutator, _numEnroll set to number enrolled passed in
void StudentRecord::setNumEnroll(int numenroll) {
     _numEnroll = numenroll;
}

//Main() demos the classes constructors, destructors, and functions
int main() {
    //Using default constructor
    StudentRecord A;
    cout << "Student A Record\n" << endl << A << endl;
    //Using constructor with parameters
    StudentRecord B = StudentRecord("Michael", "Brew", 870197, 3.3, NULL, 5);
    cout << "\n\nStudent B Record\n" << endl << B << endl;
    //Using destructor
    A.~StudentRecord();
    StudentRecord C;
    //Using assignment operator
    C = B;
    //Using accessors
    cout << "\n\nStudent C Record\n" << endl << C << endl;
    cout << "Student B's first name is " << B.getFirstName() << endl;
    cout << "Student B's last name is " << B.getLastName() << endl;
    cout << "Student B's ID is " << B.getID() << endl;
    cout << "Student B's GPA is " << B.getGPA() << endl;
    cout << "Student B's enrollment is " << B.getEnrollment() << endl;
    cout << "Student B's number enrolled is " << B.getNumEnroll() << endl;
    //Using mutator
    B.setFirstName("Ryan");
    cout << "Student B's first name is now " << B.getFirstName() << endl;   
    return 0;
}
