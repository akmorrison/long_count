#include "editing_fsm.h"
#include "date_and_time.h"
#include <stdbool.h>

//add this number to an output to make it blink off
#define BLINK_OFFSET 10
#define BLINK_TIME 50

//values used to blink the currently edited number
static unsigned blink_counter = 0;
static bool blink_state = false;

//the index of the number we're currently editing
static unsigned current_index = 0;

//called whenever we're in editing mode
void edit_state_during(int *outputs) {
    //check if we need to blink a number
    if(++blink_counter >= BLINK_TIME) {
        blink_counter = 0;
        if(blink_state)
            //number is currently off, turn it on
            outputs[current_index] -= BLINK_OFFSET;
        else
            //number is currently on, turn it off
            outputs[current_index] += BLINK_OFFSET;
        blink_state = !blink_state;
    }
}

void edit_state_enter(int *outputs) {

}

void edit_state_leave(int *outputs) {

}

void edit_state_left_button_cb(int *outputs) {
    if(blink_state)
        outputs[current_index] -= BLINK_OFFSET;
    if(current_index == 15)
        current_index = 0;
    else
        current_index++;
    blink_state = false;
    blink_counter = 0;
}

void edit_state_right_button_cb(int *outputs) {
    if(blink_state)
        outputs[current_index] -= BLINK_OFFSET;
    if(current_index == 0)
        current_index = 15;
    else
        current_index--;
    blink_state = false;
    blink_counter = 0;
}

void edit_state_increment_cb(int *outputs) {
    if(blink_state)
        outputs[current_index] -= BLINK_OFFSET;
    increment_and_rollover(outputs, current_index);
    if(blink_state)
        outputs[current_index] += BLINK_OFFSET;
}

void edit_state_decrement_cb(int *outputs) {
    if(blink_state)
        outputs[current_index] -= BLINK_OFFSET;
    decrement_and_rollover(outputs, current_index);
    if(blink_state)
        outputs[current_index] += BLINK_OFFSET;
}
