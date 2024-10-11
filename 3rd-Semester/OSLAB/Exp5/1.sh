echo "Enter a string: "
read $str
if [ $# -ls 3 ]; then
	echo "Usage : $str <startline> <endline>"
	exit 1;
fi
for i in "$@"
