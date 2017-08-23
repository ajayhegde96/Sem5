file1=(cat $1)
file2=(cat $2)
f1=cat $1|wc -l
f2=cat $2|wc -l
i=0
j=0
for f in $file1
do
if($file1[i] -gt $file2[j]||$file1[i] -eq $file2[j])
then 
$file2[j]>>merge.txt
((j+1))
else
$file1[i]>>merge.txt
((i+1))
fi
done
if(i<$f1)
then
while test $i -lt $f1
do
$file1[i]>>merge.txt
done
fi
if(j<$f2)
then
while test $j -lt $f2
do
$file2[j]>>merge.txt
done
fi


