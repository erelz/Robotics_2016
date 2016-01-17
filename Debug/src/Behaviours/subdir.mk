################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Behaviours/Behaviour.cpp \
../src/Behaviours/ForwardBehaviour.cpp \
../src/Behaviours/Manager.cpp \
../src/Behaviours/ObstacleBehaviour.cpp \
../src/Behaviours/RotateBehaviour.cpp \
../src/Behaviours/WaypointSelectionBehaviour.cpp 

OBJS += \
./src/Behaviours/Behaviour.o \
./src/Behaviours/ForwardBehaviour.o \
./src/Behaviours/Manager.o \
./src/Behaviours/ObstacleBehaviour.o \
./src/Behaviours/RotateBehaviour.o \
./src/Behaviours/WaypointSelectionBehaviour.o 

CPP_DEPS += \
./src/Behaviours/Behaviour.d \
./src/Behaviours/ForwardBehaviour.d \
./src/Behaviours/Manager.d \
./src/Behaviours/ObstacleBehaviour.d \
./src/Behaviours/RotateBehaviour.d \
./src/Behaviours/WaypointSelectionBehaviour.d 


# Each subdirectory must supply rules for building sources it contributes
src/Behaviours/%.o: ../src/Behaviours/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


