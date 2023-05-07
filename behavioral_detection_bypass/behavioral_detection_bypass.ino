#include "DigiKeyboard.h"

void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  // send <Windows> + R to open run.exe
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // run to powershell
  printWithSimulateHumanInput("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);
  
  // run dir
  printWithSimulateHumanInput("dir");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Delay to disconnect before second payload exec
  DigiKeyboard.delay(100000);
}

void printWithSimulateHumanInput(String text) {
  int textLength = text.length(); 
  for (int i = 0; i < textLength; i++) {
    DigiKeyboard.delay(random(150,250));
    DigiKeyboard.print(text[i]);
  }
}