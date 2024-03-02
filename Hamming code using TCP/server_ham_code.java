//SERVER or sender side code


import java.io.*;
import java.net.*;
import java.util.*;
public class MyServer {
public static void main(String[] args){
try{
ServerSocket ss=new ServerSocket(6666);
Socket a=ss.accept();//establishes connection
DataInputStream dis=new DataInputStream(a.getInputStream());
String str1=(String)dis.readUTF();
System.out.println(str1);
DataInputStream dis1=new DataInputStream(a.getInputStream());
int d[]=new int[7];
for(int i=0;i<7;i++)
{
String str=(String)dis.readUTF();
System.out.println(str);
d[i]=Integer.parseInt(str);
}
Scanner sc=new Scanner(System.in);

int c[]=new int[11];
System.out.println("complete code word is:");
for(int i=0;i<11;i++)
{
String str2=(String)dis.readUTF();
System.out.print(" "+str2);
c[i]=Integer.parseInt(str2);
}
System.out.println();
System.out.println("Enter the Received codeword");
int r[]=new int[11];
for(int i=0;i<11;i++)
{
r[i]=sc.nextInt();
}
int pr[]=new int[4];
int rd[]=new int[7];
pr[0]=r[0];
pr[1]=r[1];
rd[0]=r[2];
pr[2]=r[3];
rd[1]=r[4];
rd[2]=r[5];

rd[3]=r[6];
pr[3]=r[7];
rd[4]=r[8];
rd[5]=r[9];
rd[6]=r[10];
int s[]=new int[4];
s[0]=pr[0]^rd[0]^rd[1]^rd[3]^rd[4]^rd[6];
s[1]=pr[1]^rd[0]^rd[2]^rd[3]^rd[5]^rd[6];
s[2]=pr[2]^rd[1]^rd[2]^rd[3];
s[3]=pr[3]^rd[4]^rd[5]^rd[6];
int dec=(s[0]*1)+(s[1]*2)+(s[2]*4)+(s[3]*8);
if(dec==0)
System.out.println("No error");
else
{
System.out.println("Error is at "+dec);
if(r[dec-1]==0)
r[dec-1]=1;
else
r[dec-1]=0;
System.out.println("Corrected code word is : ");
for(int i=0;i<11;i++)
System.out.print(r[i]+" ");

}ss.close();
}catch(Exception e){System.out.println(e);}
} }
