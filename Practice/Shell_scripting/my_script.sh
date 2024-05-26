sum(){

echo "Enter number for fibonacci series: "
read num
if [ $num -le 1 ];then
echo "Enter number greater than 1"
exit 1
fi
num1=0
num2=1
echo "Fibonacci series is: "
echo "$num1"
echo "$num2"
for (( i=2; i<num; i++ ))
do
    num3=$(($num1 + $num2))
    echo "$num3"
    num1=$num2
    num2=$num3
done
}

sum
