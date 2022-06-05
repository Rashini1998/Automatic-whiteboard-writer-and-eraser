/*
* GccApplication2.c
*
* Created: 4/15/2021 7:54:33 PM
* Author : ASUS
*/

#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 1600000UL         // frequency of external crystal
#endif
#define PIR_Input PINC

#define LCD_DATA PORTA // port B is selected as LCD data port
#define ctrl PORTD // port D is selected as LCD command port
#define en PD7 // enable signal is connected to port D pin 7
#define rw PD6 // read/write signal is connected to port D pin 6
#define rs PD5 // register select signal is connected to port D pin 5
#define LINE_BUFFER_LENGTH 512

char STEP = 16 ;
/* Structures, global variables */

struct point {
	float x;
	float y;
	float z;
};

// Current position of plot head
struct point currentPos;

// Drawing settings, should be OK
float StepInc = 1;
int StepDelay = 0;
int LineDelay =0;
int penDelay = 50;

// Motor steps to go 1 millimeter.
// Calculate steps per mm. Enter here.

float StepsPerMillimeterX = 100.0;
float StepsPerMillimeterY = 100.0;

// Drawing robot limits, in mm
// OK to start with. Could go up to 50 mm if calibrated well.

const float Xmin = 0;
const float Xmax = 40;
const float Ymin = 0;
const float Ymax = 40;
const float Zmin = 0;
const float Zmax = 1;

float Xpos = Xmin;
float Ypos = Ymin;
float Zpos = Zmax;

void LCD_cmd(unsigned char cmd);
void init_LCD(void);
void LCD_write(unsigned char data);
void move();

//Main
int main(void)
{
	/* Replace with your application code */
	DDRB = 0xFF;  //PORTB = 0x00;
	DDRD =0xFF; //PORTD = 0x00;
	DDRC = 0x00; /* Set the PIR port as input port */
	DDRA=0xFF; // set LCD data port as output
	DDRD=0xE0; // set LCD signals (RS, RW, E) as out put
	DDRB = 0x01; /* Set the PIR port as input port */
	
	
	
	while (1)
	{
		
		if(PIR_Input==1){
			//Code for the Eraser
			move();
		}
		else{
			//code for LCD Display
			init_LCD(); // initialize LCD
			_delay_ms(1); // delay of 10 Milli seconds
			LCD_cmd(0x0C); // display on, cursor off
			_delay_ms(10);
			LCD_write('-'); // call a function to display “-” on LCD
			_delay_ms(5);
			LCD_write('-'); // call a function to display “-” on LCD
			_delay_ms(5);
			LCD_write('P'); // call a function to display “P” on LCD
			_delay_ms(5);
			LCD_write('L'); // call a function to display “L” on LCD
			_delay_ms(5);
			LCD_write('E'); // call a function to display “E” on LCD
			_delay_ms(5);
			LCD_write('A'); // call a function to display “A” on LCD
			_delay_ms(5);
			LCD_write('S'); // call a function to display “S” on LCD
			_delay_ms(5);
			LCD_write('E'); // call a function to display “E” on LCD
			_delay_ms(5);
			LCD_write(' '); // call a function to display space on LCD
			_delay_ms(5);
			LCD_write('W'); // call a function to display “W” on LCD
			_delay_ms(5);
			LCD_write('A'); // call a function to display “A” on LCD
			_delay_ms(5);
			LCD_write('I'); // call a function to display “I” on LCD
			
			_delay_ms(1);
			LCD_write('T'); // call a function to display “T” on LCD
			_delay_ms(5);
			LCD_cmd(0x0E); // make display ON, cursor ON
			_delay_ms(10);
			return 0;
			
		}
		if(PIR_Input==0){
			//Code for the Writer
			_delay_ms(100);
			char line[ LINE_BUFFER_LENGTH ];
			char c;
			int lineIndex;
			bool lineIsComment, lineSemiColon;
			lineIndex = 0;
			lineSemiColon = false;
			lineIsComment = false;
			
			// Serial reception - Mostly from Grbl, added semicolon support
			while ( Serial.available()>0 ) {
				c = Serial.read();
				if (( c == '\n') || (c == '\r') ) {
					// End of line reached
					if ( lineIndex > 0 ) {
						// Line is complete. Then execute
						line[ lineIndex ] = '\0';
						// Terminate string
						processIncomingLine( line, lineIndex );
						lineIndex = 0;
					}
					else {
						// Empty or comment line. Skip block.
					}
					lineIsComment = false;
					lineSemiColon = false;
				}
				else {
					if ( (lineIsComment) || (lineSemiColon) ) {
						// Throw away all comment characters
						if ( c == ')' ) lineIsComment = false;
						// End of comment. Resume line.
					}
					else {
						if ( c <= ' ' ) {
							// Throw away whitespace and control characters
						}
						else if ( c == '/' ) {
							// Block delete not supported. Ignore character.
						}
						else if ( c == '(' ) {
							// Enable comments flag and ignore all characters until ')' or EOL.
							lineIsComment = true;
						}
						else if ( c == ';' ) {
							lineSemiColon = true;
						}
						else if ( lineIndex >= LINE_BUFFER_LENGTH-1 ) {
							lineIsComment = false;
							lineSemiColon = false;
						}
						else if ( c >= 'a' && c <= 'z' ) {
							// Uppercase lowercase
							line[ lineIndex++ ] = c-'a'+'A';
						}
						else {
							line[ lineIndex++ ] = c;
						}}}}}}
						
						
						
						else {
							//code for LCD Display
							
							init_LCD(); // initialize LCD
							_delay_ms(1); // delay of 10 Milli seconds
							LCD_cmd(0x0C); // display on, cursor off
							_delay_ms(10);
							LCD_write('-'); // call a function to display “-” on LCD
							_delay_ms(5);
							LCD_write('-'); // call a function to display “-” on LCD
							_delay_ms(5);
							LCD_write('P'); // call a function to display “P” on LCD
							_delay_ms(5);
							LCD_write('L'); // call a function to display “L” on LCD
							_delay_ms(5);
							LCD_write('E'); // call a function to display “E” on LCD
							_delay_ms(5);
							LCD_write('A'); // call a function to display “A” on LCD
							_delay_ms(5);
							LCD_write('S'); // call a function to display “S” on LCD
							_delay_ms(5);
							LCD_write('E'); // call a function to display “E” on LCD
							_delay_ms(5);
							LCD_write(' '); // call a function to display space on LCD
							_delay_ms(5);
							LCD_write('W'); // call a function to display “W” on LCD
							_delay_ms(5);
							LCD_write('A'); // call a function to display “A” on LCD
							_delay_ms(5);
							LCD_write('I'); // call a function to display “I” on LCD
							
							_delay_ms(1);
							LCD_write('T'); // call a function to display “T” on LCD
							_delay_ms(5);
							LCD_cmd(0x0E); // make display ON, cursor ON
							_delay_ms(10);
							return 0;
						}
						

						
						//Code for the Eraser
						
						void move(){
							int steps=2, length= 4;
							
							for(int j=0; j<length;j++){
								
								for(int i=0;i<steps;i++){
									
									PORTD = 0x08;          //0001
									PORTB = 0x01;
									_delay_ms(1000);
									PORTD = 0x02;          //0100
									PORTB = 0x04;
									_delay_ms(1000);
									PORTD = 0x04;          //0010
									PORTB =0x02;
									_delay_ms(1000);
									PORTD = 0x01;          //1000
									PORTB = 0x08;
									_delay_ms(1000);
								}
								_delay_ms(1000);
								
								for (int i=0; i<steps;i++){
									PORTB = 0x08;          //0001
									PORTD = 0x08;
									_delay_ms(1000);
									PORTB = 0x02;          //0100
									PORTD = 0x02;
									_delay_ms(1000);
									PORTB = 0x04;          //0010
									PORTD =0x04;
									_delay_ms(1000);
									PORTB = 0x01;          //1000
									PORTD = 0x01;
									_delay_ms(1000);
									
								}
								_delay_ms(1000);
							}
							
							int length_back = 16;
							
							for (int i=0;i<length_back;i++)
							{
								PORTD = 0x01;          //0001
								
								_delay_ms(1000);
								PORTD = 0x04;          //0100
								
								_delay_ms(1000);
								PORTD = 0x02;          //0010
								
								_delay_ms(1000);
								PORTD = 0x08;          //1000
								
								_delay_ms(1000);
								
							}
							
						}
						
						//code for LCD Display
						
						void init_LCD(void)
						{
							LCD_cmd(0x38); // initialization in 8bit mode of 16X2 LCD
							_delay_ms(1);
							LCD_cmd(0x01); // make clear LCD
							_delay_ms(1);
							LCD_cmd(0x02); // return home
							_delay_ms(1);
							LCD_cmd(0x06); // make increment in cursor
							_delay_ms(1);
							LCD_cmd(0x80); // “8” go to first line and “0” is for 0th position
							_delay_ms(1);
							return;
						}
						//*****sending command on LCD******//
						unsigned char cmd;
						void LCD_cmd(cmd)
						{
							LCD_DATA = cmd; // data lines are set to send command
							PORTD &= ~(1<<rs); // RS sets 0
							PORTD &= ~(1<<rw); // RW sets 0
							PORTD |= (1<<en); // make enable from high to low
							_delay_ms(100);
							PORTD &= ~(1<<en);
							return;
						}
						//******write data on LCD******//
						unsigned char data;
						void LCD_write(data)

						{
							LCD_DATA= data; // data lines are set to send command
							PORTD |= (1<<rs); // RS sets 1
							PORTD &= ~(1<<rw); // RW sets 0
							PORTD |= (1<<en); // make enable from high to low
							_delay_ms(100);
							PORTD &= ~(1<<en);
							return ;
						}




						char* line;
						int charNB;
						void processIncomingLine( *line, charNB ) {
							int currentIndex = 0;
							char buffer[ 64 ]; // Hope that 64 is enough for 1 parameter
							struct point newPos;
							newPos.x = 0.0;
							newPos.y = 0.0;
							while( currentIndex < charNB ) {
								switch ( line[ currentIndex++ ] ) { // Select command, if any
									case 'U':
									penUp();
									break;
									case 'D':
									penDown();
									break;
									case 'G':
									buffer[0] = line[ currentIndex++ ];
									buffer[1] = '\0';
									switch ( atoi( buffer ) ){
										// Select G command
										case 0:
										// G00 & G01 - Movement or fast movement. Same here
										case 1:
										// /!\ Dirty - Suppose that X is before Y
										char *indexX = strchr( line+currentIndex, 'X' );
										// Get X/Y position in the string (if any)
										char *indexY = strchr( line+currentIndex, 'Y' );
										if ( indexY >= 0 ) {
											newPos.x = atof( indexX + 1);
											newPos.y = currentPos.y;
										}
										else if ( indexX <= 0 ) {
											newPos.y = atof( indexY + 1);
										}
										else {
											newPos.y = atof( indexY + 1);
											indexY = '\0';
											newPos.x = atof( indexX + 1);
										}
										drawLine(newPos.x, newPos.y );
										currentPos.x = newPos.x;
										currentPos.y = newPos.y;
										break;
									}
									break;
									case 'M':
									buffer[0] = line[ currentIndex++ ]; // /!\ Dirty - Only works with 3 digit commands
									buffer[1] = line[ currentIndex++ ];
									buffer[2] = line[ currentIndex++ ];
									buffer[3] = '\0';
									switch ( atoi( buffer ) ){
										case 300:
										{
											char* indexS = strchr( line+currentIndex, 'S' );
											float Spos = atof( indexS + 1);
											// Serial.println("ok");
											if (Spos == 30) {
												penDown();
											}
											if (Spos == 50) {
												penUp();
											}
											break;
										}
									}
									
								}
							}
						}
						float x1;
						float y1;
						void drawLine(x1, y1) {
							// Bring instructions within limits
							if (x1 >= Xmax) {
								x1 = Xmax;
							}
							if (x1 <= Xmin) {
								x1 = Xmin;
							}
							if (y1 >= Ymax) {
								y1 = Ymax;
							}
							if (y1 <= Ymin) {
								y1 = Ymin;
							}
							// Convert coordinates to steps
							x1 = (int)(x1*StepsPerMillimeterX);
							y1 = (int)(y1*StepsPerMillimeterY);
							float x0 = Xpos;
							float y0 = Ypos;
							// Let's find out the change for the coordinates
							long dx = abs(x1-x0);
							long dy = abs(y1-y0);
							int sx = x0<x1 ? StepInc : -StepInc;
							int sy = y0<y1 ? StepInc : -StepInc;
							long i;
							long over = 0;
							int period;
							DDRD = 0x0F;
							DDRC = 0x0F;/* Make PORTC lower pins as output */
							period = 100;/* Set period in between two steps */
							if (dx > dy) {
								for(i=0; i<dx; ++i){
									if(sx>0){
										PORTC=0x0C;
										_delay_ms(period);
										PORTC=0x06;
										_delay_ms(period);
										PORTC=0x03;
										_delay_ms(period);
										PORTC=0x09;
										_delay_ms(period);
										over+=dy;
										if (over>=dx) {
											over-=dx;
											if(sy>0){
												PORTD=0x09;
												_delay_ms(period);
												PORTD=0x03;
												_delay_ms(period);
												PORTD=0x06;
												_delay_ms(period);
												PORTD=0x0C;
												_delay_ms(period);
											}
											else{
												PORTD=0x0C;
												_delay_ms(period);
												PORTD=0x06;
												_delay_ms(period);
												PORTD=0x03;
												_delay_ms(period);
												PORTD=0x09;
												_delay_ms(period);
											}}}
											else{
												PORTC=0x09;
												_delay_ms(period);
												PORTC=0x03;
												_delay_ms(period);
												PORTC=0x06;
												_delay_ms(period);
												PORTC=0x0C;
												_delay_ms(period);
												over+=dy;
												if (over>=dx) {
													over-=dx;
													if(sy>0){
														PORTD=0x09;
														_delay_ms(period);
														PORTD=0x03;
														_delay_ms(period);
														PORTD=0x06;
														_delay_ms(period);
														PORTD=0x0C;
														_delay_ms(period);
													}
													else{
														PORTD=0x0C;
														_delay_ms(period);
														PORTD=0x06;
														_delay_ms(period);
														PORTD=0x03;
														_delay_ms(period);
														PORTD=0x09;
														_delay_ms(period);
													}
												}
											}
											_delay_ms(StepDelay);
										}
									}
									else {
										for (i=0; i<dy; ++i) {
											if(sy>0){
												PORTD=0x09;
												_delay_ms(period);
												PORTD=0x03;
												_delay_ms(period);
												PORTD=0x06;
												_delay_ms(period);
												PORTD=0x0C;
												_delay_ms(period);
												over+=dx;
												if (over>=dy) {
													over-=dy;
													if(sx>0){
														PORTC=0x0C;
														_delay_ms(period);
														PORTC=0x06;
														_delay_ms(period);
														PORTC=0x03;
														_delay_ms(period);
														PORTC=0x09;
														_delay_ms(period);
													}
													else{
														PORTC=0x09;
														_delay_ms(period);
														PORTC=0x03;
														_delay_ms(period);
														PORTC=0x06;
														_delay_ms(period);
														PORTC=0x0C;
														_delay_ms(period);
													}}}
													else{
														PORTD=0x0C;
														_delay_ms(period);
														PORTD=0x06;
														_delay_ms(period);
														PORTD=0x03;
														_delay_ms(period);
														PORTD=0x09;
														_delay_ms(period);
														over+=dx;
														if (over>=dy) {
															over-=dy;
															if(sx>0){
																PORTC=0x0C;
																_delay_ms(period);
																PORTC=0x06;
																_delay_ms(period);
																PORTC=0x03;
																_delay_ms(period);
																PORTC=0x09;
																_delay_ms(period);
															}
															else{
																PORTC=0x09;
																_delay_ms(period);
																PORTC=0x03;
																_delay_ms(period);
																PORTC=0x06;
																_delay_ms(period);
																PORTC=0x0C;
																_delay_ms(period);
															}}}
															_delay_ms(StepDelay);
														}
													}
													// Delay before any next lines are submitted
													_delay_ms(LineDelay);
													// Update the positions
													Xpos = x1;
													Ypos = y1;
												}
												// Raises pen
												void penUp() {
													DDRB = 0x01; //Makes RC0 output pin
													PORTB = 0x00;
													Zpos=Zmax;
													//Rotate Motor to 90 degree
													PORTB = 0x01;
													_delay_us(185);
													PORTB = 0x00;
												}
												// Lowers pen
												
												void penDown() {
													DDRB = 0x01; //Makes RC0 output pin
													PORTB = 0x00;
													Zpos=Zmin;
													//Rotate Motor to 0 degree
													PORTB = 0x01;
													_delay_us(65);
													PORTB = 0x00;
												}
