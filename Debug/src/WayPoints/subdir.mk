################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/WayPoints/WayPoint.cpp 

OBJS += \
./src/WayPoints/WayPoint.o 

CPP_DEPS += \
./src/WayPoints/WayPoint.d 


# Each subdirectory must supply rules for building sources it contributes
src/WayPoints/%.o: ../src/WayPoints/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


