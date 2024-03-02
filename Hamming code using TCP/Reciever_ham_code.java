// RECIEVER side detection code


import java.io.*;
import java.net.*;
import java.util.*;
public class MyClient {
public static void main(String[] args) {
try{
Socket s=new Socket("localhost",6666);
Scanner sc=new Scanner(System.in);
DataOutputStream dout=new DataOutputStream(s.getOutputStream());
dout.writeUTF("Enter the 7-bit data code");
int d[]=new int[7];
DataOutputStream dout1=new DataOutputStream(s.getOutputStream());
for(int i=0;i<7;i++)
{
d[i]=sc.nextInt();
dout1.writeUTF(Integer.toString(d[i]));
}
int p[]=new int[4];
p[0]=d[0]^d[1]^d[3]^d[4]^d[6];

p[1]=d[0]^d[2]^d[3]^d[5]^d[6];
p[2]=d[1]^d[2]^d[3];
p[3]=d[4]^d[5]^d[6];
int c[]=new int[11];
c[0]=p[0];
c[1]=p[1];
c[2]=d[0];
c[3]=p[2];
c[4]=d[1];
c[5]=d[2];
c[6]=d[3];
c[7]=p[3];
c[8]=d[4];
c[9]=d[5];
c[10]=d[6];
DataOutputStream dout2=new DataOutputStream(s.getOutputStream());
for(int i=0; i<11;i++)
{
dout2.writeUTF(Integer.toString(c[i]));
}
dout.close();
s.close();
}catch(Exception e){System.out.println(e);} } }
