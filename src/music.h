#include "clock.h"
#include "timer.h"
#include <stdint.h>

enum tone {
 TONE_C5 = 1000000/523,
 TONE_B4 = 1000000/493,
 TONE_A4 = 1000000/440,
 TONE_G4 = 1000000/392,
 TONE_F4 = 1000000/349,
 TONE_E4 = 1000000/329
};

enum duration {
  CROCHE = 400,
  CROCHE_POINTEE = 600,
  NOIRE = 800,
  BLANCHE = 1600
};

struct note {
  enum tone tone;
  enum duration duration_ms;
};

void play_song(struct note *song, uint32_t length) {
  set_tim1_pwm_on();
  for (uint32_t i = 0; i<length; i++) {
    set_tim1_pwm_freq(song[i].tone);
    delay(song[i].duration_ms);
    set_tim1_pwm_ccr1(0);
    delay(1);
    set_tim1_pwm_ccr1(20);
  }
  set_tim1_pwm_off();
}

struct note ieji[22] = {
  {TONE_A4, NOIRE},
  {TONE_C5, CROCHE},
  {TONE_C5, NOIRE},
  {TONE_A4, NOIRE},
  {TONE_G4, CROCHE},
  {TONE_F4, NOIRE},

  {TONE_G4, NOIRE},
  {TONE_A4, CROCHE},
  {TONE_C5, NOIRE},
  {TONE_A4, CROCHE},
  {TONE_G4, NOIRE},

  {TONE_A4, NOIRE},
  {TONE_C5, CROCHE},
  {TONE_C5, NOIRE},
  {TONE_A4, NOIRE},
  {TONE_G4, CROCHE},
  {TONE_F4, NOIRE},

  {TONE_G4, CROCHE_POINTEE},
  {TONE_A4, CROCHE_POINTEE},
  {TONE_G4, NOIRE},
  {TONE_F4, CROCHE},
  {TONE_F4, BLANCHE},
};

