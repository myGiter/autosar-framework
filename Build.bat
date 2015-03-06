@echo off
@rem +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
@rem
@rem BUILD.BAT
@rem
@rem        %1                %2          %3     %4        %5       %6                      %7
@rem Build  Arduino_Leonardo  ATMEGA32U4  Proto  Leonardo  default  Arduino_Leonardo_Proto  rebuild
@rem
@rem %1: TARGET:          i.e., Arduino_Leonardo, Arduino_Uno, Arduino_Due, STM_F100_Discovery, ...
@rem %2: CPU:             i.e. ATMEGA32U4, ...
@rem %3: CUSTOMER:        i.e., Proto, Lunazul, Bd, Rd, ...
@rem %4: PRJ:             i.e., Leonardo, ...
@rem %5: buildtype:       default, prepro, lint
@rem       default:       Compile, Lint and Link the project.
@rem       prepro:        Starts only the preprocessor for the *.c and *.asm files.
@rem       lint:          Only Lint the project.
@rem       misra:         Only Misra the project.
@rem       win_msvc:      Build for Windows with the Microsoft compiler.
@rem       win_gcc:       Build for Windows with GCC.
@rem %6: name:            project exec name i.e. Q1Lr05temp.
@rem %7: optional:        nothing or rebuild
@rem 
@rem +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
@rem ../Build.bat ARDUINO_LEONARDO ATMEGA32U4 Proto Leonardo default Arduino_Leonardo_Proto_Temp  all
@rem ../Build.bat ARDUINO_LEONARDO ATMEGA32U4 Proto Leonardo default Arduino_Leonardo_Proto_Temp  rebuild
@rem ../Build.bat ARDUINO_LEONARDO ATMEGA32U4 Proto Leonardo default Arduino_Leonardo_Proto_Temp  clean

set TargetDirectory=W:\f52401a_AutosarFramework\User\Hage\Projects\Eclipse\autosar-framework

::go to the path "%TargetDirectory%"
pushd "%TargetDirectory%"

if NOT EXIST %CD%\Build.bat cd..

set AuthorText= HAGE, STEPHAN - AUTOSAR-FRAMEWORK - 2014
set StatusText= %7: Customer %3 -  Project %4 
set TargetText= for Target: %1 - %2

set varTARGET=%1
set varCPU=%2
set varCUSTOMER=%3
set varPRJ=%4
set varBuildType=%5
set varResultName=%6
set varMakeRule=%7


@Set ExecCommand=Tools\Util\make\make.exe %varMakeRule% --jobs=1 -k -f Src\_make\Code_000.gmk TYP_TARGET=%varTARGET% TYP_CPU=%varCPU% TYP_CUSTOMER=%varCUSTOMER% TYP_PRJ=%varPRJ% TYP_BUILD=%varBuildType% TYP_NAME=%varResultName%
set CommandText= Tools\Util\make\make.exe %varMakeRule% --jobs=1 -k -f Src\_make\Code_000.gmk 

@echo +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
@echo %AuthorText% 
@echo %StatusText% 
@echo %TargetText% 
@echo +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
@echo Executing Command: %CommandText%
@echo TYP_TARGET=%varTARGET%
@echo TYP_CPU=%varCPU%
@echo TYP_CUSTOMER=%varCUSTOMER%
@echo TYP_PRJ=%varPRJ%
@echo TYP_BUILD=%varBuildType%
@echo TYP_NAME=%varResultName%

@%ExecCommand%