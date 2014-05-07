################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk
CPP_DEPS += ./pch/tizenx.h.pch.d

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pre-build main-build

# Main-build Target
main-build: CardPair.exe secondary-outputs

# Tool invocations
CardPair.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: C++ Linker'
	clang++.exe -o"CardPair.exe" $(OBJS) $(USER_OBJS) $(LIBS) -L"C:\Users\Administrator\Documents\workspace\tizen\CardPair\lib" -target arm-tizen-linux-gnueabi -gcc-toolchain "C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/tools/smart-build-interface/../arm-linux-gnueabi-gcc-4.5/" -ccc-gcc-name arm-linux-gnueabi-g++ -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mtune=cortex-a8 -Xlinker --as-needed -pie -lpthread -Xlinker -rpath="/opt/usr/apps/riQlIAKKYh/lib" -Xlinker -rpath="/home/developer/sdk_tools/lib" --sysroot="C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native" -L"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/lib" -L"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/lib/osp" -losp-uifw -losp-appfw -losp-image -losp-json -losp-ime -losp-net -lpthread -losp-content -losp-locations -losp-telephony -losp-uix -losp-media -losp-messaging -losp-web -losp-social -losp-wifi -losp-bluetooth -losp-nfc -losp-face -losp-secure-element -losp-speech-tts -losp-shell -losp-shell-core -losp-speech-stt -losp-vision -lxml2 -lalut -lopenal
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./pch/tizenx.h.pch.d ./pch/tizenx.h.pch
	-$(RM) $(MO_FILES)$(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(EDJ_FILES)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) CardPair.exe
	-@echo ' '

pre-build:
	-cp -rf C:\Users\Administrator\Documents\workspace\tizen\TizenGameHub\TizenGameHubLibrary\Debug\libTizenGameHubLibrary.so C:\Users\Administrator\Documents\workspace\tizen\CardPair\lib
	-@echo ' '

secondary-outputs: $(MO_FILES) $(EDJ_FILES)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets

$(OBJS):%.o:pch/tizenx.h.pch

pch/tizenx.h.pch: ../inc/tizenx.h
	@echo 'Building file: $<'
	@echo 'Generate pch file'
	clang++.exe -I"pch" -D_DEBUG -I"C:\Users\Administrator\Documents\workspace\tizen\CardPair\inc" -I"C:\Users\Administrator\Documents\workspace\tizen\TizenGameHub\TizenGameHubLibrary\inc" -O0 -g3 -Wall -c -fmessage-length=0 -target arm-tizen-linux-gnueabi -gcc-toolchain "C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/tools/smart-build-interface/../arm-linux-gnueabi-gcc-4.5/" -ccc-gcc-name arm-linux-gnueabi-g++ -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mtune=cortex-a8 -Wno-gnu -fPIE --sysroot="C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native" -I"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/libxml2" -I"C:\Users\Administrator\AppData\Local\Tizen\tizen-sdk\library" -I"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include" -I"C:/Users/Administrator/AppData/Local/Tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"./pch/tizenx.h.pch.d" -MT"./pch/tizenx.h.pch.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

