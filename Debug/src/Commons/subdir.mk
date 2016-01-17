################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commons/GridPosition.cpp \
../src/Commons/Location.cpp \
../src/Commons/MapObject.cpp \
../src/Commons/RobotLocation.cpp \
../src/Commons/Utils.cpp 

OBJS += \
./src/Commons/GridPosition.o \
./src/Commons/Location.o \
./src/Commons/MapObject.o \
./src/Commons/RobotLocation.o \
./src/Commons/Utils.o 

CPP_DEPS += \
./src/Commons/GridPosition.d \
./src/Commons/Location.d \
./src/Commons/MapObject.d \
./src/Commons/RobotLocation.d \
./src/Commons/Utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commons/%.o: ../src/Commons/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


