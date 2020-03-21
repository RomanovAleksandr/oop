@echo off

set PROGRAM="%~1"

if %PROGRAM% == "" (
	echo Please specify path to program
	exit /B 1
)

REM Test 1 Empty file
%PROGRAM% Empty.txt > nul && goto err
echo Test 1 passed

REM Test 2
%PROGRAM% InvalidMatrix.txt > nul && goto err
echo Test 2 passed

REM Test 3
%PROGRAM% matrix.txt > "%TEMP%\output.txt" || goto err
fc OutMatrix.txt "%TEMP%\output.txt" > nul || goto err
echo Test 3 passed

REM Invalid arguments count
%PROGRAM% > nul && goto err
echo Test 4 passed

REM Pass missing file
%PROGRAM% MissingFile.txt "%TEMP%\output.txt" > nul && goto err
echo Test 5 passed

REM Test 6
%PROGRAM% matrix2.txt > "%TEMP%\output.txt" || goto err
fc OutMatrix2.txt "%TEMP%\output.txt" > nul || goto err
echo Test 6 passed

REM Nul determ matr
%PROGRAM% NulDetermMatr.txt "%TEMP%\output.txt" > nul && goto err
echo Test 7 passed

echo tests passed
exit /B 0

:err
echo Test failed
exit /B 1