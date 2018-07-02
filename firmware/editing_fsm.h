#ifndef EDITING_FSM_H_
#define EDITING_FSM_H_

void edit_state_during(int *outputs);
void edit_state_enter(int *outputs);
void edit_state_leave(int *outputs);

void edit_state_left_button_cb(int *outputs);
void edit_state_right_button_cb(int *outputs);

void edit_state_increment_cb(int *outputs);
void edit_state_decrement_cb(int *outputs);
#endif
