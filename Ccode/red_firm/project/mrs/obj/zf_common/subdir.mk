################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_clock.c \
F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_debug.c \
F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_fifo.c \
F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_font.c \
F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_function.c \
F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_clock.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\Libraries\doc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Core" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Ld" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Peripheral" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Startup" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\user\inc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_common" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_device" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\code" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_debug.o: F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\Libraries\doc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Core" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Ld" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Peripheral" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Startup" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\user\inc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_common" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_device" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\code" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_fifo.o: F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_fifo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\Libraries\doc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Core" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Ld" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Peripheral" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Startup" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\user\inc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_common" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_device" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\code" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_font.o: F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\Libraries\doc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Core" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Ld" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Peripheral" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Startup" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\user\inc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_common" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_device" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\code" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_function.o: F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_function.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\Libraries\doc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Core" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Ld" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Peripheral" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Startup" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\user\inc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_common" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_device" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\code" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_interrupt.o: F:/����/Firmware/2023NUEDC/Ccode/red_firm/libraries/zf_common/zf_common_interrupt.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\Libraries\doc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Core" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Ld" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Peripheral" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\sdk\Startup" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\user\inc" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_common" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_device" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\project\code" -I"F:\����\Firmware\2023NUEDC\Ccode\red_firm\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

