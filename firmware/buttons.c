#include "buttons.h"
#include "xc.h"
#include "editing_fsm.h"
#include <stdbool.h>

#define ENCODER_SLOWDOWN 4

typedef struct {
    bool A;
    bool B;
} encoder_t;

static encoder_t last_encoder;
//button that means "go left"
static bool last_button_1;
//button that means "stop editing"
static bool last_button_2;
//button that means "go right"
static bool last_button_3;


static unsigned encoder_slowdown_counter = 0;

static void callback_encoder_ccw(int *output)
{
    if(++encoder_slowdown_counter == ENCODER_SLOWDOWN) {
        encoder_slowdown_counter = 0;
        edit_state_increment_cb(output);
    }
}

static void callback_encoder_cw(int *output)
{
    if(++encoder_slowdown_counter == ENCODER_SLOWDOWN) {
        encoder_slowdown_counter = 0;
        edit_state_decrement_cb(output);
    }
}

void handle_change_rot_a(int *output)
{
    volatile bool encoder_A = RC7;
    if(encoder_A != last_encoder.A) {
        last_encoder.A = encoder_A;
        if(encoder_A) {
            //a rising edge on A means CW if B is low, CCW if B is high
            if(last_encoder.B)
                callback_encoder_ccw(output);
            else
                callback_encoder_cw(output);
        } else {
            //falling edge on A means CCW if B is low, CW if B is high
            if(last_encoder.B)
                callback_encoder_cw(output);
            else
                callback_encoder_ccw(output);
        }
    }
}
void handle_change_rot_b(int *output)
{
    volatile bool encoder_B = PORTCbits.RC6;
    if (encoder_B != last_encoder.B) {
        last_encoder.B = encoder_B;
        if(encoder_B) {
            //rising  edge on B means CW if A is high, else CCW
            if(last_encoder.A)
                callback_encoder_cw(output);
            else
                callback_encoder_ccw(output);
        } else {
            //falling edge on B means CW if A is low, else CCW
            if(last_encoder.A)
                callback_encoder_ccw(output);
            else
                callback_encoder_cw(output);
        }
    }
}
