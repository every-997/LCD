#include <mbed.h>
#include <C12832.h>

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);

int main()
{
  AnalogIn leftPot(A0);
  AnalogIn rightPot(A1);

  lcd.cls();
  lcd.rect(0,0,127,31,1);
  lcd.locate(2,3);
  lcd.printf("Potentiometer monitor");
  while(true) {   // this is the third thread
    lcd.locate(2,12);
    lcd.printf("LPot %1.2f", leftPot.read());
    double lPot  = leftPot.read();
    int lPotPercent = ((lPot/80)*1000)+45;
    lcd.rect(45,12,lPotPercent,20,1);

    lcd.locate(2,21);
    lcd.printf("RPot %1.2f", rightPot.read());
    lcd.rect(45,21,125,29,1);
    wait_ms(200);
  }

}
