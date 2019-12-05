################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/condition_parser.cpp \
../src/main.cpp \
../src/test.cpp \
../src/token.cpp 

OBJS += \
./src/condition_parser.o \
./src/main.o \
./src/test.o \
./src/token.o 

CPP_DEPS += \
./src/condition_parser.d \
./src/main.d \
./src/test.d \
./src/token.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


