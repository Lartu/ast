# ast 🐡
**ast** (**a**verage and **s**um **t**ool) is a command line tool designed to calculate the sum, mean, variance or standard
deviation of a list of numbers passed through `stdin`.
The aforementioned list can be any kind of text, it will be split according to a passed delimiter
(defaults to `' '` and always splits lines)
and just the numbers found in it will be taken into consideration.

# How to Use

# Examples
Calculating the sum of a list of five numbers: `echo "123 323 42 78.43434 -78.9" | ast -s` outputs: `487.53434`.
Calculating the average of said list: `echo "123 323 42 78.43434 -78.9" | ast -m` outputs: `97.5068680000000001`.
Calculating the variance of said list: `echo "123 323 42 78.43434 -78.9" | ast -v` outputs: `17212.2418310776964`.
Calculating the standard deviation of said list: `echo "123 323 42 78.43434 -78.9" | ast -d` outputs: `131.19543372799869`.
Calculating the sum of a list of four numbers split by commas: `echo "123, 323,42 ,78.43434" | ast -s` outputs: `487.53434`.
