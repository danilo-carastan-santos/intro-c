#include <stdio.h>
#include <stdlib.h>
  
int main()
{
   //this str variable is just a buffer, to store the values read from a file
   char str[1000];
   //In a C program, a file is represented by a pointer, whose type is 
   //of a special one, the FILE type.
   //This variables is often called as file descriptor
   FILE *fptr_read, *fptr_write;

   //the name of the files to read and to write
   char fname_read[20]="test_read.txt";
   char fname_write[20]="test_write.txt";

   printf("Read a file (test_read.txt) and print the content :\n");
   printf("--------------------------------------------------------\n");

   //fopen is the function to access a file in C. the "r" says that 
   //the file is accessed only in read mode, no write will be allowed
   //more info about fopen: https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
   fptr_read=fopen(fname_read,"r");  
   if(fptr_read==NULL)
   {
      printf("Error in opening file!");
      exit(1);
   }

   //lets read just one character of the file
   char character = fgetc(fptr_read);
   printf("The first character of the file is the letter %c\n", character);

   //now lets read one line of the file, and store it in str
   //fgets will read the characters from the file until it reaches one 
   //of these conditions:
   //1 - it reaches a newline (\n) character
   //2 - it reaches a end-of-file (EOF) character
   //3 - it reaches the size of the str varible (sizeof str)
   fgets(str, sizeof str, fptr_read);
   printf("%s\n",str);

   //ok, it read the line but the first character "A" was not read
   //that's because the "A" was read already, we need to "rewind" the 
   //pinter to read the A again
   rewind(fptr_read);

   //now we should be able to read the whole line, with the "A"
   fgets(str, sizeof str, fptr_read);
   printf("%s\n",str);

   //finally, lets read the rest of the file
   while(fgets(str, sizeof str, fptr_read) != NULL){
      printf("%s",str);
   }

   //now since we are done with reading the file, we *need* to close it
   //this is impoortant!
   fclose(fptr_read);

   printf("\n\n Create a file (test.txt) and input text :\n");
	printf("----------------------------------------------\n");

   char str_write[1000];

   //the only difference here for fopen is the "w", which means that the 
   //program is allowed to write in the file
   fptr_write=fopen(fname_write,"w");	
   if(fptr_write==NULL)
   {
      printf("Error in opening file!");
      exit(1);
   }


   printf("Input a sentence for the file : Type something");

   //This is very interesting. Even the input of the terminal can be considered as a file
   //in the below fgets, we are capturing the content of a "file" wich is the terminal input
   //The variable of the terminal input "file" has a special name, called stdin
   fgets(str_write, sizeof str_write, stdin);

   //writing in a file is similar with the traditional printf. we just need to pass an aditional
   //argument, which is file descriptor (fptr_write) of the file 
   fprintf(fptr_write,"%s",str_write);

   //we need to close the file for writing as well
   //this is important!
   fclose(fptr_write);
   printf("The file %s created successfully. go check it :-)\n",fname_write);
   return 0;
}
