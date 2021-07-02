#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)
{
   int fd, fd1;
   int terminal_write;
   int terminal_read;
   int maxlen=256;
   char terminal_ip[maxlen];
   char buf1[maxlen];
   char read_file_buf;

   int char_count=0;
   int line_count= 0;
   int word_count=0;

   //write to terminal
   char terminal_message[] = "Enter name of source file :\n"  ;
   int len = strlen(terminal_message);

   terminal_write= write (1, terminal_message, len );
   
   terminal_read = read(0, terminal_ip , maxlen);
   

   fd=open (terminal_ip, O_RDONLY);

   int onebit =1;

   int fread =read(fd, read_file_buf, onebit );
   if(fread<0)
	{
		perror("read");
		exit(2);
	}
   
   int nbytes_2;
   
   while (fread!=0)
   { // this will loop input till EOF character not reached
   char_count++;
   if (read_file_buf==' '||read_file_buf== '\t'|| read_file_buf=="\n")
   {
       word_count++;
      if (read_file_buf='\n')
      line_count++;
   }

   fread= read (fd, read_file_buf, onebit);
   if(fread<0)
	{
		perror("read");
		exit(2);
	}
   }
// write code to ouput counters to terminal, and clean up variables and debug 
close(fd);
close(fd1);

return 0;

