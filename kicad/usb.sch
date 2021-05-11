EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title "Gamearino"
Date "2021-05-11"
Rev "V20.0.3"
Comp "HTL-Steyr"
Comment1 "4ABHEL, 2020/2021"
Comment2 "Hosted by Prof. Karl Zeilhofer"
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2250 3100 2250 3150
Wire Wire Line
	2250 3300 2250 3350
Wire Wire Line
	2250 3150 3050 3150
Wire Wire Line
	3050 3150 3200 3300
Wire Wire Line
	3200 3300 3950 3300
Connection ~ 2250 3150
Wire Wire Line
	2250 3150 2250 3200
Wire Wire Line
	3950 3200 3200 3200
Wire Wire Line
	3200 3200 3050 3350
Wire Wire Line
	3050 3350 2250 3350
Connection ~ 2250 3350
Wire Wire Line
	2250 3350 2250 3400
Wire Wire Line
	1650 4200 1650 4150
Wire Wire Line
	4350 4150 4350 3900
$Comp
L Device:C C?
U 1 1 5F711A46
P 4650 2400
AR Path="/5F64F622/5F711A46" Ref="C?"  Part="1" 
AR Path="/5F78AFC8/5F711A46" Ref="C?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F711A46" Ref="C?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F711A46" Ref="C?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F711A46" Ref="C?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F711A46" Ref="C?"  Part="1" 
AR Path="/5F8D661A/5F711A46" Ref="C2"  Part="1" 
F 0 "C2" V 4398 2400 50  0000 C CNN
F 1 "100n" V 4489 2400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4688 2250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811151136_Walsin-Tech-Corp-0603B104K160CT_C80516.pdf" H 4650 2400 50  0001 C CNN
F 4 "LCSC" H 4650 2400 50  0001 C CNN "Distributor"
F 5 "Walsin Tech Corp" H 4650 2400 50  0001 C CNN "Manufacturer"
F 6 "100nF ±10% 16V X7R" H 4650 2400 50  0001 C CNN "Notes"
F 7 "" H 4650 2400 50  0001 C CNN "OrderNr"
F 8 "" H 4650 2400 50  0001 C CNN "PartNr"
F 9 "0.002141" H 4650 2400 50  0001 C CNN "PriceEUR"
F 10 "500" H 4650 2400 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Walsin-Tech-Corp-0603B104K160CT_C80516.html" H 4650 2400 50  0001 C CNN "Weblink"
F 12 "C80516" H 4650 2400 50  0001 C CNN "DistOrderNr"
F 13 "0603B104K160CT" H 4650 2400 50  0001 C CNN "ManPartNr"
	1    4650 2400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F7120DC
P 4900 2400
AR Path="/5F64F622/5F7120DC" Ref="#PWR?"  Part="1" 
AR Path="/5F78AFC8/5F7120DC" Ref="#PWR?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F7120DC" Ref="#PWR?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F7120DC" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F7120DC" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F7120DC" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/5F7120DC" Ref="#PWR016"  Part="1" 
F 0 "#PWR016" H 4900 2150 50  0001 C CNN
F 1 "GND" V 4905 2272 50  0000 R CNN
F 2 "" H 4900 2400 50  0001 C CNN
F 3 "" H 4900 2400 50  0001 C CNN
	1    4900 2400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4900 2400 4800 2400
Wire Wire Line
	4500 2400 4350 2400
Connection ~ 4350 2400
Wire Wire Line
	4350 2400 4350 2700
$Comp
L htl_ics:CH340C U?
U 1 1 5F715116
P 4350 3300
AR Path="/5F64F622/5F715116" Ref="U?"  Part="1" 
AR Path="/5F78AFC8/5F715116" Ref="U?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F715116" Ref="U?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F715116" Ref="U?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F715116" Ref="U?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F715116" Ref="U?"  Part="1" 
AR Path="/5F8D661A/5F715116" Ref="U2"  Part="1" 
F 0 "U2" H 3950 3900 50  0000 C CNN
F 1 "CH340C" H 4550 2750 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 4400 2750 50  0001 L CNN
F 3 "http://www.datasheet5.com/pdf-local-2195953" H 4000 4100 50  0001 C CNN
F 4 "WCH(Jiangsu Qin Heng)" H 4350 3300 50  0001 C CNN "Manufacturer"
F 5 "LCSC" H 4350 3300 50  0001 C CNN "Distributor"
F 6 "C84681" H 4350 3300 50  0001 C CNN "DistOrderNr"
F 7 "0.239" H 4350 3300 50  0001 C CNN "PriceEUR"
F 8 "100" H 4350 3300 50  0001 C CNN "PriceForQty"
F 9 "https://lcsc.com/product-detail/USB-ICs_WCH-Jiangsu-Qin-Heng-CH340C_C84681.html" H 4350 3300 50  0001 C CNN "Weblink"
F 10 "CH340C" H 4350 3300 50  0001 C CNN "ManPartNr"
F 11 "USB-UART with internal clock" H 4350 3300 50  0001 C CNN "Notes"
	1    4350 3300
	1    0    0    -1  
$EndComp
NoConn ~ 3950 3700
$Comp
L Device:R R?
U 1 1 5F764796
P 3750 3000
AR Path="/5F64F622/5F764796" Ref="R?"  Part="1" 
AR Path="/5F78AFC8/5F764796" Ref="R?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F764796" Ref="R?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F764796" Ref="R?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F764796" Ref="R?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F764796" Ref="R?"  Part="1" 
AR Path="/5F8D661A/5F764796" Ref="R11"  Part="1" 
F 0 "R11" V 3543 3000 50  0000 C CNN
F 1 "100R" V 3634 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3680 3000 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Uniroyal-Elec-0603WAJ0101T5E_C25201.pdf" H 3750 3000 50  0001 C CNN
F 4 "C103204" H 3750 3000 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 3750 3000 50  0001 C CNN "Distributor"
F 6 "RTT03101JTP" H 3750 3000 50  0001 C CNN "ManPartNr"
F 7 "RALEC" H 3750 3000 50  0001 C CNN "Manufacturer"
F 8 "100Ω ±5% 0.1W ±100ppm/℃" H 3750 3000 50  0001 C CNN "Notes"
F 9 "0.0015" H 3750 3000 50  0001 C CNN "PriceEUR"
F 10 "100" H 3750 3000 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAJ0101T5E_C25201.html" H 3750 3000 50  0001 C CNN "Weblink"
	1    3750 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 3000 3950 3000
$Comp
L power:GND #PWR?
U 1 1 5F764C96
P 3450 3000
AR Path="/5F64F622/5F764C96" Ref="#PWR?"  Part="1" 
AR Path="/5F78AFC8/5F764C96" Ref="#PWR?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F764C96" Ref="#PWR?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F764C96" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F764C96" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F764C96" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/5F764C96" Ref="#PWR012"  Part="1" 
F 0 "#PWR012" H 3450 2750 50  0001 C CNN
F 1 "GND" H 3455 2827 50  0000 C CNN
F 2 "" H 3450 3000 50  0001 C CNN
F 3 "" H 3450 3000 50  0001 C CNN
	1    3450 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 3000 3600 3000
Text HLabel 5700 2900 2    50   Output ~ 0
TxD
Text HLabel 5050 3600 2    50   Output ~ 0
~DTR
Text HLabel 5050 3700 2    50   Output ~ 0
~RTR
Text HLabel 5700 3000 2    50   Input ~ 0
RxD
Wire Wire Line
	4750 2900 5100 2900
Wire Wire Line
	4750 3000 5100 3000
Wire Wire Line
	4750 3600 5050 3600
Wire Wire Line
	4750 3700 5050 3700
$Comp
L Device:C C?
U 1 1 5F7675CD
P 3950 2400
AR Path="/5F64F622/5F7675CD" Ref="C?"  Part="1" 
AR Path="/5F78AFC8/5F7675CD" Ref="C?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F7675CD" Ref="C?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F7675CD" Ref="C?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F7675CD" Ref="C?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F7675CD" Ref="C?"  Part="1" 
AR Path="/5F8D661A/5F7675CD" Ref="C1"  Part="1" 
F 0 "C1" V 3698 2400 50  0000 C CNN
F 1 "100n" V 3789 2400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3988 2250 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811151136_Walsin-Tech-Corp-0603B104K160CT_C80516.pdf" H 3950 2400 50  0001 C CNN
F 4 "LCSC" H 3950 2400 50  0001 C CNN "Distributor"
F 5 "Walsin Tech Corp" H 3950 2400 50  0001 C CNN "Manufacturer"
F 6 "100nF ±10% 16V X7R" H 3950 2400 50  0001 C CNN "Notes"
F 7 "" H 3950 2400 50  0001 C CNN "OrderNr"
F 8 "" H 3950 2400 50  0001 C CNN "PartNr"
F 9 "0.002141" H 3950 2400 50  0001 C CNN "PriceEUR"
F 10 "500" H 3950 2400 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Walsin-Tech-Corp-0603B104K160CT_C80516.html" H 3950 2400 50  0001 C CNN "Weblink"
F 12 "C80516" H 3950 2400 50  0001 C CNN "DistOrderNr"
F 13 "0603B104K160CT" H 3950 2400 50  0001 C CNN "ManPartNr"
	1    3950 2400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F767C48
P 3700 2400
AR Path="/5F64F622/5F767C48" Ref="#PWR?"  Part="1" 
AR Path="/5F78AFC8/5F767C48" Ref="#PWR?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F767C48" Ref="#PWR?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F767C48" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F767C48" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F767C48" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/5F767C48" Ref="#PWR013"  Part="1" 
F 0 "#PWR013" H 3700 2150 50  0001 C CNN
F 1 "GND" V 3705 2272 50  0000 R CNN
F 2 "" H 3700 2400 50  0001 C CNN
F 3 "" H 3700 2400 50  0001 C CNN
	1    3700 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 2400 3800 2400
Wire Wire Line
	4100 2400 4250 2400
Wire Wire Line
	4250 2400 4250 2700
$Comp
L gamearino-rescue:USB_C_Receptacle_USB2.0-Connector X?
U 1 1 5F6E6B4D
P 1650 3200
AR Path="/5F64F622/5F6E6B4D" Ref="X?"  Part="1" 
AR Path="/5F78AFC8/5F6E6B4D" Ref="X?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/5F6E6B4D" Ref="X?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/5F6E6B4D" Ref="X?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F6E6B4D" Ref="X?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F6E6B4D" Ref="X?"  Part="1" 
AR Path="/5F8D661A/5F6E6B4D" Ref="X1"  Part="1" 
AR Path="/5F6E6B4D" Ref="X?"  Part="1" 
F 0 "X1" H 1757 4067 50  0000 C CNN
F 1 "USB-C/16p" H 1757 3976 50  0000 C CNN
F 2 "htl_connectors:USB_C_Receptacle_LCSC_C167321" H 1800 3200 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1800 3200 50  0001 C CNN
F 4 "Jing Extension" H 1650 3200 50  0001 C CNN "Manufacturer"
F 5 "" H 1650 3200 50  0001 C CNN "PartNr"
F 6 "LCSC" H 1650 3200 50  0001 C CNN "Distributor"
F 7 "" H 1650 3200 50  0001 C CNN "OrderNr"
F 8 "0.155" H 1650 3200 50  0001 C CNN "PriceEUR"
F 9 "100" H 1650 3200 50  0001 C CNN "PriceForQty"
F 10 "https://lcsc.com/product-detail/USB-Connectors_Jing-Extension-of-the-Electronic-Co-C167321_C167321.html" H 1650 3200 50  0001 C CNN "Weblink"
F 11 "USB-C, 16-polig, USB 2.0" H 1650 3200 50  0001 C CNN "Notes"
F 12 "C167321" H 1650 3200 50  0001 C CNN "DistOrderNr"
F 13 "C167321" H 1650 3200 50  0001 C CNN "ManPartNr"
	1    1650 3200
	1    0    0    -1  
$EndComp
NoConn ~ 2250 3700
NoConn ~ 2250 3800
Text Notes 4550 4350 0    50   ~ 0
Bemerkung 1:\nPin 15, RS232:\nWenn high, wird RxD invertiert, \num direkt die RS232-Leitungen zu kontaktieren. 
Text Notes 3400 3150 0    50   ~ 0
siehe Bem.1
Wire Wire Line
	4350 1700 4350 2400
$Comp
L power:+3V3 #PWR?
U 1 1 5F96D29B
P 4350 1700
AR Path="/5F7F8851/5F7FB5B8/5F96D29B" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F96D29B" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F96D29B" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/5F96D29B" Ref="#PWR014"  Part="1" 
F 0 "#PWR014" H 4350 1550 50  0001 C CNN
F 1 "+3V3" H 4365 1873 50  0000 C CNN
F 2 "" H 4350 1700 50  0001 C CNN
F 3 "" H 4350 1700 50  0001 C CNN
	1    4350 1700
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5F81810D
P 2250 2300
AR Path="/5F7F8851/5F7FB5B8/5F81810D" Ref="#FLG?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F81810D" Ref="#FLG?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F81810D" Ref="#FLG?"  Part="1" 
AR Path="/5F8D661A/5F81810D" Ref="#FLG02"  Part="1" 
F 0 "#FLG02" H 2250 2375 50  0001 C CNN
F 1 "PWR_FLAG" V 2250 2428 50  0000 L CNN
F 2 "" H 2250 2300 50  0001 C CNN
F 3 "~" H 2250 2300 50  0001 C CNN
	1    2250 2300
	0    1    1    0   
$EndComp
Connection ~ 2250 2300
Wire Wire Line
	2250 2300 2250 2600
Text Label 3250 3200 0    50   ~ 0
D+
Text Label 3250 3300 0    50   ~ 0
D-
Wire Wire Line
	1350 4100 1350 4200
$Comp
L Regulator_Linear:AMS1117-3.3 U3
U 1 1 5F92C543
P 7400 1750
F 0 "U3" H 7400 1992 50  0000 C CNN
F 1 "AMS1117-3.3" H 7400 1901 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 7400 1950 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 7500 1500 50  0001 C CNN
F 4 "UMW Youtai Semiconductor" H 7400 1750 50  0001 C CNN "Manufacturer"
F 5 " AMS1117-3.3 " H 7400 1750 50  0001 C CNN "ManPartNr"
F 6 "LCSC" H 7400 1750 50  0001 C CNN "Distributor"
F 7 "C347222" H 7400 1750 50  0001 C CNN "DistOrderNr"
F 8 "0.023029" H 7400 1750 50  0001 C CNN "PriceEUR"
F 9 "100" H 7400 1750 50  0001 C CNN "PriceForQty"
F 10 "https://lcsc.com/product-detail/Dropout-Regulators-LDO_UMW-Youtai-Semiconductor-Co-Ltd-AMS1117-3-3_C347222.html" H 7400 1750 50  0001 C CNN "Weblink"
F 11 "LDO, 3.3V" H 7400 1750 50  0001 C CNN "Notes"
	1    7400 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1750 7800 1750
$Comp
L Device:C C?
U 1 1 5F92C552
P 6850 2100
AR Path="/5F90221A/5F92C552" Ref="C?"  Part="1" 
AR Path="/5F8D661A/5F92C552" Ref="C3"  Part="1" 
F 0 "C3" H 6736 2146 50  0000 R CNN
F 1 "10u/16V/X5R" H 6736 2055 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6888 1950 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811151151_Samsung-Electro-Mechanics-CL21A106KOQNNNE_C1713.pdf" H 6850 2100 50  0001 C CNN
F 4 "C1713" H 6850 2100 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 6850 2100 50  0001 C CNN "Distributor"
F 6 "CL21A106KOQNNNE" H 6850 2100 50  0001 C CNN "ManPartNr"
F 7 "Samsung" H 6850 2100 50  0001 C CNN "Manufacturer"
F 8 "10uF ±10% 16V X5R" H 6850 2100 50  0001 C CNN "Notes"
F 9 "0.011386" H 6850 2100 50  0001 C CNN "PriceEUR"
F 10 "200" H 6850 2100 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_SAMSUNG_CL21A106KOQNNNE_10uF-106-10-16V_C1713.html" H 6850 2100 50  0001 C CNN "Weblink"
	1    6850 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2350 7400 2050
Wire Wire Line
	6850 1750 6850 1950
Connection ~ 6850 1750
Wire Wire Line
	6850 1750 7100 1750
Wire Wire Line
	6850 2350 6850 2250
$Comp
L Device:C C4
U 1 1 5F92C571
P 7800 2100
F 0 "C4" H 7915 2146 50  0000 L CNN
F 1 "10u/16V/X5R" H 7915 2055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7838 1950 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1811151151_Samsung-Electro-Mechanics-CL21A106KOQNNNE_C1713.pdf" H 7800 2100 50  0001 C CNN
F 4 "C1713" H 7800 2100 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 7800 2100 50  0001 C CNN "Distributor"
F 6 "CL21A106KOQNNNE" H 7800 2100 50  0001 C CNN "ManPartNr"
F 7 "Samsung" H 7800 2100 50  0001 C CNN "Manufacturer"
F 8 "10uF ±10% 16V X5R" H 7800 2100 50  0001 C CNN "Notes"
F 9 "0.011386" H 7800 2100 50  0001 C CNN "PriceEUR"
F 10 "200" H 7800 2100 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_SAMSUNG_CL21A106KOQNNNE_10uF-106-10-16V_C1713.html" H 7800 2100 50  0001 C CNN "Weblink"
	1    7800 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 1950 7800 1750
Connection ~ 7800 1750
Wire Wire Line
	7800 1750 8100 1750
Wire Wire Line
	7800 2350 7800 2250
Wire Wire Line
	6550 1750 6850 1750
Wire Wire Line
	2250 1100 5950 1100
Wire Wire Line
	6550 1100 6550 1750
Wire Wire Line
	2250 1100 2250 2300
$Comp
L power:+3V3 #PWR?
U 1 1 5F92DC73
P 8100 1750
AR Path="/5F7F8851/5F7FB5B8/5F92DC73" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/5F92DC73" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/5F92DC73" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/5F92DC73" Ref="#PWR021"  Part="1" 
F 0 "#PWR021" H 8100 1600 50  0001 C CNN
F 1 "+3V3" H 8115 1923 50  0000 C CNN
F 2 "" H 8100 1750 50  0001 C CNN
F 3 "" H 8100 1750 50  0001 C CNN
	1    8100 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60590650
P 4350 4150
AR Path="/5F8674B3/60590650" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/60590650" Ref="#PWR015"  Part="1" 
F 0 "#PWR015" H 4350 3900 50  0001 C CNN
F 1 "GND" H 4354 3995 50  0000 C CNN
F 2 "" H 4350 4150 50  0001 C CNN
F 3 "" H 4350 4150 50  0001 C CNN
	1    4350 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 605914DB
P 1350 4200
AR Path="/5F8674B3/605914DB" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/605914DB" Ref="#PWR09"  Part="1" 
F 0 "#PWR09" H 1350 3950 50  0001 C CNN
F 1 "GND" H 1354 4045 50  0000 C CNN
F 2 "" H 1350 4200 50  0001 C CNN
F 3 "" H 1350 4200 50  0001 C CNN
	1    1350 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60591BD5
P 1650 4200
AR Path="/5F8674B3/60591BD5" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/60591BD5" Ref="#PWR010"  Part="1" 
F 0 "#PWR010" H 1650 3950 50  0001 C CNN
F 1 "GND" H 1654 4045 50  0000 C CNN
F 2 "" H 1650 4200 50  0001 C CNN
F 3 "" H 1650 4200 50  0001 C CNN
	1    1650 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 605932E8
P 6850 2350
AR Path="/5F8674B3/605932E8" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/605932E8" Ref="#PWR018"  Part="1" 
F 0 "#PWR018" H 6850 2100 50  0001 C CNN
F 1 "GND" H 6854 2195 50  0000 C CNN
F 2 "" H 6850 2350 50  0001 C CNN
F 3 "" H 6850 2350 50  0001 C CNN
	1    6850 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 605939B6
P 7400 2350
AR Path="/5F8674B3/605939B6" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/605939B6" Ref="#PWR019"  Part="1" 
F 0 "#PWR019" H 7400 2100 50  0001 C CNN
F 1 "GND" H 7404 2195 50  0000 C CNN
F 2 "" H 7400 2350 50  0001 C CNN
F 3 "" H 7400 2350 50  0001 C CNN
	1    7400 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60594161
P 7800 2350
AR Path="/5F8674B3/60594161" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/60594161" Ref="#PWR020"  Part="1" 
F 0 "#PWR020" H 7800 2100 50  0001 C CNN
F 1 "GND" H 7804 2195 50  0000 C CNN
F 2 "" H 7800 2350 50  0001 C CNN
F 3 "" H 7800 2350 50  0001 C CNN
	1    7800 2350
	1    0    0    -1  
$EndComp
$Comp
L htl_passives:R_sig R12
U 1 1 6040C49F
P 5250 2900
F 0 "R12" V 5457 2900 50  0000 C CNN
F 1 "100R" V 5366 2900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 2900 50  0001 C CNN
F 3 "" H 5250 2900 50  0001 C CNN
F 4 "C103204" H 5250 2900 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 5250 2900 50  0001 C CNN "Distributor"
F 6 "RTT03101JTP" H 5250 2900 50  0001 C CNN "ManPartNr"
F 7 "RALEC" H 5250 2900 50  0001 C CNN "Manufacturer"
F 8 "100Ω ±5% 0.1W ±100ppm/℃" H 5250 2900 50  0001 C CNN "Notes"
F 9 "0.0015" H 5250 2900 50  0001 C CNN "PriceEUR"
F 10 "100" H 5250 2900 50  0001 C CNN "PriceForQty"
	1    5250 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5400 2900 5700 2900
$Comp
L htl_passives:R_sig R13
U 1 1 6040C811
P 5250 3000
F 0 "R13" V 5365 3000 50  0000 C CNN
F 1 "100R" V 5456 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 3000 50  0001 C CNN
F 3 "" H 5250 3000 50  0001 C CNN
F 4 "C103204" H 5250 3000 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 5250 3000 50  0001 C CNN "Distributor"
F 6 "RTT03101JTP" H 5250 3000 50  0001 C CNN "ManPartNr"
F 7 "RALEC" H 5250 3000 50  0001 C CNN "Manufacturer"
F 8 "100Ω ±5% 0.1W ±100ppm/℃" H 5250 3000 50  0001 C CNN "Notes"
F 9 "0.0015" H 5250 3000 50  0001 C CNN "PriceEUR"
F 10 "100" H 5250 3000 50  0001 C CNN "PriceForQty"
	1    5250 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 3000 5700 3000
$Comp
L power:PWR_FLAG #FLG?
U 1 1 608C2019
P 2150 4150
AR Path="/5F7F8851/5F7FB5B8/608C2019" Ref="#FLG?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/608C2019" Ref="#FLG?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/608C2019" Ref="#FLG?"  Part="1" 
AR Path="/5F8D661A/608C2019" Ref="#FLG01"  Part="1" 
F 0 "#FLG01" H 2150 4225 50  0001 C CNN
F 1 "PWR_FLAG" V 2150 4278 50  0000 L CNN
F 2 "" H 2150 4150 50  0001 C CNN
F 3 "~" H 2150 4150 50  0001 C CNN
	1    2150 4150
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 4150 1650 4150
Connection ~ 1650 4150
Wire Wire Line
	1650 4150 1650 4100
Wire Wire Line
	4750 3200 4800 3200
Wire Wire Line
	4800 3200 4800 3300
Wire Wire Line
	4800 3500 4750 3500
Wire Wire Line
	4750 3400 4800 3400
Connection ~ 4800 3400
Wire Wire Line
	4800 3400 4800 3500
Wire Wire Line
	4750 3300 4800 3300
Connection ~ 4800 3300
Wire Wire Line
	4800 3300 4800 3400
$Comp
L power:GND #PWR?
U 1 1 608F62E4
P 4900 3400
AR Path="/5F8674B3/608F62E4" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/608F62E4" Ref="#PWR017"  Part="1" 
F 0 "#PWR017" H 4900 3150 50  0001 C CNN
F 1 "GND" H 4904 3245 50  0000 C CNN
F 2 "" H 4900 3400 50  0001 C CNN
F 3 "" H 4900 3400 50  0001 C CNN
	1    4900 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4900 3400 4800 3400
Text Notes 5150 3450 0    50   ~ 0
Terminate unused inputs
$Comp
L Device:R R?
U 1 1 60901270
P 2500 2800
AR Path="/5F64F622/60901270" Ref="R?"  Part="1" 
AR Path="/5F78AFC8/60901270" Ref="R?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/60901270" Ref="R?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/60901270" Ref="R?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/60901270" Ref="R?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/60901270" Ref="R?"  Part="1" 
AR Path="/5F8D661A/60901270" Ref="R9"  Part="1" 
F 0 "R9" V 2293 2800 50  0000 C CNN
F 1 "5k1" V 2384 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2430 2800 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Uniroyal-Elec-0603WAJ0101T5E_C25201.pdf" H 2500 2800 50  0001 C CNN
F 4 "C150387" H 2500 2800 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 2500 2800 50  0001 C CNN "Distributor"
F 6 "CR16-512FV" H 2500 2800 50  0001 C CNN "ManPartNr"
F 7 "HDK(Hokuriku Elec Industry)" H 2500 2800 50  0001 C CNN "Manufacturer"
F 8 "5k1, 1%, 100mW, 1608" H 2500 2800 50  0001 C CNN "Notes"
F 9 "0.000563" H 2500 2800 50  0001 C CNN "PriceEUR"
F 10 "1000" H 2500 2800 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAJ0101T5E_C25201.html" H 2500 2800 50  0001 C CNN "Weblink"
	1    2500 2800
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 60901A6A
P 2500 2900
AR Path="/5F64F622/60901A6A" Ref="R?"  Part="1" 
AR Path="/5F78AFC8/60901A6A" Ref="R?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/60901A6A" Ref="R?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/60901A6A" Ref="R?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/60901A6A" Ref="R?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/60901A6A" Ref="R?"  Part="1" 
AR Path="/5F8D661A/60901A6A" Ref="R10"  Part="1" 
F 0 "R10" V 2293 2900 50  0000 C CNN
F 1 "5k1" V 2384 2900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2430 2900 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Uniroyal-Elec-0603WAJ0101T5E_C25201.pdf" H 2500 2900 50  0001 C CNN
F 4 "C150387" H 2500 2900 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 2500 2900 50  0001 C CNN "Distributor"
F 6 "CR16-512FV" H 2500 2900 50  0001 C CNN "ManPartNr"
F 7 "HDK(Hokuriku Elec Industry)" H 2500 2900 50  0001 C CNN "Manufacturer"
F 8 "5k1, 1%, 100mW, 1608" H 2500 2900 50  0001 C CNN "Notes"
F 9 "0.000563" H 2500 2900 50  0001 C CNN "PriceEUR"
F 10 "1000" H 2500 2900 50  0001 C CNN "PriceForQty"
F 11 "https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0603WAJ0101T5E_C25201.html" H 2500 2900 50  0001 C CNN "Weblink"
	1    2500 2900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60901CF8
P 2750 2850
AR Path="/5F64F622/60901CF8" Ref="#PWR?"  Part="1" 
AR Path="/5F78AFC8/60901CF8" Ref="#PWR?"  Part="1" 
AR Path="/5F7F8851/5F7FB5B8/60901CF8" Ref="#PWR?"  Part="1" 
AR Path="/5F8070C3/5F7FB5B8/60901CF8" Ref="#PWR?"  Part="1" 
AR Path="/5F8AD0E2/5F7FB5B8/60901CF8" Ref="#PWR?"  Part="1" 
AR Path="/5FA85ABF/5F7FB5B8/60901CF8" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/60901CF8" Ref="#PWR011"  Part="1" 
F 0 "#PWR011" H 2750 2600 50  0001 C CNN
F 1 "GND" H 2755 2677 50  0000 C CNN
F 2 "" H 2750 2850 50  0001 C CNN
F 3 "" H 2750 2850 50  0001 C CNN
	1    2750 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2750 2850 2700 2850
Wire Wire Line
	2700 2850 2700 2800
Wire Wire Line
	2700 2800 2650 2800
Wire Wire Line
	2700 2850 2700 2900
Wire Wire Line
	2700 2900 2650 2900
Connection ~ 2700 2850
Wire Wire Line
	2350 2900 2250 2900
Wire Wire Line
	2350 2800 2250 2800
Text Notes 850  2250 0    50   ~ 0
Upstream facing port\n--> 5k1 pull down on CC1/2
$Comp
L Device:R R?
U 1 1 6091984A
P 5950 1350
AR Path="/6091984A" Ref="R?"  Part="1" 
AR Path="/603FCB6F/6091984A" Ref="R?"  Part="1" 
AR Path="/5F8D661A/6091984A" Ref="R20"  Part="1" 
F 0 "R20" H 6020 1396 50  0000 L CNN
F 1 "4k7" H 6020 1305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5880 1350 50  0001 C CNN
F 3 "" H 5950 1350 50  0001 C CNN
F 4 "C103662" H 5950 1350 50  0001 C CNN "DistOrderNr"
F 5 "LCSC" H 5950 1350 50  0001 C CNN "Distributor"
F 6 " RTT03472JTP" H 5950 1350 50  0001 C CNN "ManPartNr"
F 7 "RALEC" H 5950 1350 50  0001 C CNN "Manufacturer"
F 8 "4.7kΩ ±5% 0.1W ±100ppm/K" H 5950 1350 50  0001 C CNN "Notes"
F 9 "0.0015" H 5950 1350 50  0001 C CNN "PriceEUR"
F 10 "100" H 5950 1350 50  0001 C CNN "PriceForQty"
	1    5950 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6091ACB9
P 5950 2350
AR Path="/5F8674B3/6091ACB9" Ref="#PWR?"  Part="1" 
AR Path="/5F8D661A/6091ACB9" Ref="#PWR036"  Part="1" 
F 0 "#PWR036" H 5950 2100 50  0001 C CNN
F 1 "GND" H 5954 2195 50  0000 C CNN
F 2 "" H 5950 2350 50  0001 C CNN
F 3 "" H 5950 2350 50  0001 C CNN
	1    5950 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2350 5950 2200
Wire Wire Line
	5950 1200 5950 1100
Wire Wire Line
	5950 1600 5950 1500
Connection ~ 5950 1100
Wire Wire Line
	5950 1100 6550 1100
$Comp
L htl_semiconductors:LED_Dual_green-red D2
U 1 1 6091E428
P 5850 1900
F 0 "D2" V 5804 1690 50  0000 R CNN
F 1 "LED_Dual_green-red" V 5895 1690 50  0000 R CNN
F 2 "htl_smd:LED_LiteOn_LTST-C195KGJRKT" H 5880 1900 50  0001 C CNN
F 3 "~" H 5880 1900 50  0001 C CNN
F 4 "LiteOn" H 5850 1900 24  0001 C CNN "Manufacturer"
F 5 "LTST-C195KGJRKT" H 5850 1900 24  0001 C CNN "ManPartNr"
F 6 "LCSC" H 5850 1900 24  0001 C CNN "Distributor"
F 7 "C125104" H 5850 1900 24  0001 C CNN "DistOrderNr"
F 8 "0.0184" H 5850 1900 24  0001 C CNN "PriceEUR"
F 9 "600" H 5850 1900 24  0001 C CNN "PriceForQty"
F 10 "https://lcsc.com/products/Light-Emitting-Diodes-LED_528.html?q=LTST-C195KGJRKT" H 5850 1900 24  0001 C CNN "Weblink"
F 11 "Doppel-LED, rot/grün, 2x1608" H 5850 1900 50  0001 C CNN "Notes"
	1    5850 1900
	0    -1   1    0   
$EndComp
NoConn ~ 5750 1600
NoConn ~ 5750 2200
$EndSCHEMATC
