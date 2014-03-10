/*
 * MICHAEL BREW
 * Homework 4
 * COEN 70 - Professor Vu
 * 02/06/13
 */

#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

/*
 * Queue is a singuarly linked list of nodes that adds to the end
 * and removes from the start. Class includes constructors,
 * destructors, operator functions, functions to add and remove, 
 * as well as the node class.
 */
class Queue{
private:
    class node {
	public: 
		node* next;
		double data;
		node(node* = NULL, const double = 0.0);
	};
	node* head;
	node* tail;
	int size;
public:
    Queue();
    Queue(const Queue&);
	~Queue();
	void clear();
	Queue& operator=(const Queue&);
	friend ostream& operator<<(ostream&, const Queue&);
	friend istream& operator>>(istream&, Queue&);
	void enqueue(double);
	double dequeue();
};

//Queue default constructor
Queue::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

//Queue copy constructor
Queue::Queue(const Queue& other) {
    head = NULL;
    tail = NULL;
    size = 0;
    *this = other;
}

//Queue destructor
Queue::~Queue() {
    clear();
}

//Clears the queue by deleting each node
void Queue::clear() {
    node* temp = head;
    while(size > 0) {
        node* temp2 = temp->next;
        delete temp;
        temp = temp2;
        size--;
    }
}

/*
 * Assignment operator that clears the queue, then goes
 * through each node in the other queue, copying the data
 * and pointer from each node into the empty queue.
 */
Queue& Queue::operator=(const Queue& other) {
    //Check for self assignment
    if(this == &other) return *this;
    clear();
    node* t1 = other.head;
    while(t1 != NULL) {
        node* t2 = new node(NULL, t1->data);
        if(size == 0) {
            head = t2;
        } else {
            tail->next = t2;
        }
        size++;
        tail = t2;
        t1 = t1->next;
    }
}

//Node constructor
Queue::node::node(node* _next, double _data) {
    next = _next;
    data = _data;
}

//Output operator, displays each number from the queue on a new line
ostream& operator<<(ostream& out_str, const Queue& rhs) {
    Queue::node* temp = rhs.head;
    while(temp != NULL) {
        out_str << temp->data << endl;
        temp = temp->next;
    }
    return out_str;
}

//Input operator, enqueues a list of numbers from the user to a queue
istream& operator>>(istream& in_str, Queue& rhs) {
    string input;
    string temp;
    //Store user input in string called input
    getline(cin, input);
	for(int i = 0; i < input.length(); i++) {
        //If the current character is part of a number, or at the very end
        if(isalnum(input[i]) || (i == input.length()-1) || input[i] == '.') {
            stringstream ss;
	        string temp2 = "";
	        ss << input[i];
	        ss >> temp2;
	        temp.append(temp2);
        }
        //If the current character is a space or the last character in the input
        if((isspace(input[i])) || (i == input.length()-1)) {
            const char* c = temp.c_str();
            //Add number to queue then clear temp
            rhs.enqueue(atof(c));
            temp.clear();
        }
    }
	return in_str;
}

//Enqueue adds a number to the end of the queue
void Queue::enqueue(double num) {
    node* temp = new node(NULL, num);
    if(size != 0) {
        tail->next = temp;
    } else {
        //If the queue is empty, the new node becomes the head
        head = temp;
    }
    tail = temp;
    size++;
}

//Dequeue removes the last node from the queue and returns its data
double Queue::dequeue() {
    node* temp = head;
    head = temp->next;
    size--;
    return temp->data;
}

//Main function to test functionality, including constructors, 
//output and input operators, enqueue() and dequeue()
int main() {
    Queue A;
    cout << "Enter numbers: ";
    cin >> A;
    cout << A << endl;
    cout << "This item was removed: " << A.dequeue() << endl;
    cout << A << "\n" << endl;
    A.clear();

	Queue B;
	B.enqueue(45);
	B.enqueue(467);
	B.enqueue(53);
	B.enqueue(43);
	B.enqueue(542);
	B.enqueue(54235);
	B.enqueue(63);
	cout << "This is B: \n" << B << endl;
	cout << "This number was removed: " << B.dequeue() << endl;
	cout << "\nThis is B now: \n" << B << endl;
	
	A = B;
	cout << "A is now equal to B: \n" << A << endl;
	
	Queue C(A);
	cout << "New queue C is equal to A and B: \n" << C << endl;
    return 0;
}
    
