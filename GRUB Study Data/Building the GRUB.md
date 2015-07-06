# Buliding the GRUB
```
1. `cd' to the directory containing the package's source code.
-> cd 명령어를 이용하여 package source code 있는곳으로 가라 

2. Skip this and following step if you use release tarball and proceed to
step 4. If you want translations type `./linguas.sh'.
-> 이부분은 스킵 가능

3. Type `./autogen.sh'.
이상태
error : ./autogen.sh 줄 83 autoreconf 명령어를 찾을 수 없음 .. 
해결법 ->   sudo apt-get install autoconf
autconf 설치가 필요하다 .. 

4. Type `./configure' to configure the package for your system.
If you're using `csh' on an old version of System V, you might
need to type `sh ./configure' instead to prevent `csh' from trying
to execute `configure' itself.

Running `configure' takes awhile.  While running, it prints some
messages telling which features it is checking for.

-> 명령어 입력 ./configure 

error : bison cannot be found [configure]
해결법 -> bison 설치 sudo apt-get install bison
error : flex is not found
해결법 -> flex 설치 sudo apt-get install flex

5. Type `make' to compile the package.
-> 명령어 입력 make 

7. Optionally, type `make check' to run any self-tests that come with the package.
-> 자체 테스트 package 실시합니다 
-> 명령어 입력 : make check  / sudo make check

8. Type `make install' to install the programs and any data files and
documentation.
-> 명령어 입력 : sudo make install 
sudo 하는 이유 : 승인거부 문제 !! root 권한 문제 때문에... 

9. You can remove the program binaries and object files from the
source code directory by typing `make clean'.  To also remove the
files that `configure' created (so you can compile the package for
a different kind of computer), type `make distclean'.  There is
also a `make maintainer-clean' target, but that is intended mainly
for the package's developers.  If you use it, you may have to get
all sorts of other programs in order to regenerate files that came
with the distribution.

```
출저 : https://github.com/coreos/grub
애러 파악 및 번역 https://github.com/GangHoyong/
