#!/bin/bash
## mouli.sh for Mouli_Teksh in /home/bender/42sh/work/PSU_2016_42sh
## 
## Made by Bender_Jr
## Login   <@epitech.eu>
## 
## Started on  Sun Apr 16 23:06:06 2017 Bender_Jr
## Last update Mon Apr 17 18:19:23 2017 Bender_Jr
##

# clean option (use with ./mouli.sh -c)
# will later be expand to handle more test
# like the builtins ones, scripting etc
clean='-c'
if [ "$@" == "$clean" ]
then
    make fclean && rm -rf logz
    exit 0
fi
# color output variable
red='\033[31m'
green='\033[32m'
blue='\033[34m'
bld='\033[1m'
rst='\033[0m'

# variable defines
compil="make .PHONY"
prog='tksh'
logdir='logz'

# test cmd array
testcmd[0]="ls -l"
testcmd[1]="ls -la"
testcmd[2]="stty -a"

init_logtxt ()
{
    if [ ! -d $logdir ]; then
	mkdir $logdir
	echo "Info : $logdir created"
	echo "************************************" >> $logdir/logs.txt
	echo "( \      (  ___  )(  ____ \/ ___   )" >> $logdir/logs.txt
	echo "| (      | (   ) || (    \/\/   )  |" >> $logdir/logs.txt
	echo "| |      | |   | || |          /   )" >> $logdir/logs.txt
	echo "| |      | |   | || | ____    /   / " >> $logdir/logs.txt
	echo "| |      | |   | || | \_  )  /   /  " >> $logdir/logs.txt
	echo "| (____/\| (___) || (___) | /   (_/ " >> $logdir/logs.txt
	echo "(_______/(_______)(_______)(_______/" >> $logdir/logs.txt
	echo "************************************" >> $logdir/logs.txt
	echo "**************TekSH2k17*************" >> $logdir/logs.txt
    fi
    if [ ! -f $prog ]; then
	${compil}
    fi
}

test_prog ()
{
    if [ -f $logdir/toto.log ]; then
	rm -f $logdir/toto.log
    fi
    for i in "${testcmd[@]}"; do
	echo -e "${bld}cmd : ${blue}${i}${rst}" >> $logdir/toto.log
	echo "${i}" | ./$prog >> $logdir/toto.log 2>&1
	echo -e "${bld}exit_val : ${red}$?${rst}" >> $logdir/toto.log
    done
}

man_tcsh ()
{
    if [ -f $logdir/tata.log ]; then
	rm -f $logdir/tata.log
    fi
    for i in "${testcmd[@]}"; do
	echo -e "${bld}cmd : ${blue}${i}${rst}" >> $logdir/tata.log
	echo "${i}" | tcsh >> $logdir/tata.log 2>&1
	echo -e "${bld}exit_val : ${red}$?${rst}" >> $logdir/tata.log
    done
}

init_logtxt

echo "      _______ _______ _     _ _______ _     _                        "
echo "         |    |______ |____/  |______ |_____|                        "
echo "         |    |______ |    \_ ______| |     |                        "
echo "                                                                     "
echo " _______  _____  _     _        _____ _______ _______ _______ _______"
echo " |  |  | |     | |     | |        |      |    |______ |______    |   "
echo " |  |  | |_____| |_____| |_____ __|__    |    |______ ______|    |   "
echo " ******************************************************************  "
echo "                     (see \"$logdir\" dir for detail)	       	   "
echo "                 **************************************              "

test_prog
man_tcsh

if [ -f $logdir/logs.txt ]; then
    rm -f $logdir/logs.txt
fi
echo "                 **************************************              "
echo "                 **************************************              "
echo -e "${bld}                   Teksh logz :                       ${rst}"
echo "                 **************************************              "
cat $logdir/toto.log
echo "                 **************************************              "
echo -e "${bld}                   Tcsh logz :                        ${rst}"
echo "                 **************************************              "
cat $logdir/tata.log
echo "                 **************************************              "
echo "                 ### ******************************* ###             "
echo -e "${bld}${blue}                              ##  RESULTS ## ${rst}  "
echo "                 ### ******************************* ###             "

# diff commands
difftest=$(diff $logdir/toto.log $logdir/tata.log)

if [ "$difftest" ]
then
    echo -e "\t\t======== >>>> ${red}ya du diff !!${rst} <<<< ======== " >> $logdir/logs.txt
    echo "$difftest" >> $logdir/logs.txt
else
    echo -e "\t\t${green}****| Pas de diff TEST passed 100 % |*****${rst}" >> $logdir/logs.txt
fi
cat $logdir/logs.txt
exit 0
