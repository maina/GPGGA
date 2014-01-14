################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../ClientSocket.o \
../ServerSocket.o \
../Socket.o \
../simple_client_main.o \
../simple_server_main.o 

CPP_SRCS += \
../ClientSocket.cpp \
../ServerSocket.cpp \
../Socket.cpp \
../simple_client_main.cpp \
../simple_server_main.cpp 

OBJS += \
./ClientSocket.o \
./ServerSocket.o \
./Socket.o \
./simple_client_main.o \
./simple_server_main.o 

CPP_DEPS += \
./ClientSocket.d \
./ServerSocket.d \
./Socket.d \
./simple_client_main.d \
./simple_server_main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


