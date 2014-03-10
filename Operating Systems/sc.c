#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct pageInCache {
    int pageNumber;
    int reference;
    struct pageInCache *next;
    struct pageInCache *prev;
} page;

bool findPageInQueue(int lookingForPage, int sizeOfList);
bool addPageToList(int toAdd, int sizeOfList, int cacheSize);

page *head;
page *tail;

int main(int argc , char *argv[])
{
    char str[60];
    int pagesToGet[1024];
    int totalPagesRequested = 0;
    char *cacheSizeString = argv[1];
    int cacheSize = atoi(cacheSizeString);
    
    //Get a line from stdin
    while(fgets(str, 60, stdin) != NULL)
    {
        //If the line doesn't start with a number, go to next line
        if(!isdigit(str[0])) continue;
        else {
            int i = 0;
            char currentPage[10];
            
            //Get the number at the beginning of line and put into currentPage
            while(isdigit(str[i])) {
                currentPage[i] = str[i];
                i++;
            }
            
            //After the last digit of the page number we're getting, put a \0
            currentPage[i] = '\0';
            
            //Convert currentPage to an int and add that page number to pagesToGet
            int pageNum = atoi(currentPage);
            pagesToGet[totalPagesRequested] = pageNum;
            totalPagesRequested++;
        }
    }
    
    ///////////////////////////////////
    // IMPLEMENTION OF SECOND CHANCE //
    ///////////////////////////////////
    
    int pageFaultCount = 0;
    int sizeOfList = 0;
    
    head = NULL;
    tail = NULL;
    
    //Process each page request from pagesToGet[]
    int i;
    for(i = 0; i < totalPagesRequested; i++)
    {
        bool foundPage = findPageInQueue(pagesToGet[i], sizeOfList);
        
        //If the page already exists in cache
        if(foundPage) {
            //No fault
        }
        else {
            printf("Page fault for page %d\n", pagesToGet[i]);
            pageFaultCount++;
            
            bool added = addPageToList(pagesToGet[i], sizeOfList, cacheSize);
            if(added) sizeOfList++;
        }
    }
    
    printf("Total of %d page requests, total of %d page faults\n", totalPagesRequested, pageFaultCount);
    
    return 0;
}

bool findPageInQueue(int lookingForPage, int sizeOfList)
{
    //If the list is empty, return false
    if(sizeOfList == 0) {
        printf("List size was 0 so returning false for found\n");
        return false;
    }
    
    //Else, traverse through list and look for page number
    page *iterator = head;
    int i;
    
    for(i = 0; i < sizeOfList; i++) {
        //If we found it, update its reference bit and return true
        if(iterator->pageNumber == lookingForPage) {
            iterator->reference = 1;
            return true;
        }
        
        iterator = iterator->next;
    }
    
    //If loop finished without finding it, return false
    return false;
}

bool addPageToList(int toAdd, int sizeOfList, int cacheSize)
{
    if(sizeOfList < cacheSize) {
        page *currentToAdd = (page *)malloc(sizeof(page));
        currentToAdd->pageNumber = toAdd;
        currentToAdd->reference = 1;
        
        //If the list is currently empty, add toAdd as head and tail, and return
        if(sizeOfList == 0) {
            head = currentToAdd;
            tail = currentToAdd;
            
            currentToAdd->next = currentToAdd;
            currentToAdd->prev = currentToAdd;
        }
        //Else if there's only 1 page in list, add toAdd as tail and return
        else if(sizeOfList == 1) {
            head->next = currentToAdd;
            head->prev = currentToAdd;
            
            currentToAdd->next = head;
            currentToAdd->prev = head;
            
            tail = currentToAdd;
        }
        
        //If there's still room in the list, just add toAdd as tail and return
        else {
            tail->next = currentToAdd;
            
            page *currTail = tail;
            tail = currentToAdd;
            
            currentToAdd->prev = currTail;
            head->prev = currentToAdd;
            currentToAdd->next = head;
        }
        
        return true;
    }
    
    //Else we'll have to find a page currently in the list to remove
    page *iterator = head;
    int i;
    
    for(i = 0; i <= sizeOfList; i++) {
        //If current page reference's bit is 1, decrement it and put it at back of list
        if(iterator->reference == 1) {
            iterator->reference = 0;
            head = iterator->next;
            tail = iterator;
            
            iterator = iterator->next;
        }
        //Else if we've come across a page without its reference bit set, replace it's page number and reset ref bit
        else {
            head = head->next;
            tail = tail->next;
            tail->pageNumber = toAdd;
            tail->reference = 1;
            
            return false;
        }
    }
    
    return false;
}



