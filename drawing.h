#ifndef DRAWING_H
#define DRAWING_H

/*
 * File: drawing.h
 * HANGMAN TERMANALISED!
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

#ifdef _WIN32
#include <windows.h>
#else
#define _BSD_SOURCE
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This function clears the screen.
 */
void clear_screen(void);

/*
 * This function freezes the program
 * for a certain period of time.
 */
void hangSleep(int msec);

/*
 * This functions setups the games
 * the draws the info on screen.
 */
void drawHangman(const int step);

/*
 * This function draws the header
 * logo.
 */
void drawLogo(void);

#endif // DRAWING_H
