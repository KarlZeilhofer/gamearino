EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title "Gamearino"
Date "2020-10-13"
Rev "20.0.0-dev"
Comp "HTL-Steyr"
Comment1 "4ABHEL, 2020/2021"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L htl_modules:ESP-12F U1
U 1 1 5F8584F9
P 5750 3850
F 0 "U1" H 6200 4700 50  0000 C CNN
F 1 "ESP-12F" H 6100 4600 50  0000 C CNN
F 2 "htl_modules:ESP-12F" H 5750 3850 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 5400 3950 50  0001 C CNN
	1    5750 3850
	1    0    0    -1  
$EndComp
Text Notes 5950 2300 0    50   ~ 0
GPIO0 - Bootmode: \nlow=bootloader, \nhigh=flashboot
Text Notes 1050 750  0    50   ~ 0
TODO: SDA/SCL an ESP ausprobieren
Wire Wire Line
	6300 3350 6500 3350
Wire Wire Line
	6500 3350 6500 2800
Wire Wire Line
	6300 3450 6600 3450
$Sheet
S 4050 4600 950  550 
U 603CE165
F0 "Buttons" 50
F1 "buttons.sch" 50
F2 "C0" I R 5000 4750 50 
F3 "C1" I R 5000 4900 50 
F4 "C2" I R 5000 5050 50 
F5 "R0" O L 4050 4750 50 
F6 "R1" O L 4050 4900 50 
F7 "R2" O L 4050 5050 50 
$EndSheet
Wire Wire Line
	6600 4000 6600 4550
Wire Wire Line
	6600 4550 5100 4550
Wire Wire Line
	5100 4550 5100 3750
Wire Wire Line
	5100 3750 5200 3750
Wire Wire Line
	6600 3450 6600 2700
$Sheet
S 7100 3000 850  450 
U 603FCB6F
F0 "Auto-Reset" 50
F1 "autoreset.sch" 50
F2 "Reset" O L 7100 3150 50 
F3 "GPIO0" O L 7100 3300 50 
F4 "DTR" I R 7950 3150 50 
F5 "RTS" I R 7950 3300 50 
$EndSheet
Wire Wire Line
	6600 2700 8350 2700
Wire Wire Line
	6500 2800 8350 2800
$Sheet
S 8350 2600 650  850 
U 5F8D661A
F0 "USB" 50
F1 "usb.sch" 50
F2 "TxD" O L 8350 2700 50 
F3 "~DTR" O L 8350 3150 50 
F4 "~RTR" O L 8350 3300 50 
F5 "RxD" I L 8350 2800 50 
$EndSheet
Wire Wire Line
	7950 3150 8350 3150
Wire Wire Line
	7950 3300 8350 3300
Wire Wire Line
	7100 3150 5100 3150
Wire Wire Line
	5100 3150 5100 3350
Wire Wire Line
	5100 3350 5200 3350
Wire Wire Line
	7100 3300 6900 3300
Wire Wire Line
	6900 3300 6900 3750
Wire Wire Line
	6900 3750 6300 3750
$Comp
L Device:R R?
U 1 1 60405618
P 4900 3100
AR Path="/603CE165/60405618" Ref="R?"  Part="1" 
AR Path="/60405618" Ref="R1"  Part="1" 
F 0 "R1" H 4970 3146 50  0000 L CNN
F 1 "10k" H 4970 3055 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4830 3100 50  0001 C CNN
F 3 "~" H 4900 3100 50  0001 C CNN
	1    4900 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3550 4900 3550
Wire Wire Line
	4900 3550 4900 3250
$Comp
L power:+3.3V #PWR?
U 1 1 60406C3E
P 4900 2850
AR Path="/5F8674B3/60406C3E" Ref="#PWR?"  Part="1" 
AR Path="/60406C3E" Ref="#PWR01"  Part="1" 
AR Path="/603FCB6F/60406C3E" Ref="#PWR?"  Part="1" 
F 0 "#PWR01" H 4900 2700 50  0001 C CNN
F 1 "+3.3V" H 4915 3023 50  0000 C CNN
F 2 "" H 4900 2850 50  0001 C CNN
F 3 "" H 4900 2850 50  0001 C CNN
	1    4900 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2850 4900 2950
Wire Wire Line
	7100 3850 6300 3850
Wire Wire Line
	7100 4000 6600 4000
$Sheet
S 7100 3750 950  550 
U 5F8674B3
F0 "OLED 128x64" 50
F1 "oled.sch" 50
F2 "SDA" B L 7100 3850 50 
F3 "SCL" B L 7100 4000 50 
$EndSheet
$Comp
L Device:R R2
U 1 1 6040DF5C
P 6350 5350
F 0 "R2" H 6420 5396 50  0000 L CNN
F 1 "10k" H 6420 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6280 5350 50  0001 C CNN
F 3 "~" H 6350 5350 50  0001 C CNN
	1    6350 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3950 6300 3950
$Comp
L power:GND #PWR?
U 1 1 6040EFD2
P 6350 5550
AR Path="/5F8674B3/6040EFD2" Ref="#PWR?"  Part="1" 
AR Path="/6040EFD2" Ref="#PWR02"  Part="1" 
F 0 "#PWR02" H 6350 5300 50  0001 C CNN
F 1 "GND" H 6354 5395 50  0000 C CNN
F 2 "" H 6350 5550 50  0001 C CNN
F 3 "" H 6350 5550 50  0001 C CNN
	1    6350 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5550 6350 5500
Wire Wire Line
	6400 4900 6400 3650
Wire Wire Line
	6400 3650 6300 3650
Wire Wire Line
	6450 3550 6300 3550
Wire Wire Line
	5200 3650 3950 3650
Wire Wire Line
	3950 3650 3950 4750
Wire Wire Line
	5200 3850 3900 3850
Wire Wire Line
	3900 3850 3900 4900
Wire Wire Line
	5200 3950 3850 3950
Wire Wire Line
	3950 4750 4050 4750
Wire Wire Line
	3900 4900 4050 4900
Wire Wire Line
	4050 5050 3850 5050
Wire Wire Line
	3850 3950 3850 5050
Wire Wire Line
	6350 3950 6350 4750
Wire Wire Line
	5000 4750 6350 4750
Connection ~ 6350 4750
Wire Wire Line
	6350 4750 6350 5200
Wire Wire Line
	5000 4900 6400 4900
Wire Wire Line
	5000 5050 6450 5050
Wire Wire Line
	6450 3550 6450 5050
$Comp
L Mechanical:MountingHole H1
U 1 1 6048A1E2
P 10300 5750
F 0 "H1" H 10400 5796 50  0000 L CNN
F 1 "MountingHole" H 10400 5705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 10300 5750 50  0001 C CNN
F 3 "~" H 10300 5750 50  0001 C CNN
	1    10300 5750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 6048AB39
P 10300 5950
F 0 "H2" H 10400 5996 50  0000 L CNN
F 1 "MountingHole" H 10400 5905 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 10300 5950 50  0001 C CNN
F 3 "~" H 10300 5950 50  0001 C CNN
	1    10300 5950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 6048ACBF
P 10300 6150
F 0 "H3" H 10400 6196 50  0000 L CNN
F 1 "MountingHole" H 10400 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 10300 6150 50  0001 C CNN
F 3 "~" H 10300 6150 50  0001 C CNN
	1    10300 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 6048AE0B
P 10300 6350
F 0 "H4" H 10400 6396 50  0000 L CNN
F 1 "MountingHole" H 10400 6305 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 10300 6350 50  0001 C CNN
F 3 "~" H 10300 6350 50  0001 C CNN
	1    10300 6350
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 60461F5A
P 4800 4250
AR Path="/5F7F8851/5F7FB5B8/60461F5A" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/60461F5A" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/60461F5A" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/60461F5A" Ref="#PWR?"  Part="1" 
AR Path="/60461F5A" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 4800 4100 50  0001 C CNN
F 1 "+3V3" H 4815 4423 50  0000 C CNN
F 2 "" H 4800 4250 50  0001 C CNN
F 3 "" H 4800 4250 50  0001 C CNN
	1    4800 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4250 5200 4250
Wire Wire Line
	5200 4250 5200 4050
NoConn ~ 5200 3450
Text Notes 4000 2550 0    50   ~ 0
Enable Pin:\nmuss über 10k auf 3V3 liegen
Text Notes 6650 5450 0    50   ~ 0
GPIO15:\nmuss beim Booten über 10k\nauf GND liegen. Dann kann er\nverwendet werden. 
Text Notes 9150 4350 0    50   ~ 0
Arduino-IDE:\nProgrammierbar über die Standardeinstellungen\nfür ESP8266/NodeMCU V1.0
$Comp
L htl_virtual:Item Item1
U 1 1 60467F30
P 800 6300
F 0 "Item1" H 930 6346 50  0000 L CNN
F 1 "3D Druck: Knopf A" H 930 6255 50  0000 L CNN
F 2 "gamearino:ABKnopf" H 800 6230 50  0001 C CNN
F 3 "~" V 800 6300 50  0001 C CNN
	1    800  6300
	1    0    0    -1  
$EndComp
$Comp
L htl_virtual:Item Item2
U 1 1 6046831B
P 800 6500
F 0 "Item2" H 930 6546 50  0000 L CNN
F 1 "3D Druck: Knopf B" H 930 6455 50  0000 L CNN
F 2 "gamearino:ABKnopf" H 800 6430 50  0001 C CNN
F 3 "~" V 800 6500 50  0001 C CNN
	1    800  6500
	1    0    0    -1  
$EndComp
$Comp
L htl_virtual:Item Item3
U 1 1 6046859D
P 800 6700
F 0 "Item3" H 930 6746 50  0000 L CNN
F 1 "3D Druck: Knopf Start" H 930 6655 50  0000 L CNN
F 2 "gamearino:StartSelect" H 800 6630 50  0001 C CNN
F 3 "~" V 800 6700 50  0001 C CNN
	1    800  6700
	1    0    0    -1  
$EndComp
$Comp
L htl_virtual:Item Item4
U 1 1 60468899
P 800 6900
F 0 "Item4" H 930 6946 50  0000 L CNN
F 1 "3D Druck: Knopf Select" H 930 6855 50  0000 L CNN
F 2 "gamearino:StartSelect" H 800 6830 50  0001 C CNN
F 3 "~" V 800 6900 50  0001 C CNN
	1    800  6900
	1    0    0    -1  
$EndComp
$Comp
L htl_virtual:Item Item5
U 1 1 60469ECB
P 800 7100
F 0 "Item5" H 930 7146 50  0000 L CNN
F 1 "3D Druck: Steuerkreuz" H 930 7055 50  0000 L CNN
F 2 "gamearino:Steuerkreuz_zeik" H 800 7030 50  0001 C CNN
F 3 "~" V 800 7100 50  0001 C CNN
	1    800  7100
	1    0    0    -1  
$EndComp
$Comp
L htl_virtual:Item Item6
U 1 1 6046A8BB
P 800 7400
F 0 "Item6" H 930 7446 50  0000 L CNN
F 1 "PCB: Abmessungen?, 2 Layer, 35u Cu, d1,6mm" H 930 7355 50  0000 L CNN
F 2 "" H 800 7330 50  0001 C CNN
F 3 "~" V 800 7400 50  0001 C CNN
	1    800  7400
	1    0    0    -1  
$EndComp
$Comp
L htl_virtual:Item Item7
U 1 1 6046ADE9
P 800 7600
F 0 "Item7" H 930 7646 50  0000 L CNN
F 1 "SMD-Schablone: 120um, Edelstahl, 25mm Umlaufender Überstand" H 930 7555 50  0000 L CNN
F 2 "" H 800 7530 50  0001 C CNN
F 3 "~" V 800 7600 50  0001 C CNN
	1    800  7600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60538B2A
P 6750 4050
AR Path="/5F8674B3/60538B2A" Ref="#PWR?"  Part="1" 
AR Path="/60538B2A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6750 3800 50  0001 C CNN
F 1 "GND" H 6754 3895 50  0000 C CNN
F 2 "" H 6750 4050 50  0001 C CNN
F 3 "" H 6750 4050 50  0001 C CNN
	1    6750 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4050 6750 4050
NoConn ~ 5500 4450
NoConn ~ 5600 4450
NoConn ~ 5700 4450
NoConn ~ 5800 4450
NoConn ~ 5900 4450
NoConn ~ 6000 4450
Text Notes 7150 4700 0    50   ~ 0
TODO: SDA-Leitung macht \ndas Flashen aktuell unmöglich. 
Wire Notes Line
	7100 4600 6800 3850
$EndSCHEMATC