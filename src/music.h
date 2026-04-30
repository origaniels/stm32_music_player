#include "clock.h"
#include "timer.h"
#include <stdint.h>

#define C5 1000000/523
#define B4 1000000/493
#define A4 1000000/440
#define G4 1000000/392
#define F4 1000000/349
#define E4 1000000/329

enum duration {
  CROCHE = 400,
  CROCHE_POINTEE = 600,
  NOIRE = 800,
  BLANCHE = 1600
};

struct note {
  uint16_t tone;
  uint16_t duration_ms;
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
  {A4, NOIRE},
  {C5, CROCHE},
  {C5, NOIRE},
  {A4, NOIRE},
  {G4, CROCHE},
  {F4, NOIRE},

  {G4, NOIRE},
  {A4, CROCHE},
  {C5, NOIRE},
  {A4, CROCHE},
  {G4, NOIRE},

  {A4, NOIRE},
  {C5, CROCHE},
  {C5, NOIRE},
  {A4, NOIRE},
  {G4, CROCHE},
  {F4, NOIRE},

  {G4, CROCHE_POINTEE},
  {A4, CROCHE_POINTEE},
  {G4, NOIRE},
  {F4, CROCHE},
  {F4, BLANCHE},
};

