#ifndef PROTOCOL_H_
#define PROTOCOL_H_

/**
 * Packet Structure
 * ------------------------------------------------------------------------
 * | Protocol(4byte) | Size(4byte) |           Data(Auto)                 |
 * ------------------------------------------------------------------------
 */

enum Protocol
{
    /**
     * 프로토콜의 시작
     */
    START_PROTOCOL = 0x10000000,

    /**
     * HeartBeat 체크용 프로토콜
     * -----------------------------
     * | PING_DEVICE | 12 | 0xFFFF |
     * -----------------------------
     * data : 0xFFFF
     */
    PING_DEVICE,

    /**
     * HeartBeat 응답에 대한 프로토콜
     * -----------------------------
     * | PONG_DEVICE | 12 | 0xFFFF |
     * -----------------------------
     * data : 0xFFFF
     */
    PONG_DEVICE,

    /**
     * 스마트폰의 서비스가 실행 되었을 때 자신이 제어할 대상을 등록 대기상태 요청
     * ---------------------------------------
     * | SET_DEVICE | 26 | 00:00:00:00:00:00 |
     * ---------------------------------------
     * data : 자신이 관리하려는 PC의 MAC 주소
     */
    SET_DEVICE,

    /**
     * 요청을 보내는 장치에 대응하는 다른 장치 찾기
     * 현재 사용하지 않음
     * -----------------------
     * | FIND_DEVICE | ? | ? |
     * -----------------------
     */
    FIND_DEVICE,

    /**
     * Phone => Grub : 장치 강제 종료
     * ---------------------------------
     * | SHUTDOWN_DEVICE | 12 | 0xFFFF |
     * ---------------------------------
     * data : 0xFFFF
     */
    SHUTDOWN_DEVICE,

    /**
     * Phone => Grub : 장치 부팅 진행
     * -------------------------------------------
     * | BOOTING_DEVICE | 26 | 00:00:00:00:00:00 |
     * -------------------------------------------
     * data : 자신이 부팅을 승인 시키고자하는 대상의 MAC 주소 (확인용)
     */
    BOOTING_DEVICE,

    /**
     * 부팅상태값 요청
     * --------------------------------------------
     * | BOOTING_REQUEST | 26 | 00:00:00:00:00:00 |
     * --------------------------------------------
     * data : 스마트폰에게 승인을 받기위한 자신의 MAC 주소
     */
    BOOTING_REQUEST,

    /**
     * 프로토콜의 끝
     * 이 이상의 값은 존재치 않음
     */
    END_PROTOCOL
};

#endif
