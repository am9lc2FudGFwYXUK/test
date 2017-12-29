#!/bin/bash 

list="gcc gcc-c++ jansson-devel flex bison libxml2-devel libevent-devel libcurl-devel python-devel lua-devel"


for i in $list 
	do 
		yum -y install $i 
	done 





