loop(){
	echo "Enter the starting value : " 
	read s
	echo "Enter the incrementing value : "
	read i
	echo "Enter the limit: " 
	read l 
	
	for (( k=s;k<=l;k+=i ))
	do 
		echo $k
	done
}

loop
