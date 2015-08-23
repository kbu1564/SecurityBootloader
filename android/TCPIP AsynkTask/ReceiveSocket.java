package Control;


import android.os.Handler;
import android.os.Message;
import android.util.Log;

import java.io.IOException;

/**
 * Created by hyun on 2015-02-03.
 */
public class ReceiveSocket extends Thread{


    private static boolean threadCancel = true;

    private static Handler handler;

    SocketHandler socketHandler = null;
    public static void setHandler(Handler handler)
    {
        ReceiveSocket.handler = handler;
    }
    public static void receiveCancel()
    {
        ReceiveSocket.threadCancel = false;

    }

    public void run()
    {
        socketHandler = SocketHandler.getInstance();

        while(threadCancel)
        {
            try {
                Message message = Message.obtain();
                String receiveStream = socketHandler.receiveSocket();
                Log.d("ReceiveSocket",receiveStream);
                String what = receiveStream.substring(0,receiveStream.indexOf("$"));
                message.obj = receiveStream.substring(receiveStream.indexOf("$")+1,receiveStream.length());
                message.what = Integer.valueOf(what);
                handler.sendMessage(message);
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
        try {
            Log.d("여긴밖이얌","가가가");
            socketHandler.finishSocket();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}
