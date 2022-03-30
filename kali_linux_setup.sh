#!/bin/bash

printf "> Installing CVenom..."

mkdir ~/.CVenom &> /dev/null
cp * ~/.CVenom -r

printf " Done\n"
printf "> Installing cvg++ (NEED ROOT ACCESS)\n"

sudo cp ~/.CVenom/Compiler/cvg++ /bin

if [ ! -f "/bin/cvg++" ];then
	printf "> ERROR: Compiler Not Installed, Cause: Permission Denied\n"
else printf "> Compiler Installed\n\n"

fi

printf "> CVenom MDK Was \033[0;92mSuccessfully\033[0;97m Installed For \033[0;92m$(whoami)\033[0;97m.\n"
sleep 1
printf "> Preparing To Install Windows And Linux Compilers And Stripers...\n"
sleep 1
printf "> Press Enter To Start The Installation ! "
read
printf "> Starting The Installation Please Do Not Interrupt It Will Take a While To Finish\n"
sleep 1
sudo apt install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 gcc-mingw-w64 g++-mingw-w64 clang gcc g++
printf "> Compilers And Stripers Successfully Installed\n"
sleep 5
clear
printf "WELCOME TO CVENOM - MALWARE DEVELOPMENT MADE EASY WITH CVENOM\n"
printf "PROFESSIONAL MALWARE DEVELOPERS USES CVENOM - WANNA BE A PROFESSIONAL MALWARE DEVELOPER?\n\n"

printf "Warning: Please Do Not Use This MDK For Illegal Actions, We Are Not Responsible\n"
sleep 1
printf "\nLearn CVenom By Watching 4 Minutes Videos Right There: https://youtube.com/c/TheDoctorMLT\n"
sleep 1
printf "Or Access The Full Documentation Right There: https://github.com/Mahmoud7Osman/CVenom#documentation\n"
