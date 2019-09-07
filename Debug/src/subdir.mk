################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Communication.c \
../src/PinMux.c \
../src/Test.c \
../src/Timer.c \
../src/main.c 

SRC_OBJS += \
./src/Communication.o \
./src/PinMux.o \
./src/Test.o \
./src/Timer.o \
./src/main.o 

C_DEPS += \
./src/Communication.d \
./src/PinMux.d \
./src/Test.d \
./src/Timer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0x100 @includes-71f1f464465ef79a7e7b0ac7348f7f7f.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


