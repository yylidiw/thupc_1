:loop
rand_mkdt.exe
my_std.exe
std.exe
fc my_std.out std.out
if %errorlevel% ==0 goto loop
pause
