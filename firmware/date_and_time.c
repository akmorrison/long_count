#include "date_and_time.h"

//lord forgive me, for I have sinned
//there's no way to make this really nice and generic
//well, there probably is, but we have so much code space
//that I _really_ just don't care
void decrement_and_rollover(int* in, int index)
{
    //start at index, decrement it, and all numbers after it
    switch(index) {
    case 0:
        //in[0] is centiseconds, in[1] is deciseconds
        //rollover for in[0]->in[4] works really simply
        if(in[0] != 0) {
            in[0]--;
            return;
        }
        in[0] = 9;
    case 1:
        if(in[1] != 0) {
            in[1]--;
            return;
        }
        in[1] = 9;
    case 2:
        //in[2] holds the seconds
        if(in[2] != 0) {
            in[2]--;
            return;
        }
        in[2] = 9;
    case 3:
        //in[3] holds seconds, it shouldn't go above 5
        if(in[3] != 0) {
            in[3]--;
            return;
        }
        in[3] = 5;
    case 4:
        //in[4] holds minutes
        if(in[4] != 0) {
            in[4]--;
            return;
        }
        in[4] = 9;
    case 5:
        //in[5] is ten mintues. Can't have more than 5
        if(in[5] != 0) {
            in[5]--;
            return;
        }
        in[5] = 5;
    case 6:
        //holds hours
        if(in[6] != 0) {
            in[6]--;
            return;
        }
        in[6] = 9;
    case 7:
        //10s of hours
        if(in[7] != 0) {
            in[7]--;
            return;
        }
        in[7] = 5;
    case 8:
        //days
        if(in[8] != 0) {
            in[8]--;
            return;
        }
        in[8] = 9;
    case 9:
        //holds 10s of days. There's a bunch of logic to determining this,
        //so I'm gonna go ahead and ignore it now. Months have 30 days
        if(in[9] != 0) {
            in[9]--;
            return;
        }
        in[9] = 9;
    case 10:
        //holds months. This is complicated. If there are 0 months left,
        //this becomes 1, otherwise becomes 9
        if(in[10] != 0) {
            in[10]--;
            return;
        }
        in[10] = in[11] == 0 ? 1 : 9;
    case 11:
        //10s of months
        if(in[11] != 0) {
            in[11]--;
            return;
        }
        in[11] = 1;
    case 12:
        //years. From here on, we're pretty much good
        if(in[12] != 0) {
            in[12]--;
            return;
        }
        in[12] = 9;
    case 13:
        if(in[13] != 0) {
            in[13]--;
            return;
        }
        in[13] = 9;
    case 14:
        if(in[14] != 0) {
            in[14]--;
            return;
        }
        in[14] = 9;
    case 15:
        if(in[15] != 0) {
            in[15]--;
            return;
        }
        in[15] = 9;
    }
}

void increment_and_rollover(int* in, int index)
{
    //start at index, decrement it, and all numbers after it
    switch(index) {
    case 0:
        //in[0] is centiseconds, in[1] is deciseconds
        //rollover for in[0]->in[4] works really simply
        if(in[0] != 9) {
            in[0]++;
            return;
        }
        in[0] = 0;
    case 1:
        if(in[1] != 9) {
            in[1]++;
            return;
        }
        in[1] = 0;
    case 2:
        //in[2] holds the seconds
        if(in[2] != 9) {
            in[2]++;
            return;
        }
        in[2] = 0;
    case 3:
        //in[3] holds seconds, it shouldn't go above 5
        if(in[3] != 5) {
            in[3]++;
            return;
        }
        in[3] = 0;
    case 4:
        //in[4] holds minutes
        if(in[4] != 9) {
            in[4]++;
            return;
        }
        in[4] = 0;
    case 5:
        //in[5] is ten mintues. Can't have more than 5
        if(in[5] != 5) {
            in[5]++;
            return;
        }
        in[5] = 0;
    case 6:
        //holds hours
        if(in[6] != 9) {
            in[6]++;
            return;
        }
        in[6] = 0;
    case 7:
        //10s of hours
        if(in[7] != 5) {
            in[7]++;
            return;
        }
        in[7] = 5;
    case 8:
        //days
        if(in[8] != 9) {
            in[8]++;
            return;
        }
        in[8] = 0;
    case 9:
        //holds 10s of days. There's a bunch of logic to determining this,
        //so I'm gonna go ahead and ignore it now. Months have 30 days
        if(in[9] != 2) {
            in[9]++;
            return;
        }
        in[9] = 0;
    case 10:
        //holds months. This is complicated. If there are 0 months left,
        //this becomes 1, otherwise becomes 9
        if((in[10] != 9 && in[11] != 1) || in[10] != 1) {
            in[10]++;
            return;
        }
        in[10] = 0;
    case 11:
        //10s of months
        if(in[11] != 1) {
            in[11]++;
            return;
        }
        in[11] = 0;
    case 12:
        //years. From here on, we're pretty much good
        if(in[12] != 9) {
            in[12]++;
            return;
        }
        in[12] = 0;
    case 13:
        if(in[13] != 9) {
            in[13]++;
            return;
        }
        in[13] = 0;
    case 14:
        if(in[14] != 9) {
            in[14]++;
            return;
        }
        in[14] = 0;
    case 15:
        if(in[15] != 9) {
            in[15]++;
            return;
        }
        in[15] = 0;
    }
}
