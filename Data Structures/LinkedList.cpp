//
//  Michael Brew
//  Homework 3
//  01/30/13
//  COEN 70 - Professor Vu
//

#include <iostream>
#include <cstdio>

using namespace std;

/*
 * List is an ADT that consists of nodes which each hold an int value
 * and a pointer to the next node in the list. The class declaration
 * has constructors, a destructor, operator functions, an insert fucntion,
 * remove function, replace, clear, isEmpty, go to first, go to last,
 *go to next, go to previous, get current, as well as the node class.
 */
class List {
    public:
        List();
        ~List();
        List(const List&);
        const List& operator=(const List&);
        friend ostream& operator<<(ostream&, const List&);
        void insert(const int&);
        void remove();
        void replace(const int& item);
        void clear();
        bool isEmpty();
        void goToFirst();
        void goToLast();
        void goToNext();
        void goToPrevious();
        int getCurrent();
        
    private:
        class node{
            public:
                node(const int& data = 0, node* next = NULL);
                int data;
                node* next;
        };
        node* list;
        int size;
        node* cursor;
};

/*
 * Node class constructor taking parameters for the data value
 * and the pointer to the next node.
 */
List::node::node(const int& _data, node* _next) {
    data = _data;
    next = _next;
}

/*
 * Default List constructor that sets size to 0 and pointers to null.
 */
List::List() {
    size = 0;
    list = NULL;
    cursor = NULL;
}

//Destructor
List::~List() {
    //do nothing
}

/*
 * Copy constructor that takes in a List reference and calls the assignment
 * operator.
 */
List::List(const List& other) {
    size = 0;
    list = NULL;
    cursor = NULL;
    *this = other;
}

/*
 * Assignment operator that takes in a List reference and returns a List
 * reference.
 */
const List& List::operator=(const List& other) {
    if(this == &other) {
        cout << "You're assigning the same List to itself" << endl;
        return *this;
    }
    
    else if(other.size == 0) {
        cout << "Assigning an empty list" << endl;
        size = 0;
        list = NULL;
        cursor = NULL;
        return *this;
    }
    
    else {
        //If current list is populated, empty it
        if(size != 0) {
            node* temp;
            while(size != 0) {
                temp = list->next;
                list->next = NULL;
                list = temp;
                size--;
            }
            cursor = NULL;
            list = NULL;
        }
         
        //Now create new list node with data from other list node 
        list = new node(other.list->data, NULL);  
        size++;
        cursor = list;        
        node* temp = other.list;
        node* tempcurs;
       
        //Go through the list and copy each node and its data to our list
        for(int i = 1; i < other.size; i++) {
            cursor->next = new node(temp->next->data, NULL);           
            cursor = cursor->next;
            temp = temp->next;
            if(temp == other.cursor) {
                tempcurs = cursor;
            }
            size++;
        }

        //Set cursor to where cursor on other list was positioned
        cursor = tempcurs;
        return *this;
    }
}    

/*
 * Output operator that outputs the values of the nodes of the List
 * passed in with a space separating each number. Uses temporary
 * node pointer to traverse the list.
 */
ostream& operator<<(ostream& out_str, const List& other) {
    List::node* temp = other.list;
    for(int i = 0; i < other.size; i++) {
        out_str << temp->data << " ";
        temp = temp->next;
    }
    return out_str;
}

/*
 * Insert() creates a new node with the data supplied
 * in the parameters. Put that node in the list after
 * the cursor, then set the cursor to that node.
 */
void List::insert(const int& num) {
    if(size != 0) {
        node* tmp = list;
        while(tmp != cursor) {
            tmp = tmp->next;
        }
        node* temp2 = cursor->next;
        cursor->next = new node(num, temp2);
        cursor = cursor->next;
    }
    
    //If list was empty
    else {
        cursor = new node(num, NULL);
        list = cursor;
    }
    
    size++;
}

/*
 * Removes the node where the cursor is currently pointing, then
 * moves cursor to the node before it.
 */
void List::remove() {
    if(size != 0) { 
        node* temp = list;
        while(temp->next != cursor) {
            temp = temp->next;
        }
        temp->next = cursor->next;
        cursor->next = NULL;
        cursor = temp;
        size--;
    }
}

//Replaces the data of the current node with the int passed in.
void List::replace(const int& item) {
    if(cursor != NULL)
        cursor->data = item;
}

//Completey clears the list and deletes all pointers
void List::clear() {
    if(size != 0) {
        node* temp = list;
        while(size != 0) {
            node* temp2 = temp->next;
            delete temp->next;
            temp = temp2;
            size--;
        }
        cursor = NULL;
        list = NULL;
    }
}

//Returns true is there are no nodes in the list, false otherwise
bool List::isEmpty() {
    if(size == 0) return true;
    return false;
}

//Places the cursor on the very first item of the list.
void List::goToFirst() {
    cursor = list;
}

//Places thte cursor at the very end of the list
void List::goToLast() {
    while(cursor->next != NULL)
        cursor = cursor->next;
}

//Places the cursor on the node in line
void List::goToNext() {
    if(cursor->next != NULL)
        cursor = cursor->next;
}

//Places the cursor on the previous node in line
void List::goToPrevious() {
    node* temp = list;
    while(temp->next != cursor)
        temp = temp->next;
    cursor = temp;
}

//Returns the data of the current node
int List::getCurrent() {
    if(cursor != NULL)
        return cursor->data;
    cout << "There are no items in list" << endl;
    return -1;
}

//Main function to test all other functions
int main() {
    List A, B;
    cout << "List A: " << A << endl;
    A.insert(5);
    A.insert(2);
    A.insert(9);
    cout << "List A: " << A << endl;
    A.insert(10);
    cout << "List A: " << A << endl;
    B = A;
    List C = List(B);
    List D;
    D.insert(2);
    D.insert(3);
    D = C;
    cout << "List B: " << B << endl << "List C: " << C << endl << "List D: " << D << endl;
    A.remove();    
    cout << A << endl;
    A.replace(92324);
    cout << A << endl;
    A.clear();
    cout << "This is A: " << A << endl;
    if(A.isEmpty()) {
        cout << "A is empty" << endl;
    } else {
        cout << "A is not empty" << endl;
    }
    return 0;
}
                 
