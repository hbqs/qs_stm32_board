#ifndef __QSDK_KEY__H_
#define __QSDK_KEY__H_

#include "button.h"
#include <board.h>

#define KEY_0		GET_PIN(A, 0)
#define	KEY_1		GET_PIN(C,13)



void qsdk_key_init(void);
void qsdk_key_process(void);



#endif

