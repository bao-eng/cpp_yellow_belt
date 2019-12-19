################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/condition_parser.cpp \
../src/condition_parser_test.cpp \
../src/database.cpp \
../src/date.cpp \
../src/main.cpp \
../src/node.cpp \
../src/token.cpp 

OBJS += \
./src/condition_parser.o \
./src/condition_parser_test.o \
./src/database.o \
./src/date.o \
./src/main.o \
./src/node.o \
./src/token.o 

CPP_DEPS += \
./src/condition_parser.d \
./src/condition_parser_test.d \
./src/database.d \
./src/date.d \
./src/main.d \
./src/node.d \
./src/token.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


