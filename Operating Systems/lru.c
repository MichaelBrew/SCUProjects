#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct pageInCache {
    int pageNumber;
    int timeInCache;
} page;

int isInArray(int toFind, page *array[], int arrayLength);
void incrementTimes(page *array[], int arrayLength);
int findOldestPage(page *array[], int arrayLength);
void cleanUp(page *array[], int arrayLength);

int main(int argc , char *argv[])
{
    char str[60];
    int pagesToGet[1024];
    int totalPagesRequested = 0;
    char *cacheSizeString = argv[1];
    int cacheSize = atoi(cacheSizeString);
    page *cache[cacheSize];
    int itemsInCache = 0;
    
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
    
    ///////////////////////////
    // IMPLEMENTATION OF LRU //
    ///////////////////////////
    
    int i;
    int pageFaultCount = 0;
    for(i = 0; i < totalPagesRequested; i++) {
        int positionInCache = isInArray(pagesToGet[i], cache, itemsInCache);
        
        //If the page already exists in cache, continue
        if(positionInCache != -1) {
            cache[positionInCache]->timeInCache = 0;
        }
        else {
            printf("Page fault for page %d\n", pagesToGet[i]);
            pageFaultCount++;
            
            //If there is still empty space in cache, insert page
            if(itemsInCache < cacheSize) {
                page *currentPage = (page *)malloc(sizeof(page));
                cache[itemsInCache] = currentPage;
                cache[itemsInCache]->pageNumber = pagesToGet[i];
                cache[itemsInCache]->timeInCache = 0;
                itemsInCache++;
            }
            
            //We're going to have to remove an old page
            else {
                int indexOfRemoval = findOldestPage(cache, itemsInCache);
                cache[indexOfRemoval]->pageNumber = pagesToGet[i];
                cache[indexOfRemoval]->timeInCache = 0;
            }
        }
        
        incrementTimes(cache, itemsInCache);
    }
    
    printf("Total of %d page requests, total of %d page faults\n", totalPagesRequested, pageFaultCount);
    cleanUp(cache, itemsInCache);
    
    return 0;
}

int isInArray(int toFind, page *array[], int arrayLength)
{
    int i;
    for(i = 0; i < arrayLength; i++) {
        if(array[i]->pageNumber == toFind) return i;
    }
    return -1;
}

void incrementTimes(page *array[], int arrayLength)
{
    int i;
    for(i = 0; i < arrayLength; i++) {
        array[i]->timeInCache++;
    }
}

int findOldestPage(page *array[], int arrayLength)
{
    int oldestTime = -1;
    int i;
    int indexOfOldest = -1;
    for(i = 0; i < arrayLength; i++) {
        if(array[i]->timeInCache > oldestTime) {
            oldestTime = array[i]->timeInCache;
            indexOfOldest = i;
        }
    }
    return indexOfOldest;
}

void cleanUp(page *array[], int arrayLength) {
    int i;
    for(i = 0; i < arrayLength; i++) {
        free(array[i]);
    }
}

