#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define LAMBDA 1000
#define INFINITY 99999999

double expRand(double x);

int main() {
    
    srand(0);
    int numOfRandVar = 500000;
    double rvArray[numOfRandVar];
    double rv;
    double sumForMean = 0;
    
    //Populate array with random variables
    int i;
    for(i = 0; i < numOfRandVar; i++) {
        rv = expRand((double)random()/RAND_MAX);
        sumForMean += rv;
        rvArray[i] = rv;
    }
    
    //Calculate mean
    double mean = sumForMean/((double)numOfRandVar);
    
    //Calculate variance
    double sumForVariance = 0;
    for(i = 0; i < numOfRandVar; i++) {
        sumForVariance += pow((rvArray[i] - mean), 2);
    }
    double variance = sumForVariance / (double)numOfRandVar;
    
    
    /********************************
     *   Create and run simulator   *
     ********************************/
    
    double L = 1500; //Length of packet in bits
    double C = 1000000; //Rate server processes in bits/second
    
    double t_total = 100; //Want simulator to run for 5000 seconds
    double t_current = 0;
    double t_event = 0;
    double t_arrival = 0; //first packet arrives at 0s
    double t_delay = 0;
    double t_delaySum = 0;
    double t_departure = INFINITY; //Means the queue is empty and the server is idle
    double queue_length = 0; //Queue length is 0 at start
    double queueLengthSum = 0;
    double t_idle = 0;
    double t_start_idle = 0;
    i = 0;
    
    int arrival_counter = 0;
    int depart_counter = 0;
    
    int k = 50;
    int packetLossCount = 0;
    
    while(t_current < t_total)
    {
        t_current = fmin(t_arrival, t_departure);
        t_event = t_current;
        
        if(t_event == t_arrival) {
            
            if(queue_length == k) {
                packetLossCount++;
            } else {
                
                t_delay = (queue_length + 1)*(L/C);
                t_delaySum += t_delay;
                
                //If server is idle
                if(t_departure == INFINITY) {
                    t_idle += (t_current - t_start_idle);
                    t_departure = t_current + t_delay; //Departure is just service time of 1 packet
                }
                else {
                    queue_length++; //Packet added to queue
                }
            }
            
            t_arrival = t_current + rvArray[i]; //Use values from array to update next arrival time
            i++; //Move to next arrival time in array
            
            arrival_counter++;
        }
        else if(t_event == t_departure) {
            
            //If departing packet was only packet in system
            if(queue_length == 0) {
                t_departure = INFINITY;
                t_start_idle = t_current;
            }
            else {
                queue_length--; //decrement queue length
                t_departure += L/C; //Next departure time is time of packet spent in server
            }
            
            depart_counter++;
        }
        
        queueLengthSum += queue_length;
    }
    
    double t_averageDelay = t_delaySum/(double)(arrival_counter);
    double avgQueueLength = queueLengthSum/((double)(arrival_counter + depart_counter));
    printf("The packet loss percentage was %f\n", (((double)packetLossCount)/((double)arrival_counter))*100);
    printf("The average queue length was %f\n", avgQueueLength);
    printf("The average sojourn time was %f\n", t_averageDelay);
    printf("Server was idle for %f seconds, so %f percent\n", t_idle, (t_idle/t_total)*100);
    printf("Total of %i arrivals, %i departures\n", arrival_counter, depart_counter);
    
    return 0;
}

double expRand(double x) {
    return ((double)(-1.0/LAMBDA))*(log(1-x));
}