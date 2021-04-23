EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
L Switch:SW_Push_45deg SW2
U 1 1 603CE9C4
P 3500 3800
F 0 "SW2" H 3500 4081 50  0000 C CNN
F 1 "Up" H 3500 3990 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 3500 4000 50  0001 C CNN
F 3 "~" H 3500 4000 50  0001 C CNN
	1    3500 3800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg SW1
U 1 1 603D2E45
P 2700 4500
F 0 "SW1" H 2700 4311 50  0000 C CNN
F 1 "Left" H 2700 4220 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 2700 4700 50  0001 C CNN
F 3 "~" H 2700 4700 50  0001 C CNN
	1    2700 4500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg SW4
U 1 1 603D3ADD
P 4300 4450
F 0 "SW4" H 4300 4261 50  0000 C CNN
F 1 "Right" H 4300 4170 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 4300 4650 50  0001 C CNN
F 3 "~" H 4300 4650 50  0001 C CNN
	1    4300 4450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg SW3
U 1 1 603D44C1
P 3550 5450
F 0 "SW3" H 3550 5731 50  0000 C CNN
F 1 "Down" H 3550 5640 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 3550 5650 50  0001 C CNN
F 3 "~" H 3550 5650 50  0001 C CNN
	1    3550 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 603D526A
P 9000 3650
F 0 "R3" H 9070 3696 50  0000 L CNN
F 1 "10k" H 9070 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8930 3650 50  0001 C CNN
F 3 "~" H 9000 3650 50  0001 C CNN
	1    9000 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 603D5276
P 9000 3350
AR Path="/5F8674B3/603D5276" Ref="#PWR?"  Part="1" 
AR Path="/603D5276" Ref="#PWR?"  Part="1" 
AR Path="/603CE165/603D5276" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H 9000 3200 50  0001 C CNN
F 1 "+3.3V" H 9015 3523 50  0000 C CNN
F 2 "" H 9000 3350 50  0001 C CNN
F 3 "" H 9000 3350 50  0001 C CNN
	1    9000 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 3350 9000 3500
$Comp
L Switch:SW_Push_45deg SW5
U 1 1 603D6315
P 5200 2550
F 0 "SW5" H 5200 2831 50  0000 C CNN
F 1 "Select" H 5200 2740 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 5200 2750 50  0001 C CNN
F 3 "~" H 5200 2750 50  0001 C CNN
	1    5200 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg SW7
U 1 1 603D6F04
P 7350 4500
F 0 "SW7" H 7350 4781 50  0000 C CNN
F 1 "B" H 7350 4690 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 7350 4700 50  0001 C CNN
F 3 "~" H 7350 4700 50  0001 C CNN
	1    7350 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 603D6F0A
P 9400 3650
F 0 "R4" H 9470 3696 50  0000 L CNN
F 1 "10k" H 9470 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9330 3650 50  0001 C CNN
F 3 "~" H 9400 3650 50  0001 C CNN
	1    9400 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 603D6F16
P 9400 3350
AR Path="/5F8674B3/603D6F16" Ref="#PWR?"  Part="1" 
AR Path="/603D6F16" Ref="#PWR?"  Part="1" 
AR Path="/603CE165/603D6F16" Ref="#PWR04"  Part="1" 
F 0 "#PWR04" H 9400 3200 50  0001 C CNN
F 1 "+3.3V" H 9415 3523 50  0000 C CNN
F 2 "" H 9400 3350 50  0001 C CNN
F 3 "" H 9400 3350 50  0001 C CNN
	1    9400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 3350 9400 3500
$Comp
L Switch:SW_Push_45deg SW8
U 1 1 603D7C3B
P 7900 3450
F 0 "SW8" H 7900 3731 50  0000 C CNN
F 1 "A" H 7900 3640 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 7900 3650 50  0001 C CNN
F 3 "~" H 7900 3650 50  0001 C CNN
	1    7900 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 603D7C41
P 9800 3650
F 0 "R5" H 9870 3696 50  0000 L CNN
F 1 "10k" H 9870 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9730 3650 50  0001 C CNN
F 3 "~" H 9800 3650 50  0001 C CNN
	1    9800 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 603D7C4D
P 9800 3350
AR Path="/5F8674B3/603D7C4D" Ref="#PWR?"  Part="1" 
AR Path="/603D7C4D" Ref="#PWR?"  Part="1" 
AR Path="/603CE165/603D7C4D" Ref="#PWR05"  Part="1" 
F 0 "#PWR05" H 9800 3200 50  0001 C CNN
F 1 "+3.3V" H 9815 3523 50  0000 C CNN
F 2 "" H 9800 3350 50  0001 C CNN
F 3 "" H 9800 3350 50  0001 C CNN
	1    9800 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 3350 9800 3500
Text HLabel 2900 1000 0    50   Input ~ 0
C0
Text HLabel 4750 1000 0    50   Input ~ 0
C1
Text HLabel 7150 1000 0    50   Input ~ 0
C2
Text HLabel 10000 3900 2    50   Output ~ 0
R0
Text HLabel 10000 4000 2    50   Output ~ 0
R1
Text HLabel 10000 4100 2    50   Output ~ 0
R2
Wire Wire Line
	10000 4000 9400 4000
Wire Wire Line
	9400 3800 9400 4000
Connection ~ 9400 4000
Wire Wire Line
	10000 4100 9800 4100
Wire Wire Line
	9000 3800 9000 3900
Connection ~ 9000 3900
Wire Wire Line
	9000 3900 10000 3900
Wire Wire Line
	9800 3800 9800 4100
Connection ~ 9800 4100
$Comp
L Switch:SW_Push_45deg SW6
U 1 1 6041FBD1
P 6200 2550
F 0 "SW6" H 6450 2750 50  0000 C CNN
F 1 "Start" H 6500 2650 50  0000 C CNN
F 2 "htl_smd:SW_Push_5.1mm_H1.5mm" H 6200 2750 50  0001 C CNN
F 3 "~" H 6200 2750 50  0001 C CNN
	1    6200 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1000 2900 3700
Wire Wire Line
	3400 3700 2900 3700
Connection ~ 2900 3700
Wire Wire Line
	3450 5350 2900 5350
Wire Wire Line
	2900 3700 2900 4150
Wire Wire Line
	2600 4400 2600 4150
Wire Wire Line
	2600 4150 2900 4150
Connection ~ 2900 4150
Wire Wire Line
	2900 4150 2900 5350
Wire Wire Line
	3600 3900 5300 3900
Wire Wire Line
	3550 4000 3550 4600
Wire Wire Line
	3550 4600 2800 4600
Wire Wire Line
	3550 4000 6300 4000
Wire Wire Line
	3750 4100 3750 5550
Wire Wire Line
	3750 5550 3650 5550
Wire Wire Line
	3750 4100 6450 4100
Wire Wire Line
	4750 1000 4750 2150
Wire Wire Line
	5100 2450 4750 2450
Connection ~ 4750 2450
Wire Wire Line
	4200 4350 4200 4250
Wire Wire Line
	4200 4250 4750 4250
Wire Wire Line
	5300 2650 5300 3900
Connection ~ 5300 3900
Wire Wire Line
	5300 3900 8000 3900
Wire Wire Line
	6300 2650 6300 4000
Connection ~ 6300 4000
Wire Wire Line
	6300 4000 8100 4000
Wire Wire Line
	4400 4550 6450 4550
Wire Wire Line
	6450 4550 6450 4100
Connection ~ 6450 4100
Wire Wire Line
	6450 4100 9800 4100
Wire Wire Line
	7150 1000 7150 3350
Wire Wire Line
	7800 3350 7150 3350
Connection ~ 7150 3350
Wire Wire Line
	7150 3350 7150 4400
Wire Wire Line
	8000 3550 8000 3900
Connection ~ 8000 3900
Wire Wire Line
	8000 3900 9000 3900
Wire Wire Line
	7250 4400 7150 4400
Wire Wire Line
	7450 4600 8100 4600
Wire Wire Line
	8100 4600 8100 4000
Connection ~ 8100 4000
Wire Wire Line
	8100 4000 9400 4000
Wire Wire Line
	4750 2450 4750 4250
Wire Wire Line
	6100 2450 6100 2150
Wire Wire Line
	6100 2150 4750 2150
Connection ~ 4750 2150
Wire Wire Line
	4750 2150 4750 2450
$EndSCHEMATC
