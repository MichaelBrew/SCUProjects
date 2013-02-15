/*
 * MICHAEL BREW - 01/16/13
 *
 * Analyzer opens up a file, then precedes to analyze it by finding the average word's length,
 * the first longest word, and the last shortest word. It then outputs the data to the screen.
 *
 * COEN 70 - Professor Vu - Homework 1
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*
 * Analyzer class has functions to open a text file, find average word length, first longest word, 
 * and last shortest word. Uses variables words, chars, and wordcount to store the text, hold 
 * the amount of alphanumeric characters, and hold the amount of words, respectively. 
 */
class Analyzer {
      private:
             string words;
             int chars;
             int wordcount;
      public:
             void input(char*);
             void average();
             void longest();
             void shortest();
};

//Input() opens a file that was passed in, then puts all the text in a string called words. 
void Analyzer::input(char* file) {
     fstream myfile;
     myfile.open(file);
     string tempw;

     while(!myfile.eof()) {
        getline(myfile, tempw);  //Gets current line of text from file and stores in tempw
        if(!tempw.empty()) {     //As long as that line isn't empty...
           tempw.append(" ");    //Adds a space so there is a separation between this line and the next one
           words.append(tempw);  //Adds the line to the string words, which evenutally holds every line 
        }
     }
     
     myfile.close();
}

//Average() counts how many alphanumeric characters and total words there are, then outputs the average length.
void Analyzer::average() {
     wordcount = 0;
     chars = 0;
     
     for(int i = 0; i < words.length(); i++) {    
        if(isalnum(words[i])) { //Counting the alphanumeric characters
           chars++;
        }
             
        else if(isspace(words[i]) && !(words[i-1] == '-')) { //Counting the words, excludes '-' as a word
           wordcount++;
        }
     }

     //This line outputs the average length with a precision of 2 decimal places
     cout << "The average word's length is "<< setprecision(3) << (double)chars/wordcount << endl;
}
     
//Longest() searches through the text and finds the first longest word
void Analyzer::longest() {
     int count = 0;
     int maxLength = 0;
     int location = 0;
     int temppunct = 0; //Temporary variable to hold number of punctuation marks in an individual word
     int punctcount = 0; //Holds the number of punctuation marks in the longest word
     string longword;
     string temp;
     
     /*
     * This for loop counts the letters in each word, and if that count is greater than what maxLength is, it assigns
     * its value to maxLength and resets count to 0. The location of the space following the longest word is stored in
     * the location variable. Punctcount is assigned the value of temppunct. 
     */
     for(int i = 0; i < words.length(); i++) {
        if(isalnum(words[i])) count++;
        else if(ispunct(words[i])) temppunct++;
        else if(isspace(words[i])) {
           if(count > maxLength) {
              maxLength = count;
              location = i;
              punctcount = temppunct;
           }
           count = 0;
           temppunct = 0;
        }
     }
     
     //This for loop assigns the longest word to the string longword.
     for(int j = 0; j < maxLength+punctcount; j++) { //looping for as many characters(including punctuation) that are in the longest word
        if(!ispunct(words[location-maxLength-punctcount+j])) { //As long as the current character isn't punctuation...
           temp = words[location-maxLength-punctcount+j]; //Store the character in temp
           longword.append(temp); //Append temp to longword, essentially building longword one character at a time
        }
     }
     
     cout << "The longest word is '" << longword << "'" << endl;
}

//Shortest() searches through the text and finds the last shortest word
void Analyzer::shortest()
{
     int count = 0;
     int minLength = 999; //Arbitrary large value for minLength so the smallest word in the text isn't longer than this
     int location = 0;
     int temppunct = 0; //Temporary variable to hold number of punctuation marks in an individual word
     int punctcount = 0; //Holds the number of punctuation marks in the longest word
     string shortword;
     string temp;

     /*
     * This for loop counts the letters in each word, and if that count is less than what minLength is, it assigns
     * its value to minLength and resets count to 0. The location of the space following the shortest word is stored in
     * the location variable. Punctcount is assigned the value of temppunct. 
     */
     for(int i = 0; i < words.length(); i++) {
        if(isalnum(words[i])) count++;
        else if(ispunct(words[i])) temppunct++;
        else if(isspace(words[i]) && !(words[i-1] == '-')) {
           if(count <= minLength) {
              minLength = count;
              location = i;
              punctcount = temppunct;
           }
           count = 0;
           temppunct = 0;
        }
     }
     
     //This for loop puts together the shortest word
     for(int j = 0; j < minLength+punctcount; j++) { //Loops for as many characters are in the shortest word
        if(!ispunct(words[location-minLength-punctcount+j])) { //As long as current character isn't punctuation...
           temp = words[location-minLength-punctcount+j]; //Put that character into temp
           shortword.append(temp); //Append temp to shortword to build the shortest word character by characater
        }
     }

     cout << "The shortest word is '" << shortword << "'" << endl;
}

//Main function that creates an Analyzer object, opens the Gettysburg Address, analyzes it, and outputs results on screen.
int main()
{
    Analyzer A;
    cout << "THE GETTYSBURG ADDRESS\n" << endl;
    A.input("GettysburgAddress.txt");
    A.average();
    A.longest();
    A.shortest();
    
    cout << "\n\n\nBLOOD TOILS TEARS AND SWEAT BY WINSTON CHURCHILL\n" << endl;
    Analyzer B;
    B.input("churchill.txt");
    B.average();
    B.longest();
    B.shortest();
    
    cout << "\n\n\nFAREWELL TO THE OLD GUARD BY NAPOLEON BONAPARTE\n" << endl;
    Analyzer C;
    C.input("napoleon.txt");
    C.average();
    C.longest();
    C.shortest();
    
    
    cin.get();
    return 0;
}
