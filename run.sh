# save array of file names in a variable called FILES and loop through this variable using for loop
# file.c file2.c file3.c are the files to be compiled
FOLDER=$(ls | grep -v .sh)
bash clean.sh
for f in $FOLDER
do
  FILES=$(ls $f | grep .c)
  for files in $FILES
  do
    if [[ $files == ${files%.c} ]]
    then
      rm -rf $files
    fi
    gcc $f/$files -o $f/${files%.c} -lm
    echo "Compiled $f/$files"
  done
done
