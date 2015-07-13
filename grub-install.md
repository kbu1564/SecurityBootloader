0. 그 어떤것 보다 ubuntu 설치후 먼저 할 것은 아래 두줄
```bash
sudo apt-get update
sudo apt-get upgrade
```

1. 일단은 에디터를 사용해야하니깐...
```bash
sudo apt-get install vim
```

2. git 을 이용하여 소스를 받아야 하니까 설치..
```bash
sudo apt-get install git
```

3. 소스 컴파일을 위한 기본 라이브러리 및 툴 설치
```bash
sudo apt-get install autoconf automake libtool flex bison tree
```

4. 컴파일러를 설치
```bash
sudo apt-get install gcc g++
```

5. 컴파일러와 링커 최신버전 컴파일 설치를 위한 라이브러리 설치
```bash
sudo apt-get install patchutils texinfo
```

6. /usr/bin 을 최우선순위로 PATH 변수 설정
```bash
export PATH="/usr/bin:$PATH"
```

7. Install binutils
 6-1. http://ftp.gnu.org/gnu/binutils/에서 binutils-2.25.tar.gz(최신버전)를 다운
 6-2. bintutils-2.25.tar.gz 압축 해제
 6-3. bintutils-2.25 디렉토리로 이동
 6-4. 명령어 순차적으로 입력

```bash  
./configure --enable-64bit-bfd --disable-shared --disable-nls
make configure-host
make all
sudo make install
```
8. objconv 설치
```bash
git clone https://github.com/vertis/objconv
cd objconv
g++ -o objconv -O2 src/*.cpp
sudo cp objconv /usr/bin/objconv
```

9. 파티션 툴 설치
```bash
sudo apt-get install kpartx bxImage
```

10. qemu 설치
```bash
sudo apt-get install qemu
```

11. grub 소스 컴파일
```bash
git clone https://github.com/coreos/grub.git
cd grub
./linguas.sh
./autogen.sh
./configure --prefix=/home/사용자계정이름/g2/usr
make
make install
```

12. qemu 로 테스트하기 위한 가상 이미지 파일시스템 생성
```bash
cd ~
qemu-img create -f raw brdisk-img.raw 4G
sudo mkfs.ext2 brdisk-img.raw
fdisk brdisk-img.raw
```

//-------------------
// 실행중 입력값 들..
//-------------------
```
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

Command (m for help): p

Disk brdisk-img.raw: 2147 MB, 2147483648 bytes
1 heads, 16 sectors/track, 262144 cylinders, total 4194304 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0xc65f2bd8

         Device Boot      Start         End      Blocks   Id  System
brdisk-img.raw1            2048     4194303      !@#!!@+  83  Linux

Command (m for help): w
The partition table has been altered!

Syncing disks.
```

13. 생성한 파티션을 실제 폴더에 mount
우선 해당 가상 드라이브 이미지 파일에 대한 장치드라이버를 생성한다.
```bash
cd ~
sudo losetup /dev/loop0 brdisk-img.raw
```

생성된 장치에 대한 boot mount 실행
```bash
cd ~
mkdir boot
sudo mount /dev/loop0 boot
sudo ./g2/usr/sbin/grub-install --force --no-floppy --boot-directory=/home/사용자계정명/boot /dev/loop0
sudo ./g2/usr/sbin/grub-mkconfig ~/boot/grub/grub.cfg
```

14. Qemu 실행
```bash
cd ~
qemu-system-i386 brdisk-img.raw -serial stdio
```
