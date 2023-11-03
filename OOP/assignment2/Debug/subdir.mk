################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../assignment2.cpp \
../assignment_2.cpp \
../test.cpp 

CPP_DEPS += \
./assignment2.d \
./assignment_2.d \
./test.d 

OBJS += \
./assignment2.o \
./assignment_2.o \
./test.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./assignment2.d ./assignment2.o ./assignment_2.d ./assignment_2.o ./test.d ./test.o

.PHONY: clean--2e-

