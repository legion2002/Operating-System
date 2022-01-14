#!/bin/bash
echo $1
arr=(${1//-/ })
echo ${arr[0]}
echo arr[2]
;${2#0}