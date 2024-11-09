
// void usartInit(){
//   UBRR0H = 0;//set baud rate  = 9600
//   UBRR0L = 103;
//   UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
//   UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set frame size = 8-bit
// }
// void usartDataWrite(char data){
//   while(!(UCSR0A&(1<<UDRE0))); //wait until data register empty
//   UDR0 = data;
// }
// void usartStrWrite(char *ch){
//   while(*ch){
//     usartDataWrite(*ch++);
//   }
// }
// void usartStrWriteLn(char *ch){
//   while(*ch){
//     usartDataWrite(*ch++);
//   }
//   usartDataWrite(13);
// }
// char usartDataRead(){
//   while(!(UCSR0A&(1<<RXC0))); //wait till new data arrieved
//   return UDR0;
// }
// bool dataAvailable(){
//   return UCSR0A&(1<<RXC0);
// }
// void setup() {
//   usartInit();
//   DDRB |=(1<<PB5)|(1<<PB3)|(1<<PB1); //LED
// }
// void loop() {
//   if(dataAvailable()){
//     usartStrWrite("Data received is = ");
//     char received = usartDataRead();
//     usartDataWrite(received);
//     usartStrWriteLn("");
//     if(received == '1'){
//       PORTB ^=(1<<PB5)|(1<<PB3)|(1<<PB1); //LED ON
//     }
//     else{
//       PORTB &=~(1<<PB5) & ~(1<<PB3) &~(1<<PB1); //LED OFF
//     }
//   }
// }


// void usartInit(){
//   UBRR0H = 0;//set baud rate  = 9600
//   UBRR0L = 103;
//   UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
//   UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set frame size = 8-bit
// }
// void usartDataWrite(char data){
//   while(!(UCSR0A&(1<<UDRE0))); //wait until data register empty
//   UDR0 = data;
// }
// void usartStrWrite(char *ch){
//   while(*ch){
//     usartDataWrite(*ch++);
//   }
// }
// void usartStrWriteLn(char *ch){
//   while(*ch){
//     usartDataWrite(*ch++);
//   }
//   usartDataWrite(13);
// }
// char usartDataRead(){
//   while(!(UCSR0A&(1<<RXC0))); //wait till new data arrieved
//   return UDR0;
// }
// bool dataAvailable(){
//   return UCSR0A&(1<<RXC0);
// }
// void usartInit();
// void usartDataWrite(char data);
// void usartStrWrite(char *ch);
// void usartStrWriteLn(char *ch);
// char usartDataRead();
// bool dataAvailable();
// void setup() {
//   usartInit();
//   DDRB |=(1<<PB5)|(1<<PB0); //LED
// }
// void loop() {
//   if(dataAvailable()){
//     char received = usartDataRead();
//     usartStrWrite("Data received is = ");
//     usartDataWrite(received);
//     usartStrWriteLn("");
//     if(received == '1'){
//       PORTB ^=(1<<PB5); //LED ON
//     }
//     else if(received == '2'){
//       PORTB ^=(1<<PB0); //LED ON
//     }
//   }
// }
// void usartInit(){
//   UBRR0H = 0;//set baud rate  = 9600
//   UBRR0L = 103;
//   UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
//   UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set frame size = 8-bit
// }
// void usartDataWrite(char data){
//   while(!(UCSR0A&(1<<UDRE0))); //wait until data register empty
//   UDR0 = data;
// }
// void usartStrWrite(char *ch){
//   while(*ch){
//     usartDataWrite(*ch++);
//   }
// }
// void usartStrWriteLn(char *ch){
//   while(*ch){
//     usartDataWrite(*ch++);
//   }
//   usartDataWrite(13);
// }
// char usartDataRead(){
//   while(!(UCSR0A&(1<<RXC0))); //wait till new data arrieved
//   return UDR0;
// }
// bool dataAvailable(){
//   return UCSR0A&(1<<RXC0);
// }
// void adcInit()
// {
//   /*enable ADC,enable conversion complete interuppt, prescaller=128*/
//   ADCSRA |=(1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
// }
// int readAdc(char ch)
// {
//   unt16_t adcResult=0;
//   unit8_t temp=0;
//   ch= ch & 0b00000111; //keept only the channel number
//   ADMUX|=(1<<REFS0)|ch;
//   ADCSRA |=(1<<ADSC); //start conversion
//   while(!ADCSRA & (1<<ADIF));
//   temp=ADCL;
//   adcResult=ADCH;
//   ADCSRA|=(1<<ADIF); //clear flag
//   adcResult = (adcResult<<8)|temp;
//   return adcResult;
// }
void usartInit();
void usartDataWrite(char data);
void usartStrWrite(char *ch);
void usartStrWriteLn(char *ch);
void usartNumberWrite(int num);
char usartDataRead();
bool dataAvailable();
void adcInit();
int readAdc(char ch);

void setup() {
  usartInit();
  adcInit();
}
void loop() {
  // int sensor = readAdc(0);
  // usartNumberWrite(sensor);
  int pot = readAdc(0);
  int ldr = readAdc(5);
  usartStrWrite("pot = ");
  usartNumberWrite(pot);
  usartStrWrite("ldr = ");
  _delay_ms(200);
}

void usartInit(){
  UBRR0H = 0;//set baud rate  = 9600
  UBRR0L = 103;
  UCSR0B |=(1<<TXEN0)|(1<<RXEN0); //enable Tx and Rx
  UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00); //set frame size = 8-bit
}
void usartDataWrite(char data){
  while(!(UCSR0A&(1<<UDRE0))); //wait until data register empty
  UDR0 = data;
}
void usartStrWrite(char *ch){
  while(*ch){
    usartDataWrite(*ch++);
  }
}
void usartStrWriteLn(char *ch){
  while(*ch){
    usartDataWrite(*ch++);
  }
  usartDataWrite(13);
}
void usartNumberWrite(int num){
  char str[5];
  snprintf(str, 5, "%d", num);
  usartStrWriteLn(str);
}
char usartDataRead(){
  while(!(UCSR0A&(1<<RXC0))); //wait till new data arrieved
  return UDR0;
}
bool dataAvailable(){
  return UCSR0A&(1<<RXC0);
}
void adcInit(){
  /*enable ADC,enable conversion conversion complete interrupt, prescaller=128 */
  ADCSRA |=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
int readAdc(char ch){
  uint16_t adcResult = 0;
  uint8_t temp = 0;
  ch = ch & 0b00000111; //keept only the channel number
  ADMUX |=(1<<REFS0) | ch;
  ADCSRA |=(1<<ADSC); //start conversion
  while(!(ADCSRA & (1<<ADIF))); //wait until conversion complete
  temp = ADCL;
  adcResult = ADCH; 
  ADCSRA |=(1<<ADIF); //clear flag
  adcResult = (adcResult <<8) | temp;
  return adcResult;
}