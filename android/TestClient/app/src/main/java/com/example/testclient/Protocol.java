package com.example.testclient;

/** 
 * @FileName		: Protocol.java 
 * @Project		: SecurityBootloder 
 * @Date			: 2015. 8. 23. 
 * @작성자			: 주현 
 * @프로그램 설명		: 프로토콜 정의
 * @프로그램 기능		: 
 * @변경이력		: 
 */
interface Protocol {

    public int START_PROTOCOL = 0x10000000,

    /**
     * HeartBeat 체크용 프로토콜
     * -----------------------------
     * | PING_DEVICE | 12 | 0xFFFF |
     * -----------------------------
     * data : 0xFFFF
     */
    PING_DEVICE = 0x10000001,

    /**
     * HeartBeat 응답에 대한 프로토콜
     * -----------------------------
     * | PONG_DEVICE | 12 | 0xFFFF |
     * -----------------------------
     * data : 0xFFFF
     */
    PONG_DEVICE = 0x10000002,

    /**
     * 스마트폰의 서비스가 실행 되었을 때 자신이 제어할 대상을 등록 대기상태 요청
     * ----------------------------------------------------
     * | SET_DEVICE | 30 | DeviceType | 00:00:00:00:00:00 |
     * ----------------------------------------------------
     * data0 : 자신의 장치 속성값 (PHONE , PC)
     * data1 : 자신이 관리하려는 PC의 MAC 주소
     */
    SET_DEVICE = 0x10000003,

    /**
     * Phone => Grub : 장치 강제 종료
     * --------------------------------------------
     * | SHUTDOWN_DEVICE | 26 | 00:00:00:00:00:00 |
     * --------------------------------------------
     * data : 자신이 부팅을 승인하지 않을 대상의 MAC 주소 (확인용)
     */
    SHUTDOWN_DEVICE = 0x10000004,

    /**
     * Phone => Grub : 장치 부팅 진행
     * -------------------------------------------
     * | BOOTING_DEVICE | 26 | 00:00:00:00:00:00 |
     * -------------------------------------------
     * data : 자신이 부팅을 승인 시키고자하는 대상의 MAC 주소 (확인용)
     */
    BOOTING_DEVICE = 0x10000005,

    /**
     * 부팅상태값 요청
     * --------------------------------------------
     * | BOOTING_REQUEST | 26 | 00:00:00:00:00:00 |
     * --------------------------------------------
     * data : 부팅가능 여부 요청을 보내기 위한 PC의 MAC 주소
     */
    BOOTING_REQUEST = 0x10000006,

    /**
     * 프로토콜의 끝
     * 이 이상의 값은 존재치 않음
     */
    END_PROTOCOL = 0x10000007;

}