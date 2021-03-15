EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5300 4350 5900 4350
Wire Wire Line
	5900 3700 5900 3900
$Comp
L power:+3.3V #PWR?
U 1 1 603FFF1B
P 5900 3700
AR Path="/5F8674B3/603FFF1B" Ref="#PWR?"  Part="1" 
AR Path="/603FFF1B" Ref="#PWR?"  Part="1" 
AR Path="/603FCB6F/603FFF1B" Ref="#PWR06"  Part="1" 
F 0 "#PWR06" H 5900 3550 50  0001 C CNN
F 1 "+3.3V" H 5915 3873 50  0000 C CNN
F 2 "" H 5900 3700 50  0001 C CNN
F 3 "" H 5900 3700 50  0001 C CNN
	1    5900 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4350 5900 4200
Wire Wire Line
	5300 4250 5300 4350
$Comp
L Device:R R?
U 1 1 603FFF23
P 5900 4050
AR Path="/603FFF23" Ref="R?"  Part="1" 
AR Path="/603FCB6F/603FFF23" Ref="R8"  Part="1" 
F 0 "R8" H 5970 4096 50  0000 L CNN
F 1 "4k7" H 5970 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5830 4050 50  0001 C CNN
F 3 "" H 5900 4050 50  0001 C CNN
	1    5900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3400 5300 3350
Wire Wire Line
	4200 3400 5300 3400
Wire Wire Line
	4200 4050 4200 3400
Wire Wire Line
	4350 4050 4200 4050
Wire Wire Line
	4100 3150 4350 3150
Wire Wire Line
	4100 3700 4100 3150
Wire Wire Line
	5300 3700 4100 3700
Wire Wire Line
	5300 3850 5300 3700
Wire Wire Line
	4650 4050 5000 4050
Wire Wire Line
	4650 3150 5000 3150
$Comp
L Device:R R?
U 1 1 603FFF33
P 4500 4050
AR Path="/603FFF33" Ref="R?"  Part="1" 
AR Path="/603FCB6F/603FFF33" Ref="R7"  Part="1" 
F 0 "R7" V 4293 4050 50  0000 C CNN
F 1 "R" V 4384 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4430 4050 50  0001 C CNN
F 3 "" H 4500 4050 50  0001 C CNN
	1    4500 4050
	0    1    1    0   
$EndComp
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 603FFF39
P 5200 4050
AR Path="/603FFF39" Ref="Q?"  Part="1" 
AR Path="/603FCB6F/603FFF39" Ref="Q2"  Part="1" 
F 0 "Q2" H 5391 4096 50  0000 L CNN
F 1 "Q_NPN_BCE" H 5391 4005 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5400 4150 50  0001 C CNN
F 3 "~" H 5200 4050 50  0001 C CNN
	1    5200 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 603FFF3F
P 5200 3150
AR Path="/603FFF3F" Ref="Q?"  Part="1" 
AR Path="/603FCB6F/603FFF3F" Ref="Q1"  Part="1" 
F 0 "Q1" H 5391 3196 50  0000 L CNN
F 1 "Q_NPN_BCE" H 5391 3105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5400 3250 50  0001 C CNN
F 3 "~" H 5200 3150 50  0001 C CNN
	1    5200 3150
	1    0    0    -1  
$EndComp
Text HLabel 6200 2950 2    50   Output ~ 0
Reset
Text HLabel 6200 4350 2    50   Output ~ 0
GPIO0
Text HLabel 3600 3150 0    50   Input ~ 0
DTR
Text HLabel 3600 4050 0    50   Input ~ 0
RTS
$Comp
L Device:R R?
U 1 1 603FFF45
P 4500 3150
AR Path="/603FFF45" Ref="R?"  Part="1" 
AR Path="/603FCB6F/603FFF45" Ref="R6"  Part="1" 
F 0 "R6" V 4293 3150 50  0000 C CNN
F 1 "10k" V 4384 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4430 3150 50  0001 C CNN
F 3 "" H 4500 3150 50  0001 C CNN
	1    4500 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 4350 5900 4350
Connection ~ 5900 4350
Wire Wire Line
	3600 4050 4200 4050
Connection ~ 4200 4050
Wire Wire Line
	3600 3150 4100 3150
Connection ~ 4100 3150
Wire Wire Line
	6200 2950 5300 2950
$EndSCHEMATC
