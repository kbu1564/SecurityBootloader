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
     */
    PING_DEVICE = 0x10000001,

    /**
     * 스마트폰의 서비스가 실행 되었을 때 자신이 제어할 대상을 등록 대기상태 요청
     */
    SET_DEVICE = 0x10000002,

    /**
     * 요청을 보내는 장치에 대응하는 다른 장치 찾기
     */
    FIND_DEVICE = 0x10000003,

    /**
     * Phone => Grub : 장치 강제 종료
     */
    SHUTDOWN_DEVICE = 0x10000004,

    /**
     * Phone => Grub : 장치 부팅 진행
     */
    BOOTING_DEVICE = 0x10000005,

    /**
     * 부팅상태값 요청
     */
    BOOTING_REQUEST = 0x10000006,

    /**
     * 프로토콜의 끝 이 이상의 값은 존재치 않음
     */
    END_PROTOCOL = 0x10000007;

}