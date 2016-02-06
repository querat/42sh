#!/bin/sh
## test.sh for  in /home/querat_g/42sh
## 
## Made by gwendal querat
## Login   <querat_g@epitech.net>
## 
## Started on  Sun May 24 18:25:29 2015 gwendal querat
## Last update Sun May 24 18:27:00 2015 gwendal querat
##

echo -e "
ls
ls -l
ls src/
ls *
ls */*/*/
ls; cd src/; ls; cd ..; ls
touch mdr; ls; rm mdr; ls -l
rm PATH; ls
rm ENV; ls
cd
cd src/
cd -
cd ./42sh
cd *.c
./42sh ./42sh

ls | grep s
pwd
echo test42sh
lol=pwd
$lol
cat > mdr | OK
cat >> mdr
cat < mdr
cat < mdr | ls
cat << mdr
mmkoibofutfy
kjpij; huhih; iououbi
|
>>
<<
<
>
""
cat -e hello | grep s | ls | cd ..| touch hello | echo $HOME
ls src && ls
ls || echo WIN
echo $lol
echo $jk
 | | | | && | | | | >> <<
cat >> mdr << ls
cat ; wc;
ls ; grep s; wc; ls
ls | grep s | wc | ls
cd ; echo test | ls && cd -
ls ; grep *
mkdir \"TEST de TEST\" ; ls \"TEST de TEST\" ; cd \"TEST de TEST\" ; touch \"GROS TEST\" ; ls ; cd ..
cd \"TEST de TEST\" ; rm \"GROS TEST\" ; cd .. ; rm -rf \"TEST de TEST\"
echo lol | grep s | wc&&echo plop || ls ; echo blop
kill 0 || ./42sh && wc
&& wc && ls || grep s
;;;;;;ls;;;;;;
echo plop, ls; wc -r
ls;ls&&grep s||ls;ls;ls;ls&&grep W
./42sh < /dev/null
cat /dev/urandom
echo lol || wc && echo plop || grep s && ls && cd
kill -11 0" | ./42sh
