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
<<<<<<< HEAD
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\hursujung\TizenGameHub\CardPair\inc" -I"C:\Users\hursujung\TizenGameHub\TizenGameHubLibrary\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target arm-tizen-linux-gnueabi -gcc-toolchain "C:/tizen-sdk/tools/smart-build-interface/../arm-linux-gnueabi-gcc-4.5/" -ccc-gcc-name arm-linux-gnueabi-g++ -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mtune=cortex-a8 -Wno-gnu -fPIE --sysroot="C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/libxml2" -I"C:\tizen-sdk\library" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include" -I"C:/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
=======
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\Administrator\Documents\workspace\tizen\TizenGameHub\CardPair\inc" -I"C:\Users\Administrator\Documents\workspace\tizen\TizenGameHub\TizenGameHubLibrary\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target arm-tizen-linux-gnueabi -gcc-toolchain "C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/tools/smart-build-interface/../arm-linux-gnueabi-gcc-4.5/" -ccc-gcc-name arm-linux-gnueabi-g++ -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mtune=cortex-a8 -Wno-gnu -fPIE --sysroot="C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native" -I"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/libxml2" -I"C:\Users\Administrator\AppData\Local\Tizen\tizen-sdk\library" -I"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include" -I"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
>>>>>>> d50772aa5b31aad78637807e2c4fd23097705a0c
	@echo 'Finished building: $<'
	@echo ' '


