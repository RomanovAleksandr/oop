@echo off

set PROGRAM="%~1"

if %PROGRAM% == "" (
	echo Please specify path to program
	exit /B 1
)

REM Test 1 Empty file
%PROGRAM% Empty.txt "%TEMP%\output.txt" 1 2 || goto err
fc Empty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

REM Test 2
%PROGRAM% input.txt "%TEMP%\output.txt" ma mama || goto err
fc 2out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Test 3
%PROGRAM% input.txt "%TEMP%\output.txt" 1231234 0 || goto err
fc 3out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 3 passed

REM Many lines
%PROGRAM% input.txt "%TEMP%\output.txt" line string || goto err
fc 4out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 4 passed

REM Search string with 0 size
%PROGRAM% input.txt "%TEMP%\output.txt" "" string || goto err
fc 5out.txt "%TEMP%\output.txt" > nul || goto err
echo Test 5 passed

REM Invalid arguments count
%PROGRAM% > nul && goto err
echo Test 6 passed

REM Pass missing file
%PROGRAM% MissingFile.txt "%TEMP%\output.txt" "" "" > nul && goto err
echo Test 7 passed

echo tests passed
exit /B 0

:err
echo Test failed
exit /B 1