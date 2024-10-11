echo "Enter a file or directory name"
read str
if test -f $str
then echo "File exists and it is an ordinary file"
elif test -d $str
then echo "It is a directory file"
else
echo "It is neither a file nor a directory"
fi
