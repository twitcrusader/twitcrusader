################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gui/gtkfunctions.c \
../src/gui/windows.c 

OBJS += \
./src/gui/gtkfunctions.o \
./src/gui/windows.o 

C_DEPS += \
./src/gui/gtkfunctions.d \
./src/gui/windows.d 


# Each subdirectory must supply rules for building sources it contributes
src/gui/%.o: ../src/gui/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -DICONS_DIR=\""/Development/Workspace/ClientTwitter-TwitCrusader/src/img"\" -o"$@" "$<" `pkg-config --cflags --libs gtk+-2.0 oauth libxml-2.0`
	@echo 'Finished building: $<'
	@echo ' '


