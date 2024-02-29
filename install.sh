#!/usr/bin/env bash

echo "Name to use for compile script (the command you will write to compile things): "
read name

# this line makes the directory and if the directory already exists and gives an error it throws the error out
mkdir ~/bin 2> /dev/null

mv compile ~/bin/$name

# Any questions about the how or why or whichever question about the script feel free to talk to me about it
# nice work coming in here and looking at it :)
