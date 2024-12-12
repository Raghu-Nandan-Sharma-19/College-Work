if [ "$#" -lt 2 ]; then
	echo " usage : $0 <word to delete> <file1> <file2....>"
	exit 1
fi
word=$1
shift
for file in "$@"; do
	if [ ! -f "$file" ]; then
		echo "file not found"
		continue
	fi
	sed -i "/$word/d" "$file"
	echo "deleted lines containing '$word' from $file"
done
