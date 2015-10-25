#ifndef FUNCS_H
#define FUNCS_H

/*
 * File: funcs.h
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

// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

// SIZES
#define LIST_SIZE 1000
#define WORD_LENGTH 45
#define NUMBER_OF_CHANCES 8

// ARRAY SIZES(Please change this values as you add words in "words.h").
#define CARS_ARR_SIZE 62
#define PLANET_ARR_SIZE 8
#define RAND_ARR_SIZE 200

// ASCII VALUES.
#define SPACE 32
#define MASK 95
#define APOS 39

// ERRORS.
#define SUCCEESS 0
#define FAIL 1
#define LOAD_FAILED 101
#define NOT_ALPHABET 102


// Global Variables.
extern char cars_company[CARS_ARR_SIZE][WORD_LENGTH];
extern char planets[PLANET_ARR_SIZE][WORD_LENGTH];
extern char random_words[RAND_ARR_SIZE][WORD_LENGTH];

extern int total_words_in_list, my_score, lost;
extern char wordlist[LIST_SIZE][WORD_LENGTH];
extern char letters_available[26];

/*
 *  This function reads a file
 *  and stores the words to array
 *  in each line.
 */
int loadList(const char* filepath);

/*
 * This functions creates the menu.
 */
void makemenu(int num, char* title, ...);

/*
 * This functions displays the list.
 * (Used for debugging purposes).
 */
void displayList(void);

/*
 * This functions counts the number of
 * spaces and apostrophe.
 */
int countSpclchars(const char* str);

/*
 * This functions initializes
 * our available letters array.
 */
void fillLetters(void);

/*
 * This function turn an string to
 * all lower case.
 */
char *strtolwr(char *str);

#endif // FUNCS_H
