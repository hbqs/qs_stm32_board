#ifndef __QSDK_BEEP_H__
#define __QSDK_BEEP_H__


#include "board.h"

#define BEEP GET_PIN(A,8)

void qsdk_beep_on(void);
void qsdk_beep_off(void);
#endif
