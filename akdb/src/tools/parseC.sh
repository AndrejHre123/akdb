 #!/bin/sh
##
for var in "$@"
do
	cat $var | awk '/\/\// {print $0}; /\/\*/ {blk=1}; {if(blk) print $0}; /\*\// {blk=0}' >> "all_comments.tmp"
done