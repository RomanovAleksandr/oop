@echo off

set PROGRAM="%~1"

if %PROGRAM% == "" (
	echo Please specify path to program
	exit /B 1
)

REM Test 1 Empty file
%PROGRAM% Empty.txt "%TEMP%\output.txt" || goto err
fc Empty.txt "%TEMP%\output.txt" || goto err
echo Test 1 passed

REM Test 2
%PROGRAM% fill.txt "%TEMP%\output.txt" || goto err
fc fill2.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed

REM Test 3
%PROGRAM% hole.txt "%TEMP%\output.txt" || goto err
fc hole2.txt "%TEMP%\output.txt" > nul || goto err
echo Test 3 passed

REM Invalid arguments count
%PROGRAM% > nul && goto err
echo Test 4 passed

REM Pass missing file
%PROGRAM% MissingFile.txt "%TEMP%\output.txt" "" "" > nul && goto err
echo Test 5 passed

echo tests passed
exit /B 0

:err
echo Test failed
exit /B 1