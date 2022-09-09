# 2fa PHP

A random password generator write in C.

# Usage

____

This is a very simple program that permits you to generate random passwords from the CLI.

You have three options for generating a password:

* Digits(-d|--digit); Will generate a password with only digits
* Alphanumerical(-a|--alphanum); Will generate a password with digits and characters
* Symbol(-s|--symbol); Will generate a password including digits, characters and special symbols

#### --help

```
Usage: genp [OPTION] [number]
Generates a random password.

   -h, --help          display this help and exit
   -a, --alphanum      generates a alphanumerical password
   -d, --digit         generates a numerical password
   -s, --symbol        generates a alphanumerical password with symbols

Examples:
   genp            Generates a alphanumerical password with length 8.
   genp -d 10                    Generates a numerical password with length 10.
```

___

# Installation

```bash
git clone https://github.com/JohhnMag0/genp.git
cd genp
gcc genp.c -o genp
sudo mv genp /usr/local/bin 

# If you don't want the auto-completion you can just ignore this part
sudo mv genp_completion.bash /etc/bash_completion.d
echo "source /etc/bash_completion.d/genp_completion.bash" >> .bashrc && source .bashrc
 
```



___

# Documentation

If you want to get an overview of how this works, you can get an ide in here: <https://johhnmag0.github.io/>


