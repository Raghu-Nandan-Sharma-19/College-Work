# check if atleast one argument is provided
if [ $# -eq 0 ]; then
	echo "Usage: $file1 [file1 [file2 ... fileN]"
	exit 1
fi

# loop through all the provided arguments (file names)
for file in "$@"
do
	# check if the file exist
	if [ -f "$file" ]; then
		# convert the content to uppercase and overwrite the file
		tr '[:lower:]' '[:upper:]' < "$file" > temp_file && mv temp_file "$file"
		echo "Converted $file to uppercase"
	else
		echo "File $file does not exist"
	fi
done
