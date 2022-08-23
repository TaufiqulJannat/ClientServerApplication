
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;

public class Client {
public static void main(String[] args) throws IOException {

FileInputStream fileInputStream = null;
BufferedInputStream bufferedInputStream = null;
BufferedOutputStream bufferedOuptputStream = null;
Socket socket = null;
int count;

try{
    try {
           socket = new Socket("127.0.0.1", 5555);
        } catch (IOException ex) {
            System.out.println("Error: Unable to create Socket ");
        }

           // File file = new File("D:/ClientFile.txt");
            
            File file = new File("E:\\FtpProject\\TransferFileFromServerToClient\\SendFile\\New folder (1)\\Fileinput.txt");
            
            
            long fileLength = file.length();
            System.out.println(fileLength);
            if ( Integer.MAX_VALUE < fileLength ) {
                    System.out.println("Error: Exceeded the size of transfer");
            }


            byte[] bytes = new byte[(int) fileLength];
            
            
                try{      
                        fileInputStream = new FileInputStream(file);
                        
                }catch (IOException ex){
                    System.out.println("Error: Unable to open fileInputStream");
                }
            bufferedInputStream = new BufferedInputStream(fileInputStream);
            bufferedOuptputStream = new BufferedOutputStream(socket.getOutputStream());

while ((count = bufferedInputStream.read(bytes)) > 0) {
    bufferedOuptputStream.write(bytes, 0, count);
}
}

finally{
        bufferedOuptputStream.flush();
        bufferedOuptputStream.close();
        fileInputStream.close();
        bufferedInputStream.close();
        socket.close();
}

}
}