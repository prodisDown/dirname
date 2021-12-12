#!/bin/sh

yy=$(cat <<EOF

abc
abc//
abc///
abc/123
abc/123/
abc/123/def
abc///123///def
abc///123///def///
/
/abc
///
///abc
///abc/123
///abc///123
/abc/123/def
/abc/123/def/
/abc/123/def///
EOF
)

echo -e "Input\e[20G /bin/dirname\e[40G ./dirname"
echo "${yy}" | while read xx
do
	aa=$(dirname "${xx}")
	bb=$(./dirname "${xx}")
	echo -ne "${xx}"
	echo -ne "\e[22G${aa}"
	echo -ne "\e[42G${bb}\n"
done
