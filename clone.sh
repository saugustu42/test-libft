#!/bin/sh

if [ $# != 1 ] ; then
	echo usage: ./clone.sh your-git-repo
	exit 1
fi
git clone "$1" eval-libft
