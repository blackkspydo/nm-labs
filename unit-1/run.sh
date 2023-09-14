# save array of file names in a variable called FILES and loop through this variable using for loop
# file.c file2.c file3.c are the files to be compiled
FILES="bisection fixedPointIteration hornersMethod newtonsRaphson secant"

for f in $FILES
do
  echo "Compiling $f file..."
  gcc $f.c -o $f -lm
done

