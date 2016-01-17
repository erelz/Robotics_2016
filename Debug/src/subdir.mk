################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConfigurationsManager.cpp \
../src/Main.cpp \
../src/Map.cpp \
../src/PathFinder.cpp \
../src/Robot.cpp \
../src/WayPointsManager.cpp 

C_SRCS += \
../src/Globals.c 

OBJS += \
./src/ConfigurationsManager.o \
./src/Globals.o \
./src/Main.o \
./src/Map.o \
./src/PathFinder.o \
./src/Robot.o \
./src/WayPointsManager.o 

C_DEPS += \
./src/Globals.d 

CPP_DEPS += \
./src/ConfigurationsManager.d \
./src/Main.d \
./src/Map.d \
./src/PathFinder.d \
./src/Robot.d \
./src/WayPointsManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -Iusr/local/include/player-2.0/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


