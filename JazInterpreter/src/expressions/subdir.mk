################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/expressions/Addition.cpp \
../src/expressions/And.cpp \
../src/expressions/Assign.cpp \
../src/expressions/Begin.cpp \
../src/expressions/Call.cpp \
../src/expressions/Division.cpp \
../src/expressions/End.cpp \
../src/expressions/Equal.cpp \
../src/expressions/Gofalse.cpp \
../src/expressions/Goto.cpp \
../src/expressions/Gotrue.cpp \
../src/expressions/Greater.cpp \
../src/expressions/GreaterEqual.cpp \
../src/expressions/Halt.cpp \
../src/expressions/Label.cpp \
../src/expressions/Less.cpp \
../src/expressions/LessEqual.cpp \
../src/expressions/Lvalue.cpp \
../src/expressions/Modulo.cpp \
../src/expressions/Multiplication.cpp \
../src/expressions/Not.cpp \
../src/expressions/NotEqual.cpp \
../src/expressions/Or.cpp \
../src/expressions/Pop.cpp \
../src/expressions/Print.cpp \
../src/expressions/Push.cpp \
../src/expressions/Return.cpp \
../src/expressions/Rvalue.cpp \
../src/expressions/Show.cpp \
../src/expressions/Subtraction.cpp 

OBJS += \
./src/expressions/Addition.o \
./src/expressions/And.o \
./src/expressions/Assign.o \
./src/expressions/Begin.o \
./src/expressions/Call.o \
./src/expressions/Division.o \
./src/expressions/End.o \
./src/expressions/Equal.o \
./src/expressions/Gofalse.o \
./src/expressions/Goto.o \
./src/expressions/Gotrue.o \
./src/expressions/Greater.o \
./src/expressions/GreaterEqual.o \
./src/expressions/Halt.o \
./src/expressions/Label.o \
./src/expressions/Less.o \
./src/expressions/LessEqual.o \
./src/expressions/Lvalue.o \
./src/expressions/Modulo.o \
./src/expressions/Multiplication.o \
./src/expressions/Not.o \
./src/expressions/NotEqual.o \
./src/expressions/Or.o \
./src/expressions/Pop.o \
./src/expressions/Print.o \
./src/expressions/Push.o \
./src/expressions/Return.o \
./src/expressions/Rvalue.o \
./src/expressions/Show.o \
./src/expressions/Subtraction.o 

CPP_DEPS += \
./src/expressions/Addition.d \
./src/expressions/And.d \
./src/expressions/Assign.d \
./src/expressions/Begin.d \
./src/expressions/Call.d \
./src/expressions/Division.d \
./src/expressions/End.d \
./src/expressions/Equal.d \
./src/expressions/Gofalse.d \
./src/expressions/Goto.d \
./src/expressions/Gotrue.d \
./src/expressions/Greater.d \
./src/expressions/GreaterEqual.d \
./src/expressions/Halt.d \
./src/expressions/Label.d \
./src/expressions/Less.d \
./src/expressions/LessEqual.d \
./src/expressions/Lvalue.d \
./src/expressions/Modulo.d \
./src/expressions/Multiplication.d \
./src/expressions/Not.d \
./src/expressions/NotEqual.d \
./src/expressions/Or.d \
./src/expressions/Pop.d \
./src/expressions/Print.d \
./src/expressions/Push.d \
./src/expressions/Return.d \
./src/expressions/Rvalue.d \
./src/expressions/Show.d \
./src/expressions/Subtraction.d 


# Each subdirectory must supply rules for building sources it contributes
src/expressions/%.o: ../src/expressions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


