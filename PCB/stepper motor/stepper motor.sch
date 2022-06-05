EESchema Schematic File Version 4
EELAYER 30 0
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
L Regulator_Linear:L7805 U2
U 1 1 607263A6
P 3650 950
F 0 "U2" H 3650 1192 50  0000 C CNN
F 1 "L7805" H 3650 1101 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3675 800 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 3650 900 50  0001 C CNN
	1    3650 950 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 607271AD
P 950 1000
F 0 "J1" H 842 1185 50  0000 C CNN
F 1 "Conn_01x02_Female" H 842 1094 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2-5.08_1x02_P5.08mm_Horizontal" H 950 1000 50  0001 C CNN
F 3 "~" H 950 1000 50  0001 C CNN
	1    950  1000
	-1   0    0    -1  
$EndComp
Text GLabel 1150 1000 2    50   Input ~ 0
12v
$Comp
L power:GND #PWR0101
U 1 1 60728980
P 1150 1100
F 0 "#PWR0101" H 1150 850 50  0001 C CNN
F 1 "GND" H 1155 927 50  0000 C CNN
F 2 "" H 1150 1100 50  0001 C CNN
F 3 "" H 1150 1100 50  0001 C CNN
	1    1150 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 607294FE
P 2550 1100
F 0 "C1" H 2665 1146 50  0000 L CNN
F 1 "104" H 2665 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 2588 950 50  0001 C CNN
F 3 "~" H 2550 1100 50  0001 C CNN
	1    2550 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 60729689
P 4050 1100
F 0 "C3" H 4165 1146 50  0000 L CNN
F 1 "C" H 4165 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 4088 950 50  0001 C CNN
F 3 "~" H 4050 1100 50  0001 C CNN
	1    4050 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C4
U 1 1 60729B66
P 4450 1100
F 0 "C4" H 4568 1146 50  0000 L CNN
F 1 "CP" H 4568 1055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 4488 950 50  0001 C CNN
F 3 "~" H 4450 1100 50  0001 C CNN
	1    4450 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 6072A149
P 3100 1100
F 0 "C2" H 3218 1146 50  0000 L CNN
F 1 "220uf" H 3218 1055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 3138 950 50  0001 C CNN
F 3 "~" H 3100 1100 50  0001 C CNN
	1    3100 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 950  3100 950 
Wire Wire Line
	3100 950  3350 950 
Connection ~ 3100 950 
Wire Wire Line
	2550 1250 3100 1250
Wire Wire Line
	3100 1250 3650 1250
Connection ~ 3100 1250
Text GLabel 2550 950  0    50   Input ~ 0
12v
$Comp
L power:GND #PWR0102
U 1 1 6072C8AE
P 3650 1250
F 0 "#PWR0102" H 3650 1000 50  0001 C CNN
F 1 "GND" H 3655 1077 50  0000 C CNN
F 2 "" H 3650 1250 50  0001 C CNN
F 3 "" H 3650 1250 50  0001 C CNN
	1    3650 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 950  4050 950 
Wire Wire Line
	4050 950  4450 950 
Connection ~ 4050 950 
Wire Wire Line
	3650 1250 4050 1250
Connection ~ 3650 1250
Wire Wire Line
	4050 1250 4450 1250
Connection ~ 4050 1250
Text GLabel 4450 950  2    50   Input ~ 0
5v
$Comp
L MCU_Microchip_ATmega:ATmega32-16PU U1
U 1 1 6072E4A0
P 3500 3850
F 0 "U1" H 3500 1761 50  0000 C CNN
F 1 "ATmega32-16PU" H 3500 1670 50  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm" H 3500 3850 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc2503.pdf" H 3500 3850 50  0001 C CNN
	1    3500 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 60730763
P 7050 1500
F 0 "C6" H 7165 1546 50  0000 L CNN
F 1 "22uf" H 7165 1455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7088 1350 50  0001 C CNN
F 3 "~" H 7050 1500 50  0001 C CNN
	1    7050 1500
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C5
U 1 1 60730CA4
P 7050 950
F 0 "C5" H 7165 996 50  0000 L CNN
F 1 "22uf" H 7165 905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 7088 800 50  0001 C CNN
F 3 "~" H 7050 950 50  0001 C CNN
	1    7050 950 
	0    -1   -1   0   
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 6073224E
P 7450 1200
F 0 "Y1" V 7496 1069 50  0000 R CNN
F 1 "16mhz" V 7405 1069 50  0000 R CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 7450 1200 50  0001 C CNN
F 3 "~" H 7450 1200 50  0001 C CNN
	1    7450 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 950  6900 1500
Wire Wire Line
	7450 1350 7450 1500
Wire Wire Line
	7450 1500 7200 1500
Wire Wire Line
	7200 950  7450 950 
Wire Wire Line
	7450 950  7450 1050
Text GLabel 8150 950  2    50   Input ~ 0
Externel_clk_1
Text GLabel 8150 1500 2    50   Input ~ 0
Externel_clk_2
Wire Wire Line
	8150 950  7450 950 
Connection ~ 7450 950 
Wire Wire Line
	8150 1500 7450 1500
Connection ~ 7450 1500
$Comp
L power:GND #PWR0103
U 1 1 60736266
P 6900 1500
F 0 "#PWR0103" H 6900 1250 50  0001 C CNN
F 1 "GND" H 6905 1327 50  0000 C CNN
F 2 "" H 6900 1500 50  0001 C CNN
F 3 "" H 6900 1500 50  0001 C CNN
	1    6900 1500
	1    0    0    -1  
$EndComp
Connection ~ 6900 1500
Text GLabel 2900 2350 0    50   Input ~ 0
Externel_clk_1
Text GLabel 2900 2550 0    50   Input ~ 0
Externel_clk_2
Text GLabel 2900 2750 0    50   Input ~ 0
5v
$Comp
L Device:R R1
U 1 1 60736FCC
P 2500 2150
F 0 "R1" V 2293 2150 50  0000 C CNN
F 1 "1k" V 2384 2150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2430 2150 50  0001 C CNN
F 3 "~" H 2500 2150 50  0001 C CNN
	1    2500 2150
	0    1    1    0   
$EndComp
Text GLabel 2350 2150 0    50   Input ~ 0
5v
Wire Wire Line
	2650 2150 2900 2150
Text GLabel 3500 1850 1    50   Input ~ 0
5v
Wire Wire Line
	3500 1850 3600 1850
$Comp
L power:GND #PWR0104
U 1 1 60738970
P 3500 5850
F 0 "#PWR0104" H 3500 5600 50  0001 C CNN
F 1 "GND" H 3505 5677 50  0000 C CNN
F 2 "" H 3500 5850 50  0001 C CNN
F 3 "" H 3500 5850 50  0001 C CNN
	1    3500 5850
	1    0    0    -1  
$EndComp
Text GLabel 8600 2450 0    50   Input ~ 0
PC0
Text GLabel 4100 3950 2    50   Input ~ 0
PC0
Text GLabel 4350 4050 2    50   Input ~ 0
PC1
Text GLabel 8400 2550 0    50   Input ~ 0
PC1
Text GLabel 4100 4150 2    50   Input ~ 0
PC2
Text GLabel 8600 2650 0    50   Input ~ 0
PC2
Text GLabel 4350 4250 2    50   Input ~ 0
PC3
Text GLabel 8400 2750 0    50   Input ~ 0
PC3
Wire Wire Line
	8400 2550 8600 2550
Wire Wire Line
	8400 2750 8600 2750
Wire Wire Line
	4350 4050 4100 4050
Wire Wire Line
	4350 4250 4100 4250
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 60744758
P 8800 2550
F 0 "J3" H 8828 2576 50  0000 L CNN
F 1 "Conn_01x05_Female" H 8828 2485 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-5-5.08_1x05_P5.08mm_Horizontal" H 8800 2550 50  0001 C CNN
F 3 "~" H 8800 2550 50  0001 C CNN
	1    8800 2550
	1    0    0    -1  
$EndComp
Text GLabel 8600 2150 2    50   Input ~ 0
12v
Wire Wire Line
	8600 2150 8500 2150
Wire Wire Line
	8500 2150 8500 2350
Wire Wire Line
	8500 2350 8600 2350
Text GLabel 4100 4850 2    50   Input ~ 0
PB0
Text GLabel 6350 4350 0    50   Input ~ 0
PB0
Text GLabel 4350 4950 2    50   Input ~ 0
PB1
Text GLabel 6200 4450 0    50   Input ~ 0
PB1
Text GLabel 4100 5050 2    50   Input ~ 0
PB2
Text GLabel 4350 5150 2    50   Input ~ 0
PB3
Text GLabel 6350 4550 0    50   Input ~ 0
PB2
Text GLabel 6200 4650 0    50   Input ~ 0
PB3
Wire Wire Line
	4350 4950 4100 4950
Wire Wire Line
	4350 5150 4100 5150
Wire Wire Line
	6200 4650 6350 4650
Wire Wire Line
	6200 4450 6350 4450
Text GLabel 6350 4050 2    50   Input ~ 0
12v
Wire Wire Line
	6350 4050 6250 4050
Wire Wire Line
	6250 4050 6250 4250
Wire Wire Line
	6250 4250 6350 4250
NoConn ~ 4100 4350
NoConn ~ 4100 4450
NoConn ~ 4100 4550
NoConn ~ 4100 4650
NoConn ~ 4100 5250
NoConn ~ 4100 5350
NoConn ~ 4100 5450
NoConn ~ 4100 5550
NoConn ~ 4100 3750
NoConn ~ 4100 3650
NoConn ~ 4100 3550
NoConn ~ 4100 3450
NoConn ~ 4100 3350
NoConn ~ 4100 3250
NoConn ~ 4100 3150
NoConn ~ 4100 3050
NoConn ~ 4100 2850
NoConn ~ 4100 2750
NoConn ~ 4100 2650
NoConn ~ 4100 2550
NoConn ~ 4100 2450
NoConn ~ 4100 2350
NoConn ~ 4100 2250
NoConn ~ 4100 2150
$Comp
L Connector:Conn_01x05_Female J2
U 1 1 6075858D
P 6550 4450
F 0 "J2" H 6578 4476 50  0000 L CNN
F 1 "Conn_01x05_Female" H 6578 4385 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-5-5.08_1x05_P5.08mm_Horizontal" H 6550 4450 50  0001 C CNN
F 3 "~" H 6550 4450 50  0001 C CNN
	1    6550 4450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
