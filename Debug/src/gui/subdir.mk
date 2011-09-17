################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gui/windows.credits.c \
../src/gui/windows.main.c \
../src/gui/windows.updates.c 

OBJS += \
./src/gui/windows.credits.o \
./src/gui/windows.main.o \
./src/gui/windows.updates.o 

C_DEPS += \
./src/gui/windows.credits.d \
./src/gui/windows.main.d \
./src/gui/windows.updates.d 


# Each subdirectory must supply rules for building sources it contributes
src/gui/%.o: ../src/gui/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng14 -I/usr/include/libxml2 -O0 -g3 -Wall -c -fmessage-length=0 -DGSEAL_ENABLE -pthread -DICONS_DIR=\""/Development/WorkSpace/TwitCrusader-C/share/icons"\" -DPROG_DIR=\""Development/WorkSpace/TwitCrusader-C"\" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


