
FOLDER=$(ls | grep -v .sh)

for f in $FOLDER
do
FILES=$(ls $f)

# loop through each file
for file in $FILES
do
  # check if file is not .c or .sh
  if [[ $f/$file != *.c && $f/$file != *.sh ]]
  then
    # remove file
    rm $f/$file
    echo "Removed $f/$file"
  fi
done
done




