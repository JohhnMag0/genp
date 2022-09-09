/* *************************************
 * Random Password Generator write in C
 *
 * Name: genp
 * Author: John Mago0
 * Date: 2022-09-02
 * Version: 1.0 
 * ************************************
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Lists for passwords */
#define ALPHANUM "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"
#define SYMBOL "0!#$%&*+-/:;?@^_|~123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

/* Prints the help and end the program */
#define HELP printf("Usage: genp [OPTION] [number]\n" \
                    "Generates a random password.\n" \
                    "\n" \
                    "   -h, --help          display this help and exit\n" \
                    "   -a, --alphanum      generates a alphanumerical password\n" \
                    "   -d, --digit         generates a numerical password\n" \
                    "   -s, --symbol        generates a alphanumerical password with symbols\n" \
                    "\n" \
                    "Examples:\n" \
                    "   genp			Generates a alphanumerical password with length 8.\n" \
                    "   genp -d 10	                Generates a numerical password with length 10.\n"); \
             exit(0);

/* for loops global */
int i;

void genalpha(int size){
    unsigned int randval;
    FILE *f;
    char list[] = ALPHANUM; 
    char pass[size];

    /* /dev/urandom is a file that generates pesudorandom numbers.
    * These numbers are generated throught "noises" of the system.
    * Here I'm reading from this chaotic file to get random numbers.*/
    f = fopen("/dev/urandom", "r");
    for (i=0; i<size; i++) {
        fread(&randval, sizeof(randval), 1, f);

        /* 62 is the number of characters on the ALPHANUM list */
        pass[i] = list[randval % 62];
        printf("%c", pass[i]);
    }
    fclose(f);
    printf("\n");
}

void gendigit(int size){ 
    unsigned int randval;
    FILE *f;
    char list[] = NUM;
    char pass[size];

    f = fopen("/dev/urandom", "r");
    for (i=0; i<size; i++) {
        fread(&randval, sizeof(randval), 1, f);
        pass[i] = list[randval % 10];
        printf("%c", pass[i]);
    }
    fclose(f);
    printf("\n");
}

void gensymbol(int size){
    unsigned int randval;
    FILE *f;
    char list[] = SYMBOL;
    char pass[size];

    f = fopen("/dev/urandom", "r");
    for (i=0; i<size; i++) {
        fread(&randval, sizeof(randval), 1, f);
        pass[i] = list[randval % 69];
        printf("%c", pass[i]);
    }
    fclose(f);
    printf("\n");
}

int main(int argc, char *argv[]) 
{
    int length = 8;

    switch (argc) {
        case 1: genalpha(length); break;
        case 2: 
                if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
                    HELP
                } 
                
                length = atoi(argv[1]);

                if (length < 6 || length > 32) {
                    printf("Error: Password size must be a number between 6 and 32\n\n");
                    HELP
                }
                genalpha(length); break;
        case 3:
                length = atoi(argv[2]);
                
                if(length < 6 || length > 32) {
                    printf("Error: Password size must be a number between 6 and 32\n\n");
                    HELP
                }

                /* Checks the argument being passed */
                if (!strcmp(argv[1], "-s") || !strcmp(argv[1], "--symbol")) {
                    gensymbol(length);
                } 
                else if (!strcmp(argv[1], "-a") || !strcmp(argv[1], "--alphanum")) {
                    genalpha(length);
                } 
                else if (!strcmp(argv[1], "-d") || !strcmp(argv[1], "--digits")) {
                    gendigit(length);
                } 
                else {
                    HELP
                }
                break;
        default: HELP 
    }
}
