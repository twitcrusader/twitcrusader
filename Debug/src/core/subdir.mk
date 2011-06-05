################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/core/functions.c \
../src/core/gethttp.c \
../src/core/timeline.c \
../src/core/twitter.c 

OBJS += \
./src/core/functions.o \
./src/core/gethttp.o \
./src/core/timeline.o \
./src/core/twitter.o 

C_DEPS += \
./src/core/functions.d \
./src/core/gethttp.d \
./src/core/timeline.d \
./src/core/twitter.d 


# Each subdirectory must supply rules for building sources it contributes
src/core/%.o: ../src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -DICONS_DIR=\""/Development/Workspace/ClientTwitter-TwitCrusader/src/img"\" -o"$@" "$<" `pkg-config --cflags --libs gtk+-2.0 oauth libxml-2.0`
	@echo 'Finished building: $<'
	@echo ' '


