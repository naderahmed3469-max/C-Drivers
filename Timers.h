/*
 * Timers.h
 *
 * Created: 9/18/2025 6:02:49 PM
 *  Author: nanav
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

void Timer_CTC_init_interrupt(void);
void Timer_wave_nonPWM(void);
void Timer_wave_fastPWM(void);
void Timer2_OVF_interrupt_init(void);
short ultrasonic (void);
void Timer1_wave_fastPWM(double value);




#endif /* TIMERS_H_ */