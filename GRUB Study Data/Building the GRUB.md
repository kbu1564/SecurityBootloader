# Buliding the GRUB
```
INSTALL 참고자료 https://github.com/coreos/grub/blob/master/INSTALL

처음 SETTING : git clone https://github.com/coreos/grub.git
파일을 받아야함 !! 

명령어 SETTING은 해둘것 g++, gcc, make, cmake, autoconf, bison, flex
-> 설치방법 : sudo apt-get install [설치할 파일]

1. `cd' to the directory containing the package's source code.
-> cd 명령어를 이용하여 package source code 있는곳으로 가라 

2. Skip this and following step if you use release tarball and proceed to
step 4. If you want translations type `./linguas.sh'.
-> 이부분은 스킵 가능

3. Type `./autogen.sh'.
-> 명령어 ./autogen.sh를 입력하시오
error : ./autogen.sh 줄 83 autoreconf 명령어를 찾을 수 없음 .. 
해결법 ->   sudo apt-get install autoconf
-> autconf 설치가 필요하다 
autconf 란
Autoconf is an extensible package of M4 macros that produce shell scripts to automatically configure software 
source code packages. These scripts can adapt the packages to many kinds of UNIX-like systems without manual 
user intervention. Autoconf creates a configuration script for a package from a template file that lists the 
operating system features that the package can use, in the form of M4 macro calls.
-> Autoconf에 자동으로 소프트웨어 소스코드의 패키지를 구성하는 쉘 스크립트를 생성하는 M4 Macro 의 확장 패키지
-> 이 스크립트는 자동으로 유닉스 계열 시스템의 많은 종류의 패키지에 적용가능
참조 : http://www.gnu.org/software/autoconf/autoconf.html

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
lex 컴파일을 위해서 ... flex설치 필요
해결법 -> flex 설치 sudo apt-get install flex

bison 란
bison은 GNU 파서 생성기로 yacc를 개선하고 대체하기 위해 만들어졌다. 이 프로그램 도구는 LALR 방식으로 작성된 문법을 처리하고 해석하여 C코드로 
만들어 준다. 흔히 사칙 계산기부터 고도의 프로그래밍 언어까지 다양한 범위의 언어를 만드는데 사용할 수 있다. 문법 정의 프로그램인 lex 또는 flex와 
함께 사용되곤 한다. 대부분의 유닉스 배포판과 리눅스에 포함되어 있으며 GPL만 따른다면 비용을 지불할 필요가 없는 자유 소프트웨어이다.
참조 : 위키피디아

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

* 다른오류 발견시 알려주시면 감사합니다 수정해서 반영하겠습니다.!!

```
출저 : https://github.com/coreos/grub
애러 파악 및 번역 https://github.com/GangHoyong/
