################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libs/curl/getfile.c 

OBJS += \
./src/libs/curl/getfile.o 

C_DEPS += \
./src/libs/curl/getfile.d 


# Each subdirectory must supply rules for building sources it contributes
src/libs/curl/%.o: ../src/libs/curl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/usr/include/gtk-3.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng14 -I/usr/include/libxml2 -O0 -g3 -Wall -c -fmessage-length=0 -DGSEAL_ENABLE -pthread -DICONS_DIR=\""/Development/WorkSpace/TwitCrusader-nightly/share(icons"\" -DPROG_DIR=\""Development/WorkSpace/TwitCrusader-nightly"\" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


