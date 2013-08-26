################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Context.cpp \
../src/Expression.cpp \
../src/ExpressionFactory.cpp \
../src/JazInt.cpp \
../src/Parser.cpp \
../src/SymbolTable.cpp 

OBJS += \
./src/Context.o \
./src/Expression.o \
./src/ExpressionFactory.o \
./src/JazInt.o \
./src/Parser.o \
./src/SymbolTable.o 

CPP_DEPS += \
./src/Context.d \
./src/Expression.d \
./src/ExpressionFactory.d \
./src/JazInt.d \
./src/Parser.d \
./src/SymbolTable.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


