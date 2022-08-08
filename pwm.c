/*
 * frequency_kh: is an input argument that describes the frequency in KHz.
 * dutyCycle: is an input argument that describes the duty cycle needed for the PWM that varies from 0 to 100 ( 0 means 0%, and 100 means 100%).
 */
 void SWPWM_init(uint32_t frequency_kh, uint8_t dutyCycle)
 {
    //write the CC1S bits to 01 in the TIMx_CCMR1 register (TI1 selected).
    TIM1_CCMR1|=(1<<0);
    TIM1_CCMR1&=~(1<<1);

    //write the CC1P bit to ‘0’ (active on rising edge).

    TIM1_CCER&=~(1<<1);

    //write the CC2S bits to 10 in the TIMx_CCMR1 register (TI1 selected).
    TIMx_CCMR1&=~(1<<0);
    TIMx_CCMR1|=(1<<1);

    //write the CC2P bit to ‘1’ (active on falling edge).
    TIM1_CCER|=(1<<5);
 }