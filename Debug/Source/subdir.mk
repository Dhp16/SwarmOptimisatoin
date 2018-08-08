################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/AbstractProperties.cpp \
../Source/Particle.cpp \
../Source/Population.cpp \
../Source/PropertySetter.cpp \
../Source/main.cpp \
../Source/tools.cpp 

OBJS += \
./Source/AbstractProperties.o \
./Source/Particle.o \
./Source/Population.o \
./Source/PropertySetter.o \
./Source/main.o \
./Source/tools.o 

CPP_DEPS += \
./Source/AbstractProperties.d \
./Source/Particle.d \
./Source/Population.d \
./Source/PropertySetter.d \
./Source/main.d \
./Source/tools.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


