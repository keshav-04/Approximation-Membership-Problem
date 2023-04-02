# Approximation Membership Problem
  (CS201-pproject)


In this project, we are mainly doing the "Approximation membership problem". Here, we discussed three methods for solving this problem, which are:
  1. Bloom Filter
  2. Cuckoo Filter
  3. Quotient Filter

* Description of files:

  * main.c ~ It is mainly a driver file to run and implement the application(operations) of the given three header files.
  * qf.h ~ Header file for Quotient filter, have functions for different operations related to quotient filter.
  * bf.h ~ Header file for Bloom filter.
  * cf.h ~ Header file for Cuckoo filter.

* How to run code:


 In this one just have to run the main file, keeping the rest library files in the same folder. While running the main.c file, user should first input the first option   to choose the dataset according to the options shown in command line. Then after choosing the type of data set, user have to provide some inputs according to his/her     choice. 
 For Bloom and Cuckoo Filter user can input a srting of any length, but for Quotient Filter user have to enter a string which should be of minimum length = 8. 
Then there are different operations available for different data set, like insert and lookup operations for Bloom filter, while insert, lookup and delete operations     for Quotient filter and Cuckoo filter.
