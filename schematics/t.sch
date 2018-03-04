EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:microchip_pic18mcu
LIBS:switches
LIBS:long_count-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 14 21
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4450 3500 0    60   Input ~ 0
In
$Comp
L +5V #PWR033
U 1 1 5A9D02F6
P 5600 3175
AR Path="/5A9CB9B5/5A9D02F6" Ref="#PWR033"  Part="1" 
AR Path="/5A9D1E97/5A9D02F6" Ref="#PWR034"  Part="1" 
AR Path="/5A9D20D1/5A9D02F6" Ref="#PWR035"  Part="1" 
AR Path="/5A9D2405/5A9D02F6" Ref="#PWR036"  Part="1" 
AR Path="/5A9D267B/5A9D02F6" Ref="#PWR037"  Part="1" 
AR Path="/5A9D359D/5A9D02F6" Ref="#PWR038"  Part="1" 
AR Path="/5A9D3E7F/5A9D02F6" Ref="#PWR039"  Part="1" 
AR Path="/5A9D3E83/5A9D02F6" Ref="#PWR040"  Part="1" 
AR Path="/5A9D5137/5A9D02F6" Ref="#PWR041"  Part="1" 
AR Path="/5A9D513B/5A9D02F6" Ref="#PWR042"  Part="1" 
AR Path="/5A9D513F/5A9D02F6" Ref="#PWR043"  Part="1" 
AR Path="/5A9D5143/5A9D02F6" Ref="#PWR044"  Part="1" 
AR Path="/5A9D57FD/5A9D02F6" Ref="#PWR045"  Part="1" 
AR Path="/5A9D5801/5A9D02F6" Ref="#PWR046"  Part="1" 
AR Path="/5A9D5805/5A9D02F6" Ref="#PWR047"  Part="1" 
AR Path="/5A9D5809/5A9D02F6" Ref="#PWR048"  Part="1" 
F 0 "#PWR048" H 5600 3025 50  0001 C CNN
F 1 "+5V" H 5600 3315 50  0000 C CNN
F 2 "" H 5600 3175 50  0001 C CNN
F 3 "" H 5600 3175 50  0001 C CNN
	1    5600 3175
	1    0    0    -1  
$EndComp
Wire Wire Line
	5075 3500 5300 3500
Wire Wire Line
	5600 3300 5600 3175
Text HLabel 5875 3950 2    60   Input ~ 0
Out
Wire Wire Line
	5600 3700 5600 3950
Wire Wire Line
	5600 3950 5875 3950
$Comp
L R R92
U 1 1 5A9D0418
P 4925 3500
AR Path="/5A9CB9B5/5A9D0418" Ref="R92"  Part="1" 
AR Path="/5A9D1E97/5A9D0418" Ref="R93"  Part="1" 
AR Path="/5A9D20D1/5A9D0418" Ref="R94"  Part="1" 
AR Path="/5A9D2405/5A9D0418" Ref="R95"  Part="1" 
AR Path="/5A9D267B/5A9D0418" Ref="R96"  Part="1" 
AR Path="/5A9D359D/5A9D0418" Ref="R97"  Part="1" 
AR Path="/5A9D3E7F/5A9D0418" Ref="R98"  Part="1" 
AR Path="/5A9D3E83/5A9D0418" Ref="R99"  Part="1" 
AR Path="/5A9D5137/5A9D0418" Ref="R100"  Part="1" 
AR Path="/5A9D513B/5A9D0418" Ref="R101"  Part="1" 
AR Path="/5A9D513F/5A9D0418" Ref="R102"  Part="1" 
AR Path="/5A9D5143/5A9D0418" Ref="R103"  Part="1" 
AR Path="/5A9D57FD/5A9D0418" Ref="R104"  Part="1" 
AR Path="/5A9D5801/5A9D0418" Ref="R105"  Part="1" 
AR Path="/5A9D5805/5A9D0418" Ref="R106"  Part="1" 
AR Path="/5A9D5809/5A9D0418" Ref="R107"  Part="1" 
F 0 "R107" V 5005 3500 50  0000 C CNN
F 1 "1K" V 4925 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 4855 3500 50  0001 C CNN
F 3 "" H 4925 3500 50  0001 C CNN
	1    4925 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	4775 3500 4450 3500
$Comp
L Q_PNP_BEC Q17
U 1 1 5AA1C45F
P 5500 3500
AR Path="/5A9CB9B5/5AA1C45F" Ref="Q17"  Part="1" 
AR Path="/5A9D1E97/5AA1C45F" Ref="Q18"  Part="1" 
AR Path="/5A9D20D1/5AA1C45F" Ref="Q19"  Part="1" 
AR Path="/5A9D2405/5AA1C45F" Ref="Q20"  Part="1" 
AR Path="/5A9D267B/5AA1C45F" Ref="Q21"  Part="1" 
AR Path="/5A9D359D/5AA1C45F" Ref="Q22"  Part="1" 
AR Path="/5A9D3E7F/5AA1C45F" Ref="Q23"  Part="1" 
AR Path="/5A9D3E83/5AA1C45F" Ref="Q24"  Part="1" 
AR Path="/5A9D5137/5AA1C45F" Ref="Q25"  Part="1" 
AR Path="/5A9D513B/5AA1C45F" Ref="Q26"  Part="1" 
AR Path="/5A9D513F/5AA1C45F" Ref="Q27"  Part="1" 
AR Path="/5A9D5143/5AA1C45F" Ref="Q28"  Part="1" 
AR Path="/5A9D57FD/5AA1C45F" Ref="Q29"  Part="1" 
AR Path="/5A9D5801/5AA1C45F" Ref="Q30"  Part="1" 
AR Path="/5A9D5805/5AA1C45F" Ref="Q31"  Part="1" 
AR Path="/5A9D5809/5AA1C45F" Ref="Q32"  Part="1" 
F 0 "Q32" H 5700 3550 50  0000 L CNN
F 1 "Q_PNP_BEC" H 5700 3450 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 5700 3600 50  0001 C CNN
F 3 "" H 5500 3500 50  0001 C CNN
	1    5500 3500
	1    0    0    1   
$EndComp
$EndSCHEMATC
