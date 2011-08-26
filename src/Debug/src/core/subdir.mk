################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/core/Config.cpp \
../src/core/Functions.cpp \
../src/core/GetHTTP.cpp \
../src/core/LocalUser.cpp \
../src/core/TimeLine.cpp \
../src/core/Tweet.cpp \
../src/core/Twitter.cpp \
../src/core/User.cpp 

OBJS += \
./src/core/Config.o \
./src/core/Functions.o \
./src/core/GetHTTP.o \
./src/core/LocalUser.o \
./src/core/TimeLine.o \
./src/core/Tweet.o \
./src/core/Twitter.o \
./src/core/User.o 

CPP_DEPS += \
./src/core/Config.d \
./src/core/Functions.d \
./src/core/GetHTTP.d \
./src/core/LocalUser.d \
./src/core/TimeLine.d \
./src/core/Tweet.d \
./src/core/Twitter.d \
./src/core/User.d 


# Each subdirectory must supply rules for building sources it contributes
src/core/%.o: ../src/core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/gtkmm-3.0 -I/usr/lib/gtkmm-3.0/include -I/usr/include/atkmm-1.6 -I/usr/include/giomm-2.4 -I/usr/lib/giomm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/lib/pangomm-1.4/include -I/usr/include/gtk-3.0 -I/usr/include/cairomm-1.0 -I/usr/lib/cairomm-1.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/gdkmm-3.0/include -I/usr/include/atk-1.0 -I/usr/include/glibmm-2.4 -I/usr/lib/glibmm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng14 -I/usr/include/libxml2 -O0 -g3 -Wall -c -DGSEAL_ENABLE -pthread -DICONS_DIR=\""./src/icons"\" -DPROG_DIR=\""."\" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


