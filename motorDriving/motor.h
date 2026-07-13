#ifndef MOTOR
#define MOTOR

typedef struct motorParams motorParams_t;
void motorInit(motorParams_t* motorInitP);
void motorControl(motorParams_t *motorParams);

#endif
