#include <stdio.h>
void main(void)
{
    int x = 0; //2 variables x and y
    int y = 0;
    int i = 0;
    
    FILE *fp = NULL; //streams the file that we want to write to, the output data of programme
    FILE *gnupipe = NULL; //stream for pipe
    char *GnuCommands [] = {"set title 'Graph'", "plot 'data.tmp'"}; //commands to send to pipe
    
    fp = fopen ("data.tmp", "w");   //w: if file doesnt exist, it creates new file; if already exists, it deletes old file and creates new file.
    
    gnupipe = _popen("gnuplot -persistent", "w");  //Opens pipe that we gonna send commands to;  - persistent: gnuplot window stays open after all C program has finished, so we can take a look at our data.
    
    while (i < 100)   //loop to enable printing of data to data.tmp file
    {
        fprintf(fp, "%d %d\n", x, y);
        
        x = x + 1;
        y = y + 1;
        i = i + 1;
    }
    i = 0;
    while (i < 2)
    {
        fprintf(gnupipe, "%s\n", GnuCommands[1]); //Only have 2 commands that we have defined before. Sending commands to our pipe.
        i = i + 1;
    }
    
}
