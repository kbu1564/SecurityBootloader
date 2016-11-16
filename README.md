# Grub based Security Multi-Bootloader System (V1.0)



[![GitHub license](https://img.shields.io/badge/license-GPLv3-blue.svg)](https://raw.githubusercontent.com/IWillFindYou/SecurityBootManager/develop/LICENSE)

## Introduction
노트북을 도난당했을 경우, 도둑의 이미지와 위치정보를 알수가 없습니다 그래서 저희는 부팅하는 동시에 이미지 촬용과 IP주소를 네트워크로 보내서 사용자 휴대폰 어플로 정보(IP주소와 사진)를 통하여 범인을 찾기 위해서 만들었습니다 

## Developer
[@kbu1564](https://github.com/kbu1564)
[@GangHoyong](https://github.com/GangHoyong)
[@JuHyun Yu](https://github.com/formfoxk)
[@kimhajin](https://github.com/kimhajin)

## Development operating environment and Related matters
1. Security Multi-Bootloader development operating environment : ubuntu 14.04 / Grub
2. Security Mulit-Bootloader App Version API 17 : Android 4.2 (Jelly Bean)
3. [Grub 시작 문자열 구성 변경 및 함수 호출 스택](https://github.com/kbu1564/SecurityBootloader/issues/3)
4. [Network related matters](https://github.com/kbu1564/SecurityBootloader/issues/7)
4. [Proxy Server related matters](https://github.com/kbu1564/SecurityBootloader/issues/19)
5. [Android related matters](https://github.com/kbu1564/SecurityBootloader/issues/17)

## License
   - [GPL3.0](https://github.com/kbu1564/SecurityBootloader/blob/develop/LICENSE)
   - [GNU](https://www.gnu.org/licenses/licenses.html)

## Used OpenSource List
   - Grub2 : GPLv3.0 License : [Grub2 Site](https://www.gnu.org/software/grub/)
   - iPXE : GPLv2.0 License : [iPXE Site](http://ipxe.org/)
   
## Update history List
   - V1.0 Grub based Security Multi-Bootloader System : Android phone 이용한 부팅제어 시스템
   - V1.1 SecurityBootManager CoreLibrary : 부팅 시 주변 환경 정보를 얻을 수 있는 Framwork 
     - [V1.1 SecurityBootManager CoreLibrary](https://github.com/GangHoyong/SecurityBootManager)
