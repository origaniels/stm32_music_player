# Overview

This mini-project aims at exploring the capabilities of the STM32C031C6 for sound generation.

All of the code is written based on the available documentation, without any external tools or
libraries beyond the st-link utility and arm-none-eabi compiler.

This project reuses and improves the small HAL written for the baremetal_stm32 mini-project.

# Conclusions & Takeways

## The limitations of tim1 PWM

Through this project I explored the setup of the advanced control timer tim1 of the STM32C031C6 board.
That implied fixing the issues I previously had with the clock configuration, especially when it came to figuring out the actual clock frequency and the clock used among the multiple clocks available on the MCU.
I also found that it was rather difficult to have multiple sounds playing at several frequencies at the same time due to the fact that the different channels on tim1 only vary in duty cycle length and not on frequency.
Having multiple channels would be useful when controlling multiple motor speed outputs, but in the case of sound generation it isn't very useful.

## Playing multiple tones
In order to play at multiple frequencies simultaneously, the solution I found was to "fake it".
Basically switching between two tones every 40ms gives the impression that the 2 tones are being played at the same time. It does make a noticeable rattling sound but the sound still plays rather nicely.

For a better sound quality I would need a pre-recorded audio sample saved onto the flash, and then forward the bitstream via DMA directly to the desired output pin. However even if the recording had only 1 bit wide samples, the raw stream for a minute of recording would weigh around 300kB which is way beyond what can be stored on the flash.

The solution would then be to use secondary storage chips to store the raw music data, but I'm reserving that to a future project.

It would also be interesting to build my own DAC and try to get better sound quality.

# Dependencies

To run this project you will need the following dependencies (Arch Linux):

```
pacman -S arm-none-eabi-gcc arm-none-eabi-newlib
```

```
yay -S stlink
```

# Hardware

For this project I used a very basic 5 Ohms speaker and a Nucleo C031C6 developpement board.

# Setup and running

Flash and compile the program running:

```
make flash
```

The output signal to the speaker is on GPIO D13 on the board (corresponds to internal pin A5).

# References

- [STM32C0x1 MCU reference manual](https://www.st.com/resource/en/reference_manual/rm0490-stm32c0x1-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [STM32C031Cx datasheet](https://www.st.com/resource/en/datasheet/stm32c031c4.pdf)
- [ARM Cortex M0+ Documentation](https://developer.arm.com/documentation/dui0662/b)
- [Nucleo C031C6 user manual](https://www.st.com/resource/en/user_manual/um2953-stm32-nucleo64-board-mb1717-stmicroelectronics.pdf)


