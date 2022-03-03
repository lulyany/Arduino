import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
    public static void main(String[] args)throws Exception {
        //创建服务器对象
        ServerSocket ss=new ServerSocket(8888);
        //等待客户端连接
        Socket socket=ss.accept();
        //当前在服务器中 要读取数据 需要输入流  流有谁提供  客户端
        InputStream in=socket.getInputStream();
        //读数据
        int len;
        byte[]buffer=new byte[1024];
        while ((len=in.read(buffer))!=-1){
            System.out.println(new String(buffer,0,len));
        }
        //释放资源
        in.close();
    }
}