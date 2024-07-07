    
This terminal can execute ls,cp,mv and grep with few options:

1)ls:
	ls [OPTION]
	This works as original command ls.
	This can be executed with following options:
	1) -l 2) -U 3) -S 4) -a 
	and  normal ls
3)cp:
	cp [OPTION] [SOURCE] [TARGET]
	cp [option][SOURCE] [DIRECTORY]
	This works as original command cp.
	This can be executed with following options:
	1) -i 2) -n 3) -f 4) -v
	and normal cp
4)mv:
	mv [OPTION] [SOURCE] [TARGET]
	mv [option] [SOURCE] [DIRECTORY]
	This works as original command mv.
	This can be executed with following options:
	1) -i 2) -n 3) -f 4) -v
	and normal mv
5)grep:
	grep [OPTION] PATTERN [FILE] 
	This works as original command grep.
	This can be executed with following options:
	1) -H 2) -n 3) -c 4) -v
	and normal grep.
The requirements to execute this terminal are :
-> A Linux Ubuntu machine.
-> GCC should be installed in the machine:
	If GCC is not installed in your machine, do the following:
	Open the terminal on your machine and run the following commands:
		-> "sudo apt update"
		-> "sudo apt install build-essential"
		OR
		-> "sudo apt install gcc"
	To check if install then run the following command:
	        -> "gcc --version"
-> libreadline :
Install libreadline in your machine:
For that run the following command on your terminal:
		-> "sudo apt-get install libreadline8 libreadline-dev"
Now you are ready to run this terminal!

Steps to execute:

-> Change the directory to the directory where the files are located.
-> Now run the following commands: 
    -> "make" (To compile the executable files.)
    -> "./out.o" (To execute the terminal.)

Now you can run whichever command you want to run from the above mentioned commands.


