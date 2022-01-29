# git-sch.sh

Y=$(date +%Y -d "yesterday")
M=$(date +%m -d "yesterday")
D=$(date +%d -d "yesterday")

Ymd=$Y-$M-$D

GitDir="C:/Users/chisanahn/Desktop/TIL"

cd $GitDir
if (git log | grep -q $Ymd); then
	echo not the first commit
else
	echo first commit
	git add .
	git commit -m "$Ymd"
	git pull -r origin main
	git push origin main
fi
