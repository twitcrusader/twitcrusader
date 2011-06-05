################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include src/test/thread/subdir.mk
-include src/test/settings/subdir.mk
-include src/gui/subdir.mk
-include src/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ClientTwitter-TwitCrusader

# Tool invocations
ClientTwitter-TwitCrusader: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -DICONS_DIR=\""/Development/Workspace/ClientTwitter-TwitCrusader/src/img"\" -o"ClientTwitter-TwitCrusader" $(OBJS) $(USER_OBJS) $(LIBS) `pkg-config --cflags --libs gtk+-2.0 oauth libxml-2.0`
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) ClientTwitter-TwitCrusader
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
