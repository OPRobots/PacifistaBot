EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:arduino_nano
LIBS:Arduino_Nano-cache
LIBS:step_down_chino
LIBS:PCB_pacifista-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Arduino_Nano A1
U 1 1 5BAF954A
P 5550 3400
F 0 "A1" H 5550 3400 60  0000 C CNN
F 1 "Arduino_Nano" H 5550 3550 60  0000 C CNN
F 2 "libraries:arduino_nano" H 5550 3400 60  0001 C CNN
F 3 "" H 5550 3400 60  0000 C CNN
	1    5550 3400
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5BAF978B
P 6650 4750
F 0 "R1" V 6730 4750 50  0000 C CNN
F 1 "R" V 6650 4750 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6580 4750 50  0001 C CNN
F 3 "" H 6650 4750 50  0001 C CNN
	1    6650 4750
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5BAF989C
P 6900 4900
F 0 "R2" V 6980 4900 50  0000 C CNN
F 1 "R" V 6900 4900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6830 4900 50  0001 C CNN
F 3 "" H 6900 4900 50  0001 C CNN
	1    6900 4900
	1    0    0    -1  
$EndComp
NoConn ~ 6250 3650
$Comp
L D D1
U 1 1 5BAFA8B3
P 6950 2350
F 0 "D1" H 6950 2450 50  0000 C CNN
F 1 "D" H 6950 2250 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P7.62mm_Horizontal" H 6950 2350 50  0001 C CNN
F 3 "" H 6950 2350 50  0001 C CNN
	1    6950 2350
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR01
U 1 1 5BAFAB4B
P 7150 2250
F 0 "#PWR01" H 7150 2000 50  0001 C CNN
F 1 "GND" H 7150 2100 50  0000 C CNN
F 2 "" H 7150 2250 50  0001 C CNN
F 3 "" H 7150 2250 50  0001 C CNN
	1    7150 2250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5BAFAC34
P 4800 4350
F 0 "#PWR02" H 4800 4100 50  0001 C CNN
F 1 "GND" H 4800 4200 50  0000 C CNN
F 2 "" H 4800 4350 50  0001 C CNN
F 3 "" H 4800 4350 50  0001 C CNN
	1    4800 4350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR03
U 1 1 5BAFACCE
P 8800 1900
F 0 "#PWR03" H 8800 1650 50  0001 C CNN
F 1 "GND" H 8800 1750 50  0000 C CNN
F 2 "" H 8800 1900 50  0001 C CNN
F 3 "" H 8800 1900 50  0001 C CNN
	1    8800 1900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR04
U 1 1 5BAFB7D2
P 6800 5050
F 0 "#PWR04" H 6800 4800 50  0001 C CNN
F 1 "GND" H 6800 4900 50  0000 C CNN
F 2 "" H 6800 5050 50  0001 C CNN
F 3 "" H 6800 5050 50  0001 C CNN
	1    6800 5050
	0    1    1    0   
$EndComp
NoConn ~ 4900 2950
NoConn ~ 4900 3100
NoConn ~ 4900 3550
$Comp
L Conn_01x03 J9
U 1 1 5BAFBF4A
P 8700 5150
F 0 "J9" H 8700 5350 50  0000 C CNN
F 1 "Conn_01x03" H 8700 4950 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 8700 5150 50  0001 C CNN
F 3 "" H 8700 5150 50  0001 C CNN
	1    8700 5150
	0    1    1    0   
$EndComp
$Comp
L Conn_01x03 J15
U 1 1 5BAFC065
P 8700 5600
F 0 "J15" H 8700 5800 50  0000 C CNN
F 1 "Conn_01x03" H 8700 5400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 8700 5600 50  0001 C CNN
F 3 "" H 8700 5600 50  0001 C CNN
	1    8700 5600
	0    1    1    0   
$EndComp
$Comp
L Conn_01x03 J4
U 1 1 5BAFD664
P 6550 3450
F 0 "J4" H 6550 3650 50  0000 C CNN
F 1 "Conn_01x03" H 6550 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 6550 3450 50  0001 C CNN
F 3 "" H 6550 3450 50  0001 C CNN
	1    6550 3450
	1    0    0    -1  
$EndComp
NoConn ~ 8600 5400
NoConn ~ 8600 4950
NoConn ~ 6350 2550
$Comp
L CP C1
U 1 1 5BD4AAE4
P 8550 3900
F 0 "C1" H 8575 4000 50  0000 L CNN
F 1 "CP" H 8575 3800 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P5.00mm" H 8588 3750 50  0001 C CNN
F 3 "" H 8550 3900 50  0001 C CNN
	1    8550 3900
	0    -1   -1   0   
$EndComp
$Comp
L Step_down_chino U1
U 1 1 5BD4B28B
P 3700 2750
F 0 "U1" H 3700 2800 60  0000 C CNN
F 1 "Step_down_chino" H 3700 3050 60  0000 C CNN
F 2 "Librerias manu:Step_down_chino" H 3700 2800 60  0001 C CNN
F 3 "" H 3700 2800 60  0001 C CNN
	1    3700 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5BD4BA69
P 3050 2600
F 0 "#PWR05" H 3050 2350 50  0001 C CNN
F 1 "GND" H 3050 2450 50  0000 C CNN
F 2 "" H 3050 2600 50  0001 C CNN
F 3 "" H 3050 2600 50  0001 C CNN
	1    3050 2600
	0    1    1    0   
$EndComp
$Comp
L GND #PWR06
U 1 1 5BD4BA83
P 4350 2450
F 0 "#PWR06" H 4350 2200 50  0001 C CNN
F 1 "GND" H 4350 2300 50  0000 C CNN
F 2 "" H 4350 2450 50  0001 C CNN
F 3 "" H 4350 2450 50  0001 C CNN
	1    4350 2450
	0    1    1    0   
$EndComp
NoConn ~ 4900 2750
$Comp
L +BATT #PWR07
U 1 1 5BD4BF72
P 2200 4650
F 0 "#PWR07" H 2200 4500 50  0001 C CNN
F 1 "+BATT" H 2200 4790 50  0000 C CNN
F 2 "" H 2200 4650 50  0001 C CNN
F 3 "" H 2200 4650 50  0001 C CNN
	1    2200 4650
	0    -1   -1   0   
$EndComp
Text Label 3750 4650 0    60   ~ 0
Alimentación
Text Label 8100 1900 2    60   ~ 0
Alimentación
Text Label 3050 2850 2    60   ~ 0
Alimentación
$Comp
L Conn_01x06 J5
U 1 1 5BD4D782
P 9100 2100
F 0 "J5" H 9100 2400 50  0000 C CNN
F 1 "Conn_01x06" H 9100 1700 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 9100 2100 50  0001 C CNN
F 3 "" H 9100 2100 50  0001 C CNN
	1    9100 2100
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x06 J11
U 1 1 5BD4D9B5
P 8400 2100
F 0 "J11" H 8400 2400 50  0000 C CNN
F 1 "Conn_01x06" H 8400 1700 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 8400 2100 50  0001 C CNN
F 3 "" H 8400 2100 50  0001 C CNN
	1    8400 2100
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x06 J12
U 1 1 5BD4DB21
P 8400 3000
F 0 "J12" H 8400 3300 50  0000 C CNN
F 1 "Conn_01x06" H 8400 2600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 8400 3000 50  0001 C CNN
F 3 "" H 8400 3000 50  0001 C CNN
	1    8400 3000
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x06 J6
U 1 1 5BD4DBA6
P 9100 3000
F 0 "J6" H 9100 3300 50  0000 C CNN
F 1 "Conn_01x06" H 9100 2600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 9100 3000 50  0001 C CNN
F 3 "" H 9100 3000 50  0001 C CNN
	1    9100 3000
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x06 J3
U 1 1 5BD4DE5C
P 6550 3950
F 0 "J3" H 6550 4250 50  0000 C CNN
F 1 "Conn_01x06" H 6550 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 6550 3950 50  0001 C CNN
F 3 "" H 6550 3950 50  0001 C CNN
	1    6550 3950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x06 J2
U 1 1 5BD4E081
P 6550 2950
F 0 "J2" H 6550 3250 50  0000 C CNN
F 1 "Conn_01x06" H 6550 2550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 6550 2950 50  0001 C CNN
F 3 "" H 6550 2950 50  0001 C CNN
	1    6550 2950
	1    0    0    -1  
$EndComp
NoConn ~ 6350 2650
NoConn ~ 6350 4350
$Comp
L Conn_01x06 J1
U 1 1 5BD4E6D2
P 7350 2250
F 0 "J1" H 7350 2550 50  0000 C CNN
F 1 "Conn_01x06" H 7350 1850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 7350 2250 50  0001 C CNN
F 3 "" H 7350 2250 50  0001 C CNN
	1    7350 2250
	1    0    0    -1  
$EndComp
NoConn ~ 7150 2050
NoConn ~ 7150 2550
$Comp
L CP C2
U 1 1 5BD4EA88
P 4350 3600
F 0 "C2" H 4375 3700 50  0000 L CNN
F 1 "CP" H 4375 3500 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P3.80mm" H 4388 3450 50  0001 C CNN
F 3 "" H 4350 3600 50  0001 C CNN
	1    4350 3600
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J7
U 1 1 5BD4ED64
P 2900 4650
F 0 "J7" H 2900 4750 50  0000 C CNN
F 1 "Conn_01x01" H 2900 4550 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1-5mmDrill" H 2900 4650 50  0001 C CNN
F 3 "" H 2900 4650 50  0001 C CNN
	1    2900 4650
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J8
U 1 1 5BD4EE0F
P 3350 4650
F 0 "J8" H 3350 4750 50  0000 C CNN
F 1 "Conn_01x01" H 3350 4550 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1-5mmDrill" H 3350 4650 50  0001 C CNN
F 3 "" H 3350 4650 50  0001 C CNN
	1    3350 4650
	-1   0    0    1   
$EndComp
Wire Wire Line
	6250 2950 6350 2950
Wire Wire Line
	6250 3050 6350 3050
Wire Wire Line
	6250 3150 6350 3150
Wire Wire Line
	6250 3250 6350 3250
Wire Wire Line
	6250 3350 6350 3350
Wire Wire Line
	6250 3450 6350 3450
Wire Wire Line
	6250 3550 6350 3550
Wire Wire Line
	6250 3750 6350 3750
Wire Wire Line
	6250 3850 6350 3850
Wire Wire Line
	6250 3950 6350 3950
Wire Wire Line
	6250 4050 6350 4050
Wire Wire Line
	6250 4150 6350 4150
Wire Wire Line
	6250 4250 6350 4250
Wire Wire Line
	6250 4350 6350 4350
Wire Wire Line
	6250 2750 6350 2750
Wire Wire Line
	6250 2850 6350 2850
Wire Wire Line
	6250 2550 6350 2550
Wire Wire Line
	6250 2650 6350 2650
Wire Wire Line
	6250 2450 7150 2450
Wire Wire Line
	6250 2350 6800 2350
Wire Wire Line
	7100 2350 7150 2350
Wire Wire Line
	4650 2150 7150 2150
Wire Wire Line
	8800 1900 8900 1900
Connection ~ 8900 2000
Connection ~ 8900 2100
Connection ~ 8900 2200
Connection ~ 8900 2300
Connection ~ 8900 2400
Connection ~ 8900 2500
Connection ~ 8900 2800
Connection ~ 8900 2900
Connection ~ 8900 3000
Connection ~ 8900 3100
Connection ~ 8900 3200
Connection ~ 8900 3300
Wire Wire Line
	8100 1900 8200 1900
Connection ~ 8200 2000
Connection ~ 8200 2100
Connection ~ 8200 2200
Connection ~ 8200 2300
Connection ~ 8200 2400
Connection ~ 8200 2500
Connection ~ 8200 2800
Connection ~ 8200 2900
Connection ~ 8200 3000
Connection ~ 8200 3100
Connection ~ 8200 3200
Connection ~ 8200 3300
Wire Wire Line
	6250 4450 6850 4450
Wire Wire Line
	6850 4450 6850 4750
Wire Wire Line
	6800 4750 6900 4750
Connection ~ 6850 4750
Wire Wire Line
	4800 4350 4900 4350
Wire Wire Line
	4900 4300 4900 4400
Connection ~ 4900 4350
Wire Wire Line
	6800 5050 6900 5050
Wire Wire Line
	4250 2850 4900 2850
Connection ~ 8900 3400
Connection ~ 8200 3400
Wire Wire Line
	8200 4900 8700 4900
Wire Wire Line
	8700 4900 8700 4950
Wire Wire Line
	2500 5350 8700 5350
Wire Wire Line
	8700 5350 8700 5400
Wire Wire Line
	8900 4950 8800 4950
Wire Wire Line
	8900 5400 8800 5400
Connection ~ 8900 4950
Wire Wire Line
	8900 1900 8900 5400
Wire Wire Line
	8200 3900 8400 3900
Connection ~ 8200 3900
Wire Wire Line
	8700 3900 8900 3900
Connection ~ 8900 3900
Wire Wire Line
	3050 2850 3150 2850
Wire Wire Line
	3050 2600 3150 2600
Wire Wire Line
	4350 2450 4450 2450
Wire Wire Line
	4450 2450 4450 2600
Wire Wire Line
	4450 2600 4250 2600
Wire Wire Line
	3750 4650 3550 4650
Wire Wire Line
	2700 4650 2200 4650
Wire Wire Line
	4650 2150 4650 2850
Connection ~ 4650 2850
Connection ~ 8900 1900
Wire Wire Line
	4350 3450 4350 2850
Connection ~ 4350 2850
Wire Wire Line
	4350 3750 4350 4100
Wire Wire Line
	4350 4100 4900 4100
Wire Wire Line
	4900 4100 4900 4350
Connection ~ 8200 1900
Wire Wire Line
	8200 4900 8200 5350
Wire Wire Line
	2500 5350 2500 4650
Connection ~ 2500 4650
Connection ~ 8200 5350
Wire Wire Line
	8200 1900 8200 3900
Connection ~ 3650 4650
Wire Wire Line
	6500 4750 3650 4750
Wire Wire Line
	3650 4750 3650 4650
$EndSCHEMATC
