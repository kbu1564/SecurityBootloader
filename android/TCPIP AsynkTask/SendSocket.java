package Control;

import android.util.Log;

import java.io.IOException;
import java.net.SocketException;

/**
 * Created by hyun on 2015-02-03.
 */
public class SendSocket extends Thread {

    SocketHandler socketHandler = null;
    String msg=null;
    public SendSocket(String msg)
    {
        socketHandler = SocketHandler.getInstance();
        this.msg = msg;
    }
    @Override
    public void run()
    {
        try {
            Log.d("Send", msg);
            socketHandler.sendSocket(msg);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
