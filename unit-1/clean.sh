FILES=$(ls)

# loop through each file
for f in $FILES
do
  # check if file is not .c or .sh
  if [[ $f != *.c && $f != *.sh ]]
  then
    # remove file
    rm $f
  fi
done


