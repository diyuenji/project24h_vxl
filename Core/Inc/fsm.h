/*
 * fsm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#define normal 0
#define setting 1

#include "button.h"
#include "global.h"
#include "software_timer.h"

void fsm_simple_buttons_run();

void fsm();
#endif /* INC_FSM_H_ */
