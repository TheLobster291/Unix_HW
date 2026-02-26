#!/bin/bash
#This program stores the date command  with conversion to the epoch
#in a variable called epoch so it can be run every time I need it.
#I then take the epoch epoch and modulate it by 60 to get seconds.
#The formula follows a pattern thats epoch % N2 / N1 until the year.
#This pattern gets the remainder and then cuts only the bit we need for
#each of the designated time values. For the year, I put the conversion
#over x to equal the current year. This helped me arrive at 14704 as the 
#divide number to reach the year.
#
#For the prints, I used Unix's base conversion to print those numbers
#from decimal to the desired base-16
#
#I put this in a while loop that never ends with the first step being to 
#clear the page so you only have the one set of variables to focus on.
#After it does the math and prints everything I set it to sleep for 
#1 second to give the reader time to read and not have a seizure.


morning='AM'
afternoon='PM'

while true 
do
	
	#resets page
	clear
	
	#variable to get epoch
	epoch=$(date +%s)
	
	#variable to isolate seconds only
	seconds=`expr $epoch % 60 `
	
	#variable to isolate minutes only
	minutes=`expr $epoch % 3600 / 60`
	
	#variable to isolate hours only
	hour=`expr $epoch % 86400 / 3600`
	
	#variable to isolate days only
	day=`expr $epoch % 604800 / 86400`
	
	#variable to isolate months only
	month=`expr $epoch % 31556926 / 2629743`
	
	#variable to isolate years only
	year=`expr $epoch % 31556926 / 14704`
	
	#series of prints to see what each individual is
	printf 'seconds from epoch: %x\n' $epoch
	printf 'seconds: %x\n' $seconds
	printf 'minutes: %x\n' $minutes
	printf 'hour: %x\n' $hour
	printf 'day: %x\n' $day
	printf 'month: %x\n' $month
	printf 'year: %x\n\n' $year
	
	#if statements to print as a whole, with logic for AM or PM depending 
	#on the time
	if [ $hour -lt 12 ];then

		printf '%x/%x/%x  %x:%x:%x  %s\n' $month $day $year $hour $minutes $seconds $morning
	fi
	
	if [ $hour -ge 12 ];then

		printf '%x/%x/%x  %x:%x:%x  %s\n' $month $day $year $hour $minutes $seconds $afternoon
	fi
	
	printf "Press ctrl+C to leave the program"
	
	#sleep to have the command run again after every second
	# instead of constantly
	sleep 1s
done 


