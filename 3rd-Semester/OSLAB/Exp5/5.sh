extract_substring() {
	local str=$1
	local start=$2
	local length=$3
	echo "${str:$start:$length}"
}
find_length() {
	local str=$1
	echo ${#str}
}

echo "enter a string: "
read str

echo "enter a starting position and length of the substring"
read start length

substring=$(extract_substring "$str"  $start $length)
echo "extracted substring : $substring"
