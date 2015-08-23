# 중계 서버 UML Diagram
![serverdiagram 4](https://cloud.githubusercontent.com/assets/7445459/9296130/74a32630-44c0-11e5-916f-d4ccd3dc5d4a.jpg)

### 중계 서버 동작 흐름
서버 구현시 Server 클래스의 method 들을 이용하여 서버를 생성하도록 되어있으며 각각의 클라이언트들은 하나의 장치로 구분되어 스마트폰 1대의 소켓에 1대이상의 PC 소켓이 대응되어 Group 클래스로 Wrapping 처리됨

이렇게 생성된 Group 객체들을 배열형식으로 Server 클래스에서 가지고 있게 됨

각각의 클라이언트에서 전송되는 데이터들은 main thread 에 의해 수신처리 되며 데이터 수신시 수신된 패킷이 어떠한 속성의 타입인지 PacketParser 클래스를 통해 decode 작업을 수행하여 PacketExecuteQueue 에 push 됨

push 된 큐의 Packet 데이터들을 하나씩 꺼내어 ExecuteThread 에서 처리하게되며, 해당 패킷 속성에 해당하는 execute() 함수에 의해 해당 패킷의 루틴을 수행하게 됨

각각의 클라이언트의 비정상 종료를 위해 특정 주기적으로 Heartbeat 를 날리는 Thread 를 하나 별도로 둠
각각의 ExecuteThread 의 경우 클라이언트 단위로 패킷을 처리하도록 하는 것이 더 좋을 것 같음(Lock, UnLock 처리)

### 변경된 부분
3차 설계 당시 여러 ReceiveThread 에서 데이터를 수신하여 PacketExecuteQueue 에 저장하는 방식에서
단 하나의 main thread 에서 데이터를 수신하여 PacketExecuteQueue에 저장하는 방식으로 변경하였으며 
이렇게 저장된 큐에서 ExecuteThread 들이 각각 작업을 하나씩 할당받아 처리하도록 설계 변경

