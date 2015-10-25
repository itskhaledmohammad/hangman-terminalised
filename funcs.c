/*
 * File: funcs.c
 * HANGMAN TERMINALISED!
 *************************************
 *   +=====
 *   ||   |
 *   ||   O
 *   ||  |||
 *   ||   |
 *   ||  | |
 *   ||
 *  ----
 * Version: 0.1
 * Dated: 10/25/2015
 *
 * Copyright (c) 2015
 * Khaled Mohammad <itskhaledmohammad@gmail.com> (twitter: @itskhaledmd)
 * All Rights Reserved.
 *
 * BSD 3-Clause License
 * http://www.opensource.org/licenses/BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of (Khaled Mohammad) nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *************************************************************************/

#include "funcs.h"
char cars_company[CARS_ARR_SIZE][WORD_LENGTH];
char planets[PLANET_ARR_SIZE][WORD_LENGTH];
char random_words[RAND_ARR_SIZE][WORD_LENGTH];

int total_words_in_list, my_score, lost;
char wordlist[LIST_SIZE][WORD_LENGTH];
char letters_available[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                          'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                          'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                          'y', 'z'};

/*
 *  This function reads a file
 *  and stores the words to array
 *  in each line.
 */
int loadList(const char* filepath)
{
    int i = 0;
    char word[WORD_LENGTH + 1];

    // Get the string from the file
    FILE* listfile = fopen(filepath ,"r");

    // If we failed to open the file.
    if (listfile == NULL){
        fclose(listfile);
        printf("\n\nSorry can't open the file.\nERROR CODE: 0x1\n");
        return LOAD_FAILED;
    }

    // Reading each line from the file and copying it to the array.
    while (fgets(word, sizeof(word), listfile) != NULL){
        strtok(word, "\n"); // Chewing the new line.
        strtolwr(word);
        strcpy(wordlist[i++], word);
    }
    total_words_in_list = i;

    fclose(listfile);
    return SUCCEESS;
}

/*
 * This functions creates the menu.
 */
void makemenu(int num, char* title, ...)
{
    va_list argptr;
    va_start(argptr, title);
    printf("%s:\n", title);
    for(int i = 0; i < strlen(title); i++)
        printf("=");
    printf("\n");
    for(int j = 0; j < num; j++){
        printf("%d.%s\n", j + 1 ,va_arg(argptr, char*));
    }
    va_end(argptr);
}

/*
 * This functions displays the list.
 * (Used for debugging purposes).
 */
void displayList(void)
{
    int i;
    printf("\nLOADED WORDS: \n");

    for(i = 0; i < total_words_in_list ; i++)
        printf("%s\n", wordlist[i]);

    printf("\nLOADED WORDS: %d", i + 1);
}

/*
 * This functions counts the number of
 * spaces and Apostrophe.
 */
int countSpclchars(const char* str)
{
   int spclchars = 0;
   for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == SPACE || str[i] == APOS)
            spclchars++;
   }
   return spclchars;
}

/*
 * This functions initializes
 * our available letters array.
 */
void fillLetters(void)
{
    char val = 'a';
    for(int i = 0; i < 26; i++){
        letters_available[i] = val;
        val++;
    }
}

/*
 * This function turn an string to
 * all lower case.
 */
char *strtolwr(char *str)
{
  size_t len = strlen(str);
  for(size_t i = 0; i < len; i++)
  str[i] = tolower((unsigned char)str[i]);
  return str;
}

