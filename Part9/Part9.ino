/* Part9 display remote button number on segmented display */
#include <IRremote.h> //load IRremote library

#include <TM1637Display.h> //load segmented display library

#define CLK 4
#define DIO 5

TM1637Display tm1637(CLK, DIO); //create segmented display object
IRrecv ir(A0);//an instance of the IR receiver object,A0 is IRreceive pin;
decode_results result; // container for received IR codes

long codes[10] = { 0xFD708F, 0xFD08F7, 0xFD8877, 0xFD48B7, 0xFD28D7, 0xFDA857,
                   0xFD6897, 0xFD18E7, 0xFD9867, 0xFD58A7
                 }; //corresponding IR codes for the remote

void setup() {
  tm1637.setBrightness(0x0F);
  ir.enableIRIn();
}
void loop() {
  if (ir.decode(&result)) { //if the receiver detects something
    for (int i = 0; i < 10; ++i) //look for the code in the array
      if (result.value == codes[i]) //if the code matches
        tm1637.showNumberDec(i, false); //display the corresponding number
  }
  ir.resume(); //resume receiver
}
delay(100); //wait before checking again
}
