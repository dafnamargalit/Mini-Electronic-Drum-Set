################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /Applications/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./UARTDriver.obj" \
"./main.obj" \
"./startup_msp432p401r_ccs.obj" \
"./system_msp432p401r.obj" \
"./voltageToAudio.obj" \
"./driverlib/adc14.obj" \
"./driverlib/aes256.obj" \
"./driverlib/comp_e.obj" \
"./driverlib/cpu.obj" \
"./driverlib/crc32.obj" \
"./driverlib/cs.obj" \
"./driverlib/dma.obj" \
"./driverlib/flash.obj" \
"./driverlib/flash_a.obj" \
"./driverlib/fpu.obj" \
"./driverlib/gpio.obj" \
"./driverlib/i2c.obj" \
"./driverlib/interrupt.obj" \
"./driverlib/lcd_f.obj" \
"./driverlib/mpu.obj" \
"./driverlib/pcm.obj" \
"./driverlib/pmap.obj" \
"./driverlib/pss.obj" \
"./driverlib/ref_a.obj" \
"./driverlib/reset.obj" \
"./driverlib/rtc_c.obj" \
"./driverlib/spi.obj" \
"./driverlib/sysctl.obj" \
"./driverlib/sysctl_a.obj" \
"./driverlib/systick.obj" \
"./driverlib/timer32.obj" \
"./driverlib/timer_a.obj" \
"./driverlib/uart.obj" \
"./driverlib/wdt_a.obj" \
"../msp432p401r.cmd" \
"../driverlib/ccs/msp432p4xx_driverlib.lib" \
"../driverlib/keil/msp432p4xx_driverlib.lib" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include driverlib/subdir_vars.mk
-include driverlib/ccs/subdir_vars.mk
-include driverlib/gcc/subdir_vars.mk
-include driverlib/iar/subdir_vars.mk
-include driverlib/keil/subdir_vars.mk
-include subdir_rules.mk
-include driverlib/subdir_rules.mk
-include driverlib/ccs/subdir_rules.mk
-include driverlib/gcc/subdir_rules.mk
-include driverlib/iar/subdir_rules.mk
-include driverlib/keil/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
ecen2440_project.out \

EXE_OUTPUTS__QUOTED += \
"ecen2440_project.out" \

BIN_OUTPUTS += \
ecen2440_project.hex \

BIN_OUTPUTS__QUOTED += \
"ecen2440_project.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(A_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "ecen2440_project.out"

# Tool invocations
ecen2440_project.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(A_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"/Applications/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"ecen2440_project.map" --heap_size=1024 --stack_size=512 -i"/Applications/ccs/ccs_base/arm/include" -i"/Applications/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/lib" -i"/Applications/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="ecen2440_project_linkInfo.xml" --rom_model -o "ecen2440_project.out" $(ORDERED_OBJS) $(A_SRCS)
	@echo 'Finished building target: "$@"'
	@echo ' '

ecen2440_project.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"/Applications/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armhex" --memwidth=8 --romwidth=8 -o "ecen2440_project.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "UARTDriver.obj" "main.obj" "startup_msp432p401r_ccs.obj" "system_msp432p401r.obj" "voltageToAudio.obj" "driverlib/adc14.obj" "driverlib/aes256.obj" "driverlib/comp_e.obj" "driverlib/cpu.obj" "driverlib/crc32.obj" "driverlib/cs.obj" "driverlib/dma.obj" "driverlib/flash.obj" "driverlib/flash_a.obj" "driverlib/fpu.obj" "driverlib/gpio.obj" "driverlib/i2c.obj" "driverlib/interrupt.obj" "driverlib/lcd_f.obj" "driverlib/mpu.obj" "driverlib/pcm.obj" "driverlib/pmap.obj" "driverlib/pss.obj" "driverlib/ref_a.obj" "driverlib/reset.obj" "driverlib/rtc_c.obj" "driverlib/spi.obj" "driverlib/sysctl.obj" "driverlib/sysctl_a.obj" "driverlib/systick.obj" "driverlib/timer32.obj" "driverlib/timer_a.obj" "driverlib/uart.obj" "driverlib/wdt_a.obj" 
	-$(RM) "UARTDriver.d" "main.d" "startup_msp432p401r_ccs.d" "system_msp432p401r.d" "voltageToAudio.d" "driverlib/adc14.d" "driverlib/aes256.d" "driverlib/comp_e.d" "driverlib/cpu.d" "driverlib/crc32.d" "driverlib/cs.d" "driverlib/dma.d" "driverlib/flash.d" "driverlib/flash_a.d" "driverlib/fpu.d" "driverlib/gpio.d" "driverlib/i2c.d" "driverlib/interrupt.d" "driverlib/lcd_f.d" "driverlib/mpu.d" "driverlib/pcm.d" "driverlib/pmap.d" "driverlib/pss.d" "driverlib/ref_a.d" "driverlib/reset.d" "driverlib/rtc_c.d" "driverlib/spi.d" "driverlib/sysctl.d" "driverlib/sysctl_a.d" "driverlib/systick.d" "driverlib/timer32.d" "driverlib/timer_a.d" "driverlib/uart.d" "driverlib/wdt_a.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

