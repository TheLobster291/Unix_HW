#!/bin/bash
b="base 2"
o="base 8"
d="base10"
h="base16"
prefix="0X"

y=16

if [ $# -eq 0 ]; then
x=0
y=${x+16}
fi

if [ $# -eq 1 ]; then
x=$1
y=`expr $x + $y` 
fi

if [ $# -ge 2 ]; then
x=$1
y=$2
fi

if [ "$1" -gt "$2" ]; then
printf "the second argument needs to be smaller than the first \n"
exit
fi

if [ $x -gt 255 -o $y -gt 255 ]; then
printf "no number can be greater than 255\n"
printf "if no end bound is specified, the highest the first argument can be is 239\n"
exit
fi

if [ $3 -eq "signed" ]; then
printf "Signed functionality has not been implemented\n"
exit
fi

#printing table
printf "%8s |" "${b}"
printf "%8s |" "${o}"
printf "%8s |" "${d}"
printf "%8s \n" "${h}"

#printing dotted line
printf '%.0s-' {1..9}
printf "+"
printf '%.0s-' {1..9}
printf "+"
printf '%.0s-' {1..9}
printf "+"
printf '%.0s-' {1..9}
printf "\n"
while [ ${x} -le ${y} ]; do

printf "%.8d |" $(dc -e "${x} 2op")
printf "%.8o |" ${x}
printf "%8d |"  ${x}
printf "%+6s%0X |\n" ${prefix} ${x}
let x=x+1
done
