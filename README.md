![Stage](https://img.shields.io/badge/stage-stable-yellow.svg) ![Version](https://img.shields.io/badge/version-1.0-blue.svg)

![ast: the average and sum tool](https://raw.githubusercontent.com/Lartu/ast/master/logo/astlogo.png)

**ast** (**a**verage and **s**um **t**ool) is a command line tool designed to calculate the sum, mean, variance or standard
deviation of a list of numbers passed through `stdin`.
The aforementioned list can be any kind of text, it will be split according to a passed delimiter
(defaults to `' '` and always splits lines)
and just the numbers found in it will be taken into consideration.

# How to Build
A building script is included with the rest of the source. Run `compile` to compile **ast**.

# How to Use
Use the command `ast OPTION [delimiter]`, where `OPTION` refers to the operation you wish to perform (`-s` for sum, `-m` for mean, `-v` for variance, `-d` for standard deviation) and `delimiter` is the token used to split the passed string. Alternate switches can be found in `ast --help`.

# Examples
 * Calculating the **sum** of a list of five numbers:<br/>`echo "123 323 42 78.43434 -78.9" | ast -s` outputs `487.53434`.

 * Calculating the **average** of said list:<br/>`echo "123 323 42 78.43434 -78.9" | ast -m` outputs `97.5068680000000001`.

 * Calculating the population **variance** of said list:<br/>`echo "123 323 42 78.43434 -78.9" | ast -v` outputs `17212.2418310776964`.

 * Calculating the population **standard deviation** of said list:<br/>`echo "123 323 42 78.43434 -78.9" | ast -d` outputs `131.19543372799869`.

 * Calculating the **sum** of a list of four numbers **split by commas**:<br/>`echo "123, 323,42 ,78.43434" | ast -s ,` outputs `566.434340000000006`.
