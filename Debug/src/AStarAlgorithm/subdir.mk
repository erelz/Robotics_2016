################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AStarAlgorithm/AStarSearcher.cpp \
../src/AStarAlgorithm/MapGraphObject.cpp \
../src/AStarAlgorithm/Matrix.cpp 

OBJS += \
./src/AStarAlgorithm/AStarSearcher.o \
./src/AStarAlgorithm/MapGraphObject.o \
./src/AStarAlgorithm/Matrix.o 

CPP_DEPS += \
./src/AStarAlgorithm/AStarSearcher.d \
./src/AStarAlgorithm/MapGraphObject.d \
./src/AStarAlgorithm/Matrix.d 


# Each subdirectory must supply rules for building sources it contributes
src/AStarAlgorithm/%.o: ../src/AStarAlgorithm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -I"/home/colman/work/colman/IdanAndRonRobotics/src" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


