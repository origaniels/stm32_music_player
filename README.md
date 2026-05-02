# Overview

This project aims at exploring the capabilities of the STM32C031C6 for sound generation.

All of the code is written based on the available documentation, without any external tools or
libraries beyond the st-link utility and arm-none-eabi compiler.

This project reuses and improves the small HAL written for the baremetal_stm32 project.

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


