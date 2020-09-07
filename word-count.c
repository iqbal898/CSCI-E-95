#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000

int main(int argc, char *argv[])
{
    if (argc < 2)
      {
//Program does not have file name
        printf("Insufficienet arguments. Filename is missing.");
        return 1;
       }

       FILE* fptr = NULL;
       int i, numberOfUniqueWords, isUnique;

    // List of distinct words
        char words[MAX_WORDS][50] = { 0 };
        char word[50] = { 0 };

     // Count of distinct words
      int  count[MAX_WORDS] = { 0 };

     // Try to open file 
      fptr = fopen(argv[1], "r");
     // Exit if file not opened successfully */
            if (fptr == NULL)
          {
             printf("Unable to open file.\n");
             printf("Please check you have read previleges.\n");

             exit(EXIT_FAILURE);
           }

         int lineCount = 0;
         numberOfUniqueWords = 0;
         char newLine[2] = "";

          //start reading the words from file
       int totalWords = 0;
       while (fscanf(fptr, "%48s%1[\n]", word, newLine) != EOF)
         {
 // Check if word exits in list of all distinct words
        
	isUnique = 1;
        for (i = 0; i < numberOfUniqueWords; i++)
        {
          if (strcmp(words[i], word) == 0)
           {
                isUnique = 0;
                break;
           }
                                                                                    }

// If word is unique then add it to distinct words list
// and increment index. Otherwise increment occurrence of 
// count of current word. 

 if (isUnique)
    {
     strcpy(words[numberOfUniqueWords], word);
     count[numberOfUniqueWords]++;

     numberOfUniqueWords++; // No of distict words

     }
   
     else
     {
       count[i]++;
     }

   if (strcmp(newLine, "\n") == 0)
  {
  lineCount++;
  newLine[0] = '\0'; //reset new line.
  }
   totalWords++;
 }

// Close file
 fclose(fptr);


// Print occurrences of all words in file.

 printf("\nLines: %d\n", lineCount);

 printf("\nWords: %d\n\n", totalWords);

  for (i = 0; i < numberOfUniqueWords; i++)
 {
printf("%s  %d\n\n", words[i], count[i]);
 }

 return 0;
 }
