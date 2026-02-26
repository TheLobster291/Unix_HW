#!/usr/bin/env bash
### 
###  ldg0.sh - letter division generator script (wrapper around the long
###            division generator provided with project resources). This
###            script is to make letter division puzzles,  output in the
###            class pctX format.
### 
###     usage: [VARIABLE...] ldg0.sh KEY DIVISOR DIVIDEND [OPTION...]
### 
###      KEY - will be the first argument (${1}), encoded in puzzle base
###            and listed as a string, in ascending order from the  zero
###            letter through the highest counting value letter.  If the
###            string "random" is present,  key will instead be randomly
###            generated.
### 
###  DIVISOR - will  be the  second  argument (${2}),  encoded in  puzzle
###            base. If  instead "random#" is  provided, where #  is some
###            number  for  use as  the  length  of that  component,  the
###            divisor  will end  up  being randomly  generated (to  that
###            length).
### 
### DIVIDEND - will be the third argument (${3}),  encoded in the puzzle
###            base. If instead "random#" is provided,  where # is  some
###            number for use as the length of that component, that will
###            then indicate the dividend is to be randomly generated to
###            the implied length.
### 
###   option - description (potential optional arguments beyond ${3})
### ========   =============================================================
###     both   show both long division and letter division in script output
###    nokey   do not include puzzle key in output. Store in "puzzle.key"
### sanitize   do not use potentially confusing symbols (B,D,I,O,S,Z)
###     save   instead of displaying to STDOUT, save to "puzzle"
###   solve4   generate puzzle in solve4 format
###     help   display this help and exit
### 
### variable - description                                 default
### ========   =========================================   =======
###     BASE   set puzzle base (6-16)                      10
###    TERMS   set number of puzzle terms                  null
### 
##############################################################################

##############################################################################
##
## Declare variables
##
ARCH=$(uname -m)
KEY="${1}"
DIVISOR="${2}"
DIVIDEND="${3}"
LONGDIVGEN="./ref_ldg0.${ARCH}"
#LONGDIVGENDI is for the - divisor if needed
#LONGDIVGENDE is for the - dividend if needed

#check if help is asked
if [ $# = "help" ];then
echo "$(help.txt)"
fi

#if DIVISOR is given, set it to those numbers
if [ $DIVISOR = "^[0-9]*$" ]; then
LONGDIVGENDI= "-d $DIVISOR"
fi

#if divisor is random, needs a number value right after as thr length
if [ $DIVISOR = "[r][a][n][d][o][m][0-9]$" ]; then
DLenght = grep -Eo '[0-9]+' 
LONGDIVGENDI="-l $DLenght"
fi

#if DIVIDEN is given, set it to those numbers
if [ $DIVIDEN = "^[0-9]*$" ]; then
LONGDIVGENDE="-D $DIVIDEN"
fi

#if divisor is random, needs a number value right after as thr length
if [ $DIVIDEN = "[r][a][n][d][o][m][0-9]$" ]; then
DLenght = grep -Eo '[0-9]+' 
LONGDIVGENDE="-L $DLenght"
fi

#generate puzzle, put into puzzle.txt file
./${LONGDIVGEN} ${LONGDIVGENDI} ${LONGDIVGENDE} > puzzle.txt

#check for KEY in command line, string equal in length to base
if [ $KEY = "^[A-Z]{BASE}" ]; then
cat puzzle.txt | grep "^[0-9]&&[A-F]{BASE}" | tr -s "^[A-Z]{BASE}"
fi

#if key doesnt exist, randomly generate one
if [ $KEY != "^[A-Z]{BASE}" ]; then
cat puzzle.txt | "[A-Z]" </dev/urandom | > Puzzle.txt
fi



exit 0
