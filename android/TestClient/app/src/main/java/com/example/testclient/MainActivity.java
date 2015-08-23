package com.example.testclient;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {

    private TextView txtResponse;
    private EditText edtTextAddress, edtTextPort;
    private Button btnConnect, btnClear;
    private Socket socket = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtTextAddress = (EditText) findViewById(R.id.address);
        edtTextPort = (EditText) findViewById(R.id.port);
        btnConnect = (Button) findViewById(R.id.connect);
        btnClear = (Button) findViewById(R.id.clear);
        txtResponse = (TextView) findViewById(R.id.response);

        btnConnect.setOnClickListener(buttonConnectOnClickListener);
        btnClear.setOnClickListener(new OnClickListener() {

            public void onClick(View v) {
                txtResponse.setText("");
                try {
                    socket.close();
                } catch (IOException e) {
                    Log.e("Error", e.getMessage());
                }
            }
        });
    }

    // 클릭이벤트 리스너
    OnClickListener buttonConnectOnClickListener = new OnClickListener() {

        public void onClick(View arg0) {
            NetworkTask myClientTask = new NetworkTask(
                    edtTextAddress.getText().toString(),
                    Integer.parseInt(edtTextPort.getText().toString())
            );
            myClientTask.execute();
        }
    };

    /** 
     * @FileName		: MainActivity.java 
     * @Project		: NetworkTask 
     * @Date			: 2015. 8. 23. 
     * @작성자			: 주현 
     * @프로그램 설명		: 비동기 쓰레드 네트워크 통신
     * @프로그램 기능		: 중개서버와 TCP/IP 소켓 통신
     * @변경이력		: 
     */
    public class NetworkTask extends AsyncTask<Void, Void, Void> {

        String dstAddress;
        int dstPort;
        String response;

        // 소켓 연결 시도 수
        int connCount;

        NetworkTask(String addr, int port) {
            dstAddress = addr;
            dstPort = port;

            connCount = 0;
        }

        /** 
         * @Method Name	:  doInBackground
         * @Method 기능	:  백그라운드에서 중개 서버와 TCP/IP 소켓 통신
         * @변경이력		: 
         */
        @Override
        protected Void doInBackground(Void... arg0) {

            // 중개 서버와 TCP/IP 소켓 통신
            network();

            return null;
        }

        /** 
         * @Method Name	:  getbytes
         * @Method 기능	:  byte를 지정한 offset만큼 얻는 함수
         * @변경이력		: 
         */
        private byte[] getbytes(byte src[], int offset, int length) {
            byte dest[] = new byte[length];
            System.arraycopy(src, offset, dest, 0, length);
            return dest;
        }

        /** 
         * @Method Name	:  network
         * @Method 기능	:  중개서버와 TCP/IP 소켓 통신
         * @변경이력		: 
         */
        private void network()
        {
            try {

                socket = new Socket(dstAddress, dstPort);

                // 정상적으로 소켓이 연결되었을 경우
                if(socket != null)
                    connection();


            } catch(Exception e){
                if(connCount < 5)
                    network();
                else
                    connCount = 0;
            }
        }

        /** 
         * @Method Name	:  connection
         * @Method 기능	:  중개서버로 부터 메시지 수신
         * @변경이력		: 
         */
        private void connection()
        {
            try{
                DataInputStream dis = new DataInputStream(socket.getInputStream());

                byte[] msg = new byte[1024];

                // 메지시를 읽어 바이트 배열에 저장
                dis.read(msg, 0, msg.length);

                // 받은 메시지를 처리 한다.
                processMsg(msg);
            } catch (UnknownHostException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        /** 
         * @Method Name	:  processMsg
         * @Method 기능	:  전달 받은 메시지 처리
         * @변경이력		: 
         */
        private void processMsg(byte[] message)
        {
            int protocol = ByteType.byteToInt(getbytes(message, 0, 4), ByteOrder.LITTLE_ENDIAN);
            int size = ByteType.byteToInt(getbytes(message, 4, 4), ByteOrder.LITTLE_ENDIAN);
            String data = null;

            switch (protocol) {

                case Protocol.PING_DEVICE:
                    //data = ByteType.byteToString(getbytes(message, 8, size - 8), ByteOrder.LITTLE_ENDIAN);

                    break;

                case Protocol.SET_DEVICE:

                    break;

                case Protocol.FIND_DEVICE:

                    break;

                case Protocol.SHUTDOWN_DEVICE:

                    break;

                case Protocol.BOOTING_DEVICE:

                    break;

                case Protocol.BOOTING_REQUEST:

                    break;

                case Protocol.END_PROTOCOL:

                    break;
            }

            StringBuffer sb = new StringBuffer();
            sb.append("protocol(4bytes):" + protocol);
            sb.append("\nSize(4bytes):" + size);
            sb.append("\nData(Auto):" + data);

            response = sb.toString();

        }

        /** 
         * @Method Name	: onPostExecute
         * @Method 기능	: 모든 실행이 완료된 후 처리
         * @변경이력		: 
         */
        @Override
        protected void onPostExecute(Void result) {
            super.onPostExecute(result);
        }

    }

}