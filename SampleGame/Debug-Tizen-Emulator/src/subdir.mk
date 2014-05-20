################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/DataThread.cpp \
../src/DataThreadManager.cpp \
../src/Form1.cpp \
../src/Form2.cpp \
../src/FormFactory.cpp \
../src/GameSelectForm.cpp \
../src/Lanking.cpp \
../src/SceneManagementFrame.cpp \
../src/SceneRegister.cpp \
../src/ThreadUI.cpp \
../src/ThreadUIEntry.cpp 

OBJS += \
./src/AppResourceId.o \
./src/DataThread.o \
./src/DataThreadManager.o \
./src/Form1.o \
./src/Form2.o \
./src/FormFactory.o \
./src/GameSelectForm.o \
./src/Lanking.o \
./src/SceneManagementFrame.o \
./src/SceneRegister.o \
./src/ThreadUI.o \
./src/ThreadUIEntry.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/DataThread.d \
./src/DataThreadManager.d \
./src/Form1.d \
./src/Form2.d \
./src/FormFactory.d \
./src/GameSelectForm.d \
./src/Lanking.d \
./src/SceneManagementFrame.d \
./src/SceneRegister.d \
./src/ThreadUI.d \
./src/ThreadUIEntry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\kichul\Documents\workspace\tizen\TizenGameHub\SampleGame\inc" -I"C:\Users\kichul\Documents\workspace\tizen\TizenGameHub\TizenGameHubLibrary\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target i386-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/osp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


