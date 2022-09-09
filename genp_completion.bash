#!/bin/bash

_genp_completion()
{
	if [ "${#COMP_WORDS[@]}" != "2" ]; then
		return
	fi

	COMPREPLY=($(compgen -W "--alphanum --digit --symbol --help" -- "${COMP_WORDS[1]}"))

}

complete -F _genp_completion genp
