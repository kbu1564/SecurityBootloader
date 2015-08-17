#ifndef PROTOCOL_H_
#define PROTOCOL_H_

enum Protocol
{
	/**
	 * 프로토콜의 시작
	 */
	START_PROTOCOL = 0x10000000,

    /**
     * 요청을 보내는 장치에 대응하는 다른 장치 찾기
     */
    FIND_DEVICE,

    /**
     * Phone => Grub : 장치 강제 종료
     */
    SHUTDOWN_DEVICE,

    /**
     * Phone => Grub : 장치 부팅 진행
     */
    BOOTING_DEVICE,

    /**
     * 부팅상태값 요청
     */
    BOOTING_REQUEST,

	/**
	 * 프로토콜의 끝
	 * 이 이상의 값은 존재치 않음
	 */
	END_PROTOCOL
};

#endif

