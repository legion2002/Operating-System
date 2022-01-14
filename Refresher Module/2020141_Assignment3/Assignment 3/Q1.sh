#!/bin/bash

# This line breaks down the date string into dd mm yyyy
arr=(${1//-/ })

# date validation starts here
if [[ ${arr[1]#0} -ge 1  && ${arr[1]#0} -le 12 ]]; then
	
if [[ ${arr[2]#0} -ge 1000 && ${arr[2]#0} -le 9999 ]]; then
	
if [[ (${arr[1]#0} -eq 1 || ${arr[1]#0} -eq 3 || ${arr[1]#0} -eq 5 || ${arr[1]#0} -eq 7 || ${arr[1]#0} -eq 8 || ${arr[1]#0} -eq 10 || ${arr[1]#0} -eq 12) && ${arr[0]#0} -ge 1 && ${arr[0]#0} -le 31 ]]; then
		# Calendar is printed as date is correct
       cal ${arr[1]#0} ${arr[2]#0}
       exit 0
elif  [[ ${arr[1]#0} -eq 2 && ${arr[0]#0} -ge 1 && ${arr[0]#0} -le 29 ]]; then
	
	if [[ $(expr ${arr[2]#0} % 4) -eq 0 ]]; then
		# Calendar is printed as date is correct
		cal ${arr[1]#0} ${arr[2]#0}
		exit 0
	
	elif [[ ${arr[1]#0} -eq 2 && ${arr[0]#0} -ge 1 && ${arr[0]#0} -le 28 ]]; then
		   # Calendar is printed as date is correct
	       cal ${arr[1]#0} ${arr[2]#0}
       	       exit 0
	fi
else 
	if [[ ${arr[0]#0} -ge 1 && ${arr[0]#0} -le 30 ]]; then
		# Calendar is printed as date is correct
		cal ${arr[1]#0} ${arr[2]#0}
		exit 0
	fi
fi
fi
fi

# If none of the conditions are correct, error message is given
echo "The date is invalid"
 
