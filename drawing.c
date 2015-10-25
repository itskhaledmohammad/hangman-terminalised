/*
 * File: drawing.c
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

#include "drawing.h"
#include "funcs.h"

// Global Variables.
int total_words_in_list, my_score, lost;
char wordlist[LIST_SIZE][WORD_LENGTH];
char letters_available[26];

/*
 * This function clears the screen.
 */
void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*
 * This function freezes the program
 * for a certain period of time.
 */
void hangSleep(int msec)
{
    #ifdef _WIN32
        Sleep(msec);
    #else
        usleep(msec * 1000);
    #endif
}

/*
 * This functions setups the games
 * the draws the info on screen.
 */
void drawHangman(const int step)
{
    clear_screen();
    drawLogo();
    switch(step){
            case 0:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE LETTERS:        \n"
                " ||        %s                        \n"
                " ||                                  \n"
                " ||         Chances Left: %d         \n"
                " ||          Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;
            case 1:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||                                  \n"
                " ||         Chances Left: %d         \n"
                " ||          Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;

            case 2:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||   O                              \n"
                " ||         Chances Left: %d         \n"
                " ||          Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;
            case 3:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||   O                              \n"
                " ||  /      Chances Left: %d         \n"
                " ||          Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;
            case 4:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||   O                              \n"
                " ||  /|     Chances Left: %d         \n"
                " ||          Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;
            case 5:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||   O                              \n"
                " ||  /|\\    Chances Left: %d        \n"
                " ||          Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;
            case 6:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||   O                              \n"
                " ||  /|\\    Chances Left: %d        \n"
                " ||   |      Your Score: %d          \n"
                " ||            Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;

            case 7:
                printf("\n"
                "*************************************\n"
                " +=====    AVAILABLE WORDS:          \n"
                " ||   |    %s                        \n"
                " ||   O                              \n"
                " ||  /|\\    Chances Left: %d        \n"
                " ||   |      Your Score: %d          \n"
                " ||  /         Lost: %d              \n"
                " ||                                  \n"
                " +====+                              \n"
                "*************************************\n"
                ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                lost);
                break;
            case 8:
                // A Bit animation..
                for(int i = 0; i < 3; i++){
                    clear_screen();
                    drawLogo();
                    printf("\n"
                    "*************************************\n"
                    " +=====    AVAILABLE WORDS:          \n"
                    " ||   |    %s                        \n"
                    " ||   O                              \n"
                    " ||  /|\\    Chances Left: %d        \n"
                    " ||   |      Your Score: %d          \n"
                    " ||  / \\       Lost: %d             \n"
                    " ||                                  \n"
                    " +====+                              \n"
                    "*************************************\n"
                    "Help!!!\n\n"
                    ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                    lost);

                    hangSleep(600);
                    clear_screen();
                    drawLogo();
                    printf("\n"
                    "*************************************\n"
                    " +=====    AVAILABLE WORDS:          \n"
                    " ||   |    %s                        \n"
                    " ||   O                              \n"
                    " ||  |||    Chances Left: %d         \n"
                    " ||   |      Your Score: %d          \n"
                    " ||  | |       Lost: %d              \n"
                    " ||                                  \n"
                    " +====+                              \n"
                    "*************************************\n"
                    ,letters_available, NUMBER_OF_CHANCES - step, my_score,
                    lost);
                    if(i < 2){
                        printf("Help!!!\n\n");
                        hangSleep(1000);
                    }
                }
                break;
    }
}

/*
 * This function draws the header
 * logo.
 */
void drawLogo(void)
{
    printf(""
           "  _   _  \n"
           " | | | | __ _ _ __   __ _ _ __ ___   __ _ _ __   \n"
           " | |_| |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\  \n"
           " |  _  | (_| | | | | (_| | | | | | | (_| | | | | \n"
           " |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n"
           "  _____             |___/ _             _ _              _   _ \n"
           " |_   _|__ _ __ _ __ ___ (_)_ __   __ _| (_)___  ___  __| | | |\n"
           "   | |/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | | / __|/ _ \\/ _` | | |\n"
           "   | |  __/ |  | | | | | | | | | | (_| | | \\__ \\  __/ (_| | |_|\n"
           "   |_|\\___|_|  |_| |_| |_|_|_| |_|\\__,_|_|_|___/\\___|\\__,_| (_)\n"
           "\n"
           " - Save him if you can! \n\n"
           "[*] Version: 0.1\n"
           "[*] Author: Khaled Mohammad(@itskhaledmohammad)\n"
           "[*] Released under BSD-3-Clause\n"
           "\n\n");

}
