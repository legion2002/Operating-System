#!/bin/bash

#This is the add function
add(){
    count=0
    sum=0
    for num in "$@"
        
        do 
            if [[ count -ne 0 ]]; then
                
                sum=$(( num + sum ))
            fi
            ((count++))
        done
    echo "Sum is: $sum"
}

# This is the subtract function
sub(){
    count=0
    diff=$2
    
    for num in "$@"
        
        do 
            
            if [[ count -ne 0 ]] && [[ count -ne 1 ]]; then
                
                diff=$(( diff - num ))
            fi
            ((count++))
        done
    echo "Difference is: $diff"
}

#This is the multiply function
mul(){
    count=0
    mul=1
    
    for num in "$@"
        
        do 
            
            if [[ count -ne 0 ]]; then
                
                mul=$(( mul * num ))
            fi
            ((count++))
        done
    echo "Product is: $mul"
}

# This is the divide function
div(){
    count=0
    div=$2
    
    for num in "$@"
        
        do 
            
            if [[ count -ne 0 ]] && [[ count -ne 1 ]]; then
                
                div=$(( div / num ))
            fi
            ((count++))
        done
    echo "Quotient is: $div"
}

# This is the exponentiation function
exp(){
    count=0
    exp=$2
    orig=$2
    
    for num in "$@"
        
        do 
            orig=$exp
            if [[ count -ne 0 ]] && [[ count -ne 1 ]]; then
                i=1
                if [[ $num -eq 0 ]]; then
                    exp=1
                fi
                while [[ $i -lt $num ]]
                    do
                        ((i++))
                        exp=$(( exp * orig ))
                    done
            fi
            ((count++))
        done
    echo "Answer is: $exp"
}

# This is the main menu which uses if-else statements to call the correct function
if [[ "$1" == "add" ]]; then
    add "$@"
fi
if [[ "$1" == "sub" ]]; then
    sub "$@"
fi
if [[ "$1" == "mul" ]]; then
    mul "$@"
fi
if [[ "$1" == "div" ]]; then
    div "$@"
fi
if [[ "$1" == "exp" ]]; then
    exp "$@"
fi