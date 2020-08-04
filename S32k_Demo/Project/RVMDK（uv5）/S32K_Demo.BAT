SET PATH=d:\Keil_v5\ARM\ARMCC\Bin;D:\Program Files\Python38\Scripts\;D:\Program Files\Python38\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\dotnet\;d:\Program Files\Git\cmd;C:\Program Files\TortoiseGit\bin;D:\Program Files\PuTTY\;D:\Python38\Scripts\;D:\Python38\;C:\Users\wande\AppData\Local\Microsoft\WindowsApps;D:\Program Files\JetBrains\PyCharm 2019.3.4\bin;;C:\Users\wande\AppData\Local\Programs\Microsoft VS Code\bin;C:\Users\wande\.dotnet\tools;D:\mingw64\bin;
SET CPU_TYPE=S32K144HAxxxLHx
SET CPU_VENDOR=NXP
SET UV2_TARGET=S32K_Demo
SET CPU_CLOCK=0x00B71B00
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\croutine.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\event_groups.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\list.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\queue.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stream_buffer.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\tasks.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\timers.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\port.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\heap_4.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\schm.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\ecum.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\startup.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\startup_s32k144._ia"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\system_s32k144.__i"
"d:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\S32k_Demo.lnp"
"d:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\S32k_Demo.axf" --i32combined --output ".\Objects\S32k_Demo.hex"
