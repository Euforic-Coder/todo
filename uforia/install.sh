#!/bin/bash

if [ ! -d /usr/include/uforia ]
then
	sudo mkdir /usr/include/uforia
fi

sudo cp *.h /usr/include/uforia
echo "uforia header files copied to /usr/include/uforia"
