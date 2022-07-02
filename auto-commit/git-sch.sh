# git-sch.sh

Ymd=$(date -v -1d '+%Y-%m-%d')

GitDir="/Users/anchisan/Projects/TIL"

cd $GitDir
if (git log | grep -q $Ymd); then
	echo
	echo not the first commit
else
	echo
	echo first commit at $Ymd
	git add .
	git commit -m "$Ymd"
	git pull -r origin main
	git push origin main
fi