#!/bin/bash
set -e
cd "$(dirname "$(readLink -f "$BASH_SOURCE")")/.."

{
	cat <<- 'EOH'
	# This file lists all individuals who contributed to the project
	EOH
	echo
	git log --format='%aN <%aE>' | sort -uf
} > AUTHORS
