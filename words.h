#ifndef WORDS_H
#define WORDS_H

/*
 * File: words.h
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

/// Please change the values in "funcs.h" as you add new words to the list.

// List of car companies.
char cars_company[CARS_ARR_SIZE][WORD_LENGTH] = {
"AB Flug", "AC", "Acura", "Aerogear", "APR Performance", "Aston Martin", "Audi",
"Bentley", "BMW", "Border", "Buick", "Cadillac", "Chevrolet", "Chrysler", "Datsun", "Dodge",
"Eagle", "Ferrari", "Ford", "Guldstrand", "Hennessey", "Honda", "Hyundai", "Infiniti", "INGS",
"Jaguar", "Koenigsegg", "Lancia", "Lexus", "Lingenfelter", "Lotus", "Mazda", "McLaren", "Mercedes",
"Mine's", "MINI", "Mitsubishi", "Mugen", "Nissan", "Opel", "Pagani", "Panoz", "Peugeot", "Pontiac",
"Porsche", "Renault", "Saab", "Saleen", "Seat", "Shelby", "Sparco", "Subaru", "Tommy Kaira", "Tom\'s",
"Toyota", "TVR", "Vauxhall", "Veilside", "VIS Racing", "Volkswagen", "Volvo", "Wings West"
};

// List of planets.
char planets[PLANET_ARR_SIZE][WORD_LENGTH] = {
"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"
};

// List of random words.
char random_words[RAND_ARR_SIZE][WORD_LENGTH] = {
"coat", "fork", "narrow", "kindly", "self", "maddening", "synonymous", "lackadaisical",
"frightened", "test", "truthful", "wise", "cake", "unlock", "delightful", "wax", "boy",
"glove", "wanting", "weigh", "sea", "internal", "smiling", "save", "bawdy", "loose", "unpack",
"recess", "elated", "guide", "frame", "describe", "awake", "grandmother", "haircut", "changeable",
"quiet", "wiggly", "bitter", "big", "youthful", "meddle", "coordinated", "sable", "veil", "happy",
"unsuitable", "protective", "tickle", "colour", "separate", "painstaking", "meeting", "perpetual",
"inexpensive", "tip", "answer", "pass", "cave", "injure", "taste", "lethal", "reproduce", "bite",
"example", "drag", "reduce", "peck", "overjoyed", "kindhearted", "borrow", "title", "lively", "last",
"dress", "level", "succeed", "bored", "yoke", "parched", "crush", "bleach", "alluring", "stitch",
"cup", "dry", "quicksand", "decorous", "near", "root", "sack", "fragile", "compare", "bang",
"unadvised", "men", "long", "division", "carpenter", "cushion", "march", "mountainous",
"knowledge", "strip", "plate", "strengthen", "trees", "invention", "bump", "adhesive",
"confused", "drum", "coach", "level", "appear", "sprout", "bumpy", "glass", "spare",
"attract", "touch", "miniature", "hesitant", "open", "crime", "work", "cable", "brash",
"pump", "muddle", "pan", "cycle", "eyes", "necessary", "creepy", "land", "offer", "statuesque",
"nosy", "abaft", "wild", "disappear", "seemly", "spray", "command", "garrulous", "careless",
"military", "smash", "truck", "lamp", "wilderness", "jeans", "skate", "care", "seed", "follow",
"obsolete", "pull", "woman", "absorbing", "achiever", "reflect", "amusement", "mean", "telephone",
"oven", "yam", "existence", "pink", "north", "plant", "surround", "bee", "orange", "destroy", "yarn",
"moan", "massive", "nest", "brown", "rail", "scientific", "spoon", "show", "crown", "milk", "third",
"price", "servant", "tank", "arithmetic", "decorate", "taboo", "brake", "red", "love", "unbecoming",
"valuable", "childlike"
};

#endif // WORDS_H
