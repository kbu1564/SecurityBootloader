package com.example.testclient;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * Created by 주현 on 2015-08-24.
 */
public class ByteType {
    /** 
     * @Method Name	: intTobyte 
     * @Method 기능	: int 타입을 byte 타입으로 변환
     * @변경이력		: 
     * @param integer
     * @param order
     * @return 
     */
    public static byte[] intTobyte(int integer, ByteOrder order) {

        ByteBuffer buff = ByteBuffer.allocate(Integer.SIZE/8);
        buff.order(order);

        // 인수로 넘어온 integer을 putInt로설정
        buff.putInt(integer);

        System.out.println("intTobyte : " + buff);
        return buff.array();
    }

    /** 
     * @Method Name	: byteToInt 
     * @Method 기능	: byte 타입을 int 타입으로 변환
     * @변경이력		: 
     * @param bytes
     * @param order
     * @return 
     */
    public static int byteToInt(byte[] bytes, ByteOrder order) {

        ByteBuffer buff = ByteBuffer.allocate(Integer.SIZE/8);
        buff.order(order);

        // buff사이즈는 4인 상태임
        // bytes를 put하면 position과 limit는 같은 위치가 됨.
        buff.put(bytes);
        // flip()가 실행 되면 position은 0에 위치 하게 됨.
        buff.flip();

        System.out.println("byteToInt : " + buff);

        return buff.getInt(); // position위치(0)에서 부터 4바이트를 int로 변경하여 반환
    }

    public static String byteToString(byte[] bytes, ByteOrder order) {

        ByteBuffer buffer = ByteBuffer.allocate(bytes.length);
        buffer.order(order);
        buffer.put( bytes );

        byte[] tmpbytes = new byte[bytes.length];

        buffer.position(0);
        buffer.get(tmpbytes);

        return new String(tmpbytes);
    }
}
