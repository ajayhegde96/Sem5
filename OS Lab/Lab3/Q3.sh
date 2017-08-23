echo "Enter directory"
read direc
cd $direc
x=`ls -A`
for files in $x
do
var1=$files
var2=`grep $var1 TOC.txt |wc -l`
if test $var2 -eq 0
then
echo $var1>>TOC.txt
fi
done
