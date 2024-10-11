if [ "$#" -ne 3 ]; then
	echo "Usage: $0 <filename> <start_line> <end_line>"
	exit 1
fi

file=$1
start_line=$2
end_line=$3

if [ ! -f "$file" ]; then
	echo "File not found !"
	exit 1
fi

sed -n "${start_line},${end_line}p" "$file"

