@echo off

set PROGRAM="%~1"

if %PROGRAM% == "" (
	echo Please specify path to program
	exit /B 1
)

REM Input 0
%PROGRAM% 0 > "%TEMP%\output.txt" || goto err
fc 1out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

REM Input 255
%PROGRAM% 255 > "%TEMP%\output.txt" || goto err
fc 2out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Input 6
%PROGRAM% 6 > "%TEMP%\output.txt" || goto err
fc 3out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 3 passed

REM Input 99999999999999999
%PROGRAM% 99999999999999999 > nul && goto err
echo Test 5 passed

REM Input more than 255
%PROGRAM% 300 > nul && goto err
echo Test 6 passed

REM Input not number
%PROGRAM% abc > nul && goto err
echo Test 7 passed

REM Input -1
%PROGRAM% -1 > nul && goto err
echo Test 8 passed

echo tests passed
exit /B 0

:err
echo Test failed
exit /B 1