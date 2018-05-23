// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int X = fraction[0] - '0';
    int Y = fraction[2] - '0';
    float mult = 8.0 / Y;

    return round(X * mult);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int offset = 0;
    if (note[0] == 'B'){
        offset = 2;
    } else if (note[0] == 'G'){
        offset = -2;
    } else if (note[0] == 'F'){
        offset = -4;
    } else if (note[0] == 'E'){
        offset = -5;
    } else if (note[0] == 'D'){
        offset = -7;
    } else if (note[0] == 'C'){
        offset = -9;
    }

    float diff;
    if (strlen(note) == 2) {
        diff = offset + 12 * (note[1] - '0' - 4);
    } else {
        diff = offset + 12 * (note[2] - '0' - 4);
        if (note[1] == '#'){
            diff += 1;
        } else {
            diff -= 1;
        }
    }
    diff /= 12;
    return (int)round(pow(2.0, diff) * 440.0);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0){
        return true;
    } else {
        return false;
    }
}
