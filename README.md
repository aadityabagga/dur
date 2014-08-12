dur (short for duration) is a C program to find the difference between 2 dates.

# Usage

It takes input in the form of 2 dates, initial-date and final-date;

in the format yyyy-mm-dd yyyy-mm-dd

Output is the number of days difference between the dates.

For example,

dur 2013-12-30 2014-01-31
Day(s): 32

# Installation

To use it, run the compiled binary for your architecture from the bin folder (if available),
or to compile and install it, download the source, and run :

(as root)
 # make

(or)
 $ sudo make install

For Arch Linux users, its also available in the AUR:
https://aur.archlinux.org/packages/dur/

# Using

For some possible ways in which you can use the program, see the use-cases file inside the doc folder:
https://github.com/aadityabagga/dur/blob/master/doc/use-cases

# Note

For really large differences in date, example, 1901-01-01 to 2013-11-28 (41239 days),
the output maybe incorrect by a day or two, as the program was not meant for such complete accuracy.
(error % = 0.005 approx)

However, effort was made to reduce the errors to a minumum, and it should work correctly for most cases.