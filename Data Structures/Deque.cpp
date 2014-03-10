/*
 * MICHAEL BREW - Homework 5
 * 02/13/13
 * COEN 70 - Professor Vu
 */

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

template<typename T>
class Deque;

template<typename T>
ostream& operator<<(ostream&, const Deque<T>&);

template<typename T>
istream& operator>>(istream&, Deque<T>&);


/*
 * Deque is a template class that acts like a queue but it can
 * add and remove data from the front and back. It uses the node
 * class and has 8 functions besides the basic ones.
 */
template<typename T>
class Deque {
private:
    class node{
        public:
            node* next;
	        T data;
     	    node(node* = NULL, const T& = T());
    };
    node* head;
    node* tail;
    int dsize;
    
public:
    Deque();
    ~Deque();
    Deque(const Deque&);
    const Deque& operator=(const Deque&);
    friend ostream& operator<<<>(ostream&, const Deque<T>&);
    friend istream& operator>><>(istream&, Deque<T>&);
    void clear();
    void push_front(T);
    void push_back(T);
    void pop_front();
    void pop_back();
    T front();
    T back();
    int size();
    bool isEmpty();
};

//Node constructor
template<typename T>
Deque<T>::node::node(node* _next, const T& _data) {
    next = _next;
    data = _data;
}

//Deque constructor
template<typename T>
Deque<T>::Deque() {
    head = NULL;
    tail = NULL;
    dsize = 0;
}

//Destructor
template<typename T>
Deque<T>::~Deque() {
    clear();
}

//Copy constructor
template<typename T>
Deque<T>::Deque(const Deque<T>& other) {
    head = NULL; 
    tail = NULL;
    dsize = 0;
    *this = other;
}

/*
 * Assignment operator traverses through the deque passed in, and 
 * accordingly copies over each node's data to a new node and puts
 * that in our deque.
 */
template<typename T>
const Deque<T>& Deque<T>::operator=(const Deque<T>& other) {
    //Check for self assignment
    if(this == &other) return *this;
    clear();
    head = NULL;
    tail = NULL;
    dsize = 0;
    node* t1 = other.head;
    while(t1 != NULL) {
        node* t2 = new node(NULL, t1->data);
        if(dsize == 0) {
            head = t2;
        } else {
            tail->next = t2;
        }
        dsize++;
        tail = t2;
        t1 = t1->next;
    }
}

//Output operator that prints out the data of each node starting from the front of the deque
template<typename T>
ostream& operator<<(ostream& out_str, const Deque<T>& rhs) {
    typename Deque<T>::node* temp = rhs.head;
    while(temp != NULL) {
        out_str << temp->data << " ";
        temp = temp->next;
    }
    return out_str;
}

//Input operator that allows users to enter data into a deque, but only ints
template<typename T>
istream& operator>>(istream& in_str, Deque<T>& rhs) {
    cout << "Please enter integers separated by a space then press enter" << endl;
    string input;
    string temp;
    //Store user input in string called input
    getline(cin, input);
	for(int i = 0; i < input.length(); i++) {
        //If the current character is part of a number, or at the very end
        if(isalnum(input[i]) || (i == input.length()-1)) {
            stringstream ss;
	        string temp2 = "";
	        ss << input[i];
	        ss >> temp2;
	        temp.append(temp2);
        }
        //If the current character is a space or the last character in the input
        if((isspace(input[i])) || (i == input.length()-1)) {
            //Add number to queue then clear temp
            rhs.push_front(atoi(temp.c_str()));
            temp.clear();
        }
    }
	return in_str;
}

//Clears the deque
template<typename T>
void Deque<T>::clear() {
    node* temp = head;
    while(dsize > 0) {
        node* temp2 = temp->next;
        delete temp;
        temp = temp2;
        dsize--;
    }
}

//Pushes the data passed in to the front of the deque
template<typename T>
void Deque<T>::push_front(T num) {
    node* temp = new node(NULL, num);
    if(dsize == 0) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    dsize++;
}

//Pushes the data passed in to the back of the deque
template<typename T>
void Deque<T>::push_back(T num) {
    node* temp = new node(NULL, num);
    if(dsize == 0) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    dsize++;
}

//Removes the first item from the deque
template<typename T>
void Deque<T>::pop_front() {
    if(dsize == 0) return;
    node* temp = head;
    head = temp->next;
    dsize--;
}

//Removes the last item from the deque
template<typename T>
void Deque<T>::pop_back() {
    if(dsize == 0) return;
    node* temp = head;
    while(temp->next != tail) {
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;
    dsize--;
}

//Returns the data at the front of the deque
template<typename T>
T Deque<T>::front() {
    if(head != NULL)
        return head->data;
}

//Returns the data at the back of the deque
template<typename T>
T Deque<T>::back() {
    if(tail != NULL)
        return tail->data;
}

//Returns the size of the deque
template<typename T>
int Deque<T>::size() {
    return dsize;
}

//Returns true if the deque is empty, false otherwise
template<typename T>
bool Deque<T>::isEmpty() {
    if(dsize == 0) return true;
    return false;
}

//Main function to test functionality of deque class
int main() {
    Deque<int> A;
    A.push_front(3);
    A.push_front(6);
    cout << "Here is A with 2 items: " << A << endl;
    cout << "Now putting 8 at the back" << endl;
    A.push_back(8);
    cout << "Here is A now: " << A << endl;
    cout << "Popping the first number from A" << endl;
    A.pop_front();
    cout << "Now here's A: " << A << endl;
    cout << "Popping the last number from A" << endl;
    A.pop_back();
    cout << "Now here's A: " << A << endl;
    Deque<int> B(A);
    cout << "Created new deque B from A, here is B: " << B << endl;
    Deque<string> C;
    C.push_front("hello");
    C.push_back("world");
    cout << "C is a deque of strings, here's C: " << C << endl;
    cout << "The first item in C is " << C.front() << endl;
    cout << "The last item in C is " << C.back() << endl;
    cout << "The size of C is " << C.size() << endl;
    if(C.isEmpty()) cout << "C is an empty deque" << endl;
    else if(!C.isEmpty()) cout << "C is not empty" << endl;
    return 0;
 }
