echo "Enter directory"
read direc
cd $direc
rm `ls -A1 | head -n 1` 
