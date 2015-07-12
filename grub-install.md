0. 그 어떤것 보다 ubuntu 설치후 먼저 할 것은 아래 두줄
sudo apt-get update
sudo apt-get upgrade

1. 일단은 에디터를 사용해야하니깐...
sudo apt-get install vim

2. git 을 이용하여 소스를 받아야 하니까 설치..
sudo apt-get install git

3. 소스 컴파일을 위한 기본 라이브러리 및 툴 설치
sudo apt-get install autoconf automake libtool flex bison tree

4. 컴파일러를 설치
sudo apt-get install gcc g++

5. 컴파일러와 링커 최신버전 컴파일 설치를 위한 라이브러리 설치
sudo apt-get install patchutils texinfo

6. objconv, objdump, strip, ar, nm, ld 등의 명령어 최신버전 설치
binutils-2.25 버전 소스 컴파일 설치

7. 아래의 옵션으로 binutils 설치
./configure --enable-64bit-bfd --disable-shared --disable-nls
make configure-host
make all
sudo make install

8. /usr/bin 을 최우선순위로 PATH 변수 설정
export PATH="/usr/bin:$PATH"

9. objconv 설치
git clone https://github.com/vertis/objconv
cd objconv
g++ -o objconv -O2 src/*.cpp
sudo cp objconv /usr/bin/objconv

10. 파티션 툴 설치
sudo apt-get install kpartx bxImage

11. qemu 설치
sudo apt-get install qemu

12. grub 소스 컴파일
git clone https://github.com/coreos/grub.git
cd grub
./linguas.sh
./autogen.sh
./configure --prefix=/home/사용자계정이름/g2/usr
make
make install

13. qemu 로 테스트하기 위한 가상 이미지 파일시스템 생성
cd ~
qemu-img create -f raw brdisk-img.raw 4G
fdisk brdisk-img.raw

//-------------------
// 실행중 입력값 들..
//-------------------
Device contains neither a valid DOS partition table, nor Sun, SGI or OSF disklabel
Building a new DOS disklabel with disk identifier 0xc65f2bd8.
Changes will remain in memory only, until you decide to write them.
After that, of course, the previous content wont be recoverable.

Warning: invalid flag 0x0000 of partition table 4 will be corrected by w(rite)

Command (m for help): x

Expert command (m for help): c
Number of cylinders (1-1048576, default 261): 406

Expert command (m for help): h
Number of heads (1-256, default 255): 16

Expert command (m for help): s
Number of sectors (1-63, default 63): 63

Expert command (m for help): r

Command (m for help): p

Disk brdisk-img.raw: 2147 MB, 2147483648 bytes
1 heads, 16 sectors/track, 262144 cylinders, total 4194304 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0xc65f2bd8

         Device Boot      Start         End      Blocks   Id  System

Command (m for help): n
Partition type:
   p   primary (0 primary, 0 extended, 4 free)
   e   extended
Select (default p): p
Partition number (1-4, default 1): 1
First sector (2048-4194303, default 2048): 
Using default value 2048
Last sector, +sectors or +size{K,M,G} (2048-4194303, default 4194303): 2000000            

Command (m for help): n
Partition type:
   p   primary (1 primary, 0 extended, 3 free)
   e   extended
Select (default p): p
Partition number (1-4, default 2): 2
First sector (2000001-4194303, default 2000001): 
Using default value 2000001
Last sector, +sectors or +size{K,M,G} (2000001-4194303, default 4194303): 
Using default value 4194303

Command (m for help): p

Disk brdisk-img.raw: 2147 MB, 2147483648 bytes
1 heads, 16 sectors/track, 262144 cylinders, total 4194304 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0xc65f2bd8

         Device Boot      Start         End      Blocks   Id  System
brdisk-img.raw1            2048     2000000      998976+  83  Linux
brdisk-img.raw2         2000001     4194303     1097151+  83  Linux

Command (m for help): w
The partition table has been altered!

Syncing disks.

14. 생성한 파티션 format
sudo kpartx -l brdisk-img.raw

//----------------------
// 출력
//----------------------
loop0p1 : 0 1997953 /dev/loop0 2048
loop0p2 : 0 2194303 /dev/loop0 2000001
loop deleted : /dev/loop0
//----------------------

sudo kpartx -a brdisk-img.raw
sudo mkfs.ext3 /dev/mapper/loop0p1
sudo mkfs.ext3 /dev/mapper/loop0p2

# 여기서 '/dev/mapper/loop1p1'의 값은 위의 출력 loop 번호값 참고

cd ~
mkdir boot
sudo mount /dev/mapper/loop1p1 boot
sudo ./g2/usr/sbin/grub-install --no-floppy --boot-directory=/home/사용자계정/boot /dev/loop0
sudo ./g2/usr/sbin/grub-mkconfig ~/boot/grub/grub.cfg

15. Qemu 실행
cd ~
qemu-system-i386 brdisk-img.raw -serial stdio
