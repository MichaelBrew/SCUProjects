/*
 * Michael Brew
 * COEN 177 Lab
 * Lab 1
 *
 * shell.c is a simple shell you can run in the terminal and can run terminal commands with no parameters. To exit, just type exit and press enter.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH 50 //Max length of the command enetered by user

int main (int argc, char *argv[])
{
  char line_input[MAX_LENGTH];
  int status;
  
  while(1)
  {
    char *arguments[200];
    char *cmd;
    pid_t ChildPID;
    
    //Print My Shell, and if there's an error getting input, break
    printf("\n[My Shell]$ ");
    if(!fgets(line_input, MAX_LENGTH, stdin)) break;
    
    //Use strtok to store the command ended by a return into cmd
    cmd = strtok(line_input, " \n");

    //Fork the process
    ChildPID = fork();
    
    //If command is exit, then exit shell
    if(strcmp(cmd, "exit") == 0)
    {
      exit(EXIT_SUCCESS);
    }
      
    //Else if fork() was successful
    else if(ChildPID >= 0)
    {
      //If this is the child process, execute command
      if(ChildPID == 0)
      {
          execvp(cmd, argv);
      }
      //Else if this is the parent process, wait on child process
      else {
          waitpid(-1, &status, 0);
      }
    }
  }
  
  printf("\n");
  return 0;
}
    
    