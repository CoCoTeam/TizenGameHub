################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/CardPairApp.cpp \
../src/CardPairEntry.cpp \
../src/CardPairFormFactory.cpp \
../src/CardPairFrame.cpp \
../src/DataThread.cpp \
../src/DataThreadManager.cpp \
../src/FormGame.cpp \
../src/FormGameMulti.cpp \
../src/FormGameSeconds.cpp \
../src/FormGameTimeTrial.cpp \
../src/FormMain.cpp \
../src/FormModeSelect.cpp \
../src/FormSocial.cpp 

OBJS += \
./src/AppResourceId.o \
./src/CardPairApp.o \
./src/CardPairEntry.o \
./src/CardPairFormFactory.o \
./src/CardPairFrame.o \
./src/DataThread.o \
./src/DataThreadManager.o \
./src/FormGame.o \
./src/FormGameMulti.o \
./src/FormGameSeconds.o \
./src/FormGameTimeTrial.o \
./src/FormMain.o \
./src/FormModeSelect.o \
./src/FormSocial.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/CardPairApp.d \
./src/CardPairEntry.d \
./src/CardPairFormFactory.d \
./src/CardPairFrame.d \
./src/DataThread.d \
./src/DataThreadManager.d \
./src/FormGame.d \
./src/FormGameMulti.d \
./src/FormGameSeconds.d \
./src/FormGameTimeTrial.d \
./src/FormMain.d \
./src/FormModeSelect.d \
./src/FormSocial.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\JOHEEYEON\workspace\TizenGameHub\CardPair\inc" -I"C:\Users\JOHEEYEON\workspace\TizenGameHub\TizenGameHubLibrary\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target i386-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../i386-linux-gnueabi-gcc-4.5/" -ccc-gcc-name i386-linux-gnueabi-g++ -march=i386 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-emulator-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


