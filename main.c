/*
 * File: main.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcs.h"
#include "words.h"
#include "drawing.h"

/*
 * View license which
 * the program is released under.
 */
void viewLicense(void)
{
    clear_screen();
    drawLogo();
    getchar(); // Eating up any left chars.
    printf(
           " Copyright (c) 2015\n"
           " Khaled Mohammad <itskhaledmohammad@gmail.com> (twitter: @itskhaledmd)\n"
           " All Rights Reserved.\n"
           "\n"
           " BSD 3-Clause License\n"
           " http://www.opensource.org/licenses/BSD-3-Clause\n"
           "\n"
           " Redistribution and use in source and binary forms, with or without\n"
           " modification, are permitted provided that the following conditions are\n"
           " met:\n"
           "\n"
           " * Redistributions of source code must retain the above copyright notice,\n"
           "   this list of conditions and the following disclaimer.\n"
           " * Redistributions in binary form must reproduce the above copyright\n"
           "   notice, this list of conditions and the following disclaimer in the\n"
           "   documentation and/or other materials provided with the distribution.\n"
           " * Neither the name of (Khaled Mohammad) nor the names of its contributors\n"
           "   may be used to endorse or promote products derived from this software\n"
           "   without specific prior written permission.\n"
           "\n"
           " THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS\n"
           " IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED\n"
           " TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A\n"
           " PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT\n"
           " HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\n"
           " SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED\n"
           " TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR\n"
           " PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF\n"
           " LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING\n"
           " NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS\n"
           " SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n\n");
           //"************************************************************************\n");
           printf("Press enter to continue...\n");
           getchar();
}

/*
 * This function starts the game.
 */
void startGame(void)
{
    // Initialization.
    int option = 0, stat = 0, randinx = 0, chances_left = 0, char_state = 0,
        length = 0, letters_found = 0;
    char *pltr, *randword, ourLetter, mask_word[WORD_LENGTH];

    // Brushing up...
    srand(time(NULL));
    clear_screen();
    drawLogo();

    do{
        getchar(); // Eating up any left chars

        // Our Menu.
        makemenu(5, "What words you want to play with?",
                    "Cars Companies. *Bhrummm bhrumm*",
                    "Planets.(FYI there are more planets than Mars and Jupiter!).",
                    "Random words.",
                    "Your Coustom List(Put it in the same folder and name it as \"words.hang\")",
                    "Return to main menu.(Your Boring! -_-)");
        printf("Please Type in your option : ");
        scanf("%d", &option);

        // Loading our list.
        switch(option){
            case 1:
                // Randomly choosing an word.
                total_words_in_list = sizeof(cars_company) / WORD_LENGTH;
                randinx = rand() % total_words_in_list;
                randword = cars_company[randinx];
                strtolwr(randword);
                break;

            case 2:
                // Randomly choosing an word.
                total_words_in_list = sizeof(planets) / WORD_LENGTH;
                randinx = rand() % total_words_in_list;
                randword = planets[randinx];
                strtolwr(randword);
                break;

            case 3:
                // Randomly choosing an word.
                total_words_in_list = sizeof(random_words) / WORD_LENGTH;
                randinx = rand() % total_words_in_list;
                randword = random_words[randinx];
                strtolwr(randword);
                break;
            case 4:
                stat = loadList("words.hang");
                randinx = rand() % total_words_in_list;
                randword = wordlist[randinx];
                break;
            case 5:
                continue; // Returning to main menu.
            default:
                printf("\n\nInvalid input! Please choose from the options.");
                hangSleep(2000);
                clear_screen();
                drawLogo();
                continue;
        }

        // If we successfully opened our list.
        if(stat == 0){
            fillLetters(); // Initializing the available letters array.

            // Finding the length of the random word.
            length = strlen(randword);

            // Masking our word.
            for(int i = 0; i < length; i++){

                // Checking for '(Apostrophe) and Space.
                if(randword[i] != APOS && randword[i] != SPACE)
                    mask_word[i] = MASK;
                else
                    mask_word[i] = randword[i];
            }
            mask_word[length] = '\0'; // Setting an end marker to the string.

            // Calculating the length without the Apostrophe and Spaces.
            length = length - countSpclchars(randword);

            // While all the chances are gone or all the letters are correct.
            chances_left = NUMBER_OF_CHANCES;
            letters_found = 0;
            while(chances_left > 0 && letters_found != length){
                char_state = 1;

                // Getting a letter.
                do{
                    // Drawing the main screen.
                    drawHangman(NUMBER_OF_CHANCES - chances_left);
                    printf("\nYOUR WORD: %s\n\n"
                           "LENTH OF YOUR WORD: %d\n\n", mask_word, length);
                    getchar(); // Eating up any left chars.

                    // Take an available character from letter.
                    if(char_state == 0)
                        printf("Please type a character from the available letter.\n");
                    printf("Guess a letter: ");
                    ourLetter = getchar();                                        // Getting our character.

                    // Ignoring enters.
                    if(ourLetter == '\n'){
                        char_state = 0;
                        getchar();                                                // Eating up any left chars.
                        continue;
                    }
                    ourLetter = tolower(ourLetter);                               // Converting character to lower case.
                    pltr = strchr(letters_available, ourLetter);                  // Looking if the character is in array.
                    if(pltr != NULL){
                        letters_available[(pltr-letters_available+1) - 1] = MASK; // Removing the character from the array.
                        char_state = 1;
                    }
                    else{
                        char_state = 0;
                    }
                }while(char_state == 0);

                // Checking if the input is it correct.
                pltr = strchr(randword, ourLetter);                      // Looking for the letter.
                if(pltr != NULL){
                    while(pltr != NULL){
                        mask_word[(pltr-randword+1) - 1] = ourLetter;    // Revealing the masked letter.
                        pltr = strchr(pltr + 1, ourLetter);
                        letters_found++;
                    }
                }

                // If character is not found then subtract 1 from number of chances.
                else{
                    chances_left--;
                }

                // Win or Lose!
                if(letters_found == length){
                    my_score++;                                                   // Incrementing our score.
                    drawHangman(NUMBER_OF_CHANCES - chances_left);                // Drawing our Hangman.
                    printf("Way to go! You saved the man!!!\n"
                           "YOUR WORD: %s\n"
                           "Congrats you Won!!\n", randword);
                }
                else if(chances_left == 0){
                    lost++;                                                       // Incrementing number of times lost.
                    drawHangman(NUMBER_OF_CHANCES - chances_left);
                    printf("You killed the poor man! Shame!!!\n"
                           "YOUR WORD: %s\n"
                           "Loser!!!!!\n", randword);
                }
            }
            printf("*************************************\n\n"
                   "Lets Play Again!\n");
        }
        else{
            printf("Sorry We have Encountered an problem.\n"
                   "STATUS: TERMINATING...\n\n");
            hangSleep(4000);
            clear_screen();
            drawLogo();
        }
    }while(option != 5);
}

int main()
{
    // Initialization.
    int option = 0;
    my_score = 0, lost = 0;
    do{
        clear_screen();
        drawLogo();

        // Our main menu.
        makemenu(3, "MAIN MENU",
                    "START GAME",
                    "VIEW LICENSE",
                    "EXIT");
        printf("Type in your option : ");   // Taking input.
        scanf("%d", &option);
        switch(option){
            case 1:
                startGame();                // Starting our game.
                break;
            case 2:
                viewLicense();              // View license.
                break;
            case 3:
                break;
            default:
                printf("\n\nInvalid input! Please choose from the options.");
                hangSleep(2000);
                break;
        }
    }while(option != 3);
}
